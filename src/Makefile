FILE = Impiccato.o Stampa.o Inizializza.o
CXXFLAGS = -Wall -export-dynamic `pkg-config --cflags --libs gtk+-3.0`

Impiccato: $(FILE)
	g++ -o Impiccato $(FILE) -Wall -export-dynamic `pkg-config --cflags --libs gtk+-3.0`


-include dependencies 

#dichiariamo i phony target
.PHONY: depend clean cleanall debug


depend:
	g++ -MM *.cc > dependencies 

#per ripulire la directory dai file temporanei
clean:
	rm *.o
cleanall:
	rm Impiccato *.o

debug:
	g++ -o Impiccato -export-dynamic ./Impiccato.cc ./Inizializza.cc ./Stampa.cc -g `pkg-config --cflags --libs gtk+-3.0` -D DEBUG_MODE

