#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxAgentStep 24
#define SIZE 5  //グリッドワールドの大きさ

//構造体でグリッドワールド作成
struct Grid{
		union{
			struct{
				double up,down,left,right;
				};
			double arrow[4];
		};
};

//構造体でグリッドワールド設定

struct GridWorld{
		Grid box[SIZE][SIZE];
};

struct GridWorld grid;

//行列の初期化
void gridworld(void){
	int x,y;
	for(x = 0 ; x < SIZE ; x++){
		for(y = 0 ; y < SIZE ; y++){
			
			Grid.box[x][y].up =0.25;
			Grid.box[x][y].right =0.25;
			Grid.box[x][y].down =0.25;
			Grid.box[x][y].left =0.25;
			
			
			if(y == 0)
				 Grid.box[x][y].down=0.0;
			if(x == 0)
			 	 Grid.box[x][y].left=0.0;
			if(y == (SIZE-1))
				 Grid.box[x][y].up=0.0;
			if(x == (SIZE-1))
				 Grid.box[x][y].right=0.0;
		}
	}
	
	
}

void LearnAgent(void){
	
	//乱数の初期化	
	int AgentAxisX,AgenAxistY;		//エージェントの位置
	srand(unsigned)(time(NULL));
		AgentAxisX = rand()%SIZE;
		AgentAxisY = rand()%SIZE;
		
		Grid.box[AgentAxisX][AgentAxisY]
	
	

}
