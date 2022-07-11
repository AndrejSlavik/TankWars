#define _CRT_SECURE_NO_WARNINGS
#define ARENA 42
#define G 9.81
#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
double fire(int x, int y){
	double angle,hit;
	x = (double)x / 3.6;
	angle = (y * M_PI) / 180;
	hit = round((double)((pow(x,2) / G)* (sin(2*angle))/(double)100));
	return hit;
}
int randNumber(int a, int b){
return rand() % (b - a + 1) + a;
}
int game(){
	int i, t1, t2, x, y, hit = 0, c = 0, k = 0, p = 0, hpp = 2, hpc = 2, AIx = 0, AIy = 0, q = 0, TESTx=0, TESTy = 0;
	char m;
	t1 = randNumber(1, 21);
	t2 = randNumber(22, 42);
	AIy = (ARENA - (ARENA - t2) - 1);
	while (p != 1){
		/*printf("\nc=%d\n", c);
		printf("hit=%d\n", hit);
		printf("t1=%d\n", t1);
		printf("t2=%d\n", t2);
		printf("k=%d\n", k);
		printf("AIx=%d\n", AIx);
		printf("AIy=%d\n", AIy);0
		printf("q=%d\n", q);
		printf("TESTx=%d\n", TESTx);
		printf("TESTy=%d\n", TESTy);
		printf("t2-c=%d\n", t2-c);*/
		if (k > 0) {
			if (k % 2 == 0) {
				printf("\nIt's computer's turn! WAITING FOR MOVE...");
				Sleep(3000);
				if (q == 0) {
					c = randNumber(AIx, AIy);
					q++;
				}
				if (q > 0){
					if ((t2 - c) > t1) {
						AIx = c;
						TESTx++;
					}
					if ((t2 - c) < t1) {
						AIy = t2 - c;
						TESTy++;
					}
					c = randNumber(AIx, AIy);
				}
				printf(" COMPUTER=%d\n", c);
				Sleep(1000);
			}
			else {
				printf("\nHP PLAYER: %d", hpp);
				printf("%70s", "HP COMPUTER: ");
				printf("%d", hpc);
				printf("\nWhere would you like to move? ('s'=stay, 'l'=left, 'r'=right)\n");
				scanf("%c", &m);
				scanf("%c", &m);
				if (m == 's')
					t1 = t1;
				if (m == 'l'){
					t1--;
					if (t1 == 0){
						printf("You can't go much further left!\n");
						t1++;
					}
				}
				if (m == 'r'){
						t1++;
					if (t1 == 22){
						printf("You can't go much further right!\n");
						t1--;
					}
				}
				printf("Initial strength/speed (m/s):\n");
				scanf("%d", &x);
				printf("Angle (degrees):\n");
				scanf("%d", &y);
				hit = fire(x, y);
				printf("HIT:%d\n",hit);
			}
		}
		for (i = 1; i < 20; i++)
			printf("\n");
		for (i = 1; i <= ARENA; i++) {
			if (i == t1) {
				printf(" A");
				i++;
			}
			if (i == t2) {
				printf(" B");
				i++;
			}
			if (k % 2 == 1) {
				if (i == (hit + t1)) {
					printf(" *");
					i++;
				}
			}
			else {
				if (i == (t2 - c)) {
					printf(" *");
					i++;
				}
			}
			if (t1 == (t2 - c)) {
				printf("\n\nTank B(COMPUTER) is victorious!");
				p++;
				break;
			}
			if ((hit + t1) == t2) {
				printf("\n\nTank A(PLAYER) is victorious!");
				p++;
				break;
			}
			if ((t1+hit) > ARENA) {
				printf("\nOut of range!");
				break;
			}
			if (((t1+hit) == (t2 - 1)) || ((t1 + hit) == (t2 + 1))) {
				printf("Close hit!\n");
				hpc--;
				printf("Tank B(COMPUTER) HP: %d\n", hpc);
				hit = 0;
				break;
			}
			if (((t2 - c) == (t1 - 1)) || ((t2 - c) == (t1 + 1))) {
				printf("Close hit!\n");
				hpp--;
				printf("Tank A(PLAYER) HP: %d\n",hpp);
				c = 0;
				break;
			}
			if (hpc == 0) {
				printf("\n\nTank A is victorious!");
				p++;
				break;
			}
			if (hpp == 0) {
				printf("\n\nTank B is victorious!");
				p++;
				break;
			}
			printf(" _");
		}
		if ((k%2==1) && (k>0)){
			Sleep(5000);
			system("cls");
		}
		k++;
	}
	return 0;
}
int main() {
srand(time(0));
game();
return 0;
}