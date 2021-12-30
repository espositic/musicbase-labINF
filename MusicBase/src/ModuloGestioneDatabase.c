#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ModuloOutput.h"
#include "ModuloInput.h"
#include "ModuloRicerca.h"
#include "Dichiarazioni.h"

//Creazione elementi

Brano creaBrano(DatabaseBrano DBBrano);
Artista creaArtista(DatabaseArtista DBArtista,Artista nuovoArtista);
Album creaAlbum(DatabaseAlbum DBAlbum);
Genere creaGenere(DatabaseGenere DBGenere);
Utente creaUtente(DatabaseUtente DBUtente);
Playlist creaPlaylist(int idUtente, DatabasePlaylist DBPlaylist);

//Relazioni
void aggiungiRelazioneBranoAlbum(int idBrano,int idAlbum, DatabaseBranoAlbum DBBranoAlbum);
void creaRelazioneBranoAlbum(DatabaseBranoAlbum DBBranoAlbum, Brano nuovoBrano, DatabaseAlbum DBAlbum, DatabaseBrano DBBrano, DatabaseBranoArtista DBBranoArtista, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBPlaylistBrano);
void aggiungiRelazioneBranoArtista(int idBrano,int idArtista,DatabaseBranoArtista DBBranoArtista);
DatabaseBranoArtista creaRelazioneBranoArtista(DatabaseBranoArtista DBBranoArtista, Brano nuovoBrano, DatabaseArtista DBArtista);
void aggiungiRelazioneBranoGenere(int idBrano,int idGenere, DatabaseBranoGenere DBBranoGenere);
void creaRelazioneBranoGenere(DatabaseBranoGenere DBBranoGenere, Brano nuovoBrano, DatabaseGenere DBGenere);
void aggiungereBranoAPlaylist(int idBrano, int idPlaylist,DatabasePlaylistBrano DBPlaylistBrano);
//Trovare ultima posizione
int cercaUltimoBrano(DatabaseBrano DDBrano);
int cercaUltimoArtista(DatabaseArtista DBArtista);
int cercaUltimoAlbum(DatabaseAlbum DBAlbum);
int cercaUltimoGenere(DatabaseGenere DBGenere);
int cercaUltimoUtente(DatabaseUtente DBUtente);
int cercaUltimaPlaylist(DatabasePlaylist DBPlaylist);
int cercaPrimaPosizioneLibera(DatabaseBranoArtista DBBranoArtista);
int cercaPrimaRelazioneBranoAlbum(DatabaseBranoAlbum DBBranoAlbum);
int cercaPrimaRelazioneBranoGenereLibera(DatabaseBranoGenere DBBranoGenere);
int cercaPrimaRelazionePlaylistBranoLibera(DatabasePlaylistBrano DBPlaylistBrano);
void inserireBrano(DatabaseBrano DBBrano, DatabaseBranoAlbum DBBranoAlbum, DatabaseAlbum DBAlbum, DatabaseBranoGenere DBBranoGenere, DatabaseBranoArtista DBBranoArtista, DatabaseArtista DBArtista, DatabasePlaylistBrano DBPlaylistBrano);
void inserireAlbum(DatabaseAlbum DBAlbum);
void inserireArtista(DatabaseArtista DBArtista);
void inserisciGenere(DatabaseGenere DBGenere);
void inserisciUtente(DatabaseUtente DBUtente);
void inserisciPlaylist(int idUtente, DatabasePlaylist DBPlaylist, DatabaseBrano DBBrano, DatabaseUtente DBUtente, DatabasePlaylistBrano DBBranoPlaylist);
void modificaBrano(DatabaseBrano DBBrano, int campo, int idBrano);
void modificaAlbum(int campo, int idAlbum, DatabaseAlbum DBAlbum);
void modificaArtista(DatabaseArtista DBArtista, int campo, int idArtista);
void modificaGenere(int idGenere, DatabaseGenere DBGenere);
void modificaPlaylist(DatabasePlaylist DBPlaylist, int campo, int idPlaylist);
void modificaUtente(int campo, int idUtente, DatabaseUtente DBUtente);
void cancellaBrano(int idBrano, DatabaseBrano DBBrano, DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist);
void cancellaArtista(int idArtista, DatabaseArtista DBArtisti, DatabaseBrano DBBrano,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist);
void cancellaAlbum(int idAlbum, DatabaseAlbum DBAlbum, DatabaseBrano DBBrano,DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoArtista DBBranoArtista, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist);
void cancellaGenere(int idGenere, DatabaseGenere DBGenere, DatabaseBrano DBBrani,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum,DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist);
void cancellaPlaylist(int idPlaylist, DatabasePlaylist DBPlaylist,DatabaseBrano DBBrani,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum,DatabaseBranoGenere DBBranoGenere,DatabasePlaylistBrano DBBranoPlaylist);
void cancellaRelBranoArtista(int idBrano, DatabaseBranoArtista DBBranoArtista);
void cancellaRelBranoAlbum(int idBrano, DatabaseBranoAlbum DBBranoAlbum);
void cancellaRelBranoGenere(int idBrano, DatabaseBranoGenere DBBranoGenere);
void cancellaRelBranoPlaylist(int idBrano, DatabasePlaylistBrano DBBranoPlaylist);


/*	Funzione che prende come input il brano da inserire assieme
 * 	al database brano in cui inserire il brano e gli altri database
 * per creare le relazioni tra i database e come output avremo il
 * database brano aggiornato */
