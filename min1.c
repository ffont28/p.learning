#include <stdio.h>
#include <ctype.h>
#include <string.h>

int len = 0;

char *maiuscolo (char *s) {
	char a[len];
	char *data = a;
	len=0;

	while (*s != '\0') {
		a[len] = toupper(s[0]);
		len++;
		s++;
	}	
	return data;
}

int main (void) {
	char s[] = "ciao come va";
	len = sizeof(s);
	char *f = maiuscolo(s);

	printf("testo inserito: %s\n", f);	

	return 0;
}
