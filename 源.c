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
            continue;							//清空行
	switch (ch)                            //玩家是否进入游戏
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
		signed int poker[52] =         //构建牌堆
		{
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10
		};
		do
		{
			int maker[10] = { 0 };    //构建庄家手牌
			int player[10] = { 0 };   //构建玩家手牌
			int card;
			int i = 2, j = 2;
			int sum_maker;
			int sum_player;
			printf("Let's play the wonderful game now!\n");

			card = rand() % 52;
			maker[0] = poker[card];
			card = rand() % 52;
			maker[1] = poker[card];   //为庄家发两张初始牌

			card = rand() % 52;
			player[0] = poker[card];
			card = rand() % 52;
			player[1] = poker[card];   //为玩家发两张初始牌

			sum_maker = maker[0] + maker[1];
			sum_player = player[0] + player[1];    //计算点数和

			do
			{
				if (sum_maker < 16)
				{
					card = rand() % 52;       //随机生成card值
					maker[j] = poker[card];
					sum_maker += maker[j];
					j++;
				}
				if (sum_maker > 21)
				{
					printf("Congratulations！You win the game!\n");
					return 0;
				}
				if (sum_maker >= 16 && sum_maker <= 21)
					break;
			} while (sum_maker < 16);             //庄家的游戏方法

			printf("Now,you have point %d and point %d. Your poker points are %d in all,player.\n",player[0],player[1], sum_player); 
			printf("Do you want a new card?\n");
			printf("Please enter y to continue or n to stop.\n");         //询问玩家是否要牌

			c_h= getchar();
			while (getchar() != '\n')
					continue;                    //要牌后的操作
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
							case 'n':     //要过牌后不再要牌
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
								break;      //退出此开关
						}
					}
					else        //玩家要牌后爆牌
					{
						printf("What a pity,you lose the game!\n");
					}
				} while (cch= 'y'&&sum_player<=21);     //此时若上面输入了y要牌且还没爆，继续加牌
			
			case 'n':                           //玩家不要牌直接比大小
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
					"Please enter y to continue or n to quit.\n");      //是否开始一局新的比赛
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
