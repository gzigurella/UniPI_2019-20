#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sum_pow(float x, int n);
int read_positive_int(void);
float read_positive_float(void);

/*main function*/
int main(void){
	int pow;
	pow = read_positive_int();
	float base;
	base = read_positive_float();

	sum_pow(base, pow);
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

float read_positive_float(void){
	float b;
	while(scanf("%f", &b) != 1 || b < 0){
		puts("Inserisci un numero reale positivo.");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return b;
}

void sum_pow(float x, int n){
	int i = 0;
	float sum = 0;
	while(i <= n){
		sum += pow(x, i);
		i++;
	}
	printf("%.2f\n", sum);
	return;
}