void inserireBrano(DatabaseBrano DBBrano, DatabaseBranoAlbum DBBranoAlbum, DatabaseAlbum DBAlbum, DatabaseBranoGenere DBBranoGenere, DatabaseBranoArtista DBBranoArtista, DatabaseArtista DBArtista, DatabasePlaylistBrano DBPlaylistBrano)
{	Brano nuovoBrano;
	char risposta;
	do
	{
		nuovoBrano=creaBrano(DBBrano);
		stampaBrano(nuovoBrano);
		printf("Confermi la tua scelta?(Y/N)");
		risposta=leggiCarattere();
	}
	while(risposta!='Y');
	DBBrano[nuovoBrano.idBrano]=nuovoBrano;
	DBBrano[nuovoBrano.idBrano+1].idBrano=IDSENTINELLA;
	creaRelazioneBranoAlbum(DBBranoAlbum, nuovoBrano, DBAlbum, DBBrano, DBBranoArtista, DBBranoGenere, DBPlaylistBrano);
	creaRelazioneBranoArtista(DBBranoArtista, nuovoBrano, DBArtista);
	return;
}

/*	Funzione che prende come input nuovoBrano di tipo brano e
 * il database brano per effettuare la creazione del nuovo brano.
 * Infine restituiamo il nuovo brano creato.*/
Brano creaBrano(DatabaseBrano DBBrano)
{
	Brano nuovoBrano;
	int annoSbagliato=1;
	nuovoBrano.idBrano=cercaUltimoBrano(DBBrano);
	printf("Inserisci il nome del brano");
	nuovoBrano.titolo=calloc(30,sizeof(char));
	nuovoBrano.titolo=(char*)leggiStringa();
	printf("Inserisci la durata del brano, in secondi");
	nuovoBrano.durata=leggiIntero();
	nuovoBrano.ascolti=0;
	printf("Inserisci l'anno di uscita brano");
	nuovoBrano.anno=leggiIntero();
	annoSbagliato=0;

	do
	{
		nuovoBrano.anno=leggiIntero();
			if(nuovoBrano.anno<ANNOMIN || nuovoBrano.anno>ANNOATTUALE)
			{
				printf("Anno sbagliato, inseriscilo dinuovo");
				annoSbagliato=1;
			}
			else
			{
				annoSbagliato=0;
			}
	}
	while(annoSbagliato==1);
	return nuovoBrano;
}

/*	Funzione che ha come input il database brano e come output abbiamo
 * la posizione dell'ultimo brano nel database. Questa funzione
 * serve per trovare la prima posizione libera nel database.*/
int cercaUltimoBrano(DatabaseBrano DDBrano)
{
	int ultimoID=0;
			while(DDBrano[ultimoID].idBrano!=IDSENTINELLA)
			{
				ultimoID++;
			}
	return ultimoID;
}

/*	Funzione che ha come input nuovo Brano di tipo brano,
 * 	il database brano album (dove inseriremo la relazione),
 *	il database album(dove cercheremo l'album) e gli altri
 *	database per un eventuale cancellazione del brano mentre come
 * 	output avremo il database brano album aggiornato. Questa
 * 	funzione inserisce a relazione tra brano e album.*/
void creaRelazioneBranoAlbum(DatabaseBranoAlbum DBBranoAlbum, Brano nuovoBrano, DatabaseAlbum DBAlbum, DatabaseBrano DBBrano, DatabaseBranoArtista DBBranoArtista, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBPlaylistBrano)
{
	char* albumDaCercare;
	int risultatoRicercaAlbum;
	char risposta;
	printf("Questo brano all'interno di quale album si trova?");
	albumDaCercare=calloc(20,sizeof(char));
	albumDaCercare=(char*)leggiStringa();
	risultatoRicercaAlbum=cercaAlbum(DBAlbum,albumDaCercare);
		if(risultatoRicercaAlbum>=0)
		{
			aggiungiRelazioneBranoAlbum(nuovoBrano.idBrano,risultatoRicercaAlbum,DBBranoAlbum);
		}
		else
		{
			printf("L'album scelto non è nel catalogo, il brano verra cancellato, confermi?(Y/N)");
			risposta=leggiCarattere();
			if(risposta=='N')
			{
				inserireAlbum(DBAlbum);
				aggiungiRelazioneBranoAlbum(nuovoBrano.idBrano, cercaUltimoAlbum(DBAlbum),DBBranoAlbum);
			}
			else
			{
				cancellaBrano(nuovoBrano.idBrano, DBBrano, DBBranoArtista,  DBBranoAlbum, DBBranoGenere, DBPlaylistBrano);
			}
		}
		return;
}

/*	Funzione che effettua la ricerca dell'album richiesto
 * (infatti come input abbiamo il nome dell'album da cercare
 * assieme al database che contiene tutti gli album, mentre
 * come output avremo la posizione in cui si trova l'album che abbimo cercato).*/
int cercaAlbum(DatabaseAlbum DBAlbum, char* nomeAlbum)
{
	int idTrovato=-1;
	int trovato=0;
	int i=0;
		while(DBAlbum[i].idAlbum!=IDSENTINELLA && trovato==0)
		{
			if(strcmp(DBAlbum[i].titolo,nomeAlbum)==0)
			{
				trovato=1;
				idTrovato=i;
			}
			i=i+1;
		}
		return idTrovato;
}

/*	Funzione che aggiunge la relazione tra brano e album
 * (infatti come input abbiamo gli id del brano e dell'album
 * in cui aggiungere la relazione assieme anche al database
 * brano album in cui inserire la relazione, mentre come output
 * avremo il database brano album aggiornato con le nuove relazioni)*/
void aggiungiRelazioneBranoAlbum(int idBrano,int idAlbum, DatabaseBranoAlbum DBBranoAlbum)
{	BranoAlbum NuovaRelazione;
	int primaPosizioneLibera=0;
	primaPosizioneLibera=cercaPrimaRelazioneBranoAlbum(DBBranoAlbum);
	NuovaRelazione.idAlbum=idAlbum;
	NuovaRelazione.idBrano=idBrano;
	DBBranoAlbum[primaPosizioneLibera]=NuovaRelazione;
	realloc(DBBranoAlbum, sizeof(BranoAlbum)*(primaPosizioneLibera+1));
	DBBranoAlbum[primaPosizioneLibera+1]=NuovaRelazione;
	DBBranoAlbum[primaPosizioneLibera+1].idAlbum=IDSENTINELLA;
	DBBranoAlbum[primaPosizioneLibera+1].idBrano=IDSENTINELLA;
	return;
}

