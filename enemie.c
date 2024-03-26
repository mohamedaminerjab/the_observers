#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"enemie.h"
int 
nb_frame1=12 ,
enemie_h=100,
enemie_w=100,
enemie_y=100,
enemie_x=100;


void init_tab_anim_ennemie(SDL_Rect *clip,enemie *e)
{	


for (int j=0;j<nb_frame1; j++)
	{
	clip[j].h=enemie_h;
	clip[j].w=enemie_w;
	clip[j].x = j*enemie_w;
	clip[j].y = 0;
        }


}

void initennemi(enemie *e)
{

    e->ennemie = IMG_Load("images/ENNEMIE.png");

    e->pos_ennemie.x = 900;
    e->pos_ennemie.y = 400;
    init_tab_anim_ennemie(e->anim_ennemie,e);
    e->frame_ennemie=0;
    e->direction=0;  
    e->col=0;
    e->show=1;
    
    
}
void afficherennemi(enemie e, SDL_Surface *screen)
{
   
   SDL_BlitSurface(e.ennemie,&e.anim_ennemie[e.frame_ennemie], screen, &e.pos_ennemie);
  
  

}
void afficher_perso(SDL_Surface *screen,personnage p)
{	
	SDL_BlitSurface(p.perso,NULL,screen,&p.perso_pos);
}
void animerEnnemi(enemie *e)
{   if (e->frame_ennemie >=0 && e->frame_ennemie <(nb_frame1-1)) 
 e->frame_ennemie++;
    if ( e->frame_ennemie ==(nb_frame1-1)) 
       e->frame_ennemie=0;
}
void deplacer(enemie * e)
{
srand (time(0));
	
	int maxi_down=300+rand()%300;
	int maxi_up=150+rand()%300;
      
  	printf("maxup : %d\t maxdown : %d\n",maxi_up,maxi_down );


if(e->pos_ennemie.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_ennemie.y<=maxi_up)
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_ennemie.y-=7;

}
if(e->direction==0)
{
	e->pos_ennemie.y+=7;
}

  




}
void update_ennemie(enemie *e,personnage *p)
{ 	deplacerIA(e,p);
	animerEnnemi(e);
	

}

int collision(personnage *p, enemie *e)
{
	

if ((p->perso_pos.x + p->perso_pos.w < e->pos_ennemie.x) || (p->perso_pos.x> e->pos_ennemie.x + e->pos_ennemie.w) ||
(p->perso_pos.y + p->perso_pos.h< e->pos_ennemie.y) || (p->perso_pos.y> e->pos_ennemie.y + e->pos_ennemie.h ))
return 0;
else 
return 1;
 
}

int gerer(enemie *e) {
	
	e->show=0;
	
	return 0; 
}
 

void deplacerIA(enemie *e,personnage *p)
{	srand (time(0));
	int diff;
	int maxi_down=300+rand()%300;
	int maxi_up=150+rand()%300;
      
  	//printf("maxup : %d\t maxdown : %d\n",maxi_up,maxi_down );


if(e->pos_ennemie.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_ennemie.y<=maxi_up)
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_ennemie.y-=7;

}
if(e->direction==0)
{
	e->pos_ennemie.y+=7;
}

  diff=e->pos_ennemie.x-p->perso_pos.x;
  
  if (diff<350 && diff>50 ){

e->pos_ennemie.x-=3;
  }

if (diff >-350 && diff < 0){
  
  e->pos_ennemie.x+=3;
  }


}







int 
nb_frame=12 ,
entity_h=100,
entity_w=100,
entity_y=100,
entity_x=100;

								 

void init_tab_anim_entity(SDL_Rect *clip,entity *en)
{		
	for (int j=0;j<nb_frame; j++)
	{
	clip[j].h=entity_h;
	clip[j].w=entity_w;
	clip[j].x = j*entity_x;
	clip[j].y = 0;
        }  
}


/**
* @brief To initialize the entity e  .
* @param e the entity
* @return Nothing
*/

void initentity(entity *en)
{


    en->entity = IMG_Load("images/es.png"); 

    en->pos_entity.x = 400;
    en->pos_entity.y = 100;
    init_tab_anim_entity(en->anim_entity,en); 
    en->frame_entity=0;//indice mta3 l taswera 
    en->direction=0;  
    en->col=0;
    en->show=1; 
      
}
/**
* @brief To show the entity e .
* @param screen the screen
* @param e the entity
* @return Nothing
*/


void afficherentity(entity en , SDL_Surface *screen)
{
   
   SDL_BlitSurface(en.entity,&en.anim_entity[en.frame_entity], screen, &en.pos_entity);

}
/**
* @brief for the random movement of the secondary entity .
* @param e the entity
* @param p the personnage  
* @return Nothing
*/


/**
* @brief for the animation the secondary entity .
* @param e the entity 
* @return Nothing
*/

void animerentity(entity *en)
{   
	if (en->frame_entity >=0 && en->frame_entity <(nb_frame-1)) 
	en->frame_entity++;
	
	if ( en->frame_entity ==(nb_frame-1)) 
	en->frame_entity=0;
}

/** @brief to change the maxi down and the maxi up randomly .
* @param e the entity 
* @return Nothing
*/


/*void rand_min_max(entity *e){
	srand (time(0));
  	e->maxi_up=50+rand()%100;
 	e->maxi_down=350+rand()%100;

  	printf("maxup : %d\tmaxdown : %d\n",e->maxi_up,e->maxi_down );

}*/


/**
* @brief for the detection of a collision bounding box  .
* @param e the entity 
* @param p the personnage 
* @return collision  
*/

int detect_collision(personnage *p, entity* en)
{
	
if ((p->perso_pos.x + p->perso_pos. w< en->pos_entity. x) || (p->perso_pos.x> en->pos_entity. x + en->pos_entity. w) ||
(p->perso_pos.y + p->perso_pos.h< en->pos_entity. y) || (p->perso_pos.y> en->pos_entity. y + en->pos_entity. h ))
return 0;
else 
return 1;
 
}
/**
* @brief if the type of the entity is good so it will disappear in case of collision   .
* @param e the entity  
* @return 0
*/
int gestion(entity* en)
{
en->show=0; 
return 0;

}

