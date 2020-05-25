#include "noeud.h"
#include <experimental/random>

//Constructor
noeud::noeud(noeud* f1, noeud* f2, noeud* m, int val, int id){
    //Dans un premier temps, le soin de l'identitfiant est laissé à l'utilisateur de la classe
    //Définition des attributs avec les objets entrés en paramètre
    fille1_ = f1;
    fille2_ = f2;
    mere_ = m;
    valeur_ = val;
    id_ = id;

    // //Attribution de la fonction AND, OR ou NOT en fonction de la valeur entrée en numérique
    // //AND sera 3, OR sera 4, NOT sera 5
    // switch(valeur_) {
    //     case 3:
    //         str_ = "x1 AND x2";
    //     break;
    //     case 4:
    //         str_ = "x1 OR x2";
    //     break;
    //     case 5:
    //         str_ = "NOT x1";
    //     break;
    //     default:
    //         str_ = "pas de valeur de fonction";
    // }
    //NOUVELLE FONCTION


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
    //on vérifie que la fille existe bien, sinon elle n'a pas de id_
    //renvoie l'id de la mère si elle existe et sinon renvoie 0
    if(fille1_ == NULL){
        return 0;
    }
    else{
        return fille1_->id_;
    }
    
};

int noeud::read_id_fille2(){
    //on vérifie que la fille existe bien, sinon elle n'a pas de id_
    //renvoie l'id de la mère si elle existe et sinon renvoie 0
    if(fille2_ == NULL){
        return 0;
    }
    else{
        return fille2_-> id_;
    }
};
    
int noeud::read_id_mere(){
    //on vérifie que la mère existe bien, sinon elle n'a pas de id_
    //renvoie l'id de la mère si elle existe et sinon renvoie 0
    if(mere_ == NULL){
        return 0;
    }
    else{
        return mere_-> id_;
    }
};

noeud* noeud::read_fille1(){
    //renvoie l'adresse occupée par la fille
    return fille1_;
};

noeud* noeud::read_fille2(){
    //renvoie l'adresse occupée par la fille
    return fille2_;
};

noeud* noeud::read_mere(){
    //renvoie l'adresse occupée par la mere
    return mere_;
};


int noeud::read_id(){
    //renvoie l'id du noeud
    return id_;
};
    
std::string noeud::read_str(){
    //renvoie la fonction logique
    return str_;
};

void noeud::put_mere(noeud* nd){
    //permet de modifier la mere
    if(mere_ != NULL){
            if(mere_->fille1_->id_ == id_){ //on regarde sur quelle branche 1 ou 2 de la mère se trouve le noeud
                mere_->fille1_ = NULL; //réattribution de la nouvelle fille à la mère si le noeud présent était sa fille1
            }
            else{
                mere_->fille2_ = NULL; //réattribution de la nouvelle fille à la mère si le noeud présent était sa fille2
            }
        }

    mere_ = nd;

    if(nd->fille1_ == NULL){
        nd->fille1_ = this;
    }
    else{
        nd->fille2_ = this;
    }
};
   
void noeud::put_fille1(noeud* nd){
    //permet de modifier la fille1

    if(fille1_ != NULL){
        fille1_->mere_ = NULL;
    }

    fille1_ = nd;

    nd->mere_ = this;

};
    
void noeud::put_fille2(noeud* nd){
    //permet de modifier la fille2
    if(fille2_ != NULL){
        fille2_->mere_ = NULL;
    }

    fille2_ = nd;

    nd->mere_ = this;
};
    
void noeud::put_valeur(int val){
    //permet de modifier la valeur de la fonction logique du noeud
    valeur_ = val;

    //modifie alors automatiquement l'attribut str_ avec la bonne fonction logique
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

void noeud::put_str(std::string str){
    str_ = str; //permet de modifier le str pour ensuite pour avoir la chaine de fonction logique
};

void noeud::put_id(int id){
    //permet de modifier l'identifiant
    id_ = id;
};

//Opérateur




//Fonctions
void noeud::insertion(noeud* nd){

    //vérification que le noeud mère existe sinon la fille n'existe pas
    if(mere_ != NULL){
        if(mere_->fille1_->id_ == id_){ //on regarde sur quelle branche 1 ou 2 de la mère se trouve le noeud
            mere_->fille1_ = nd; //réattribution de la nouvelle fille à la mère si le noeud présent était sa fille1
        }
        else{
            mere_->fille2_ = nd; //réattribution de la nouvelle fille à la mère si le noeud présent était sa fille2
        }
    }
    
    nd->mere_ = mere_; //la mère de nd devient alors la mère du noeud présent
    mere_ = nd; //nd devient la mère du noeud présent

    if(nd->fille1_ == NULL){ //par défaut si nd n'a pas de fille1, le noeud présent deviendra sa fille1
        nd->fille1_ = this;
    }
    else{
        nd->fille2_ = this; //sinon ca sera sa fille2
    }  

};

void noeud::deletion(){
    if(mere_ != NULL){ //si la mere existe bien, il faut mettre sa fille à jour
        if(mere_->fille1_->id_ == id_){
        mere_->fille1_ = NULL; //si c'est la fille1, on la supprime donc
        }
        else{
            mere_->fille2_ = NULL; //sinon on supprime la fille2
        }
    }

    fille1_ = NULL; //on met tous les paramètres à NULL au noeud présent car il est supprimé
    fille2_ = NULL;
    mere_ = NULL;
};

void noeud::remplacement(noeud* nd){
    nd->mere_ = mere_; //on définit la mère et les filles de nd comme celles du noeud présent
    nd->fille1_ = fille1_;
    nd->fille2_ = fille2_;

    if(mere_ != NULL){ //si le noeud présent a effectivement une mère
        if(mere_->fille1_->id_ == id_){ //on regarde si le noeud présent est sa fille1 ou 2
            mere_->fille1_ = nd; //si c'est la fille1, on la redéfinit en tant que nd
        }
        else{
            mere_->fille2_ = nd; //sinon, c'est la fille2 et dans ce cas c'est elle qui l'on redéfinit en tant que nd
        }
    }

    fille1_ = NULL; //le noeud présent est retiré, il n'a donc plus de mère ni de filles
    fille2_ = NULL;
    mere_ = NULL;
};

void noeud::mute(noeud* nd){
    int rd = std::experimental::randint(1,3); //on tire au hasard un nombre entre 1 et 3
    
    //ici on choisit que 1 sera l'insertion, 2 le remplacement et 3 la délétion
    switch(rd) {
        case 1:
            this->insertion(nd);
        break;
        case 2:
            this->remplacement(nd);
        break;
        case 3:
            this->deletion();
        break;
        //default:
            
    }
};

bool noeud::viabilite(){
    if(valeur_ == 3 || valeur_ == 4){ //si on a un AND ou un OR, 
        if(fille1_ != NULL && fille2_ != NULL){ //il est nécessaire d'y avoir deux filles pour que la fonction soit correcte
            return true;
        }
        else{
            return false;
        }
    }
    else if(valeur_ == 5){ //Par ailleurs, si l'on a un NOT,
        if(fille1_ != NULL && fille2_ != NULL){ //Dans ce cas, si le noeud a deux filles, ce ne sera pas correct
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
