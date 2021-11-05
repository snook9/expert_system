//***********************Jonathan CASSAING************************************************************************************************
//***********************v1.0 -> 12/02/2009***********************************************************************************************
//****************************************************************************************************************************************

//***********************Systeme_Expert_v1.0**********************************************************************************************
//****************************************************************************************************************************************
//****************************************************************************************************************************************


#include "InitMoteur.h"

#define SYSTEME_EXPERT	"__________Systeme_Expert_v1.0__________"				//Version du Systeme_Expert
#define LOOK_REGLES "ls *.bdr"									//Affichage des fichiers regles dispo
#define LOOK_FAITS "ls *.bdf"									//Affichage des fichiers faits dispo

void MenuRegles(Struct_Regle **Tete_Regle, int *iFlag_Presence_Base_Regles);			//Prototypes des fonctions
void MenuFaits(Struct_Fait **Tete_Fait, int *iFlag_Presence_Base_Faits);

void MenuModifBaseRegles(Struct_Regle **Tete_Regle);
void MenuModifBaseFaits(Struct_Fait **Tete_Fait);


//****************************************************************************************************************************************
//********************Fonction int main (void)********************************************************************************************
//****************************************************************************************************************************************
int main(void)
{
	char Poubelle;										//Variable de recuperation du caractere \n
	char sBut[Max];										//But a demontrer pour ChainageAR
	int iFlag_Presence_Base_Regles=0;							//Variable de detection d'une base de regles en memoire
	int iFlag_Presence_Base_Faits=0;							//Variable de detection d'une base de faits en memoire
	int Choix;										//Variable de choix pour les menu
	int Test;										//Variable Test des retours de fonction
	Struct_Regle *Tete_Regle;								//Pointeur tete pour la liste des regles
	Struct_Fait *Tete_Fait;									//Pointeur tete pour la lite des faits

	do
	{
		system(CLEAN);									//effacer l'ecran, CLEAN est definit dans InitMoteur.h
		printf("\n\t"SYSTEME_EXPERT"\n\n");						//Affichage du menu main
		printf("\t(0) Lancer un chainage avant\n");
		printf("\t(1) Lancer un chainage arriere\n");
		printf("\n\t(2) Menu base de faits\n");
		printf("\t(3) Menu base de regles\n");
		printf("\n\t(4) Quitter\n");
		printf("\nVotre choix : ");
		scanf("%d",&Choix);
		scanf("%c",&Poubelle);

		switch(Choix)
		{
			case 0 :
				if( iFlag_Presence_Base_Regles==1 && iFlag_Presence_Base_Faits==1)	//Lancement d'un chainage avant seulement si 	les bases sont presentes en memoire
				{				
					if( fChainageAV(Tete_Regle, Tete_Fait)==-1 )printf("Echec fChainageAV");
					else printf("\nChainage avant termine");
				}
				else
				{
					printf("\nAucune base en memoire");			//Sinon erreur
				}
				
				printf("\n\nTAPEZ ENTRER");
				getc(stdin);
			break;

			case 1 :
				if( iFlag_Presence_Base_Regles==1 && iFlag_Presence_Base_Faits==1)	//Lancement d'un chainage arriere seulement si les bases sont presentes en memoire
				{
					memset(sBut, 0, Max);					
					printf("\nEntrez le but a demontrer : ");
					fgets(sBut,Max,stdin);
					AntiCR(sBut);
					Test=fChainageAR( sBut, Tete_Regle, Tete_Fait);

					if( Test==1 )printf("But demontre");
					else if( Test==0 )printf("But NON demontre");
					else if( Test==-1 )printf("Echec fChainageAR");
				}
				else
				{
					printf("\nAucune base en memoire");			//Sinon erreur
				}

				printf("\n\nTAPEZ ENTRER");
				getc(stdin);
			break;

			case 2 :
				MenuFaits(&Tete_Fait, &iFlag_Presence_Base_Faits);			//Menu de la base de faits	
			break;

			case 3 :
				MenuRegles(&Tete_Regle, &iFlag_Presence_Base_Regles);			//Menu de la base de regles
			break;

			case 4 :
				printf("\nFin du programme\n\n");					//Fin du programme
				return 0;
			break;

			default :									//Recuperation des autres caracteres tapes par l'utilisateur
			break;
		}
	}while(1);
}

