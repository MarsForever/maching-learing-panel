#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define size 5  //グリッドワールドの大きさ

#define L_Agent_step 20 //学習時のエージェントの移動距離（ステップ数）
#define E_Agent_step 20 //評価時のエージェントの移動距離（ステップ数）
#define P 2.0 //報酬時の係数
#define T 10 //学習履歴の長さ

int record_X[L_Agent_step]; //移動の履歴
int record_Y[L_Agent_step];
int record_Dir[L_Agent_step];

//ゴール地点を設定（ゴール値の初期化）

int x_goal = 0;
int y_goal = 0;
//File  *FP;

//構造体でグリッドワールド作成
struct GRID{
			union{
					struct{
							double up;
							double down;
							double left;
							double right;
					};
					double arrow[4];
			};
};

//構造体でグリッドワールドを設定

struct GRIDWORLD{
		GRID box[size][size];
};

GRIDWORLD grid;

//グリッドワールド
//バラメーター（確立）の初期化

void gridworld(void)
{
	int x,y; //グリッドワールドのX座標、Y座標
	//矢印初期化（矢印の長さを０に設定）
	
	for(x=0 ; x<size ; x++){
			for(y=0; y<size ; y++){
					grid.box[x][y].up = 1.0;
					grid.box[x][y].down = 1.0;
					grid.box[x][y].left = 1.0;
					grid.box[x][y].right = 1.0;
					
					if(y == 0) grid.box[x][y].down == 0.0;
					if(x == 0) grid.box[x][y].left == 0.0;
					if(y ==(size-1) ) grid.box[x][y].up = 0.0;
					if(x ==(size-1) ) grid.box[x][y].right = 0.0;
			}
	}
}

void griddisp(int goalx, int goaly)
{
		int a,x,y;
		int boxup;
		int boxdown;
		int boxleft;
		int boxright;
		
		
		for(a=0 ; a<size ; a++){
				printf("--- X%d ---",a);
		}
		
		printf("/n");
		
		for(a=0 ; a<size ; a++){
					for(x=0 ; x<size ; x++){
						boxup = grid.box[x][y].up;
						if(goaly == y && goalx == x){
								printf(" |        | ");
						}else{
								printf(" |   %2d    |",boxup);
						}
					}
					printf("/n");
					for(x=0 ; x<size ; x++){
						printf(" |      |");
					}
					printf("/n");
					for(x=0 ; x<size ; x++){
							boxleft = grid.box[x][y].left;
							boxright = grid.box[x][y].right;
							if(goaly == y && goalx == x){
									printf("%dGOAL",y);
							}else{
								
									if(0 == x){
											printf(" %d&Y%2d   %2d | ",y,boxleft,boxright);
									}else{
											printf(" | %2d     %2d |",boxleft,boxright);
									}
									
					}
					
		}
		printf("\n");
		for(x=0 ; x<size ;x ++){
						printf(" |      | ");
		}
		printf("\n");
		for(x=0 ; x<size ; x++){
					boxdown = grid.box[x][y].down;
					if(goaly == y && goalx == x){
						printf("  |     |  ");
					}else{
						printf("  |    %2d    |",boxdown);						
					}
			}
			printf("\n");
			for(a=0 ; a<size ; a++){
						printf("-----------------");
			}
			printf("\n");
		}
}

void learn_agent(void){
		//乱数の初期化
		srand(0);
		
		
		//-------------------------------------------------------------
		//学習
		//-------------------------------------------------------------


		//4方向の確率は同等に設定//グリッドワールド作成時に設定済み

		//学習の各バラメータを設定

		const int max_learn_count = 100;
		int i = 0;
		//int record_X[Agent_step];//移動の履歴
		//int record_Y[Agent_step];
		//int record_Dir[Agent_step];
		int Agent_X,Agent_Y; //エージェントのスタート位置
		int goalnum = 0; //エージェントがゴールに着いたか確認するために入れる変数
		double probability_sum; 	//４方向の確率の合計
		double direction; //4方向の確率の合計による方向
		
		
		gridworld();
		
		
		//回数まで繰り返す
		//必要な変数：現在の学習回数（初期値 0）learn_count、学習を行う回数max_learn_count100
		int Learn_count;
		
		for(Learn_count = 0 ; Learn_count < max_learn_count ; Learn_count ++)  //学習回数に到達してない
		{
					//任意のスタート位置に配置
					//エージェントの座標 = randの値（　0から　４(size)）を入れる。
					Agent_X = rand() % size;
					Agent_Y = rand() % size;
					
					//規定のステップ数の繰り返し
					for(int step = 0 ; step < L_Agent_step; step ++){
						printf("位置　　＝　[%d][%d]\n",Agent_X,Agent_Y);
						
						//-------------------------------------------------------------
						//行動
						
						//４方向の移動は確率により決定する。
						
						probability_sum = grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right+
						grid.box[Agent_X][Agent_Y].down +grid.box[Agent_X][Agent_Y].left;
						printf("probability_sum = %f\n",probability_sum);
						
						//確率に基づいてエージェントを移動させる。
						
						
						direction = (double)rand() /RAND_MAX * probability_sum;
						
						record_X[step] = Agent_X;
						record_Y[step] = Agent_Y;
						
						//上へ進む場合
						
						if(direction < grid.box[Agent_X][Agent_Y].up){
							record_Dir[step] = 0;
							Agent_Y = Agent_Y -1;
						
						}
						//右へ進む場合
						
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right){
							record_Dir[step] = 1;
							Agent_Y = Agent_Y -1;
						}
						
						//下へ進む場合
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right + 
						 		grid.box[Agent_X][Agent_Y].down){
							record_Dir[step] = 2;
							Agent_Y = Agent_Y -1;
						}
						
						//左へ進む場合
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right  +
								grid.box[Agent_X][Agent_Y].down + grid.box[Agent_X][Agent_Y].left){
							record_Dir[step] = 3;
							Agent_Y = Agent_Y -1;
						}
						
						//break;
						
						//-------------------------------------------------------------
						
						//移動した場所にゴールがあるかを判定
						
						if(Agent_X == x_goal && Agent_Y == y_goal){
									//今の場所がゴールである
									
									goalnum++;
									
									////ゴールに到達した場合は、エージェントに報酬を与える
									for(int t = 0 ; t<= T && t<= step ; t++){
										////一連の行動に対して報酬を分配
												grid.box[record_X[step-t]][record_Y[step-t]].arrow[record_Dir[step-t]]
												=grid.box[record_X[step-t]][record_Y[step-t]].arrow[record_Dir[step-t]]+P * (T - t + 1)/ T;
									}
									
									
									//ループを抜ける
									break;
							}
					}
							//***********確認***********
							printf("%f\n",grid.box[Agent_X][Agent_Y].up);
							printf("%f\n",grid.box[Agent_X][Agent_Y].down);
							printf("%f\n",grid.box[Agent_X][Agent_Y].right);
							printf("%f\n",grid.box[Agent_X][Agent_Y].left);
							//***********確認***********
				
			//	}
	
	
		}	

