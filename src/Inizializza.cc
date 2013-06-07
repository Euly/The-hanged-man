#include <cstdlib>
#include <ctime>
#include <string>
#include "Struttura_dati.h"
#include "Inizializza.h"

/**
 * @file
 * 
 * Questo file contiene tutte le funzioni relative all'inizializzazione delle
 * strutture e variabili utilizzate.
 * Inoltre qui è contenuta la funzione ::parola, la quale sceglie in modo 
 * oppurtuno quale parola assegnare al giocatore di turno.
 * */

bool turno ;
informazioni gioc[2], p ;
argomenti ar ;

void inizializzo_punteggio()
{
	for(int i = 0 ; i < 2 ; i++) {
		gioc[i].Tentativi = 0 ;
		
		TRACE2(cout<<"NewGame == "<<NewGame<<endl) ;
		if(NewGame){
			gioc[i].Punti = 0 ;	// I punti sono inversamente proporzionali agli errori
			gioc[i].Hits = 3 ;
		}
	}
}

void inizializzo_argomenti()
{
	/* Arte: artisti italiani */
	int i = 0 ;
	ar.mat[i][0] = "tintoretto" ;		// Jacopo Robusti: pittore
	ar.mat[i][1] = "veronese" ;			// Paolo Caliari: pittore
	ar.mat[i][2] = "michelangelo" ;	// Michelangelo Buonarroti: scultore, pittore
	ar.mat[i][3] = "caravaggio" ;		// Michelangelo Merisi: pittore
	ar.mat[i][4] = "canova" ;				// Antonio Canova: scultore
	ar.mat[i][5] = "leonardo" ;			// Leonardo Da Vinci: inventore, tuttofare
	ar.mat[i][6] = "carracci" ;			// Annibale Carracci: pittore
	ar.mat[i][7] = "donatello" ;		// Donato di Niccolò di Betto Bardi: scultore
	ar.mat[i][8] = "modigliani" ;		// Amedeo Clemente Modigliani: pittore, scultore
	ar.mat[i][9] = "pomodoro" ;			// Arnaldo Pomodoro: scultore (contemporaneo)
	
	/* Letteratura: autori italiani e non */
	i++ ;
	ar.mat[i][0] = "pirandello" ;		// Luigi Pirandello, Italia
	ar.mat[i][1] = "alfieri" ;			// Vittorio Alfieri, Italia
	ar.mat[i][2] = "alighieri" ;		// Durante (Dante) Alighieri, Italia
	ar.mat[i][3] = "petrarca" ;			// Francesco Petrarca, Italia
	ar.mat[i][4] = "boccaccio" ;		// Giovanni Boccaccio, Italia
	ar.mat[i][5] = "svevo" ;				// Italo Svevo, Italia
	ar.mat[i][6] = "baudelaire" ;		// Charles Baudelaire, Francia
	ar.mat[i][7] = "joyce" ;				// James Joyce, Irlanda
	ar.mat[i][8] = "fitzgerald" ;		// Francis Scott Fitzgerald, USA
	ar.mat[i][9] = "goethe" ;				// Johann Wolfgang von Goethe, Germania
	
	/* Cinema: attori e registi */
	i++ ;
	ar.mat[i][0] = "kidman" ;				// Nicole Kidman: attrice
	ar.mat[i][1] = "knightley" ;		// Keira Knightley: attrice
	ar.mat[i][2] = "connery" ;			// Sean Connery: attore
	ar.mat[i][3] = "kubrick" ;			// Stanley Kubrick: regista
	ar.mat[i][4] = "nickolson" ;		// Jack Nickloson: attore
	ar.mat[i][5] = "wright" ;				// Joe Wright: regista
	ar.mat[i][6] = "radcliffe" ;		// Daniel Radcliffe: attore
	ar.mat[i][7] = "spielberg" ;		// Steven Spielberg: regista
	ar.mat[i][8] = "almodovar" ;		// Pedro Almodovar Caballero: regista
	ar.mat[i][9] = "sutherland" ;		// Donald McNicol Sutherland : attore
	
	/* Sport: tennis, calcio, pattinaggio, nuoto */
	i++ ;
	ar.mat[i][0] = "federer" ;			// Roger Federer: tennista
	ar.mat[i][1] = "nadal" ;				// Rafael Nadal: tennista
	ar.mat[i][2] = "roddick" ;			// Andy Roddick: tennista
	ar.mat[i][3] = "ibrahimovic" ;	// Zlatan Ibrahimovic: calciatore
	ar.mat[i][4] = "boateng" ;			// Kevin-Prince Boateng: calciatore
	ar.mat[i][5] = "milito" ;				// Diego Alberto Milito: calciatore
	ar.mat[i][6] = "kostner" ;			// Carolina Kostner: pattinatrice
	ar.mat[i][7] = "phelps" ;				// Michael Phelps: nuotatore
	ar.mat[i][8] = "pellegrini" ;		// Federica Pellegrini: nuotatrice
	ar.mat[i][9] = "cagnotto" ;			// Tania Cagnotto: tuffatrice
	
	/* Geografia: capitali del mondo */
	i++ ;
	ar.mat[i][0] = "mogadiscio" ;		// Capitale della Somalia
	ar.mat[i][1] = "montevideo" ;		// Capitale dell'Uruguay
	ar.mat[i][2] = "wellington" ;		// Capitale della Nuova Zelanda
	ar.mat[i][3] = "canberra" ;			// Capitale dell'Australia
	ar.mat[i][4] = "ottawa" ;				// Capitale del Canada
	ar.mat[i][5] = "santiago" ;			// Capitale del Cile
	ar.mat[i][6] = "tegucigalpa" ;	// Capitale delle Honduras
	ar.mat[i][7] = "reykjavik" ;		// Capitale dell'Islanda
	ar.mat[i][8] = "vilnius" ;			// Capitale della Lituania
	ar.mat[i][9] = "windhoek" ;			// Capitale della Namibia
	
	/* Scienze: Fisica, Chimica, Scienze Naturali */
	i++ ;
	ar.mat[i][0] = "mesosfera" ;		// Parte dell'atmosfera oltre l'ozono
	ar.mat[i][1] = "mantello" ;			// Strato tra la litosfera e il nucleo
	ar.mat[i][2] = "tundra" ;				// Bioma delle regioni subpolari
	ar.mat[i][3] = "alogenuri" ;		// Minerali che acquistano elettroni
	ar.mat[i][4] = "angiosperme" ;	// Tipologia di fiori
	ar.mat[i][5] = "gasteropodi" ;	// Classe di molluschi
	ar.mat[i][6] = "protista" ;			// Regno degli unicellulari
	ar.mat[i][7] = "neutrino" ;			// Particella elementare priva di carica
	ar.mat[i][8] = "kelvin" ;				// Unità di misura della temperatura (S.I)
	ar.mat[i][9] = "stechiometria" ; // Branca della chimica
	
	/* Informatica: lessico generico */
	i++ ;
	ar.mat[i][0] = "tethering" ;		// Dispositivo come gateway per internet
	ar.mat[i][1] = "backup" ;				// Copia di sicurezza
	ar.mat[i][2] = "crackeraggio" ;	// Intrusione, violazione
	ar.mat[i][3] = "feedback" ;			// Riscontro, retroazione
	ar.mat[i][4] = "motherboard" ;	// Scheda Madre dei calcolatori
	ar.mat[i][5] = "multitasking" ;	// Più processi in esecuzione
	ar.mat[i][6] = "outsourcing" ;	// Esternalizzazione
	ar.mat[i][7] = "pipeline" ;			// Concatenazione azioni
	ar.mat[i][8] = "shareware" ;		// Programma in prova gratuita
	ar.mat[i][9] = "wildcard" ;			// Metacarattere
}

