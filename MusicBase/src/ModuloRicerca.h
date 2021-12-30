#ifndef MODULORICERCA_H_
#define MODULORICERCA_H_
#include"Dichiarazioni.h"

int* ricercaBranoTramiteTitoloBrano(char* titoloBrano, DatabaseBrano DBBrano);
int* ricercaPlaylistTramiteNomePlaylist(char* nomePlaylist, DatabasePlaylist DBPlaylist);
int* ricercaUtenteTramiteNomeUtente(char* nomeUtente, DatabaseUtente DBUtente);
int* ricercaArtistaTramiteNomeArtista(char* nomeArtista, DatabaseArtista DBArtista);
int* ricercaAlbumTramiteTitoloAlbum(char* titoloAlbum, DatabaseAlbum DBAlbum);
int* ricercaAlbumTramiteAnnoAlbum(int annoAlbum, DatabaseAlbum DBAlbum);
int* ricercaGenereTramiteNome(char* nome, DatabaseGenere DBGenere);
int cercaAlbum(DatabaseAlbum DBAlbum, char* nomeAlbum);
int cercaArtista(DatabaseArtista DBArtista,char* nomeArtista);
int cercaGenere(DatabaseGenere DBGenere, char* nomeGenere);

#endif /* MODULORICERCA_H_ */
