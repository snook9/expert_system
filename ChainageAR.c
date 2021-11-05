/********************CASSAING Jonathan******************************/

/********************ChainageAR.c***********************************/
/********************v1.0 -> 11/02/2009*****************************/


#include "InitMoteur.h"
#include "ChainageAR.h"


/*******************************************************************/
/*Attention : fonction recursive************************************/
int fChainageAR(char* But, Struct_Regle *Tete_Regle, Struct_Fait *Tete_Fait)
{
	

	Struct_Regle *RegleAct;
	Struct_Hypothese *Hypothese;
	int Continue = 1;
	int Resultat = 0;
	
	//printf("\nRésultat 1 = %d",Resultat); 
	
	if( fFaitPresent( Tete_Fait , But )==0)	// si le but n'est pas déjà dans la base
	{
		RegleAct = Tete_Regle;		// On pointe vers la 1° Règle de la base
		Hypothese = RegleAct->Premiere_Hypothese;

	//	printf("\nRésultat 2 = %d",Resultat); 

		while( RegleAct!=NULL && Resultat==0 )	//si on est pas à la fin de la base et que le résultat est faux
		{

			//printf("\nRegleAct : %s",RegleAct->sConclusion);
			if( strcmp(RegleAct->sConclusion,But)==0 )	//si la conclusion de la règle = but
			{
				Hypothese = RegleAct->Premiere_Hypothese;
				//printf("\nRésultat 3 = %d\nTestRegle(%s) : %d",Resultat,RegleAct->sConclusion,fTestRegle(RegleAct,Tete_Fait) ); 
				Continue=1;
				while (Hypothese != NULL && Continue ==1)
				{
					Continue = fChainageAR ( Hypothese->sHypothese, Tete_Regle, Tete_Fait); // Récursivité
					Hypothese = Hypothese->Hypothese_Suivante;
				//	printf("\nHypothese = %s",Hypothese->sHypothese);

				}

				Resultat = Continue;
				//printf("\nRésultat 4 = %d",Resultat); 
			}
			RegleAct = RegleAct -> Regle_Suivante;
		}
	}
	else 	// le but est dans la base de faits
	{
		Resultat = 1;
	}
	return Resultat;
}


/*******************************************************************/
/*******************************************************************/

/*******************************************************************/
/*******************************************************************/
