using namespace std; 
#include "noeud.cpp"
#include <vector>
#include "formule.cpp"

class fonctionnement{

public:

//Constructor
	fonctionnement(vector<noeud> vect); 

//Destructor
	~fonctionnement();
	
//Fonctions
	
	//Création d'une fonction 
	vector<noeud> random();
	
	//Lecture de chaque ligne du fichier .csv pour en tirer les booléens 
	vector<bool> StockBool(string line);
	
	//Mise en forme des données recues 
	void lecture();
	
	//Sélection du meilleur mutant  
	formule selection(vector<formule> mutant, int n); 
	
	//Synhtèse et affichage des résultats
	void rendu(); 

	//donne nom aux noeuds pour l'affichage :
  	void nomme_noeuds();
	
protected: 

	vector<noeud>* sac_; 
	int nb_col;
	int nb_lignes;
	vector<vector<bool>> genes_;



}; 
