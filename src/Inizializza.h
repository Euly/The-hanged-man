/**
 * @file
 * 
 * Header file contenente le funzioni del sorgente Inizializza.cc con le 
 * relative descrizioni.
 * */
 
/**
 * Funzione che inizializza i punteggi e gli aiuti dei giocatori in caso di 
 * nuova partita (NewGame == true) mentre li lascia invariati ad ogni
 * cambio turno. I tentativi vengono invece sempre inizializzati a 0.
 * Sono le funzioni ::confronta_parola , ::risultato e ::Help che modificano 
 * effettivamente i tentativi, i punteggi e gli aiuti di ogn giocatore.
 * */
void inizializzo_punteggio() ;

/**
 * Funzione che prende in ingresso la matrice di stringhe e la inizializza con
 * le parole suddivise per argomenti. Viene utilizzata solo quando la modalità
 * di gioco è Multiplayer == false. 
 * */
void inizializzo_argomenti() ;

/**
 * Funzione di supporto a ::parola e serve a ritornare un numero casuale. \n
 * 
 * Il numero generato è casuale in quanto si appoggia alla funzione di libreria 
 * rand() utilizzando ogni volta un seme diverso. 
 * Il seme è scelto grazie alla funzione time(0) che ritorna il numero di 
 * secondi trascorsi dal 1 gennaio 1970. \n
 * 
 * Viene utilizzato per scegliere in maniera casuale gli indici delle parole  
 * tra le colonne della matrice di stringhe (10 per ogni argomento) e, se il
 * giocatore ha scelto argomento == "tutti", anche tra le righe. \n
 * 
 * @param [in] mod La funzione prende in ingresso il numero di range massimo per 
 * essere randomizzato.
 * 
 * @return La funzione ritorna un numero intero compreso tra 0 e mod-1.
 * */
int indice(int mod) ;

/**
 * Funzione che sceglie la parola da assegnare al giocatore in base alla 
 * modalità di gioco. 
 * Se la modalità è Multiplayer == true, allora prende il buffer dell'EntryText
 * e ne ricopia il contenuto dentro gioc[turno].Parola ; altrimenti sceglie la
 * parola dalla matrice di stringhe precedentemente inizializzata attraverso la
 * funzione ::indice per il calcolo degli indici righe/colonne. 
 * */
void parola() ;

/**
 * Funzione che crea una parola lunga come quella da indovinare inizializzandola
 * con i trattini bassi (underscore '_'). 
 * Tale parola serve come array di appoggio sia per far visualizzare al 
 * giocatore la lunghezza della parola, sia per modificarla a run time 
 * aggiungendo le lettere nelle posizioni giuste se l'utente ha indovinato un 
 * carattere.
 * Infine si usa questa parola per confrontarla, ad ogni tasto premuto, con la
 * parola da indovinare.
 * */
void crea_parola() ;

