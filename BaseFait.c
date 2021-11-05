/********************CASSAING Jonathan******************************/

/********************BaseFait.c*************************************/
/********************v1.0 -> 10/02/2009*****************************/

#include "InitMoteur.h"
#include "BaseFait.h"

/*******************************************************************/
/*******************************************************************/
int fCreerBaseFait( Struct_Fait **Tete_Fait )
{	
	int Choix;
	char Poubelle;
	char sNouveauFait[Max]="";					//Premier fait de la base de faits

	*Tete_Fait=(Struct_Fait *)malloc( sizeof(Struct_Fait) );	//Allocation de la memoire pour la tete

	if( *Tete_Fait == NULL )					//Quitter si erreur d'allocation de memoire
	{
		return -1;
	}

	(*Tete_Fait)->Fait_Suivant=NULL;				//Fait suivant initialise a NULL

	printf("\nEntrez le premier fait : ");				//L'utilisateur entre le premier fait
	fgets((*Tete_Fait)->sValeur, Max, stdin);
	AntiCR( (*Tete_Fait)->sValeur );				//Suppression du \n en fin de chaine

	do
	{
		printf("\nVoulez vous entrer un autre fait ?");		//Possibilite de continuer l'ajout d'autres faits
		printf("\n\t(0) NON");
		printf("\n\t(1) OUI");
		printf("\nVotre choix : ");
		scanf("%d",&Choix);
		scanf("%c",&Poubelle);

		switch(Choix)
		{	
			case 0 :					//Quitter si l'utilisateur choisit NON
			break;
			
			case 1 :					//Ajout d'un nouveau fait si l'utilisateur choisit OUI
				printf("\nEntrez un autre fait : ");
				fgets(sNouveauFait, Max, stdin);
				if( fCreerFait( (*Tete_Fait), sNouveauFait)==-1 )
				{	
					printf("\nErreur d'allocation de memoire");
					return -1;
				}
			break;

			default :
			break;
		}	

	}while( Choix!=0 );

	

	return 0;
}

/*******************************************************************/
/*Attention : fonction recursive************************************/
void fSupprimerBaseFait(Struct_Fait *Tete_Fait)		
{
	if( Tete_Fait == NULL )						//Condition de sortie de la recursivite
	{
		return ;
	}
	
	fSupprimerBaseFait( Tete_Fait->Fait_Suivant );			//RECURSIVITE
	
	free( Tete_Fait );						//Libere la memoire utilise par la base de faits
}

