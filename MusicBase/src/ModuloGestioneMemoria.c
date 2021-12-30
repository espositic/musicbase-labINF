#include<stdio.h>
#include<stdlib.h>
#include"Dichiarazioni.h"
#include<string.h>
int contaElementiFile(int TipoElementoInBit, FILE* FileDiInput);

void StampaUtente(Utente U){
	printf("\n");
	printf("nome: %s\n", U.nomeUtente);
	printf("password: %s\n", U.password);
	printf("id: %d\n", U.idUtente);
	if(U.admin==0)printf("admin\n");
	else printf("standard\n");
return;
}
void caricaDBUtenti(DatabaseUtente DBUtenti){
	FILE* f=fopen("Utenti.db","rb");
	if(!f){
		fclose(f);
		f=fopen("Utenti.db", "wb");
		Utente Utenti[3];
		strcpy(Utenti[0].nomeUtente, "admin\0");
		strcpy(Utenti[0].password, "admin\0");
		Utenti[0].admin=0;
		Utenti[0].idUtente=0;
		fwrite(Utenti, sizeof(Utente), 1, f);
		Utenti[0].idUtente=-1;
		fseek(f, sizeof(Utente), SEEK_SET);
		fwrite(Utenti, sizeof(Utente), 1, f);
		fclose(f);
		fopen("Utenti.db","rb");}
		int dim=contaElementiFile(sizeof(Utente), f);
		realloc(DBUtenti, sizeof(Utente)*dim);
		fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
		fread(DBUtenti, sizeof(Utente), dim, f);
		fclose(f);
		StampaUtente(DBUtenti[0]);
}
void caricaDBBrano(DatabaseBrano DBBrano){
	int dim;
	FILE* f=fopen("Brani.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("Brani.db", "wb"); //Lo riapro in scrittura, creandolo
		Brano sent;sent.idBrano=-1;//creo la sentinella
		fwrite(&sent, sizeof(Brano), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("Brani.db", "rb");
	}
	dim=contaElementiFile(sizeof(Brano), f); //conto quanti elementi ha
	realloc(DBBrano,sizeof(Brano)*dim);
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBBrano, sizeof(Brano), dim, f); 	//Salvo il contenuto in un array in memoria
	fclose(f);
}
void caricaDBAlbum(DatabaseAlbum DBAlbum){
	int dim;
	FILE* f=fopen("Album.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("Album.db", "wb"); //Lo riapro in scrittura, creandolo
		Album sent;sent.idAlbum=-1;
		fwrite(&sent, sizeof(Album), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("Brani.db", "rb");
	}
	dim=contaElementiFile(sizeof(Album), f); //conto quanti elementi ha
	realloc(DBAlbum,sizeof(Album)*dim); 	//Salvo il contenuto in un array in memoria
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBAlbum, sizeof(Album), dim, f);
	fclose(f);
}
void caricaDBArtisti(DatabaseArtista DBArtisti){
	int dim;
	FILE* f=fopen("Artisti.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("Artisti.db", "wb"); //Lo riapro in scrittura, creandolo
		Artista sent;sent.idArtista=-1;
		fwrite(&sent, sizeof(Artista), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("Artisti.db", "rb");
	}
	dim=contaElementiFile(sizeof(Artista), f); //conto quanti elementi ha
	realloc(DBArtisti,sizeof(Artista)*dim); 	//Salvo il contenuto in un array in memoria
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBArtisti, sizeof(Artista), dim, f);
	fclose(f);
}
void caricaDBGeneri(DatabaseGenere DBGeneri){
	int dim;
	FILE* f=fopen("Generi.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("Generi.db", "wb"); //Lo riapro in scrittura, creandolo
		Genere sent;sent.idGenere=-1;
		fwrite(&sent, sizeof(Genere), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("Generi.db", "rb");
	}
	dim=contaElementiFile(sizeof(Genere), f); //conto quanti elementi ha
	realloc(DBGeneri,sizeof(Genere)*dim); 	//Salvo il contenuto in un array in memoria
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBGeneri, sizeof(Genere), dim, f);
	fclose(f);
}
void caricaDBPlaylist(DatabasePlaylist DBPlaylist){
	int dim;
	FILE* f=fopen("Generi.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("Playlist.db", "wb"); //Lo riapro in scrittura, creandolo
		Playlist sent;sent.idPlaylist=-1;
		fwrite(&sent, sizeof(Playlist), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("Playlist.db", "rb");
	}
	dim=contaElementiFile(sizeof(Playlist), f); //conto quanti elementi ha
	realloc(DBPlaylist,sizeof(Playlist)*dim); 	//Salvo il contenuto in un array in memoria
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBPlaylist, sizeof(Playlist), dim, f);
	fclose(f);
}
void caricaDBBranoAlbum(DatabaseBranoAlbum DBBranoAlbum){
	int dim;
	FILE* f=fopen("BranoAlbum.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("BranoAlbum.db", "wb"); //Lo riapro in scrittura, creandolo
		BranoAlbum sent;sent.idAlbum=-1;sent.idBrano=-1;
		fwrite(&sent, sizeof(BranoAlbum), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("BranoAlbum.db", "rb");
	}
	dim=contaElementiFile(sizeof(BranoAlbum), f); //conto quanti elementi ha
	realloc(DBBranoAlbum,sizeof(BranoAlbum)*dim); 	//Salvo il contenuto in un array in memoria
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBBranoAlbum, sizeof(BranoAlbum), dim, f);
	fclose(f);
}
void caricaDBBranoArtista(DatabaseBranoArtista DBBranoArtista){
	int dim;
	FILE* f=fopen("BranoArtista.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("BranoArtista.db", "wb"); //Lo riapro in scrittura, creandolo
		BranoArtista sent;sent.idArtista=-1;sent.idBrano=-1;
		fwrite(&sent, sizeof(BranoArtista), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("BranoArtista.db", "rb");
	}
	dim=contaElementiFile(sizeof(BranoArtista), f); //conto quanti elementi ha
	realloc(DBBranoArtista,sizeof(BranoArtista)*dim); 	//Salvo il contenuto in un array in memoria
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBBranoArtista, sizeof(BranoArtista), dim, f);
	fclose(f);
}
void caricaDBBranoGenere(DatabaseBranoGenere DBBranoGenere){
	int dim;
	FILE* f=fopen("BranoGenere.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("BranoGenere.db", "wb"); //Lo riapro in scrittura, creandolo
		BranoGenere sent;sent.idBrano=-1;sent.idGenere=-1;
		fwrite(&sent, sizeof(BranoGenere), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("BranoGenere.db", "rb");
	}
	dim=contaElementiFile(sizeof(BranoGenere), f); //conto quanti elementi ha
	realloc(DBBranoGenere,sizeof(BranoGenere)*dim); 	//Salvo il contenuto in un array in memoria
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBBranoGenere, sizeof(BranoGenere), dim, f);
	fclose(f);
}
void caricaDBBranoPlaylist(DatabasePlaylistBrano DBBranoPlaylist){
	int dim;
	FILE* f=fopen("BranoPlaylist.db", "rb"); //apro il file
	if(!f) //Se non esiste:
	{
		fclose(f); 	//lo chiudo
		f=fopen("BranoPlaylist.db", "wb"); //Lo riapro in scrittura, creandolo
		PlaylistBrano sent;sent.idPlaylist=-1;
		fwrite(&sent, sizeof(PlaylistBrano), 1, f); //e ci metto almeno la sentinella
		fclose(f); //lo chiudo e lo riapro in lettura
		fopen("BranoPlaylist.db", "rb");
	}
	dim=contaElementiFile(sizeof(PlaylistBrano), f); //conto quanti elementi ha
	realloc(DBBranoPlaylist,sizeof(PlaylistBrano)*dim); 	//Salvo il contenuto in un array in memoria
	fseek(f, 0, SEEK_SET);//Mi posiziono all'inizio
	fread(&DBBranoPlaylist, sizeof(PlaylistBrano), dim, f);
	fclose(f);
}
int contaElementiFile(int tipo, FILE* f){
	int contatore;
	fseek(f, 0, SEEK_END);//Mi posiziono alla fine
	contatore = ftell(f);//Leggo in che posizione mi trovo dl file
	//Se dividendo per la dimensione del tipo scelto non viene 0 vuol dire che c'è stato qualche errore
	if(contatore%tipo!=0)
		contatore=-1;
	else	//altrimenti conto quanti sono gli elementi
		contatore=contatore/tipo;
	return contatore;
}

