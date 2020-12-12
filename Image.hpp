/**
 * \file Image.hpp
 * \brief Définition de la classe MyWindow
 * \author Romain / Irfan / Clément
 *
 * La classe MyWindow qui sert d'affiche général pour toute notre
 *
 **/


// Image.hpp

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "Forme.hpp"
#include <string>

/**
 * \brief      Cette classe décrit une image
 */
class Image : public Forme {
    private :

        /// Adresse de l'image
        string adresse;

        /// Pointeur sur une EZImage
        EZImage * image;  

        /// Booléean permettant de gérer la transparence
        bool alpha = false;

        ///  Permet de gérer la taille de l'image
        double facteur = 1; 
    public : 

        /**
         * \brief      Construit une nouvelle instance d'Image
         *
         * \param[in]  x_        { La coordonée sur l'axe des abscisse de l'ancre de l'Image }
         * \param[in]  y_        { La coordonée sur l'axe des ordonnées de l'ancre de l'Image }
         * \param[in]  filename  L'adresse de l'aimge
         * \param[in]  alpha_    La transparence de l'image
         * \param[in]  facteur_  La taille de l'image
         */
        Image(uint x_, uint y_, const char* filename, bool alpha_, double facteur_);

        /**
         * \brief      Construit une nouvelle instance d'Image par copie
         *
         * \param[in]  orig  L'Image originale
         */

        Image(const Image & orig);

        /**
         * \brief      Construit une nouvelle instance d'Image à partir de paramètres donné dans un fichier
         *
         * \param      is    Indique le fichier à lire
         */

        Image(istream & is);

        /**
         * \brief      Détruit une instance d'Image
         */

        ~Image();


        /**
         * \brief      { Recupère l'alpha de l'image }
         *
         * \return     { Un booléan permettant de savoir si l'image est transparente ou non }
         */

        inline bool getalpha() const {return alpha;}

        /**
         * \brief      { Change l'alpha de l'Image }
         *
         * \param[in]  alpha_  Change la valeur du booléan pour rendre l'Image transparente ou non
         */

        inline void setalpha(bool alpha_) {alpha = alpha_;}  

        /**
         * \brief      Récupère la  taille.
         *
         * \return     La taille.
         */

        inline double getTaille() const {return facteur;}

        /**
         * \brief      Change la taille.
         *
         * \param[in]  facteur_  La taille
         */

        inline void setTaille(double facteur_) {facteur = facteur_;}

        /**
         * \brief      Permet de dessiner une Image
         *
         * \param      <unnamed>  { Fenêtre dans laquelle on dessine }
         * \param[in]  isActive   Indique si on dessine ou pas
         */

        void dessiner(EZWindow&, bool isActive=false) const override;

        /// Augmente la taille de l'Image
        inline void augmenteTaille () {setTaille(getTaille()+0.025); image = image->scale(facteur);}


        /// Diminue la taille de l'Image
        inline void diminueTaille () {setTaille(getTaille()-0.025); image = image->scale(facteur);}

        
        /// Change la transparence de l'Image
        void changeTransparence(); 

        /**
         * \brief      Calcul du périmètre de l'Image
         *
         * \return     { La valeur du périmètre }
         */

        double perimetre() const; 
    protected: 

        /**
         * \brief      Permet d'écrire les propriétées de l'Image dans un fichier texte
         *
         * \param[in]      <unnamed>  { Fichier de sortie }
         */


        void ecrire(ostream& os) const;
};
#endif