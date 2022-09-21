///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include "Bubble.h"
#include <vector>


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

	SC_THREAD(thread);
}


///////////////////////////////////////////////////////////////////////////////
//
//	Destructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::~Bubble()
{
	/*
	
	À compléter
	
	*/

}


///////////////////////////////////////////////////////////////////////////////
//
//	thread
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::thread(void)
{
	// Variables
	const unsigned int ADDR_MEM_SIZE = 0;
	uint32_t mem_size;
	uint32_t uiOffset = 4;

	// 1ere lecture: nombre d'éléments à trier
	/*

	À compléter

	*/
	mem_size = readPort->Read(ADDR_MEM_SIZE);
	uint32_t* uiUnsortedData = new uint32_t[mem_size];

	// Lecture des éléments à trier
	/*

	À compléter

	*/
	for (int i = 0; i < mem_size; i++) {
		uiUnsortedData[i] = readPort->Read(uiOffset);
		uiOffset += 4;
	}
		

	//Appel à bubble sort
	/*

	À compléter

	*/
	bubbleSort(uiUnsortedData, mem_size);

	// Arrêt de la simulation
	sc_stop();

}


///////////////////////////////////////////////////////////////////////////////
//
//	bubbleSort
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::bubbleSort(unsigned int *ptr, int counter)
{
	uint32_t uiMoovedData = 0;
	uint32_t uiSmallestIndex = 0;
	uint32_t uiFinalCounter = counter;
	// Affichage avant tri
	/*

	À compléter

	*/
	printf("Unsorted data input:\n");

	for (int i = 0; i < counter; i++)
		printf("%d \n", ptr[i]);
	// Tri
	/*

	À compléter

	*/
	while(counter != 0)
	{
		uint32_t uiSmallestData = ptr[uiSmallestIndex];

		for(int i = uiSmallestIndex; i< uiFinalCounter; i++)
		{
			if(uiSmallestData > ptr[i])
			{
				uiSmallestData = ptr[i];
				uiMoovedData = ptr[uiSmallestIndex];
				ptr[uiSmallestIndex] = uiSmallestData;
				ptr[i] = uiMoovedData;
				
			
			}
		
		}
		counter--;
		uiSmallestIndex++;
	
	}

	// Affichage après tri
	/*

	À compléter

	*/
	printf("Sorted data output (ascending):\n");

	for (int i = 0; i < uiFinalCounter; i++)
		printf("%d \n", ptr[i]);
	
}
