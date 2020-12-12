/**
 * \file Cercle.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/
 
 

#ifndef pi
#define pi 3.14159265358979323846
#include <iostream>
#include <cmath>

using namespace std;

#include "Cercle.hpp"

Cercle::Cercle(ulong couleur_, ulong x_, ulong y_, uint epaisseur_,bool rempli_,bool anime_, ulong rayon_)
	: Forme(couleur_, x_, y_, epaisseur_,rempli_,anime_), rayon(rayon_)
{
}
Cercle::Cercle(Cercle &orig)
	: Cercle(orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(), orig.getEpaisseur(),orig.getRempli(),orig.getAnime(), orig.rayon)
{
}
Cercle::Cercle(istream &is)
	: Forme(is), rayon(0)
{
	is >> rayon;
}
Cercle::~Cercle()
{
}
double Cercle::perimetre() const
{
	return (2 * pi * rayon);
}
void Cercle::dessiner(EZWindow &win, bool isActive) const
{
	Forme::dessiner(win, isActive); // Pour régler la couleur du dessin.
	if (Forme::getRempli())
	{
		win.fillCircle(getAncre().getX(), getAncre().getY(),
				   getAncre().getX() + rayon, getAncre().getY() + rayon);
	}
	else
	{
		win.drawCircle(getAncre().getX(), getAncre().getY(),
				   getAncre().getX() + rayon, getAncre().getY() + rayon);
	}
	
	
}
void Cercle::ecrire(ostream &os) const
{
	os << "Cercle"
	   << " ";
	Forme::ecrire(os); // Écrire la forme que constitue l'éllipse actuel.
	os << " " << rayon;
}


#endif