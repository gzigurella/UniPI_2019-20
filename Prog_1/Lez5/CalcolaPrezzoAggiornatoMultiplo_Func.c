#include <stdio.h>
#include <stdlib.h>

void operazioni(int x);
float leggi_prezzo();
float leggi_percentuale();
float calcola_prezzo_ivato(float a, float b);
float calcola_prezzo_scontato(float a, float b);

/*main function*/
int main(void){
	int op;
	
	do{
		while(scanf("%d", &op) != 1 || op > 1){
			puts("scelta non valida");
			scanf("%*[^\n]");
			scanf("%*c");
		}
		operazioni(op);
	}while(op >= 0);
	if(op < 0){
		fflush(stdin);
		return 0;
	}
}

void operazioni(int x){
	if(x < 0){
		return;
	}
	float init, perc;
	init = leggi_prezzo();
	perc = leggi_percentuale();

	if(x == 1){
		/* Prezzo con Iva */

		float ivato = calcola_prezzo_ivato(perc, init);
	    printf("%20s%20s%20s\n", "Prezzo_Init", "Percentuale", "Prezzo_ivato");
	    printf("%20.2f%20.2f%20.2f\n", init, perc, ivato);
	    return;
	}else if(x == 0){
		/* Prezzo con Sconto */

		float ivato = calcola_prezzo_scontato(perc, init);
	    printf("%20s%20s%20s\n", "Prezzo_Init", "Percentuale", "Prezzo_scontato");
	    printf("%20.2f%20.2f%20.2f\n", init, perc, ivato); 
	    return;
	}
}

float leggi_prezzo(){
	float b;
	while(scanf("%f", &b) != 1 || b < 0){
		puts("Prezzo non valido");
		scanf("%*[^\n]");
		scanf("%*c");		
	}
	return b;
}

float leggi_percentuale(){
	float a;
	while(scanf("%f", &a) != 1 || a < 0 || a > 100){
		puts("Percentuale non valida");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return a;
}

float calcola_prezzo_ivato(float a, float b){
	return b + b * (a/100);
}

float calcola_prezzo_scontato(float a, float b){
	return b - b * (a/100);
}