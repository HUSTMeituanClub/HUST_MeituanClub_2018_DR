#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	printf("Welcome to my gaming house!\nHere,A is one point,J,Q,K are ten points.\n");
	printf("enter y to start or q to exit.\n");
	char ch, cch, cc_h, c_h;
	ch = getchar();
	while (getchar() != '\n')
            continue;							//�����
	switch (ch)                            //����Ƿ������Ϸ
	{
	case 'y':
            break;
	case 'n':
            return 0;
    default:
            break;
	}

	do
	{
		srand((int)time(NULL));
		signed int poker[52] =         //�����ƶ�
		{
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10
		};
		do
		{
			int maker[10] = { 0 };    //����ׯ������
			int player[10] = { 0 };   //�����������
			int card;
			int i = 2, j = 2;
			int sum_maker;
			int sum_player;
			printf("Let's play the wonderful game now!\n");

			card = rand() % 52;
			maker[0] = poker[card];
			card = rand() % 52;
			maker[1] = poker[card];   //Ϊׯ�ҷ����ų�ʼ��

			card = rand() % 52;
			player[0] = poker[card];
			card = rand() % 52;
			player[1] = poker[card];   //Ϊ��ҷ����ų�ʼ��

			sum_maker = maker[0] + maker[1];
			sum_player = player[0] + player[1];    //���������

			do
			{
				if (sum_maker < 16)
				{
					card = rand() % 52;       //�������cardֵ
					maker[j] = poker[card];
					sum_maker += maker[j];
					j++;
				}
				if (sum_maker > 21)
				{
					printf("Congratulations��You win the game!\n");
					return 0;
				}
				if (sum_maker >= 16 && sum_maker <= 21)
					break;
			} while (sum_maker < 16);             //ׯ�ҵ���Ϸ����

			printf("Now,you have point %d and point %d. Your poker points are %d in all,player.\n",player[0],player[1], sum_player); 
			printf("Do you want a new card?\n");
			printf("Please enter y to continue or n to stop.\n");         //ѯ������Ƿ�Ҫ��

			c_h= getchar();
			while (getchar() != '\n')
					continue;                    //Ҫ�ƺ�Ĳ���
			switch(c_h)
			{
			case 'y':
				do
				{
					card = rand() % 52;
					player[i] = poker[card];
					printf("You get point %d.", player[i]);
					sum_player += player[i];
					printf("Now,your points is %d.", sum_player);
					i++;
					if (sum_player <= 21)
					{
						printf("Do you want a new card?\n"
								"please enter y to continue or n to stop\n", sum_player);
						cch = getchar();
						while (getchar() != '\n')
							continue;
						switch (cch)
						{
							case 'y':
								break;
							case 'n':     //Ҫ���ƺ���Ҫ��
								if (sum_maker > sum_player&&sum_maker <= 21)
								{
									printf("The maker points are %d.\nYour points are %d.\n", sum_maker, sum_player);
									printf("What a pity,you lose the game!\n");
								}
								if (sum_maker == sum_player && sum_player <= 21)
								{
									printf("The maker points are %d.\nYour points are %d.\n", sum_maker, sum_player);
									printf("Push!\n");
								}
								if (sum_maker < sum_player&&sum_player <= 21)
								{
									printf("The maker points are %d.\nYour points are %d\n", sum_maker, sum_player);
									printf("Congratulations,you win the game!\n\n");
								}
								break;      //�˳��˿���
						}
					}
					else        //���Ҫ�ƺ���
					{
						printf("What a pity,you lose the game!\n");
					}
				} while (cch= 'y'&&sum_player<=21);     //��ʱ������������yҪ���һ�û������������
			
			case 'n':                           //��Ҳ�Ҫ��ֱ�ӱȴ�С
				if (sum_maker > sum_player&&sum_maker<=21)
				{
					printf("The maker points are %d.\nYour points are %d.\n", sum_maker, sum_player);
					printf("What a pity,you lose the game!\n");
				};
				if (sum_maker == sum_player&&sum_player<=21)
				{
					printf("The maker points are %d.\nYour points are %d.\n", sum_maker, sum_player);
					printf("Push!\n");
				};
				if (sum_maker < sum_player&&sum_player<=21)
				{
					printf("The maker points are %d.\nYour points are %d.\n", sum_maker, sum_player);
					printf("Congratulations,you win the game!\n\n");
				};
			}
			printf("Do you want to begin a new game?"
					"Please enter y to continue or n to quit.\n");      //�Ƿ�ʼһ���µı���
			cc_h= getchar();
			while (getchar() != '\n')
				continue;
			switch (cc_h)
			{
				case'y':
					break;
				case'n':
					return 0;
			}
		} while (cc_h = 'p');
	}while (cc_h = 'y');
	return 0;
}
