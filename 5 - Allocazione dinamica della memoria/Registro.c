#include <stdio.h>
#include <stdlib.h>

char **newBook(int n){
	char **m;
	int r;
	
	m = malloc(n*sizeof(char*));
	
	for (r=0;r<n;r++){
		*(m+r)=NULL;
	}
	return m;
}

int book(int chiave, char *nome, char **list){
	if (*(list+chiave)!=NULL){
		printf("errore nel memorizzare in posizione %d\n",chiave);				
		return 0;
	}
	*(list+chiave)=nome;
	return 1;
}

int cancel(int chiave, char **list){
	*(list+chiave)=NULL;
	/*NOTA che qui non eseguo il controllo se ciò che cancello è interno alla memoria allocata
	precedentemente, ma poco importa perchè a me interessa preservare intatti i dati 
	all'interno della zona allocata*/
	return 1;
}

int printBook(int n, char **list){
	int	i;
	for (i=0;i<n;i++){
		if (*(list+i)!=NULL)
			printf("%d -> %s\n",i,*(list+i));
	}
	return 1;
}

int main(void){
	char c, *name,**list;	
	int n,k,i,size=3;

	printf("Benvenuto nel programma REGISTRO:\ninserisci uno dei comandi disponibili:\n");
	
	while( ( c = getchar () ) != 'f' ){
		switch(c){
			case 'b': // b n --> newBook(n)		
				scanf(" %d",&n);
				list=newBook(n);
				break;
			case '+': // + k name --> book(k, name)
				i=0;				
				scanf(" %d ",&k);
				name = malloc(size*sizeof(char));				
				while (1){	
					scanf("%c",&c);
					if (c=='\n')
						break;			
					if (i>=size){
						size+=3;
						name=realloc(name,size*sizeof(char));
					}	
					name[i++]=c;
				}
				if (i>=size){
					size++;
					name=realloc(name,size*sizeof(char));
				}			
				name[i]='\0';
				book(k,name,list);
				break;
			case '-': // - k --> cancel(k)
				scanf("%d",&k);
				cancel(k,list);				
				break;
			case 'm': // m from to ---> move from to
				// ..
				break;
			case 'p': // p ---> printBook()
				printBook(n,list);				
				break;
		}
	}
}
