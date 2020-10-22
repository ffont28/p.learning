#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LUN 10							// randdirez:::	1=DX 2=SX 3=SU 4=GIU

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
			switch (randdirez%4){
				case 0: rinew=ri--; printf("-riga\n");//SU
				case 1: rinew=ri++; printf("+riga\n");//GIU
				case 2: conew=co++; printf("+colonna\n");//DX
				case 3: conew=co--; printf("-colonna\n");//SX
			}
			if (array[rinew][conew]=='.')/*&& rinew>0 && conew>0)*/{
				ri=rinew;
				co=conew;
				array[ri][co]=contlet;
			} else {
				printf("Fallito in %d,%d\n",rinew,conew);				
				goto label;
			}
			printf("randirez: %d , posizione [%d:%d]\n",randdirez%4,ri,co);			
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
