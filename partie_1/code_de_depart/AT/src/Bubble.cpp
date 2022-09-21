///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include <Bubble.h>


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
}


///////////////////////////////////////////////////////////////////////////////
//
//	Interface avec le module Reader
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::interface(void)
{
	unsigned int ReadData;
	/*
	
	À compléter
	
	*/
	address.write(true);
	request.write(true);
	while (!ack.read());
	ReadData = data.read();
	request.write(false);

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
	while (counter != 0)
	{
		uint32_t uiSmallestData = ptr[uiSmallestIndex];
		wait(clk.posedge_event());

		for (int i = uiSmallestIndex; i < uiFinalCounter; i++)
		{
			if (uiSmallestData > ptr[i])
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
