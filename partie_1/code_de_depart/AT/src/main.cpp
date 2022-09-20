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
	// Variables
	int sim_units = 2; //SC_NS 

	// Clock
	sc_clock sClk( "SysClock", 4000, SC_NS, 0.5 );
	
	// Instanciation des composants
	Bubble iBubble("Bubble");
	/*
	
	À compléter
	
	*/
	
	// Signaux
	/*
	
	À compléter
	
	*/
	
	// Connexion des ports
	iBubble.clk(sClk);
	/*
	
	À compléter
	
	*/
	
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
