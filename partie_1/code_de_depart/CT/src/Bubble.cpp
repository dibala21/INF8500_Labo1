///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include "Bubble.h"


///////////////////////////////////////////////////////////////////////////////
//
//	Constructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::Bubble( sc_module_name zName )
: sc_module(zName)
{
	/*
	
	À compléter
	
	*/
	SC_METHOD(bubble);
	sensitive << clk.pos(); 
}


///////////////////////////////////////////////////////////////////////////////
//
//	Destructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::~Bubble()
{
}


///////////////////////////////////////////////////////////////////////////////
//
//	Bubble: communication + traitement dans une machine à états
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::bubble(void)
{
	unsigned int* ReadData = nullptr;
	unsigned int DataSize = 0; 
	unsigned int AdressCounter = 0;

	/*
	
	À compléter
		
	Machine à états. Exemple:
	- demande des données à Reader
	- lecture du nombre d'éléments
	- lecture des données (1 lecture par cycle d'hrologe)
	- Tri: a chaque passage dans l'état on fait un chagement de position si nécessaire. On reste dans l'état tant que le tri n'est pas terminé (1 opération par cycle d'hrologe)
	- Affichage (pas de wait nécessaire)
	- Arrêt de la simulations
	
	*/
	switch (CurrentState)
	{
	case Bubble::WaitingDataSize:
		address.write(0);
		request.write(true);
		while (!ack.read());
		CurrentState = ReadingDataSize;
		break;
	case Bubble::ReadingDataSize:
		DataSize = data.read();
		ReadData = new unsigned int[DataSize];
		request.write(false);
		CurrentState = WaitingData;
		break;
	case Bubble::WaitingData:
		AdressCounter++;
		if(AdressCounter <= DataSize)
		{
			address.write(AdressCounter);
			request.write(true);
			while (!ack.read());
			CurrentState = ReadingData;
		}
		else
		{
			AdressCounter = 0;
			CurrentState = Sorting;
		}
		break;
	case Bubble::ReadingData:
		ReadData[AdressCounter - 1] = data.read();
		request.write(false);
		CurrentState = WaitingData;
		break;
	case Bubble::Sorting:
		break;
	case Bubble::Printing:
		break;
	default:
		break;
	}
	/*
	switch (CurrentState)
	{
	case Bubble::SendingRequest:
		address.write(true);
		request.write(true);
		CurrentState = Reading;
		break;
	case Bubble::Reading:
		while (!ack.read());
		ReadData = data.read();
		break;
	case Bubble::PostRead:
		break;
	default:
		break;
	}
	*/
}
