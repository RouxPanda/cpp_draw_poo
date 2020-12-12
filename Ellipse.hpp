/**
 * \file Ellipse.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/


#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "forme.hpp"

/**
 * \brief      Cette classe décrit une Ellipse.
 */
class Ellipse : public Forme {
private:
		/**
		 * demiLargeur et demihauteur de l'Ellipse
		 */
	uint demilargeur, demihauteur;
public:
	/**
	 * \brief      Construit une nouvelle instance d'Ellipse
	 *
	 * \param[in]  couleur      La couleur
	 * \param[in]  x            { La coordoné de l'axe des abscisses de l'ancre de l'Ellipse }
	 * \param[in]  y            { La coordoné de l'axe des ordonnés de l'ancre de l'Ellipse }
	 * \param[in]  epaisseur    L'epaisseur
	 * \param[in]  rempli       Un booleen permetant de définir si le cercle est plein ou pas
	 * \param[in]  demilargeur  La demilargeur
	 * \param[in]  demihauteur  La demihauteur
	 */

	Ellipse(ulong couleur,ulong x, ulong y,uint epaisseur,bool rempli,bool anime, ulong demilargeur, ulong demihauteur);

	/**
	 * \brief      Construit une nouvelle instance d'Ellipse par copie
	 *
	 * \param      orig  L'Ellipse que l'on veut copier
	 */

	Ellipse(Ellipse& orig);

	/**
	 * \brief      Construit une nouvelle instance d'Ellipse à partir de paramètres donné dans un fichier
	 *
	 * \param      is    Indique le fichier à lire
	 */

	Ellipse(istream& is);

	/**
	 * \brief      Détruit une instance d'Ellipse
	 */
	~Ellipse();

	/**
	 * \brief      Récupère la demilargeur
	 *
	 * \return     La demilargeur.
	 */

	inline int getDemilargeur() const { return demilargeur; }

	/**
	 * \brief      Récupère la demihauteur
	 *
	 * \return     La demihauteur.
	 */

	inline int getDemihauteur() const { return demihauteur; }

	/**
	 * \brief      Change la demilargeur
	 *
	 * \param[in]  demilargeur_  The demilargeur
	 */

	inline void setDemilargeur(uint demilargeur_) { demilargeur=demilargeur_; }

	/**
	 * \brief      Change la demihauteur
	 *
	 * \param[in]  demihauteur_  The demihauteur
	 */

	inline void setDemihauteur(uint demihauteur_) { demilargeur = demihauteur_; }

	/**
	 * \brief      Calcul du périmètre de l'Ellipse
	 *
	 * \return     { La valeur du périmètre }
	 */

	double perimetre() const;

	/**
	 * \brief      Permet de dessiner l'Ellipse
	 *
	 * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
	 * \param[in]  isActive   Indique si on dessine ou pas
	 */


	void dessiner(EZWindow& win, bool isActive = false) const;

	/**
	 * \brief      { Permet de changer la taille de L'Ellipse }
	 *
	 * \param[in]  x_           { La coordonée sur l'axe des abscisse de l'ancre de L'Ellipse }
	 * \param[in]  y_           { La coordonée sur l'axe des ordonnées de l'ancre de L'Ellipse }
	 * \param[in]  augmntation  L'augmentation de la taille
	 */

	void changertaille(uint x_,uint y_,double augmntation);

protected:

	/**
	 * \brief      Permet d'écrire les propriétées de l'Ellipse dans un fichier texte
	 *
	 * \param[in]      <unnamed>  { Fichier de sortie }
	 */
	void ecrire(ostream& os) const;


};
#endif