//学習終了
	griddisp(x_goal,y_goal);
	printf("学習時のゴールの数 = %d\n", goalnum);
	
	//-------------------------------------------------------------
}

void evaluation(void){
		//乱数の初期化
		srand(0);
	
	
		//printf("ゴール位置　　＝ ([%d][%d]\n)",x_goal,y_goal);
		
		//-------------------------------------------------------------
		//評価
		//-------------------------------------------------------------
		
		//４方向の確率は同等に設定//グリッドワールド作成時に設定済み
		
		//評価の各バラメータを設定
		
		const int max_Evaluation_count = 100;
		int i = 0;
		int Agent_X,Agent_Y; //エージェントのスた=と位置
		int goalnum = 0;  //エージェントがゴールに着いたか確認するために入れる変数
		double probability_sum; //4方向の確率の合計
		double direction; //４方向の確率の合計による方向
		
		
		
		
		//評価かいすうまで
		//必要な変数：現在の学習回数（初期値０）Evaluation_count,評価を行う回数max_Evaluation_count 100
		int Evaluation_count = 0;
		
		for(Evaluation_count = 0; Evaluation_count < max_Evaluation_count; Evaluation_count++){ //評価回数に到達してない
				//任意のスタート位置に配置
				//エージェントの座標 = randの値（０から４(size)）を入れる。
				
				Agent_X = rand()% size;
				Agent_Y = rand()% size;
				
				//規定のステップ数の繰り返し
				for(int step = 0 ; step < E_Agent_step ; step++)
				{
					//printf("位置   =  [%d].[%d]\n", Agent_X,Agent_Y);
					//-------------------------------------------------------------
					//行動
					
					
					//4方向の移動は矢印により決定する。
					probability_sum = grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right  +
								grid.box[Agent_X][Agent_Y].down + grid.box[Agent_X][Agent_Y].left;
					//printf("probability_sum = %f\n",probability_sum);
					
					
					//矢印に基づいてエージェントを移動させる。
					direction = (double)rand() / RAND_MAX * probability_sum;
					
					
					record_X[step] = Agent_X;
					record_Y[step] = Agent_Y;
					
					//上へ進む場合
					
					if(direction < grid.box[Agent_X][Agent_Y].up){
							
							Agent_Y = Agent_Y -1;
						
						}
						
						//右へ進む場合
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right){
						
							Agent_X = Agent_X  + 1;
						}
						
						//下へ進む場合
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right + 
						 		grid.box[Agent_X][Agent_Y].down){
							
							Agent_Y = Agent_Y  + 1;
						}
						
						//左へ進む場合
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right  +
								grid.box[Agent_X][Agent_Y].down + grid.box[Agent_X][Agent_Y].left
						){
							
							Agent_X = Agent_X -1;
						}
						
						//break;
						
						//-------------------------------------------------------------
						
						//移動した場所にゴールがあるか判定
						
						if(Agent_X == x_goal && Agent_Y == y_goal){
								//今の場所がゴールである
								goalnum++;
								
								//ループを抜ける
								
								break;
								
						}
				}
				
		//			//***********確認***********
		//					printf("%f\n",grid.box[Agent_X][Agent_Y].up);
		//					printf("%f\n",grid.box[Agent_X][Agent_Y].down);
		//					printf("%f\n",grid.box[Agent_X][Agent_Y].right);
		//					printf("%f\n",grid.box[Agent_X][Agent_Y].left);
		//			//***********確認***********
		//	｝
		
		}
	
			//評価終了
			//griddisp(x_goal,y_goal);
			printf("評価時のゴールの数＝%d\n",goalnum);
			//-------------------------------------------------------------
	
}
main(){
		printf("ゴール位置　＝　([%d].[%d])\n",x_goal,y_goal);

		learn_agent();
	
	//	evaluation();
}