/**
 * \file Forme.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/


// Forme.hpp

#ifndef FORME_HPP
#define FORME_HPP

#include "Point.hpp"
#include <iostream>

/**
 * \brief      Cette classe décrit une forme
 */
class Forme
{
private:

    ///La couleur
    ulong couleur;

    /// L'ancre
    Point ancre;

    /// item_description
    bool selected;

    /// Valeur de l'épaisseur
    uint epaisseur;

    /// Booléen permettant de choisir si la forme sera rempli ou non
    bool rempli;

    ///
    bool anime;


public:
    /**
     * \brief      Construit une nouvelle instance de Forme
     *
     * \param[in]  couleur    La couleur
     * \param[in]  x          { La coordoné de l'axe des abscisses de l'ancre de la Forme}
     * \param[in]  y          { La coordoné de l'axe des ordonnés de l'ancre de la Forme }
     * \param[in]  epaisseur  L'epaisseur
     * \param[in]  rempli     Un booleen permetant de définir si le cercle est plein ou pas
     */


    Forme(ulong couleur, uint x, uint y, uint epaisseur, bool rempli,bool anime);

    /**
     * \brief      Construit une nouvelle instance de Forme par copie
     *
     * \param[in]  orig   L'original
     */

    Forme(const Forme &orig);

    /**
     * \brief      Construit une nouvelle instance de Forme à partir de paramètres donné dans un fichier
     *
     * \param      is    Indique le fichier à lire
     */

    Forme(istream &is);

    /**
     * \brief      Constructs a new instance.
     *
     * \param[in]  <unnamed>  { parameter_description }
     * \param      <unnamed>  { parameter_description }
     * \param      <unnamed>  { parameter_description }
     */

    Forme(ulong couleur, uint x_, uint y_);

    /**
     * \brief      Détruit une instance de Forme
     */

    virtual ~Forme();

    /**
     * \brief      Récupère la couleur
     *
     * \return     La couleur.
     */

    inline ulong getCouleur() const { return couleur; }

    /**
     * \brief      Change la couleur.
     *
     * \param[in]  couleur_  La couleur
     */

    inline void setCouleur(ulong couleur_) { couleur = couleur_; }

    /**
     * \brief      Change les coordonées de l'ancre
     *
     * \param[in]  x_    La nouvelle valeur sur l'axe des abscisses
     * \param[in]  y_    la nouvelle valeur sur l'axe des ordonnée
     */

    inline void setAncre(const uint x_, const uint y_) { ancre.setXY(x_, y_); }

    /**
     * \brief      Récupère l'épaisseur
     *
     * \return     L'épaisseur.
     */

    inline uint getEpaisseur() const { return epaisseur; }

    /**
     * \brief      Change l'épaisseur.
     *
     * \param[in]  epaisseur_  L'épaisseur
     */

    inline void setEpaisseur(uint epaisseur_) { epaisseur = epaisseur_; }

    /**
     * \brief      Récupère l'ancre.
     *
     * \return     L'ancre.
     */

    inline Point getAncre() const { return ancre; }

    /**
     * \brief      Voir si la forme est rempli
     *
     * \return     Si la forme est rempli ou non
     */
    inline bool getRempli() const { return rempli; }

    /**
     * \brief      Rempli la Forme
     *
     * \param[in]  rempli_  la Forme rempli
     */

    inline void setRempli(bool rempli_) { rempli = rempli_; }

    /**
     * \brief      Determines si le curseur est sur l'ancre
     *
     * \param[in]  x_    { La position du curseur en abscisse }
     * \param[in]  y_    { la position du curseur en ordonnée}
     *
     * \return     Vrai si c'est sur l'ancre, faux sinon.
     */
    inline bool isOverAncre(uint x_, uint y_) const { return ancre.isOver(x_, y_); }
    
   

    /**
     * \brief      Récupère l'animation courante
     *
     * \return     L'animation.
     */

    inline bool getAnime() const{ return anime;}

    /**
     * @brief      Change l'animation courante
     *
     * @param[in]  anime_   L'animation
     */


    inline void setAnime(bool anime_) { anime = anime_; }
    

    /**
     * \brief      Permet de dessiner une Forme
     *
     * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
     * \param[in]  isActive   Indique si on dessine ou pas
     */

    virtual void dessiner(EZWindow &, bool active = false) const;

    /**
     * \brief      Calcul du périmètre de la Forme
     *
     * \return     { La valeur du périmètre }
     */

    virtual double perimetre() const = 0;

    /**
     * \brief      Surcharge de l'opérateur de lecture du flux
     *
     * \param      <unnamed>  { L'output }
     * \param[in]  <unnamed>  { La forme }
     *
     * \return     Le résultat de l'opérateur de lecture du flux
     */

    friend ostream &operator<<(ostream &, const Forme &);

    /**
     * \brief      { Permet de lire dans le .txt et charger les formes qui sont écrites dedans }
     *
     * \param      <unnamed>  { Fichier à lire dedans }
     *
     * \return     { Les caractéristiques des formes récupérées }
     */
    static Forme *charger(istream &);

protected:

    /**
     * \brief      Permet d'écrire les propriétées de l'Ellipse dans un fichier texte
     *
     * \param[in]      <unnamed>  { Fichier de sortie }
     */

    virtual void ecrire(ostream &) const = 0; // /!\ virtuelle **pure** !
};

#endif