#include <stdio.h>
#include <stdlib.h> 
#include "main.h"

#define LARGEUR 800
#define HAUTEUR 800

BOX plateau[6][6];

/** MODELE **/
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


void init_piece1_debug(){
	//BLANC
	plateau[0][1].typeP=PALADIN;
	plateau[0][2].typeP=PALADIN;
	plateau[0][3].typeP=LICORNE;
	plateau[1][1].typeP=PALADIN;
	plateau[1][3].typeP=PALADIN;
	plateau[1][4].typeP=PALADIN;
	
	//NOIR
	plateau[4][0].typeP=PALADIN;
	plateau[4][1].typeP=LICORNE;
	plateau[4][2].typeP=PALADIN;
	plateau[4][5].typeP=PALADIN;
	plateau[5][2].typeP=PALADIN;
	plateau[5][4].typeP=PALADIN;
	
}

void init_piece2_debug(){
	//BLANC
	plateau[0][0].typeP=PALADIN;
	plateau[1][0].typeP=PALADIN;
	plateau[2][0].typeP=PALADIN;
	plateau[3][0].typeP=PALADIN;
	plateau[4][0].typeP=PALADIN;
	plateau[5][0].typeP=LICORNE;
	
	//NOIR
	plateau[5][0].typeP=PALADIN;
	plateau[5][1].typeP=PALADIN;
	plateau[5][2].typeP=LICORNE;
	plateau[5][3].typeP=PALADIN;
	plateau[5][4].typeP=PALADIN;
	plateau[5][5].typeP=PALADIN;
	
}
/** LA VUE **/
void afficher_fond()
{
	POINT p1,p2;
	p1.x=0;
	p1.y=0;
	p2.x=800;
	p2.y=800;
	draw_fill_rectangle(p1,p2,dimgray);
}
void afficher_quadrillage(){
	POINT a, b;
	int n;
	a.x=100; a.y=100;
	b.x=700; b.y=100;

	for(n=0; n<7; n++){
		draw_line(a, b, aquamarine);
		a.y+=100;
		b.y+=100; 
	}
	a.x=100; a.y=100;
	b.x=100; b.y=700;
	for(n=0; n<7; n++){
		draw_line(a, b, aquamarine);
		a.x+=100;
		b.x+=100; 
	}
}

void affiche_licorne(POINT bg, COUL coulP){
	POINT p1,p2,p3;
	printf("test");
	p1.x=bg.x+5;
	p1.y=bg.y+5;
	p2.x=p1.x+45;
	p2.y=p1.y+90;
	p3.x=p1.x+90;
	p3.y=p1.y;
	if (coulP == BLANC)
	{
		printf("test");
		draw_fill_triangle(p1,p2,p3,lavenderblush);
		
	}else{
		draw_fill_triangle(p1,p2,p3,rouge);
	}
	
}

void affiche_paladin(POINT bg, COUL coulP){
	POINT p1,p2;
	p1.x=bg.x+20;
	p1.y=bg.y+20;
	p2.x=p1.x+60;
	p2.y=p1.y+60;
	
	if (coulP == BLANC)
	{
		draw_fill_rectangle(p1,p2,lavenderblush);
	}else{
		draw_fill_rectangle(p1,p2,rouge);
	}
}

/** 	AFFCIHAGE 
for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			printf("%d ",plateau[i][j].lisere);
		}
		printf("\n");
	}
	* */




/** CONTROLEUR **/

POINT numBox_to_pointBG_ig1(NUMBOX numB){
	POINT pbg;
	pbg.x = numB.l*100;
	pbg.y = numB.c*100;		
	return pbg;
}

POINT numBox_to_pointBG_ig2(NUMBOX numB){
	
	POINT pbg;
	pbg.x = numB.l*100;
	pbg.y = numB.c*100;		
	return pbg;
}

NUMBOX Point_ig1_to_numBox(POINT P){
	NUMBOX num_case;
		num_case.l = P.x/100;
		num_case.c = P.y/100;
		return num_case;
}


int main(){
	COUL joueur;
	joueur=BLANC;
	init_plateau(plateau);
	init_graphics(LARGEUR, HAUTEUR);
	affiche_auto_off();
	
	POINT p,pbg;
	NUMBOX case1;
	int i;
	afficher_fond();
	afficher_quadrillage();
	affiche_all();
	for(i=0;i<15;i++)
	{
		p=wait_clic();
		case1=Point_ig1_to_numBox(p);
		pbg=numBox_to_pointBG_ig1(case1);
		if(i%2 == 0)
		{
			affiche_licorne(pbg,joueur);
		}
		else{
		affiche_paladin(pbg,joueur);
		}
		affiche_all();
	}
	wait_escape();    
	

	
	
	return 0;
}


