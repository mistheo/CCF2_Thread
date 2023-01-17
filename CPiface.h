#pragma once
#include <wiringPi.h>
#include <piFace.h>
#include <iostream>
using namespace std;
class CPiface
{
public:
	CPiface();
	~CPiface();

	// initialisation  avec comme argument PIFACE=200
	void init(unsigned int);
	// Allume la led (parametre numero de la led 1 a 8)
	void AllumerLed(unsigned int);
	// Eteint la led (parametre numero de la led 1 a 8)
	void EteindreLed(unsigned int);
	//allume et eteint successivement les leds de 1 a 8
	// ou inversement selon le sens et la vitesse choisis
	// eteint toutes les led
	void RazLed();
	// allume toutes les led
	void AllLed();
	// initialise les boutons en Pull Up (état de repos = état haut)
	void InitPullUp();
	// teste les 4 boutons en les numerotant de 1 à 4
	// retourne le numero du bouton appuye ou 0 si aucun
	int TestBouton();
	
};

