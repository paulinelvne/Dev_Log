#include "formule.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include <string>

int main(){
	//std::vector<int> v(3,3);
	std::vector<int> vect1{3,3};
    std::vector<int> vect2{4,4};
    std::vector<int> vect3{0,0};
    std::vector<int> vect4{1,1};
    std::vector<int> vect5{5,5};
    std::vector<int> vect6{1,1};
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect4, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, vect5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect6, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, vect2, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, vect6, 139); //x1
    noeud* noeud9 = new noeud(NULL, NULL, NULL, vect5, 141); //NOT

    noeud2->put_mere(noeud1);
    noeud5->put_mere(noeud1);
    noeud3->put_mere(noeud2);
    noeud4->put_mere(noeud2);
    noeud6->put_mere(noeud5);
    noeud1->put_mere(noeud7);
    noeud8->put_mere(noeud7);
    noeud7->put_mere(noeud9);

    noeud1->put_str("AND");
    noeud2->put_str("OR");
    noeud3->put_str("x1");
    noeud4->put_str("x2");
    noeud5->put_str("NOT");
    noeud6->put_str("x1");
    noeud5->put_str("NOT");
    noeud6->put_str("x1");
    noeud7->put_str("OR");
    noeud8->put_str("x1");
    noeud9->put_str("NOT");
    std::vector<noeud*> content = {noeud1, noeud2, noeud3, noeud4, noeud5, noeud6, noeud7, noeud8, noeud9};
    formule* f = new formule(content, 1000);
	//int a = transforme(1, 3, 1);
	//std::cout<< "t" << transforme_str(noeud2, noeud3, noeud1) << std::endl ;
	//std::cout<< (((content[0]->read_mere()))->read_valeur(0)==5) << std::endl;
	
	std::cout<< f->retourne_tous_noeuds() << std::endl ;

	//delete f;
	//delete noeud3;
	//delete noeud2;
	//delete noeud1;


    std::string const nomFichier("D:/Dev_log/Projet/Dev_Log/f_noeuds.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)    
    {
        monFlux << f->retourne_tous_noeuds() << std::endl;

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }

    std::string const nomFichier2("D:/Dev_log/Projet/Dev_Log/f_edges.txt");
    std::ofstream monFlux2(nomFichier2.c_str());

    if(monFlux)    
    {
        monFlux2 << f->retourne_liste_noeuds() << std::endl;

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
  
	return(0);
}