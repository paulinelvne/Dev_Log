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
	int formule_globale(int w);
	std::string formule_globale_str(int w);
	void select_mutants(float taux_mut);
	std::string retourne_liste_noeuds();
	std::string retourne_tous_noeuds();
	void add_fitness(int ft);
	int get_fitness();
	void operator=(formule f);

	
friend int transforme(int xA, int ope, int xB);
friend std::string transforme_str(noeud* xA, noeud* ope, noeud* xB=NULL, int w=0);

};
int fitness(formule* X, noeud* Y, int n);
#endif
