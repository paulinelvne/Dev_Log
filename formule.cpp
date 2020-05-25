#include "formule.h"
#include "noeud.cpp"
#include <math.h>  
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

formule::formule()
{
	noeud* noeud1 = new noeud(NULL, NULL, NULL, 4, 1);
	std::vector<noeud*> contenu_{noeud1}; 
	int fitness_= 1000;


}


formule::formule(std::vector<noeud*> contenu, int fit)
{
	contenu_=contenu;
	fitness_= fit;


}

formule::formule(formule & autre)
{
	contenu_=autre.contenu_;
	fitness_=autre.fitness_;
}



formule::~formule()
{
	/*int i=0;
	for (int i =0; i< contenu_.size();i++)
   {
     delete (contenu_[i]);
   } 
   contenu_.clear();
	//delete *contenu_;
*/
}

int transforme(int xA, int ope, int xB=36)
{
	if(xB==36)
	{
		return(!xA);
	}
	else if(ope == 3)
	{
		return(xA && xB);
	}
	else if(ope == 2)
	{
		return(xA || xB);
	}
	return(0);
}

int formule::formule_globale()
{
	std::vector<noeud*> base_t ; // base de l'arbre

	int i=0;
	for(i=0; i< contenu_.size(); i++)
	{
		if((contenu_[i]->read_fille1() == NULL) && (contenu_[i]->read_fille2() == NULL))
		{
			base_t.push_back(contenu_[i]);
			
		}
	}
	
	std::cout << base_t.size() << std::endl ;
	int a = base_t.size();

	if((a==1) && (((base_t[0]->read_mere()))->read_valeur()==4))
			{
				return(transforme((base_t[0]->read_valeur()), 4));
			}
	
	
	while((a!= 1))
	{	
		std::vector<noeud*> new_base ;
		std::sort(base_t.begin(), base_t.end(), [](noeud* lhs, noeud* rhs) {return lhs->read_id_mere() < rhs->read_id_mere();});
		// trie base_t par ordre d'adresse de mères croissant 
		std::vector<int> a_supprimer; // indice des noeuds à supprimer à la fin du for
		int i = 0;



		int b = base_t.size()-1;
		
		for(i=0; i < b ; i++)
		{
			
			if(((base_t[i]->read_mere())->read_id()) == ((base_t[i+1]->read_mere())->read_id()))
			{
				(base_t[i]->read_mere())->put_valeur(transforme((base_t[i])->read_valeur(), (base_t[i]->read_mere())->read_valeur(), (base_t[i+1])->read_valeur()));
				
				noeud * a_push = base_t[0]->read_mere();
				new_base.push_back(a_push);
				a_supprimer.push_back(i);
				a_supprimer.push_back(i+1);
				std::cout << "if" << std::endl;
			}

			else if((base_t[i]->read_mere() != base_t[i+1]->read_mere()) && (((base_t[i]->read_mere()))->read_valeur()==4))
			{
				std::cout << "elif" << std::endl;
				(base_t[i]->read_mere())->put_valeur(transforme(base_t[i]->read_valeur(), 4));
				noeud * a_push = base_t[0]->read_mere();
				new_base.push_back(a_push);
				a_supprimer.push_back(i);
				std::cout << "elif" << std::endl;
			}
		}
	
		int asupsize = a_supprimer.size();
		int snb = new_base.size();
	

		for(i=0; i <= a_supprimer.size(); i++)
		{	
				int n = a_supprimer[0];
				base_t.erase(base_t.begin()+n-i);
				a_supprimer.erase(a_supprimer.begin());
		}
		

		for(i=0; i <= new_base.size(); i++)
		{	
				base_t.push_back(new_base[i]);
		}
		new_base.clear();

		a = a - asupsize + snb ;
	

	}
	return(base_t[0]->read_valeur());
	
}


void formule::select_mutants(float taux_mut)
{
	int nb_mut ;
	nb_mut=ceil(taux_mut*contenu_.size());
	int i;
	for(i=0; i < contenu_.size(); i++)
	{
		int s = contenu_.size();
		int r;
		r=rand()%s;
		//contenu_[r]=contenu_[r]->mute();
		if(contenu_[r]->viabilite()==false)
			{contenu_[r]->deletion();}

	}

}

std::string transforme_str(noeud* xA, noeud* ope, noeud* xB)
{
	if(xB==NULL)
	{
		return(xA->read_str() + ope->read_str());
	}
	else if((ope->read_valeur() == 3 )|| ( ope->read_valeur() == 2 ))
	{
		return(xA->read_str() + ope->read_str() + xB->read_str());
	}
	
}

std::string formule::formule_globale_str()
{
	std::vector<noeud*> base_t ; // base de l'arbre

	int i=0;
	for(i=0; i< contenu_.size(); i++)
	{
		if((contenu_[i]->read_fille1() == NULL) && (contenu_[i]->read_fille2() == NULL))
		{
			base_t.push_back(contenu_[i]);
			
		}
	}
	
	std::cout << base_t.size() << std::endl ;
	int a = base_t.size();

	if((a==1) && (((base_t[0]->read_mere()))->read_valeur()==4))
			{
				return(transforme_str(base_t[0], base_t[0]->read_mere()));
			}
	
	
	while((a!= 1))
	{	
		std::vector<noeud*> new_base ;
		std::sort(base_t.begin(), base_t.end(), [](noeud* lhs, noeud* rhs) {return lhs->read_id_mere() < rhs->read_id_mere();});
		// trie base_t par ordre d'adresse de mères croissant 
		std::vector<int> a_supprimer; // indice des noeuds à supprimer à la fin du for
		int i = 0;



		int b = base_t.size()-1;
		
		for(i=0; i < b ; i++)
		{
			
			if(((base_t[i]->read_mere())->read_id()) == ((base_t[i+1]->read_mere())->read_id()))
			{
				(base_t[i]->read_mere())->put_str(transforme_str(base_t[i], (base_t[i]->read_mere()), base_t[i+1]));
				
				noeud * a_push = base_t[0]->read_mere();
				new_base.push_back(a_push);
				a_supprimer.push_back(i);
				a_supprimer.push_back(i+1);
				std::cout << "if" << std::endl;
			}

			else if((base_t[i]->read_mere() != base_t[i+1]->read_mere()) && (((base_t[i]->read_mere()))->read_valeur()==4))
			{
				std::cout << "elif" << std::endl;
				(base_t[i]->read_mere())->put_str(transforme_str(base_t[i], base_t[i]->read_mere()));
				noeud * a_push = base_t[0]->read_mere();
				new_base.push_back(a_push);
				a_supprimer.push_back(i);
				std::cout << "elif" << std::endl;
			}
		}
	
		int asupsize = a_supprimer.size();
		int snb = new_base.size();
	

		for(i=0; i <= a_supprimer.size(); i++)
		{	
				int n = a_supprimer[0];
				base_t.erase(base_t.begin()+n-i);
				a_supprimer.erase(a_supprimer.begin());
		}
		

		for(i=0; i <= new_base.size(); i++)
		{	
				base_t.push_back(new_base[i]);
		}
		new_base.clear();

		a = a - asupsize + snb ;
	

	}
	return(base_t[0]->read_str());
	
}