/*	Funzione che crea relazione tra brano e artista (infatti
 * 	come input abbiamo il brano da cui creare la relazzione
 * 	assieme al database che contiene tutti gli artisti (dove
 *  andremo a cercare l'artista da collegare) ed infine abbiamo
 *   anche il database brano artista dove inseriremo la nuova relazione.
 *    Mentre come output avremo il database brano artista aggiornato)*/
DatabaseBranoArtista creaRelazioneBranoArtista(DatabaseBranoArtista DBBranoArtista, Brano nuovoBrano, DatabaseArtista DBArtista)
{
	char* artistaDaCercare;
	char risposta;
	int risultatoRicercaArtista=0;
	printf("Chi è l'artista del brano che vuoi inserire?");
	artistaDaCercare=calloc(30,sizeof(char));
	artistaDaCercare=(char*)leggiStringa();
	risultatoRicercaArtista=cercaArtista(DBArtista, artistaDaCercare);
		if(risultatoRicercaArtista>=0)
		{
			aggiungiRelazioneBranoArtista(nuovoBrano.idBrano, risultatoRicercaArtista, DBBranoArtista);
		}
		else
		{
			printf("L'artista scelto non è nel catalogo, il brano verrà cancellato, confermi?(Y/N)");
		}
		risposta=leggiCarattere();
		if(risposta=='Y')
		{
		}
		else
		{
			inserireArtista(DBArtista);
			aggiungiRelazioneBranoArtista(nuovoBrano.idBrano,cercaUltimoArtista(DBArtista),DBBranoArtista);
		}
		return DBBranoArtista;
}

/*	Funzione che effettua la ricerca dell'artista nel database
 *	artista(infatti come input avremo l'artista da ricercare assieme
 *	al database in cui effettuare la ricerca, mentre come output
 *	avremo la posizione dell'artista trovato)*/
int cercaArtista(DatabaseArtista DBArtista,char* nomeArtista)
{
	int idTrovato=-1;
	int trovato=0;
	int i=0;
	while(DBArtista[i].idArtista!=IDSENTINELLA && trovato==0)
	{
		if(strcmp(DBArtista[i].nomeArte,nomeArtista)==0)
		{
			trovato=1;
			idTrovato=i;
		}
		i=i+1;
	}
	return idTrovato;
}

/*	Funzione che aggiunge la relazione tra brano e artista all'interno
 * del database(infatti come input avremo gli id degli artisti e dei brani
 * assieme al database brano artista in cui inserire la relazione, mentre
 * come output avremo il database brano artista aggiornato)*/
void aggiungiRelazioneBranoArtista(int idBrano,int idArtista,DatabaseBranoArtista DBBranoArtista)
{
	int primaPosizioneLibera=cercaPrimaPosizioneLibera(DBBranoArtista);
	DBBranoArtista[primaPosizioneLibera].idArtista=idArtista;
	DBBranoArtista[primaPosizioneLibera].idBrano=idBrano;
	DBBranoArtista[primaPosizioneLibera+1].idBrano=IDSENTINELLA;
	DBBranoArtista[primaPosizioneLibera+1].idArtista=IDSENTINELLA;
	return;
}

/* 	Funzione che effettua la ricerca della prima posizione libera nel
 * database brano artista(infatti come input avremo il database brano
 * artista in cui effettuare la ricerca e come output avremo la posizione
 *  in cui si trova la prima posizione libera)*/
int cercaPrimaPosizioneLibera(DatabaseBranoArtista DBBranoArtista)
{
	int i=0;
	while(DBBranoArtista[i].idBrano!=IDSENTINELLA)
	{
		i=i+1;
	}
	return i;
}

/*	Funzione che crea la relazione brano genere,
*	infatti come input avremo il brano di cui effettuare
*	la relazione,poi il database genere (che contiene tutti
*	i generi) ed infine il database brano genere dove inseriremo
*	la nuova relazione. Mnetre come output avremo il database
*	brano genere aggiornato)*/
void creaRelazioneBranoGenere(DatabaseBranoGenere DBBranoGenere, Brano nuovoBrano, DatabaseGenere DBGenere)
{
	char* genereDaCercare;
	char risposta;
	int risultatoRicercaGenere=0;
	printf("Il brano in questione di che genere è?");
	genereDaCercare=calloc(30,sizeof(char));
	genereDaCercare=(char*)leggiStringa();
	risultatoRicercaGenere=cercaGenere(DBGenere, genereDaCercare);
	if(risultatoRicercaGenere>=0)
	{
		aggiungiRelazioneBranoGenere(nuovoBrano.idBrano, risultatoRicercaGenere,DBBranoGenere);
	}
	else
	{
		printf("Il genere scelto non è presente nel catalogo, il brano verrà cancellato, confermi?(Y/N)");
		risposta=leggiCarattere();

			if(risposta=='Y')
			{
				//Da definire
			}
			else
			{
				inserisciGenere(DBGenere);
				aggiungiRelazioneBranoGenere(nuovoBrano.idBrano,cercaUltimoGenere(DBGenere),DBBranoGenere);

			}
	}
	return;
}

/*	Questa funzione effettua la ricerca del genere richiesto
 * (infatti come input avremo il genere da ricercare assieme
 * al database genere(in cui efffettuare la ricerca) e come
output avremo la posizione del genere in cui è situato)*/
int cercaGenere(DatabaseGenere DBGenere, char* nomeGenere)
{
	int i=0;
	int trovato=0;
	int idTrovato=-1;
	while(DBGenere[i].idGenere!=IDSENTINELLA && trovato==0)
	{
		if(strcmp(DBGenere[i].nome,nomeGenere)==0)
		{
			trovato=1;
			idTrovato=i;
		}
		i=i+1;
	}
	return idTrovato;

}

