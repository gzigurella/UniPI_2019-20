#include <stdio.h>
#include <stdlib.h>

/*struct definition*/
typedef struct date{
    int giorno;
    int mese;
    int anno;
}data;

/*function prototypes*/
data data_valida(int g, int m, int a);
data data_confronto(data prima, data seconda);

/*main function*/
int main(void){
    int static x, y, z;
    int static j, k, l;
    data date1 = data_valida(x, y, z);    
    data date2;
    
    do{
        date2 = data_valida(j, k, l);
        date1 = data_confronto(date1, date2);
    }while(date2.giorno != 00 && date2.mese != 00 && date2.anno != 0000);

    printf("Data meno recente: %02d/%02d/%04d", date1.giorno, date1.mese, date1.anno);
    fflush(stdin);
    return 0;
}

data data_valida(int g, int m, int a){
    while(scanf("%2d/%2d/%4d", &g, &m, &a) != 3 || g < 0 || g > 31 || m < 0 || m > 12 || a > 9999){
        puts("Data inserita errata, inserire una data nel formato gg/mm/aaaa.");
        scanf("%*[^\n]");
        scanf("%*c");
    }
    data first = {g, m, a};
    return first;
}

data data_confronto(data prima, data seconda){
    if(seconda.giorno == 0 && seconda.mese == 0 && seconda.anno == 0){
        return prima;
    }
    if(prima.anno > seconda.anno){
        return seconda;
    }else if(prima.anno < seconda.anno){
        return prima;
    }
    else if(prima.anno == seconda.anno){
        if(prima.mese > seconda.mese){
            return seconda;
        }else if(prima.mese < seconda.mese){
            return prima;
        }
        else if(prima.mese == seconda.mese){
            if(prima.giorno > seconda.giorno){
                return seconda;
            }
        }
    }
    return prima;
}