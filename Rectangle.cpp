/**
 * \file Rectangle.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/


// Rectangle.cpp

#include <iostream>
#include <cmath>

using namespace std;

#include "Rectangle.hpp"

Rectangle::Rectangle(ulong couleur_, uint x_, uint y_, uint epaisseur_,bool rempli_,bool anime_, uint largeur_, uint hauteur_)
    : Forme(couleur_, x_, y_, epaisseur_,rempli_,anime_), largeur(largeur_), hauteur(hauteur_)
{
}

Rectangle::Rectangle(const Rectangle &orig)
    : Rectangle(orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(), orig.getEpaisseur(),orig.getRempli(),orig.getAnime(), orig.largeur, orig.hauteur) // ERREUR couleur, x et y pass accessibles
{
}

Rectangle::Rectangle(istream &is)
    : Forme(is), largeur(0), hauteur(0)
{
  is >> largeur >> hauteur;
}

Rectangle::~Rectangle()
{
}

double Rectangle::perimetre() const
{
  return (2 * largeur) + (2 * hauteur);
}

void Rectangle::ecrire(ostream &os) const
{
  os << "Rectangle"
     << " ";
  Forme::ecrire(os); // Écrire la forme que constitue le Rectangle actuel.
  os << " " << largeur << " " << hauteur;
}

void Rectangle::dessiner(EZWindow &w, bool isActive) const // CORRECTION !
{
  Forme::dessiner(w, isActive); // Pour régler la couleur du dessin.
  if(Forme::getRempli())
    {
          w.fillRectangle(getAncre().getX(), getAncre().getY(),
                    getAncre().getX() + largeur, getAncre().getY() + hauteur);
        
    }
    else
    {
          w.drawRectangle(getAncre().getX(), getAncre().getY(),
                    getAncre().getX() + largeur, getAncre().getY() + hauteur);
    }
}


