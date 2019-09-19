#include <stdio.h>
#include <stdlib.h>
#include "graphics.h" 
#include "main.h"

#define LARGEUR 700
#define HAUTEUR 700

int main(){
	printf("Salut\n");
	init_graphics(LARGEUR, HAUTEUR); /* (largeur, hauteur) */
	POINT p;
	p.x=250;
	p.y=250;
	draw_fill_circle(p, 100, aquamarine);
	wait_escape();    
	

	return 0;
}
