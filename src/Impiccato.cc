/** 
 * @mainpage
 * 
 * GIOCO DELL'IMPICCATO \n
 *
 * Il programma implementa il semplice gioco dell'impiccato nella modalità
 * 1 giocatore o 2 giocatori. \n
 * 
 * REGOLE DEL GIOCO: \n
 * \n
 * MODALITÀ "1 GIOCATORE" \n
 * --------------------------------------------------------------------------- \n
 * Il giocatore gioca contro il computer che sceglie la parola da assegnare 
 * scegliendola a random da una lista predefinita. \n
 * Il giocatore può però scegliere l'argomento che più preferisce e il computer 
 * limiterà la sua scelta a tale campo. \n
 * Gli argomenti proposti sono: \n
 * -	ARTE : artisti italiani \n
 * -	LETTERATURA : autori italiani e non \n
 * -	CINEMA : attori e registi famosi \n
 * -	SPORT : tennis, calcio, pattinaggio, nuoto \n
 * -	GEOGRAFIA : capitali del mondo \n
 * -	SCIENZE : fisica, chimica, scienze naturali \n
 * -	INFORMATICA : lessico generico \n
 * \n
 * MODALITÀ "2 GIOCATORI" \n
 * --------------------------------------------------------------------------- \n
 * Si tratta di una sfida fra i due giocatori. \n
 * All'inizio il giocatore 2 sceglie una parola che l'avversario deve indovinare
 * ed al turno successivo di scambiano di ruolo. \n
 * In ogni momento di gioco, il giocatore attivo può vedere sia i punti da lui 
 * ottenuti, sia quelli del suo avversario con i relativi aiuti ancora a 
 * disposizione. \n
 * \n
 * PUNTI ED AIUTI \n
 * --------------------------------------------------------------------------- \n
 * Il massimo punteggio per ogni parola indovinata è 10 punti. \n
 * Ogni giocatore ha a disposizione 10 tentativi per turno per indovinare la 
 * parola nascosta nella nuvola e 3 aiuti totali(Hits) che può richiedere 
 * premendo semplicemente il tasto "Help". \n
 * I punti conseguiti all'atto di scoperta della parola sono inversamente 
 * proporzionali ai tentativi che il giocatore ha effettuato durante il turno. \n
 * Ogni tentativo mancato viene infatti conteggiato con -1 punto, perciò se la 
 * parola non viene indovinata entro i 10 tentativi, il giocatore ottiene 0 
 * punti. Allo stesso modo, si ottiene il punteggio pieno se non si commettono 
 * errori. \n
 * Gli aiuti si intendono complessivi per la sessione di gioco, quindi un 
 * giocatore che abbia finito tutti e 3 gli aiuti nei turni precedenti, dovrà 
 * affrontare la sfida (contro il pc o contro l'altro giocatore) senza ulteriori
 * suggerimenti. \n
 * \n
 * GIOCO \n
 * --------------------------------------------------------------------------- \n
 * Il giocatore deve indovinare la parola nascosta nella nuvola. \n
 * Per farlo deve scegliere una lettera alla volta cliccando sull'apposito tasto
 * oppure scrivendola da tastiera. \n
 * \n
 * Si può ricominciare il gioco cliccando sul pulsante "New Game". Tutti i 
 * giocatori, i loro punteggi ed i loro aiuti verranno persi. \n
 * \n \n
 * 
 * Il programma è suddiviso in 3 moduli principali: \n
 * Impiccato.cc		contenente il main \n
 * Inizializza.cc 	contenente le funzioni di inizializzazione \n 
 * Stampa.cc	 contenente le funzioni relative alla stampa \n
 * \n
 * Tutti i moduli si appoggiano alla libreria utilizzata per implementare 
 * l'interfaccia grafica. \n
 * \n
 * Tutti i moduli hanno un header file a loro dedicato: \n
 * Impiccato.h \n
 * Inizializza.h \n
 * Stampa.h \n
 * 
 * Per informazioni sulla struttura dati del programma @see Struttura_dati.h
 * 
 * File contenente il modulo Main. \n
 * 
 * @author Diana Pop
 * */

#include <cstdlib>
#include "Struttura_dati.h"
#include "Impiccato.h"


/**
 * @file
 * 
 * Questo file contiene la maggior parte delle funzioni del programma nonché la
 * funzione principale ::main da cui parte tutto.
 * Inoltre contiene gli handler che permettono il collegamento, tramite 
 * interfaccia grafica e relative chiamate di funzioni, degli altri moduli.
 * */

GtkBuilder *builder ;
bool Multiplayer ;
bool NewGame = true ;
int MASK = 3 ;