/*	Questa funzione aggiunge la relazione tra brano e genere nel database
 *	brano genere(infatti come input avremo i vari id brano e id genere
 *	 assieme al database brano genere in cui inserire la relazione. Mentre
 *	 come output avremo il database brano genere aggiornato)*/

void aggiungiRelazioneBranoGenere(int idBrano,int idGenere, DatabaseBranoGenere DBBranoGenere)
{
	int primaPosizioneLibera=0;
	primaPosizioneLibera=cercaPrimaRelazioneBranoGenereLibera(DBBranoGenere);
	DBBranoGenere[primaPosizioneLibera].idGenere=idGenere;
	DBBranoGenere[primaPosizioneLibera].idBrano=idBrano;
	DBBranoGenere[primaPosizioneLibera+1].idBrano=IDSENTINELLA;
	DBBranoGenere[primaPosizioneLibera+1].idGenere=IDSENTINELLA;
	return;
}

/*	Questa funzione cerca la prima posizione libera nel database brano genere
 * (infatti come input abbiamo il database brano genere da cui effettuare la ricerca,
 *  mentre come output avremo la prima posizione libera)*/
int cercaPrimaRelazioneBranoGenereLibera(DatabaseBranoGenere DBBranoGenere)
{
	int i=0;
	while(DBBranoGenere[i].idBrano!=IDSENTINELLA)
	{
		i=i+1;
	}
	return i;
}

/*	Funzione che serve per inserire il nuovo artista nel database artista
 * 	(infatti come input abbiamo l'artista da inserire assieme al database
 * 	 artista. Mentre come output avremo il database artista aggiornato)*/
void inserireArtista(DatabaseArtista DBArtista)
{	Artista nuovoArtista;
	char risposta;
	do
	{
		nuovoArtista=creaArtista(DBArtista, nuovoArtista);
		stampaArtista(nuovoArtista);
		printf("Confermi la tua scelta?(Y/N)");
		risposta=leggiCarattere();
			while(risposta!='Y')
			{
				DBArtista[nuovoArtista.idArtista]=nuovoArtista;
				realloc(DBArtista, sizeof(Artista)*(nuovoArtista.idArtista+1));
				DBArtista[nuovoArtista.idArtista+1]=nuovoArtista;
				DBArtista[nuovoArtista.idArtista+1].idArtista=IDSENTINELLA;
			}
	}while(risposta=='Y');
	return;
}


/*	Funzione che serve a creare le info sul nuovo artista(infatti come
*	input abbiamo il nuovoArtista di tipo "artista" in cui inserire i
*	nuovi dati, assieme al database artisti in cui inseriremo il nuovo
*	artista. mentre come output avremo il database artisti aggiornato
*	con i nuovi artisti)*/
Artista creaArtista(DatabaseArtista DBArtista,Artista nuovoArtista)
{
	int ultimoArtista=cercaUltimoArtista(DBArtista);
	nuovoArtista.idArtista=ultimoArtista;
	printf("Qual è il nome dell'artista da inserire?");
	nuovoArtista.nome=calloc(30,sizeof(char));
	nuovoArtista.nome=(char*)leggiStringa();
	printf("Qual è il cognome dell'artista da inserire?");
	nuovoArtista.cognome=calloc(30,sizeof(char));
	nuovoArtista.cognome=(char*)leggiStringa();
	printf("Qual è il nome d'arte dell'artista da inserire?");
	nuovoArtista.nomeArte=calloc(30,sizeof(char));
	nuovoArtista.nomeArte=(char*)leggiStringa();
	printf("inserire il link della biografia dell'artista");
	nuovoArtista.linkBio=calloc(30,sizeof(char));
	nuovoArtista.linkBio=(char*)leggiStringa();
	return nuovoArtista;
}

/*	Funzione utilizzata per cercare l'ultimo artista nel
 * 	database(infatti come input abbiamo il database per effettuare la ricerca)*/
int cercaUltimoArtista(DatabaseArtista DBArtista)
{
	int ultimoID=0;
	while(DBArtista[ultimoID].idArtista!=IDSENTINELLA)
	{
		ultimoID=ultimoID+1;
	}
	return ultimoID;
}

/*	Funzione che serve per inserire il nuovo album nel database album
 * 	(infatti come input abbiamo l'album da inserire assieme al database
 * 	 album. Mentre come output avremo il database album aggiornato)*/
void inserireAlbum(DatabaseAlbum DBAlbum)
{	Album nuovoAlbum;
	char risposta;
	do
	{
		nuovoAlbum=creaAlbum(DBAlbum);
		stampaAlbum(nuovoAlbum);
		printf("Confermi la tua scelta?(Y/N)");
		risposta=leggiCarattere();
			while(risposta!='Y')
			{
				DBAlbum[nuovoAlbum.idAlbum]=nuovoAlbum;
				realloc(DBAlbum, sizeof(Album)*(nuovoAlbum.idAlbum+1));
				DBAlbum[nuovoAlbum.idAlbum+1]=nuovoAlbum;
				DBAlbum[nuovoAlbum.idAlbum+1].idAlbum=IDSENTINELLA;
			}
	}while(risposta=='Y');
	return;
}

/*	//funzione che serve per la creazione dei nuovi album
 * (infatti come input abbiamo il nuovo album assieme al
 * database album. Mentre come output avremo l'album creato)*/
Album creaAlbum(DatabaseAlbum DBAlbum)
{
	Album nuovoAlbum;
	nuovoAlbum.idAlbum=cercaUltimoAlbum(DBAlbum);
	printf("Qual è il titolo dell'album da inserire?");
	nuovoAlbum.titolo=calloc(30,sizeof(char));
	nuovoAlbum.titolo=(char*)leggiStringa();
	printf("Qual'è l'anno di uscita dell'album da inserire?");
	nuovoAlbum.anno=leggiIntero();
	return nuovoAlbum;
}

