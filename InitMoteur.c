/********************CASSAING Jonathan******************************/

/********************InitMoteur.c***********************************/
/********************v1.0 -> 11/02/2009*****************************/


#include "InitMoteur.h"


/*******************************************************************/
/*******************************************************************/
void AntiCR ( char* Chaine)
{
	int i;
	for(i=0; Chaine[i]!='\n' && Chaine[i]!='\0' ;i++);
	if(Chaine[i]=='\n')Chaine[i] = '\0';
}

/*******************************************************************/
/*******************************************************************/
int fFaitPresent( Struct_Fait *Tete_Fait , char* Conclusion )
{
	Struct_Fait *FaitAct;
	FaitAct = Tete_Fait;
	
	if(Tete_Fait == NULL)		// au cas ou la tete de faits ou de règles est Null
	{
		return -1;
	}
	

	while(FaitAct!=NULL)
	{
		if( strcmp(Conclusion,FaitAct->sValeur) == 0 ) // on a trouvé la conclusion dans la base
		{
			return 1;
		}
		FaitAct = FaitAct->Fait_Suivant; // On pointe sur le fait suivant
	}
	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fTestRegle(Struct_Regle *RegleAct, Struct_Fait *Tete_Fait)
{
	int ret=-1;

	Struct_Fait *FaitAct;
	Struct_Hypothese *Hypothese;
	
	Hypothese = RegleAct -> Premiere_Hypothese;

	while(Hypothese!=NULL)	//tant que on a des hypothèses à tester
	{
		ret = -1;
		FaitAct = Tete_Fait;	// on pointe vers le 1° de la base

		while(FaitAct!=NULL) 	//tant que il y a des faits
		{
			if( strcmp( Hypothese->sHypothese , FaitAct->sValeur)==0) 		// l'Hypothèse est validée
			{
				Hypothese = Hypothese -> Hypothese_Suivante;	// on pointe vers l'hypothese suivante
				FaitAct = NULL;		// on arrete de tester les faits puisqu'on a trouvé la bon
				ret=0;
			}
			else
			{
				FaitAct = FaitAct -> Fait_Suivant;		// sinon on pointe vers le fait suivant
				if(FaitAct==NULL)
				{
					return -1;	//on a testé tous les fait et aucun ne correspond
				}
			}
		}	
	}
	return ret;
}


/*******************************************************************/
/*******************************************************************/

/*******************************************************************/
/*******************************************************************/

