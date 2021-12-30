#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dichiarazioni.h"
#define IDSENTINELLA -1
#define IDCANCELLATO -2

/*	Funzione che dato in input il titolo di un brano e il database in cui cercarlo
 * 	darà in output un array contenente gli id dei brani che hanno quel titolo.*/
int* ricercaBranoTramiteTitoloBrano(char* titoloBrano, DatabaseBrano DBBrano){
	int* risultato;
	risultato=calloc(100,sizeof(int));
	int i=0;
	int j=0;
	while(DBBrano[i].idBrano!=IDSENTINELLA){
		if(strcmp(titoloBrano,DBBrano[i].titolo)==0 && DBBrano[i].idBrano!=IDCANCELLATO){
			risultato[j]=i;
			j=j+1;
		}
		i=i+1;
	}
	return risultato;
}

/*	Funzione che dato in input il nome di una playlist e il database in cui cercarla
 * 	darà in output un array contenente gli id delle playlist che hanno quel nome.*/
int* ricercaPlaylistTramiteNomePlaylist(char* nomePlaylist, DatabasePlaylist DBPlaylist){
	int* risultato;
	risultato=calloc(100,sizeof(int));
	int i=0;
	int j=0;
	while(DBPlaylist[i].idPlaylist!=IDSENTINELLA){
		if(strcmp(nomePlaylist,DBPlaylist[i].nome)==0 && DBPlaylist[i].idPlaylist!=IDCANCELLATO){
			risultato[j]=i;
			j=j+1;
		}
		i=i+1;
	}
	return risultato;
}

/*	Funzione che dato in input il nome di un utente e il database in cui cercarlo
 * 	darà in output un array contenente gli id degli utenti che hanno quel nome.*/
int* ricercaUtenteTramiteNomeUtente(char* nomeUtente, DatabaseUtente DBUtente){
	int* risultato;
	risultato=calloc(100,sizeof(int));
	int i=0;
	int j=0;
	while(DBUtente[i].idUtente!=IDSENTINELLA){
		if(strcmp(nomeUtente,DBUtente[i].nomeUtente)==0 && DBUtente[i].idUtente!=IDCANCELLATO){
			risultato[j]=i;
			j=j+1;
		}
		i=i+1;
	}
	return risultato;
}

/*	Funzione che dato in input il nome di un artista e il database in cui cercarlo
 * 	darà in output un array contenente gli id degli artisti che hanno quel nome.*/
int* ricercaArtistaTramiteNomeArtista(char* nomeArte, DatabaseArtista DBArtista){
	int* risultato;
	risultato=calloc(100,sizeof(int));
	int i=0;
	int j=0;
	while(DBArtista[i].idArtista!=IDSENTINELLA){
		if(strcmp(nomeArte,DBArtista[i].nomeArte)==0 && DBArtista[i].idArtista!=IDCANCELLATO){
			risultato[j]=i;
			j=j+1;
		}
		i=i+1;
	}
	return risultato;
}

/*	Funzione che dato in input il titolo di un album e il database in cui cercarlo
 * 	darà in output un array contenente gli id degli album che hanno quel titolo.*/
int* ricercaAlbumTramiteTitoloAlbum(char* titoloAlbum, DatabaseAlbum DBAlbum){
	int* risultato;
	risultato=calloc(100,sizeof(int));
	int i=0;
	int j=0;
	while(DBAlbum[i].idAlbum!=IDSENTINELLA){
		if(strcmp(titoloAlbum,DBAlbum[i].titolo)==0 && DBAlbum[i].idAlbum!=IDCANCELLATO){
			risultato[j]=i;
			j=j+1;
		}
		i=i+1;
	}
	return risultato;
}

/*	Funzione che dato in input l'anno di un album e il database in cui cercarlo
 * 	darà in output un array contenente gli id degli album che sono usciti in
 * 	quell'anno.*/
int* ricercaAlbumTramiteAnnoAlbum(int annoAlbum, DatabaseAlbum DBAlbum){
	int* risultato;
	risultato=calloc(100,sizeof(int));
	int i=0;
	int j=0;
	while(DBAlbum[i].idAlbum!=IDSENTINELLA){
		if(annoAlbum==DBAlbum[i].anno && DBAlbum[i].idAlbum!=IDCANCELLATO){
			risultato[j]=i;
			j=j+1;
		}
		i=i+1;
	}
	return risultato;
}

/*	Funzione che dato in input il nome di un genere e il database in cui cercarlo
 * 	darà in output un array contenente gli id dei generi che hanno quel nome.*/
int* ricercaGenereTramiteNome(char* nome, DatabaseGenere DBGenere){
	int* risultato;
	risultato=calloc(100,sizeof(int));
	int i=0;
	int j=0;
	while(DBGenere[i].idGenere!=IDSENTINELLA){
		if(strcmp(nome,DBGenere[i].nome)==0 && DBGenere[i].idGenere!=IDCANCELLATO){
			risultato[j]=i;
			j=j+1;
		}
		i=i+1;
	}
	return risultato;
}
