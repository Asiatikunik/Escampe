#include "graphics.h"

/** STRUCTURES **/
struct NUMBOX{
	int l; /* pour ligne */
	int c; /* pour colonne */
};
typedef struct NUMBOX NUMBOX;

enum TYPE{
	VIDE, LICORNE, PALADIN
};
typedef enum TYPE TYPE;

enum COUL{
	BLANC, NOIR
};
typedef enum COUL COUL;

struct BOX{
	int lisere; /* {1,2,3} */
	TYPE typeP; /* [VIDE,LICORNE,PALADIN} */
	COUL coulP; /*{BLANC,NOIR} */
};
typedef struct BOX BOX;



/** PROTOTYPES **/
void init_plateau();
void init_piece1_debug();
void init_piece2_debug();
void affiche_paladin(POINT bg, COUL coulP);
void affiche_licorne(POINT bg, COUL coulP);
void affiche_lisere(POINT bg, int nblisere);
void afficher_quadrillage();
POINT numBox_to_pointBG_ig1(NUMBOX numB);
POINT numBox_to_pointBG_ig2(NUMBOX numB);
NUMBOX point_ig1_to_numBox(POINT P);
NUMBOX point_ig2_to_numBox(POINT P);
