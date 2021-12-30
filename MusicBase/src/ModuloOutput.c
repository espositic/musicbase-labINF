#include <stdio.h>
#include <stdlib.h>
#include "ModuloInput.h"
#include "Dichiarazioni.h"
//#include "GestioneDatabase.h"

void stampaBrano(Brano branoStampa);
void stampaArtista(Artista artistaStampa);
void stampaAlbum(Album albumStampa);
void stampaGenere(Genere genereStampa);
void stampaUtente(Utente utenteStampa);
void stampaPlaylist(Playlist playlistStampa, DatabaseUtente DBUtente);
void stampaBraniPlaylist(Playlist playlistStampa, DatabasePlaylistBrano DBPlaylistBrano, DatabaseBrano DBBrano);
void menuAdmin();
void MenuUtenteStandard();
void ricercaGenerale();
void stampaListaBrani(int*risultato, DatabaseBrano DBBrano);
void stampaListaPlaylist(int*risultato, DatabasePlaylist DBPlaylist);
void stampaListaUtenti(int*risultato, DatabaseUtente DBUtente);
void stampaListaArtista(int*risultato, DatabaseArtista DBArtista);
void stampaListaAlbum(int*risultato, DatabaseAlbum DBAlbum);


/*	Funzione che dato in input un brano, ne stampa a video
 * 	tutti i suoi campi.*/
void stampaBrano(Brano branoStampa){
	printf("/nTitolo :%s",branoStampa.titolo );
	int DurataInMinuti=(branoStampa.durata-(branoStampa.durata%60))/60;
	int Secondi=branoStampa.durata%60;
	printf("Durata %d:%d\n", DurataInMinuti, Secondi);
	printf("/nAnno :%d",branoStampa.anno);
}

/*	Funzione che dato in input un artista, ne stampa a video
 * 	tutti i suoi campi.*/
void stampaArtista(Artista artistaStampa){
	printf("/nNome :%s",artistaStampa.nome);
	printf("/nCognome :%s",artistaStampa.cognome);
	printf("/nNomeArte :%s",artistaStampa.nomeArte);
	printf("/nLinkBio :%s",artistaStampa.linkBio);
}

/*	Funzione che dato in input un album, ne stampa a video
 * 	tutti i suoi campi.*/
void stampaAlbum(Album albumStampa){
	printf("/nTitolo :%s",albumStampa.titolo);
	printf("/nAnno :%d",albumStampa.anno);
}

/*	Funzione che dato in input un genere, ne stampa a video
 * 	tutti i suoi campi.*/
void stampaGenere(Genere genereStampa){
	printf("/nGenere :%s",genereStampa.nome);
}

/*	Funzione che dato in input un utente, ne stampa a video
 * 	tutti i suoi campi.*/
void stampaUtente(Utente utenteStampa){
	printf("/nNome Utente :%s",utenteStampa.nomeUtente);
}

/*	Funzione che dato in input una playlist, ne stampa a
 * 	video tutti i suoi campi.*/
void stampaPlaylist(Playlist playlistStampa, DatabaseUtente DBUtente){
	printf("/nNome della Playlist :%s",playlistStampa.nome);
	printf("/nDescrizione della Playlist :%s", playlistStampa.descrizione);
	stampaUtente(DBUtente[playlistStampa.idUtente]);
}

/*	Funzione che dati in input una playlist, il database contenente
 * 	le relazioni tra essa e i brani e il database dei brani, stampa
 * 	le informazioni relative ai brani contenuti in essa.*/
void stampaBraniPlaylist(Playlist playlistStampa, DatabasePlaylistBrano DBPlaylistBrano, DatabaseBrano DBBrano){
	printf("/nNome della Playlist :%s",playlistStampa.nome);
	int i=0;
	while(DBPlaylistBrano[i].idPlaylist!=IDSENTINELLA){
		if(DBPlaylistBrano[i].idPlaylist==playlistStampa.idPlaylist){
			stampaBrano(DBBrano[DBPlaylistBrano[i].idBrani]);
		}
		i=i+1;
	}
}

