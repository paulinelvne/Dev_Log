#include "gtest/gtest.h"
#include "fonctionnement.cpp"


//--------------------------------------------------------------------------------------------------------------------
//                                       Tests de la classe fonctionnement
//-------------------------------------------------------------------------------------------------------------


//Constructeur
TEST(Constructors,FonctionnementTestConstructor){
	//Initialisation
	    std::vector<int> vect1{1,1};
	    std::vector<int> vect2{0,0};
	    std::vector<int> vect3{3,3};
	    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 140);
	    noeud* noeud1 = new noeud(NULL, NULL, NULL , vect1, 133);
	    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 134);
	    std::vector<noeud*> content = {noeud1, noeud2, noeud3};
	    fonctionnement test(content);
	//Tests
	    EXPECT_TRUE(((test.getsac())[0])->read_valeur(0) == 1);
	    EXPECT_TRUE(((test.getsac())[0])->read_valeur(1) == 1);
	    EXPECT_TRUE(((test.getsac())[1])->read_valeur(0) == 0);
	    EXPECT_TRUE(((test.getsac())[1])->read_valeur(1) == 0);
	    EXPECT_TRUE(((test.getsac())[2])->read_valeur(0) == 3);
	    EXPECT_TRUE(((test.getsac())[2])->read_valeur(1) == 3);
	    EXPECT_TRUE(content == test.getsac());
}

//StockBool

TEST(StockBool,TestStockBool){
	//Initialisation
	    std::vector<int> vect1{1,1};
	    std::vector<int> vect2{0,0};
	    std::vector<int> vect3{3,3};
	    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 140);
	    noeud* noeud1 = new noeud(NULL, NULL, NULL , vect1, 133);
	    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 134);
	    std::vector<noeud*> content = {noeud1, noeud2, noeud3};
	    fonctionnement test(content);
	    string ligne_test_1 = "GTEX-1AYD5-1226-SM-7EWEP,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,0"; 
	    vector<bool> comparaison1 = {0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,0};
	    string ligne_test_2 = "GTEX-NPJ8-0326-SM-2D7VV,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,1,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,1";
	    vector<bool> comparaison2 = {1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,1,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,1};	
	//Tests 
	    EXPECT_TRUE(test.StockBool(ligne_test_1)==comparaison1);
	    EXPECT_TRUE(test.StockBool(ligne_test_2)==comparaison2);
	
}


//lecture
TEST(lecture,Testlecture){
	//Initialisation 
	    std::vector<int> vect1{1,1};
	    std::vector<int> vect2{0,0};
	    std::vector<int> vect3{3,3};
	    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 140);
	    noeud* noeud1 = new noeud(NULL, NULL, NULL , vect1, 133);
	    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 134);
	    std::vector<noeud*> content = {noeud1, noeud2, noeud3};
	    fonctionnement test(content);
	    test.lecture("binary_gene_expression_ACE2_tfs.csv");
	    EXPECT_TRUE(test.getgenes()[0][0]==0);
	    EXPECT_TRUE(test.getgenes()[0][2]==1);
	    EXPECT_TRUE(test.getgenes()[0][3]==0);
	    EXPECT_TRUE(test.getgenes()[3][0]==1);
	    EXPECT_TRUE(test.getgenes()[3][1]==1);
}


