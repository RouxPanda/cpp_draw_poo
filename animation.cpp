/**
 * \file animation.cpp
 * \brief Implantation de la classe "Animation"
 * \author Romain / Irfan / Clément
 *
 * La classe Animation sert à animer les formes
 *
 **/

#include "animation.hpp"

Animation::Animation(uint delai_, ulong couleurtemp_, bool clignement_, bool clignoter_, bool arcenciel_, bool animepaisseur_, bool maxepaisseur_)
    : delai(delai_), couleurtemp(couleurtemp_), clignement(clignement_), clignoter(clignoter_), arcenciele(arcenciel_), animeepaisseur(animepaisseur_), maxepaisseur(maxepaisseur_), parcourscouleurs(0)
{}

Animation::~Animation()
{}

void Animation::clignotement(EZWindow &fenetre, Forme &forme)
{
    if (forme.getAnime()) //si la forme est animée
    {
        //on arrête les autres animations
        arcenciele = false;
        animeepaisseur = false;
        clignement = !clignement;
        if (clignement)
        {
            forme.setCouleur(ez_white);
            fenetre.sendExpose(); //on rafraîchit la fenêtre
        }
        else
        {
            forme.setCouleur(couleurtemp);
            fenetre.sendExpose(); //on rafraîchit la fenêtre
        }
        fenetre.startTimer(delai); //on réarme le timer
    }
    else
    {
        //on stoppe le timer
        fenetre.stopTimer();
        if (forme.getCouleur() != ez_white)
            forme.setCouleur(couleurtemp);
        else
            forme.setCouleur(ez_black);
        fenetre.sendExpose();
        //on arrête l'animation
        clignoter = false;
    }
}

//si la forme est animée
void Animation::arcenciel(EZWindow &fenetre, Forme &forme)
{
    const uint MAX = 8;
    //tableau d'entiers positifs à précision étendue contenant des couleurs
    ulong couleurs[MAX] = {ez_black, ez_blue, ez_cyan, ez_red, ez_yellow, ez_green, ez_grey, ez_magenta}; 
    if (forme.getAnime())
    {
        //on arrête les autres animations
        clignoter = false;
        animeepaisseur = false;
        if (parcourscouleurs < MAX)
        {
            forme.setCouleur(couleurs[parcourscouleurs]);
            ++parcourscouleurs; //on parcourt le tableau de couleurs
            fenetre.startTimer(delai);
        }
        else if (parcourscouleurs == MAX)
        {
            parcourscouleurs = 0; //on remet la valeur à 0 pour que ça tourne en boucle
            fenetre.startTimer(delai);
        }
        fenetre.sendExpose();
    }
    else
    {
        fenetre.stopTimer();
        if (forme.getCouleur() == ez_white)
            forme.setCouleur(ez_black);
        fenetre.sendExpose();
        arcenciele = false;
    }
}

//si la forme est animée
void Animation::animepaisseur(EZWindow &fenetre, Forme &forme)
{
    if (forme.getAnime())
    {
        //on arrête les autres animations
        clignoter = false;
        arcenciele = false;
        if ((forme.getEpaisseur() <= 10) and (!maxepaisseur))
        {
            forme.setEpaisseur(forme.getEpaisseur() + 1);
        }
        else
        {
            maxepaisseur = true;
        }
        if ((forme.getEpaisseur() >= 1) and (maxepaisseur))
        {
            forme.setEpaisseur(forme.getEpaisseur() - 1);
        }
        if ((forme.getEpaisseur() == 1))
        {
            maxepaisseur = false;
        }
        fenetre.sendExpose();
        fenetre.startTimer(delai);
    }
    else
    {
        fenetre.stopTimer();
        forme.setEpaisseur(1);
        fenetre.sendExpose();
        animeepaisseur = false;
    }
}