/*******************************************************************/
/*******************************************************************/
int fAfficherBaseFait(Struct_Fait *Tete_Fait)
{
	Struct_Fait *Fait_Actuel;

	printf("\n____________________Affichage de la base de faits____________________\n\n");	

	if( Tete_Fait == NULL )						//Quitter si la base est vide
	{
		printf("\nBase de fais vide");
		return -1;
	}

	Fait_Actuel = Tete_Fait;					//Initialisation du pointeur de deplacement

	while( Fait_Actuel != NULL )					//Tant qu'il y a des faits
	{
		printf("%s;",Fait_Actuel->sValeur);			//Affichage d'un fait
		Fait_Actuel = Fait_Actuel->Fait_Suivant;		//Deplacement vers le fait suivant
	}

	printf("\n");

	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fChargerBaseFait(Struct_Fait **Tete_Fait, char *Path_Fichier)
{
	FILE *Fic;
	char cBuffer;							//Buffer de lecture dans le fichier
	char sNouveauFait[Max]="";
	int i;								//Variable de detection si la tete a etait modifier

	i=0;
	AntiCR(Path_Fichier);						//Suppression de \n
	
	Fic=fopen(Path_Fichier,"r");					//Ouverture du fichier en lecture
	if(Fic==NULL)
	{
		printf("\nErreur d'ouverture (Fonction fChargerBaseFait)");
		return -1;
	}

	(*Tete_Fait)=(Struct_Fait *)malloc( sizeof(Struct_Fait) );	//Allocation de memoire

	if( *Tete_Fait == NULL )
	{
		return -1;
	}

	(*Tete_Fait)->Fait_Suivant=NULL;				//Fait suivant a NULL
	memset((*Tete_Fait)->sValeur, 0, Max);				//Valeur a 0

	while( fread(&cBuffer,1,1,Fic)!=0 && !feof(Fic) )		//Lecture tant que la fin n'est pas atteinte
	{
		if( i==0 )						//Si la tete n'a pas encore etait modifiee
		{
			if( cBuffer != ';' )				//Si le caractere lut n'est pas un ;
			{
				sprintf(sNouveauFait,"%s%c",sNouveauFait,cBuffer);	//Concatenation du Buffer lut dans une chaine
			}
			else						//Sinon
			{
				strcpy( (*Tete_Fait)->sValeur, sNouveauFait );		//Ecriture du premier fait dans la valeur de la tete
				memset(&sNouveauFait, 0, Max);				//Remise a 0 de la chaine
				i++;					//Incrementation de la variable de detection
			}
		}
		else
		{
			if( cBuffer != ';' )				//Si le caractere lut n'est pas un ;
			{
				sprintf(sNouveauFait,"%s%c",sNouveauFait,cBuffer);	//Concatenation du Buffer lut dans une chaine
			}
			else						//Sinon
			{
				fCreerFait( (*Tete_Fait), sNouveauFait);		//Ajout du fait lut en fin de liste
				memset(&sNouveauFait, 0, Max);				//Remise a 0 de la chaine
			}
		}	
	}


	if (Fic!=NULL)							//Fermeture du fichier
	{
		fclose(Fic);
		Fic=NULL;
	}

	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fSauverBaseFait(Struct_Fait *Tete_Fait, char *Path_Fichier)
{
	FILE *Fic;
	Struct_Fait *Fait_Actuelle;					//Pointeur de deplacement dans la liste des faits
	int Choix;
	char Poubelle;

	Choix=1;
	AntiCR(Path_Fichier);						//Suppression de \n

	if( Tete_Fait == NULL )
	{
		printf("\nBase de fais vide");				//Quitter si pas de memoire
		return -1;
	}

	Fic=fopen(Path_Fichier,"r");					//Ouverture du fichier "Path_Fichier" en lecture afin de verifier son existance
	if(Fic!=NULL)							//Si le fichier existe, possibilite de l'ecraser
	{
		do
		{
			system(CLEAN);					//Menu
			printf("\nLe fichier %s existe deja", Path_Fichier);
			printf("\nVoulez vous l'ecraser ?");
			printf("\n\t(0) NON");
			printf("\n\t(1) OUI");
			printf("\nVotre choix : ");
			scanf("%d",&Choix);
			scanf("%c",&Poubelle);
		}while( Choix!=0 && Choix!=1 );
	}
	
	if (Fic!=NULL)							//Fermeture du fichier
	{
		fclose(Fic);
		Fic=NULL;
	}

	if( Choix==1 )							//Si l'utilisateur a choisit d'ecraser le fichier ou si le fichier n'existait pas
	{
		Fic=fopen(Path_Fichier,"w");				//Ouverture du fichier en ecriture
		if(Fic==NULL)
		{
			printf("\nErreur d'ouverture (Fonction fSauverBaseFait)");
			return -1;
		}

		Fait_Actuelle = Tete_Fait;				//Pointeur de deplacement dans la base de faits initialise

		while( Fait_Actuelle != NULL )				//Tant qu'il y a des faits
		{
			fprintf(Fic,"%s;",Fait_Actuelle->sValeur);	//Ecriture des faits dans le fichier	
			Fait_Actuelle = Fait_Actuelle->Fait_Suivant;	//Deplacement vers le fait suivant
		}

		if (Fic!=NULL)						//Fermeture du fichier
		{
			fclose(Fic);
			Fic=NULL;
		}
	}
		
	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fCreerFait(Struct_Fait *Tete_Fait, char *sNouveauFait)
{
	Struct_Fait *Nouvelle_Struct_Fait;				//Pointeur local pour l'ajout d'un nouveau fait
	Struct_Fait *Fait_Actuel;					//Pointeur de deplacement dans la liste des faits
	
	Fait_Actuel = Tete_Fait;					//Initialisation du pointeur de deplacement

	AntiCR(sNouveauFait);						//Suppression de \n

	Nouvelle_Struct_Fait=(Struct_Fait *)malloc( sizeof(Struct_Fait) );	//Allocation de la memoire

	if( Nouvelle_Struct_Fait == NULL )				//Quitter si echec d'allocation de memoire
	{
		return -1;
	}
	
	while( Fait_Actuel->Fait_Suivant != NULL )			//Tant que le fait suivant n'est pas NULL
	{
		Fait_Actuel = Fait_Actuel->Fait_Suivant;		//Deplacement vers le fait suivant
	}

	Fait_Actuel->Fait_Suivant = Nouvelle_Struct_Fait;		//Ajout de la nouvelle structure a la fin
	strcpy(Nouvelle_Struct_Fait->sValeur, sNouveauFait);		//Copie du nouveau fait dans la nouvelle structure
	Nouvelle_Struct_Fait->Fait_Suivant = NULL;			//Suivant de la nouvelle structure a NULL

	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fSupprimerFait(Struct_Fait **Tete_Fait, char *sSupprimeFait)
{
	Struct_Fait *Fait_Actuel;					//Pointeur de deplacement dans la liste des faits
	Struct_Fait *Fait_Buffer;					//Buffer pour memoriser le fait avant le fait actuel
	
	Fait_Actuel = *Tete_Fait;					//Initialisation du fait actuel a la tete
	Fait_Buffer = Fait_Actuel;					//Initialisation du buffer a la tete
	
	AntiCR(sSupprimeFait);						//Suppression de \n

	while( Fait_Actuel != NULL )					//Tant que qu'il y a des fait
	{
		if( strcmp( (*Tete_Fait)->sValeur, sSupprimeFait ) == 0 )	//Si le fait a supprimer = le fait de la tete
		{
			(*Tete_Fait) = (*Tete_Fait)->Fait_Suivant;		//La tete pointe vers le fait suivant
			free(Fait_Actuel);					//Libere la memoire de l'ancienne tete
			return 0;
		}
		else
		{
			if( strcmp( Fait_Actuel->sValeur, sSupprimeFait ) == 0 )	//Si le fait a supprimer = le fait actuel
			{
				Fait_Buffer->Fait_Suivant = Fait_Actuel->Fait_Suivant;	//Le suivant du precedent pointe vers le suivant de l'actuel
				free(Fait_Actuel);					//Libere la memoire de l'actuel
				return 0;
			}
		}
		Fait_Buffer = Fait_Actuel;						//Le precedent = l'actuel
		Fait_Actuel = Fait_Actuel->Fait_Suivant;				//Deplacement de l'actuel vers le suivant
	}

	return -1;	
}

/*******************************************************************/
/*******************************************************************/

/*******************************************************************/
/*******************************************************************/
