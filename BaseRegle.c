/********************CASSAING Jonathan******************************/

/********************BaseRegle.c*************************************/
/********************v1.0 -> 12/02/2009*****************************/


#include "InitMoteur.h"
#include "BaseRegle.h"


/*******************************************************************/
/*******************************************************************/
int fCreerRegle(Struct_Regle *Tete_Regle)
{
	int j,i=1;	
	char Choix = 'O',Poubelle;

	if( Tete_Regle == NULL )	//au cas ou la base n'existe pas
	{
		return -1;
	}
	

	Struct_Regle *Nouvelle_Struct_Regle;	//Nouvelle Regle à entrer
	Struct_Regle *RegleAct;			//curseur

	RegleAct = Tete_Regle;			//on pointe vers le début de la base

	Nouvelle_Struct_Regle=(Struct_Regle *)malloc( sizeof(Struct_Regle) );	//allocation de la mémoire de la nouvelle Regle
	Nouvelle_Struct_Regle -> Premiere_Hypothese = (Struct_Hypothese *)malloc( sizeof(Struct_Hypothese) );
	//allocation de la mém pour la structure hypothese
	
	Struct_Hypothese *Hypothese;


	while( RegleAct->Regle_Suivante != NULL )	//on se décale jusqu'à la fin
	{
		RegleAct = RegleAct->Regle_Suivante;
	}

	j=RegleAct->iNumero;			//on récupère le numéro de la dernière règle
	
	RegleAct->Regle_Suivante = Nouvelle_Struct_Regle;	//on pointe vers la nouvelle regle en fin de base
	Nouvelle_Struct_Regle->Regle_Suivante = NULL;		//qui pointe vers NULL

	Hypothese =  Nouvelle_Struct_Regle->Premiere_Hypothese;	//hypothese pointe au début vers la 1° hypothese
	Hypothese->Hypothese_Suivante = NULL;
	
	
	printf("\nEntrez la Conclusion à la Regle %d : ",j+1);
	scanf("%s",Nouvelle_Struct_Regle->sConclusion);
	scanf("%c",&Poubelle);
	
	Nouvelle_Struct_Regle->iNumero = j+1;		//numéro de la nouvelle Regle

	printf("\n Entrez l'hypothese n°%d : ",i);
	scanf("%s",Hypothese->sHypothese);	//on écrit l'hypothese dans l'hypothese
	scanf("%c",&Poubelle);

	printf("\n Voulez vous entrer une nouvelle hypothese ? (O/N) : ");
	scanf("%c",&Choix);	
	scanf("%c",&Poubelle);
	
	while(Choix!='O'&&Choix!='N')
	{
		printf("\nATTENTION erreur de saisie");
		printf("\n Voulez vous entrer une nouvelle hypothese ? (O/N) : ");
		scanf("%c",&Choix);	
		scanf("%c",&Poubelle);
	}

	for( i=2 ; Choix == 'O'; i++ )
	{	
		Hypothese -> Hypothese_Suivante  = (Struct_Hypothese *)malloc( sizeof(Struct_Hypothese) );//allou la mémoire pour l'H suivante
		Hypothese =  Hypothese->Hypothese_Suivante;						//on se décale

		Hypothese->Hypothese_Suivante = NULL;							//elle pointe vers NULL


		printf("\n Entrez l'hypothese n°%d : ",i);
		scanf("%s",Hypothese->sHypothese);	//on écrit l'hypothese dans l'hypothese
		scanf("%c",&Poubelle);

		//printf("\n2%s ",Hypothese -> sHypothese);//#


		printf("\n Voulez vous entrer une nouvelle hypothese ? (O/N) : ");
		scanf("%c",&Choix);	
		scanf("%c",&Poubelle);

		while(Choix!='O'&&Choix!='N')
		{
			printf("\nATTENTION erreur de saisie");
			printf("\n Voulez vous entrer une nouvelle hypothese ? (O/N) : ");
			scanf("%c",&Choix);	
			scanf("%c",&Poubelle);
		}
	}

	
	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fCreerBaseRegle( Struct_Regle **Tete_Regle )
{	
	char Choix = 'O',Poubelle;
	int i=1;

	*Tete_Regle=(Struct_Regle *)malloc( sizeof(Struct_Regle) );	//allocation mémoire de la structure Regle
	
	(*Tete_Regle) -> Premiere_Hypothese = (Struct_Hypothese *)malloc( sizeof(Struct_Hypothese) );//allocation de la mém pour la structure hypothese

	Struct_Hypothese *Hypothese;

	//(*Hypothese) = *((*Tete_Regle)->Premiere_Hypothese);	//hypothese pointe au début vers la 1° hypothese

	Hypothese =  (*Tete_Regle)->Premiere_Hypothese;	//hypothese pointe au début vers la 1° hypothese
	Hypothese->Hypothese_Suivante = NULL;
	(*Tete_Regle)->Regle_Suivante = NULL;

	if( *Tete_Regle == NULL )
	{
		return -1;
	}

	(*Tete_Regle)->Regle_Suivante=NULL;

	printf("\nEntrez la Conclusion : ");
	scanf("%s",(*Tete_Regle)->sConclusion);
	scanf("%c",&Poubelle);
	
	(*Tete_Regle)->iNumero = 1;

	printf("\n Entrez l'hypothese n°%d : ",i);
	scanf("%s",Hypothese->sHypothese);	//on écrit l'hypothese dans l'hypothese
	//scanf("%s"(*Tete_Regle)->Premiere_Hypothese);
	scanf("%c",&Poubelle);
	//printf("\n1%s ",Hypothese -> sHypothese);//#



	printf("\n Voulez vous entrer une nouvelle hypothese ? (O/N) : ");
	scanf("%c",&Choix);	
	scanf("%c",&Poubelle);
	
	while(Choix!='O'&&Choix!='N')
	{
		printf("\nATTENTION erreur de saisie");
		printf("\n Voulez vous entrer une nouvelle hypothese ? (O/N) : ");
		scanf("%c",&Choix);	
		scanf("%c",&Poubelle);
	}

	for( i=2 ; Choix == 'O'; i++ )
	{	
		Hypothese -> Hypothese_Suivante  = (Struct_Hypothese *)malloc( sizeof(Struct_Hypothese) );//allou la mémoire pour l'H suivante
		Hypothese =  Hypothese->Hypothese_Suivante;						//on se décale

		Hypothese->Hypothese_Suivante = NULL;							//elle pointe vers NULL


		printf("\n Entrez l'hypothese n°%d : ",i);
		scanf("%s",Hypothese->sHypothese);	//on écrit l'hypothese dans l'hypothese
		scanf("%c",&Poubelle);

		//printf("\n2%s ",Hypothese -> sHypothese);//#


		printf("\n Voulez vous entrer une nouvelle hypothese ? (O/N) : ");
		scanf("%c",&Choix);	
		scanf("%c",&Poubelle);

		while(Choix!='O'&&Choix!='N')
		{
			printf("\nATTENTION erreur de saisie");
			printf("\n Voulez vous entrer une nouvelle hypothese ? (O/N) : ");
			scanf("%c",&Choix);	
			scanf("%c",&Poubelle);
		}
	}

	//AFFICHAGE


	Hypothese =  (*Tete_Regle)->Premiere_Hypothese;
	//printf("\n3%s ",Hypothese -> sHypothese);//#

	//printf("\n Règle %d : ",(*Tete_Regle)->iNumero);


	while( Hypothese != NULL)
	{
		printf("%s ",Hypothese -> sHypothese);
		Hypothese =  Hypothese->Hypothese_Suivante;
	}

	printf("-> %s\n\n",(*Tete_Regle)->sConclusion);

	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fAfficherBaseRegle(Struct_Regle *Tete_Regle)
{
	Struct_Regle *RegleAct;
	Struct_Hypothese *Hypothese;

	printf("\n____________________Affichage de la base de Regles____________________\n\n");	

	if( Tete_Regle == NULL )
	{
		printf("\nBase de regles vide");
		return -1;
	}

	RegleAct = Tete_Regle;

	while( RegleAct != NULL )
	{
		printf("Regle %4d : ",RegleAct->iNumero);
		Hypothese =  RegleAct->Premiere_Hypothese;

		while( Hypothese != NULL)
		{
			printf("%s ",Hypothese -> sHypothese);
			Hypothese =  Hypothese->Hypothese_Suivante;
		}

		printf("-> %s\n",RegleAct->sConclusion);

		RegleAct = RegleAct -> Regle_Suivante;

	}

	return 0;
}

/*******************************************************************/
/*Attention : fonction recursive************************************/
void fSupprimerHypothese(Struct_Hypothese *Hypothese)
{
	if(Hypothese == NULL)
	{
		return;
	}
	fSupprimerHypothese( Hypothese->Hypothese_Suivante);

	free(Hypothese);
}

/*******************************************************************/
/*Attention : fonction recursive************************************/
void fSupprimerBaseRegle(Struct_Regle *Tete_Regle)
{
	if( Tete_Regle == NULL )
	{
		return ;
	}
	fSupprimerBaseRegle( Tete_Regle->Regle_Suivante );

	fSupprimerHypothese( Tete_Regle->Premiere_Hypothese );

	free( Tete_Regle );	
}

/*******************************************************************/
/*******************************************************************/
int fSupprimerRegle(Struct_Regle **Tete_Regle, int NRegle)
{

	Struct_Regle *RegleAct;
	Struct_Regle *RegleBuff;
	
	RegleAct = *Tete_Regle;
	//printf("RegleAct -> inuméri = %d",RegleAct->iNumero);
	
	while( RegleAct->iNumero != NRegle )
	{
		RegleBuff = RegleAct;
		RegleAct = RegleAct -> Regle_Suivante;

		if(RegleAct==NULL)
		{
			printf("\nErreur! pas de Regle à ce numéro");
			return -1;
		}
	}
	//on a RegleBuff qui est à la regle précedente de celle à supprimer
	// RegleAct qui est celle à supprimer

	if(RegleAct==*Tete_Regle && RegleAct->Regle_Suivante == NULL)	//La regle est seule dans la base
	{
		printf("\n Erreur, Regle seule dans la base, veuillez supprimer la base");
		return -1;
	}
		
	if(RegleAct==*Tete_Regle)	//Celle à supprimer est la 1°
	{
		printf("\nC'est la première");
		RegleBuff=*Tete_Regle;
		*Tete_Regle = (*Tete_Regle)->Regle_Suivante;
		printf("\nNouvelle tete regle : %s",( *Tete_Regle)->sConclusion);
		free (RegleBuff);
		return 0;
	}
	else
	{	

		if(RegleAct->Regle_Suivante != NULL) //celle à supprimer n'est pas la dernière
		{	
			printf("\nCe n'est pas la dernière");
			RegleBuff->Regle_Suivante = (RegleBuff->Regle_Suivante)->Regle_Suivante;	//on saute une regle dans la chaine
		}
		else				    //celle à supprimer est la dernière
		{
			printf("\n C'est la dernière ");
			RegleBuff->Regle_Suivante = NULL;
		}
	}

	printf("\n Regle Act : %s",RegleAct->sConclusion);
	free(RegleAct);	//free la regle supprimée
	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fModifierRegle(Struct_Regle **Tete_Regle)
{
	char Poubelle;	

	Struct_Regle *RegleAct;

	int NRegle;
	RegleAct = *Tete_Regle;

	if(fAfficherBaseRegle(*Tete_Regle)!=0)
	{
		return -1;
	}

	printf("\nQuelle regle souhaitez-vous Modifier : ");
	scanf("%d",&NRegle);
	scanf("%c",&Poubelle);	

	while( RegleAct->iNumero != NRegle )
	{
		RegleAct = RegleAct -> Regle_Suivante;

		if(RegleAct==NULL)
		{
			printf("\nErreur! pas de Regle à ce numéro");
			return -1;
		}
	}

	if(fSupprimerRegle(Tete_Regle,RegleAct->iNumero)!=0 )
	{
		return-1;
	}

	fAfficherBaseRegle(*Tete_Regle);

	if(fCreerRegle(*Tete_Regle)!=0)
	{
		return -1;
	}
	
	return 0;
	
}

/*******************************************************************/
/*******************************************************************/
int fSauverBaseRegle(Struct_Regle *Tete_Regle, char *Path_Fichier)
{
	FILE *Fic;
	Struct_Regle *Regle_Actuelle;					//Pointeur de deplacement dans la liste des regles
	Struct_Hypothese *Hypothese_Actuelle;				//Pointeur de deplacement dans la liste des hypotheses
	int Choix;							//Variable de choix pour le menu
	char Poubelle;							//Variable de recuperation du caractere \n apres un scanf

	Choix=1;
	AntiCR(Path_Fichier);						//Suppression du \n a la fin de Path_Fichier

	if( Tete_Regle == NULL )					//Quitter si Tete_Regle==NULL
	{
		printf("\nBase de regles vide");
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
			printf("\nErreur d'ouverture (Fonction fSauverBaseRegle)");
			return -1;
		}

		Regle_Actuelle = Tete_Regle;				//Pointeur de deplacement dans la base de regles initialise
		Hypothese_Actuelle = Tete_Regle->Premiere_Hypothese;	//Pointeur de deplacement dans la base des hypotheses initialise

		while( Regle_Actuelle != NULL )					//Tant qu'il y a des regles
		{
			while( Hypothese_Actuelle != NULL )					//Tant qu'il y a des hypotheses
			{
				fprintf(Fic,"%s ",Hypothese_Actuelle->sHypothese);		//Ecriture de l'hypothese actuelle dans le fichier
				Hypothese_Actuelle = Hypothese_Actuelle->Hypothese_Suivante;	//Deplacement vers l'hypothese suivante
			}

			fprintf(Fic,"-> %s;",Regle_Actuelle->sConclusion);	//Ecriture de la conclusion de la regle dans le fichier
			Regle_Actuelle = Regle_Actuelle->Regle_Suivante;	//Deplacement vers la regle suivante
			if( Regle_Actuelle != NULL )Hypothese_Actuelle = Regle_Actuelle->Premiere_Hypothese;	//Si la regle suivante n'est pas NULL, deplacement vers l'hypothese suivante
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
int fChargerBaseRegle(Struct_Regle **Tete_Regle, char *Path_Fichier)
{
	FILE *Fic;
	Struct_Regle *Regle_Actuelle;		//Pointeur de deplacement
	Struct_Regle *Sup_Regle_Actuelle;	//Pointeur de deplacement dans la partie "suppression de la memoire en trop"
	Struct_Regle *Sup_Regle_Buffer;		//Pointeur buffer dans la partie "suppression de la memoire en trop"

	char sBuffer[Max];			//Buffer de lecture
	char sHypothese[Max]="";		//Buffer de l'hypothese
	char sConclusion[Max]="";		//Buffer de la conclusion
	int iHypo;				//Variable de detection d'une hypothese/conclusion
	int i;					//Variable de deplacement dans sBuffer
	int cpt;				//Variable de numerotation des regles
	int iFirst_Hypo;			//Variable de detection de la premiere hypothese
	int iFirst_Conc;			//Variable de detection de la premiere conclusion

	cpt=1;					//Initialisation du numero
	iHypo=1;				//Le premier caractere lut sera une hypothese
	i=0;					//Initialisation de la variable de deplacement dans sBuffer
	iFirst_Hypo=0;				//La premiere lecture sera une premiere hypothese
	iFirst_Conc=0;				//La premiere lecturre sera une premiere conclusion
	AntiCR(Path_Fichier);			//Suppression de \n en fin de chaine Path_Fichier

	Fic=fopen(Path_Fichier,"r");		//Ouverture du fichier en lecture
	if(Fic==NULL)
	{
		printf("\nErreur d'ouverture (Fonction fChargerBaseRegle)");		//Quitter si echec d'ouverture
		return -1;
	}

	(*Tete_Regle)=(Struct_Regle *)malloc( sizeof(Struct_Regle) );
	if( (*Tete_Regle) == NULL )							//Quitter si echec d'allocation de memoire
	{
		return -1;
	}

	(*Tete_Regle)->Premiere_Hypothese=(Struct_Hypothese *)malloc( sizeof(Struct_Hypothese) );
	if( (*Tete_Regle)->Premiere_Hypothese == NULL )					//Quitter si echec d'allocation de memoire
	{
		return -1;
	}

	Regle_Actuelle = (*Tete_Regle);	

	
	(*Tete_Regle)->Regle_Suivante=NULL;						//Mise a NULL du pointeur suivant
	memset((*Tete_Regle)->sConclusion, 0, Max);					//Vidage de la conclusion de la regle

	while( fread(&sBuffer[i],1,1,Fic)!=0 && !feof(Fic) )				//Boucle de lecture
	{
		if(iFirst_Hypo==0)								//Si iFirst_Hypo==0, la prochaine hypothese est une hypothese de tete
		{		
			if( sBuffer[i]==' ' && sBuffer[i-1]=='>' &&sBuffer[i-2]=='-' )		//Si les caracteres precedent etaient " ->"
			{
				iHypo=0;							//Detection d'une conclusion
			}
			else
			{
				if( iHypo==1 && sBuffer[i]!=' ' && sBuffer[i]!='-' && sBuffer[i]!='>' && sBuffer[i]!=';' && sBuffer[i]!='\n' && sBuffer[i]!='\r')
				{								//Si iHypo==1, donc la prochaine chaine est une hypothese
					sprintf(sHypothese,"%s%c",sHypothese,sBuffer[i]);	//Si le caractere lut est different des caracteres de commandes : " ->;\n\r", concatenation du buffer de lecture dans la nouvelle hypothese			
				}
				else
				{
					if( iHypo==1 && sBuffer[i]==' ' )			//Si le caractere lut est un espace, l'hypothese est complete
					{
						strcpy( Regle_Actuelle->Premiere_Hypothese->sHypothese, sHypothese);	//Ecriture de l' hypothese de tete

						memset( sHypothese, 0, Max);			//Mise a 0 du buffer hypothese
						memset( sBuffer, 0, Max);			//Mise a 0 du buffer de lecture
						i=0;						//Mise a 0 de la variable de deplacement dans le buffer de lecture
						iFirst_Hypo=1;					//La prochaine hypothese ne sera pas une hypothese de tete
						
					}
				}
			}
		}
		else										//Si la prochaine hypothese n'est pas une hypothese de tete
		{
			if( sBuffer[i]==' ' && sBuffer[i-1]=='>' &&sBuffer[i-2]=='-' )		//Si les caracteres precedent etaient " ->"
			{
				iHypo=0;							//Detection d'une conclusion
			}
			else
			{
				if( iHypo==1 && sBuffer[i]!=' ' && sBuffer[i]!='-' && sBuffer[i]!='>'&& sBuffer[i]!=';' && sBuffer[i]!='\n' && sBuffer[i]!='\r')
				{
					sprintf(sHypothese,"%s%c",sHypothese,sBuffer[i]);	//Meme principe que plus haut			
				}
				else
				{
					if( iHypo==1 && sBuffer[i]==' ' )
					{
						fCreerHypothese( Regle_Actuelle->Premiere_Hypothese, sHypothese);	//Ici, nous rentrons dans une fonction qui ajoute l'hypothese en fin de liste
						memset( sHypothese, 0, Max);
						memset( sBuffer, 0, Max);
						i=0;
					}
				}
			}
		}

		if(iFirst_Conc==0)								//Si la prochaine conclusion est une conclusion de tete
		{
			if( iHypo==0 && sBuffer[i]!=' ' && sBuffer[i]!='-' && sBuffer[i]!='>' && sBuffer[i]!=';' && sBuffer[i]!='\n' && sBuffer[i]!='\r')
			{
				sprintf(sConclusion,"%s%c",sConclusion,sBuffer[i]);		//Meme principe que plus haut
			}
			else
			{	
				if( iHypo==0 && sBuffer[i]==';' )				//Si iHypo==0, la prochaine chaine sera une conclusion
				{								//Si le caractere lut est le caractere ; de separation des regles
					iHypo=1;						//La prochaine chaine sera une hypothese

					strcpy( (*Tete_Regle)->sConclusion, sConclusion);	//Ecriture de la conclusion
					(*Tete_Regle)->iNumero = cpt;				//Incrementation du numero
					cpt++;
				
					Regle_Actuelle->Regle_Suivante=(Struct_Regle *)malloc( sizeof(Struct_Regle) );	//Allocation de memoire pour la prochaine regle
					if( Regle_Actuelle->Regle_Suivante == NULL )							//Quitter si echec d'allocation de memoire
					{
						return -1;
					}

					Regle_Actuelle = Regle_Actuelle->Regle_Suivante;	//Deplacement de la regle actuelle a la suivante

					Regle_Actuelle->Premiere_Hypothese=(Struct_Hypothese *)malloc( sizeof(Struct_Hypothese) );	//Allocation de memoire pour la prochaine hypothese
					if( Regle_Actuelle->Premiere_Hypothese == NULL )							//Quitter si echec d'allocation de memoire
					{
						return -1;
					}

					memset( sConclusion, 0, Max);				//Remise a 0 des buffers
					memset( sBuffer, 0, Max);
					iFirst_Conc=1;						//La prochaine conclusion ne sera plus la premiere conclusion
					iFirst_Hypo=0;						//La prochaine hypothese sera une hypothese tete
					i=0;
					
				}
			}
		}
		else
		{

			if( iHypo==0 && sBuffer[i]!=' ' && sBuffer[i]!='-' && sBuffer[i]!='>' && sBuffer[i]!=';' && sBuffer[i]!='\n' && sBuffer[i]!='\r')
			{
				sprintf(sConclusion,"%s%c",sConclusion,sBuffer[i]);		//Meme principe que plus haut
			}
			else
			{	
				if( iHypo==0 && sBuffer[i]==';' )
				{
					iHypo=1;						//Detection d'une hypothese
					fCreerConclusion( (*Tete_Regle), sConclusion,cpt);	//Ajout de la conclusion en fin de liste
					cpt++;							//Incrementation du numero
					Regle_Actuelle->Regle_Suivante=(Struct_Regle *)malloc( sizeof(Struct_Regle) );			//Allocations de memoire comme plus haut
					if( Regle_Actuelle->Regle_Suivante == NULL )							//Quitter si echec d'allocation de memoire
					{
						return -1;
					}

					Regle_Actuelle = Regle_Actuelle->Regle_Suivante;	//Deplacement de la regle actuelle a la suivante

					Regle_Actuelle->Premiere_Hypothese=(Struct_Hypothese *)malloc( sizeof(Struct_Hypothese) );
					if( Regle_Actuelle->Premiere_Hypothese == NULL )							//Quitter si echec d'allocation de memoire
					{
						return -1;
					}

					Regle_Actuelle-> Regle_Suivante = NULL;

					memset( sConclusion, 0, Max);				//Mise a 0 des buffers
					memset( sBuffer, 0, Max);
					i=0;
					iFirst_Hypo=0;						//La prochaine hypothese sera une hypothese tete
				}
			}
		}

		i++;
	}

	//Cette partie libere l'espace memoire en trop pour le chargement : une structure regle a ete reservee en plus pendant le traitement
	Sup_Regle_Actuelle = *Tete_Regle;
	
	while( Sup_Regle_Actuelle->iNumero != 0 )	//On recherche la regle numero 0, car c'est le numero de la regle vide a supprimer
	{
		Sup_Regle_Buffer = Sup_Regle_Actuelle;
		Sup_Regle_Actuelle = Sup_Regle_Actuelle -> Regle_Suivante;

		if(Sup_Regle_Actuelle==NULL)
		{
			printf("\nErreur! pas de Regle à ce numéro");
			return -1;
		}
	}
	//on a RegleBuff qui est à la regle précedente de celle à supprimer
	// RegleAct qui est celle à supprimer

	free(Sup_Regle_Actuelle);
	Sup_Regle_Buffer->Regle_Suivante = NULL;

	if (Fic!=NULL)
	{
		fclose(Fic);
		Fic=NULL;
	}

	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fCreerConclusion(Struct_Regle *Tete_Regle,char *sNouvelleConclusion,int cpt)
{
	Struct_Regle *Regle_Actuelle;					//Pointeur de deplacement dans la liste des regles
	Struct_Regle *Nouvelle_Regle;	

	Regle_Actuelle = Tete_Regle;					//Initialisation du pointeur de deplacement

	//Nouvelle_Regle=(Struct_Regle *)malloc( sizeof(Struct_Regle) );	//Allocation de la memoire

	if( Nouvelle_Regle == NULL )					//Quitter si echec d'allocation de memoire
	{
		return -1;
	}
	
	while( Regle_Actuelle->Regle_Suivante != NULL )					//Tant que la Regle suivante n'est pas NULL
	{
		Regle_Actuelle = Regle_Actuelle->Regle_Suivante;	//Deplacement vers la Regle suivante
	}

	//Regle_Actuelle->Regle_Suivante = Nouvelle_Regle;

	//Regle_Actuelle=(Struct_Regle *)malloc( sizeof(Struct_Regle));

	strcpy(Regle_Actuelle->sConclusion, sNouvelleConclusion);	//Copie de la nouvelle regle dans la nouvelle structure
	Regle_Actuelle->iNumero = cpt;
	Nouvelle_Regle->Regle_Suivante = NULL;				//Suivant de la nouvelle structure a NULL

	return 0;
}

/*******************************************************************/
/*******************************************************************/
int fCreerHypothese(Struct_Hypothese *Tete_Hypothese,char *sNouvelleHypothese)
{
	Struct_Hypothese *Hypothese_Actuelle;					//Pointeur de deplacement dans la liste des Hypotheses
	Struct_Hypothese *Nouvelle_Hypothese;
	
	Hypothese_Actuelle = Tete_Hypothese;					//Initialisation du pointeur de deplacement

	Nouvelle_Hypothese=(Struct_Hypothese *)malloc( sizeof(Struct_Hypothese) );		//Allocation de la memoire

	if( Nouvelle_Hypothese == NULL )					//Quitter si echec d'allocation de memoire
	{
		return -1;
	}
	
	while( Hypothese_Actuelle->Hypothese_Suivante != NULL )					//Tant que l'Hypothese suivante n'est pas NULL
	{
		Hypothese_Actuelle = Hypothese_Actuelle->Hypothese_Suivante;	//Deplacement vers l'Hypothese suivante
	}
	//on est à la dernière hypothese et on doit en ajouter une après	

	Hypothese_Actuelle->Hypothese_Suivante = Nouvelle_Hypothese; //on fait pointer vers la nouvelle hypo
	strcpy(Nouvelle_Hypothese->sHypothese, sNouvelleHypothese);	//Copie de la nouvelle Hypothese dans la nouvelle structure
	Nouvelle_Hypothese->Hypothese_Suivante = NULL;			//Suivant de la nouvelle structure a NULL

	return 0;
}

/*
int fChargerBaseFait(Struct_Fait *Tete_Fait, char *Path_Fichier)
{
	FILE *Fic;
	char cBuffer;
	char sNouveauFait[Max]="";
	int i;

	i=0;
	memset(&sNouveauFait, 0, Max);
	
	Fic=fopen(Path_Fichier,"r");
	if(Fic==NULL)
	{
		printf("\nErreur d'ouverture (Fonction fChargerBaseFait)");
		return -1;
	}

	fSupprimerBaseFait(Tete_Fait);
	*Tete_Fait=(Struct_Fait *)malloc( sizeof(Struct_Fait) );

	if( *Tete_Fait == NULL )
	{
		return -1;
	}

	(*Tete_Fait)->Fait_Suivant=NULL;

	while(fread(&cBuffer,1,1,Fic)!=0 && !feof(Fic))
	{
		if( cBuffer== '\n' && i<2 )
		{		
			i++;
		}		

		if( i==2 )
		{
			sprintf(sNouveauFait,"%s%c",sNouveauFait,cBuffer);
			if( cBuffer == '\n' )
			{
				fCreerFait(Tete_Fait, sNouveauFait);
				memset(&sNouveauFait, 0, Max);
			}
		}	
	}


	if (Fic!=NULL)
	{
		fclose(Fic);
		Fic=NULL;
	}

	return 0;
}


int fSauverBaseFait(Struct_Fait *Tete_Fait, char *Path_Fichier)
{
	FILE *Fic;
	Struct_Fait *Fait_Actuelle;
	int Choix;
	char Poubelle;

	Choix=1;

	if( Tete_Fait == NULL )
	{
		printf("\nBase de fais vide");
		return -1;
	}

	Fic=fopen(Path_Fichier,"r");
	if(Fic!=NULL)
	{
		do
		{
			system(CLEAN);
			printf("\nLe fichier %s existe deja", Path_Fichier);
			printf("\nVoulez vous l'ecraser ?");
			printf("\n\t(0) NON");
			printf("\n\t(1) OUI");
			printf("\nVotre choix : ");
			scanf("%d",&Choix);
			scanf("%c",&Poubelle);
		}while( Choix!=0 && Choix!=1 );
	}
	
	if (Fic!=NULL)
	{
		fclose(Fic);
		Fic=NULL;
	}

	if( Choix==1 )
	{
		Fic=fopen(Path_Fichier,"w");
		if(Fic==NULL)
		{
			printf("\nErreur d'ouverture (Fonction fSauverBaseFait)");
			return -1;
		}

		fprintf(Fic,"\n____________________Base de faits____________________\n\n");	

		Fait_Actuelle = Tete_Fait;

		while( Fait_Actuelle != NULL )
		{
			fprintf(Fic,"%s",Fait_Actuelle->sValeur);		
			Fait_Actuelle = Fait_Actuelle->Fait_Suivant;
		}

		if (Fic!=NULL)
		{
			fclose(Fic);
			Fic=NULL;
		}
	}
		
	return 0;
}


	Hypothese =  (*Tete_Regle)->Premiere_Hypothese;	//hypothese pointe au début vers la 1° hypothese
	Hypothese->Hypothese_Suivante = NULL;


int main (void)					
{
	int Test;
	Struct_Regle *Tete_Regle;

	Test=fCreerBaseRegle(&Tete_Regle);

	fCreerRegle(Tete_Regle);

	fAfficherBaseRegle(Tete_Regle);

	fModifierBaseRegle(&Tete_Regle);

	//fSupprimerBaseRegle(Tete_Regle);
	//printf("\n Base supprimée");
	//printf("\nteteRegle : %s",Tete_Regle->sConclusion);
	fAfficherBaseRegle(Tete_Regle);

	
	if(fAfficherBaseFait(Tete_Fait)==-1)printf("error d'affichage");
	if(fChargerBaseFait(Tete_Fait, PATH)==-1)printf("error de chargement");
	if(fAfficherBaseFait(Tete_Fait)==-1)printf("error d'affichage");
	fSupprimerBaseFait(Tete_Fait);
	
	
	return 0;
}
*/

/*******************************************************************/
/*******************************************************************/

/*******************************************************************/
/*******************************************************************/

