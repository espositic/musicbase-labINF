#ifndef MODULOOUTPUT_H_
#define MODULOOUTPUT_H_
#include"Dichiarazioni.h"

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
void stampaListaGeneri(int*risultato, DatabaseGenere DBGenere);

#endif /* MODULOOUTPUT_H_ */
