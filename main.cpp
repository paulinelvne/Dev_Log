#include"noeud.cpp"
#include<iostream>

int main(){
    // test fonction rendu :

    std::vector<int> vect1(1,1);
    std::vector<int> vect2(0,0);
    std::vector<int> vect3(3,3);
    noeud* noeud1 = new noeud(NULL, NULL, NULL , vect1, 133);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 134);
    noeud* noeud3 = new noeud(noeud1, noeud2, NULL, vect3, 140);
    noeud3->put_str("OR");
    noeud2->put_str("x1");
    noeud1->put_str("x2");
    noeud1->put_mere(noeud3);
    noeud2->put_mere(noeud3);
    vector<noeud*> content = {noeud1, noeud2, noeud3};
    formule* f1 = new formule(content, 1200);

    fonctionnement* ff = new fonctionnement(content);


    noeud* noeud1b = new noeud(NULL, NULL, NULL , vect1, 133);
    noeud* noeud2b = new noeud(NULL, NULL, NULL, vect2, 134);
    noeud* noeud3b = new noeud(noeud1b, noeud2b, NULL, vect3, 140);
    noeud3b->put_str("OR");
    noeud2b->put_str("x1");
    noeud1b->put_str("x2");
    noeud1b->put_mere(noeud3b);
    noeud2b->put_mere(noeud3b);
    vector<noeud*> content2 = {noeud1, noeud2, noeud3};
    formule* f2 = new formule(content, 1250);
    vector<formule*> mutant = {f1,f2};
    rendu(ff->selection(mutant));
/*

    std::vector<int> vect1(4,4);
    std::vector<int> vect2(5,5);
    std::vector<int> vect3(3,3);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 2);

    noeud1->insertion(noeud2);
    
    std::cout << noeud1->read_valeur(0) << std::endl;
    std::cout << noeud1->read_id_fille1() << std::endl;
    std::cout << noeud1->read_id_fille2() << std::endl;
    std::cout << noeud1->read_id_mere() << std::endl;
    std::cout << noeud1->read_id() << std::endl;
    std::cout << noeud1->read_str() << std::endl;

    std::cout << std::endl;

    std::cout << noeud1->read_fille1() << std::endl;
    std::cout << noeud1->read_fille2() << std::endl;
    std::cout << noeud1->read_mere() << std::endl;

    std::cout << std::endl;

    std::cout << noeud2->read_valeur(0) << std::endl;
    std::cout << noeud2->read_id_fille1() << std::endl;
    std::cout << noeud2->read_id_fille2() << std::endl;
    std::cout << noeud2->read_id_mere() << std::endl;
    std::cout << noeud2->read_id() << std::endl;
    std::cout << noeud2->read_str() << std::endl;

    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 3);

    noeud1->remplacement(noeud3);

    std::cout << std::endl;

    std::cout << noeud2->viabilite() << std::endl;
    std::cout << noeud3->viabilite() << std::endl;

    std::cout << std::endl;

    std::cout << noeud1->read_valeur(0) << std::endl;
    std::cout << noeud1->read_id_fille1() << std::endl;
    std::cout << noeud1->read_id_fille2() << std::endl;
    std::cout << noeud1->read_id_mere() << std::endl;
    std::cout << noeud1->read_id() << std::endl;
    std::cout << noeud1->read_str() << std::endl;

    std::cout << std::endl;

    std::cout << noeud2->read_valeur(1) << std::endl;
    std::cout << noeud2->read_id_fille1() << std::endl;
    std::cout << noeud2->read_id_fille2() << std::endl;
    std::cout << noeud2->read_id_mere() << std::endl;
    std::cout << noeud2->read_id() << std::endl;
    std::cout << noeud2->read_str() << std::endl;

    std::cout << std::endl;

    std::cout << noeud3->read_valeur(1) << std::endl;
    std::cout << noeud3->read_id_fille1() << std::endl;
    std::cout << noeud3->read_id_fille2() << std::endl;
    std::cout << noeud3->read_id_mere() << std::endl;
    std::cout << noeud3->read_id() << std::endl;
    std::cout << noeud3->read_str() << std::endl;

    noeud3->deletion();

    std::cout << std::endl;

    std::cout << noeud2->read_valeur(1) << std::endl;
    std::cout << noeud2->read_id_fille1() << std::endl;
    std::cout << noeud2->read_id_fille2() << std::endl;
    std::cout << noeud2->read_id_mere() << std::endl;
    std::cout << noeud2->read_id() << std::endl;
    std::cout << noeud2->read_str() << std::endl;

    std::cout << std::endl;

    std::cout << noeud3->read_valeur(0) << std::endl;
    std::cout << noeud3->read_id_fille1() << std::endl;
    std::cout << noeud3->read_id_fille2() << std::endl;
    std::cout << noeud3->read_id_mere() << std::endl;
    std::cout << noeud3->read_id() << std::endl;
    std::cout << noeud3->read_str() << std::endl;

    noeud1->mute(noeud2);

    std::cout << std::endl;

    std::cout << noeud1->read_valeur(0) << std::endl;
    std::cout << noeud1->read_id_fille1() << std::endl;
    std::cout << noeud1->read_id_fille2() << std::endl;
    std::cout << noeud1->read_id_mere() << std::endl;
    std::cout << noeud1->read_id() << std::endl;
    std::cout << noeud1->read_str() << std::endl;

    std::cout << std::endl;

    std::cout << noeud2->read_valeur(0) << std::endl;
    std::cout << noeud2->read_id_fille1() << std::endl;
    std::cout << noeud2->read_id_fille2() << std::endl;
    std::cout << noeud2->read_id_mere() << std::endl;
    std::cout << noeud2->read_id() << std::endl;
    std::cout << noeud2->read_str() << std::endl;

    // delete noeud1;
    // delete noeud2;
    // delete noeud3;
*/
  
} 
