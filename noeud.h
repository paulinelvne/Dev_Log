#include <cstddef>
#include <string>
#include <vector>
#ifndef DEF_noeud
#define DEF_noeud

class noeud{

public:
//Constructor
	noeud (noeud* f1, noeud* f2, noeud* m, std::vector<int> val, int id);

//Destructor
	~noeud ();

//Affichage
    int read_valeur(int i);
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
    void put_valeur(int val, int n);
    void put_str(std::string str);
    void put_id(int id);
    

//Fonctions
	void insertion(noeud* nd);
    void deletion();
    void remplacement(noeud* nd);
    bool viabilite();
    void mute(noeud* nd);

//Opérateurs
    void operator=(noeud* nd);


protected:

    noeud* fille1_ = NULL;
    noeud* fille2_ = NULL;
    noeud* mere_ = NULL;
    std::vector<int> valeur_;
    std::string str_;
    int id_;
	
};

#endif 