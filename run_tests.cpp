#include "gtest/gtest.h"
#include "formule.cpp"
//--------------------------------------------------------------------------------------------------------------------
//                                       Tests de la classe formule
//-------------------------------------------------------------------------------------------------------------

// Fonction Amie Transforme
TEST(transforme, AND) 
{
    EXPECT_EQ(transforme(1, 3, 1), 1);
    EXPECT_EQ(transforme(1, 3, 0), 0);
    EXPECT_EQ(transforme(0, 3, 0), 0);
    EXPECT_EQ(transforme(0, 3, 1), 0);

}

TEST(transforme, OR) 
{
    EXPECT_EQ(transforme(1, 4, 1), 1);
    EXPECT_EQ(transforme(0, 4, 1), 1);
    EXPECT_EQ(transforme(1, 4, 0), 1);
    EXPECT_EQ(transforme(0, 4, 0), 0);
}
TEST(transforme, NOT) 
{
    EXPECT_EQ(transforme(1, 1), 0);
    EXPECT_EQ(transforme(0, 1), 1);
}

//Fonction amie Transforme_str

TEST(transforme_str, AND) 
{
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 3, 140);
    noeud* noeud1 = new noeud(NULL, NULL, NULL , 1, 133);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, 0, 134);
    noeud3->put_str("AND");
    noeud2->put_str("x1");
    noeud1->put_str("x2");
    EXPECT_EQ(transforme_str(noeud2, noeud3, noeud1)=="(x1ANDx2)", 1);

}

TEST(transforme_str, OR) 
{
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 4, 140);
    noeud* noeud1 = new noeud(NULL, NULL, NULL , 1, 133);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, 0, 134);
    noeud3->put_str("OR");
    noeud2->put_str("x1");
    noeud1->put_str("x2");
    EXPECT_EQ(transforme_str(noeud2, noeud3, noeud1)=="(x1ORx2)", 1);

}
TEST(transforme_str, NOT) 
{
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 3, 140);
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 1, 133);
    noeud3->put_str("NOT");
    noeud2->put_str("x1");
    EXPECT_EQ(transforme_str(noeud2, noeud3)=="(NOTx1)", 1);}

// fonction_globale_str


TEST(formule_globale_str, test1)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 0, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 1, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, 5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 0, 137); //x1

    noeud2->put_mere(noeud1);
    noeud5->put_mere(noeud1);
    noeud3->put_mere(noeud2);
    noeud4->put_mere(noeud2);
    noeud6->put_mere(noeud5);

    noeud1->put_str("AND");
    noeud2->put_str("OR");
    noeud3->put_str("x1");
    noeud4->put_str("x2");
    noeud5->put_str("NOT");
    noeud6->put_str("x1");
    std::vector<noeud*> content = {noeud1, noeud2, noeud3, noeud4, noeud5, noeud6};
    formule* f = new formule(content, 1000);
    EXPECT_EQ(f->formule_globale_str()=="((x1ORx2)AND(NOTx1))", 1);

}

TEST(formule_globale_str, test2)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 0, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 1, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, 5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 0, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, 4, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, 0, 139); //x1


    noeud2->put_mere(noeud1);
    noeud5->put_mere(noeud1);
    noeud3->put_mere(noeud2);
    noeud4->put_mere(noeud2);
    noeud6->put_mere(noeud5);
    noeud1->put_mere(noeud7);
    noeud8->put_mere(noeud7);

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
    std::vector<noeud*> content = {noeud1, noeud2, noeud3, noeud4, noeud5, noeud6, noeud7, noeud8};
    formule* f = new formule(content, 1000);
    EXPECT_EQ(f->formule_globale_str()=="(x1OR((x1ORx2)AND(NOTx1)))", 1);

}

TEST(formule_globale_str, test3)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 0, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 1, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, 5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 0, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, 4, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, 0, 139); //x1
    noeud* noeud9 = new noeud(NULL, NULL, NULL, 5, 141); //NOT

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
    EXPECT_EQ(f->formule_globale_str()=="(NOT(x1OR((x1ORx2)AND(NOTx1))))", 1);

}

TEST(formule_globale, test1)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 0, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 1, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, 5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 0, 137); //x1

    noeud2->put_mere(noeud1);
    noeud5->put_mere(noeud1);
    noeud3->put_mere(noeud2);
    noeud4->put_mere(noeud2);
    noeud6->put_mere(noeud5);

    noeud1->put_str("AND");
    noeud2->put_str("OR");
    noeud3->put_str("x1");
    noeud4->put_str("x2");
    noeud5->put_str("NOT");
    noeud6->put_str("x1");
    std::vector<noeud*> content = {noeud1, noeud2, noeud3, noeud4, noeud5, noeud6};
    formule* f = new formule(content, 1000);
    EXPECT_EQ(f->formule_globale(), 1);

}

TEST(formule_globale, test2)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 0, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 1, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, 5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 0, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, 4, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, 0, 139); //x1


    noeud2->put_mere(noeud1);
    noeud5->put_mere(noeud1);
    noeud3->put_mere(noeud2);
    noeud4->put_mere(noeud2);
    noeud6->put_mere(noeud5);
    noeud1->put_mere(noeud7);
    noeud8->put_mere(noeud7);

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
    std::vector<noeud*> content = {noeud1, noeud2, noeud3, noeud4, noeud5, noeud6, noeud7, noeud8};
    formule* f = new formule(content, 1000);
    EXPECT_EQ(f->formule_globale(), 1);
}



TEST(formule_globale, test3)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 0, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 1, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, 5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 0, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, 4, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, 0, 139); //x1
    noeud* noeud9 = new noeud(NULL, NULL, NULL, 5, 141); //NOT

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
    EXPECT_EQ(f->formule_globale(), 0);

}


TEST(formule_globale, test4)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 0, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 1, 135); //x2
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 0, 137); //x1

    noeud2->put_mere(noeud1);
    noeud3->put_mere(noeud2);
    noeud4->put_mere(noeud2);
    noeud6->put_mere(noeud1);

    noeud1->put_str("AND");
    noeud2->put_str("OR");
    noeud3->put_str("x1");
    noeud4->put_str("x2");
    noeud6->put_str("x1");
    std::vector<noeud*> content = {noeud1, noeud2, noeud3, noeud4, noeud6};
    formule* f = new formule(content, 1000);
    EXPECT_EQ(f->formule_globale(), 0);

}

TEST(formule_globale, test5)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 1, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 1, 135); //x2
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 1, 137); //x1

    noeud2->put_mere(noeud1);
    noeud3->put_mere(noeud2);
    noeud4->put_mere(noeud2);
    noeud6->put_mere(noeud1);

    noeud1->put_str("AND");
    noeud2->put_str("OR");
    noeud3->put_str("x1");
    noeud4->put_str("x2");
    noeud6->put_str("x1");
    std::vector<noeud*> content = {noeud1, noeud2, noeud3, noeud4, noeud6};
    formule* f = new formule(content, 1000);
    EXPECT_EQ(f->formule_globale(), 1);

}

TEST(formule_globale, test6)
{
    noeud* noeud1 = new noeud(NULL, NULL, NULL, 3, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , 4, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, 1, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, 0, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, 5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, 0, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, 4, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, 1, 139); //x1
    noeud* noeud9 = new noeud(NULL, NULL, NULL, 5, 141); //NOT

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
    EXPECT_EQ(f->formule_globale(), 0);

}