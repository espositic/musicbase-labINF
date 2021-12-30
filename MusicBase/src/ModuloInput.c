#include <stdio.h>
#include <stdlib.h>

int leggiIntero();
char leggiCarattere();
char* leggiStringa();

/*	Funzione che legge un intero da tastiera*/
int leggiIntero(){
	int valoreNumerico;
	scanf("%d",&valoreNumerico);
	return valoreNumerico;
}

/*	Funzione che legge un carattere da tastiera*/
char leggiCarattere(){
	char carattere;
	scanf("%c",&carattere);
	return carattere;
}

/*	Funzione che legge una stringa da tastiera*/
char* leggiStringa(){
	char* stringa;
	stringa=calloc(30,sizeof(char));
	gets(stringa);
	return stringa;
}
