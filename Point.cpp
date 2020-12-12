/**
 * \file Point.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/


// Point.cpp

#include <iostream>
#include <cmath>

using namespace std;

#include "Point.hpp"

Point :: Point(uint x_, uint y_) 
: x(x_), y(y_) 
{} 

Point :: Point (const Point & orig)
: Point(orig.x, orig.y)
{}
 
Point :: Point (istream& is)
{
    is >> x >> y;
}

Point :: ~Point()
{}

bool Point::isOver (uint x_, uint y_) const
{
   // En C++ « a <= b <= c » se traduit en « (a <= b && b <= c) »
   
return
  x-taille <= x_ && x_ <= x+taille &&
  y-taille <= y_ && y_ <= y+taille;
}

void Point::dessiner(EZWindow & win, bool isActive) const
{
win.setColor( isActive ? ez_red : ez_green);
win.drawRectangle(x-taille,y-taille,x+taille,y+taille);
}    

ostream& operator<<(ostream& os, const Point &p)
{
    os << p.x << " " << p.y << endl;
    return os;
}
    
istream& operator>> (istream& is, Point & p)
{
    is >> p.x >> p.y;
    return is;
 }