void salvareSuFile(DatabaseBrano DBBrani, DatabaseAlbum DBAlbum, DatabaseArtista DBArtisti, DatabaseGenere DBGeneri, DatabasePlaylist DBPlaylist, DatabaseBranoAlbum DBBranoAlbum, DatabaseBranoArtista DBBranoArtista, DatabaseBranoGenere DBBranoGenere, DatabasePlaylistBrano DBBranoPlaylist){
FILE* f=fopen("Brani.db","wb");
int i=0;
while(DBBrani[i].idBrano!=-1){
	i++;
}
fwrite(&DBBrani, sizeof(Brano), i, f);
fclose(f);
f=fopen("Album.db","wb");
i=0;
while(DBAlbum[i].idAlbum!=-1){
	i++;
}
fwrite(&f, sizeof(Album), i, f);
fclose(f);
f=fopen("Artisti.db","wb");
i=0;
while(DBArtisti[i].idArtista!=-1){
	i++;
}
fwrite(&f, sizeof(Artista), i, f);
fclose(f);
f=fopen("Generi.db","wb");
i=0;
while(DBGeneri[i].idGenere!=-1){
	i++;
}
fwrite(&f, sizeof(Genere), i, f);
fclose(f);
f=fopen("Playlist.db","wb");
i=0;
while(DBPlaylist[i].idPlaylist!=-1){
	i++;
}
fwrite(&f, sizeof(Playlist), i, f);
fclose(f);
f=fopen("BranoArtista.db","wb");
i=0;
while(DBBranoArtista[i].idBrano!=-1){
	i++;
}
fwrite(&f, sizeof(BranoArtista), i, f);
fclose(f);
f=fopen("BranoAlbum.db","wb");
i=0;
while(DBBranoAlbum[i].idBrano!=-1){
	i++;
}
fwrite(&f, sizeof(BranoAlbum), i, f);
fclose(f);
f=fopen("BranoGenere.db","wb");
i=0;
while(DBBranoGenere[i].idBrano!=-1){
	i++;
}
fwrite(&f, sizeof(BranoGenere), i, f);
fclose(f);
f=fopen("BranoPlaylist.db","wb");
i=0;
while(DBBranoPlaylist[i].idPlaylist!=-1){
	i++;
}
fwrite(&f, sizeof(PlaylistBrano), i, f);
fclose(f);
return;
}

