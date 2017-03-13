#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define size 5  //�O���b�h���[���h�̑傫��

#define L_Agent_step 20 //�w�K���̃G�[�W�F���g�̈ړ������i�X�e�b�v���j
#define E_Agent_step 20 //�]�����̃G�[�W�F���g�̈ړ������i�X�e�b�v���j
#define P 2.0 //��V���̌W��
#define T 10 //�w�K�����̒���

int record_X[L_Agent_step]; //�ړ��̗���
int record_Y[L_Agent_step];
int record_Dir[L_Agent_step];

//�S�[���n�_��ݒ�i�S�[���l�̏������j

int x_goal = 0;
int y_goal = 0;
//File  *FP;

//�\���̂ŃO���b�h���[���h�쐬
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

//�\���̂ŃO���b�h���[���h��ݒ�

struct GRIDWORLD{
		GRID box[size][size];
};

GRIDWORLD grid;

//�O���b�h���[���h
//�o�����[�^�[�i�m���j�̏�����

void gridworld(void)
{
	int x,y; //�O���b�h���[���h��X���W�AY���W
	//��󏉊����i���̒������O�ɐݒ�j
	
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
		//�����̏�����
		srand(0);
		
		
		//-------------------------------------------------------------
		//�w�K
		//-------------------------------------------------------------


		//4�����̊m���͓����ɐݒ�//�O���b�h���[���h�쐬���ɐݒ�ς�

		//�w�K�̊e�o�����[�^��ݒ�

		const int max_learn_count = 100;
		int i = 0;
		//int record_X[Agent_step];//�ړ��̗���
		//int record_Y[Agent_step];
		//int record_Dir[Agent_step];
		int Agent_X,Agent_Y; //�G�[�W�F���g�̃X�^�[�g�ʒu
		int goalnum = 0; //�G�[�W�F���g���S�[���ɒ��������m�F���邽�߂ɓ����ϐ�
		double probability_sum; 	//�S�����̊m���̍��v
		double direction; //4�����̊m���̍��v�ɂ�����
		
		
		gridworld();
		
		
		//�񐔂܂ŌJ��Ԃ�
		//�K�v�ȕϐ��F���݂̊w�K�񐔁i�����l 0�jlearn_count�A�w�K���s����max_learn_count100
		int Learn_count;
		
		for(Learn_count = 0 ; Learn_count < max_learn_count ; Learn_count ++)  //�w�K�񐔂ɓ��B���ĂȂ�
		{
					//�C�ӂ̃X�^�[�g�ʒu�ɔz�u
					//�G�[�W�F���g�̍��W = rand�̒l�i�@0����@�S(size)�j������B
					Agent_X = rand() % size;
					Agent_Y = rand() % size;
					
					//�K��̃X�e�b�v���̌J��Ԃ�
					for(int step = 0 ; step < L_Agent_step; step ++){
						printf("�ʒu�@�@���@[%d][%d]\n",Agent_X,Agent_Y);
						
						//-------------------------------------------------------------
						//�s��
						
						//�S�����̈ړ��͊m���ɂ�茈�肷��B
						
						probability_sum = grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right+
						grid.box[Agent_X][Agent_Y].down +grid.box[Agent_X][Agent_Y].left;
						printf("probability_sum = %f\n",probability_sum);
						
						//�m���Ɋ�Â��ăG�[�W�F���g���ړ�������B
						
						
						direction = (double)rand() /RAND_MAX * probability_sum;
						
						record_X[step] = Agent_X;
						record_Y[step] = Agent_Y;
						
						//��֐i�ޏꍇ
						
						if(direction < grid.box[Agent_X][Agent_Y].up){
							record_Dir[step] = 0;
							Agent_Y = Agent_Y -1;
						
						}
						//�E�֐i�ޏꍇ
						
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right){
							record_Dir[step] = 1;
							Agent_Y = Agent_Y -1;
						}
						
						//���֐i�ޏꍇ
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right + 
						 		grid.box[Agent_X][Agent_Y].down){
							record_Dir[step] = 2;
							Agent_Y = Agent_Y -1;
						}
						
						//���֐i�ޏꍇ
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right  +
								grid.box[Agent_X][Agent_Y].down + grid.box[Agent_X][Agent_Y].left){
							record_Dir[step] = 3;
							Agent_Y = Agent_Y -1;
						}
						
						//break;
						
						//-------------------------------------------------------------
						
						//�ړ������ꏊ�ɃS�[�������邩�𔻒�
						
						if(Agent_X == x_goal && Agent_Y == y_goal){
									//���̏ꏊ���S�[���ł���
									
									goalnum++;
									
									////�S�[���ɓ��B�����ꍇ�́A�G�[�W�F���g�ɕ�V��^����
									for(int t = 0 ; t<= T && t<= step ; t++){
										////��A�̍s���ɑ΂��ĕ�V�𕪔z
												grid.box[record_X[step-t]][record_Y[step-t]].arrow[record_Dir[step-t]]
												=grid.box[record_X[step-t]][record_Y[step-t]].arrow[record_Dir[step-t]]+P * (T - t + 1)/ T;
									}
									
									
									//���[�v�𔲂���
									break;
							}
					}
							//***********�m�F***********
							printf("%f\n",grid.box[Agent_X][Agent_Y].up);
							printf("%f\n",grid.box[Agent_X][Agent_Y].down);
							printf("%f\n",grid.box[Agent_X][Agent_Y].right);
							printf("%f\n",grid.box[Agent_X][Agent_Y].left);
							//***********�m�F***********
				
			//	}
	
	
		}	