extern "C" gboolean handler_delete_event(GtkWidget *widget, GdkEvent *event,
															           gpointer user_data)
{
	gtk_main_quit() ;
	return true ;
}

extern "C" void Link_Doc (GtkButton *button, gpointer user_data)
{
	system("sensible-browser ./../doc/html/index.html") ;
}

extern "C" void Nuova_partita (GtkButton *button, gpointer user_data)
{
	/* Setto NewGame a true per le chiamate di inizializzazione punteggio */
	NewGame = true ;
	
	/* Nascondo la precedente schermata di gioco */
	GtkWidget *play = GTK_WIDGET(gtk_builder_get_object(builder, "Gioco")) ;
	gtk_widget_hide(play) ;
	
	/* Pulisco il buffer delle precedenti operazioni: nomi, parola */
	GtkEntry *buf = GTK_ENTRY(gtk_builder_get_object(builder, "entry1")) ;
	gtk_entry_set_text(buf, "") ;
	
	buf = GTK_ENTRY(gtk_builder_get_object(builder, "entry2")) ;
	gtk_entry_set_text(buf, "") ;
	
	buf = GTK_ENTRY(gtk_builder_get_object(builder, "word_entry")) ;
	gtk_entry_set_text(buf, "") ;
	
	/* Chiamo la funzione Resetto() per assicurarmi che tutti i tasti siano attivi
	 * e che non vi sia nessuna immagine dell'omino impiccato (sintomo di 
	 * tentativi) già effettuati dal giocatore. */
	Resetto() ;
	
	/* Richiamo la schermata con la modalità di gioco iniziale */
	GtkWidget *modo_win = GTK_WIDGET(gtk_builder_get_object(builder, "Modo")) ;
	gtk_widget_show_all(modo_win) ;
}

extern "C" void Regole_fine (GtkButton *button, gpointer user_data)
{
	GtkWidget *w = GTK_WIDGET(gtk_builder_get_object(builder, "Window_regole")) ;
	gtk_widget_hide(w) ;
}

extern "C" void Regole_inizio (GtkButton *button, gpointer user_data)
{
	GtkWidget *w = GTK_WIDGET(gtk_builder_get_object(builder, "Window_regole")) ;
	gtk_widget_show_all(w) ;
}

extern "C" void Cambio_turno (GtkButton *button, gpointer user_data)
{
	NewGame = false ;
	GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "Risultato")) ;
	gtk_widget_hide(window) ;

	TRACE1("Chiamo Resetto()\n") ;
	Resetto() ;
	
	if(Multiplayer){
		turno = !turno ;
		crea_parola() ;
		Mostra_finestra_parola() ;
	}
	else{
		GtkWidget *argo = GTK_WIDGET(gtk_builder_get_object(builder, "Argomento")) ;
		gtk_widget_show_all(argo) ;
	}
}

extern "C" void Help (GtkButton *button, gpointer user_data)
{
	if(gioc[turno].Hits == 0)
		return ;
		
	gioc[turno].Hits-- ;
		
	int ind ;
	for(ind = 0 ; ind < gioc[turno].LUN_PAR ; ind++)
		if(p.Parola[ind] == '_')
			break ;
	
	char C = gioc[turno].Parola[ind] ;
	char *c = new char[2] ;
	c[0] = toupper(C) ; c[1] = '\0' ;
	GtkButton *lettera = GTK_BUTTON(gtk_builder_get_object(builder, c)) ;
	gtk_button_clicked(lettera) ;
}

static void Resetto ()
{
	GtkImage *image = GTK_IMAGE(gtk_builder_get_object(builder, "Impiccato")) ;
	gtk_image_set_from_file(image, NULL) ;
	
	for(char c = 'A' ; c <= 'Z' ; c++){
		TRACE3(cout<<"c == "<<c<<endl) ; 
		
		char *C = new char[2] ;
		C[0] = c ; C[1] = '\0' ;
		TRACE3(cout<<"C == "<<C<<endl) ;
		
		gtk_widget_set_sensitive(GTK_WIDGET(gtk_builder_get_object(builder, C)), true) ;
	}
	
}


extern "C" void Play (GtkButton *button, gpointer user_data)
{
	GtkWidget *window ;
	
	if(Multiplayer)
		window = GTK_WIDGET(gtk_builder_get_object(builder, "Parola")) ;
	else
		window = GTK_WIDGET(gtk_builder_get_object(builder, "Argomento")) ;
	
	gtk_widget_hide(window) ;
	
	if(Multiplayer)
		Resetto() ;
		
	parola() ;
		
	window = GTK_WIDGET(gtk_builder_get_object(builder, "Gioco")) ;
	gtk_widget_show_all(window) ;
	
	// Chiamate di funzioni che possono stare nella prossima funzione
	crea_parola() ;
	stampa_label() ;
	inizializzo_punteggio() ;
	conta_giocatore() ;
	aggiorna_punti() ;
}