/*	Funzione che effettua la ricerca della prima posizione
 *	libera nel database album(infatti come input abbiamo il
 *	 database album, mentre come output avremo la prima posizione libera)*/
int cercaUltimoAlbum(DatabaseAlbum DBAlbum)
{
	int ultimoID=0;
	while(DBAlbum[ultimoID].idAlbum!=IDSENTINELLA)
	{
		ultimoID=ultimoID+1;
	}
	return ultimoID;
}

/*	Funzione che serve per inserire un nuovo genere nel database
 * 	genere(infatti come input avremo il nuovo genere da inserire
 * 	assieme al database genere, mentre come output avremo il database
 * 	 genere aggiornato)*/
void inserisciGenere(DatabaseGenere DBGenere)
{
	char risposta;
	Genere nuovoGenere;
	do
	{
		nuovoGenere=creaGenere(DBGenere);
		stampaGenere(nuovoGenere);
		printf("Confermi la tua scelta?(Y/N)");
		risposta=leggiCarattere();
	}while(risposta=='Y');
	DBGenere[nuovoGenere.idGenere]=nuovoGenere;
	DBGenere[nuovoGenere.idGenere+1].idGenere=IDSENTINELLA;
	return;
}

/*	Funzione utilizzata per creare un nuovo genere, infatti avremo
 * 	come input il dato nuovoGenere di tipo Genere(che dovremmo creare)
 * 	assieme al database genere. Mentre come output avremo il nuogo genere creato*/
Genere creaGenere(DatabaseGenere DBGenere)
{
	Genere nuovoGenere;
	nuovoGenere.idGenere=cercaUltimoGenere(DBGenere);
	printf("Qual è il nome del genere da inserire");
	nuovoGenere.nome=calloc(30,sizeof(char));
	nuovoGenere.nome=(char*)leggiStringa();
	return nuovoGenere;
}

/*	Funzione utilizzata per cercare la prima posizione libera nel
 * 	database genere(infatti come inpiut avremo il database genere,
 * 	mentre come output avremo la prima posizione libera)*/
int cercaUltimoGenere(DatabaseGenere DBGenere)
{
	int ultimoID=0;
	while(DBGenere[ultimoID].idGenere!=IDSENTINELLA)
	{
		ultimoID=ultimoID+1;
	}
	return ultimoID;
}

/*	Funzione utilizzata per inserire un nuovo utente nel database
*	utente(infatti come input avremo il nuovo utente da inserire
*	assieme al database utente(in cui appunto inseriremo il nuovo utente)
*	, mentre come output avremo il database aggiornato con il nuovo utente inserito)*/
void inserisciUtente(DatabaseUtente DBUtente)
{
	char risposta;
	Utente nuovoUtente;
	do
	{
		nuovoUtente=creaUtente(DBUtente);
		stampaUtente(nuovoUtente);
		printf("Confermi la tua scelta?(Y/N)");
		risposta=leggiCarattere();
	}while(risposta!='Y');
	DBUtente[nuovoUtente.idUtente]=nuovoUtente;
	DBUtente[nuovoUtente.idUtente+1].idUtente=IDSENTINELLA;
	return;
}

/*	Funzione utilizzata per ricercare un utente nel database(infatti come
 * 	input avremo l'utente da cercare assieme al database utente in cui
 * 	effettuare la ricerca, mentre come output avremo il database utente aggiornato)*/
Utente creaUtente(DatabaseUtente DBUtente)
{	Utente nuovoUtente;
	nuovoUtente.idUtente=cercaUltimoUtente(DBUtente);
	printf("Qual è il nome utente dell'utente da inserire?");
	nuovoUtente.nomeUtente=calloc(30,sizeof(char));
	nuovoUtente.nomeUtente=(char*)leggiStringa();
	printf("inserire la password");
	nuovoUtente.password=calloc(30,sizeof(char));
	nuovoUtente.password=(char*)leggiStringa();
	return nuovoUtente;
}

/*	Funzione utilizzata per cercare la prima posizione libera nel
 * database utente(infatti come input avremo il database utente
 *  in cui effettuare la ricerca, mentre come output avremo la prima
 *   posizione libera)*/
int cercaUltimoUtente(DatabaseUtente DBUtente)
{
	int ultimoID;
	while(DBUtente[ultimoID].idUtente!=IDSENTINELLA)
	{
		ultimoID=ultimoID+1;
	}
	return ultimoID;
}

void inserisciPlaylist(int idUtente, DatabasePlaylist DBPlaylist, DatabaseBrano DBBrano, DatabaseUtente DBUtente, DatabasePlaylistBrano DBBranoPlaylist)//funzione utilizzata per inserire una nuova playlist nel databasePlaylist(infatti come input avremo la nuova playlist da inserire, poi avremo anche il database brano(in cui prenderemo i vari brani inseriti nella playlist), successivamente avremo l'id utente che indicherà l'utente che ha creato la playlist ed infine avremo il database playlist dove inserire la nuova playlist. Mentre come output avremo il database playlist aggiornato)
{	Playlist nuovaPlaylist;
	char risposta;
	do
	{
		nuovaPlaylist=creaPlaylist(idUtente, DBPlaylist);
		stampaPlaylist(nuovaPlaylist, DBUtente);
		printf("confermi la tua scelta?(Y/N)");
		risposta=leggiCarattere();

	}while(risposta!='Y');

	do
	{
		printf("Vuoi aggiungere un brano alla playlist?");
		risposta=leggiCarattere();
			if(risposta=='Y')
			{
				printf("Scrivi il titolo del brano da aggiugnere alla playlist");
				char* titoloBrano=calloc(30,sizeof(char));
				titoloBrano=(char*)leggiStringa();
				int* idBrano= (int*)ricercaBranoTramiteTitoloBrano(titoloBrano,DBBrano);
				stampaListaBrani(idBrano, DBBrano);
				printf("Quale brano vuoi aggiungere?");
				int id=leggiIntero();
				aggiungereBranoAPlaylist(id, nuovaPlaylist.idPlaylist ,DBBranoPlaylist);
			}
	}while(risposta=='Y');

	DBPlaylist[nuovaPlaylist.idPlaylist]=nuovaPlaylist;
	return;
}

