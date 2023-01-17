#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "CPiface.h"
#include "CDonneesPartagees.h"

void* thread_gestion_boutons(void* data)
{
	int** ptr = (int**)data;
	CDonneesPartagees* ptrDonneesPartagees = (CDonneesPartagees*)ptr[0];
	CPiface* ptr_Piface = (CPiface*)ptr[1];
	int numBouton;
	do
	{
		//tant que pas appuyé
		do
		{
			numBouton = ptr_Piface->TestBouton();
		} while ((ptrDonneesPartagees->litFin() != true) && (numBouton == 0));
		
		switch (numBouton)
		{
		case 0://  c est fini - 
			break;
		case 1: ptrDonneesPartagees->plusVite();
			cout << "plus rapide -" << ptrDonneesPartagees->litVitesse() << endl;
			 break;
		case 2:	ptrDonneesPartagees->moinsVite();
			cout << "plus lent -" << ptrDonneesPartagees->litVitesse() << endl;
			break;
			
		case 3:	ptrDonneesPartagees->changeSens();
				cout << "on change de sens ";
			cout << ((ptrDonneesPartagees->litSens() == 1 )? "Gauche" : "Droite") << endl;
			break;
		case 4:	cout << "on arrête le chenillard PAR LE BOUTON 4\n";
			ptrDonneesPartagees->setFin(true);
			break;
		}

	} while (ptrDonneesPartagees->litFin() != true);

	ptrDonneesPartagees->setFin(true);
	cout << " fin thread boutons\n";
	
	return NULL;
}


