#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxAgentStep 8
#define SIZE 5  //�O���b�h���[���h�̑傫��

//�\���̂ŃO���b�h���[���h�쐬
 struct grid{
		union{
			struct{
				double up,down,left,right;
				};
			double arrow[4];
		};
}grid[SIZE][SIZE];

//�\���̂ŃO���b�h���[���h�ݒ�

//struct GridWorld{
//		Grid box[SIZE][SIZE];
//};


//�s��̏�����

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
			//0���炯
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
	
	//�����̏�����	
	int AgentAxisX,AgentAxisY;		//�G�[�W�F���g�̈ʒu
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