using namespace std; 
#include "noeud.cpp"
#include <vector>
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
	//formule selection(); 
	
	//Synhtèse et affichage des résultats
	void rendu(); 

protected: 

	vector<noeud> sac_; 
	vector<vector<bool>> genes_;



}; 