/*	Funzione che effettua la creazione di nuove playlist(infatti come input
 *	abbiamo la nuova playlist di tipo Playlist da creare, poi abbiamo anche
 *	il databasePlaylist in cui inserire la nuova playlist ed infine abbiamo
 *	l'id utente che ha creato la playlist. Mentre come output avremo il nuovo
 *	database aggiornato)*/
Playlist creaPlaylist(int idUtente, DatabasePlaylist DBPlaylist)
{	Playlist nuovaPlaylist;
	char risposta;
	nuovaPlaylist.idPlaylist=cercaUltimaPlaylist(DBPlaylist);
	nuovaPlaylist.idPlaylist=idUtente;
	printf("Qual è il nome della playlist da inserire?");
	nuovaPlaylist.nome=calloc(30,sizeof(char));
	nuovaPlaylist.nome=(char*)leggiStringa();
	printf("Inserisci la descrizione");
	nuovaPlaylist.descrizione=calloc(100,sizeof(char));
	nuovaPlaylist.descrizione=(char*)leggiStringa();
	do
	{
		printf("la playlist è pubblica?(Y/N)");
		risposta=leggiCarattere();
	}while(risposta!='Y' && risposta!='N');

	if(risposta=='Y')
	{
		nuovaPlaylist.pubblica=1;
	}
	else
	{
		nuovaPlaylist.pubblica=0;
	}
	return nuovaPlaylist;
}

/*	Funzione che ricerca la prima posizione libera nel database
 * 	playlist(infatti come input abbiamo il database playlist
 * 	mentre come output avremo la prima posizione libera)*/
int cercaUltimaPlaylist(DatabasePlaylist DBPlaylist)
{
	int ultimoID=0;
	while(DBPlaylist[ultimoID].idPlaylist!=IDSENTINELLA)
	{
		ultimoID=ultimoID+1;
	}
	return ultimoID;
}

/*	Questa funzione viene utilizzata per aggiungere i brani
 * alla nuova playlist(infatti abbiamo come input la nuova
 *  playlist creata assieme al database brano e al ddatabase
 *  playlist brano, così da inserire i nuovi brani e aggiungere
 *  la nuova relazione(abbiamo anche i vari id brano e id playlist
 *  per creare la relaione). Mentre come output avremo il database
 *  playlist brano aggiornato)*/
void aggiungereBranoAPlaylist(int idBrano, int idPlaylist,DatabasePlaylistBrano DBPlaylistBrano)
{
	int primaPosizioneLibera;
	primaPosizioneLibera=cercaPrimaRelazionePlaylistBranoLibera(DBPlaylistBrano);
	DBPlaylistBrano[primaPosizioneLibera].idPlaylist=idPlaylist;
	DBPlaylistBrano[primaPosizioneLibera].idBrani=idBrano;
	DBPlaylistBrano[primaPosizioneLibera+1].idPlaylist=IDSENTINELLA;
	DBPlaylistBrano[primaPosizioneLibera+1].idBrani=IDSENTINELLA;
	return;
}

/*//funzione utilizzata per ricercare la prima posizione libera nel
 *  database playlist brano(infatti come input avremo il database
 *   playlist brano, mentre come output la prima posizione libera)*/
int cercaPrimaRelazionePlaylistBranoLibera(DatabasePlaylistBrano DBPlaylistBrano)
{
	int i=0;
	while(DBPlaylistBrano[i].idPlaylist!=IDSENTINELLA)
	{
		i=i+1;
	}
	return i;
}

int cercaPrimaRelazioneBranoAlbum(DatabaseBranoAlbum DBAlbum){
	int i=0;
	while(DBAlbum[i].idAlbum!=IDSENTINELLA)
		i++;
	return i;
}
//Da controllare
/*	Questa funzione viene utilizzata per modificare un determinato brano
 * 	richiesto dall'utente(infatti in input avremo il database brano che
 * 	cointiene i brani assieme all'id brano utile per determinare il brano
 * 	da modificare(abbiamo anche il valore Campo che serve a determinare cosa
 * 	modificare del brano). Mentre come output avremo il database brano aggiornato)*/
void modificaBrano(DatabaseBrano DBBrano, int campo, int idBrano)
{
	char* titolo;
	int durata;
	int anno;
	if(campo==1)
	{
		printf("inserisci nuovo nome");
		titolo=calloc(30,sizeof(char));
		titolo=(char*)leggiStringa();
		DBBrano[idBrano].titolo=titolo;
	}
	else if(campo==2)
	{
		printf("qual è la nuova durata?");
		durata=leggiIntero();
		DBBrano[idBrano].durata=durata;
	}
	else if(campo==3)
	{
		printf("in che anno è uscito il brano?");
		do
		{
			anno=leggiIntero();
		}while(anno<ANNOMIN || anno>ANNOATTUALE);
		DBBrano[idBrano].anno=anno;
	}
	return;
}

/*	Funzione che effettua la modifica di un determinato album(infatti abbiamo
 * come input l'ird dell'album da modificare assieme al database da cui modificare
 * l'album(abbiamo anche la variabile campo che indica cosa modificare dell'album).
 * mentre come output avremo il database album aggiornato)*/
void modificaAlbum(int campo, int idAlbum, DatabaseAlbum DBAlbum)
{
	char* titolo;
	int anno;
	if(campo==1)
	{
		printf("nuovo nome");
		titolo=calloc(30,sizeof(char));
		titolo=(char*)leggiStringa();
		DBAlbum[idAlbum].titolo=titolo;
	}
	else if(campo==2)
	{
		printf("nuovo anno");
		do
		{
			anno=leggiIntero();
		}while(anno<ANNOMIN || anno>ANNOATTUALE);
		DBAlbum[idAlbum].anno=anno;
	}
}

