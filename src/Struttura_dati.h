/**
 * @file
 * 
 * Header file contenente la struttura dati del gioco:
 * - strutture globali
 * - variabili globali costanti
 * - variabili globali suddivise per moduli
 * - macro per il debug
 * */

#include <iostream>
#include <cstring>
#include <gtk/gtk.h>
using namespace std ;

/** Numero di argomenti per la scelta della parola. */
const int NUM_ARG = 7 ; 

/** Numero di parole diverse per argomento. */
const int PAR_ARG = 10 ; 
	
/** 
 * Struttura globale con i campi informazione relativi ai giocatori:
 * - Nome
 * - Punti
 * - Tentativi
 * - Aiuti
 * - Parola da indovinare
 * 
 * Parametri aggiuntivi:
 * - Lunghezza del nome per la creazione della stringa dinamica
 * - Lunghezza della parola da indovinare per la creazione della parola 
 *   d'appoggio
 * */
struct informazioni {
	char *Nome ;
	int LUN_NOME, LUN_PAR ;
	int Punti, Tentativi, Hits ;
	char *Parola ;
} ;

/** 
 * Struttura globale contenente la matrice di string. 
 * */
struct argomenti {
	string mat[NUM_ARG][PAR_ARG] ;
} ;

/*..............................INIZIALIZZA.CC...............................*/

/**
 * Variabile booleana che permette di cambiare turno dei giocatori. Viene usata
 * come indice nell'array di tipo informazioni gioc[]. */
extern bool turno ;

/**
 * Variabili di tipo struttura che permettono di accedere ai vari campi.
 * gioc[2] è utilizzata per tenere traccia separatamente di ogni giocatore,
 * mentre p viene usata solo per accedere ai campi LUN_PAR e Parola e serve per
 * la stringa da sovrascrivere dopo l'inizializzazione con i trattini. 
 * */
extern informazioni gioc[2], p ;

/**
 * Variabile globale che serve per accedere alla matrice di stringhe.
 * */
extern argomenti ar ;

/*...............................IMPICCATO.CC................................*/

/**
 * Puntatore ad un oggetto dell'interfaccia grafica. Viene utilizzato per 
 * raggiungere tutti gli oggetti desiderati e modificarne il contenuto a 
 * piacimento. Sostiene l'intera interfaccia grafica del programma. 
 * */
extern GtkBuilder *builder ;

/**
 * Booleano che indica se si sta giocando in modalità Multiplayer 
 * (due giocatori), oppure no. 
 * All'inizio del gioco è settato a false (giocatore singolo) 
 * */
extern bool Multiplayer ; 

/**
 * Booleano che indica se si sta eseguendo o meno una nuova partita.
 * Serve per evitare reinizializzazioni di punteggi ed aiuti durante i cambi 
 * turno nella modalità Multiplayer == true oppure il gioca ancora nella 
 * modalità 1 giocatore. 
 * */
extern bool NewGame ;													 

/*............................. MACRO DEBUG..................................*/

/**
 * Maschera utilizzata per il Debug Mode. Definita nel file ""Inizializza.cc".
 * - Se settata ad 1 provoca un debug superficiale
 * - Se settata a 2 il tracing di fa più intenso
 * - Se settata a 3 provoca il livello massimo di debug
 * */
extern int MASK ;

/**
 * Macro per la modalità Debug. Si attiva tramite la compilazione con il 
 * comando "make debug" e si disattiva con il comando "make". 
 * */
#ifdef DEBUG_MODE
#		define TRACE(X, Y) { if((X) & MASK)	{Y; }}
#else
#		define TRACE(X, Y)	do {} while (0)
#endif

#define TRACE1(x) TRACE(1, x)
#define TRACE2(x) TRACE(2, x)
#define TRACE3(x) TRACE(3, x)




