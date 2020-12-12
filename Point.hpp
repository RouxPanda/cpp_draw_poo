/**
 * \file Point.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/

// Point.hpp

#ifndef POINT_HPP
#define POINT_HPP
using namespace std;

#include "ez-draw++.hpp"

///Permet de renommer un unsigned int en uint
typedef unsigned int uint;

///Permet de renommer un unsigned long int en ulong
typedef unsigned long int ulong;

/// Cette classe décrit un point
class Point {
private :
   static const uint taille=3;

   /// Les coordonnées sur l'axe des abscisses et des ordonnées des points
   uint x,y;
public :
   
   /**
    * \brief      Créer une nouvelle instance de Point
    *
    * \param[in]  x     { Point sur l'axe des abscisses }
    * \param[in]  y     { Point sur l'axe des ordonnées }
    */

   Point (uint x, uint y);

   /**
    * \brief      Construit une nouvelle instance de Point par copie
    *
    * \param[in]  <unnamed>  {  Le Point que l'on veut copier }
    */

   Point (const Point&); 

   /**
    * \brief      Construit une nouvelle instance de Point à partir de paramètres donné dans un fichier
    *
    * \param      is    Indique le fichier à lire
    */

   Point (istream& is);

   /**
    * \brief      Destruit une instance de l'objet    
    */

   ~Point();

   /**
    * \brief      Récupère les coordonées de l'axe des abscisse
    *
    * \return     Le x.
    */

   inline uint getX() const {return x;}

   /**
    * \brief      Récupère les coordonées de l'axe des abscisse
    *
    * \return     Le y.
    */

   inline uint getY() const {return y;}

   /**
    * \brief      Change les valeurs des x et y
    *
    * \param[in]  _x    La nouvelle valeur
    * \param[in]  _y    La nouvelle valeur
    */

   inline void setXY(uint _x, uint _y){ x=_x ;  y=_y;} 

    /**
     * \brief      Determines si le curseur est sur l'ancre
     *
     * \param[in]  x_    { La position du curseur en abscisse }
     * \param[in]  y_    { la position du curseur en ordonnée}
     *
     * \return     Vrai si c'est sur l'ancre, faux sinon.
     */

   bool isOver(uint x_, uint y_) const;

    /**
     * \brief      Permet de dessiner un point
     *
     * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
     * \param[in]  isActive   Indique si on dessine ou pas
     */

   void dessiner(EZWindow&, bool = false) const;

   /**
    * \brief      Bitwise left shift operator.
    *
    * \param      os    The operating system
    * \param[in]  p     { parameter_description }
    *
    * \return     The result of the bitwise left shift
    */

   friend ostream& operator<< ( ostream & os, const Point & p);

   /**
    * \brief      Bitwise right shift operator.
    *
    * \param      is    Indicates if
    * \param      p     { parameter_description }
    *
    * \return     The result of the bitwise right shift
    */

   friend istream& operator>> ( istream & is, Point & p);
};
#endif