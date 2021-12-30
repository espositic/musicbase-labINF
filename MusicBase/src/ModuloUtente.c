#include "ModuloInput.h"
#include <string.h>
#include "Dichiarazioni.h"
#include <stdio.h>
#include <stdlib.h>


Utente login(DatabaseUtente DBUtente){
	Utente utenteLoggato;
	int loginRiuscito=0;
	while(loginRiuscito==0){
		printf("Inserisci nome utente");
		char* nomeUtente=calloc(30,sizeof(char));
		nomeUtente=leggiStringa();
		int* idUtente;
		idUtente=ricercaUtenteTramiteNomeUtente(nomeUtente, DBUtente);
		printf("Inserisci password");
		char* password=calloc(30,sizeof(char));
		password=leggiStringa();
		int i=0;
		while(idUtente[i]!=IDSENTINELLA){
			if(strcmp(DBUtente[idUtente[i]].password,password)==0){
				loginRiuscito=1;
			}
			i=i+1;
		}
		if(loginRiuscito==0){
			printf("Credenziali errate, inseriscile di nuovo");
		}
		else{
			utenteLoggato=DBUtente[idUtente[i]];
		}
	}
	return utenteLoggato;
}
