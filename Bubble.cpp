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
	const unsigned int ADDR_MEM_SIZE = 0x00;
	const unsigned int ADDR_MEM_DATA_START = 0x01;

	// Variables
	std::vector<unsigned int> unsorted_data;
	int mem_size;
    unsigned int word_last_read;

	// 1ere lecture: nombre d'éléments à trier
	/*

	À compléter

	*/
	mem_size = readPort->Read(ADDR_MEM_SIZE);

	// Lecture des éléments à trier
	/*

	À compléter

	*/
	for (int i = ADDR_MEM_DATA_START; i <= mem_size; i++) {
        word_last_read = readPort->Read(i);
		unsorted_data.push_back(word_last_read);
	}

	//Appel à bubble sort
	/*

	À compléter

	*/
	bubbleSort(unsorted_data.data(), mem_size);

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
	// Affichage avant tri
	/*

	À compléter

	*/
    // Affichage 4-par-4 pour plus de lisibilité sur une ligne
	printf("Unsorted data input:\n");
	for (int i = 0; i < counter; i += 4) {
		printf("%d: %u %u %u %u\n", counter, ptr[i], ptr[i + 1], ptr[i + 2], ptr[i + 3]);
	}

	// Tri
	/*

	À compléter

	*/


	// Affichage après tri
	/*

	À compléter

	*/
	printf("Sorted data output (ascending):\n");
	for (int i = 0; i < counter; i += 4) {
		printf("%d: %u %u %u %u\n", counter, ptr[i], ptr[i + 1], ptr[i + 2], ptr[i + 3]);
	}
}
