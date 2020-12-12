/**
 * \file Polygone.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/

#include <iostream>
#include <cmath>

using namespace std;

#include "Polygone.hpp"
#define PI 3.14159265

Polygone::Polygone(ulong couleur_, unsigned int x_, unsigned int y_, unsigned int epaisseur_, bool rempli_,bool anime_, unsigned int rayon_, unsigned int nb_point_)
    : Forme(couleur_, x_, y_, epaisseur_, rempli_,anime_), nb_point(nb_point_), rayon(rayon_), xOrigin(x_), yOrigin(y_)
{
  //On calcule alpha pour permettre de trouver tout les points par la trigonométrie
  unsigned int alpha = 360 / nb_point_;
  for (unsigned int i = 0; i < nb_point_; i++)
  {
    addXiYi((rayon_ * cos(i * alpha * PI / 180.0)) + x_, (rayon_ * sin(i * alpha * PI / 180.0)) + y_);
  }
}

Polygone::Polygone(const Polygone &orig)
: Polygone ( orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(),orig.getEpaisseur(), orig.getRempli(),orig.getAnime(), orig.rayon, orig.getNbPoints()) 
{}

Polygone::Polygone(istream &is)
    : Forme(is), nb_point(0), rayon(0),xOrigin(0),yOrigin(0)
{
  is >> nb_point >> rayon >> xOrigin >> yOrigin;
  unsigned int alpha = 360 / nb_point;
  for (unsigned int i = 0; i < nb_point; i++)
  {
    addXiYi((rayon * cos(i * alpha * PI / 180.0)) + getAncre().getX(), (rayon * sin(i * alpha * PI / 180.0) + getAncre().getY()));
  }
}

Polygone::~Polygone()
{}

double Polygone::perimetre() const
{ 
  //On toruve la taille d'un côté du polygone pour la multiplié au nombre de côté pour trouver le périmètre final
  int taille = sqrt(pow((getXi(1) - getXi(0)),2) + pow(getYi(1) - getYi(0),2));
  return (taille*nb_point); 
}

void Polygone::ecrire(ostream &os) const
{
  os << "Polygone"
     << " ";
  Forme::ecrire(os); // Écrire la forme que constitue le Polygone actuel.
  os << " " << nb_point << " "<< rayon << " " << xOrigin << " " << yOrigin;
}

void Polygone::dessiner(EZWindow &w, bool isActive) const // CORRECTION !
{
  //On établis un nouveau vecteur de point qui possède les mêmes points que tPoints mais décaler par rapport à la position de la nouvelle ancre
  Forme::dessiner(w, isActive); // Pour régler la couleur du dessin.
  std::vector<Point *> tPointsDraw;
  for (size_t i = 0; i < nb_point; i++)
    tPointsDraw.push_back(new Point (tPoints[i]->getX() + getAncre().getX() - xOrigin, tPoints[i]->getY() + getAncre().getY() - yOrigin));
  
  //On dessine ensuite la forme si elle est remplis ou pas
  if (Forme::getRempli())
  {
    w.fillTriangle(tPointsDraw[nb_point - 1]->getX(), tPointsDraw[nb_point - 1]->getY(), tPointsDraw[0]->getX(), tPointsDraw[0]->getY(), getAncre().getX(), getAncre().getY());
    for (size_t i = 0; i < nb_point - 1; i++)
    {
      w.fillTriangle(tPointsDraw[i]->getX(), tPointsDraw[i]->getY(), tPointsDraw[i + 1]->getX(), tPointsDraw[i + 1]->getY(), getAncre().getX(), getAncre().getY());
    }
  }
  else
  {
    w.drawLine(tPointsDraw[nb_point - 1]->getX(), tPointsDraw[nb_point - 1]->getY(), tPointsDraw[0]->getX(), tPointsDraw[0]->getY());
    for (size_t i = 0; i < nb_point - 1; i++)
    {
      w.drawLine(tPointsDraw[i]->getX(), tPointsDraw[i]->getY(), tPointsDraw[i + 1]->getX(), tPointsDraw[i + 1]->getY());
    }
  }
}
