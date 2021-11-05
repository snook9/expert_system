/********************CASSAING Jonathan******************************/

/********************BaseFait.h*************************************/
/********************v1.0 -> 11/02/2009*****************************/


/*Attention : inclure InitMoteur.h**********************************/


/********************fCreerBaseFait*********************************/
/*Cette fonction cree une base de faits*****************************/
/*******************************************************************/
/*Parametres : *Tete_Fait, pointeur tete de la base de faits********/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, pointeur tete initialisé **************************/
int fCreerBaseFait(Struct_Fait **Tete_Fait);


/********************fSupprimerBaseFait*****************************/
/*Cette fonction libere une base de faits jusqu'a NULL**************/
/*******************************************************************/
/*Parametres : *Tete_Fait, pointeur tete de la base de faits********/
void fSupprimerBaseFait(Struct_Fait *Tete_Fait);


/********************fAfficherBaseFait******************************/
/*Cette fonction affiche a l'ecran une base de faits****************/
/*******************************************************************/
/*Parametres : *Tete_Fait, pointeur tete de la base de faits********/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, affichage termine**********************************/
int fAfficherBaseFait(Struct_Fait *Tete_Fait);


/********************fChargerBaseFait*******************************/
/*Cette fonction charge en memoire une base de faits****************/
/*depuis un fichier*************************************************/
/*******************************************************************/
/*Parametres : *Tete_Fait, pointeur tete de la base chargee*********/
/*	       *Path_Fichier, chemin du fichier a charger***********/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, fichier charge*************************************/
int fChargerBaseFait(Struct_Fait **Tete_Fait, char *Path_Fichier);


/********************fSauverBaseFait********************************/
/*Cette fonction sauvegarde une base dans un fichier****************/
/*******************************************************************/
/*Parametres : *Tete_Fait, pointeur tete de la base de faits********/
/*	       *Path_Fichier, chemin du fichier a sauvegarder*******/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, fichier sauvegarde*********************************/
int fSauverBaseFait(Struct_Fait *Tete_Fait, char *Path_Fichier);


/********************fCreerFait*************************************/
/*Cette fonction ajoute un fait en fin de liste*********************/
/*******************************************************************/
/*Parametres : *Tete_Fait, pointeur tete de la base de faits********/ 
/*	       *sNouveauFait, fait a rajouter dans la base de fait**/
/*******************************************************************/
/*Retourne : -1, erreur d'ajout*************************************/
/*            0, ajout termine**************************************/
int fCreerFait(Struct_Fait *Tete_Fait, char *sNouveauFait);


/********************fSupprimerFait*********************************/
/*Cette fonction supprime un fait***********************************/
/*******************************************************************/
/*Parametres : *Tete_Fait, pointeur tete de la base de faits********/ 
/*	       *sSupprimeFait, fait a supprimer dans la base *******/
/*******************************************************************/
/*Retourne : -1, si Tete_Fait = NULL ou sSupprimeFait non trouve****/
/*            0, Suppression reussie********************************/
int fSupprimerFait(Struct_Fait **Tete_Fait, char *sSupprimeFait);


/*******************************************************************/
/*******************************************************************/

/*******************************************************************/
/*******************************************************************/


