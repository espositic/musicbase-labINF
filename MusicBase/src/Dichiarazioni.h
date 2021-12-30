#ifndef DICHIARAZIONI_H_
#define DICHIARAZIONI_H_

#define ANNOMIN 1970
#define ANNOATTUALE 2020
#define IDSENTINELLA -1
#define	IDCANCELLATO -2

typedef struct Album{
	int idAlbum;
	char* titolo;
	int anno;
}Album;

typedef struct
{
	int idUtente;
	char* nomeUtente;
	char* password;
	int admin;
}Utente;

typedef struct
{
	int idBrano;
	char* titolo;
	int durata;
	int ascolti;
	int anno;
}Brano;


typedef struct
{
	int idArtista;
	char* nome;
	char* cognome;
	char* nomeArte;
	char* linkBio;
}Artista;


typedef struct
{
	int idGenere;
	char* nome;
}Genere;

typedef struct
{
	int idBrano;
	int idAlbum;
}BranoAlbum;

typedef struct
{
	int idBrano;
	int idGenere;
}BranoGenere;

typedef	struct
{
	int idPlaylist;
	int idBrani;
}PlaylistBrano;

typedef struct
{
	int idPlaylist;
	int idUtente;
	char* nome;
	char* descrizione;
	int pubblica;
}Playlist;

typedef struct
{
	int idBrano;
	int idArtista;
}BranoArtista;

typedef Brano* DatabaseBrano;
typedef Utente* DatabaseUtente;
typedef Genere* DatabaseGenere;
typedef Album* DatabaseAlbum;
typedef Artista* DatabaseArtista;
typedef BranoAlbum* DatabaseBranoAlbum;
typedef BranoGenere* DatabaseBranoGenere;
typedef BranoArtista* DatabaseBranoArtista;
typedef BranoGenere* DatabaseBranoGenere;
typedef Playlist* DatabasePlaylist;
typedef PlaylistBrano* DatabasePlaylistBrano;


#endif /* DICHIARAZIONI_H_ */
