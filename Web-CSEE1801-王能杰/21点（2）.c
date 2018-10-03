#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct base
{
	char name[8];
	int value;
	_Bool geted;
	_Bool isA;
};

void getpoker(struct base poker[], struct base object[], int *ptr);
void display(struct base object[], int n);
void displayall(struct base object[], int n,char who[8]);
int count(struct base object[], int n);
void selectbanker(struct base poker[], struct base banker[], int *ptr,_Bool *select);
void compare(struct base banker[], struct base player[],int i, int j);
int countA(struct base object[], int n);

int main(void)
{
	char ch;
	srand(time(NULL));
	puts("欢迎来到史上最简陋的21点小游戏 (＾＿＾)\n\n"
	     "鉴于作者实在太懒，这里不赘述21点游戏的规则。详情请咨询……百度/Google\n\n"
	     "补充说明，本游戏中所有牌皆为暗牌\n\n"
	     "如果出bug卡住……请关掉重启……\n");
	puts("是否开始一局新游戏？（输入y或任意键开始游戏，输入n退出游戏）\n");
	ch = getchar();
	while (getchar() != '\n')
		continue;
	switch (ch)
	{
	case 'y':
		break;
	case 'n':
		return 0;
	default:
		break;
	}
	
	do {
		struct base poker[52] = {
			{"黑桃A",1,false,true},{"红心A",1,false,true},{"草花A",1,false,true},{"方片A",1,false,true},
			{"黑桃2",2,false,false},{"红心2",2,false,false},{"草花2",2,false,false},{"方片2",2,false,false},
			{"黑桃3",3,false,false},{"红心3",3,false,false},{"草花3",3,false,false},{"方片3",3,false,false},
			{"黑桃4",4,false,false},{"红心4",4,false,false},{"草花4",4,false,false},{"方片4",4,false,false},
			{"黑桃5",5,false,false},{"红心5",5,false,false},{"草花5",5,false,false},{"方片5",5,false,false},
			{"黑桃6",6,false,false},{"红心6",6,false,false},{"草花6",6,false,false},{"方片6",6,false,false},
			{"黑桃7",7,false,false},{"红心7",7,false,false},{"草花7",7,false,false},{"方片7",7,false,false},
			{"黑桃8",8,false,false},{"红心8",8,false,false},{"草花8",8,false,false},{"方片8",8,false,false},
			{"黑桃9",9,false,false},{"红心9",9,false,false},{"草花9",9,false,false},{"方片9",9,false,false},
			{"黑桃10",10,false,false},{"红心10",10,false,false},{"草花10",10,false,false},{"方片10",10,false,false},
			{"黑桃J",10,false,false},{"红心J",10,false,false},{"草花J",10,false,false},{"方片J",10,false,false},
			{"黑桃Q",10,false,false},{"红心Q",10,false,false},{"草花Q",10,false,false},{"方片Q",10,false,false},
			{"黑桃K",10,false,false},{"红心K",10,false,false},{"草花K",10,false,false},{"方片K",10,false,false}
		};
		struct base banker[12];
		struct base player[12];


		int i = 0, j = 0;
		_Bool chooseb, choosep;
		puts("\n开始游戏！双方抽牌！");
		getpoker(poker, banker, &i);
		getpoker(poker, player, &j);
		display(player, j);
		
		do {
			displayall(player, j, "您");

			if (count(player, j) > 21)
			{
				puts("\n您爆牌了！！！\n\n您输了！！！\n");
				break;
			}
			else
			{
				selectbanker(poker, banker, &i, &chooseb);
				if (count(banker, i) > 21)
				{
					displayall(banker, i, "庄家");
					puts("\n庄家爆牌了！！！\n\n您赢了！！！\n");
					break;
				}
			}
			if (count(banker, i) <= 21 && count(player, j) <= 21)
			{
				puts("您是否继续抽牌？（输入y或任意键抽牌，输入n放弃）\n");
				ch = getchar();
				while (getchar() != '\n')
					continue;
				switch (ch)
				{
				case 'y':
					choosep = true;
					getpoker(poker, player, &j);
					display(player, j);
					break;
				case 'n':
					choosep = false;
					break;
				default:
					choosep = true;
					getpoker(poker, player, &j);
					display(player, j);
					break;
				}
			}
		} while (choosep || chooseb);

		if ((!chooseb || !choosep) && (count(banker, i) <= 21 && count(player, j) <= 21))
			compare(banker, player, i, j);

		puts("是否开始一局新游戏（输入y或任意键重新开局，输入n退出游戏）\n");
		ch = getchar();
		while (getchar() != '\n')
			continue;
		switch (ch)
		{
		case 'y':
			puts("\n----------------------------------------------------------------------------------");
			break;
		case 'n':
			return 0;
		default:
			puts("\n----------------------------------------------------------------------------------");
			break;
		}
	}while (1);
	getchar();
	return 0;
}

void getpoker(struct base poker[],struct base object[], int * ptr)
{
	int k;
	k = rand() % 52;
	while (poker[k].geted==true)
		continue;
	poker[k].geted = true;
	object[*ptr].geted = poker[k].geted;
	object[*ptr].isA = poker[k].isA;
	strcpy(object[*ptr].name, poker[k].name);
	object[*ptr].value = poker[k].value;
	*ptr = *ptr + 1;
}

