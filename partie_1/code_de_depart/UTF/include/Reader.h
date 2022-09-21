///////////////////////////////////////////////////////////////////////////////
//
//	Reader.h
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _READER_H_
#define _READER_H_

#include <systemc.h>
#include "LMBIF.h"
#include "InterfaceRead.h"

///////////////////////////////////////////////////////////////////////////////
//
//	Class Reader
//
///////////////////////////////////////////////////////////////////////////////
class Reader : public sc_module, public InterfaceRead
{
	public:
		// Ports
		sc_port<LMBIF>			dataPortRAM;
		
		// Constructor
		Reader( sc_module_name zName );

		// Destructor
		~Reader();

	private:
	
	// Read - InterfaceRead
	virtual unsigned int Read(unsigned int uiAddr);
};

#endif
