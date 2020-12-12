/**
 * \file Polygone.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/


#ifndef POLYNOME_HPP
#define POLYNOME_HPP

#include "Forme.hpp"
#include <vector>

/// Cette classe décrit un polygone.

class Polygone : public Forme
{
private:

    /// Le tableau de pointeur de point qui permet le stockage des divers points de notre polygone
    std::vector<Point *> tPoints;

    /**
     * on a dans l'ordre : le nombre de point du polygone, le rayon du polygone, la valeur d'origine de l'ancre à sa création pour x et aussi pour y
     */

    unsigned int nb_point, rayon, xOrigin, yOrigin;

public:

    /**
     * \brief      Constructeur de polygone.
     *
     * \param[in]  couleur_    La couleur
     * \param[in]  x_          La coordonnées de l'ancre X
     * \param[in]  y_          La coordonnées de l'ancre Y
     * \param[in]  epaisseur_  L'épaisseur
     * \param[in]  rempli_     le booléen remplie
     * \param[in]  rayon_      Le rayon
     * \param[in]  nb_point_   Le nombre de point
     */

    Polygone(ulong couleur_, unsigned int x_, unsigned int y_, unsigned int epaisseur_, bool rempli_,bool anime_, unsigned int rayon_, unsigned int nb_point_);

    /**
     * \brief      Constructeur par copie de polygone
     *
     * \param[in]  orig  l'original qui doit se faire copier
     */

    Polygone(const Polygone &orig);

    /**
     * \brief      Construit une nouvelle instance de Polygone à partir de paramètres donné dans un fichier
     *
     * \param      is    Indique le fichier à lire
     */
    Polygone(istream &is);

    /**
     * \brief      Destructeur de polygone
     */

    ~Polygone();

    /**
     * \brief      Accesseur la valeur du point i sur l'axe X
     *
     * \param[in]  i     La position du point dans tPoints
     *
     * \return     la valeur de X
     */

    inline uint getXi(int i) const { return tPoints[i]->getX(); }

    /**
     * \brief      Accesseur la valeur du point i sur l'axe Y
     *
     * \param[in]  i     La position du point dans tPoints
     *
     * \return     la valeur de Y
     */

    inline uint getYi(int i) const { return tPoints[i]->getY(); }

    /**
     * \brief      Ajoute à tPoints un nouveau point avec ces valeurs x_ et y_ en paramètre
     *
     * \param[in]  xi_   La valeur X
     * \param[in]  yi_   La valeur Y
     */

    inline void addXiYi(uint xi_, uint yi_) {tPoints.push_back(new Point (xi_, yi_));}

    /**
     * \brief      Accesseur du nombre de point
     * 
     * \return     la valeur du nombre de point
     */
    inline int getNbPoints() const { return nb_point;}

    /**
     * \brief      Donne le périmètre du polygone
     *
     * \return     Retourne la valeur du périmètre
     */
    
    double perimetre() const;

    /**
     * \brief      Permet de dessiner le Polygone
     *
     * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
     * \param[in]  isActive   Indique si on dessine ou pas
     */

    void dessiner(EZWindow &, bool isActive = false) const override;
protected:

    /**
     * \brief      Permet d'écrire les propriétées du Rectangle dans un fichier texte
     *
     * \param      <unnamed>  { Fichier de sortie }
     */
    
    void ecrire(ostream &) const;
};
#endif
