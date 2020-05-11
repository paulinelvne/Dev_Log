#include <cstddef>

class noeud{

public:
//Constructor
	noeud (noeud* f1, noeud* f2, noeud* m, int val);

//Destructor
	~noeud ();


//Fonctions
	void insertion(int fct, noeud* nd);
    void deletion();
    void remplacement(noeud* nd);
    bool viabilite();


protected:

    noeud* fille1_ = NULL;
    noeud* fille2_ = NULL;
    noeud* mere_ = NULL;
    int valeur_;
	
};