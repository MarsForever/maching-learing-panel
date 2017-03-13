#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxAgentStep 8
#define SIZE 5  //グリッドワールドの大きさ

//構造体でグリッドワールド作成
 struct grid{
		union{
			struct{
				double up,down,left,right;
				};
			double arrow[4];
		};
}grid[SIZE][SIZE];

//構造体でグリッドワールド設定

//struct GridWorld{
//		Grid box[SIZE][SIZE];
//};


//行列の初期化

void gridworld(){
	int x, y;
	struct grid Grid;
	for(x = 0 ; x < SIZE ; x++){
		for(y = 0 ; y < SIZE ; y++){
		
			
			if(y == 0)
				grid[x][y].down=0.0;
			if(x == 0)
				grid[x][y].left=0.0;
			if(y ==(SIZE-1) ) grid[x][y].up = 0.0;
			if(x ==(SIZE-1) ) grid[x][y].right = 0.0;	
			//0だらけ
		}
	}
		
			grid[x][y].up =0.25;
			grid[x][y].right =0.25;
			grid[x][y].down =0.25;
			grid[x][y].left =0.25;
			

		printf("%d\n",grid[x][y].up);		
		printf("%d\n",grid[x][y].down);	
		printf("%d\n",grid[x][y].right);
		printf("%d\n",grid[x][y].left);	
	


}

void LearnAgent(void){
	
	//乱数の初期化	
	int AgentAxisX,AgentAxisY;		//エージェントの位置
	srand((unsigned)time(NULL));

	double ProbablitySum;
	double Direction;

	gridworld();

	AgentAxisX = rand()%SIZE;
	AgentAxisY = rand()%SIZE;

	for(int step = 0 ; step <MaxAgentStep ; step++){
			ProbablitySum=grid[AgentAxisX][AgentAxisY].up+grid[AgentAxisX][AgentAxisY].down+grid[AgentAxisX][AgentAxisY].left+grid[AgentAxisX][AgentAxisY].right;
			

			
	}
}      

int main(){
	LearnAgent();
} 