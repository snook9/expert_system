/********************CASSAING Jonathan******************************/

/********************BaseRegle.h************************************/
/********************v1.0 -> 09/02/2009*****************************/


/*Attention : inclure InitMoteur.h**********************************/


/********************fCreerBaseRegle********************************/
/*Cette fonction cree une base de regles****************************/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base de regles******/
/*             NRegle, nombre de regles a reserver en memoire*******/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, pointeur tete initialise pour NRegle***************/
int fCreerBaseRegle(Struct_Regle **Tete_Regle);


/********************fSupprimerBaseRegle****************************/
/*Cette fonction libere une base de regles jusqu'a NULL*************/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base de regles******/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, memoire liberee************************************/
void fSupprimerBaseRegle(Struct_Regle *Tete_Regle);


/********************fAfficherBaseRegle*****************************/
/*Cette fonction affiche a l'ecran une base de Regles***************/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base de Regles******/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, affichage termine**********************************/
int fAfficherBaseRegle(Struct_Regle *Tete_Regle);


/********************fChargerBaseRegle******************************/
/*Cette fonction charge en memoire une base de Regles***************/
/*depuis un fichier*************************************************/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base chargee********/
/*	       *Path_Fichier, chemin du fichier a charger***********/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, fichier charge*************************************/
int fChargerBaseRegle(Struct_Regle **Tete_Regle, char *Path_Fichier);


/********************fSauverBaseRegle*******************************/
/*Cette fonction sauvegarde une base dans un fichier****************/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base de Regles******/
/*	       *Path_Fichier, chemin du fichier a sauvegarder*******/
/*******************************************************************/
/*Retourne : -1, si echec*******************************************/
/*            0, fichier sauvegarde*********************************/
int fSauverBaseRegle(Struct_Regle *Tete_Regle, char *Path_Fichier);


/********************fCreerRegle************************************/
/*Cette fonction creer et ajoute une Regle en fin de liste**********/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base de Regles******/ 
/*******************************************************************/
/*Retourne : -1, si Tete_Regle = NULL*******************************/
/*            0, Ajout termine**************************************/
int fCreerRegle(Struct_Regle *Tete_Regle);


/********************fModifierRegle*********************************/
/*Cette fonction modifie une Regle *********************************/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base de Regles******/ 
/*	       *ModifRegle, Regle a modifier dans la base de Regle**/
/*******************************************************************/
/*Retourne : -1, si Tete_Regle = NULL ou ModifRegle non trouve******/
/*            0, Modification termine*******************************/
int fModifierRegle(Struct_Regle **Tete_Regle);



/********************fSupprimerRegle********************************/
/*Cette fonction supprime une Regle*********************************/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base de Regles******/ 
/*	       *SupprimeRegle, Regle a supprimer dans la base ******/
/*******************************************************************/
/*Retourne : -1, si Tete_Regle = NULL ou SupprimeRegle non trouve***/
/*            0, Suppression reussie********************************/
int fSupprimerRegle(Struct_Regle **Tete_Regle,int NRegle);


/********************fCreerConclusion*******************************/
/*Cette fonction ajoute une structure regle avec********************/
/*sa conclusion en fin de liste*************************************/
/*******************************************************************/
/*Parametres : **Tete_Regle, pointeur tete de la base de Regles*****/ 
/*	       *sNouvelleConclusion, conclusion a ajouter***********/
/*******************************************************************/
/*Retourne :  -1, erreur d'ajout************************************/
/*             0, ajout termine*************************************/
int fCreerConclusion(Struct_Regle *Tete_Regle,char *sNouvelleConclusion,int cpt);


/********************fCreerHypothese********************************/
/*Cette fonction ajoute une structure hypothese avec****************/
/*son hypothese en fin de liste*************************************/
/*******************************************************************/
/*Parametres : *Tete_Regle, pointeur tete de la base de Regles******/ 
/*	       *sNouvelleHypothese, Hypothese a ajouter*************/
/*******************************************************************/
/*Retourne :  -1, erreur d'ajout************************************/
/*             0, ajout termine*************************************/
int fCreerHypothese(Struct_Hypothese *Tete_Hypothese,char *sNouvelleHypothese);


/*******************************************************************/
/*******************************************************************/

/*******************************************************************/
/*******************************************************************/
