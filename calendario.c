#include <stdio.h>

int main()
{
    printf("Inserisci il numero del mese ");
    int mese;
    scanf("%d", &mese);
    printf("Inserisci il giorno di inizio mese ");
    int ginizio;
    scanf("%d", &ginizio);
    printf("L\tM\tM\tG\tV\tS\tD\n");
    int ultimodelmese=31;
    (mese==2)? ultimodelmese=28:0;
//   printf("c1 %d\n", ultimodelmese);
    if (mese==4||mese==6||mese==9||mese==11){ 
    ultimodelmese=30;
    }
//    printf("c2 %d\n", ultimodelmese);
    int i;
    for (i=1;i<ginizio;i++){
        printf("\t");
    }
    for (i=1;i<=ultimodelmese;i++){
        printf("%d\t",i);
        ((ginizio+i-1)%7==0)? printf("\n"):6;
    }
}
