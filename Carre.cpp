/**
 * \file Carre.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/


// Carre.cpp

#include <iostream>
#include <cmath>

using namespace std;

#include "Carre.hpp"

Carre::Carre(ulong couleur_, uint x_, uint y_, uint epaisseur_,bool rempli_,bool anime_, uint cote_)
    : Forme(couleur_, x_, y_, epaisseur_,rempli_,anime_), cote(cote_)
{
}

Carre::Carre(const Carre &orig)
    : Carre(orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(), orig.getEpaisseur(),orig.getRempli(),orig.getAnime(), orig.cote) // ERREUR couleur, x et y pass accessibles
{
}

Carre::Carre(istream &is)
    : Forme(is), cote(0)
{
  is >> cote;
}

Carre::~Carre()
{
}

double Carre::perimetre() const
{
  return (cote * 4);
}

void Carre::ecrire(ostream &os) const
{
  os << "Carre"
     << " ";
  Forme::ecrire(os); // Écrire la forme que constitue le Rectangle actuel.
  os << " " << cote;
}

void Carre::dessiner(EZWindow &w, bool isActive) const // CORRECTION !
{
  Forme::dessiner(w,isActive);
  if(Forme::getRempli())
  {
      w.fillRectangle(getAncre().getX(),getAncre().getY(),getAncre().getX()+cote,getAncre().getY()+cote);
  }
  else
  {
      w.drawRectangle(getAncre().getX(),getAncre().getY(), getAncre().getX()+cote,getAncre().getY()+cote);
  }
}