/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define LUNGH 50

int main(void) {
    
    int i, pali,lun;
    char a[LUNGH];
    
    for ( i = 0; i < LUNGH; i++) {
        scanf("%c", &a[i]);
        if (a[i] == '.')
            break;
    }
    
    lun = i;
    
//    printf("%c",a[i-3]);
    
    for ( i = 0; i < lun; i++) {
//        for ( pali = lun; pali >= 0; pali--) {
 //           printf("%d %d   %c %c\n",i,lun-i-1,a[i],a[lun-i-1]);
           if (a[i]!=a[lun-i-1]){
            return printf("non è palindromo");
            }
//          pali--;    
//        printf("%d %d\n",i,lun);
        
    }
    
//    printf("%d",lun);
    
    printf("E' palindromo");

    return 0;
}
