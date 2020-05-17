#pragma once
#include "noeud.h"


using namespace std;

class Formule
{
private:
	noeud contenu_;
	int fitness_;
protected:

public:
	int fitness();
	int nbr_mutation();
	void select_aleatoire();
	bool formule_globale();
	
friend bool transforme(int xA, int ope, int xB);
};
