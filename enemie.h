#ifndef enemie_H_INCLUDED
#define enemie_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include<time.h>

typedef struct 
	{ 
            SDL_Surface *ennemie;  
            SDL_Rect pos_ennemie,anim_ennemie[70];
            int frame_ennemie;
           int direction,col,type,maxi_up,maxi_down,show;
     }enemie;

typedef struct
{
SDL_Surface *perso; 
SDL_Rect perso_pos ;
}personnage ;
typedef struct {   
	  

	SDL_Surface *entity; 
	SDL_Rect pos_entity; 
	SDL_Rect anim_entity[70];  // l tab ali fih l les surfaces mta3 kol frame  o kol frame andha indice ( frame_entity )
	int frame_entity;
	int direction;
	int col ;
	int maxi_up,maxi_down;
	int show;

}entity ;






int detect_collision(personnage *p, entity* e);  
int gestion(entity* e);
void init_tab_anim_ennemie (SDL_Rect* clip,enemie *e); 
void initennemi(enemie *e)  ;
void afficherennemi(enemie e, SDL_Surface * screen) ;
void afficher_perso(SDL_Surface *screen,personnage p);

void animerennemi( enemie * e)  ; 
void deplacer(enemie * e);  
//int collision(SDL_Rect E, SDL_Rect p);//
void update_ennemie (enemie *e,personnage *p);

int collision(personnage *p, enemie *e);

int gerer(enemie *e) ; 
void deplacerIA(enemie *e, personnage *p);


void init_tab_anim_entity(SDL_Rect* clip,entity *en);   
void initentity (entity *en) ;
void afficherentity(entity en , SDL_Surface *screen);
void animerentity(entity *en);


#endif //  #include "fonction.h"

