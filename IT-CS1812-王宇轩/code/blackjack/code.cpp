#include <cstring>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <windows.h>

using namespace std;
typedef long long LL;

const LL Lim = 1000000000;

struct Card {
	int col, num;
	Card(int a, int b) {col = a, num = b;}
	Card() {}
} card[2];

/*
	p_sum[] : player's point
	flag[][] : if a card have occured
	give_up[] : if a player give up get card
	A_flag[] : player's A card number
	if_hint : if player need hint everyturn
	s : input infomation
*/
int p_sum[3], flag[15][4], give_up[3], A_flag[3], if_hint;
char s[1000];

//delay time
void delay_time(LL time) {
	for (LL i = 1; i <= time; i ++);
}

//distinguish the string is yes or no
int judge_yes_no(char *s) {
	int len = strlen(s + 1);
	if (len == 3 && s[1] == 'Y' && s[2] == 'e' && s[3] == 's') return 1;
	if (len == 2 && s[1] == 'N' && s[2] == 'o') return 2;
	return 0;
}

//output player input wrong information
void wrong_input() {
	printf("I can't know what your main...\n");
	printf("\n");
}

//distinguish input is yes or no
int get_yes_no() {
	// yes -> 1, no -> 2;
	printf("Please input Yes or No\n");
	int t = 0; 
	while (t == 0) {
		printf("\n");
		scanf("%s", s + 1);
		printf("\n");
		t = judge_yes_no(s);
		if (t == 0) {
			wrong_input();		
			printf("Please input Yes or No\n");
		}
	}
	return t;
}

//distinguish input number
int judge_num(char *s) {
	int len = strlen(s + 1);
	if (len != 1) return 0;
	if (s[1] == '1') return 1;
	if (s[1] == '2') return 2;
	if (s[1] == '3') return 3;
	return 0;
}

//distinguish input operation
int judge_operation(char *s) {
	int len = strlen(s + 1);
	if (len == 4 && s[1] == 'h' && s[2] == 'i' && s[3] == 'n' && s[4] == 't') return 5;
	if (len != 1) return 0;
	if (s[1] == 'y') return 1;
	if (s[1] == 'n') return 2;
	if (s[1] == 'q') return 3;
	if (s[1] == 'l') return 4;
	return 0;
}

//change a number to card's infomation
Card get_card_info(int x) {
	return (Card(x % 4, x / 4 + 1));
}

//random a card
Card deal(int id) {
	int x = rand() % 52;
	Card now = get_card_info(x);
	while (flag[now.num][now.col]) {
		x = rand() % 52;
		now = get_card_info(x);
	}
	flag[now.num][now.col] = 1;
	return now;
}

//output hint
void output_hint(int mode) {
	if (mode == 2) printf("\n");
	printf("Hint!!\n");
	printf("y : you want to get this card\n");
	printf("n : you don't want to get this card\n");
	printf("q : you want to quit\n");
	printf("l : you want to look the scoreboard\n");
	if (mode == 1) printf("\n");
}

//output scoreboard
void output_scoreboard() {
	printf("Player 1 have %d points\n", p_sum[1]);
	printf("Player 2 have %d points\n", p_sum[2]);
	printf("\n");
}

void game_over(int id, int mode) {
	//change color to red
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	if (mode == 1) {
		if (id == 1) printf("Congradulate! You win this game\n"); else
			printf("So sad, AI win this game\n");
	} else printf("Congradulate! Player %d win this game\n", id);
	printf("\n");
	//change color to white
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
}

//judge winner
void judge_winner(int mode) {
	printf("Game over!!\n");
	output_scoreboard();
	if (p_sum[1] == p_sum[2]) printf("Draw!!!!\n"); else
		game_over((p_sum[1] < p_sum[2]) ? 2 : 1, mode);
}

