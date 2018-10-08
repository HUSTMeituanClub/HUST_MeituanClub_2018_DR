#include<stdio.h>
#include<stdlib.h>

int main()
{
	char ch1;
	printf("21点游戏\n请输入:");
	ch1=getchar();
	switch(ch1)
	{
		case'y':
		     puts("OK");
		     break;
		case'n':
			puts("Not bad");
			break;
		case'q':
		    puts("Bye");	
		    break;
		default:
		    	break;
    }
    system("pause");
    return 0;
    
}