void backupDatabase(){
FILE* FileA;
FILE* FileB;
int NumElementi;

FileA=fopen("Brani.db", "rb");	//Backup brani
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''Brani.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("BraniBackup.db","wb");
	NumElementi=contaElementiFile(sizeof(Brano), FileB);
	Brano BranoAppoggio[NumElementi];
	fread(&BranoAppoggio, sizeof(Brano), NumElementi, FileA);
	fwrite(&BranoAppoggio, sizeof(Brano), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}

FileA=fopen("Album.db", "rb");	//Backup album
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''Album.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("AlbumBackup.db","wb");
	NumElementi=contaElementiFile(sizeof(Album), FileB);
	Album AlbumAppoggio[NumElementi];
	fread(&AlbumAppoggio, sizeof(Album), NumElementi, FileA);
	fwrite(&AlbumAppoggio, sizeof(Album), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}

FileA=fopen("Artisti.db", "rb");	//Backup artisti
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''Artisti.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("ArtistaBackup.db","wb");
	NumElementi=contaElementiFile(sizeof(Artista), FileB);
	Artista ArtistaAppoggio[NumElementi];
	fread(&ArtistaAppoggio, sizeof(Artista), NumElementi, FileA);
	fwrite(&ArtistaAppoggio, sizeof(Artista), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}

FileA=fopen("Generi.db", "rb");	//Backup generi
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''Genere.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("GenereBackup.db","wb");
	int NumElementi=contaElementiFile(sizeof(Genere), FileB);
	Genere GenereAppoggio[NumElementi];
	fread(&GenereAppoggio, sizeof(Genere), NumElementi, FileA);
	fwrite(&GenereAppoggio, sizeof(Genere), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}

FileA=fopen("Playlist.db", "rb");	//Backup playlist
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''Playlist.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("PlaylistBackup.db","wb");
	int NumElementi=contaElementiFile(sizeof(Playlist), FileB);
	Playlist PlaylistAppoggio[NumElementi];
	fread(&PlaylistAppoggio, sizeof(Playlist), NumElementi, FileA);
	fwrite(&PlaylistAppoggio, sizeof(Playlist), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}

FileA=fopen("BranoArtista.db", "rb");	//Backup BranoArtista
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''BranoArtista.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("BranoArtistaBackup.db","wb");
	int NumElementi=contaElementiFile(sizeof(BranoArtista), FileB);
	BranoArtista BranoArtistaAppoggio[NumElementi];
	fread(&BranoArtistaAppoggio, sizeof(BranoArtista), NumElementi, FileA);
	fwrite(&BranoArtistaAppoggio, sizeof(BranoArtista), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}

FileA=fopen("BranoAlbum.db", "rb");	//Backup BranoAlbum
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''BranoArtista.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("BranoAlbumBackup.db","wb");
	int NumElementi=contaElementiFile(sizeof(BranoAlbum), FileB);
	BranoAlbum BranoAlbumAppoggio[NumElementi];
	fread(&BranoAlbumAppoggio, sizeof(BranoAlbum), NumElementi, FileA);
	fwrite(&BranoAlbumAppoggio, sizeof(BranoAlbum), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}

FileA=fopen("BranoGenere.db", "rb");	//Backup BranoGenere
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''BranoGenere.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("BranoGenereBackup.db","wb");
	int NumElementi=contaElementiFile(sizeof(BranoGenere), FileB);
	BranoGenere BranoGenereAppoggio[NumElementi];
	fread(&BranoGenereAppoggio, sizeof(BranoGenere), NumElementi, FileA);
	fwrite(&BranoGenereAppoggio, sizeof(BranoGenere), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}

FileA=fopen("BranoPlaylist.db", "rb");	//Backup BranoPlaylist
if(!FileA){	//Non dovrebbe mai verificarsi questa condizione
	printf("Errore, file ''BranoPlaylist.db'' non trovato");
	fclose(FileA);}
else{
	FileB=fopen("BranoPlaylistBackup.db","wb");
	int NumElementi=contaElementiFile(sizeof(PlaylistBrano), FileB);
	PlaylistBrano BranoPlaylistAppoggio[NumElementi];
	fread(&BranoPlaylistAppoggio, sizeof(PlaylistBrano), NumElementi, FileA);
	fwrite(&BranoPlaylistAppoggio, sizeof(PlaylistBrano), NumElementi, FileB);
	fclose(FileA);
	fclose(FileB);
	}
	return;
}

