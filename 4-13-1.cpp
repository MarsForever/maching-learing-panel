#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxAgentStep 24
#define SIZE 5  //�O���b�h���[���h�̑傫��

//�\���̂ŃO���b�h���[���h�쐬
struct Grid{
		union{
			struct{
				double up,down,left,right;
				};
			double arrow[4];
		};
};

//�\���̂ŃO���b�h���[���h�ݒ�

struct GridWorld{
		Grid box[SIZE][SIZE];
};

struct GridWorld grid;

//�s��̏�����
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
	
	//�����̏�����	
	int AgentAxisX,AgenAxistY;		//�G�[�W�F���g�̈ʒu
	srand(unsigned)(time(NULL));
		AgentAxisX = rand()%SIZE;
		AgentAxisY = rand()%SIZE;
		
		Grid.box[AgentAxisX][AgentAxisY]
	
	

}
