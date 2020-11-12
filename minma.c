#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n = 512;

char *maiuscolo (char *s) {
	char a[n];
	char *data = a;
	n=0;

	while (*s != '\0') {
		a[n] = toupper(s[0]);
		n++;
		s++;
	}	
	return data;
}

int main (void) {
	char s[n];

	printf("inserire un testo\n");
	scanf("%[^\n]%*c", s);
	
	char *f = maiuscolo(s);

	printf("testo inserito: %s\n", f);	

	return 0;
}