static void Mostra_finestra_parola()
{
	GtkLabel *nome_gioc2 = 
									GTK_LABEL(gtk_builder_get_object(builder, "LabelNomeGioc2")) ;
	gtk_label_set_text(nome_gioc2, gioc[!turno].Nome);
		
	GtkWidget	*window = GTK_WIDGET(gtk_builder_get_object(builder, "Parola")) ;
	gtk_widget_show_all(window) ;
}

extern "C" void nomi_giocatori (GtkButton *button, gpointer user_data)
{
	GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "Players")) ;
	gtk_widget_hide(window) ;
	
	GtkEntry *nome = GTK_ENTRY(gtk_builder_get_object(builder, "entry1")) ;
	GtkEntryBuffer *buffer1 = 
					GTK_ENTRY_BUFFER(gtk_builder_get_object(builder, "entrybuffer1")) ;
	buffer1 = gtk_entry_get_buffer(nome) ;
	
	const char * name1 = gtk_entry_buffer_get_text(buffer1) ;
	gioc[turno].LUN_NOME = strlen(name1) ;
	gioc[turno].Nome = new char[gioc[turno].LUN_NOME] ;
	strcpy(gioc[turno].Nome,name1) ;
	
	TRACE1(cout<<gioc[turno].Nome<<endl) ;
	
	if(!Multiplayer){
		window = GTK_WIDGET(gtk_builder_get_object(builder, "Argomento")) ;
		gtk_widget_show_all(window) ;
	}
	else {
		nome = GTK_ENTRY(gtk_builder_get_object(builder, "entry2")) ;
		GtkEntryBuffer *buffer2 = 
						GTK_ENTRY_BUFFER(gtk_builder_get_object(builder, "entrybuffer2")) ;
		buffer2 = gtk_entry_get_buffer(nome) ;
		
		const char *name2 = gtk_entry_buffer_get_text(buffer2) ;
		gioc[!turno].LUN_NOME = strlen(name2) ;
		gioc[!turno].Nome = new char[gioc[!turno].LUN_NOME] ;
		strcpy(gioc[!turno].Nome, name2) ;

		TRACE1(cout<<gioc[!turno].Nome<<endl) ;
		
		/* Inseriamo il nome nella label della prossima finestra. */
		Mostra_finestra_parola() ;
	}
}

extern "C" void info_gioco(GtkButton *button, gpointer user_data)
{
	turno = false ;		// Partiamo dal giocatore 1

	TRACE1(cout<<"Multiplayer = ") ;
	
	if (button == GTK_BUTTON(gtk_builder_get_object(builder, "Gioc2")) ){
		Multiplayer = true ;
		TRACE1(cout<<"true\n") ;
	}
	else{
		Multiplayer = false ;
		TRACE1(cout<<"false\n") ;
	}
	
	GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "Modo")) ;
	gtk_widget_hide(window) ;
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "Players")) ;
	
	if(!Multiplayer){
		gtk_widget_show(window) ;
		gtk_widget_hide(GTK_WIDGET(gtk_builder_get_object(builder, "giocatore2a"))) ;
		gtk_widget_hide(GTK_WIDGET(gtk_builder_get_object(builder, "giocatore2b"))) ;
	}
	else{
		gtk_widget_show_all(window) ;
		gtk_widget_show(GTK_WIDGET(gtk_builder_get_object(builder, "giocatore2a"))) ;
		gtk_widget_show(GTK_WIDGET(gtk_builder_get_object(builder, "giocatore2b"))) ;
	}
}

extern "C" void start(GtkButton *button, gpointer user_data)
{
	GtkWidget *start_win = 
									GTK_WIDGET(gtk_builder_get_object(builder, "Titolo_gioco")) ;						
	gtk_widget_hide(start_win) ;
	
	GtkWidget *modo_win = GTK_WIDGET(gtk_builder_get_object(builder, "Modo")) ;
	gtk_widget_show_all(modo_win) ;
}

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    
    builder = gtk_builder_new() ;
    
    gtk_builder_add_from_file(builder, "Impiccato.glade", NULL) ;
	
		gtk_builder_connect_signals(builder, NULL) ;
		
		gtk_main() ;

    return 0 ;
}
