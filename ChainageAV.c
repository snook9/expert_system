/********************CASSAING Jonathan******************************/

/********************ChainageAV.c***********************************/
/********************v1.0 -> 11/02/2009*****************************/


#include "InitMoteur.h"
#include "ChainageAV.h"
#include "BaseFait.h"						//Pour la fonction fCreerFait


/*******************************************************************/
/*******************************************************************/
int fChainageAV( Struct_Regle *Tete_Regle,Struct_Fait *Tete_Fait )
{
	int NewFait=1;
	Struct_Regle *RegleAct;

	if(Tete_Regle == NULL || Tete_Fait == NULL)		// au cas ou la tete de faits ou de règles est Null
	{
		return -1;
	}
	while(NewFait==1)					// tant que l'on trouve des nouveaux faits
	{
		NewFait=0;					// on remet le flag à 0 afin de ne pas tomber ds une boucle infinie
		RegleAct = Tete_Regle;				// on pointe vers la Tete de Règle

		while(RegleAct != NULL)				// tant qu'on n'est pas à la fin de la base de règles
		{
			if(fTestRegle(RegleAct,Tete_Fait)==0 && fFaitPresent(Tete_Fait,RegleAct->sConclusion) ==0) // si une la conclusion d'une règle
			{								//est confirmé et la conclusion n'est pas déjà dans la base	
				NewFait = 1; 	    					// il y a de nouveaux faits
				if(fCreerFait(Tete_Fait,RegleAct->sConclusion)!=0) 	// on ajoute un fait en fin de liste
				{return -1;}
			}
			RegleAct = RegleAct -> Regle_Suivante;	// on se décale de une règle
		}
	}
	return 0;
}


/*******************************************************************/
/*******************************************************************/

/*******************************************************************/
/*******************************************************************/
