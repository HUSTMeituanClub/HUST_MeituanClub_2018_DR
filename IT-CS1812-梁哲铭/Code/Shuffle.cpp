#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>

int heap[53], hh[53];
int i,ran;

void shuffle() {
	srand(time(0));
	for (i= 52; i> 0; i--) hh[i]= 1;
	for (i= 52; i> 0; ) { 
		ran = rand()%52 +1;
		if (hh[ran]) {
			hh[ran] = 0;
			heap[i] = ran;
			i--;
		}		
	}
}

int main(){
	shuffle();
	for (i= 1; i<53; i++) printf("%d\n",heap[i]);
	return 0;
}
