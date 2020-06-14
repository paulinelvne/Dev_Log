#include "formule.h"
#include "noeud.cpp"
#include <math.h>  
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <string> 

formule::formule()
{
	std::vector<int> vect1{4,4};
	noeud* noeud1 = new noeud(NULL, NULL, NULL, vect1, 1);
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
	
}

int transforme(int xA, int ope, int xB=36)
{
	if(xB==36) // cas où on n'a pas renseigné de xB => signifie que l'opérateur est NOT
	{
		return(!xA);
	}
	else if(ope == 3) // opérateur AND
	{
		return(xA && xB);
	}
	else if(ope == 4) // opérateur OR
	{
		return(xA || xB);
	}
	return(0);
}

int formule::formule_globale(int w)
{
	std::vector<noeud*> base_t ; // base de l'arbre

	int i=0;
	for(i=0; i< contenu_.size(); i++)
	{
		if((contenu_[i]->read_fille1() == NULL) && (contenu_[i]->read_fille2() == NULL))
		{
			base_t.push_back(contenu_[i]); // Je remplis la base de l'arbre avec les noeuds qui n'ont pas d'enfants
			
		}
	}
	
	int a = base_t.size();

	if((a==1) && (((base_t[0]->read_mere()))->read_valeur(w)==5)) // Cas où la base n'a qu'un noeud
			{
				return(transforme((base_t[0]->read_valeur(w)), 5));
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
				(base_t[i]->read_mere())->put_valeur(transforme((base_t[i])->read_valeur(w), (base_t[i]->read_mere())->read_valeur(w), (base_t[i+1])->read_valeur(w)), w);
				// la mère prend la valeur de ses deux noeuds 
				noeud * a_push = base_t[i]->read_mere();
				new_base.push_back(a_push);
				a_supprimer.push_back(i);
				a_supprimer.push_back(i+1);
			}

			else if((base_t[i]->read_mere() != base_t[i+1]->read_mere()) && (((base_t[i]->read_mere()))->read_valeur(w)==5))
			{
				(base_t[i]->read_mere())->put_valeur(transforme(base_t[i]->read_valeur(w), 4), w);
				noeud * a_push = base_t[i]->read_mere();
				new_base.push_back(a_push);
				a_supprimer.push_back(i);
			}
		}
	
		int asupsize = a_supprimer.size();
		int snb = new_base.size();
	
		
		for(i=0; i < asupsize; i++)
		{	
				int n = a_supprimer[0];
				base_t.erase(base_t.begin()+n-i); //+n-i)
				a_supprimer.erase(a_supprimer.begin());
		}
		
		
		for(i=0; i < snb; i++)
		{	
				base_t.push_back(new_base[i]);
		}
	
		new_base.clear();

		a = a - asupsize + snb ;
	}
		while(base_t[0]->read_mere() != NULL) // Je vérifie que le dernier noeud restant n'a pas en fait un NOT en parent
	{
		(base_t[0]->read_mere())->put_valeur(transforme(base_t[0]->read_valeur(w), (base_t[0]->read_mere())->read_valeur(w)), w);
		base_t[0]=base_t[0]->read_mere();
	}
	

	
	return(base_t[0]->read_valeur(w));
	
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

std::string transforme_str(noeud* xA, noeud* ope, noeud* xB, int w)
{
	if(xB==NULL) // cas où on ne renseigne pas de xB => NOT
	{
		return("(" + ope->read_str()+ xA->read_str()+ ")");
	}
	else if((ope->read_valeur(w) == 3 )|| ( ope->read_valeur(w) == 4 )) // AND ou OR
	{
		return("("+ xA->read_str() + ope->read_str() + xB->read_str()+")");
	}
	return("erreur");
} 

