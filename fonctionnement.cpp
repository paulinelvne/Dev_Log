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
vector<noeud> fonctionnement::random(){


return sac_;


}

//Lecture et stockage de chaque ligne du .csv

vector<bool> fonctionnement::StockBool(string line){
	int i = 0;
	int T_string=0;
	while(line[i]!= '\0'){
		T_string ++;
		i++;
	}
	vector<bool> ret;
	int compteur = 0;
	for(int j=23;j<T_string;j++){
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
/*formule fonctionnement::selection(){





}*/

//Rendu 
void fonctionnement::rendu(){





}; 
