#ifndef MODULOGESTIONEDATABASE_H_
#define MODULOGESTIONEDATABASE_H_

void inserireBrano(DatabaseBrano DBBrano, DatabaseBranoAlbum DBBranoAlbum, DatabaseAlbum DBAlbum, DatabaseBranoGenere DBBranoGenere, DatabaseBranoArtista DBBranoArtista, DatabaseArtista DBArtista, DatabasePlaylistBrano DBPlaylistBrano);
void inserireAlbum(DatabaseAlbum DBAlbum);
void inserireArtista(DatabaseArtista DBArtista);
void inserisciGenere(DatabaseGenere DBGenere);
void inserisciUtente(DatabaseUtente DBUtente);
void inserisciPlaylist(int idUtente, DatabasePlaylist DBPlaylist, DatabaseBrano DBBrano, Playlist nuovaPlaylist, DatabaseUtente DBUtente);
void modificaBrano(DatabaseBrano DBBrano, int campo, int idBrano);
void modificaAlbum(int campo, int idAlbum, DatabaseAlbum DBAlbum);
void modificaArtista(DatabaseArtista DBArtista, int campo, int idArtista);
void modificaGenere(int idGenere, DatabaseGenere DBGenere);
void modificaPlaylist(DatabasePlaylist DBPlaylist, int campo, int idPlaylist);
void modificaUtente(int campo, int idUtente, DatabaseUtente DBUtente);
void cancellaBrano(int idBrano, DatabaseBrano DBBrano, DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist);
void cancellaArtista(int idArtista, DatabaseArtista DBArtisti, DatabaseBrano DBBrano,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist);
void cancellaAlbum(int idAlbum, DatabaseAlbum DBAlbum, DatabaseBrano DBBrano,DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoAlbum DBBranoArtista, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist);
void cancellaGenere(int idGenere, DatabaseGenere DBGenere, DatabaseBrano DBBrani,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum,DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist);
void cancellaPlaylist(int idPlaylist, DatabasePlaylist DBPlaylist,DatabaseBrano DBBrani,DatabaseBranoArtista DBBranoArtista, DatabaseBranoAlbum DBBranoAlbum,DatabaseBranoGenere DBBranoGenere,DatabasePlaylistBrano DBBranoPlaylist);



#endif /* MODULOGESTIONEDATABASE_H_ */