void ripristinoDatabase(){
 //Ripristino database brani
 FILE* from=fopen("BraniBackup.db","rb");
 FILE* to=fopen("Brani.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 Brano brano;
 do{
 fread(&brano, sizeof(Brano), 1, from);
 fwrite(&brano, sizeof(Brano), 1, to);
 }while(brano.idBrano!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database album
 from=fopen("AlbumBackup.db","rb");
 to=fopen("Album.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 Album album;
 do{
 fread(&album, sizeof(Album), 1, from);
 fwrite(&album, sizeof(Album), 1, to);
 }while(album.idAlbum!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database generi
 from=fopen("GenereBackuo.db","rb");
 to=fopen("Genere.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 Genere genere;
 do{
 fread(&genere, sizeof(Genere), 1, from);
 fwrite(&genere, sizeof(Genere), 1, to);
 }while(genere.idGenere!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database artisti
 from=fopen("ArtistaBackup.db","rb");
 to=fopen("Artista.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 Artista artista;
 do{
 fread(&artista, sizeof(Artista), 1, from);
 fwrite(&artista, sizeof(Artista), 1, to);
 }while(artista.idArtista!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database utenti
 from=fopen("UtentiBackup.db","rb");
 to=fopen("Utenti.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 Utente utenti;
 do{
 fread(&utenti, sizeof(Utente), 1, from);
 fwrite(&utenti, sizeof(Utente), 1, to);
 }while(utenti.idUtente!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database playlist
 from=fopen("PlaylistBackup.db","rb");
 to=fopen("playlist.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 Playlist playlist;
 do{
 fread(&playlist, sizeof(Playlist), 1, from);
 fwrite(&playlist, sizeof(Playlist), 1, to);
 }while(playlist.idPlaylist!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database BranoAlbum
 from=fopen("BranoAlbumBackup.db","rb");
 to=fopen("BranoAlbum.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 BranoAlbum branoAlbum;
 do{
 fread(&branoAlbum, sizeof(BranoAlbum), 1, from);
 fwrite(&branoAlbum, sizeof(BranoAlbum), 1, to);
 }while(branoAlbum.idAlbum!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database BranoArtista
 from=fopen("BranoArtistaBackup.db","rb");
 to=fopen("BranoArtista.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 BranoArtista branoArtista;
 do{
 fread(&branoArtista, sizeof(BranoArtista), 1, from);
 fwrite(&branoArtista, sizeof(BranoArtista), 1, to);
 }while(branoArtista.idArtista!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database BranoGenere
 from=fopen("BranoGenereBackup.db","rb");
 to=fopen("BranoGenere.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 BranoGenere branoGenere;
 do{
 fread(&branoGenere, sizeof(BranoGenere), 1, from);
 fwrite(&branoGenere, sizeof(BranoGenere), 1, to);
 }while(branoGenere.idGenere!=IDSENTINELLA);
 fclose(from);
 fclose(to);

 //Ripristino database BranoPlaylist
 from=fopen("BranoPlaylistBackup.db","rb");
 to=fopen("BranoPlaylist.db","wb");
 fseek(from, 0, SEEK_SET);
 fseek(to, 0, SEEK_SET);
 PlaylistBrano playlistBrano;
 do{
 fread(&playlistBrano, sizeof(PlaylistBrano), 1, from);
 fwrite(&playlistBrano, sizeof(PlaylistBrano), 1, to);
 }while(playlistBrano.idPlaylist!=IDSENTINELLA);
 fclose(from);
 fclose(to);
}
