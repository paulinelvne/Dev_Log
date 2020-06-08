#include<iostream>
#include "fonctionnement.h"
#include<vector>
#include <fstream>
#include <vector>
using namespace std; 
#include <stdio.h>
#include <string.h>

//Constructor
fonctionnement::fonctionnement(vector<noeud> vect){
/*	int Taille_vect=vect.size();
	for(int i=0;i<Taille_vect;i++){
	sac_[i]=vect[i]; 
	} 
*/
	sac_=vect;
}

//Fonctions



//Destructeur
fonctionnement::~fonctionnement(){
    delete this-> sac_;

};


//Random
vector<noeud>* fonctionnement::random(int num_column, int taille_formule, vector<vector<bool>> grille)
{
for (int i =0;i<577;i++)
{
  sac_->push_back(noeud(NULL,NULL,NULL,grille[i][num_column], i)) ;//créé et ajoute un noeud sans mère ni fille, dont sa valeur égale celle de la ligne et colonne correspondantes du fichier et d'identifiant égal à sa place dans le sac.
}
    srand (time(NULL)); //init le random
for (int j = 0;j<taille_formule;j++)
{
  int compteur = 577; // taille du sac_
  int identifiant = 577; // num des id des noeuds
  int n1 = rand()%compteur; //pioche entre 0 et le compteur ce qui sera 
  int n2 = rand()%compteur; // pareil, on remarque que n1 peut être égale à n2.
  int val_op = rand()%3 +3; // pioche les valeurs des opérateurs entre 3, 4 et 5.

  noeud nouveau_noeud1(NULL,NULL,NULL,0,0); //init noeud par défaut

  nouveau_noeud1 = sac_[0][n1];
  nouveau_noeud1.put_id(identifiant); // le copie, change mère + id mais ajoute pas au sac !!
  identifiant ++;

  noeud nouveau_noeud2(NULL,NULL,NULL,0,0); //init noeud par défaut
  nouveau_noeud2 = sac_[0][n2]; // le copie, change mère + id mais ajoute pas au sac !!
  nouveau_noeud1.put_id(identifiant); // le copie, change mère + id mais ajoute pas au sac !!
  identifiant ++;

  sac_[0].push_back(noeud(&nouveau_noeud1,&nouveau_noeud2,NULL, val_op, compteur)) ;
  nouveau_noeud1.put_mere(&sac_[0][compteur]);
  nouveau_noeud2.put_mere(&sac_[0][compteur]);

  compteur ++;
}
return sac_;
}

//nomme_noeud
void fonctionnement::nomme_noeuds()
{
  string str = "X";
  for (int i=0;i<577;i++)
  {
    if(sac_[0][i].read_valeur() == 3 )
    {
      sac_[0][i].put_str("AND");
    }
    if(sac_[0][i].read_valeur() == 4 )
    {
      sac_[0][i].put_str("OR");
    }
    if(sac_[0][i].read_valeur() == 5 )
    {
      sac_[0][i].put_str("NOT");
    }
    else
    {
      std::string s = std::to_string(i);
      str = str + s;
    }
  }
}


//Lecture et stockage de chaque ligne du .csv

vector<bool> fonctionnement::StockBool(string line){
	int i = 0;
	int T_string=0;
	while(line[i]!= '\0'){
		T_string ++;
		i++;
	}
	this->nb_ligne =T_string - 23;			//donne le nb de ligne du fichier d'entré, -23 car les 23 premiers caractères sont l'entête des lignes
	vector<bool> ret;
	int compteur = 0;
	for(int j=23;j<T_string;j++){			//j=23 car format en-tête des lignes tjrs égale et de 23 caractères.
        	if(line[j]=='1'){
			ret.push_back(1);
			compteur ++;
		}

		if(line[j]=='0'){
			ret.push_back(0);
			compteur ++;
		}
	}
	cout << compteur<< "   ";
	return ret; 
}

//Lecture
void fonctionnement::lecture(){





}

//Selection
formule fonctionnement::selection(vector<formule> mutant, int n){
	formule best_mutant = mutant[0];
	for(int i = 1; i<=n; i++){
		if(abs(mutant[i].fitness()) < abs(best_mutant.fitness() )){
			best_mutant = mutant[i];
		}
	}
	return best_mutant;
};

//Rendu 
void fonctionnement::rendu(){
ofstream test("Fichier_rendu.txt");		//ouvre le flux : créer le fichier ou bien l'ouvre s'il existe déja
if(test)  //On teste si tout est OK, si le fichier est bien ouvert
{
    test<<"formule du meilleur mutant  : "<<" formule " << endl;	//remplacer formule par la formule obtenue grâce à la fonction formule_globale_str() de la classe formule puis sélection pour prendre la meilleur formule.
    test<<"Fitness du meilleur mutant : " << "fitness" << endl;		//remplacer fitness par la fitness obtenue grâce aux fonction selection et fitness()
}
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
}
}; 
