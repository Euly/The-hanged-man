#include "Struttura_dati.h"
#include "Stampa.h"

/**
 * @file
 * 
 * Questo file contiene le funzioni relative all'implementazione algoritmica
 * della soluzione del gioco, nonché la stampa a video (tramite interfaccia
 * grafica) di tutte le variabili utilizzate nel programma (nomi giocatori,
 * punteggi, aiuti, ...).
 * */

void aggiorna_punti()
{
	TRACE2(cout<<"Giocatore1\n") ;
	GtkLabel * nome = GTK_LABEL(gtk_builder_get_object(builder, "Label_nome1")) ;
	gtk_label_set_text(nome, gioc[turno].Nome) ;
	TRACE2(cout<<"Punti INT == "<<gioc[turno].Punti<<endl) ;
	
	char pt1[3] ;
	int LUN_pt1 = sprintf(pt1, "%d", gioc[turno].Punti) ;
	pt1[LUN_pt1] = '\0' ;
	TRACE2(cout<<"Punti CHAR == "<<pt1<<endl) ;
	
	GtkLabel * punti = GTK_LABEL(gtk_builder_get_object(builder, "Label_punti1")) ;
	gtk_label_set_text(punti, pt1) ;
	
	
	nome = GTK_LABEL(gtk_builder_get_object(builder, "Label_nome2")) ;
	punti = GTK_LABEL(gtk_builder_get_object(builder, "Label_punti2")) ;
	
	GtkLabel * hits = GTK_LABEL(gtk_builder_get_object(builder, "Label_hits")) ;
	
	if(Multiplayer){
		gtk_label_set_text(nome, gioc[!turno].Nome) ;
		TRACE2(cout<<"Giocatore2\n") ;
		TRACE2(cout<<"Punti INT == "<<gioc[!turno].Punti<<endl) ;
		
		char pt2[3] ;
		int LUN_pt2 = sprintf(pt2, "%d", gioc[!turno].Punti) ;
		pt2[LUN_pt2] = '\0' ;
		TRACE2(cout<<"Punti CHAR == "<<pt2<<endl) ;
		
		gtk_label_set_text(punti, pt2) ;
		TRACE2(cout<<"Hits INT == "<<gioc[!turno].Hits<<endl) ;
		
		char h[3] ;
		int LUN_h = sprintf(h, "%d", gioc[!turno].Hits) ;
		h[LUN_h] = '\0' ;
		TRACE2(cout<<"Hits CHAR == "<<h<<endl) ;
	
		gtk_label_set_text(hits, h) ;
	}
	else{
		gtk_label_set_text(nome, "") ;
		gtk_label_set_text(punti, "") ;
		gtk_label_set_text(hits, "") ;
	}
}

void conta_giocatore()
{
	TRACE2(cout<<"Giocatore corrente:\n") ;
	TRACE2(cout<<"Hits INT == "<<gioc[turno].Hits<<endl) ;
	
	char h[3] ;
	int LUN_h = sprintf(h, "%d", gioc[turno].Hits) ;
	h[LUN_h] = '\0' ;
	TRACE2(cout<<"Hits CHAR == "<<h<<endl) ;
	
	GtkLabel * Hits = GTK_LABEL(gtk_builder_get_object(builder, "Num_Hits")) ;
	gtk_label_set_text(Hits, h) ;
	TRACE2(cout<<"Tentativi INT == "<<gioc[turno].Tentativi<<endl) ;
	
	char t[3] ;
	int LUN_t = sprintf(t, "%d", gioc[turno].Tentativi) ;
	t[LUN_t] = '\0' ;
	TRACE2(cout<<"Tentativi CHAR == "<<t<<endl) ;
	
	GtkLabel * Tent = GTK_LABEL(gtk_builder_get_object(builder, "Num_Tent")) ;
	gtk_label_set_text(Tent, t) ;
	
}

void stampa_label()
{
	/* tracing */
	for(int i = 0 ; i < gioc[turno].LUN_PAR ; i++)
		TRACE2(cout<<p.Parola[i]<<" ") ;
		
	cout<<endl ;
	GtkLabel *XWord = GTK_LABEL(gtk_builder_get_object(builder, "XWord")) ;
	gtk_label_set_text(XWord, p.Parola) ;
}

int impiccato()
{
	GtkImage *image = GTK_IMAGE(gtk_builder_get_object(builder, "Impiccato")) ;
	
	if(!strcmp(gioc[turno].Parola, p.Parola)){
		gtk_image_set_from_file(image, "Winner.png") ;
		return 0 ;
	}
	
	switch(gioc[turno].Tentativi){
		case (1) :
								gtk_image_set_from_file(image, "animazione1.png") ;
								break ;
		case (2) :
								gtk_image_set_from_file(image, "animazione2.png") ;
								break ;
		case (3) :
								gtk_image_set_from_file(image, "animazione3.png") ;
								break ;	
		case (4) :
								gtk_image_set_from_file(image, "animazione4.png") ;
								break ;	
		case (5) :
								gtk_image_set_from_file(image, "animazione5.png") ;
								break ;							
		case (6) :
								gtk_image_set_from_file(image, "animazione6.png") ;
								break ;							
		case (7) :
								gtk_image_set_from_file(image, "animazione7.png") ;
								break ;							
		case (8) :
								gtk_image_set_from_file(image, "animazione8.png") ;
								break ;		
		case (9) :
								gtk_image_set_from_file(image, "animazione9.png") ;
								break ;						
		case (10) :
								gtk_image_set_from_file(image, "animazione10.png") ;
						  	
								return 1 ;								
	}
	return -1 ;
}

