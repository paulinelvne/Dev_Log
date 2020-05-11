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
    //je n'ai pas trouvé comment dire au noeud du dessus que this est supprimé 
    //Peut être rajouté une valeur_ genre 6 ou ca serait le vide
    //Ouais mais non ca ne marcherait pas non plus 
    //Je réfléchis
    //J'ai peut être trouvé, je pense qu'il faut quand même qu'on en parle

    if(mere_->fille1_ == this){
        mere_->fille1_ = NULL;
    }
    else{
        mere_->fille2_ = NULL;
    }

    fille1_ = NULL;
    fille2_ = NULL;
    mere_ = NULL;
};

void noeud::remplacement(noeud* nd){
    fille1_ = nd->fille1_;
    fille2_ = nd->fille2_;
    mere_ = nd->mere_;
    valeur_ = nd->valeur_;
};

bool noeud::viabilite(){
    if(valeur_ == 3 || valeur_ == 4){
        if(fille1_ != NULL && fille2_ != NULL){
            return true;
        }
        else{
            return false;
        }
    }
    else if(valeur_ == 5){
        if(fille1_ != NULL && fille2_ != NULL){
            return false;
        }
        else{
            return true;
        }
    }

    else{
        return false;
    }
};


//Dans cette version, AND sera 3, OR sera 4, NOT sera 5