//distinguish player's operation
int get_operation(int id) {
	printf("Now is Player %d turn!\n", id);
	delay_time(Lim / 2);
	printf("\n");
	printf("Please choice y or n or q or l or hint.\n");
	if (if_hint == 1) output_hint(2);
	int t = 0;
	/*
		t = 0 wrong input
		t = 1 get this card
		t = 2 give up this card
		t = 3 quit game
		t = 4 watch operation hint
		t = 5 watch scoreboard
	*/
	while (t == 0) {
		printf("\n");
		scanf("%s", s + 1);
		printf("\n");
		t = judge_operation(s);
		if (t == 0) wrong_input();
		if (t == 4) output_scoreboard();
		if (t == 5) output_hint(1);
		if (t > 3) t = 0;
		if (t == 0) printf("Please choice y or n or q or l or hint.\n");
	}  
}

//output card
void output_card(Card now) {
	//change color to blue;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	int c = now.col, n = now.num;
	//card's kind
	if (c == 0) printf("Hearts");
	if (c == 1) printf("Blocks");
	if (c == 2) printf("Spade");
	if (c == 3) printf("Blossom");
	//card's number
	if (n == 1) printf("A");
	if (n == 11) printf("J");
	if (n == 12) printf("Q");
	if (n == 13) printf("K");
	if (n > 1 && n < 11) printf("%d", n);
	printf("\n");
	printf("\n");
	//change color to white
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
}

//clear the data last turn
void clear_info() {
	A_flag[1] = A_flag[2] = 0;
	p_sum[1] = p_sum[2] = 0;
	give_up[1] = give_up[2] = 0;
	memset(flag, 0, sizeof flag);
}

//game on and preparation
int Game_on(int mode) {
	printf("Game on!\n");
	printf("\n");
	if (mode == 2) printf("You are Player 1\n");
	printf("\n");
	delay_time(Lim / 2);
	//give player some operation hint
	output_hint(1);
	delay_time(Lim);
	//judge if player need hint every turn
	printf("If you need operation help every turn?\n");
	if_hint = get_yes_no();
	//random play order
	printf("OK, let's random who play first!\n");
	delay_time(Lim / 2);
	printf("\n");
	int id = rand() % 2 + 1;
	printf("Player %d\n", id);
	return id;
}

//clear screen to begin a new turn or new game
void clear_screen(int mode) {
	if (mode == 1) printf("\n");
	printf("input any char to go to next turn!\n");
	scanf("%s", s);
	system("cls");
}

//one player give uo this game
void player_quit(int id, int mode) {
	printf("Player %d is quit\n", id);
	game_over(3 - id, mode);
}

//one player's point is 21
void blackjack(int id, int mode) {
	printf("\n");
	if (id == 2 && mode == 2) printf("Blackjack! AI get 21 points!\n"); else
		printf("Blackjack! you get 21 points!\n");
	printf("\n");
	delay_time(Lim / 2);
	game_over(id, mode);
}

//one player's point is over 21
void bust(int id, int mode) {
	printf("\n");
	if (id == 2 && mode == 2) printf("Bust! AI have over 21 points!\n"); else
		printf("Bust! your have over 21 points!\n");
	printf("\n");
	delay_time(Lim / 2);
	game_over(3 - id, mode);
}

//judge if AI should get card this turn by simulating many time;
int E_calc(int id) {
	printf("Now is AI turn!\n", id);
	printf("\n");
	delay_time(Lim / 2);
	int rid = 3 - id;
	if (p_sum[id] < p_sum[rid]) return 1;
	if (p_sum[id] + 10 <= 21) return 1;
	int cnt = 0, num = 100;
	for (int i = 1; i <= num; i ++) {
		int ran = min(10, rand() % 13 + 1);
		if (p_sum[id] + ran - 10 * A_flag[id] <= 21) cnt ++; else cnt --;
	}
	//adjust parameter
	if (cnt >= num / 4) return 1; 
	return 2;
}	

