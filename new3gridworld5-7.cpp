#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxAgentStep 24
#define SIZE 5  //�O���b�h���[���h�̑傫��

//�\���̂ŃO���b�h���[���h�쐬
 typedef struct GRID{
	double a[4];
}Grid;

 Grid grid[SIZE][SIZE];


/*void gridworld(){
	grid[1][1].a[1]=2.0;
	printf("%3d",grid[1][1].a[1]);
}*/

void LearnAgent(void){
	
	//�����̏�����	
	int AgentAxisX,AgentAxisY;		//�G�[�W�F���g�̈ʒu
	srand((unsigned)time(NULL));

	double ProbablitySum;
	double Direction;

	//gridworld();

	AgentAxisX = rand()%SIZE;
	AgentAxisY = rand()%SIZE;

	for(int step = 0 ; step <MaxAgentStep ; step++){
		//	ProbablitySum=grid[AgentAxisX][AgentAxisY].up+grid[AgentAxisX][AgentAxisY].down+grid[AgentAxisX][AgentAxisY].left+grid[AgentAxisX][AgentAxisY].right;
			

			
	}
}      

int main(){
	grid[1][1].a[1]=2.0;
	printf("%3d",grid[1][1].a[1]);
} 