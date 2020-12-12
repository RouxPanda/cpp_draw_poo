/**
 * \file Formes.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/

// Formes.hpp

#ifndef FORMES_HPP
#define FORMES_HPP

#include "Forme.hpp"

/**
 * \brief      Cette classe décrit des Formes
 */
class Formes {

  ///Le nombre maximum de formes
  uint maxformes;

  /// Le nombre actuel de formes
  uint nbformes;

  /// Un tableau alloué dynamiquement dont les éléments sont des (Formes*), l'allocation du tableau est faite dynamiquement
  Forme** formes; // Tableau alloué dynamiquement dont les éléments sont des (Forme*). La deuxième étoile est due à l'allocation dynamique du tableau.
public:

  /**
   * \brief      Construit une instance de tableau de Formes
   *
   * \param[in]  taille  la taille du tableau (200 si non précisé)
   */

  Formes(uint taille=200);

  /**
   * \brief      Destruit une instance de Formes
   */

  ~Formes();

  /**
   * \brief      { Rajoute une forme dans le tableau }
   *
   * \param      forme  La forme
   */

  void ajouter(Forme *forme);

  /**
   * \brief      Determines si le curseur est sur l'ancre
   *
   * \param[in]  x_    { La position du curseur en abscisse }
   * \param[in]  y_    { la position du curseur en ordonnée}
   *
   * \return     Vrai si c'est sur l'ancre, faux sinon.
   */

  Forme *isOverAncre(uint _x,uint _y);

  /**
   * \brief      Permet de dessiner une Formes
   *
   * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
   * \param[in]  isActive   Indique si on dessine ou pas
   */


  void dessiner(EZWindow& w) const;

  /**
   * \brief      Surcharge de l'opérateur de lecture du flux   
   * \param      os      Le systeme 
   * \param[in]  formes  Les formes
   *
   * \return     Le résultat de la surchage de l'opérateur de lecture du flux
   */

  friend ostream&  operator<<(ostream&  os, const Formes& formes);

  /**
   * \brief      Surcharge de l'opérateur d'addition
   *
   * \param[in]  p1    The p 1
   * \param[in]  p2    The p 2
   *
   * \return     Le résultat de l'addition
   */

  friend Formes operator+ (const Formes & p1, const Formes & p2);
  /**
   * \brief      { Permet de sauvegarder les formes actuelle dans un fichier texte }
   *
   * \param      os    Le fichier texte
   */

  void sauver(ostream& os) const;

  /**
   * \brief      { Permet de lire dans le .txt et charger les formes qui sont écrites dedans }
   *
   * \param      <unnamed>  { Fichier à lire dedans }
   *
   * \return     { Les caractéristiques des formes récupérées }
   */

  void charger(istream& is);

  /**
   * \brief      Récupère le nombre de formes
   *
   * \return     Le nombre de forme
   */

  inline uint getNbFormes() const {return nbformes;};

  /**
   * \brief      { Permet de supprimer une forme }
   *
   * \param      <unnamed>  { La forme courante à supprimer }
   */

  void supprimer(Forme *);

};
#endif