void risultato(int i){
	if(i == -1)
		return ;
	
	gioc[turno].Punti += (10 - gioc[turno].Tentativi) ; 

	TRACE1(cout<<"punteggio raggiunto= "<<gioc[turno].Punti<<endl) ;
	
	GtkWidget *win = GTK_WIDGET(gtk_builder_get_object(builder, "Gioco")) ;
	gtk_widget_hide(win) ;
	
	GtkLabel *label = GTK_LABEL(gtk_builder_get_object(builder, "Label_nome_gioc")) ;
	gtk_label_set_text(label, gioc[turno].Nome) ;
	
	label = GTK_LABEL(gtk_builder_get_object(builder, "Label_indovinato")) ;	
	
	GtkLabel *lab = GTK_LABEL(gtk_builder_get_object(builder, "guessed")) ;
	gtk_label_set_text(lab, gioc[turno].Parola) ;
	
	GtkImage *image = GTK_IMAGE(gtk_builder_get_object(builder, "Faccina")) ;
	GtkImage *omino = GTK_IMAGE(gtk_builder_get_object(builder, "Vivo_morto")) ;
	
	if (i == 0){
		gtk_image_set_from_file(image, "face-smile.svg") ;
		gtk_image_set_from_file(omino, "Winner.png") ;
		gtk_label_set_text(label, "Hai indovinato!") ;	
	}
	else{
		gtk_image_set_from_file(image, "face-sad.svg") ;
		gtk_image_set_from_file(omino, "animazione10.png") ;
		gtk_label_set_text(label, "Non hai indovinato.") ;
	}
	
	label = GTK_LABEL(gtk_builder_get_object(builder, "Label_Turno")) ;
	image = GTK_IMAGE(gtk_builder_get_object(builder, "Gioca_ancora")) ;
	if (Multiplayer){
		gtk_label_set_text(label, "Passa turno") ;
		gtk_image_set_from_file(image, "gtk-go-forward.png") ;
	}
	else{
		gtk_label_set_text(label, "Gioca ancora") ;
		gtk_image_set_from_file(image, "gioca_ancora.png") ;
	}
	
	win = GTK_WIDGET(gtk_builder_get_object(builder, "Risultato")) ;
	gtk_widget_show_all(win) ;
}

extern "C" void confronta_parola(GtkButton *button, gpointer user_data)
{
	bool controllo = false ;
	
	const char *car = new char[1];
	car =  gtk_button_get_label(button) ;
	TRACE2(cout<<"Carattere premuto: "<<car<<endl) ;
	
	gtk_widget_set_sensitive(GTK_WIDGET(gtk_builder_get_object(builder, car)), false) ;
	
	char c = car[0] ;
	c = tolower(c) ;
	TRACE3(cout<<"c == "<<c<<endl) ;
	
	for(int i = 0 ; i < gioc[turno].LUN_PAR ; i++)
		if(gioc[turno].Parola[i] == c)
		{
			controllo = true ;
			break ;
		}
	
	if(!controllo)
	{
		gioc[turno].Tentativi++ ;
	}
	
	for(int i = 0 ; i < gioc[turno].LUN_PAR ; i++)
		if(gioc[turno].Parola[i] == c)
			p.Parola[i] = c ;
			
	stampa_label() ;
	risultato(impiccato()) ;
	conta_giocatore() ;
}

/* Funzione di supporto a Esci() nel caso in cui l'utente ci ripensi e voglia
 * tornare al gioco. */
extern "C" void Play_again(GtkButton * button, gpointer user_data){
	GtkWidget *win = GTK_WIDGET(gtk_builder_get_object(builder, "Esci")) ;
	gtk_widget_hide(win) ;
	
	win = GTK_WIDGET(gtk_builder_get_object(builder, "Risultato")) ;
	gtk_widget_show_all(win) ;
}

/* Funzione che permette al giocatore di uscire dal gioco. */
extern "C" void Esci(GtkButton * button, gpointer user_data)
{
	GtkWidget *win1 = GTK_WIDGET(gtk_builder_get_object(builder, "Risultato")) ;
	gtk_widget_hide(win1) ;
	
	GtkLabel *nome1 = GTK_LABEL(gtk_builder_get_object(builder, "NomeG1")) ;
	GtkLabel *punti1 = GTK_LABEL(gtk_builder_get_object(builder, "PuntiG1")) ;
	gtk_label_set_text(nome1, gioc[0].Nome) ;
	
	/* Per i punti usiamo l'escamotage adottato in aggiorna_punti() */
	char pt1[3] ;
	int LUN_pt1 = sprintf(pt1, "%d", gioc[0].Punti) ;
	pt1[LUN_pt1] = '\0' ;
	gtk_label_set_text(punti1, pt1) ;
	
	if(Multiplayer){
		GtkLabel *nome2 = GTK_LABEL(gtk_builder_get_object(builder, "NomeG2")) ;
		GtkLabel *punti2 = GTK_LABEL(gtk_builder_get_object(builder, "PuntiG2")) ;
		gtk_label_set_text(nome2, gioc[1].Nome) ;
		
		char pt2[3] ;
		int LUN_pt2 = sprintf(pt2, "%d", gioc[1].Punti) ;
		pt2[LUN_pt2] = '\0' ;
		gtk_label_set_text(punti2, pt2) ;
	}
	
	GtkWidget *win2 = GTK_WIDGET(gtk_builder_get_object(builder, "Esci")) ;
	gtk_widget_show_all(win2) ;
	
}





