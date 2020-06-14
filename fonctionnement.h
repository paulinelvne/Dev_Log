using namespace std; 
#include "formule.h"
#include <vector>


class fonctionnement{

public:

//Constructor
	fonctionnement(vector<noeud*> vect); 

//Destructor
	~fonctionnement();
	
//Fonctions
	
	//Création d'une fonction 
	vector<noeud> random();
	
	//Lecture de chaque ligne du fichier .csv pour en tirer les booléens 
	vector<bool> StockBool(string line);
	
	//Mise en forme des données recues 
	void lecture(string path_to_the_file);
	
	//Sélection du meilleur mutant  
	formule* selection(vector<formule*> mutant); 
	
	
	

	//donne nom aux noeuds pour l'affichage :
  	void nomme_noeuds();
  	
  	//getter
  	
  	  //sac
  	vector<noeud*> getsac();
  	  //genes
  	vector<vector<bool>> getgenes();
	
protected: 

	vector<noeud*> sac_; 
	int nb_col;
	int nb_ligne;
	vector<vector<bool>> genes_;



}; 
void rendu(formule* mutant);
