#include <cstddef>
#include <string>

class noeud{

public:
//Constructor
	noeud (noeud* f1, noeud* f2, noeud* m, int val, int id);

//Destructor
	~noeud ();

//Affichage
    int read_valeur();
    int read_id_fille1();
    int read_id_fille2();
    int read_id_mere();
    noeud* read_fille1();
    noeud* read_fille2();
    noeud* read_mere();
    int read_id();
    std::string read_str();
    
    void put_mere(noeud* nd);
    void put_fille1(noeud* nd);
    void put_fille2(noeud* nd);
    void put_valeur(int val);
    void put_id(int id);
    void put_str(std::string str);
    

//Fonctions
	void insertion(int fct, noeud* nd);
    void deletion();
    void remplacement(noeud* nd);
    bool viabilite();

//Opérateurs



protected:

    noeud* fille1_ = NULL;
    noeud* fille2_ = NULL;
    noeud* mere_ = NULL;
    int valeur_;
    std::string str_;
    int id_;
	
};