/**
 * \file MyWindow.cpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "ez-draw++.hpp"
#include "MyWindow.hpp"

#include "Formes.hpp"

#include "Point.hpp"   // Uniquement pour le constructeur qui peuple la fenêtre
#include "Ellipse.hpp" // avec quelques formes.
#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"
#include "Triangle.hpp"
#include "Polygone.hpp"
#include "Image.hpp"

MyWindow::MyWindow(int w, int h, const char *name)
    : EZWindow(w, h, name), formes1(200), formes2(200), formes3(200), bformes1(true), bformes2(false), bformes3(false), pforme(nullptr), 
    image(nullptr), image2(nullptr), facteur(1),chiffreCalque(1), nb_point_polygone(6), image_x(0), image_y(0)
{
  anime = new Animation(500,0,false,false,false,false,false); 
  setDoubleBuffer(true); // On demande un affiche avec double tampon pour eviter les scintillements.
}

MyWindow::~MyWindow()
{
	delete anime;
  delete pforme;
  delete image;
  delete image2;
}

//cette fonction est déclenchée quand le timer est écoulé
void MyWindow::timerNotify()
{
  if (pforme)
  {
    if (anime->getClignoter()==true)
      anime->clignotement(*this,*pforme);
    if (anime->getArcenciele()==true)
      anime->arcenciel(*this,*pforme);
    if (anime->getAnimeepaisseur()==true)
      anime->animepaisseur(*this,*pforme);
  }
}

//Permet le raffraichissement et l'affichage des formes et des images dans la fenêtre
void MyWindow::expose()
{
  if (bformes1)
    formes1.dessiner(*this);
  if (bformes2)
    formes2.dessiner(*this);
  if (bformes3)
    formes3.dessiner(*this);
  if (pforme != nullptr)
    pforme->dessiner(*this, true);
  if (image != nullptr)
    image2->paint(*this, image_x, image_y);

  setColor(ez_black);
  drawText(EZAlign::TL, 3, 3, "h : affiche l'aide sur la console");
}

// S'active quand on appuie sur un bouton de la souris
void MyWindow::buttonPress(int mouse_x, int mouse_y, int button)
{
  if (button == 1)
    pforme = calqueActif(chiffreCalque).isOverAncre(mouse_x, mouse_y);

  if(pforme)
    anime->setCouleurtemp(pforme->getCouleur());
}
// Deplacement de la souris :
void MyWindow::motionNotify(int mouse_x, int mouse_y, int button)
{
  if (button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
    pforme->setAncre(mouse_x, mouse_y); // on la bouge.

  sendExpose();
}
// Relachement d'un bouton de la souris
void MyWindow::buttonRelease(int mouse_x, int mouse_y, int button)
{
  if (button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
    pforme->setAncre(mouse_x, mouse_y);
  sendExpose();
}

Formes& MyWindow::calqueActif(int i)
{
  switch(i)
  {
    case 1:
      return formes1;
    break;
    case 2:
      return formes2;
    break;
    case 3:
      return formes3;
    break;
    default:
      break;
  }
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{
  switch (keysym)
  {
  case EZKeySym::Escape: // Permet de quitter la fenetre
  case EZKeySym::q:
    EZDraw::quit();
    break;

  case EZKeySym::E:
    cout << calqueActif(chiffreCalque);
    break;
  
  case EZKeySym::S:
  {
    ofstream f("formes.txt");
    calqueActif(chiffreCalque).sauver(f);
  }
  break;

  case EZKeySym::C:
  {
    ifstream f("formes.txt");
    calqueActif(chiffreCalque).charger(f);
  }
  break;

  case EZKeySym::plus: // Permet d'augmenter l'epaisseur de la forme sélectionné
  {
    if (pforme)
    {
      if (pforme->getEpaisseur() < 10) //on met cette condition pour pas que la forme soit trop épaisse
        pforme->setEpaisseur(pforme->getEpaisseur() + 1);
    }
  }
  break;

  case EZKeySym::minus: // Permet de diminuter l'epaisseur de la forme sélectionné
  {
    if (pforme)
    {
      if (pforme->getEpaisseur() >= 1) //on met cette condition pour éviter que l'application crashe
        pforme->setEpaisseur(pforme->getEpaisseur() - 1);
    }
  }
  break;

  case EZKeySym::F: // Permert de remplir la forme sélectionné ou de la vider
  {
    if (pforme)
    {
      pforme->setRempli(!(pforme->getRempli()));
    }
  }
  break;

  case EZKeySym::p: // Permet d'afficher le périmètre de la forme sélectionné
  {
    cout << "périmètre de la forme sélectionné " << pforme->perimetre() << endl;
  }
  break;

  case EZKeySym::f: //Permet d'affiche
  {

  string adresse_image; 
  cout << "Veuillez indiquer le chemin de votre image ( .jpg, .png, .gif et .bmp)" <<endl; 
  cout << "Image de test par exemple : " << endl
      << "./images/ball1.jpg" << endl
      << "./images/ball2.gif" << endl
      << "./images/bubblets.png" << endl
      << "./images/paper1.jpg" << endl
      << "./images/tux1.png" << endl
      << "./images/tux2.gif" << endl;
  cin >> adresse_image; 
  try
  {
  formes1.ajouter(new Image(getWidth()/2-25, getHeight()/2-25, adresse_image.c_str(), false, 1));
  }
  catch ( exception& image)
  {
    cerr << "Erreur chargement de l'image" ;
  }

  
}
  break;

  case EZKeySym::a: //Permet de changer la transparence de l'image
  {
    if (pforme) {
       Image * image = dynamic_cast<Image*> (pforme);
       if (image != nullptr)
          image->changeTransparence();
  }
  break;


  case EZKeySym::d: // Delete la forme courante
  {
    if (pforme)
      calqueActif(chiffreCalque).supprimer(pforme);
  }
  break;

  case EZKeySym::m: //Fais clignoter la forme
  {
    pforme->setAnime(!(pforme->getAnime()));
    anime->setClignoter(true);
    startTimer(anime->getDelai());
    
  }
  break;
  case EZKeySym::z: // Fais tourner les couleurs de la forme en arc en ciel
  {
    pforme->setAnime(!(pforme->getAnime()));
    anime->setArcenciele(true);
    startTimer(anime->getDelai());

  }
  break;
  case EZKeySym::u: // Permet d'animer l'epaisseur de la forme
  {
    pforme->setAnime(!(pforme->getAnime()));
    anime->setAnimeepaisseur(true);
    startTimer(anime->getDelai());

  }
  break;

  case EZKeySym::_0: // Change la couleur de la forme en noir
    if (pforme)
      pforme->setCouleur(ez_black);
    break;
  case EZKeySym::_1: // Change la couleur de la forme en gris
    if (pforme)
      pforme->setCouleur(ez_grey);
    break;
  case EZKeySym::_2: // Change la couleur de la forme en rouge
    if (pforme)
      pforme->setCouleur(ez_red);
    break;
  case EZKeySym::_3: // Change la couleur de la forme en vert 
    if (pforme)
      pforme->setCouleur(ez_green);
    break;
  case EZKeySym::_4: // Change la couleur de la forme en bleu
    if (pforme)
      pforme->setCouleur(ez_blue);
    break;
  case EZKeySym::_5: // Change la couleur de la forme en jaune
    if (pforme)
      pforme->setCouleur(ez_yellow); 
    break;
  case EZKeySym::_6: // Change la couleur de la forme en cyan
    if (pforme)
      pforme->setCouleur(ez_cyan);
    break;
  case EZKeySym::_7: // Change la couleur de la forme en magenta
    if (pforme)
      pforme->setCouleur(ez_magenta);
    break;

  case EZKeySym::h:
   cout << "q : quitter" << endl
         << "h : cette aide" << endl
         << "E : ecrire la liste des formes sur la console" << endl
         << "S : sauve la liste des formes sur disque" << endl
         << "C : charge la liste des formes depuis le disque" << endl
         << "+ : augmente l'épaisseur" << endl
         << "- : diminue l'épaisseur" << endl
         << "p : affiche le périmètre de la forme" << endl
         << "F : remplit la forme" << endl << endl
         << "0 : met en noir la forme" << endl
         << "1 : met en gris la forme" << endl
         << "2 : met en rouge la forme" << endl
         << "3 : met en vert la forme" << endl
         << "4 : met en bleu la forme" << endl
         << "5 : met en jaune la forme" << endl
         << "6 : met en cyan la forme" << endl
         << "7 : met en magenta la forme" << endl << endl
         << "r : crée un rectangle" << endl
         << "e : crée une ellipse" << endl
         << "s : crée un carré" << endl
         << "c : crée un cercle" << endl
         << "t : crée un triangle" << endl 
         << "P : crée un Polygone"
         << "d : supprimer une forme" << endl << endl
         << "m : clignoter une forme" << endl
         << "z : forme arc en ciel" << endl
         << "u : animation epaisseur" << endl << endl
         << "& : Activer/Desactiver calque 1" << endl
         << "(apostrophe double) : Activer/Desactiver calque 2" << endl
         << "(apostrophe simple) : Activer/Desactiver calque 3" << endl
         << "( : Changer le calque sur lequel on écrit" << endl << endl
         << "b : ajouter un point sur le polygone" << endl
         << "n : supprimer un point sur le polygone" << endl << endl
         << "f : Affiche l'image" << endl
         << "a : Change la transparence de l'image en on/off" << endl
         << "'Shift_L et plus) ou (Shift_L  et KP_Add) pour augmenter la taille de l'image" << endl
         << "(Shit_L et moins) ou (Shit_L et KP_Subtract) pour diminuer la taille de l'image" << endl
         << "(del) : Supprime l'image" << endl;
    break;

  case EZKeySym::r: // Permet de créer un rectangle
    calqueActif(chiffreCalque).ajouter(new Rectangle(ez_black, getWidth() / 2 - 25, getHeight() / 2 - 25, 1, false, false, getWidth() / 2 + 25, getHeight() / 2 + 25));
    break;
  case EZKeySym::e: // Permet de créer une ellipse
    calqueActif(chiffreCalque).ajouter(new Ellipse(ez_black, getWidth() / 2 - 25, getHeight() / 2 - 15, 1, false, false, 50, 30));
    break;
  case EZKeySym::s: // Permet de créer un carré
    calqueActif(chiffreCalque).ajouter(new Carre(ez_black, getWidth() / 2 - 25, getHeight() / 2 - 25, 1, false, false, 50));
    break;
  case EZKeySym::c: // Permet de créer un Cercle
    calqueActif(chiffreCalque).ajouter(new Cercle(ez_black, getWidth() / 2 - 25, getHeight() / 2 - 25, 1, false, false, 25));
    break;
  case EZKeySym::t: // Permet de créer un triangle
    calqueActif(chiffreCalque).ajouter(new Triangle(ez_black, getWidth() / 2, getHeight() / 2 - 50, 1, false, false, getWidth() / 2 - 25, getHeight() / 2 - 30, getWidth() / 2 + 25, getHeight() / 2 - 30));
    break;
  case EZKeySym::P: // Permet de créer un polygone
    calqueActif(chiffreCalque).ajouter(new Polygone(ez_black, getWidth() / 2 - 25, getHeight() / 2 - 15, 1, false, false, 70, 10));
    break;

  case EZKeySym::b: // Permet d'augmenter le nombre de points dans le polygone
    if (pforme) {
       Polygone * poly = dynamic_cast<Polygone*> (pforme);
       if (poly != nullptr)
       {
        calqueActif(chiffreCalque).supprimer(pforme);
        nb_point_polygone = poly->getNbPoints() + 1;
        calqueActif(chiffreCalque).ajouter(new Polygone(ez_black, poly->getAncre().getX(), poly->getAncre().getY(), 1, false, false, 70, nb_point_polygone));
       }
    }
    break;
    
  case EZKeySym::n: // Permet de diminuer le nombre de points dans le polygone
    if (pforme) {
       Polygone * poly = dynamic_cast<Polygone*> (pforme);
       if (poly != nullptr)
       {
        calqueActif(chiffreCalque).supprimer(pforme);
        if(poly->getNbPoints()>=3)
          nb_point_polygone = poly->getNbPoints() - 1;
        calqueActif(chiffreCalque).ajouter(new Polygone(ez_black, poly->getAncre().getX(), poly->getAncre().getY(), 1, false, false, 70, nb_point_polygone));
       }
    }
    
    break;
  }
  break;
  case EZKeySym::Prior: //On augmente la taille de l'image
  {
    if (pforme) 
    {
     Image * picture = dynamic_cast<Image*> (pforme);
     if (picture != nullptr)
        picture->augmenteTaille();
    }
  }
  break;
  
  case EZKeySym::Next: //On diminue la taille de l'image
  {
    if (pforme) 
    {
     Image * picture = dynamic_cast<Image*> (pforme);
     if (picture != nullptr)
        picture->diminueTaille();
    }
  }

  break;

  case EZKeySym::Delete: // Permet de supprimer l'image selectionnée
  {
    if (pforme) 
    {
     Image * picture = dynamic_cast<Image*> (pforme);
     if (picture != nullptr)
        delete picture;
    }
  }
  break;
   
  case EZKeySym::ampersand: // Permet d'activer le calque 1
    bformes1 = !bformes1;
    if(bformes1)
      cout << "calques 1 activé" << endl;
    else
      cout << "calques 1 désactivé" << endl;
  break;

  case EZKeySym::quotedbl: // Permet d'activer le calque 2
    bformes2 = !bformes2;
    if(bformes2)
      cout << "calques 2 activé" << endl;
    else
      cout << "calques 2 désactivé" << endl;
  break;

  case EZKeySym::apostrophe: // Permet d'activer le calque 3
    bformes3 = !bformes3;
    if(bformes3)
      cout << "calques 3 activé" << endl;
    else
      cout << "calques 3 désactivé" << endl;
  break;

  case EZKeySym::parenleft: // Permet de passer au calque suivant
    if(chiffreCalque==3)
      chiffreCalque=1;
    else
      chiffreCalque+=1;
    cout << "calque actif : " << chiffreCalque << endl;
  break;

  default:
    break;
  
  }

  sendExpose();
}
