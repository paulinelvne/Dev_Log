class noeud{

public:
//Constructor
	noeud (noeud* f1, noeud* f2, noeud* m, int val);

//Destructor
	~noeud ();


//Fonctions
	void insertion(int fct, noeud* nd);
    void deletion();
    void remplacement();
    bool viabilite();


protected:

    noeud* fille1_;
    noeud* fille2_;
    noeud* mere_;
    int valeur_;
	
};