#include "noeud.h"

//Constructor
noeud::noeud(noeud* f1, noeud* f2, noeud* m, int val, int id){
    //Dans un premier temps, le soin de l'identitfiant est laissé à l'utilisateur de la classe
    fille1_ = f1;
    fille2_ = f2;
    mere_ = m;
    valeur_ = val;
    id_ = id;

    switch(valeur_) {
        case 3:
            str_ = "x1 AND x2";
        break;
        case 4:
            str_ = "x1 OR x2";
        break;
        case 5:
            str_ = "NOT x1";
        break;
        default:
            str_ = "pas de valeur de fonction";
}


};


//Destructeur
noeud::~noeud(){
    delete this->fille1_;
    delete this->fille2_;
    delete this->mere_;
    
};

//Affichage
int noeud::read_valeur(){
    return this->valeur_;
};

int noeud::read_id_fille1(){
    if(fille1_ == NULL){
        return 0;
    }
    else{
        return fille1_->id_;
    }
    
};

int noeud::read_id_fille2(){
    if(fille2_ == NULL){
        return 0;
    }
    else{
        return fille2_-> id_;
    }
};
    
int noeud::read_id_mere(){
    if(mere_ == NULL){
        return 0;
    }
    else{
        return mere_-> id_;
    }
};

noeud* noeud::read_fille1(){
    return fille1_;
};

noeud* noeud::read_fille2(){
    return fille2_;
};

noeud* noeud::read_mere(){
    return mere_;
};


int noeud::read_id(){
    return id_;
};
    
std::string noeud::read_str(){
    return str_;
};

void noeud::put_mere(noeud* nd){
    mere_ = nd;
};
   
void noeud::put_fille1(noeud* nd){
    fille1_ = nd;
};
    
void noeud::put_fille2(noeud* nd){
    fille2_ = nd;
};
    
void noeud::put_valeur(int val){
    valeur_ = val;
};

void noeud::put_id(int id){
    id_ = id;
};
    
void noeud::put_str(std::string str){
    str_ = str;
};

//Opérateur




//Fonctions
void noeud::insertion(int fct, noeud* nd){

    //reactualisation du noeud présent
    if(mere_ != NULL){
        if(mere_->fille1_->id_ == id_){
            mere_->fille1_ = nd;
        }
        else{
            mere_->fille2_ = nd;
        }
    }
    
    nd->mere_ = mere_;
    mere_ = nd;

    if(nd->fille1_ == NULL){
        nd->fille1_ = this;
    }
    else{
        nd->fille2_ = this;
    }  

};

void noeud::deletion(){
    if(mere_ != NULL){
        if(mere_->fille1_->id_ == id_){
        mere_->fille1_ = NULL;
        }
        else{
            mere_->fille2_ = NULL;
        }
    }

    fille1_ = NULL;
    fille2_ = NULL;
    mere_ = NULL;
};

void noeud::remplacement(noeud* nd){
    nd->mere_ = mere_;
    nd->fille1_ = fille1_;
    nd->fille2_ = fille2_;

    if(mere_ != NULL){
        if(mere_->fille1_->id_ == id_){
            mere_->fille1_ = nd;
        }
        else{
            mere_->fille2_ = nd;
        }
    }

    fille1_ = NULL;
    fille2_ = NULL;
    mere_ = NULL;
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