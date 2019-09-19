#include <stdio.h>
#include <stdlib.h> 
#include "main.h"

#define LARGEUR 700
#define HAUTEUR 700

BOX plateau[6][6];

void init_plateau(){
	
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			plateau[i][j].typeP=VIDE;
		}
	}
	
	/* LISERE 1 */
	plateau[0][0].lisere=1;
	plateau[0][4].lisere=1;
	plateau[1][1].lisere=1;plateau[1][3].lisere=1;
	plateau[2][2].lisere=1;plateau[2][4].lisere=1;
	plateau[3][1].lisere=1;plateau[3][5].lisere=1;
	plateau[4][0].lisere=1;plateau[4][2].lisere=1;plateau[4][4].lisere=1;
	plateau[5][3].lisere=1;
	
	/* LISERE 2 */
	plateau[0][1].lisere=2;plateau[0][2].lisere=2;plateau[0][5].lisere=2;
	plateau[1][5].lisere=2;
	plateau[2][0].lisere=2;plateau[2][3].lisere=2;
	plateau[3][0].lisere=2;plateau[3][3].lisere=2;
	plateau[4][5].lisere=2;
	plateau[5][1].lisere=2;plateau[5][2].lisere=2;plateau[5][5].lisere=2;
	
	/* LISERE 3 */
	plateau[0][3].lisere=3;
	plateau[1][0].lisere=3;plateau[1][2].lisere=3;plateau[1][4].lisere=3;
	plateau[2][1].lisere=3;plateau[2][5].lisere=3;
	plateau[3][2].lisere=3;plateau[3][4].lisere=3;
	plateau[4][1].lisere=3;plateau[4][3].lisere=3;
	plateau[5][0].lisere=3;plateau[5][4].lisere=3;
		
	
}	
int main(){
	
	init_plateau(plateau);
	
	/*init_graphics(LARGEUR, HAUTEUR);
	POINT p;
	p.x=250;
	p.y=250;
	draw_fill_circle(p, 100, aquamarine);
	wait_escape();    
	
*/
	
	
	return 0;
}


/** 	AFFCIHAGE 
for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			printf("%d ",plateau[i][j].lisere);
		}
		printf("\n");
	}
	* */
