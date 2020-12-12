/**
 * \file Image.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/

// Image.cpp 

#include <iostream>
#include <string>

using namespace std; 

#include "Image.hpp"



Image::Image(uint x_, uint y_, const char* file, bool alpha_, double facteur_)
: Forme(0,x_,y_), adresse(file), image(nullptr), alpha(alpha_), facteur(facteur_)
{
    image = new EZImage(adresse.c_str());
}

Image::Image(const Image & orig)
: Image(orig.getAncre().getX(), orig.getAncre().getY(), orig.adresse.c_str(), orig.alpha, orig.facteur)
{
}

Image::Image(istream & is)
: Forme(is), adresse("vide"), image(nullptr), alpha(true), facteur(1)
{
    is >> adresse; 
    image = new EZImage(adresse.c_str());
    is >> alpha >> facteur; 
    image = image->scale(facteur); 
}

Image::~Image()
{
    delete image;
}

void Image::dessiner(EZWindow& win, bool isActive) const
{
    Forme::dessiner(win, isActive);
    image->paint(win, getAncre().getX(), getAncre().getY()); 
}

double Image::perimetre() const 
{
    return facteur; 
}

void Image::ecrire(ostream & os)const 
{
    os << "Image" << " ";
    Forme::ecrire(os);
    os << " " << adresse << " " << alpha << " " << facteur ;
}

void Image::changeTransparence() 
{
    image->setAlpha(!(image->getAlpha())); //set l'alpha à l'opposé de l'alpha actuel pour changer 
}