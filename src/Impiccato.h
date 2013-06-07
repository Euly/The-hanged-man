#include "Inizializza.h"
#include "Stampa.h"

/**
 * @file
 * 
 * Header file contenente le funzioni del sorgente Impiccato.cc con le 
 * relative descrizioni.
 * */

/**
 * Funzione che permette di chiudere le finestre dell'applicazione causando
 * l'uscita dal gtk_main() (ciclo infinito). 
 * 
 * @see main()
 * */
extern "C" gboolean handler_delete_event(GtkWidget *widget, GdkEvent *event,
															           gpointer user_data) ;
															           

/**
 * Funzione che permette di fare una nuova partita, resettando tutti i valori
 * precedenti e ripartendo dall'inizio. 
 * */
extern "C" void Nuova_partita (GtkButton *button, gpointer user_data) ;

/** 
 * Funzione che nasconde la finestra con le regole del gioco. 
 * */
extern "C" void Regole_fine (GtkButton *button, gpointer user_data) ;

/**
 * Funzione che apre la finestra delle regole del gioco. 
 * */
extern "C" void Regole_inizio (GtkButton *button, gpointer user_data) ;


/**
 * Funzione che permette il cambio turno dei giocatori in caso di modalità
 * Multiplayer == true. Vengono conservati il numero degli aiuti a 
 * disposizione di ognuno ed i punteggi fino ad ora. 
 * */
extern "C" void Cambio_turno (GtkButton *button, gpointer user_data) ;

/**
 * Funzione che permette al giocatore di utilizzare uno dei suoi "Hits" e quindi
 * di scoprire una lettera mancante nella parola da indovinare. 
 * */
extern "C" void Help (GtkButton *button, gpointer user_data) ;

/**
 * Funzione di supporto a Play() per resettare tutti i bottoni premuti nel turno
 * precedente e l'immagine dell'impiccato. La funzione viene richiamata tutte le
 * volte che il giocatore decide di passare turno (modalità Multiplayer == true)
 * oppure quando vuole giocare ancora contro il computer. 
 * */
static void Resetto () ;

/**
 * Funzione che richiama la funzione di scelta della parola (::parola) da 
 * indovinare da un altro sorgente e la memorizza nella struttura. 
 * La parola è scelta o dall'avversario o randomizzata dalla matrice 
 * inizializzata con le parole scelte a tempo di scrittura del programma. 
 * */
extern "C" void Play (GtkButton *button, gpointer user_data) ;

/**
 * Funzione di supporto a ::nomi_giocatori() e a ::Cambio_turno().
 * Mostra la finestra che prende in ingresso la parola dell'avversario. 
 * La funzione viene chiamata solo nella modalità Multiplayer == true all'atto
 * di dover scegliere la parola da indovinare (scelta fatta dall'avversario). 
 * */
static void Mostra_finestra_parola() ;


/**
 * Funzione che prende in ingresso il buffer con i nomi dei giocatori e li 
 * memorizza nel campo della struttura a loro dedicato. 
 * */
extern "C" void nomi_giocatori (GtkButton *button, gpointer user_data) ;


/**
 * Funzione che permette di scegliere la modalità di gioco:
 * - Singolo giocatore: scelta dell'argomento della parola
 * - Due giocatori: inserimento parola da parte dell'avversario
 * */
extern "C" void info_gioco (GtkButton *button, gpointer user_data) ;

/**
 * Funzione che chiude la finestra con il titolo del gioco ed apre quella con la
 * scelta della modalità di gioco. È la primissima funzione che viene chiamata
 * all'inizio del programma (fatta eccezione per la funzione principale ::main).
 * */
extern "C" void start(GtkButton *button, gpointer user_data) ;

/**
 * Funzione principale del programma.
 * Contiene un ciclo infinito da cui si esce soltanto attraverso la funzione
 * ::handler_delete_event.
 * */
int main(int argc, char **argv) ;
