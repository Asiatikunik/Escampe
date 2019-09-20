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
	
	plateau[0][1].coulP=BLANC;
	plateau[0][2].coulP=BLANC;
	plateau[0][3].coulP=BLANC;
	plateau[1][1].coulP=BLANC;
	plateau[1][3].coulP=BLANC;
	plateau[1][4].coulP=BLANC;
	
	//NOIR
	plateau[4][0].typeP=PALADIN;
	plateau[4][1].typeP=LICORNE;
	plateau[4][2].typeP=PALADIN;
	plateau[4][5].typeP=PALADIN;
	plateau[5][2].typeP=PALADIN;
	plateau[5][4].typeP=PALADIN;
	
	plateau[4][0].coulP=PALADIN;
	plateau[4][1].coulP=LICORNE;
	plateau[4][2].coulP=PALADIN;
	plateau[4][5].coulP=PALADIN;
	plateau[5][2].coulP=PALADIN;
	plateau[5][4].coulP=PALADIN;
	
}

void init_piece2_debug(){
	//BLANC
	plateau[0][0].typeP=PALADIN;
	plateau[1][0].typeP=PALADIN;
	plateau[2][0].typeP=PALADIN;
	plateau[3][0].typeP=PALADIN;
	plateau[4][0].typeP=PALADIN;
	plateau[5][0].typeP=LICORNE;
	
	plateau[0][0].coulP=BLANC;
	plateau[1][0].coulP=BLANC;
	plateau[2][0].coulP=BLANC;
	plateau[3][0].coulP=BLANC;
	plateau[4][0].coulP=BLANC;
	plateau[5][0].coulP=BLANC;
	
	//NOIR
	plateau[0][5].typeP=PALADIN;
	plateau[1][5].typeP=PALADIN;
	plateau[2][5].typeP=LICORNE;
	plateau[3][5].typeP=PALADIN;
	plateau[4][5].typeP=PALADIN;
	plateau[5][5].typeP=PALADIN;
	
	plateau[0][5].coulP=NOIR;
	plateau[1][5].coulP=NOIR;
	plateau[2][5].coulP=NOIR;
	plateau[3][5].coulP=NOIR;
	plateau[4][5].coulP=NOIR;
	plateau[5][5].coulP=NOIR;
	
}


/** LA VUE **/

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
	
	p1.x=bg.x+25;
	p1.y=bg.y+25;
	p2.x=p1.x+25;
	p2.y=p1.y+60;
	p3.x=p1.x+50;
	p3.y=p1.y;
	if (coulP == BLANC)
	{
		draw_fill_triangle(p1,p2,p3,lavenderblush);
		
	}else{
		draw_fill_triangle(p1,p2,p3,noir);
	}
	
}

void affiche_paladin(POINT bg, COUL coulP){
	POINT p1,p2;
	p1.x=bg.x+30;
	p1.y=bg.y+30;
	p2.x=p1.x+40;
	p2.y=p1.y+40;
	
	if (coulP == BLANC)
	{
		draw_fill_rectangle(p1,p2,lavenderblush);
	}else{
		draw_fill_rectangle(p1,p2,noir);
	}
}

void affiche_plateau(int ig){
	int i,j;
	TYPE pion;
	NUMBOX numcase;
	POINT p;
	
	
	for(i=0;i<6;i++){
		for(j=0;j<6;j++)
		{
			numcase.l=i;
			numcase.c=j;
			p=numBox_to_pointBG_ig1(numcase);
		
			
			pion=plateau[i][j].typeP;
			switch (pion)
			{
				case VIDE:
				break;
				
				case PALADIN:
				affiche_paladin(p,plateau[i][j].coulP);
				break;
				
				case LICORNE:
				affiche_licorne(p,plateau[i][j].coulP);
				default:;
			}
		}
	}

	
	
	
}
void affiche_lisere(POINT bg, int nblisere){
	POINT p;
	p.x=bg.x+50;
	p.y=bg.y+50;
	switch (nblisere)
	{
		case 1:
		draw_fill_circle(p,48,lavenderblush);
		draw_fill_circle(p,46,dimgray);
		break;
		
		case 2:
		draw_fill_circle(p,48,lavenderblush);
		draw_fill_circle(p,46,dimgray);
		draw_fill_circle(p,44,lavenderblush);
		draw_fill_circle(p,42,dimgray);
		break;
		
		case 3:
		draw_fill_circle(p,48,lavenderblush);
		draw_fill_circle(p,46,dimgray);
		draw_fill_circle(p,44,lavenderblush);
		draw_fill_circle(p,42,dimgray);
		draw_fill_circle(p,40,lavenderblush);
		draw_fill_circle(p,38,dimgray);
		
		break;
		
		default:;
	}
	
	
}

void affiche_all_lisere(){
	int i,j;
	POINT p;
	p.x=100;
	p.y=100;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			
			affiche_lisere(p,plateau[i][j].lisere);
			p.x+=100;
		}
		p.x=100;
		p.y+=100;
	}
}

/** CONTROLEUR **/

POINT numBox_to_pointBG_ig1(NUMBOX numB){
	POINT pbg,debut;
	debut.x=100;
	debut.y=600;
	pbg.x = debut.x + numB.c*100;
	pbg.y = debut.y - numB.l*100;		
	return pbg;
}

POINT numBox_to_pointBG_ig2(NUMBOX numB){
	
	POINT pbg,debut;
	debut.x=100;
	debut.y=600;
	pbg.x = debut.x + numB.c*100;
	pbg.y = debut.y - numB.l*100;		
	return pbg;
}

NUMBOX point_ig1_to_numBox(POINT P){
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
	fill_screen(dimgray);
	afficher_quadrillage();
	affiche_all_lisere();
	affiche_all();
	
	/*for(i=0;i<15;i++)
	{
			p=wait_clic();
			case1=point_ig1_to_numBox(p);
			pbg=numBox_to_pointBG_ig1(case1);
			
			if(i%2 == 0)
			{
				affiche_licorne(pbg,joueur);
			}
			else{
			affiche_paladin(pbg,joueur);
			}
			
			affiche_all();
		
	}*/
	init_piece2_debug();
	affiche_plateau(1);
	wait_escape();    
	

	
	
	return 0;
}


