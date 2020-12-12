/**
 * \file Rectangle.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/



// Rectangle.hpp

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"


/// Cette classe décrit un rectangle
class Rectangle : public Forme
{
private:

    /// La largeur du rectangle
    uint largeur;

    /// La hauteur du rectangle
    uint hauteur;

public:

    /**
     * \brief      Construit une nouvelle instance de Rectangle
     *
     * \param[in]  couleur    La couleur
     * \param[in]  x          { La coordoné de l'axe des abscisse de l'ancre du Rectangle  }
     * \param[in]  y          { La coordoné de l'axe des ordonnée de l'ancre du Rectangle }
     * \param[in]  epaisseur  L'epaisseur du Rectangle
     * \param[in]  rempli     Un booleen permetant de définir si le Rectangle est plein ou pas
     * \param[in]  largeur    La largeur du rectangle
     * \param[in]  hauteur    la hauteur du rectangle
     */

    Rectangle(ulong couleur, uint x, uint y, uint epaisseur,bool rempli,bool anime, uint largeur, uint hauteur);

    /**
     * \brief      Construit une nouvelle instance de Rectangle par copie
     *
     * \param[in]  orig  Le Rectangle que l'on veut copier
     */

    Rectangle(const Rectangle &orig);

    /**
     * \brief      Construit une nouvelle instance de Rectangle à partir de paramètres donné dans un fichier
     *
     * \param      is    Indique le fichier à lire
     */

    Rectangle(istream &is);

    /**
     * \brief      Detruit une instance de Rectangle
     */

    ~Rectangle();

    /**
     * \brief      Récupère la largeur.
     *
     * \return     La largeur.
     */

    inline uint getLargeur() const { return largeur; }

    /**
     * \brief      Change la largeur.
     *
     * \param[in]  largeur_  la largeur
     */

    inline void setLargeur(uint largeur_) { largeur = largeur_; }

    /**
     * \brief      Récupère la hauteur
     *
     * \return     La hauteur.
     */

    inline uint getHauteur() const { return hauteur; }

    /**
     * \brief      Change la hauteur
     *
     * \param[in]  hauteur_  la hauteur
     */

    inline void setHauteur(uint hauteur_) { hauteur = hauteur_; }

    /**
     * \brief      Calcul le périmètre du Rectangle
     *
     * \return     { Le périmètre du Rectangle }
     */

    double perimetre() const;

    /**
     * \brief      Permet de dessiner le Rectangle
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
