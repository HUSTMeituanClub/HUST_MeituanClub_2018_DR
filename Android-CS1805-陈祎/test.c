#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define LEN 52

void randPoker(int *);
int cresp(int * , int *);
int choice(int *, int *);
void check(int *, char *);
void ruler();

int main()
{
    //打个广告
	system("title CY OF MEITUAN");
	
	//宣读规则
	ruler();
	
	/*生成一个长度为LEN的顺序数组*/
    int poker[LEN];
    for(int i = 0;i < LEN;i ++)
        poker[i] = i + 1;
    
    /*生成一个长度为LEN的无序数组*/
    randPoker(poker);

    int s1 = 0;//庄家的总点数
	int s2 = 0;//玩家的总点数
	
	int mark1;
	int mark2;
	
	int turn = 1;//轮次
    int k = 0;//发牌数
	
	/*先处理直接发牌的第一轮*/
	printf("荷官:开始发牌,现在是第%d轮\n", turn);
	printf("庄家");	
	s1 += cresp(poker, &k);
	k++;	
	printf("玩家");
    s2 += cresp(poker, &k);
	k++;
	turn ++;
	
	printf("---------按任意键进入下一回合---------\n");
	system("pause > nul");
	//system("cls");//处理屏幕
	
	
    /*抽牌阶段*/
    while(turn != 1)
    {
        
        if(mark1 != 0)
		{
			/*庄家回合*/  
		printf("荷官:开始发牌,现在是第%d轮\n", turn);		
        printf("---------------庄家回合---------------\n");
		printf("庄家:直到上一轮你的总点数为%d\n", s1);
		mark1 = choice(poker, &k);//人工庄家
        s1 += mark1; 
		printf("当前你的总分为:%d\n", s1);		
        
		printf("--------------------------------------\n");
		//system("pause > nul");
		}else printf("-------------庄家已经放弃-------------\n");
        
		
        		
        //system("cls");//处理屏幕
        if(mark2 != 0)
		{
			/*玩家回合*/
		printf("荷官:开始发牌,现在是第%d轮\n", turn);
		printf("---------------玩家回合---------------\n");
		printf("玩家:直到上一轮你的总点数为%d\n", s2);		
        mark2 = choice(poker, &k);//获取当前牌的数值 		
        s2 += mark2;
		printf("当前你的总分为:%d\n", s2);
        
		printf("--------------------------------------\n");	
        //system("pause > nul"); 		
		}else printf("-------------玩家已经放弃-------------\n");
		
		//结算
		if (s1>21 && s2<22) 
        {
            //system("cls");//处理屏幕
			printf("庄家:\n");
			for(int i = 0;i < (s2/2);i ++)
				printf("你爆点了！玩家获胜。\n");
			printf("按任意键结束游戏！\n");
			system("pause > nul");
            break;
        }else if (s2>21 && s1<22) 
        {
            //system("cls");//处理屏幕
			printf("玩家:\n");
			for(int i = 0;i < (s1/2);i ++)
				printf("你爆点了！庄家获胜。\n");
			printf("按任意键结束游戏！\n");
			system("pause > nul");
            break;
        }else if(s1>21&&s2>21)
		{
			printf("荷官:由于庄家玩家同时获胜，按规则庄家获胜！");
		  
        }
		turn ++;//轮次+1
		
		//system("cls");//处理屏幕

        //处理玩家庄家同时放弃的情况
        if ((mark1 == 0)&&(mark2 == 0)) 
        {
            
            printf("荷官:由于庄家和玩家同时放弃，现在进入结算阶段...\n");
			if (s1 == s2) 
            {
                printf("push状态:庄家和玩家打成平局！\n");
				system("pause > nul");
				break;
            }else if(s1 > s2) 
            {
               printf("庄家胜利！");
			   system("pause > nul");
			   break;
            }else 
            {
                printf("玩家胜利！");
				system("pause > nul");
				break;
            }
            
        }
        
    }
    
    return 0;
}

void randPoker(int * p)
{
     //接受poker，对其无序化
     for(int i = LEN;i > 1;i --)
     {
        srand((unsigned int)time(0));
        int r = rand() % i;
        int temp;
	    temp = p[i - 1];
	    p[i - 1] = p[r];
	    p[r] = temp;
     }
	
    
}

int cresp(int * p, int * k)
{
    int chk = (p[*k] % 13)+1;
	if(p[*k] < 14)
	{
		char hs[5] = "红桃";
		check(&chk, hs);
	}else if(p[*k] < 27)
	{
		char hs[5] = "方块";
		check(&chk, hs);
	}else if(p[*k] < 40)
	{
		char hs[5] = "黑桃";
		check(&chk, hs);
	}else
	{
		char hs[5] = "梅花";
		check(&chk, hs);
	}
	
	return chk;
}

int choice(int * p, int * k)
{
    int num;
    int m;
    
	printf("是否接受本轮发牌？(1.接受2.放弃)\n");
	printf("你的选择是:");
    
	/*处理非法输入的情况*/
	while(scanf("%d", &num) != 1)
	{
		while((getchar())!='\n')/*清空输入流*/
			continue;
		printf("请使用合法输入(1/2)!!\n你的选择是:");
		continue;
	}
    switch (num)
    {
        case 1:
            m = cresp(p, k);
            (*k) ++;
            return m;
            break;
        case 2:
            m = 0;
			printf("你放弃了本回合!!\n");
            return m;
            break;
    }	
    
}

void check(int * c, char * str)
{
	if(*c == 1)
	{
		printf("你抽到的是\"%sA\"\n", str);
		*c = 11;
	}else if(*c == 11)
    {
        printf("你抽到的是\"%sJ\"\n", str);
		*c = 10;
    }else if(*c == 12)
    {
        printf("你抽到的是\"%sQ\"\n", str);
		*c = 10;
    }else if(*c == 13)
    {
        printf("你抽到的是\"%sK\"\n", str);
		*c = 10;
    }else printf("抽到的是\"%s%d\"\n", str, *c);
	
}

void ruler()
{
	printf("----------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------规则介绍-------------------------------------------\n");
	printf("1.牌组有花色,但不同花色牌不影响点数.\n2.A记11点, J,Q,K都记10点,牌面2-9以该数字记点.\n");
	printf("3.放弃摸牌的一方将失去后轮的摸牌机会！双方同时放弃则比较当前双方点数之和，高者获胜.\n");
	printf("4.若一轮中双方同时爆牌,则玩家失败,庄家获胜！\n");
	printf("-------------------------------------------规则介绍-------------------------------------------\n");
	printf("---------------------------------------按任意键开始游戏---------------------------------------\n");
	system("pause > nul");
	system("cls");//处理屏幕
}
