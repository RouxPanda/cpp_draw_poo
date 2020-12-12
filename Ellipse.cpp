/**
 * \file Ellispe.cpp
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

#include "Ellipse.hpp"

Ellipse::Ellipse(ulong couleur_, ulong x_, ulong y_, uint epaisseur_,bool rempli_,bool anime_, ulong demilargeur_, ulong demihauteur_)
	: Forme(couleur_, x_, y_, epaisseur_,rempli_,anime_), demilargeur(demilargeur_), demihauteur(demihauteur_)
{
}
Ellipse::Ellipse(Ellipse &orig)
	: Ellipse(orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(), orig.getEpaisseur(),orig.getRempli(),orig.getAnime(), orig.demilargeur, orig.demihauteur)
{
}
Ellipse::Ellipse(istream &is)
	: Forme(is), demilargeur(0), demihauteur(0)
{
	is >> demilargeur >> demihauteur;
}
Ellipse::~Ellipse()
{
}
double Ellipse::perimetre() const
{
	return (2 * pi * sqrt(((demilargeur ^ 2) + (demihauteur ^ 2)) / 2));
}
void Ellipse::dessiner(EZWindow &win, bool isActive) const
{
	Forme::dessiner(win, isActive); // Pour r�gler la couleur du dessin.
	if (Forme::getRempli())
	{
		win.fillCircle(getAncre().getX(), getAncre().getY(),
				   getAncre().getX() + demilargeur, getAncre().getY() + demihauteur);
	}
	else
	{
		win.drawCircle(getAncre().getX(), getAncre().getY(),
				   getAncre().getX() + demilargeur, getAncre().getY() + demihauteur);
	}
	
}

void Ellipse::ecrire(ostream &os) const
{
	os << "Ellipse"
	   << " ";
	Forme::ecrire(os); // �crire la forme que constitue l'�llipse actuel.
	os << " " << demilargeur << " " << demihauteur;
}

#endif