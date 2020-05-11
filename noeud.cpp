#include "noeud.h"

//Constructor
noeud::noeud(noeud* f1, noeud* f2, noeud* m, int val){
    fille1_ = f1;
    fille2_ = f2;
    mere_ = m;
    valeur_ = val;

};


//Destructeur
noeud::~noeud(){
    delete this->fille1_;
    delete this->fille2_;
    delete this->mere_;
    
};

void noeud::insertion(int fct, noeud* nd){

    //creation du nouveau noeud dans l'insertion
    noeud new_noeud(this, nd, mere_, fct);
    //new_noeud(this, nd, mere_, fct);

    //reactulisation du noeud présent
    *mere_ = new_noeud;

};

void noeud::deletion(){
    //il faut que je trouve comment je pointe sur aucun noeud
};

void noeud::remplacement(noeud* nd){
    fille1_ = nd->fille1_;
    fille2_ = nd->fille2_;
    mere_ = nd->mere_;
    valeur_ = nd->valeur_;
};

bool noeud::viabilite(){
    return true;
};


//Dans cette version, AND sera 3, OR sera 4, NOT sera 5