/*	Questa funzione è utilizzata per effettuare modifiche su un detemrinato artista
 *  richiesto(infatti come input abbiamo l'ird dell'artista da modificare assieme al
 *  database da cui prendere l'artista(ovvero sia database artisti), inoltre abbiamo
 *   anche la variabile campo utilizzata per determinare cosa vogliamo modificare
 *   dell'artista. Mentre come output avremo il database artisti modificato)*/
void modificaArtista(DatabaseArtista DBArtista, int campo, int idArtista)
{
	char* nuovoNome;
	char* nuovoCognome;
	char* nuovoNomeArte;
	char* nuovaLinkBio;
	if(campo==1)
	{
		printf("inserisci nuovo nome");
		nuovoNome=calloc(30,sizeof(char));
		nuovoNome=(char*)leggiStringa();
		DBArtista[idArtista].nome=nuovoNome;
	}
	else if(campo==2)
	{
		printf("inserisci nuovo cognome");
		nuovoCognome=calloc(30,sizeof(char));
		nuovoCognome=(char*)leggiStringa();
		DBArtista[idArtista].cognome=nuovoCognome;
	}
	else if(campo==3)
	{
		printf("inserisci nuovo nome d'arte");
		nuovoNomeArte=calloc(30,sizeof(char));
		nuovoNomeArte=(char*)leggiStringa();
		DBArtista[idArtista].nomeArte=nuovoNomeArte;
	}
	else if(campo==4)
	{
		printf("inserisci nuova linkbio");
		nuovaLinkBio=calloc(30,sizeof(char));
		nuovaLinkBio=(char*)leggiStringa();
		DBArtista[idArtista].linkBio=nuovaLinkBio;

	}
	return;
}


/*	Funzione utilizzata per modificare un determinato genere richiesto
 * 	(infatti come input abbiamo il database genere assieme all'id genere
 * 	da modificare, mnetre come output avremo il database genere modiifcato)*/
void modificaGenere(int idGenere, DatabaseGenere DBGenere)
{
	char* nuovoNomeGenere;
	printf("qual è il nuovo nome genere");
	nuovoNomeGenere=calloc(30,sizeof(char));
	nuovoNomeGenere=(char*)leggiStringa();
	DBGenere[idGenere].nome=nuovoNomeGenere;
	return;
}

/*	Funzione utilizzata per modificare una playlist(infatti come input abbiamo
 *	l'id della playlist da comoficare assieme al database playlist(abbiamo anche
 *	la variabile campo che indica cosa andremo a modificare. Mentre come output
 *	avremo il database Playlist modificato)*/
void modificaPlaylist(DatabasePlaylist DBPlaylist, int campo, int idPlaylist)
{
	char* nuovoNome;
	char* nuovaDescrizione;
	if(campo==1)
	{
		printf("scrivi il nuovo nome");
		nuovoNome=calloc(30,sizeof(char));
		nuovoNome=(char*)leggiStringa();
		DBPlaylist[idPlaylist].nome=nuovoNome;
	}
	else if(campo==2)
	{
		printf("inserisci nuova descrizione");
		nuovaDescrizione=calloc(100,sizeof(char));
		nuovaDescrizione=(char*)leggiStringa();
		DBPlaylist[idPlaylist].descrizione=nuovaDescrizione;
	}
	return;
}


/*	Questa funzione viene utilizzata per apportare modifiche a un
 * determinato utente(infatti come input abbiamo il database da cui
 * prelevare l'utente assieme all'id utente da cercare(inoltre abbiamo
 * anche una variabile campo utilizzata per decidere cosa modificare).
 * Mentre come output avremo il databse Utente modificato)*/
void modificaUtente(int campo, int idUtente, DatabaseUtente DBUtente)
{
	char* nuovoNomeUtente;
	char* nuovaPassword;
	if(campo==1)
	{
		printf("inserisci nuovo nome utente");
		nuovoNomeUtente=calloc(30,sizeof(char));
		nuovoNomeUtente=(char*)leggiStringa();
		DBUtente[idUtente].nomeUtente=nuovoNomeUtente;
	}
	else if(campo==2)
	{
		printf("inserisci nuova password");
		nuovaPassword=calloc(30,sizeof(char));
		nuovaPassword=(char*)leggiStringa();
		DBUtente[idUtente].password=nuovaPassword;
	}
	return;
}

/*	Questa funzione effettua la cancellazione dei brani da tutti i
 * database in cui lo troviamo(infatti come input abbiamo l'id del brano
 * da cancellare, assieme ai vari database da cui cancellarlo, mentre
 * come output avremo il database brano aggiornato)*/
void cancellaBrano(int idBrano, DatabaseBrano DBBrano, DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist)
{
	DBBrano[idBrano].idBrano=IDCANCELLATO;
	cancellaRelBranoArtista(idBrano,DBBranoArtista);
	cancellaRelBranoAlbum(idBrano,DBBranoAlbum);
	cancellaRelBranoGenere(idBrano,DBBranoGenere);
	cancellaRelBranoPlaylist(idBrano,DBBranoPlaylist);
	return;
}

/*	Questa funzione effettua la cancellazione degli artisti dal database
 * 	artista(infatti come input abbiamo l'id artista da cancellare assieme
 * 	ai vari database in cui ritroviamo l'artista. Mentre come output avremo
 * 	il database Artista aggiornato)*/
void cancellaArtista(int idArtista, DatabaseArtista DBArtisti, DatabaseBrano DBBrano,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist)
{
	DBArtisti[idArtista].idArtista=IDCANCELLATO;
	int i=0;
	while(DBBranoArtista[i].idArtista!=IDSENTINELLA)
	{
		if(DBBranoArtista[i].idArtista==idArtista)
		{
			cancellaBrano(DBBranoArtista[i].idBrano, DBBrano, DBBranoArtista, DBBranoAlbum, DBBranoGenere, DBBranoPlaylist);
		}
		i=i+1;
	}
	return;
}

