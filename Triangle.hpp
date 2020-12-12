/**
 * \file Triangle.hpp
 * \brief Définition de la classe Triangle
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert à dessiner un triangle dans le fenêtre
 *
 **/


// Triangle.hpp

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"


/**
 * \brief      Cette classe décrit un Triangle
 */
class Triangle : public Forme
{
private:

    /// abscisse du deuxième point
    uint x2;

    
    /// ordonné du deuxième point
    uint y2;

   
    /// abscisse du troisième point
    uint x3;

   
    /// ordonné du troisième point
    uint y3;

   

public:

    /**
     * \brief      Construit une nouvelle instance de la classe Triangle
     *
     * \param[in]  couleur    { la couleur de la forme }
     * \param[in]  x          { parameter_description }
     * \param[in]  y          { parameter_description }
     * \param[in]  epaisseur  { épaisseur du triangle }
     * \param[in]  rempli     { booléen permettant de savoir si un triangle est rempli ou pas }
     * \param[in]  x2         { abscisse du deuxième point }
     * \param[in]  y2         { ordonné du deuxième point }
     * \param[in]  x3         { abscisse du troisième point }
     * \param[in]  y3         { ordonné du troisième point }
     */

    Triangle(ulong couleur, uint x, uint y, uint epaisseur,bool rempli,bool anime, uint x2, uint y2, uint x3, uint y3);

    /**
     * \brief      Construit une nouvelle instance de Triangle par copie
     *
     * \param[in]  orig  Le triangle que l'on veut copier
     */

    Triangle(const Triangle &orig);

    /**
     * \brief      Construit une nouvelle instance de Triangle à partir de paramètres donné dans un fichier
     *
     * \param      is    Indique le fichier à lire
     */

    Triangle(istream &is);

    /**
     * \brief      Détruit une instance de Triangle
     */

    ~Triangle();

    /**
     * \brief      Récupère l'abscisse du deuxième point
     *
     * \return     l'abscisse du deuxième point
     *.
     */

    inline uint getX2() const { return x2; }

    /**
     * \brief      Change l'abscisse du deuxième point
     *
     * \param[in]  x2_   La nouvelle abscisse du deuxième point
     */

    inline void setX2(uint x2_) { x2 = x2_; }

    /**
     * \brief      Récupère l'ordonné du deuxième point
     *
     * \return     l'ordonné du deuxième point
     */

    inline uint getY2() const { return y2; }

    /**
     * \brief      Change l'ordonné du deuxième point
     *
     * \param[in]  y2_    La nouvelle ordonné du deuxième point
     */

    inline void setY2(uint y2_) { y2 = y2_; }

    /**
     * \brief      Change l'abscisse du troisième point
     *
     * \return     l'abscisse du troisième point
     */

    inline uint getX3() const { return x3; }

    /**
     * \brief      Change l'abscisse du troisième point
     *
     * \param[in]  x3_   La nouvelle valeur de l'abscisse du troisième point
     */

    inline void setX3(uint x3_) { x3 = x3_; }

    /**
     * \brief      Récupère  l'ordonné du troisième point.
     *
     * \return      l'ordonné du troisième point.
     */

    inline uint getY3() const { return y3; }

    /**
     * \brief      Change  l'ordonné du troisième point.
     *
     * \param[in]  y3_   La nouvelle valeur de l'ordonné du troisième point
     */

    inline void setY3(uint y3_) { y3 = y3_; }

    /**
     * \brief      Calcul du périmètre du Triangle
     *
     * \return     { La valeur du périmètre }
     */

    double perimetre() const;

	/**
	 * \brief      Permet de dessiner le Triangle
	 *
	 * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
	 * \param[in]  isActive   Indique si on dessine ou pas
	 */

    void dessiner(EZWindow &, bool isActive = false) const override;

protected:

	/**
	 * \brief      Permet d'écrire les propriétées du Triangle dans un fichier texte
	 *
	 * \param      <unnamed>  { Fichier de sortie }
	 */

    void ecrire(ostream &) const;
};
#endif