int indice(int mod)
{
	int i = 0 ;
	
	srand(time(0)) ;		// La generazione del seme è sempre diversa perché 
	i = rand() % mod ;		// Ritorna un indice compreso tra 0 e mod-1
	
	return i ;
}

void parola()
{
	if(Multiplayer) {
		GtkEntry *parola = GTK_ENTRY(gtk_builder_get_object(builder, "word_entry")) ;
		GtkEntryBuffer *buffer = 
						GTK_ENTRY_BUFFER(gtk_builder_get_object(builder, "entrybuffer3")) ;
		buffer = gtk_entry_get_buffer(parola) ;
	
		const char * word = gtk_entry_buffer_get_text(buffer) ;
		gioc[turno].LUN_PAR = strlen(word) ;
		gioc[turno].Parola = new char[gioc[turno].LUN_PAR] ;
		
		strcpy(gioc[turno].Parola, word) ;
		TRACE1(cout<<"Parola prima: "<<gioc[turno].Parola<<endl) ;
		
		/* Posso ripulire il buffer passando alla GtkEntry una stringa vuota. */
		gtk_entry_set_text(parola, "") ;
		
		/* Trasformo la parola inserita dall'avversario in caratteri minuscoli per
		 * la correttezza dell'algoritmo di ricerca lettere definito in 
		 * confronta_parola() nel file "Stampa.cc". */
		char c ;
		for(int i = 0 ; i < gioc[turno].LUN_PAR ; i++){
			c = gioc[turno].Parola[i] ;
			c = tolower(c) ;
			gioc[turno].Parola[i] = c ;
		}
		TRACE1(cout<<"Parola dopo: "<<gioc[turno].Parola<<endl) ;
	}
	else{
		inizializzo_argomenti() ;
		int i = indice(NUM_ARG) ; // Tra gli argomenti non si conteggia "Tutti"
		int bottone = 0 ;
		GtkToggleButton *radio_but ;
		
		switch(bottone){
			case (0): 
								radio_but = GTK_TOGGLE_BUTTON(gtk_builder_get_object
														(builder, "arte")) ;
								if(gtk_toggle_button_get_active(radio_but)){
									i = 0 ;
									break ;
								}
			case (1):
								radio_but =	GTK_TOGGLE_BUTTON(gtk_builder_get_object
														(builder, "letteratura")) ;
								if(gtk_toggle_button_get_active(radio_but)){
									i = 1 ;
									break ;
								}
			case (2):
								radio_but = GTK_TOGGLE_BUTTON(gtk_builder_get_object
														(builder, "cinema")) ;
								if(gtk_toggle_button_get_active(radio_but)){
									i = 2 ;
									break ;
								}
			case (3):
								radio_but = GTK_TOGGLE_BUTTON(gtk_builder_get_object
														(builder, "sport")) ;
								if(gtk_toggle_button_get_active(radio_but)){
									i = 3 ;
									break ;
								}					
			case (4):
								radio_but = GTK_TOGGLE_BUTTON(gtk_builder_get_object
														(builder, "geografia")) ;
								if(gtk_toggle_button_get_active(radio_but)){
									i = 4 ;
									break ;
								}		
			case (5):
								radio_but = GTK_TOGGLE_BUTTON(gtk_builder_get_object
														(builder, "scienze")) ;
								if(gtk_toggle_button_get_active(radio_but)){
									i = 5 ;
									break ;
								}
			case (6):
								radio_but = GTK_TOGGLE_BUTTON(gtk_builder_get_object
														(builder, "informatica")) ;
								if(gtk_toggle_button_get_active(radio_but)){
									i = 6 ;
									break ;
								}													
		}
		
		int j = indice(PAR_ARG) ;
		const char * word = ar.mat[i][j].c_str() ;
		gioc[turno].LUN_PAR = strlen(word) ;
		gioc[turno].Parola = new char[gioc[turno].LUN_PAR] ;
		strcpy(gioc[turno].Parola, word) ;
	}
	
	TRACE1(cout<<"Parola scelta:\n"<<gioc[turno].Parola<<endl) ;
}

void crea_parola()
{
	p.Parola = new char[gioc[turno].LUN_PAR] ;
	
	int i ;
	for(i = 0 ; i < gioc[turno].LUN_PAR ; i++)
		p.Parola[i] = '_' ;	
		
	p.Parola[i] = '\0' ;	// Metto il carattere terminatore alla stringa creata

	TRACE2(cout<<"Parola inizializzata: "<<p.Parola<<endl) ;
}