//Selection 
TEST(selection,Testselection){
	//Initialisation 
	    std::vector<int> vect1{1,1};
	    std::vector<int> vect2{0,0};
	    std::vector<int> vect3{3,3};
	    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 140);
	    noeud* noeud1 = new noeud(NULL, NULL, NULL , vect1, 133);
	    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 134);
	    std::vector<noeud*> content = {noeud1, noeud2, noeud3};
	    fonctionnement test(content);
	    formule* f1 =new formule(content, 1000);
	    std::cout<<(*f1).get_fitness();
	    formule* f2=new formule(content, 300);
	    formule* f3=new formule(content, 100);
	    std::vector<formule*> VectFormule = {f1, f2, f3};
	    EXPECT_TRUE((*(test.selection(VectFormule))).get_fitness() == 100);
	    EXPECT_TRUE((*(test.selection(VectFormule))) == f3);



}





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
/*
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
    std::vector<int> vect1(1,1);
    std::vector<int> vect2(0,0);
    std::vector<int> vect3(3,3);
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 140);
    noeud* noeud1 = new noeud(NULL, NULL, NULL , vect1, 133);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 134);
    noeud3->put_str("AND");
    noeud2->put_str("x1");
    noeud1->put_str("x2");
    EXPECT_EQ(transforme_str(noeud2, noeud3, noeud1)=="(x1ANDx2)", 1);

}

TEST(transforme_str, OR) 
{
    std::vector<int> vect1(1,1);
    std::vector<int> vect2(0,0);
    std::vector<int> vect3(4,4);
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 140);
    noeud* noeud1 = new noeud(NULL, NULL, NULL , vect1, 133);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 134);
    noeud3->put_str("OR");
    noeud2->put_str("x1");
    noeud1->put_str("x2");
    EXPECT_EQ(transforme_str(noeud2, noeud3, noeud1)=="(x1ORx2)", 1);

}
TEST(transforme_str, NOT) 
{
    std::vector<int> vect1(1,1);
    std::vector<int> vect3(3,3);
   
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 140);
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect1, 133);
    noeud3->put_str("NOT");
    noeud2->put_str("x1");
    EXPECT_EQ(transforme_str(noeud2, noeud3)=="(NOTx1)", 1);}

// fonction_globale_str


TEST(formule_globale_str, test1)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
    noeud* noeud1 = new noeud(NULL, NULL, NULL,vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect4, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, vect5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect6, 137); //x1

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
    EXPECT_EQ(f->formule_globale_str(0)=="((x1ORx2)AND(NOTx1))", 1);

}

TEST(formule_globale_str, test2)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect4, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, vect5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect6, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, vect2, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, vect6, 139); //x1


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
    EXPECT_EQ(f->formule_globale_str(0)=="(x1OR((x1ORx2)AND(NOTx1)))", 1);

}

TEST(formule_globale_str, test3)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
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
    EXPECT_EQ(f->formule_globale_str(0)=="(NOT(x1OR((x1ORx2)AND(NOTx1))))", 1);

}
/*
TEST(formule_globale, test1)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect4, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, vect5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect6, 137); //x1

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
    f->formule_globale(0);
    EXPECT_EQ(1, 1);

}

TEST(formule_globale, test2)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect4, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, vect5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect6, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, vect2, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, vect6, 139); //x1


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
    EXPECT_EQ(f->formule_globale(0), 1);
}



TEST(formule_globale, test3)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect4, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, vect5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect6, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, vect2, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, vect3, 139); //x1
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
    EXPECT_EQ(f->formule_globale(0), 0);

}


TEST(formule_globale, test4)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect4, 135); //x2
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect6, 137); //x1

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
    EXPECT_EQ(f->formule_globale(0), 0);

}

TEST(formule_globale, test5)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect4, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect4, 135); //x2
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect4, 137); //x1

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
    EXPECT_EQ(f->formule_globale(0), 1);

}

TEST(formule_globale, test6)
{
    std::vector<int> vect1(3,3);
    std::vector<int> vect2(4,4);
    std::vector<int> vect3(0,0);
    std::vector<int> vect4(1,1);
    std::vector<int> vect5(5,5);
    std::vector<int> vect6(0,0);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 140); //AND
    noeud* noeud2 = new noeud(NULL, NULL, NULL , vect2, 133); //OR
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect4, 134); //x1
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect3, 135); //x2
    noeud* noeud5 = new noeud(NULL, NULL, NULL, vect5, 136); //NOT
    noeud* noeud6 = new noeud(NULL, NULL, NULL, vect3, 137); //x1
    noeud* noeud7 = new noeud(NULL, NULL, NULL, vect2, 138); //OR
    noeud* noeud8 = new noeud(NULL, NULL, NULL, vect4, 139); //x1
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
    EXPECT_EQ(f->formule_globale(0), 0);

}*/ 
/*

TEST(Constructor, NoeudTestConstructor) {
    std::vector<int> vect1(4,4);
	noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
    EXPECT_TRUE(noeud1->read_valeur(0) == 4);
    EXPECT_TRUE(noeud1->read_id_fille1() == 0);
    EXPECT_TRUE(noeud1->read_id_fille2() == 0);
    EXPECT_TRUE(noeud1->read_id_mere() == 0);
    EXPECT_TRUE(noeud1->read_id() == 1);
    EXPECT_TRUE(noeud1->read_fille1() == NULL);
    EXPECT_TRUE(noeud1->read_fille2() == NULL);
    EXPECT_TRUE(noeud1->read_mere() == NULL);

}

TEST(Insertion, NoeudTestInsertion) {
    std::vector<int> vect1(4,4);
    std::vector<int> vect2(5,5);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 2);

    noeud1->insertion(noeud2);
    
    EXPECT_TRUE(noeud1->read_valeur(0) == 4);
    EXPECT_TRUE(noeud1->read_id_fille1() == 0);
    EXPECT_TRUE(noeud1->read_id_fille2() == 0);
    EXPECT_TRUE(noeud1->read_id_mere() == 2);
    EXPECT_TRUE(noeud1->read_id() == 1);
    EXPECT_TRUE(noeud1->read_fille1() == NULL);
    EXPECT_TRUE(noeud1->read_fille2() == NULL);

    EXPECT_TRUE(noeud2->read_valeur(1) ==  5);
    EXPECT_TRUE(noeud2->read_id_fille1() == 1);
    EXPECT_TRUE(noeud2->read_id_fille2() == 0);
    EXPECT_TRUE(noeud2->read_id_mere() == 0);
    EXPECT_TRUE(noeud2->read_id() == 2);
    EXPECT_TRUE(noeud2->read_mere() == NULL);
    EXPECT_TRUE(noeud2->read_fille2() == NULL);
}

TEST(Viabilite, NoeudTestViabilite) {
    std::vector<int> vect1(4,4);
    std::vector<int> vect2(5,5);
    std::vector<int> vect3(3,3);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 2);

    noeud1->insertion(noeud2);

    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 3);

    noeud1->remplacement(noeud3);

    EXPECT_TRUE(noeud2->viabilite() == 1);
    EXPECT_TRUE(noeud3->viabilite() == 0);
}

TEST(Remplacement, NoeudTestRemplacement) {
    std::vector<int> vect1(4,4);
    std::vector<int> vect2(5,5);
    std::vector<int> vect3(3,3);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 2);

    noeud1->insertion(noeud2);

    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 3);

    noeud1->remplacement(noeud3);

    EXPECT_TRUE(noeud1->read_valeur(0) == 4);
    EXPECT_TRUE(noeud1->read_id_fille1() == 0);
    EXPECT_TRUE(noeud1->read_id_fille2() == 0);
    EXPECT_TRUE(noeud1->read_id_mere() == 0);
    EXPECT_TRUE(noeud1->read_id() == 1);
    EXPECT_TRUE(noeud1->read_fille1() == NULL);
    EXPECT_TRUE(noeud1->read_fille2() == NULL);
    EXPECT_TRUE(noeud1->read_mere() == NULL);

    EXPECT_TRUE(noeud2->read_valeur(0) ==  5);
    EXPECT_TRUE(noeud2->read_id_fille1() == 3);
    EXPECT_TRUE(noeud2->read_id_fille2() == 0);
    EXPECT_TRUE(noeud2->read_id_mere() == 0);
    EXPECT_TRUE(noeud2->read_id() == 2);
    EXPECT_TRUE(noeud2->read_mere() == NULL);
    EXPECT_TRUE(noeud2->read_fille2() == NULL);

    EXPECT_TRUE(noeud3->read_valeur(0) == 3);
    EXPECT_TRUE(noeud3->read_id_fille1() == 0);
    EXPECT_TRUE(noeud3->read_id_fille2() == 0);
    EXPECT_TRUE(noeud3->read_id_mere() == 2);
    EXPECT_TRUE(noeud3->read_id() == 3);
    EXPECT_TRUE(noeud3->read_fille1() == NULL);
    EXPECT_TRUE(noeud3->read_fille2() == NULL);
}

TEST(Deletion, NoeudTestDeletion) {
    std::vector<int> vect1(4,4);
    std::vector<int> vect2(5,5);
    std::vector<int> vect3(3,3);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 2);

    noeud1->insertion(noeud2);

    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 3);

    noeud1->remplacement(noeud3);

    noeud3->deletion();

    EXPECT_TRUE(noeud1->read_valeur(0) == 4);
    EXPECT_TRUE(noeud1->read_id_fille1() == 0);
    EXPECT_TRUE(noeud1->read_id_fille2() == 0);
    EXPECT_TRUE(noeud1->read_id_mere() == 0);
    EXPECT_TRUE(noeud1->read_id() == 1);
    EXPECT_TRUE(noeud1->read_fille1() == NULL);
    EXPECT_TRUE(noeud1->read_fille2() == NULL);
    EXPECT_TRUE(noeud1->read_mere() == NULL);

    EXPECT_TRUE(noeud2->read_valeur(0) ==  5);
    EXPECT_TRUE(noeud2->read_id_fille1() == 0);
    EXPECT_TRUE(noeud2->read_id_fille2() == 0);
    EXPECT_TRUE(noeud2->read_id_mere() == 0);
    EXPECT_TRUE(noeud2->read_id() == 2);
    EXPECT_TRUE(noeud2->read_mere() == NULL);
    EXPECT_TRUE(noeud2->read_fille1() == NULL);
    EXPECT_TRUE(noeud2->read_fille2() == NULL);

    EXPECT_TRUE(noeud3->read_valeur(0) == 3);
    EXPECT_TRUE(noeud3->read_id_fille1() == 0);
    EXPECT_TRUE(noeud3->read_id_fille2() == 0);
    EXPECT_TRUE(noeud3->read_id_mere() == 0);
    EXPECT_TRUE(noeud3->read_id() == 3);
    EXPECT_TRUE(noeud3->read_mere() == NULL);
    EXPECT_TRUE(noeud3->read_fille1() == NULL);
    EXPECT_TRUE(noeud3->read_fille2() == NULL);

}

TEST(Operator, NoeudTestOperator) {
    std::vector<int> vect1(4,4);
    std::vector<int> vect2(5,5);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 2);

    noeud2 = noeud1;

    EXPECT_TRUE(noeud1->read_valeur(0) == noeud2->read_valeur(0));
    EXPECT_TRUE(noeud1->read_id_fille1() == noeud2->read_id_fille1());
    EXPECT_TRUE(noeud1->read_id_fille2() == noeud2->read_id_fille2());
    EXPECT_TRUE(noeud1->read_id_mere() == noeud2->read_id_mere());
    EXPECT_TRUE(noeud1->read_id() == noeud2->read_id());
    EXPECT_TRUE(noeud1->read_fille1() == noeud2->read_fille1());
    EXPECT_TRUE(noeud1->read_fille2() == noeud2->read_fille2());
    EXPECT_TRUE(noeud1->read_mere() == noeud2->read_mere());

}

TEST(Put, NoeudTestPut) {
    std::vector<int> vect1(4,4);
    std::vector<int> vect2(5,5);
    std::vector<int> vect3(3,3);
    noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
    noeud* noeud2 = new noeud(NULL, NULL, NULL, vect2, 2);
    noeud* noeud3 = new noeud(NULL, NULL, NULL, vect3, 3);
    noeud* noeud4 = new noeud(NULL, NULL, NULL, vect3, 4);

    noeud1->put_fille1(noeud2);
    noeud1->put_fille2(noeud3);
    noeud1->put_mere(noeud4);
    noeud1->put_id(5);
    noeud1->put_valeur(5,1);

    EXPECT_TRUE(noeud1->read_valeur(0) == 5);
    EXPECT_TRUE(noeud1->read_valeur(1) == 5);
    EXPECT_TRUE(noeud1->read_id_fille1() == 2);
    EXPECT_TRUE(noeud1->read_id_fille2() == 3);
    EXPECT_TRUE(noeud1->read_id_mere() == 4);
    EXPECT_TRUE(noeud1->read_id() == 5);

    EXPECT_TRUE(noeud2->read_valeur(0) ==  5);
    EXPECT_TRUE(noeud2->read_id_fille1() == 0);
    EXPECT_TRUE(noeud2->read_id_fille2() == 0);
    EXPECT_TRUE(noeud2->read_id_mere() == 5);
    EXPECT_TRUE(noeud2->read_id() == 2);
    EXPECT_TRUE(noeud2->read_fille1() == NULL);
    EXPECT_TRUE(noeud2->read_fille2() == NULL);

    EXPECT_TRUE(noeud3->read_valeur(0) == 3);
    EXPECT_TRUE(noeud3->read_id_fille1() == 0);
    EXPECT_TRUE(noeud3->read_id_fille2() == 0);
    EXPECT_TRUE(noeud3->read_id_mere() == 5);
    EXPECT_TRUE(noeud3->read_id() == 3);
    EXPECT_TRUE(noeud3->read_fille1() == NULL);
    EXPECT_TRUE(noeud3->read_fille2() == NULL);

    EXPECT_TRUE(noeud4->read_valeur(0) == 3);
    EXPECT_TRUE(noeud4->read_id_fille1() == 5);
    EXPECT_TRUE(noeud4->read_id_fille2() == 0);
    EXPECT_TRUE(noeud4->read_id_mere() == 0);
    EXPECT_TRUE(noeud4->read_id() == 4);
    EXPECT_TRUE(noeud4->read_mere() == NULL);
    EXPECT_TRUE(noeud4->read_fille2() == NULL);

}

TEST(Destructeur, StringTestDestructor){
	TearDown();
	TearDownTestCase();
}*/