/*	Questa funzione effettua la cancellazione degli album dal database
 * 	album(infatti come input abbiamo l'id album da cancellare assieme
 * 	ai vari database in cui ritroviamo l'album. Mentre come output avremo
 * 	il database album aggiornato)*/
void cancellaAlbum(int idAlbum, DatabaseAlbum DBAlbum, DatabaseBrano DBBrano,DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoArtista DBBranoArtista, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist)
{
	DBAlbum[idAlbum].idAlbum=IDCANCELLATO;
	int i=0;
	while(DBBranoAlbum[i].idAlbum!=IDSENTINELLA)
	{
		if(DBBranoAlbum[i].idAlbum==idAlbum)
		{
			cancellaBrano(DBBranoAlbum[i].idBrano, DBBrano, DBBranoArtista, DBBranoAlbum, DBBranoGenere, DBBranoPlaylist);
		}
		i=i+1;
	}
	return;
}

/*	Questa funzione serve per effettuare la cancellazione di un determinato
 * genere dal database genere(infatti abbiamo come input l'id del genere da
 * modificare assieme ai vari database in cui viene trovato. Mentre come output
 * avremo il database genere modificato)*/
void cancellaGenere(int idGenere, DatabaseGenere DBGenere, DatabaseBrano DBBrani,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum,DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist)
{
	DBGenere[idGenere].idGenere=IDCANCELLATO;
	int i=0;
	while(DBBranoGenere[i].idGenere!=IDSENTINELLA)
	{
		if(DBBranoGenere[i].idGenere==idGenere)
		{
			cancellaBrano(DBBranoGenere[i].idBrano,DBBrani,DBBranoArtista,DBBranoAlbum,DBBranoGenere,DBBranoPlaylist);
		}
		i=i+1;
	}
	return;
}

/*	Funzione utilizzata per cancellare una playlist dai vari database in
 * cui è situata(infatti come input abbiamo l'id del database che deve essere
 * cancellato assieme ai database da cui rimuoverla. Mentre come output abbiamo
 * il database Playlist aggiornato)*/
void cancellaPlaylist(int idPlaylist, DatabasePlaylist DBPlaylist,DatabaseBrano DBBrani,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum,DatabaseBranoGenere DBBranoGenere,DatabasePlaylistBrano DBBranoPlaylist)
{
	DBPlaylist[idPlaylist].idPlaylist=IDCANCELLATO;
	int i=0;
	while(DBBranoPlaylist[i].idPlaylist!=IDSENTINELLA && DBBranoPlaylist[i].idPlaylist!=idPlaylist)
	{
		i=i+1;
	}
	if(DBBranoPlaylist[i].idPlaylist!=IDSENTINELLA)
	{
		DBBranoPlaylist[i].idPlaylist=IDCANCELLATO;
	}
	return;
}

/*	Funzione che rimuove la relazione tra brano e artista(infatti come input abbiamo
 * l'id del brano e il database brano artista. Mentre come output avremo il database
 * brano artista modificato)*/
void cancellaRelBranoArtista(int idBrano, DatabaseBranoArtista DBBranoArtista)
{
	int i=0;
	while(DBBranoArtista[i].idBrano!=idBrano && DBBranoArtista[i].idArtista!=IDSENTINELLA)
	{
		i=i+1;
	}
	if(DBBranoArtista[i].idBrano!=IDSENTINELLA)
	{
		DBBranoArtista[i].idBrano=IDCANCELLATO;
		DBBranoArtista[i].idArtista=IDCANCELLATO;
	}
	return;
}

/*	Funzione utilizzata per rimuovere relazione tra brano e album(infatti
 * come inpout abbiamo l'id del brano e il database brano album da cui
 * rimuovere la relazione. Mentre come output avremo il database brano
 * album aggiornato)*/
void cancellaRelBranoAlbum(int idBrano, DatabaseBranoAlbum DBBranoAlbum)
{
	int i=0;
	while(DBBranoAlbum[i].idBrano!=idBrano && DBBranoAlbum[i].idBrano!=IDSENTINELLA)
	{
		i=i+1;
	}
	if(DBBranoAlbum[i].idBrano!=IDSENTINELLA)
	{
		DBBranoAlbum[i].idBrano=IDCANCELLATO;
		DBBranoAlbum[i].idAlbum=IDCANCELLATO;
	}
	return;
}

/*	Funzione utilizzata per rimuovere le relazioni di un brano nel database
 * brano genere(infatti come input abbiamo l'id del brano e il database brano
 * genere da cui rimuovere la relazione. Mentre come output avremo il database
 * Brano genere aggiornato)*/
void cancellaRelBranoGenere(int idBrano, DatabaseBranoGenere DBBranoGenere)
{
	int i=0;
	while(DBBranoGenere[i].idBrano!=idBrano && DBBranoGenere[i].idBrano!=IDSENTINELLA)
	{
		i=i+1;
	}
	if(DBBranoGenere[i].idBrano!=IDSENTINELLA)
	{
		DBBranoGenere[i].idBrano=IDCANCELLATO;
		DBBranoGenere[i].idGenere=IDCANCELLATO;
	}
	return;
}

/*	Funzione utilizzata per rimuovere la relazione di un brano nel database brano
 * playlist(infatti, come input, abbiamo l'id del brano da rimuovere assieme al
 * database brano playlist da cui rimuovere la relazione. Mentre come output avremo
 * il database brano playlist)*/
void cancellaRelBranoPlaylist(int idBrano, DatabasePlaylistBrano DBBranoPlaylist)
{
	int i=0;
	while(DBBranoPlaylist[i].idBrani!=idBrano && DBBranoPlaylist[i].idPlaylist!=IDSENTINELLA)
	{
		i=i+1;
	}
	if(DBBranoPlaylist[i].idPlaylist!=IDSENTINELLA)
	{
		DBBranoPlaylist[i].idPlaylist=IDCANCELLATO;
	}
	return;
}