/*	Funzione che stampa a video le possibili azioni che l'admin può fare.*/
void menuAdmin(){
	printf("Che operazione vuoi effettuare?");
	int scelta=1;
	do{
		if(scelta<0 && scelta>4){
			printf("Scelta non valida, riprova");
		}
		printf("0- Non effettuare nessuna scelta");
		printf("1- Aggiungere un nuovo elemento");
		printf("2- Eliminare un elemento esistente");
		printf("3- Modificare un elemento esistente");
		printf("4-Riprodurre un brano");
		printf("5- Effettua il backup del database completo");
		scelta=leggiIntero();
	}
	while(scelta<0 && scelta >4);
	int scelta2=1;
	if(scelta>0){
		if(scelta>1){
			printf("0- Non effettuare nessuna scelta");
			printf("1-Aggiungere un nuovo brano");
			printf("2-Aggiungere un nuovo album");
			printf("3-Aggiungere un nuovo genere");
			printf("4-Aggiungere un nuovo artista");
			printf("5-Aggiungere una nuova playlist");
		}
		do{
			if(scelta2>-1 && scelta2<5){
				printf("Scelta non valida, riprova");
			}
			scelta2=leggiIntero();
		}
		while(scelta2>-1 && scelta2<6);
	}
	if(scelta==2){
		printf("0- Non effettuare nessuna scelta");
		printf("1-Eliminare un brano esistente");
		printf("2-Eliminare un album esistente");
		printf("3-Eliminare un genere esistente");
		printf("4-Eliminare un artista esistente");
		printf("5-Eliminare una playlist esistente");
		do{
			if(scelta2>-1 && scelta2<5){
				printf("Scelta non valida, riprova");
			}
			scelta2=leggiIntero();
		}
		while(scelta2>-1 && scelta2<6);
	}
	 if(scelta==3){
		printf("0- Non effettuare nessuna scelta");
		printf("1-Modificare un brano esistente");
		printf("2-Modificare un album esistente");
		printf("3-Modificare un genere esistente");
		printf("4-Modificare un artista esistente");
		printf("5-Modificare una playlist esistente");
		do{
			if(scelta2<0 && scelta2>5){
				printf("Scelta non valida, riprova");
			}
			scelta2=leggiIntero();
		}
		while(scelta2<0 && scelta2>5);
	scelta=scelta*10;
	scelta=scelta+scelta2;
	}
}

/*	Funzione che stampa a video le possibili azioni che un normale utente può fare.*/
void MenuUtenteStandard(){
	int scelta=0;
	printf("Quale operazione vuoi effettuare?");
	do{
	if(scelta>-1 && scelta<4){
		printf("Scelta non valida, riprova");
	}
	printf("0- Non effettuare nessuna scelta");
	printf("1- Ricerca brano");
	printf("2- Crea playlist");
	printf("3- Riproduci playlist");
	scelta=leggiIntero();
	}
	while(scelta>-1 && scelta<6);
}

/*	Funzione che stampa le possibili ricerche che si possono effettuare nel database*/
void ricercaGenerale(){
	int scelta;
	printf("Che tipo di ricerca vuoi effettuare?");
	printf("0- Non effettuare nessuna ricerca");
	printf("1- Ricerca per nome brano");
	printf("2- Ricerca brano tramite artista");
	printf("3- Ricerca brano tramite genere");
	printf("4- Ricerca brano tramite album");
	scelta=0;
	do{
		if(scelta>-1 && scelta<5){
			printf("Scelta non valida, riprova");
		}
	scelta=leggiIntero();
	}
	while(scelta>-1 && scelta<5);
}

/*	Funzione che dati in input un array di id di brani e il database dei brani
 *	stampa le informazioni dei brani.*/
void stampaListaBrani(int*risultato, DatabaseBrano DBBrano){
	int i=0;
	while(risultato[i]!=IDSENTINELLA){
		int j=0;
		while(DBBrano[j].idBrano!=IDSENTINELLA){
			if(DBBrano[j].idBrano==risultato[i]){
				printf("%d",i);
				printf("Il titolo del brano è: %s", DBBrano[j].titolo);
				printf("L’anno di uscita del brano è: %d",DBBrano[j].anno);
				printf("La durata del brano è di: %d",DBBrano[j].durata);
			}
			j=j+1;
		}
		i=i+1;
	}
	if(i==0){
		printf("Nessun brano è stato trovato");
	}
}

