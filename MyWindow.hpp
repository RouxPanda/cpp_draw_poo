/**
 * \file MyWindow.hpp
 * \brief En-tête de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 */

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include "Formes.hpp"
#include "animation.hpp"


/**
 * \brief      Cette classe décrit la fenêtre principale
 */
class MyWindow : public EZWindow
{

  /// Les 3 formes, qui sont les 3 calques de notre fenêtre
  Formes formes1, formes2, formes3;

  /// Les 3 booléens qui permette de savoir si oui ou non il faut afficher les calques ou pas
  bool bformes1, bformes2, bformes3;

  /// Un pointeur sur forme
  Forme *pforme;

  ///Permet d'afficher une image
  EZImage* image;

  /// Permet d'afficher une autre image pour gérer le changement de taille
  EZImage* image2;

  ///Une instance de la classe animation qui permet d'afficher les animations depuis sa classe
  Animation * anime;

  ///Le facteur de multiplication de changement de taille de l'image ( ne doit pas être négatif)
  double facteur;
  
  /// Le nombre du calques actuellement actif et nombre de point dans le polygone
  int chiffreCalque, nb_point_polygone;

  ///Les coordonées des axe des abscisses et des ordonnées des images
  int image_x,image_y;



public:

  /**
   * \brief      Créer une nouvelle instance de MyWindow
   *
   * \param[in]  w     { width=  la longueur de la fenêtre }
   * \param[in]  h     { height = la haute de la fenêtre }
   * \param[in]  name  Le nom de la fenêtre
   */
  MyWindow(int w, int h, const char *name);


  /// Détruit une instance de MyWindow
  ~MyWindow();

  /// Cette fonction virtuelle est déclenchée lorsque votre fenêtre doit être redessinée (ne serait-ce que partiellement). \nC'est dans cette fonction que vous pouvez réaliser des opérations graphiques. Normalement, il n'est pas souhaitable d'en faire à un autre moment du programme.

  void expose();

  /**
   * \brief      { Cette fonction virtuelle est appelée à chaque fois qu'une touche du clavier est enfoncée et que la fenêtre est sélectionnée (active). }
   *
   * \param[in]  keysym  La touche du clavier sur laquelle on appuie
   */

  void keyPress(EZKeySym keysym);

  /**
   * \brief      { Cette fonction virtuelle est déclenchée à chaque fois qu'un des boutons de la souris est appuyé. }
   *
   * \param[in]  mouse_x  Coordonée sur l'axe des abscisses de la souris au moment du clic
   * \param[in]  mouse_y  Coordonée sur l'axe des ordonnées de la souris au moment du clic
   * \param[in]  button   Le numéro du bouton qui a été appuyé
   */

  void buttonPress(int mouse_x, int mouse_y, int button);
  
  /**
   * { Le nombre du calques actuellement actif }
   */
  
  /**
   * \brief      { Cette fonction virtuelle est déclenchée à chaque relâchement d'un bouton de la souris. }
   *
   * \param[in]  mouse_x  Coordonée sur l'axe des abscisses de la souris au moment du relachement du clic
   * \param[in]  mouse_y  Coordonée sur l'axe des ordonnées de la souris au moment du relachement du clic
   * \param[in]  button   Le numéro du bouton qui a été relaché
   */
  void buttonRelease(int mouse_x, int mouse_y, int button);

  /**
   * \brief      { Cette fonction virtuelle est appelée à chaque mouvement de la souris dans la fenêtre. }
   *
   * \param[in]  mouse_x  Coordonée sur l'axe des abscisses de la souris à chaque déplacement
   * \param[in]  mouse_y  Coordonée sur l'axe des ordonnées de la souris à chaque déplacement
   * \param[in]  button   les boutons qui sont appuyé 
   */
  void motionNotify(int mouse_x, int mouse_y, int button);
  
  /**
   * \brief      { Prend en paramètre le calque actif actuel pour retourner un des 3 calques pour être écrit dedans}
   *
   * \param[in]  i  Prend en paramètre le chiffre du calque actif
   */
  Formes& calqueActif(int i);

  /// Cette fonction virtuelle est appelée quand le compte à rebours est arrivé à 0
  void timerNotify();

};

#endif
