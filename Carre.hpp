/**
 * \file Carre.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/
 
 
 // Carre.hpp

#ifndef CARRE_HPP
#define CARRE_HPP

#include "Forme.hpp"

/**
 * \brief      Cette classe décrit un carré
 */
class Carre : public Forme {
	private :
    /**
     * La longueur du coté d'un carré
     */
	uint cote;


	public :


	/**
	 * \brief      Construit une nouvelle instance de carré
	 *
	 * \param[in]  couleur    La couleur
	 * \param[in]  x          { La coordoné de l'axe des abscisse de l'ancre du carré  }
	 * \param[in]  y          { La coordoné de l'axe des ordonnée de l'ancre du carré }
	 * \param[in]  epaisseur  L'epaisseur du carré
	 * \param[in]  rempli     Un booleen permetant de définir si le carré est plein ou pas
	 * \param[in]  cote       la longueur des cotés du carré
	 */
	Carre (ulong couleur, uint x, uint y,uint epaisseur,bool rempli,bool anime, uint cote);


	/**
	 * \brief      Construit une nouvelle instance de carré par copie
	 *
	 * \param[in]  orig  Le carré que l'on veut copier
	 */
	
	Carre (const Carre& orig);


	/**
	 * \brief      Construit une nouvelle instance de carré à partir de paramètres donné dans un fichier
	 *
	 * \param      is    Indique le fichier à lire
	 */
	Carre ( istream& is);


	/**
	 * \brief      Détruit une instance de carré
	 * 
	 */
	~Carre();


	/**
	 * \brief      Récupère la longueur des cotés d'un carré
	 *
	 * \return     la longueur des cotés.
	 */
	inline uint getCote() const { return cote; }


	/**
	 * \brief      Change la longueur des cotés d'un carré
	 *
	 * \param[in]  cote_  la longueur des cotés
	 */
	inline void setCote (uint cote_) { cote=cote_; }


	/**
	 * \brief      Calcul du périmètre du carré
	 *
	 * \return     { la valeur du périmètre }
	 */
	double perimetre() const ;


	/**
	 * \brief      Permet de dessiner le carré
	 *
	 * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
	 * \param[in]  isActive   Indique si on dessine ou pas
	 */
	void dessiner(EZWindow&,bool isActive=false) const override;


	protected :
	/**
	 * \brief      Permet d'écrire les propriétées du carré dans un fichier texte
	 *
	 * \param      <unnamed>  { Fichier de sortie }
	 */
	void ecrire (ostream &) const;
};
#endif
