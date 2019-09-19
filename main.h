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