//A player's turn and operation
int P_turn(int id) {
	clear_screen(1);
	if (give_up[id]) {
		printf("Player %d jump this turn.\n", id);
		printf("\n");
		printf("Your points is %d\n", p_sum[id]);
		return 1;
	}
	Card now = deal(id);
	int t = get_operation(id);
	printf("Your card is ");
	output_card(now);
	if (t == 1) {
		if (now.num == 1) A_flag[id] ++; //get a A, now A = 11;
		p_sum[id] += min(10, now.num);
		if (p_sum[id] > 21 && A_flag[id] > 0) p_sum[id] -= 10, A_flag[id] --; //change a A to 1;
		printf("Your points is %d\n", p_sum[id]);
	}
	if (t == 2) {
		give_up[id] = 1;
		printf("Your final points is %d\n", p_sum[id]);
		//all player give up this game
		if (give_up[1] && give_up[2]) {
			judge_winer(1);
			return 0;
		}
	}
	if (t == 3) player_quit(id, 1); //player give up this game
	if (p_sum[id] == 21) blackjack(id, 1); //player's point is 21
	if (p_sum[id] > 21) bust(id, 1); //player's point over 21
	if (t == 3 || p_sum[id] >= 21) return  0; //game over
	return 1;
}

//AI's turn and operation
int E_turn(int id) {
	clear_screen(1);
	if (give_up[id]) {
		printf("AI jump this turn.\n");
		printf("\n");
		printf("AI's points is %d\n", p_sum[id]);
		return 1;
	}
	Card now = deal(id);
	int t = E_calc(id);
	if (t == 1) printf("AI want to get this card.\n");
	if (t == 2) printf("AI don't get this card.\n");
	delay_time(Lim / 2);
	printf("\n");
	printf("AI's card is ");
	output_card(now);
	//get this card
	if (t == 1) {
		if (now.num == 1) A_flag[id] ++; // get a A, now A = 11
		p_sum[id] += min(10, now.num);
		if (p_sum[id] > 21 && A_flag[id] > 0) p_sum[id] -= 10, A_flag[id] --; // change a A to 1
		printf("AI's points is %d\n", p_sum[id]);
	}
	//give up this card
	if (t == 2) {
		give_up[id] = 1;
		printf("AI's final points is %d\n", p_sum[id]);
		//all player give up this game
		if (give_up[1] && give_up[2]) {
			judge_winer(2);
			return 0;
		}
	}
	if (t == 3) player_quit(id, 2); //AI give up this game
	if (p_sum[id] == 21) blackjack(id, 2); //AI's point is 21
	if (p_sum[id] > 21) bust(id, 2); //AI's point is over 21
	if (t == 3 || p_sum[id] >= 21) return  0; //game over
	return 1;
}

//game mode 1 
void game_PvP() {
	clear_screen(2);
	clear_info();
	int id = Game_on(1);
	for (; ; id = 3 - id) 
		if (!P_turn(id)) return;
}

//game mode 2
void game_PvE() {
	clear_screen(2);
	clear_info();
	int id = Game_on(2);
	for (; ; id = 3 - id) {
		if (id == 1) {
			if (!P_turn(id)) return;
		} else {
			if (!E_turn(id)) return;
		} 
	}
}

int main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
	printf("Welcome to blackjack\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
	printf("\n");
	srand(time(0));
	for (; ;) {
		// select if begin game
		printf("Do you want to start a new game?\n");
		int t = get_yes_no();
		if (t == 2) {
			printf("Bye bye!");
			break;
		}
		
		//select mode
		printf("Please select mode of this game.\n");
		printf("1. PvP\n");
		printf("2. PvE\n");
		printf("3. quit this game\n");
		printf("input 1 - 3.\n");
		t = 0;
		while (t == 0) {
			printf("\n");
			scanf("%s", s + 1);
			printf("\n");
			t = judge_num(s); 
			if (t == 0) {
				wrong_input();
				printf("Please input 1 - 3\n");
			}
		}
		if (t == 3) continue;
		if (t == 1) game_PvP(); 
		if (t == 2) game_PvE();	
	}
}
