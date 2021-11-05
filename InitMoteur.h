/********************CASSAING Jonathan******************************/

/********************InitMoteur.h***********************************/
/********************v1.0 -> 11/02/2009*****************************/


#define Max 255								//Caracteres Max pour les faits

#ifdef WIN32								//Si vous etes sous Windows 
#define CLEAN "cls"							//"cls" pour rafraichir l'ecran sous Windows
#elif defined (linux)							//Si vous etes sous Linux
#define CLEAN "clear"							//"clear" pour rafraichir l'ecran sous Linux
#elif __APPLE__	
#define CLEAN "clear"
#endif

typedef struct Struct_Fait						//Structure des faits
{
        char sValeur[Max];						//Valeur d'un fait
        struct Struct_Fait *Fait_Suivant;				//Fait suivant
}Struct_Fait ;


typedef struct Struct_Regle						//Structure des regles
{
        char sConclusion[Max] ;						//Conclusion d'une regle
	int iNumero;							//Numero d'une regle
        struct Struct_Regle *Regle_Suivante;				//Regle suivante
        struct Struct_Hypothese *Premiere_Hypothese;			//Premiere hypothese d'une regle
}Struct_Regle ;

typedef struct Struct_Hypothese						//Structure hypothese
{
        char sHypothese[Max] ;                 				//Valeur de l’hypothese
        struct Struct_Hypothese *Hypothese_Suivante; 			//Hypothese suivante
}Struct_Hypothese;


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BaseFait.h"							//Module de la base de faits
#include "BaseRegle.h"							//Module de la base de regles
#include "ChainageAV.h"							//Module du chainage avant
#include "ChainageAR.h"							//Module du chainage arriere


/********************AntiCR*****************************************/
/*Cette fonction remplace le premier \n d'une chaine par \0*********/
/*******************************************************************/
/*Parametres : *Chaine, chaine a traiter****************************/
void AntiCR(char *Chaine);


/********************fFaitPresent***********************************/
/*Cette fonction test si le fait est deja dans la base**************/
/*******************************************************************/
/*Parametres : *Tete_Fait, pointeur tete de la base de faits********/
/*	       *Fait, fait a rechercher*****************************/
/*******************************************************************/
/*Retourne : -1, si Tete_Fait = NULL********************************/
/*            1, si le fait existe**********************************/
/*            0, si le fait n'existe pas****************************/
int fFaitPresent(Struct_Fait *Tete_Fait, char *Fait);


/********************fTestRegle*************************************/
/*Cette fonction test si la conclusion d'une regle existe***********/
/*******************************************************************/
/*Parametres : *Regle_Actuelle, regle a tester**********************/
/*             *Tete_Fait, pointeur tete de la base de faits********/
/*******************************************************************/
/*Retourne : -1, si *Regle_Actuelle ou Tete_Fait = NULL*************/
/*            1, si la conclusion de la regle existe****************/
/*            0, si la conclusion de la regle n'existe pas**********/
int fTestRegle(Struct_Regle *Regle_Actuelle, Struct_Fait *Tete_Fait);


/*******************************************************************/
/*******************************************************************/

/*******************************************************************/
/*******************************************************************/
