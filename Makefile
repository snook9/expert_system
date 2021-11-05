#____________________CASSAING Jonathan______________________________

#____________________Makefile_______________________________________
#____________________v1.0 -> 11/02/2009_____________________________


Systeme_Expert : InitMoteur.o BaseFait.o BaseRegle.o ChainageAV.o ChainageAR.o Systeme_Expert.o
	gcc InitMoteur.o BaseFait.o BaseRegle.o ChainageAV.o ChainageAR.o Systeme_Expert.o -o Systeme_Expert -Wall -g

Systeme_Expert.o : Systeme_Expert.c
	gcc -c Systeme_Expert.c -Wall -g

InitMoteur.o : InitMoteur.h InitMoteur.c
	gcc -c InitMoteur.c -Wall -g

BaseFait.o : BaseFait.h BaseFait.c InitMoteur.h
	gcc -c BaseFait.c -Wall -g

BaseRegle.o : BaseRegle.h BaseRegle.c InitMoteur.h
	gcc -c BaseRegle.c -Wall -g

ChainageAV.o : ChainageAV.h ChainageAV.c InitMoteur.h BaseFait.h
	gcc -c ChainageAV.c -Wall -g

ChainageAR.o : ChainageAR.h ChainageAR.c InitMoteur.h
	gcc -c ChainageAR.c -Wall -g

#____________________________________________________________________
#____________________________________________________________________

#____________________________________________________________________
#____________________________________________________________________
