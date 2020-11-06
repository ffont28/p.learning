/*
Questo programma legge in input da linea di comando una parola (dopo il comando /a.out) e restituisce una stinga
che segnala se la parola è inserita è palindroma o meno. Per semplicità viene letta e considerata solamente la prima parola
dopo la chiamata ad esecuzione del codice.
[in LUBUNTU 'attraversa.c']
Ultima rev. 6/11/2020 ffont28
*/
#include <stdio.h> 
#include <string.h> 
#define LENGTH 100

int main (int argc, char **argv) {	
	printf("argc %d\n", argc);
	int i,lung;
	
	printf("%s\n",argv[1]);		
	lung=strlen(argv[1]);
	printf("lunghezza è %d\n",lung);	
	for (i=0;i<lung;i++){	// i i+1 i+2                  lun-(i+1)   lun-i
		printf(">>>>>>>>>>> tra %c e %c\n", argv[1][i],argv[1][lung-i-1]);		
		if (argv[1][i]!=argv[1][lung-i-1]){
			printf("NON ");			
			break;
		}
		if (i>(lung/2))
			break;
		
	}
	printf("E' PALINDROMA!\n");
  return 0;
}
