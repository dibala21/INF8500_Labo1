///////////////////////////////////////////////////////////////////////////////
//
//	Reader.h
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _READER_H_
#define _READER_H_

#include <systemc.h>
#include "LMBIF.h"

///////////////////////////////////////////////////////////////////////////////
//
//	Class Reader
//
///////////////////////////////////////////////////////////////////////////////
class Reader : public sc_module
{
	public:
		// Ports
		/*
		
		À compléter
		
		*/
		sc_in_clk				clk;

		sc_port<LMBIF>			dataPortRAM;

		sc_out<unsigned int>	data;
		sc_in<unsigned int>		address;

		sc_out<bool>			ack;
		sc_in<bool>				request;

		
		// Constructor
		Reader( sc_module_name zName );

		// Destructor
		~Reader();

	private:
	
		// Process SystemC
		SC_HAS_PROCESS(Reader);
	
		void interface(void);
};

#endif
