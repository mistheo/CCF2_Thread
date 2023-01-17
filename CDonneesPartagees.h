#pragma once

class CDonneesPartagees
{
public:
	CDonneesPartagees();
	~CDonneesPartagees();

	pthread_mutex_t mutexVariablesPartagees;
	void changeSens();
	void plusVite();
	void moinsVite();
	int litSens();
	int litVitesse();
	void setFin(bool);
	bool litFin();
private:
	int sens;
	int vitesse;
	bool fin;
};

