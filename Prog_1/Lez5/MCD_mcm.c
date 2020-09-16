#include <stdio.h>
#include <stdlib.h>

int read_positive_int(void);
int mcm(int a, int b);
int MCD(int a, int b);

/*main function*/
int main(void){
	int N, M;
	N = read_positive_int();
	M = read_positive_int();

	if(N != 0){
		printf("%d\n", MCD(N, M));
		printf("%d\n", mcm(N, M));
	}

	fflush(stdin);
	return 0;
}

int read_positive_int(void){
	int a;
	while(scanf("%d", &a) != 1 || a < 0){
		puts("Inserisci un intero positivo.");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return a;
}

int MCD(int a, int b){
	while(a != b){
		if(a > b){
			a = a - b;
		}
		else{
			b = b - a;
		}
	}
	return a;
}

int mcm(int a, int b){
	return ((a*b)/MCD(a,b));
}