//****************************************************************************************************************************************
//********************Fonction void MenuRegles(void)**************************************************************************************
//****************************************************************************************************************************************
void MenuRegles(Struct_Regle **Tete_Regle, int *iFlag_Presence_Base_Regles)
{
	char sPath_Fichier[Max];									//Chemin de la base
	char Poubelle;
	int Choix;

	do
	{
		system(CLEAN);
		printf("\n\tMenu base de regles\n\n");
		printf("\t(0) Creer une base de regles\n");
		printf("\t(1) Afficher la base de regles\n");
		printf("\t(2) Modifier la base de regles\n");
		printf("\t(3) Supprimer la base de regles\n");
		printf("\n\t(4) Sauvegarder la base de regles\n");
		printf("\t(5) Charger une base de regles\n");
		printf("\n\t(6) Quitter\n");
		printf("\nVotre choix : ");
		scanf("%d",&Choix);
		scanf("%c",&Poubelle);

		switch(Choix)
		{
			case 0 :				
				if( (*iFlag_Presence_Base_Regles) == 0)					//Creation d'une base de regle seulement si une base n'existe pas deja
				{				
					if( fCreerBaseRegle(Tete_Regle)==-1 )printf("\nEchec fCreerBaseRegle");
					(*iFlag_Presence_Base_Regles) = 1;
				}
				else printf("\nAttention, base existante : Veuillez la supprimer");	//Sinon erreur
				printf("\n\nTAPEZ ENTRER");
				getc(stdin);			
			break;

			case 1 :
				if( (*iFlag_Presence_Base_Regles)==1 )					//Affichage de la base seulement si elle existe
				{				
					system(CLEAN);					
					if( fAfficherBaseRegle( (*Tete_Regle) )==-1 )printf("\nEchec fAfficherBaseRegle");
				}
				else
				{
					printf("\nAucune base en memoire");				//Sinon erreur
				}
				printf("\n\nTAPEZ ENTRER");
				getc(stdin);							
			break;

			case 2 :				
				if( (*iFlag_Presence_Base_Regles)==1 )
				{				
					MenuModifBaseRegles(Tete_Regle);				//Sous menu de modification de la base
				}
				else
				{
					printf("\nAucune base de regles en memoire");
					printf("\n\nTAPEZ ENTRER");
					getc(stdin);
				}						
			break;

			case 3 :				
				if( (*iFlag_Presence_Base_Regles)==1 )					//Suppression de la base seulement si elle existe
				{				
					fSupprimerBaseRegle( (*Tete_Regle) );
					(*iFlag_Presence_Base_Regles) = 0;
					printf("\nBase supprimee");
				}
				else
				{
					printf("\nAucune base de regles en memoire");			//Sinon erreur
				}

				printf("\n\nTAPEZ ENTRER");
				getc(stdin);				
			break;

			case 4 :
				if( (*iFlag_Presence_Base_Regles)==1 )					//Sauvegarde de la base si elle est presente en memoire
				{				
					memset(sPath_Fichier, 0, Max);
					printf("\nBases actuelles :\n");
					system(LOOK_REGLES);				
					printf("\nEntrez le chemin du fichier : ");
					fgets(sPath_Fichier,Max,stdin);
					if( fSauverBaseRegle( (*Tete_Regle), sPath_Fichier)==-1 )printf("\nEchec fSauverBaseRegle");
					else printf("\nBase sauvegarde");
				}
				else
				{
					printf("\nAucune base de faits en memoire");			//Sinon erreur
				}

				printf("\n\nTAPEZ ENTRER");
				getc(stdin);	
			break;

			case 5 :
				if( (*iFlag_Presence_Base_Regles)==1 )printf("\nAttention, base existante : Veuillez la supprimer");
				else
				{
					memset(sPath_Fichier, 0, Max);
					printf("\nBases disponnibles :\n");
					system(LOOK_REGLES);			
					printf("\nEntrez le chemin du fichier : ");
					fgets(sPath_Fichier,Max,stdin);

					if( fChargerBaseRegle(Tete_Regle, sPath_Fichier)==-1 )printf("\nEchec fChargerBaseRegle : Fichier introuvable");
					else
					{
						(*iFlag_Presence_Base_Regles) = 1; 
						printf("\nBase charge");
					}
				}
				printf("\n\nTAPEZ ENTRER");
				getc(stdin);	
			break;

			case 6 :				
				return;			
			break;

			default :
			break;
		}

	}while(1);
}

