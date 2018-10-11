#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

int p[5],b[5];
int np,nb,sp,sb,npa,nba;
int i,cz;

void shuffle(){
	srand(time(0));
	np = 2;
	npa = 0;
	p[0] = rand() % 13 + 1;
	p[1] = rand() % 13 + 1;
	if (p[0] == 1) npa++;
	if (p[1] == 1) npa++;
	sp = min(10,p[0]) + min(10,p[1]);	
	nb = 2;
	nba = 0;
	b[0] = rand() % 13 + 1;
	b[1] = rand() % 13 + 1;
	if (b[0] == 1) nba++;
	if (b[1] == 1) nba++;
	sb = min(10,b[0]) + min(10,b[1]);
}
void display(){
	printf("Player: ");
	for (i = 0; i < np; i++) {
		if (p[i] == 11) printf("J ");
		if (p[i] == 12) printf("Q ");
		if (p[i] == 13) printf("K ");
		if (p[i] < 11) printf("%d ",p[i]);
	}
	if ((npa > 0) && (sp + 10 < 22)) sp+=10;
	printf("    score: %d\n",sp);
	printf("Banker: ");
	for (i = 0; i < nb; i++) {
		if (b[i] == 11) printf("J ");
		if (b[i] == 12) printf("Q ");
		if (b[i] == 13) printf("K ");
		if (b[i] < 11) printf("%d ",b[i]);
	}
	if ((nba > 0) && (sb + 10 < 22)) sb+=10;
	printf("    score: %d\n",sb);	
}

int main(){
	printf("Welcome to Blackjack!\n");
	shuffle();
	display();
	while (sp < 22){	//player
		printf("Player do:   1.stand   2.hit   3.quit\nPlease Please enter a number:   ");
		scanf("%d", &cz); 
		if (cz == 2) {	//hit
			np++;
			p[np-1] = rand() % 13 + 1;
			if (p[np-1] == 1) npa++;
			sp += min(10,p[np-1]);
		};
		if (cz == 3) return 0;//quit
		display();
		if (cz == 1) break;//stand		
	}
	if (sp < 22) while (sb < 22){ //Banker
		printf("Banker do:   1.stand   2.hit   3.quit\nPlease Please enter a number:   ");
		scanf("%d", &cz);//switch!!
		if (cz == 1) break;//stand
		if (cz == 2) {	//hit
			nb++;
			b[nb-1] = rand() % 13 + 1;
			if (b[nb-1] == 1) nba++;
			sb += min(10,b[nb-1]);
		};
		if (cz == 3) return 0;//quit
		display();	
	}; 
	if (((sp > sb) && (sp < 22)) or (sb > 21)) printf("Player win") ;
	else if	(sp == sb) printf("Push"); 
	else printf("Banker win");
	return 0;
}
