#include <pthread.h>
#include <semaphore.h>
#include <wiringPi.h>
#include <iostream>
using namespace std;
#include "CDonneesPartagees.h"
#include "CPiface.h"
#include "lesThreads.h"

int main(int argc, char *argv []){
	//CChenillard monChenillard;
	cout << " chenillard commande par clavier et / ou boutons\n";
	CDonneesPartagees DonneesPartagees;
	CPiface maPiface;
	int* pointeurs[2]; 
	pointeurs[0] =(int *) &DonneesPartagees;
	pointeurs[1] = (int *)&maPiface;
	pthread_t thClavier;
	pthread_t thBoutons;

	cout << "chenillard initialise vers la gauche ";
	cout << "avec une vitesse de 1000 msec\n";
	cout << "Vous pouvez modifier son fonctionnement avec les 4 boutons:\n";
	cout << "Bouton 1: plus rapide - limite 50 msec\n";
	cout << "Bouton 2: plus lent - limite 5000 msec\n";
	cout << "Bouton 3: on change de sens\n";
	cout << "Bouton 4: on arrête le chenillard\n";

	// création du thread qui gère les boutons et lancement :
	//  - paramètre 1 : l'adresse de l'objet thread
	//  - paramètre 2 : des attributs pour un comportement spécifique (NULL ici)
	//  - paramètre 3 : le nom de la fonction thread
	//  - paramètre 4 : un paramètre passé à la fonction thread
			
	int ret = pthread_create(&thBoutons, NULL, thread_gestion_boutons, pointeurs);
	if (ret)
	{
		cout << "Error - pthread_create() return code : " << ret << endl;
	}
	cout << "Vous pouvez aussi modifier son fonctionnement avec le clavier:\n";
	cout << "touche 1: plus rapide - limite 50 msec\n";
	cout << "touche 2: plus lent - limite 5000 msec\n";
	cout << "touche 3: on change de sens\n";
	cout << "touche 4: on arrête le chenillard\n";
	
	// thread principal - le chenillard
	
	int numLed = 1;
	int mavitesse=1000;
	int monsens=1;
	do 
	{
			mavitesse = DonneesPartagees.litVitesse();
			maPiface.AllumerLed(numLed);
			delay(mavitesse);
			maPiface.EteindreLed(numLed);
			if (monsens > 0)
				numLed = (numLed == 8) ? 1 : numLed + monsens;
			else
				numLed = (numLed == 1) ? 8 : numLed + monsens;
	} while (DonneesPartagees.litFin()!=true);
	
	pthread_join(thBoutons, NULL);    // on attend que le thread des boutons soit arrêté
	pthread_join(thClavier, NULL); // on attend la fin du thread clavier
	
	return 0;
}

