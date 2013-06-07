/**
 * @file
 * 
 * Header file contenente le funzioni del sorgente Stampa.cc con le 
 * relative descrizioni.
 * */

/**
 * Funzione che fa sì che sia visibile, durante la fase di gioco, il punteggio
 * del giocatore attuale aggiornato al turno precedente. Se attiva la modalità
 * Multiplayer, è possibile visualizzare anche il punteggio dell'avversario. 
 * */
void aggiorna_punti() ;

/**
 * Funzione che tiene aggiornato il numero di tentativi e gli aiuti ancora a 
 * disposizione del giocatore. 
 * */
void conta_giocatore() ;


/**
 * Funzione che stampa le lettere già indovinate dal giocatore nella posizione
 * corretta rispetto alla parola da indovinare; stampa '_' per ogni lettera 
 * ancora da scoprire. 
 * */
void stampa_label() ;

/**
 * Funzione che cambia l'immagine dell'omino impiccato in base agli errori 
 * commessi durante il gioco (tentativi di indovinare le lettere). 
 * 
 * @return La funzione ritorna -1, 0, 1. Tale valore viene dato come parametro
 * alla funzione ::risultato.
 * */
int impiccato() ;

/**
 * Funzione che apre la finestra del risultato di tale turno di gioco.
 * Tale finestra contiene la parola indovinata o che doveva esserlo e 
 * un'etichetta positiva in caso di vittoria, negativa in caso contrario.
 * 
 * @param [in] i La funzione prende in ingresso il valore di ritorno della 
 * funzione ::impiccato.
 * 
 * Se il valore è -1 non fa nulla, se è 0 allora il giocatore ha indovinato la 
 * parola, se è 1 ha perso. 
 * 
 * @see impiccato()
 * */
void risultato(int i) ;


/**
 * Funzione che confronta le lettere premute dal giocatore e la parola da 
 * indovinare. Inoltre tiene aggiornati i contatori dei punti e degli aiuti 
 * utilizzati. 
 * 
 * Chiama le funzioni ::stampa_label , ::risultato , ::impiccato e 
 * ::conta_giocatore .
 * 
 * */
extern "C" void confronta_parola(GtkButton *button, gpointer user_data) ;
