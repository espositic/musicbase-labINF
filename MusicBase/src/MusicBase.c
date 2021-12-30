#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dichiarazioni.h"
#include "ModuloGestioneMemoria.h"
#include "ModuloInput.h"
#include "ModuloOutput.h"
#include "ModuloRicerca.h"
#include "ModuloGestioneDatabase.h"

int main(){
	int* idBrani;
	int* idAlbum;
	int* idGeneri;
	int* idArtisti;
	int* idPlaylist;
	char* StrAppoggio;
	StrAppoggio=calloc(30,sizeof(char));
	int scelta,SottoScelta;
	char risp;


	DatabaseBrano DBBrano;
	DBBrano=calloc(100,sizeof(Brano));
	caricaDBBrano(DBBrano);
	DatabaseAlbum DBAlbum;
	DBAlbum=calloc(100,sizeof(Album));
 	caricaDBAlbum(DBAlbum);
    DatabaseArtista DBArtisti;
	DBArtisti=calloc(100,sizeof(Artista));
    caricaDBArtisti(DBArtisti);
    DatabaseGenere DBGeneri;
	DBGeneri=calloc(100,sizeof(Genere));
    caricaDBGeneri(DBGeneri);
    DatabasePlaylist DBPlaylist;
	DBPlaylist=calloc(100,sizeof(Playlist));
    caricaDBPlaylist(DBPlaylist);
    DatabaseBranoArtista DBBranoArtista;
	DBBranoArtista=calloc(100,sizeof(BranoArtista));
    caricaDBBranoArtista(DBBranoArtista);
    DatabaseBranoAlbum DBBranoAlbum;
	DBBranoAlbum=calloc(100,sizeof(BranoAlbum));
    caricaDBBranoAlbum(DBBranoAlbum);
    DatabaseBranoGenere DBBranoGenere;
	DBBranoGenere=calloc(100,sizeof(BranoGenere));
    caricaDBBranoGenere(DBBranoGenere);
    DatabasePlaylistBrano DBPlaylistBrano;
	DBPlaylistBrano=calloc(100,sizeof(PlaylistBrano));
    caricaDBBranoPlaylist(DBPlaylistBrano);
	DatabaseUtente DBUtenti;
	DBUtenti=calloc(100,sizeof(Utente));
	caricaDBUtenti(DBUtenti);

	do{
	printf("Esegui il login perfavore\n");
	Utente UtenteCorrente=login(DBUtenti);
    if(UtenteCorrente.admin==0)
    	menuAdmin();
	else
		MenuUtenteStandard();
    	printf("Cosa vuoi fare? Inserisci il numero");
    	scelta=leggiIntero();
	if(scelta!=0){
		if(scelta==11)
			inserireBrano(DBBrano,DBBranoAlbum, DBAlbum, DBBranoGenere,DBBranoArtista,DBArtisti, DBPlaylistBrano);
		else if(scelta==12)
		    inserireAlbum(DBAlbum);
        else if(scelta==13)
        	inserisciGenere(DBGeneri);
        else if(scelta==14)
        	inserireArtista(DBArtisti);
        else if(scelta==21){
        	printf("Quale brano vuoi cancellare?\n");
        	StrAppoggio=(char*)leggiStringa();
        	idBrani=ricercaBranoTramiteTitoloBrano(StrAppoggio, DBBrano);
        	stampaListaBrani(idBrani, DBBrano);
        	printf("Scegli il brano da eliminare\n");
        	SottoScelta=leggiIntero();
        	cancellaBrano(SottoScelta, DBBrano, DBBranoArtista, DBBranoAlbum, DBBranoGenere, DBPlaylistBrano);
        	}
        else if(scelta==22){
        	printf("Quale album vuoi cancellare?\n");
        	StrAppoggio=(char*)leggiStringa();
        	idAlbum=ricercaAlbumTramiteTitoloAlbum(StrAppoggio, DBAlbum);
        	stampaListaAlbum(idAlbum,DBAlbum);
        	printf("Scegli l'album da eliminare\n");
        	SottoScelta=leggiIntero();
        	cancellaAlbum(SottoScelta, DBAlbum, DBBrano,DBBranoAlbum, DBBranoArtista, DBBranoGenere, DBPlaylistBrano);
        	}
        else if(scelta==23){
        	printf("Quale genere vuoi cancellare?\n");
        	StrAppoggio=(char*)leggiStringa();
        	idGeneri=ricercaGenereTramiteNome(DBGeneri,StrAppoggio);
        	stampaListaGeneri(idGeneri, DBGeneri);
        	printf("Scegli il genere da eliminare\n");
        	SottoScelta=leggiIntero();
        	cancellaGenere(SottoScelta,DBGeneri, DBBrano, DBBranoArtista, DBBranoAlbum, DBBranoGenere, DBPlaylistBrano);
        }
        else if(scelta==24){
        	printf("Quale artista vuoi cancellare?\n");
        	StrAppoggio=leggiStringa();
        	idArtisti=ricercaArtistaTramiteNomeArtista(StrAppoggio, DBArtisti);
        	stampaListaArtista(idArtisti, DBArtisti);
        	printf("Scegli l'artista da eliminare\n");
        	SottoScelta=leggiIntero();
        	cancellaArtista(SottoScelta, DBArtisti, DBBrano, DBBranoArtista, DBBranoAlbum, DBBranoGenere, DBPlaylistBrano);
                }
        else if(scelta==25){
        	printf("Quale playlist vuoi cancellare?\n");
        	StrAppoggio=leggiStringa();
        	idPlaylist=ricercaPlaylistTramiteNomePlaylist(StrAppoggio, DBPlaylist);
        	stampaListaPlaylist(idPlaylist, DBPlaylist);
        	printf("Scegli la playlist da eliminare\n");
        	SottoScelta=leggiIntero();
        	cancellaPlaylist(SottoScelta,DBPlaylist,DBBrano,DBBranoArtista, DBBranoAlbum, DBBranoGenere, DBPlaylistBrano);
                }
        else if(scelta==31){
        	int CampoScelto;
        	printf("Quale brano vuoi modificare?\n");
        	StrAppoggio=(char*)leggiStringa();
        	idBrani=ricercaBranoTramiteTitoloBrano(StrAppoggio,DBBrano);
        	stampaListaBrani(idBrani, DBBrano);
        	printf("Scegli il brano da modificare\n");
        	SottoScelta=leggiIntero();
        	printf("Quale campo vuoi modificare?:\n"
        			"1- Titolo\n2- Durata\n");
        	do{
        		scanf("%d", &CampoScelto);
        	}while(CampoScelto<1 || CampoScelto>2);
        	modificaBrano(SottoScelta, CampoScelto, DBBrano);
        }
        else if(scelta==32){
        	int CampoScelto;
        	printf("Quale album vuoi modificare?\n");
        	StrAppoggio=leggiStringa();
        	idAlbum=ricercaAlbumTramiteTitoloAlbum(StrAppoggio, DBAlbum);
        	stampaListaAlbum(idAlbum, DBAlbum);
        	printf("Scegli l'album da modificare\n");
        	SottoScelta=leggiIntero();
        	printf("Quale campo vuoi modificare?:\n"
        			"1- Titolo\n2- Descrizione\n");
        	do{
        		scanf("%d", &CampoScelto);
        	}while(CampoScelto<1 || CampoScelto>2);
        	modificaAlbum(SottoScelta, CampoScelto, DBAlbum);
        }
        else if(scelta==33){
        	printf("Quale genere vuoi modificare?\n");
        	StrAppoggio=(char*)leggiStringa();
        	idGeneri=(int*)ricercaGenereTramiteNome(StrAppoggio, DBGeneri);
        	stampaListaGeneri(idGeneri,DBGeneri);
        	printf("Scegli il genere da modificare\n");
        	SottoScelta=leggiIntero();
        	modificaGenere(SottoScelta, DBAlbum);
        }
        else if(scelta==34){
        	int CampoScelto;
        	printf("Quale artista vuoi modificare?\n");
        	StrAppoggio=(char*)leggiStringa();
        	idArtisti=ricercaArtistaTramiteNomeArtista(StrAppoggio, DBArtisti);
        	stampaListaArtista(idArtisti, DBArtisti);
        	printf("Scegli l'artista da modificare\n");
        	SottoScelta=leggiIntero();
        	printf("Quale campo vuoi modificare?:\n"
        			"1- Nome\n2- Cognome\n3- Nome d'arte\n4-Link biografia");
        	do{
        		scanf("%d", &CampoScelto);
        	}while(CampoScelto<1 || CampoScelto>4);
        	modificaArtista(SottoScelta, CampoScelto, DBAlbum);
        }
        else if(scelta==35){
        	int CampoScelto;
        	printf("Quale playlist vuoi modificare?\n");
        	StrAppoggio=leggiStringa();
        	idPlaylist=ricercaPlaylistTramiteNomePlaylist(StrAppoggio, DBPlaylist);
        	stampaListaPlaylist(idPlaylist, DBPlaylist);
        	printf("Scegli la playlist da modificare\n");
        	SottoScelta=leggiIntero();
        	printf("Quale campo vuoi modificare?:\n"
        			"1- Titolo\n2- Descrizione");
        	do{
        		scanf("%d", &CampoScelto);
        	}while(CampoScelto<1 || CampoScelto>2);
        	modificaPlaylist(SottoScelta, CampoScelto, DBPlaylist);
        }
        else if(scelta==41){
        	ricercaGenerale();
        	printf("Qual è il brano che cerchi?");
        	SottoScelta=leggiIntero();
        	stampaBrano(DBBrano[SottoScelta]);
                        }
        else if(scelta==51){
        	backupDatabase();
                                }
        else if(scelta==61){
        	ripristinoDatabase();
        }
        else if(scelta==1){
        	ricercaGenerale();
        	printf("Qual è il brano che cerchi?");
        	SottoScelta=leggiIntero();
        	stampaBrano(DBBrano[SottoScelta]);
                        }

        else if(scelta==2){
        		creaPlaylist(DBPlaylist, UtenteCorrente);
                          }
	}
	salvareSuFile(DBBrano, DBAlbum, DBArtisti, DBGeneri, DBPlaylist, DBBranoAlbum, DBBranoArtista, DBBranoGenere, DBPlaylistBrano);
	printf("Vuoi effettuare un'altra operazione?");
	scanf("%c", &risp);
}while(risp=='y'||risp=='Y');
    system("pause");
	return EXIT_SUCCESS;
}
