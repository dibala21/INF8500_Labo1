///////////////////////////////////////////////////////////////////////////////
//
//	Reader.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include "Reader.h"

///////////////////////////////////////////////////////////////////////////////
//
//	Constructor
//
///////////////////////////////////////////////////////////////////////////////
Reader::Reader(sc_module_name zName)
: sc_module(zName)
{
	/*
	
	À compléter
	
	*/
	SC_THREAD(interface);
	//sensitive << clk.pos(); //au niveau du RTL ?
}

///////////////////////////////////////////////////////////////////////////////
//
//	Destructor
//
///////////////////////////////////////////////////////////////////////////////
Reader::~Reader()
{
}

///////////////////////////////////////////////////////////////////////////////
//
//	read
//
///////////////////////////////////////////////////////////////////////////////
void Reader::interface(void)
{
	unsigned int  DataAdress;
	unsigned int DataToWrite;

	// Boucle infinie
	while(1)
	{
		/*
		
		À compléter
		
		*/
		
		wait( clk.posedge_event() );

		if (request.read()) {

			DataAdress = address.read();
			DataToWrite = dataPortRAM->Read(DataAdress);
			data.write(DataToWrite);
			ack.write(true);
			wait(clk.posedge_event());
			ack.write(false);

		}
		
	}
}
