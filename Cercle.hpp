/**
 * \file Cercle.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/
 
 

#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "forme.hpp"

/**
 * \brief      Cette classe décrit un Cercle
 */
class Cercle : public Forme {
private:
	/**
	 * Rayon du cercle
	*/
	uint rayon;
public:

	/**
	 * \brief      Construit une nouvelle instance de Cercle
	 *
	 * \param[in]  couleur    La couleur
	 * \param[in]  x          {  La coordoné de l'axe des abscisses de l'ancre du cercle }
	 * \param[in]  y          { La coordoné de l'axe des ordonnés de l'ancre du cercle }
	 * \param[in]  epaisseur   L'epaisseur
	 * \param[in]  rempli     Un booleen permetant de définir si le cercle est plein ou pas
	 * \param[in]  rayon      Le rayon
	 */
	Cercle(ulong couleur, ulong x, ulong y,uint epaisseur,bool rempli,bool anime, ulong rayon);
	/**
	 * \brief      Construit une nouvelle instance de Cercle par copie
	 *
	 * \param      orig  Le Cercle que l'on veut copier
	 */

	Cercle(Cercle& orig);

	/**
	 * \brief      Construit une nouvelle instance de Cercle à partir de paramètres donné dans un fichier
	 *
	 * \param      is    Indique le fichier à lire
	 */
	Cercle(istream& is);

	/**
	 * \brief      Détruit une instance de Cercle
	 */

	~Cercle();

	/**
	 * \brief      Récupère le rayon du Cercle
	 *
	 * \return     Le rayon.
	 */

	inline int getRayon() const { return rayon; }

	/**
	 * \brief      Change le rayon.
	 *
	 * \param[in]  rayon_  Le rayon
	 */


	inline void setRayon(uint rayon_) { rayon = rayon_; }

	/**
	 * \brief      Calcul du périmètre du Cercle
	 *
	 * \return     { La valeur du périmètre }
	 */
	double perimetre() const;

	/**
	 * \brief      Permet de dessiner le Cercle
	 *
	 * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
	 * \param[in]  isActive   Indique si on dessine ou pas
	 */
	void dessiner(EZWindow& win, bool isActive = false) const;

	/**
	 * \brief      { Permet de changer la taille du Cercle }
	 *
	 * \param[in]  x_           { La coordonée sur l'axe des abscisse de l'ancre du Cercle }
	 * \param[in]  y_           { La coordonée sur l'axe des ordonnées de l'ancre du Cercle}
	 * \param[in]  augmntation  L'augmentation de la taille
	 */

	void changertaille(uint x_,uint y_,double augmntation);

protected:
	/**
	 * \brief      Permet d'écrire les propriétées du Cercle dans un fichier texte
	 *
	 * \param      <unnamed>  { Fichier de sortie }
	 */
	void ecrire(ostream& os) const;

};
#endif
