#include"noeud.cpp"
#include<iostream>

int main(){

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

} 