void display(struct base object[], int n)
{
	printf("\n您抽到了%s!\n", object[n - 1].name);
}

void displayall(struct base object[], int n, char who[8])
{
	int i = 0;
	printf("\n%s目前抽得的牌为：",who);
	for (i = 0; i < n; i++)
		printf(" %s", object[i].name);
	putchar('\n');
}

int count(struct base object[], int n)
{
	int total = 0;
	int i;
	for (i = 0; i < n; i++)
		total += object[i].value;
	return total;
}

void selectbanker(struct base poker[], struct base banker[], int *ptr,_Bool *select)
{
	int num,total1,total2;
	
	puts("\n----------------------------------------------------------------------------------");

	num = countA(banker, *ptr);
	total1 = count(banker, *ptr);
	total2 = total1 + 10;
	if (num == 0)
	{
		if (total1 <= 15)
		{
			puts("\n庄家选择了抽牌。\n");
			getpoker(poker, banker, ptr);
			*select = true;
		}
		else
		{
			puts("\n庄家放弃了抽牌。\n");
			*select = false;
		}
	}
	else
	{
		if ((total2 >= 16 && total2 <= 21) || (total2 > 21 && total1 > 15))
		{
			puts("\n庄家放弃了抽牌。\n");
			*select = false;
		}
		else
		{
			puts("\n庄家选择了抽牌。\n");
			getpoker(poker, banker, ptr);
			*select = true;
		}
	}
}

int countA(struct base object[], int n)
{
	int i = 0, num = 0;
	for (i = 0; i < n; i++)
		if (object[i].isA==true)
			num++;
	return num;
}

void compare(struct base banker[], struct base player[], int i, int j)
{
	displayall(player, j, "您");
	displayall(banker, i, "庄家");
	int talp1, talp2;
	int talb1, talb2;
	talp1 = count(player, j);
	talp2 = talp1 + 10;
	talb1 = count(banker, i);
	talb2 = talb1 + 10;
	if (countA(banker, j) > 0 && countA(player, i) > 0)
	{
		if (talb2 > 21 && talp2 > 21)
		{
			if (talb1 > talp1)
			{
				puts("\n您输了！！！\n");
				return;
			}
			else if (talb1 < talp1)
			{
				puts("\n您赢了！！！\n");
				return;
			}
			else
			{
				puts("\n平局！！！\n");
				return;
			}
		}
		else if (talb2 <= 21 && talp2 > 21)
		{
			if (talb2 == talp1)
			{
				puts("\n平局！！！\n");
				return;
			}
			else if (talb2 == (talb2 > talp1) ? talb2 : talp1)
			{
				puts("\n您输了！！！\n");
				return;
			}
			else
			{
				puts("\n您赢了！！！\n");
				return;
			}
		}
		else if (talp2 <= 21 && talb2 > 21)
		{
			if (talb1 == talp2)
			{
				puts("\n平局！！！\n");
				return;
			}
			else if (talb1 == (talb1 > talp2) ? talb1 : talp2)
			{
				puts("\n您输了！！！\n");
				return;
			}
			else
			{
				puts("\n您赢了！！！\n");
				return;
			}
		}
		else
		{
			if (talb2 == talp2)
			{
				puts("\n平局！！！\n");
				return;
			}
			else if (talb2 == (talb2 > talp2) ? talb2 : talp2)
			{
				puts("\n您输了！！！\n");
				return;
			}
			else
			{
				puts("\n您赢了！！！\n");
				return;
			}
		}
	}
	else if (countA(banker, j) == 0 && countA(player, i) > 0)
	{
		if (talp2 > 21)
		{
			if (talb1 > talp1)
			{
				puts("\n您输了！！！\n");
				return;
			}
			else if (talb1 < talp1)
			{
				puts("\n您赢了！！！\n");
				return;
			}
			else
			{
				puts("\n平局！！！\n");
				return;
			}
		}
		else
		{
			if (talb1 == talp2)
			{
				puts("\n平局！！！\n");
				return;
			}
			else if (talb1 >talp2)
			{
				puts("\n您输了！！！\n");
				return;
			}
			else
			{
				puts("\n您赢了！！！\n");
				return;
			}
		}
	}
	else if (countA(banker, j) > 0 && countA(player, i) == 0)
	{
	if (talb2 > 21)
	{
		if (talb1 > talp1)
		{
			puts("\n您输了！！！\n");
			return;
		}
		else if (talb1 < talp1)
		{
			puts("\n您赢了！！！\n");
			return;
		}
		else
		{
			puts("\n平局！！！\n");
			return;
		}
	}
	else
	{
		if (talb2 == talp1)
		{
			puts("\n平局！！！\n");
			return;
		}
		else if (talb2 == (talb2 > talp1) ? talb2 : talp1)
		{
			puts("\n您输了！！！\n");
			return;
		}
		else
		{
			puts("\n您赢了！！！\n");
			return;
		}
	}
    }
	else
	{
	if (talb1 > talp1)
	{
		puts("\n您输了！！！\n");
		return;
	}
	else if (talb1 < talp1)
	{
		puts("\n您赢了！！！\n");
		return;
	}
	else
	{
		puts("\n平局！！！\n");
		return;
	}
	}
}
