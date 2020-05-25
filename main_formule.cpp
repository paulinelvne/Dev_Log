#include "formule.cpp"
#include <iostream>
#include <vector>

int main(){
	noeud* noeud3 = new noeud(NULL, NULL, NULL, 4, 140);
	noeud* noeud1 = new noeud(NULL, NULL, NULL , 1, 133);
	noeud* noeud2 = new noeud(NULL, NULL, NULL, 0, 134);
	noeud2->put_mere(noeud3);
	//noeud1->put_mere(noeud3);
	//noeud3->put_fille1(noeud1);
	noeud3->put_fille2(noeud2);
	std::vector<noeud*> content = {noeud2, noeud3};
	formule* f = new formule(content, 1000);
	//f->formule_globale();
	//int a = transforme(1, 3, 1);
	std::cout<< "t" << transforme_str(noeud2, noeud3) << std::endl ;
	std::cout<< f->formule_globale_str() << std::endl ;

	//delete f;
	//delete noeud3;
	//delete noeud2;
	//delete noeud1;

	return(0);
}