//****************************************************************************************************************************************
//********************Fonction void MenuFaits(void)***************************************************************************************
//****************************************************************************************************************************************
void MenuFaits(Struct_Fait **Tete_Fait, int *iFlag_Presence_Base_Faits)
{
	char sPath_Fichier[Max];									//Meme fonctionnement que pour la base de regles
	char Poubelle;
	int Choix;

	do
	{
		system(CLEAN);
		printf("\n\tMenu base de faits\n\n");
		printf("\t(0) Creer une base de faits\n");
		printf("\t(1) Afficher la base de faits\n");
		printf("\t(2) Modifier la base de faits\n");
		printf("\t(3) Supprimer la base de faits\n");
		printf("\n\t(4) Sauvegarder la base de faits\n");
		printf("\t(5) Charger une base de faits\n");
		printf("\n\t(6) Quitter\n");
		printf("\nVotre choix : ");
		scanf("%d",&Choix);
		scanf("%c",&Poubelle);

		switch(Choix)
		{
			case 0 :
				if( (*iFlag_Presence_Base_Faits) == 0 )
				{
					if( fCreerBaseFait(Tete_Fait)==-1 )printf("\nEchec fCreerBaseFait");
					(*iFlag_Presence_Base_Faits) = 1;
				}
				else printf("\nAttention, base existante : Veuillez la supprimer");
				printf("\n\nTAPEZ ENTRER");
				getc(stdin);			
			break;

			case 1 :
				if( (*iFlag_Presence_Base_Faits)==1 )
				{				
					system(CLEAN);					
					if( fAfficherBaseFait( (*Tete_Fait) )==-1 )printf("\nEchec fAfficherBaseFait");
				}
				else
				{
					printf("\nAucune base de faits en memoire");
				}
				printf("\n\nTAPEZ ENTRER");
				getc(stdin);			
			break;

			case 2 :
				if( (*iFlag_Presence_Base_Faits)==1 )
				{				
					MenuModifBaseFaits(Tete_Fait);
				}
				else
				{
					printf("\nAucune base de faits en memoire");
					printf("\n\nTAPEZ ENTRER");
					getc(stdin);
				}			
			break;

			case 3 :
				if( (*iFlag_Presence_Base_Faits)==1 )
				{				
					fSupprimerBaseFait( (*Tete_Fait) );
					(*iFlag_Presence_Base_Faits) = 0;
					printf("\nBase supprimee");
				}
				else
				{
					printf("\nAucune base de regles en memoire");
				}				

				printf("\n\nTAPEZ ENTRER");
				getc(stdin);			
			break;
				
			case 4 :
				if( (*iFlag_Presence_Base_Faits)==1 )
				{				
					memset(sPath_Fichier, 0, Max);
					printf("\nBases actuelles :\n");
					system(LOOK_FAITS);					
					printf("\nEntrez le chemin du fichier : ");
					fgets(sPath_Fichier,Max,stdin);
					if( fSauverBaseFait( (*Tete_Fait), sPath_Fichier)==-1 )printf("\nEchec fSauverBaseFait");
					else printf("\nBase sauvegarde");
				}
				else
				{
					printf("\nAucune base de faits en memoire");
				}

				printf("\n\nTAPEZ ENTRER");
				getc(stdin);			
			break;
	
			case 5 :
				if( (*iFlag_Presence_Base_Faits)==1 )printf("\nAttention, base existante : Veuillez la supprimer");
				else
				{
					memset(sPath_Fichier, 0, Max);
					printf("\nBases disponnibles :\n");
					system(LOOK_FAITS);			
					printf("\nEntrez le chemin du fichier : ");
					fgets(sPath_Fichier,Max,stdin);

					if( fChargerBaseFait(Tete_Fait, sPath_Fichier)==-1 )printf("\nEchec fChargerBaseFait : Fichier introuvable");
					else
					{
						(*iFlag_Presence_Base_Faits) = 1;
						printf("\nBase charge");
					}
				}
				printf("\n\nTAPEZ ENTRER");
				getc(stdin);			
			break;

			case 6 :
				return;
			break;

			default :
			break;
		}
	}while(1);
}

