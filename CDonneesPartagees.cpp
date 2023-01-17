#include <pthread.h>
#include <semaphore.h>
#include "CDonneesPartagees.h"

CDonneesPartagees::CDonneesPartagees()
{
	sens = 1;
	vitesse = 1000;
	fin = false;
	pthread_mutex_init(&mutexVariablesPartagees, NULL);
	
}
CDonneesPartagees::~CDonneesPartagees()
{
	pthread_mutex_destroy(&mutexVariablesPartagees);
	
}

void CDonneesPartagees::changeSens()
{
	pthread_mutex_lock(&mutexVariablesPartagees);
	sens = -sens;
	pthread_mutex_unlock(&mutexVariablesPartagees);
}
void CDonneesPartagees::moinsVite()
{
	pthread_mutex_lock(&mutexVariablesPartagees);
	vitesse =  vitesse + 100 ;
	pthread_mutex_unlock(&mutexVariablesPartagees);
}
void CDonneesPartagees::plusVite()
{
	pthread_mutex_lock(&mutexVariablesPartagees);
	vitesse = vitesse -100;
	if (vitesse < 100) vitesse = 100;
	pthread_mutex_unlock(&mutexVariablesPartagees);
}
int CDonneesPartagees::litSens()
{
	int result;
	pthread_mutex_lock(&mutexVariablesPartagees);
	result = sens; // qd on le lit il n'est pas en cours de mise a jour
	pthread_mutex_unlock(&mutexVariablesPartagees);
	return result;
}
int CDonneesPartagees::litVitesse()
{
	int result;
	pthread_mutex_lock(&mutexVariablesPartagees);
	result=vitesse; // qd on la lit elle n'est pas en cours de mise a jour
	pthread_mutex_unlock(&mutexVariablesPartagees);
	return result;
}
void CDonneesPartagees::setFin(bool valfin)
{
	fin = valfin;
}
bool CDonneesPartagees::litFin()
{
	return fin;
}

