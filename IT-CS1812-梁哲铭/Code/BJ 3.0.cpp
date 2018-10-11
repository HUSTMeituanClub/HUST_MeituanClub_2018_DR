#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<windows.h>

using namespace std;

int p[5],b[5];
int np,nb,sp,sb,npa,nba,bankerdo;
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
	if (bankerdo) i = 0 ; 
	else {
		printf("* ");
		i = 1;
	}
	for ( ; i < nb; i++) {
		if (b[i] == 11) printf("J ");
		if (b[i] == 12) printf("Q ");
		if (b[i] == 13) printf("K ");
		if (b[i] < 11) printf("%d ",b[i]);
	}
	if ((nba > 0) && (sb + 10 < 22)) sb+=10;
	printf("    score: %d\n",sb);	
}

int main(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout << "Welcome to Blackjack!" << endl << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	shuffle();
	display();
	while (sp < 22){	//player
		cout << "Player do:   1.stand   2.hit   3.quit" << endl << endl;		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout << "Please enter a number:   ";
		cin >> cz;
		cout << endl << endl << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		if (cz == 2) {	//hit
			np++;
			p[np-1] = rand() % 13 + 1;
			if (p[np-1] == 1) npa++;
			sp += min(10,p[np-1]);
		};
		if (cz == 3) return 0;//quit
		if (cz == 1) bankerdo = 1;
		display();
		if (cz == 1) break;//stand		
	}
	bankerdo = 1;
	if (sp < 22) while (sb < 22){ //Banker	
		cout << "Banker do:   1.stand   2.hit   3.quit" << endl << endl;		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout << "Please enter a number:   ";
		cin >> cz;
		cout << endl << endl << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	cout << endl;
	if (((sp > sb) && (sp < 22)) or (sb > 21)) printf("Player win") ;
	else if	(sp == sb) printf("Push"); 
	else printf("Banker win");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	return 0;
}