//�w�K�I��
	griddisp(x_goal,y_goal);
	printf("�w�K���̃S�[���̐� = %d\n", goalnum);
	
	//-------------------------------------------------------------
}

void evaluation(void){
		//�����̏�����
		srand(0);
	
	
		//printf("�S�[���ʒu�@�@�� ([%d][%d]\n)",x_goal,y_goal);
		
		//-------------------------------------------------------------
		//�]��
		//-------------------------------------------------------------
		
		//�S�����̊m���͓����ɐݒ�//�O���b�h���[���h�쐬���ɐݒ�ς�
		
		//�]���̊e�o�����[�^��ݒ�
		
		const int max_Evaluation_count = 100;
		int i = 0;
		int Agent_X,Agent_Y; //�G�[�W�F���g�̃X��=�ƈʒu
		int goalnum = 0;  //�G�[�W�F���g���S�[���ɒ��������m�F���邽�߂ɓ����ϐ�
		double probability_sum; //4�����̊m���̍��v
		double direction; //�S�����̊m���̍��v�ɂ�����
		
		
		
		
		//�]�����������܂�
		//�K�v�ȕϐ��F���݂̊w�K�񐔁i�����l�O�jEvaluation_count,�]�����s����max_Evaluation_count 100
		int Evaluation_count = 0;
		
		for(Evaluation_count = 0; Evaluation_count < max_Evaluation_count; Evaluation_count++){ //�]���񐔂ɓ��B���ĂȂ�
				//�C�ӂ̃X�^�[�g�ʒu�ɔz�u
				//�G�[�W�F���g�̍��W = rand�̒l�i�O����S(size)�j������B
				
				Agent_X = rand()% size;
				Agent_Y = rand()% size;
				
				//�K��̃X�e�b�v���̌J��Ԃ�
				for(int step = 0 ; step < E_Agent_step ; step++)
				{
					//printf("�ʒu   =  [%d].[%d]\n", Agent_X,Agent_Y);
					//-------------------------------------------------------------
					//�s��
					
					
					//4�����̈ړ��͖��ɂ�茈�肷��B
					probability_sum = grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right  +
								grid.box[Agent_X][Agent_Y].down + grid.box[Agent_X][Agent_Y].left;
					//printf("probability_sum = %f\n",probability_sum);
					
					
					//���Ɋ�Â��ăG�[�W�F���g���ړ�������B
					direction = (double)rand() / RAND_MAX * probability_sum;
					
					
					record_X[step] = Agent_X;
					record_Y[step] = Agent_Y;
					
					//��֐i�ޏꍇ
					
					if(direction < grid.box[Agent_X][Agent_Y].up){
							
							Agent_Y = Agent_Y -1;
						
						}
						
						//�E�֐i�ޏꍇ
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right){
						
							Agent_X = Agent_X  + 1;
						}
						
						//���֐i�ޏꍇ
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right + 
						 		grid.box[Agent_X][Agent_Y].down){
							
							Agent_Y = Agent_Y  + 1;
						}
						
						//���֐i�ޏꍇ
						else if(direction < grid.box[Agent_X][Agent_Y].up + grid.box[Agent_X][Agent_Y].right  +
								grid.box[Agent_X][Agent_Y].down + grid.box[Agent_X][Agent_Y].left
						){
							
							Agent_X = Agent_X -1;
						}
						
						//break;
						
						//-------------------------------------------------------------
						
						//�ړ������ꏊ�ɃS�[�������邩����
						
						if(Agent_X == x_goal && Agent_Y == y_goal){
								//���̏ꏊ���S�[���ł���
								goalnum++;
								
								//���[�v�𔲂���
								
								break;
								
						}
				}
				
		//			//***********�m�F***********
		//					printf("%f\n",grid.box[Agent_X][Agent_Y].up);
		//					printf("%f\n",grid.box[Agent_X][Agent_Y].down);
		//					printf("%f\n",grid.box[Agent_X][Agent_Y].right);
		//					printf("%f\n",grid.box[Agent_X][Agent_Y].left);
		//			//***********�m�F***********
		//	�p
		
		}
	
			//�]���I��
			//griddisp(x_goal,y_goal);
			printf("�]�����̃S�[���̐���%d\n",goalnum);
			//-------------------------------------------------------------
	
}
main(){
		printf("�S�[���ʒu�@���@([%d].[%d])\n",x_goal,y_goal);

		learn_agent();
	
	//	evaluation();
}