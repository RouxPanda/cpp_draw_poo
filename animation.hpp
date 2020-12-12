#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include "Forme.hpp"

/**
 * \file animation.hpp
 * \brief En-tête de la classe Animation
 * \author Romain / Irfan / Clément
 *
 * La classe Animation sert à animer les formes
 *
 */

/**
 * \brief La classe Animation permet d'animer des formes
 */
class Animation
{
private:
    /// c'est le compte à rebours (en ms)
    uint delai;
    /// Une couleur temporaire qui prend la valeur de la couleur de la forme avant l'animation "clignotement"
    ulong couleurtemp;
    /// Un booléen qui permet de passer à une forme de couleur à une forme de couleur et vice-versa
    bool clignement;
    /// Un booléen qui permet de savoir si l'animation "clignotement" est en marche ou pas
    bool clignoter;
    /// Un booléen qui permet de savoir si l'animation "arc en ciel" est en marche ou pas
    bool arcenciele;
    /// Un booléen qui permet de savoir si l'animation "animation épaisseur" est en marche ou pas
    bool animeepaisseur;
    /// Un booléen qui permet de savoir si on atteint l'épausseur maximum (ici 10)
    bool maxepaisseur;
    /// Un entier positif qui permet de parcourir un tableau contenant des couleurs
    uint parcourscouleurs;

public:

    /**
     * \brief      Crée une nouvelle instance de la classe Animation
     *
     * \param[in]  <unnamed>  { le compte à rebours en ms }
     * \param[in]  <unnamed>  { couleur temporaire qui prend la valeur de la couleur de la forme avant l'animation "clignotement" }
     * \param[in]  <unnamed>  { booléen qui permet de passer à une forme de couleur à une forme de couleur et vice-versa }
     * \param[in]  <unnamed>  { booléen qui permet de savoir si l'animation "clignotement" est en marche ou pas }
     * \param[in]  <unnamed>  { booléen qui permet de savoir si l'animation "arc en ciel" est en marche ou pas }
     * \param[in]  <unnamed>  { booléen qui permet de savoir si l'animation "animation épaisseur" est en marche ou pas }
     * \param[in]  <unnamed>  { entier positif qui permet de parcourir un tableau contenant des couleurs }
     */

    Animation(uint,ulong, bool,bool, bool, bool, bool);

    /**
     * \brief      Détruit une instance de la classe Animation
     */

    ~Animation();

    /**
     * \brief      { animation "clignotement" }
     *
     * \param      fenetre  La fenetre de l'application
     * \param      forme    Indique la forme à clignoter
     */

    void clignotement(EZWindow & fenetre,Forme& forme);

    /**
     * \brief      { animation "arc en ciel" }
     *
     * \param      fenetre  La fenetre de l'application
     * \param      forme    Indique la forme à clignoter
     */

    void arcenciel(EZWindow & fenetre,Forme& forme);

    /**
     * \brief      { animation "animation epaisseur" }
     *
     * \param      fenetre  La fenetre de l'application
     * \param      forme    Indique la forme à clignoter
     */

    void animepaisseur(EZWindow & fenetre,Forme& forme);

    /**
     * \brief      Récupère le timer
     *
     * \return     le timer
     */

    inline uint getDelai() const { return delai; }

    /**
     * \brief      Change la valeur du timer
     *
     * \param[in]  delai_  le timer
     */

    inline void setDelai(uint delai_) { delai=delai_; }
    /**
     * \brief      Récupère la couleur temporaire
     *
     * \return     la couleur temporaire
     */


    inline ulong getCouleurtemp() const { return couleurtemp; }
    
    /**
     * \brief      Change la valeur de la couleur temporaire
     *
     * \param[in]  couleurtemp_  la couleur temporaire
     */

    inline void setCouleurtemp(ulong couleurtemp_) { couleurtemp=couleurtemp_; }

    /**
     * \brief      Récupère la valeur du booléen "clignoter"
     *
     * \return     le booléen "clignoter"
     */

    inline bool getClignoter() const { return clignoter; }
    
    /**
     * \brief      Change la valeur du booléen "clignoter"
     *
     * \param[in]  clignoter_  le booléen qui change la valeur de la donnée membre "clignoter"
     */

    inline void setClignoter(bool clignoter_) { clignoter=clignoter_; }
   
    /**
     * \brief      Récupère la valeur du booléen "arcenciele"
     *
     * \return     le booléen "arcenciele"
     */

    inline bool getArcenciele() const { return arcenciele; }

    /**
     * \brief      Change la valeur du booléen "arcenciele"
     *
     * \param[in]  arcenciele_  le booléen qui change la valeur de la donnée membre "arcenciele"
     */

    inline void setArcenciele(bool arcenciele_) { arcenciele=arcenciele_; }

    /**
     * \brief      Récupère la valeur du booléen "animeepaisseur"
     *
     * \return     le booléen "animeepaisseur"
     */
    inline bool getAnimeepaisseur() const { return animeepaisseur; }

    /**
     * \brief      Change la valeur du booléen "animeepaisseur"
     *
     * \param[in]  animeepaisseur_  le booléen qui change la valeur de la donnée membre "animeepaisseur"
     */

    inline void setAnimeepaisseur(bool animeepaisseur_) { animeepaisseur=animeepaisseur_; }
};

#endif