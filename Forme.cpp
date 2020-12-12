/**
 * \file Forme.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/


// Forme.cpp

#include <iostream>
#include <cmath>

using namespace std;

#include "Forme.hpp"
#include "Rectangle.hpp" 
#include "Ellipse.hpp"
#include "Carre.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"
#include "Image.hpp"
#include "Polygone.hpp"

Forme ::Forme(ulong couleur_, uint x_, uint y_, uint epaisseur_, bool rempli_,bool anime_)
    : couleur(couleur_), ancre(x_, y_), epaisseur(epaisseur_), rempli(rempli_),anime(anime_)
{
}

Forme ::Forme(const Forme &orig)
    : Forme(orig.couleur, orig.getAncre().getX(), orig.getAncre().getY(), orig.epaisseur, orig.rempli,orig.anime)
{
}

Forme ::Forme(istream &is)
    : couleur(ez_black), ancre(0, 0), epaisseur(1),rempli(false),anime(false)
{
    /* Première solution simple à comprendre mais utilisant des variables locales :
    uint x, y;
    is >> couleur >> x >> y;
ancre.setXY(x,y);
   autres solution, plus élégante : */
    is >> couleur >> ancre >> epaisseur >> rempli >> anime;
}

Forme::Forme(ulong couleur_, uint x_, uint y_)
    :couleur(couleur_), ancre(x_, y_)
{   
}

Forme::~Forme()
{
}

void Forme::dessiner(EZWindow &w, bool isActive) const
{
    w.setColor(ez_black);
    w.setThick(epaisseur);
    ancre.dessiner(w, isActive);
    w.setColor(couleur);
}

ostream &operator<<(ostream &os, const Forme &f) // /!\ Fonction impossible à rendre polymorphe car operator<< n'est pas une fonction membre !
{
    f.ecrire(os);
    return os;
}


void Forme ::ecrire(ostream &os) const // Fonction membre polymorphe
{
    os << couleur << " " << ancre << " " << epaisseur << " " << rempli << " " << anime;
}

Forme *Forme::charger(istream &is)
{
    string chaine;
    is >> chaine;
    if (chaine == "Rectangle")    // On a trouvé « Rectangle » dans le fichier...
        return new Rectangle(is); // ... et maintenant, on analyse la chaine : « 0 10 10 50 60 » pour construire le nouveau Rectangle.
    else if (chaine == "Ellipse")
        return new Ellipse(is);
    else if (chaine == "Carre")
        return new Carre(is);
    else if (chaine == "Cercle")
        return new Cercle(is);
    else if (chaine == "Triangle")
        return new Triangle(is);
    else if (chaine == "Image")
        return new Image(is);
    else if (chaine == "Polygone")
        return new Polygone(is);
    else

        throw runtime_error("On n'a pas lu une forme connue.");
}

/*
char str[]="Bonjour"; // Ou autrement dit str est un « char * » ; La valeur de str est l'adresse du « B » initial de la chaîne

cin >> str; // On change éventuellement la valeur de str... mais pas son adresse !

switch(str)
{
     case "Bonjour" : // La valeur de cette constante n'est pas la chaîne, c'est l'adresse du « B » initial de cette constante.
         ....
         break;
}
*/

