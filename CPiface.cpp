#include "CPiface.h"
#define PIFACE 200
CPiface::CPiface()
{
	init(PIFACE);
	InitPullUp();

}
CPiface::~CPiface()
{

}

void CPiface::init(unsigned int nb)
{
	cout << "Raspberry PiFace chenillard\n"
		<< "======================\n";
	wiringPiSetupSys();
	piFaceSetup(nb);
}

void CPiface::InitPullUp()
{
	for (int i = 1; i <= 4; i++)// 4 entrees boutons en pull up - repos = etat haut
	{
		pullUpDnControl(PIFACE - 1 + i, PUD_UP);
	}
}

void CPiface::AllumerLed(unsigned int numLed)
{
	if (numLed >= 1 && numLed <= 8)
	{
		digitalWrite((numLed - 1 + PIFACE), HIGH);
	}
}

void CPiface::EteindreLed(unsigned int numLed)
{
	if (numLed >= 1 && numLed <= 8)
	{
		digitalWrite((numLed - 1 + PIFACE), LOW);
	}
}
 
void CPiface::RazLed() {
	for (int i = PIFACE; i <= PIFACE + 7; i++) {
		digitalWrite(i, LOW);
	}
}
void CPiface::AllLed() {
	for (int i = PIFACE; i <= PIFACE + 7; i++) {
		digitalWrite(i, HIGH);
	}
}

int CPiface::TestBouton()
{
	int numBouton = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (digitalRead(PIFACE - 1 + i) == LOW) numBouton = i;
	}
	delay(200); // pour éviter le rebond 
	return numBouton;
}
