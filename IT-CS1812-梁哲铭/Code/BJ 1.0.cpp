#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

int p[5],b[5];
int np,nb,sp,sb;
int i,cz;

void shuffle(){
	srand(time(0));
	np = 2;
	p[0] = rand() % 10 + 1;
	p[1] = rand() % 10 + 1;
	sp = p[0] + p[1];	
	nb = 2;
	b[0] = rand() % 10 + 1;
	b[1] = rand() % 10 + 1;
	sb = b[0] + b[1];
}
void display(){
	printf("Player: ");
	for (i = 0; i < np; i++) printf("%d ",p[i]);//p[0..n-1]
	printf("    score: %d\n",sp);
	printf("Banker: ");
	for (i = 0; i < nb; i++) printf("%d ",b[i]);//b[0..n-1]
	printf("    score: %d\n",sb);	
}

int main(){
	shuffle();
	display();
	while (sp < 22){	//player
		printf("Player do:   1.stand   2.hit   3.quit\n");
		scanf("%d", &cz); //switch!!
		if (cz == 2) {	//hit
			np++;
			p[np-1] = rand() % 10 + 1;
			sp += p[np-1];
		};
		if (cz == 3) return 0;//quit
		display();
		if (cz == 1) break;//stand		
	}
	if (sp < 22) while (sb < 22){ //Banker
		printf("Banker do:   1.stand   2.hit   3.quit\n");
		scanf("%d", &cz);//switch!!
		if (cz == 1) break;//stand
		if (cz == 2) {	//hit
			nb++;
			b[nb-1] = rand() % 10 + 1;
			sb += b[nb-1];
		};
		if (cz == 3) return 0;//quit
		display();	
	}; 
	
	if (((sp > sb) && (sp < 22)) or (sb > 21)) printf("Player win") ;else printf("Banker win");
	return 0;
}
