#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
#include "CDonneesPartagees.h"


void* thread_gestion_clavier(void* data)
{
	int** ptrTab = (int**)data;
	CDonneesPartagees* ptr_DonneesPartagees = (CDonneesPartagees*)ptrTab[0];
	char touche;
	system("stty -icanon min 1");
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
	
	
	cout << "DANS THREAD CLAVIER" << std::endl;

	do
	{
		touche = getchar();
		switch (touche)
		{
		case '1':  
			ptr_DonneesPartagees->plusVite();
			cout << "plus rapide -" << ptr_DonneesPartagees->litVitesse() << endl;
			break;
		case '2':	ptr_DonneesPartagees->moinsVite();
			cout << "plus lent -" << ptr_DonneesPartagees->litVitesse() << endl; break;

		case '3':	ptr_DonneesPartagees->changeSens();
			cout << "on change de sens ";
			cout << ((ptr_DonneesPartagees->litSens() == 1) ? "Gauche" : "Droite") << endl;
			break;
		case '4':	 cout << "on arrête le chenillard PAR LA TOUCHE 4\n";
			ptr_DonneesPartagees->setFin(true);
			break;
		}

	} while (ptr_DonneesPartagees->litFin()!=true);

	// on sort sur touche 4 
	ptr_DonneesPartagees->setFin(true);
	cout <<  " fin thread clavier\n";
	
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) & ~O_NONBLOCK);
	system("stty icanon min 1");
	return NULL;
}