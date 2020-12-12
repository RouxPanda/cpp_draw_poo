/**
 * \file Triangle.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/

#include <iostream>
#include <cmath>

using namespace std;

#include "Triangle.hpp"

Triangle::Triangle(ulong couleur_, uint x_, uint y_, uint epaisseur_, bool rempli_, bool anime_, uint x2_, uint y2_, uint x3_, uint y3_)
    : Forme(couleur_, x_, y_, epaisseur_, rempli_, anime_), x2(x2_), y2(y2_), x3(x3_), y3(y3_)
{
}

Triangle::Triangle(const Triangle &orig)
    : Triangle(orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(), orig.getEpaisseur(), orig.getRempli(), orig.getAnime(), orig.x2, orig.y2, orig.x3, orig.y3) // ERREUR couleur, x et y pass accessibles
{
}

Triangle::Triangle(istream &is)
    : Forme(is), x2(0), y2(0), x3(0), y3(0)
{
  is >> x2 >> y2 >> x3 >> y3;
}

Triangle::~Triangle()
{
}

double Triangle::perimetre() const
{
  //on calcule le périmètre du triangle grâce à la formule du calcul de la distance entre deux points
  //plus d'informations ici : https://fr.wikihow.com/calculer-la-distance-entre-deux-points
  double cote1 = sqrt(((x2-getAncre().getX())^2) + ((y2-getAncre().getY())^2));
  double cote2 = sqrt(((x3-x2)^2) + ((y3-y2)^2));
  double cote3 = sqrt(((getAncre().getX()-x3)^2) + ((getAncre().getY()-y3)^2));
  return cote1 + cote2 + cote3;
}

void Triangle::ecrire(ostream &os) const
{
  os << "Triangle"
     << " ";
  Forme::ecrire(os); // Écrire la forme que constitue le Triangle actuel.
  os << " " << x2 << " " << y2 << " " << x3 << " " << y3;
}

void Triangle::dessiner(EZWindow &w, bool isActive) const // CORRECTION !
{
  Forme::dessiner(w, isActive); // Pour régler la couleur du dessin.
  if (Forme::getRempli())
  {
    //on remplit la forme
    w.fillTriangle(getAncre().getX(), getAncre().getY(),
                   getAncre().getX() + x2, getAncre().getY() + y2, getAncre().getX() + x3, getAncre().getY() + y3);
  }
  else
  {
    //on dessine le forme
    w.drawTriangle(getAncre().getX(), getAncre().getY(),
                   getAncre().getX() + x2, getAncre().getY() + y2, getAncre().getX() + x3, getAncre().getY() + y3);
  }
}
