///////////////////////////////////////////////////////////////////////////////
//
//	main.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include <systemc.h>
#include "Bubble.h"
#include "Reader.h"
#include "DataRAM.h"

#define RAMSIZE 0x400

// Global variables
bool m_bError = false;

///////////////////////////////////////////////////////////////////////////////
//
//	Main
//
///////////////////////////////////////////////////////////////////////////////
int sc_main(int arg_count, char **arg_value)
{
	// Clock
	sc_clock sClk( "SysClock", 4000, SC_NS, 0.5 );
	
	// Instanciation des composants
	Bubble iBubble("Bubble");
	/*
	
	À compléter
	
	*/
	Reader iReader("Reader");
	DataRAM iDataRAM( "DataRAM", "memory/mem.hex", RAMSIZE, false);
	
	// Signaux
	/*
	
	À compléter
	
	*/
	sc_signal<unsigned int> data;
	sc_signal<unsigned int> address;
	sc_signal<bool> ack;
	sc_signal<bool> request;
	
	// Connexion des ports
	/*
	
	À compléter
	
	*/
	// Reader
	iReader.clk(sClk);
	iReader.dataPortRAM(iDataRAM);
	iReader.data(data);
	iReader.address(address);
	iReader.ack(ack);
	iReader.request(request);

	// Bubble
	iBubble.clk(sClk);
	iBubble.address(address);
	iBubble.data(data);
	iBubble.request(request);
	iBubble.ack(ack);
	
	// Démarrage de l'application
	if (!m_bError)
	{
		cout << "Demarrage de la simulation." << endl;
		sc_start( 20, SC_MS);
		cout << endl << "Simulation s'est terminee a " << sc_time_stamp() << endl;
	}
	// Fin du programme
	return 0;
}
