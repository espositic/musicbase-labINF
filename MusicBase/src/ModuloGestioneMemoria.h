#ifndef MODULOGESTIONEMEMORIA_H_
#define MODULOGESTIONEMEMORIA_H_

#include "Dichiarazioni.h"

void stampaBrano(Brano BranoDaStampare);
void caricaDBUtenti(DatabaseUtente DBUtenti);
void caricaDBBrano(DatabaseBrano DBBrani);
void caricaDBAlbum(DatabaseAlbum DBAlbum);
void caricaDBArtisti(DatabaseArtista DBArtisti);
void caricaDBGeneri(DatabaseGenere DBGeneri);
void caricaDBPlaylist(DatabasePlaylist DBPlaylist);
void caricaDBBranoArtista(DatabaseBranoArtista DBBranoArtista);
void caricaDBBranoAlbum(DatabaseBranoAlbum DBBranoAlbum);
void caricaDBBranoGenere(DatabaseBranoGenere DBBranoGenere);
void caricaDBBranoPlaylist(DatabasePlaylistBrano DBBranoPlaylist);
void backUpDatabase();
void ripristinoDatabase();
Utente login(Utente* DBUtenti);
void ripristinoDatabase();
void salvareSuFile(Brano* DBBrani, Album* DBAlbum, Artista* DBArtisti, Genere* DBGeneri, Playlist* DBPlaylist, BranoAlbum* DBBranoAlbum, BranoArtista* DBBranoArtista, BranoGenere* DBBranoGenere, PlaylistBrano* DBBranoPlaylist);
void stampaUtente(Utente U);

#endif /* MODULOGESTIONEMEMORIA_H_ */
