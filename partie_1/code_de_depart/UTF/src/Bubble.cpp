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

	SC_THREAD(interface);
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
//	Interface avec le module Reader: sc_thread ou sc_method
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::interface(void)
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
	int n_words_to_sort = counter;
	unsigned int* words_being_sorted = ptr;
	unsigned int temp_word;	// temporary holder used for swapping in place

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
	// Faire n passages à travers les données.
	for (int i = n_words_to_sort; i >= 1; i--) {
		// Traverser chacun des mots de la liste. À chaque passe on raccourcit
		// le prochain de 1 mot.
		//printf("i: %d\n", i);
		for (int j = 0; j < i; j++) {
			// Comparer chaque paire de mots consécutifs. Si deux mots ne sont
			// pas en ordre, on les permutte.	
			if (words_being_sorted[j] > words_being_sorted[j+1]) {
				temp_word = words_being_sorted[j];
				words_being_sorted[j] = words_being_sorted[j+1];
				words_being_sorted[j+1] = temp_word;
			}
		}
	}


	// Affichage après tri
	/*

	À compléter

	*/
	printf("Sorted data output (ascending):\n");
	for (int i = 0; i < counter; i += 4) {
		printf("%d: %u %u %u %u\n", counter, ptr[i], ptr[i + 1], ptr[i + 2], ptr[i + 3]);
	}
}
