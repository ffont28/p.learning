/*
ULTIMO AGGIORNAMENTO 22/10/2020 19:56. PROGRAMMA FUNZIONANTE COMPLETO DI COMMENTI DI DEBUG PER COMPRENDERNE L'ESECUZIONE

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LUN 10							// randdirez:::	0=SU 1=GIU 2=DX 3=SX

int array[LUN][LUN],ri,rinew,co,conew,randdirez,direz,contlet;

int main(void){
	
	srand(time(NULL));

	for (ri=0;ri<LUN;ri++){				//	INIZIALIZZO
		for (co=0;co<LUN;co++){			//	ARRAY
			array[ri][co]='.';			//	CON
		}								//	TUTTI
	} 									//	PUNTINI
	
	ri=0;
	co=0;	
	array[ri][co]='A';
	for (contlet='B';contlet<='Z';contlet++){	// INIZIO A FARE LA PASSEGIATA!
		if (array[ri][co+1] /*DX*/ =='.'||array[ri][co-1] /*SX*/ =='.' || array[ri-1][co] /*SU*/ =='.' || array[ri+1][co] /*GIU*/=='.'){
			// CONDIZIONE DI CELLA LIBERA DA POTER RIEMPIRE
label:		randdirez=rand();
			printf("sono in POSIZIONE: [%d:%d] => ho VALORE %c\n",ri,co,contlet);			
			printf("RANDDIREZ== %d ovvero ", randdirez%4);	//////////////////////////////
			switch (randdirez%4){
				case 0: rinew=ri-1; printf("-riga\n"); break;//SU
				case 1: rinew=ri+1; printf("+riga\n"); break;//GIU
				case 2: conew=co+1; printf("+colonna\n"); break;//DX
				case 3: conew=co-1; printf("-colonna\n"); break;//SX
			}
			if ((array[rinew][conew]=='.')&& (rinew>=0) && (conew>=0)){
				ri=rinew;
				co=conew;
				array[ri][co]=contlet;
			} else {
				printf("Fallito in %d,%d quindi NON SCRIVO e tengo conto di [%d:%d]\n\n",rinew,conew,ri,co);
				rinew=ri;
				conew=co;				
				goto label;
			}
			printf("POSIZIONE OK CON MOSSA: %d , ho messo %c in posizione [%d:%d]\n",randdirez%4,contlet,ri,co);			
		}
	}											// FINE PASSEGGIATA


	printf("\n ORA (RI)STAMPO\n\n");

	for (ri=0;ri<LUN;ri++){
		for (co=0;co<LUN;co++){
			printf("%c  ", array[ri][co]);	
		}
		printf("\n");
	} 
	printf("\n\t\tFINE\n");	
	return 0;
}
