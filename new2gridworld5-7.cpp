#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxAgentStep 24
#define SIZE 5  //グリッドワールドの大きさ

//構造体でグリッドワールド作成
 struct GRID{
	struct{
	double up;
	double down;
	double left;
	double right;
	};
}grid[SIZE][SIZE];


/*void gridworld(){
	grid[1][1].down=2.0;
	printf("%3d",grid[1][1].down);
}*/

void LearnAgent(void){
	
	//乱数の初期化	
	int AgentAxisX,AgentAxisY;		//エージェントの位置
	srand((unsigned)time(NULL));

	double ProbablitySum;
	double Direction;

	//gridworld();

	AgentAxisX = rand()%SIZE;
	AgentAxisY = rand()%SIZE;

	for(int step = 0 ; step <MaxAgentStep ; step++){
			ProbablitySum=grid[AgentAxisX][AgentAxisY].up+grid[AgentAxisX][AgentAxisY].down+grid[AgentAxisX][AgentAxisY].left+grid[AgentAxisX][AgentAxisY].right;
			

			
	}
}      

int main(){
	int x, y;
	
	for(x = 0 ; x < 5 ; x++){
		for(y = 0 ; y < 5 ; y++){
			grid[x][y].up =0.25;
			grid[x][y].right =0.25;
			grid[x][y].down =0.25;
			grid[x][y].left =0.25;
		
			printf("%3d",grid[x][y].up);		
		putchar('\n');
			printf("%3d",grid[x][y].down);
		putchar('\n');
			printf("%3d",grid[x][y].right);
		putchar('\n');
			printf("%3d",grid[x][y].left);	
		putchar('\n');
		
			if(y == 0)
				grid[x][y].down=0.0;
			if(x == 0)
				grid[x][y].left=0.0;
			if(y ==(SIZE-1) ) grid[x][y].up = 0.0;
			if(x ==(SIZE-1) ) grid[x][y].right = 0.0;
		} 
	}
}