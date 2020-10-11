#include <stdio.h>
#define N 100

int main( void) {
    
    char str[N],ch;
    int i=0;
    
    while ((ch=getchar())!='\n'){
        str[i]=ch;
        i++;
    }
    int cursore;
    char dacancellare=str[i-1];
    for (cursore=0;cursore<=i;cursore++){
        
        if (str[cursore]==dacancellare){
            if (((cursore==0) && (str[cursore+1]==' ')) || ((cursore==i+1) && (str[cursore-2]==' '))){
                printf("/");
            } else {
                if (str[cursore-1]==' ' && str[cursore+1]==' '){
                    printf("/");
                }
            }
            
        } else {
            printf("%c",str[cursore]);
        }
//        if (str[cursore]== ' '){
//        }
    }
    
/*    int k;
    for (k=0;k<=i;k++){
        printf("%c",str[k]);
*/
 
    printf("\t\t\t%d %d", cursore, i);
    return 0;
}