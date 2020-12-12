/**
 * \file Formes.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

#include "ez-draw++.hpp"

#include "Formes.hpp"
#include "Polygone.hpp"


Formes::Formes(unsigned int taille)
:maxformes(taille),nbformes(0),formes(nullptr)
{
    formes = new Forme*[taille];
}

Formes::~Formes() {
    for (uint i=0; i<nbformes; i++)
    delete formes[i];
    delete [] formes;
}

void Formes::ajouter(Forme *f)
{
    if (nbformes >= maxformes) 
    throw runtime_error ("Le nombre de formes maximales est atteint.") ;
else
   formes[nbformes++] = f;
}

void Formes::dessiner(EZWindow& w) const
{
    for ( uint i=0; i<nbformes; i++)
   formes[i]->dessiner(w);
}

Forme* Formes::isOverAncre(uint _x,uint _y)
{
    for (uint i = 0 ; i < nbformes ; ++i)
    {
        if (formes[i]->isOverAncre(_x, _y)) 
			return formes[i];
	}
	return nullptr;
}

ostream& operator<<(ostream& os, const Formes& formes)
{
for(uint i=0; i<formes.nbformes; i++) 
os << *(formes.formes[i]) << endl; 
return os;
}

Formes operator+ (const Formes & p1, const Formes & p2)
{
    Formes popo(500);
    for (size_t i = 0; i < p1.nbformes; i++)
    {
        popo.ajouter(p1.formes[i]);
    }
    for (size_t i = 0; i < p2.nbformes; i++)
    {
        popo.ajouter(p1.formes[i]);
    }
    return popo;
}

void Formes::sauver(ostream& os) const
{
    os << nbformes << endl << *this; // On écrit le nombre de formes et la liste de celles-ci grâce à la méthode précédante.
}

void Formes::charger(istream& is)
{
    uint nbr_formes; 
    is >> nbr_formes;
    for (uint i = 0 ; i < nbr_formes ; ++i)
		ajouter( Forme :: charger(is));
}

void Formes::supprimer(Forme *f)
{
    uint j = nbformes; //j permet de savoir à partir de quelle case du tableau on doit commencer à décaler à cause du trou dans le tableau provoqué par la suppression
    for(uint i=0;i<nbformes; i++) //On parcourt le tableau de *Forme
    {
        if(formes[i] == f)//Lorsque l'on trouve la forme correspondante, on la supprime et on enregistre sa place + 1 dans j
        {
            formes[i]->~Forme();

            j = i+1;
        }
    }
    if(nbformes>=2) 
    {
        for(uint i =j;i<nbformes; i++)
        {
            formes[i-1] = formes[i];
        }
    }
    nbformes--; //on décremente car on a supprimé une forme
}