//****************************************************************************************************************************************
//********************Fonction void MenuModifBaseFaits(void)******************************************************************************
//****************************************************************************************************************************************
void MenuModifBaseFaits(Struct_Fait **Tete_Fait)
{
	char sNouveauFait[Max];										//Pour l'ajout d'un nouveau fait
	char sSupprimeFait[Max];									//Pour la suppression d'un fait
	char Poubelle;
	int Choix;

	do
	{
		system(CLEAN);
		printf("\n\tMenu modification de la base de faits\n\n");
		printf("\t(0) Creer un fait\n");
		printf("\t(1) Supprimer un fait\n");
		printf("\n\t(2) Quitter\n");
		printf("\nVotre choix : ");
		scanf("%d",&Choix);
		scanf("%c",&Poubelle);

		switch(Choix)
		{
			case 0 :
				memset(sNouveauFait, 0, Max);						//Ajout d'un nouveau fait
				printf("\nEntrez un nouveau fait : ");
				fgets(sNouveauFait,Max,stdin);

				if( fCreerFait( (*Tete_Fait), sNouveauFait)==-1 )printf("\nEchec fCreerFait");
				else printf("\nFait ajoute : ");

				printf("\n\nTAPEZ ENTRER");
				getc(stdin);
			break;

			case 1 :
				memset(sSupprimeFait, 0, Max);						//Suppression d'un fait	
				printf("\nEntrez le fait a supprimer : ");
				fgets(sSupprimeFait,Max,stdin);

				if( fSupprimerFait(Tete_Fait, sSupprimeFait)==-1 )printf("\nFait inexistant");
				else printf("\nFait supprime : ");

				printf("\n\nTAPEZ ENTRER");
				getc(stdin);
			break;

			case 2 :
				return;
			break;

			default :
			break;
		}
	}while(1);
}

//****************************************************************************************************************************************
//********************Fonction void MenuModifBaseRegles(void)*****************************************************************************
//****************************************************************************************************************************************
void MenuModifBaseRegles(Struct_Regle **Tete_Regle)
{	
	char Poubelle;
	int Choix;
	int NRegle;											//Numero de la regle a rechercher

	do
	{
		system(CLEAN);
		printf("\n\tMenu modification de la base de regles\n\n");
		printf("\t(0) Creer une regle\n");
		printf("\t(1) Modifier une regle\n");
		printf("\t(2) Supprimer une regle\n");
		printf("\n\t(3) Quitter\n");
		printf("\nVotre choix : ");
		scanf("%d",&Choix);
		scanf("%c",&Poubelle);

		switch(Choix)
		{
			case 0 :
				if( fCreerRegle( (*Tete_Regle) )==-1 )printf("\nEchec fCreerRegle");	//Creation d'une nouvelle regle

				printf("\nTAPEZ ENTRER");
				getc(stdin);
			break;

			case 1 :
				if( fModifierRegle(Tete_Regle)==-1 )printf("\nEchec fModifierRegle");	//Modification d'une regle existante

				printf("\nTAPEZ ENTRER");
				getc(stdin);
			break;

			case 2 :			
				printf("\nEntrez le numero de la regle a supprimer : ");		//Suppression d'une regle
				scanf("%d",&NRegle);
				scanf("%c",&Poubelle);
				if( fSupprimerRegle(Tete_Regle, NRegle)==-1 )printf("\nEchec fSupprimerRegle");

				printf("\nTAPEZ ENTRER");
				getc(stdin);
			break;

			case 3 :
				return;
			break;

			default :
			break;
		}
	}while(1);
}


//****************************************************************************************************************************************
//****************************************************************************************************************************************
//****************************************************************************************************************************************

//****************************************************************************************************************************************
//****************************************************************************************************************************************
//****************************************************************************************************************************************
