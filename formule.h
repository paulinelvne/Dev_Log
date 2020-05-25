#include <vector>
#include "noeud.h"
#include <string>
#ifndef DEF_formule
#define DEF_formule


class formule
{


private:
	std::vector<noeud*> contenu_;
	int fitness_;
protected:

public:
	formule();
	formule(std::vector<noeud*> contenu, int fit);
	formule(formule & autre);
	~formule();
	int fitness();
	int nbr_mutation();
	void select_aleatoire();
	int formule_globale();
	std::string formule_globale_str();
	void select_mutants(float taux_mut);
	

	
friend int transforme(int xA, int ope, int xB);
friend std::string transforme_str(noeud* xA, noeud* ope, noeud* xB=NULL);

};
#endif