/*	Funzione che dati in input un array di id di playlist e il database delle playlist
 *	stampa le informazioni delle playlist.*/
void stampaListaPlaylist(int*risultato, DatabasePlaylist DBPlaylist){
	int i=0;
	while(risultato[i]!=IDSENTINELLA){
		int j=0;
		while(DBPlaylist[j].idPlaylist!=IDSENTINELLA){
			if(DBPlaylist[j].idPlaylist==risultato[i]){
				printf("%d",i);
				printf("Il nome della playlist è: %s",DBPlaylist[i].nome);
				printf("La descrizione della playlist è; %s", DBPlaylist[i].descrizione);
			}
			j=j+1;
		}
		i=i+1;
	}
	if(i==0){
		printf("Nessuna playlist è stata trovata");
	}
}

/*	Funzione che dati in input un array di id di utenti e il database degli utenti
 *	stampa le informazioni degli utenti.*/
void stampaListaUtenti(int*risultato, DatabaseUtente DBUtente){
	int i=0;
	while(risultato[i]!=IDSENTINELLA){
		int j=0;
		while(DBUtente[j].idUtente!=IDSENTINELLA){
			if(DBUtente[j].idUtente==risultato[i]){
				printf("%d",i);
				printf("Il nome utente dell'utente è: %s",DBUtente[i].nomeUtente);
			}
			j=j+1;
		}
		i=i+1;
	}
	if(i==0){
		printf("Nessun utente è stato trovato");
	}
}

/*	Funzione che dati in input un array di id di generi e il database dei generi
 *	stampa le informazioni dei generi.*/
void stampaListaGeneri(int*risultato, DatabaseGenere DBGenere){
	int i=0;
	while(risultato[i]!=IDSENTINELLA){
		int j=0;
		while(DBGenere[j].idGenere!=IDSENTINELLA){
			if(DBGenere[j].idGenere==risultato[i]){
				printf("%d",i);
				printf("Il nome del genere è: %s",DBGenere[i].nome);
			}
			j=j+1;
		}
		i=i+1;
	}
	if(i==0){
		printf("Nessun genere è stato trovato");
	}
}


/*	Funzione che dati in input un array di id di artisti e il database degli artisti
 *	stampa le informazioni degli artisti.*/
void stampaListaArtista(int*risultato, DatabaseArtista DBArtista){
	int i=0;
	while(risultato[i]!=IDSENTINELLA){
		int j=0;
		while(DBArtista[j].idArtista!=IDSENTINELLA){
			if(DBArtista[j].idArtista==risultato[i]){
				printf("%d",i);
				printf("Il nome dell’artista è: %s",DBArtista[i].nome);
				printf("Il cognome dell’artista è: %s",DBArtista[i].cognome);
				printf("Il nome d’arte dell’artista è: %s",DBArtista[i].nomeArte);
				printf("Il link alla biografia è: %s",DBArtista[i].linkBio);
				j=j+1;
			}
			i=i+1;
		}
	}
	if(i==0){
		printf("Nessun artista è stato trovato");
	}
}

/*	Funzione che dati in input un array di id di album e il database degli album
 *	stampa le informazioni degli album.*/
void stampaListaAlbum(int*risultato, DatabaseAlbum DBAlbum){
	int i=0;
		while(risultato[i]!=IDSENTINELLA){
			int j=0;
			while(DBAlbum[j].idAlbum!=IDSENTINELLA){
				if(DBAlbum[j].idAlbum==risultato[i]){
					printf("%d",i);
					printf("Il nome dell’album è: %s", DBAlbum[i].titolo);
					printf("L’anno di uscita dell’album è: %d", DBAlbum[i].anno);
					j=j+1;
				}
				i=i+1;
			}
		}
		if(i==0){
			printf("Nessun album è stato trovato");
		}
}
