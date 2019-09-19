#include "graphics.h"

/** STRUCTURES **/
struct BOX{
	int lisere; /* {1,2,3} */
	TYPE typeP; /* [VIDE,LICORNE,PALADIN} */
	COUL coulP; /*{BLANC,NOIR} */
};
typedef struct BOX BOX;

enum COUL
{
	BLANC, NOIR
};
typedef enum COUL COUL;

enum TYPE
{
	VIDE, LICORNE, PALADIN
};
typedef enum TYPE TYPE;

struct NUMBOX{
	int l; /* pour ligne */
	int c; /* pour colonne */
};
typedef NUMBOX NUMBOX;


/** PROTOTYPES **/