std::string formule::formule_globale_str(int w)
{
	std::vector<noeud*> base_t ; // base de l'arbre

	int i=0;
	for(i=0; i< contenu_.size(); i++)
	{
		if((contenu_[i]->read_fille1() == NULL) && (contenu_[i]->read_fille2() == NULL)) // je récupère les noeuds qui n'ont pas de filles, ce sont les bases de l'arbre
		{
			base_t.push_back(contenu_[i]);
			
		}
	}
	
	//std::cout << base_t.size() << std::endl ;
	int a = base_t.size();

	if((a==1) && (((base_t[0]->read_mere()))->read_valeur(w)==5)) // cas où il n'y a qu'un noeud dans la base
			{
				return(transforme_str(base_t[0], base_t[0]->read_mere())); // je retourne NOT ce noeud
			}
	
	
	while((a!= 1))
	{	
		std::vector<noeud*> new_base ; // je créé une nouvelle base pour ne pas avoir à modifier base_t pendant l'incrémentation
		std::sort(base_t.begin(), base_t.end(), [](noeud* lhs, noeud* rhs) {return lhs->read_id_mere() < rhs->read_id_mere();});
		// trie base_t par ordre d'adresse de mères croissant 
		std::vector<int> a_supprimer; // indice des noeuds à supprimer à la fin du for
		int i = 0;



		int b = base_t.size()-1;
		for(i=0; i < b ; i++)
		{
			
			if(((base_t[i]->read_mere())->read_id()) == ((base_t[i+1]->read_mere())->read_id())) // cas du AND ou OR
			{
				(base_t[i]->read_mere())->put_str(transforme_str(base_t[i], (base_t[i]->read_mere()), base_t[i+1])); // str_ de la mère prend la valeur de son association avec ses deux filles
				
				noeud * a_push = base_t[i]->read_mere();
				new_base.push_back(a_push); // j'ajoute la mère à new_base, afin de l'ajouter ensuite à base_t
				a_supprimer.push_back(i); //j'ajoute au vect à supprimer les indices des noeuds filles, inutiles maintenant.
				a_supprimer.push_back(i+1);
				

			}

			else if((base_t[i]->read_mere() != base_t[i+1]->read_mere()) && (((base_t[i]->read_mere()))->read_valeur(w)==5)) // cas du NOT
			{
				
				(base_t[i]->read_mere())->put_str(transforme_str(base_t[i], base_t[i]->read_mere()));
				noeud * a_push = base_t[i]->read_mere();
				new_base.push_back(a_push);
				a_supprimer.push_back(i);
	
			}
		}

		int asupsize = a_supprimer.size();
		int snb = new_base.size();
	

		for(i=0; i < asupsize; i++) // Je supprime tous les noeuds filles que je viens d'utiliser
		{	
				int n = a_supprimer[0];
				base_t.erase(base_t.begin()+n-i);
				a_supprimer.erase(a_supprimer.begin());
		}
		

		for(i=0; i < snb; i++) // Je push dans base_t les nouveaux noeuds à la base de l'arbre
		{	
				base_t.push_back(new_base[i]);
		}
		new_base.clear(); // je vide new_base pour le nouveau tour de boucle
		

		a = a - asupsize + snb  ; // Je modifie la valeur de a sans utiliser base_t.size car cela créerait une segmentation fault
		

	}
	while(base_t[0]->read_mere() != NULL) // Je vérifie que le dernier noeud restant n'a pas en fait un NOT en parent
	{
		(base_t[0]->read_mere())->put_str(transforme_str(base_t[0], base_t[0]->read_mere()));
		base_t[0]=base_t[0]->read_mere();
	}
	return(base_t[0]->read_str());//Je retourne le str_ du dernier noeud restant qui contient tous ceux de ses enfants
	
}

void formule::add_fitness(int ft)
{
	fitness_ = ft;
}

int formule::get_fitness()
{
	return this->fitness_;
}

void operator=(formule* f){
	*f.contenu_ = contenu_;
	*f.fitness_ = fitness_;
}

std::string formule::retourne_liste_noeuds()
{
	int i=0;
	int s=contenu_.size();
	std::string str_retournee = "[";
	for(i=0;i<s;i++)
	{
		if( contenu_[i]->read_id_mere() != 0 )
		{	str_retournee += "(" ;
			str_retournee += std::to_string(contenu_[i]->read_id_mere());
			str_retournee += ", " ;
			str_retournee += std::to_string(contenu_[i]->read_id()) ;
			str_retournee += ") ,";
		}

	}
	std::string str_retournee2 = str_retournee.substr(0, str_retournee.length() - 1);
	str_retournee2 += "]";
	return(str_retournee2);

}

std::string formule::retourne_tous_noeuds()
{
	int i=0;
	int s=contenu_.size();
	std::string str_retournee = "";
	std::string couleur = "yellowgreen";
	for(i=0;i<s;i++)
	{
		if(contenu_[i]->read_valeur(0)==3 || contenu_[i]->read_valeur(0)==4 || contenu_[i]->read_valeur(0)==5 )
			{
					couleur = "forestgreen";
			}
		else
			{
					couleur = "yellowgreen";
			}
		
		str_retournee += std::to_string(contenu_[i]->read_id());
		str_retournee += "=";
		str_retournee += "(";
		str_retournee += std::to_string(i);
		str_retournee += ", ";
		str_retournee += contenu_[i]->read_str();
		str_retournee += ", ";
		str_retournee += couleur;
		str_retournee += ")";
		str_retournee += "\n";

	}
	std::string str_retournee2 = str_retournee.substr(0, str_retournee.length() - 1);
	return(str_retournee2);

};

int fitness(formule* X, noeud* Y, int n){

int sum=0;
int tmp=0;
int i=0;
for (int i = 0; i < n ; i++)
{
 	tmp = Y->read_valeur(i)- X->formule_globale(i);
 	sum += tmp*tmp;
 }
 	X->add_fitness(-sum);
return -sum;
};
//sum += (Y->read_valeur(i) - X->formule_globale(i))*(Y->read_valeur(i)- X->formule_globale(i));
 