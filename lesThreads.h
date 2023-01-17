#pragma once
// fonction executee par le thread qui gere le clavier 
// recoit en parametre l'adresse de l'objet DonneesPartagees
// qui contient le sens et la vitesse et leurs accesseurs
void* thread_gestion_clavier(void* data);
// fonction executee par le thread qui gere les 4 boutons de la piface 
// recoit en parametre un tableau de 2 adresses: int **
// l'adresse de l'objet DonneesPartagees
// qui contient le sens et la vitesse et leurs accesseurs
// l'adresse de l'objet Piface qui permet d'acceder aux 4 boutons
void* thread_gestion_boutons(void* data);
