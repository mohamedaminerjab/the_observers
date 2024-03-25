#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

int main()
{
    // Declaration des variables
    SDL_Surface *screen;
    image IMAGE, IMAGE1, IMAGE2, IMAGE3, IMAGE4, IMAGE_PLAY_OFF, IMAGE_SETTING_OFF, IMAGE_QUIT_OFF, IMAGE_BTN7, IMAGE_BTN8, IMAGE_BTN9, IMAGE_PLAY_OFF0, IMAGE_PLAY_OFF1, IMAGE_PLAY_OFF2, IMAGE_PLAY_OFF3, IMAGE_PLAY_OFF4, IMAGE_PLAY_OFF5, IMAGE_PLAY_OFF6, IMAGE_PLAY_OFF7;
    image IMAGE_PLAY_ON, IMAGE_SETTING_ON, IMAGE_QUIT_ON;
    Mix_Music *music;
    Mix_Chunk *music_bref;
    Text txte;
    SDL_Event event;
    int boucle = 1, tt = 0, tt1 = 0, tt2 = 0;
    int detect = 0;
    int cpt = 0;

    // initialisation de la SDL
    TTF_Init();

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1)
    {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        return -1;
    }
    // reglage de la fenetre
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    // initialisation
    //(image *imge,int x,int y,int w,int h,char emplacement[]);
    IMAGE_PLAY_OFF, IMAGE_SETTING_OFF, IMAGE_QUIT_OFF, IMAGE_PLAY_ON, IMAGE_SETTING_ON, IMAGE_QUIT_ON;
    initialiser_imageBACK(&IMAGE, 0, 0, 1280, 720, "images/tafya11.png");//taswirat back 1
    initialiser_imageBACK(&IMAGE1, 0, 0, 1280, 720, "images/cheela11.png");//taswirat back 2
    initialiser_imageBACK(&IMAGE2, 0, 0, 1280, 720, "images/tafya11.png");//taswirat back 3
    initialiser_imageBACK(&IMAGE3, 0, 0, 1280, 720, "images/cheela11.png");//taswirat back 4    
    initialiser_imageBACK(&IMAGE4, 0, 0, 1280, 720, "images/tafya11.png");//taswirat back 5
    initialiser_imageBOUTON(&IMAGE_PLAY_OFF, 480, 186, 320, 130, "images/buttonplayoff.png");
    initialiser_imageBOUTON(&IMAGE_SETTING_OFF, 480, 320, 320, 130, "images/settingoff.png");
    initialiser_imageBOUTON(&IMAGE_QUIT_OFF, 480, 451, 320, 130, "images/quitoff.png");
    initialiser_imageBOUTON(&IMAGE_PLAY_ON, 480, 188, 320, 130, "images/buttonplayon.png");
    initialiser_imageBOUTON(&IMAGE_SETTING_ON, 480, 322, 320, 130, "images/settingon.png");
    initialiser_imageBOUTON(&IMAGE_QUIT_ON, 480, 453, 320, 130, "images/quiton.png");

    initialiser_audio(music, "sons/music.mp3");
    initText(&txte);
    /****************/
    // boucle de menu
    /***************/
    int volume = 100;

    while (boucle)
    {

        Mix_VolumeMusic(volume);
        afficher_image(screen, IMAGE);    // afficher l image de background
        displayText(txte,screen);
        if (cpt % 30 >= 0 && cpt % 30 < 10)//animation
            {
                afficher_image(screen, IMAGE1);//taswirat back 2 
                displayText(txte,screen);
            }
            else if (cpt % 30 >= 10 && cpt % 30 < 15)
            {
                afficher_image(screen, IMAGE2);//taswirat back 3
                displayText(txte,screen);
            }
            else if (cpt % 30 >= 15 && cpt % 30 < 20)
            {
                afficher_image(screen, IMAGE3);//taswirat back 4
                displayText(txte,screen);
            }
            else
            {
                afficher_image(screen, IMAGE4);//taswirat back 5
                displayText(txte,screen);
            }
            cpt++;  
        afficher_image(screen, IMAGE_PLAY_OFF); // afficher le bouton play
        afficher_image(screen, IMAGE_SETTING_OFF); // afficher le bouton setting
        afficher_image(screen, IMAGE_QUIT_OFF); // afficher le bouton  quit
        if (detect == 1)
            afficher_image(screen, IMAGE_PLAY_ON);// afficher le bouton play selectionee
        if (detect == 2)
            afficher_image(screen, IMAGE_SETTING_ON);// afficher le bouton setting selectionee
        if (detect == 3)
            afficher_image(screen, IMAGE_QUIT_ON);// afficher le bouton quit selectionee
        // afficher_texte(screen, txte);
        while (SDL_PollEvent(&event))
        {

            

            switch (event.type)
            {
            case SDL_QUIT:
                boucle = 0;
                break;
                //avec souris
            case SDL_MOUSEBUTTONDOWN: // quitter le menu
                if (detect == 1 || detect == 2)
                    jouer_audiobref(music_bref, "sons/ClicDeSouris.wav");
                    
                if (detect == 2)
                    volume = options(screen, volume);//nod5el lel option ki neclique ala setting b souris
                if (detect == 1)
                    volume = play(screen, volume);//nod5el lel option ki neclique ala play b souris
                if (detect == 3)
                    boucle = 0; //ki neclique 3ala quit no5rej ml jeu
                break;
                //avec clavier
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_RETURN) // entrer
                {
                    if (detect == 1 || detect == 2)
                        jouer_audiobref(music_bref, "sons/ClicDeSouris.wav");
                    Mix_PlayChannel(-1, music_bref, 0);
                    if (detect == 1)
                        volume = play(screen, volume); // ki necliquer entrer w ani play da5elner lel play

                    if (detect == 2)
                        volume = options(screen, volume); // ki necliquer entrer w ani option da5elner lel option
                    if (detect == 3)
                        boucle = 0; // ki necliquer entrer w ani quit no5rej ml jeu
                }
                if (event.key.keysym.sym == SDLK_p)// p t3 el clavier
                {
                    detect = 1;
                     jouer_audiobref(music_bref, "sons/ClicDeSouris.wav");
                    
                    volume = play(screen, volume);//ki necliquer 3ala p nod5el lel play
                }
                else if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    boucle = 0;//no5rej ml jeu
                }
                else if (event.key.keysym.sym == SDLK_s)//s t3 clavier
                {
                    detect = 2;
                    jouer_audiobref(music_bref, "sons/ClicDeSouris.wav");
                    
                    SDL_Event mouseEvent;
                    mouseEvent.type = SDL_MOUSEBUTTONDOWN;
                    mouseEvent.button.button = SDL_BUTTON_LEFT;
                    SDL_PushEvent(&mouseEvent);
                }//nod5el lel setting 

                else if (event.key.keysym.sym == SDLK_UP) // flech fou9eni
                {
                    if (detect == 0)
                    {
                        detect = 3; // button quit selectionee
                    }

                    else if (detect == 3)
                    {
                        detect = 2; // button setting selectionee
                    }
                    else if (detect == 2)
                    {
                        detect = 1; // button play selectionee
                    }
                    else
                        detect = 0;
                }

                else if (event.key.keysym.sym == SDLK_DOWN) // flech loutani
                {
                    if (detect == 0)
                    {
                        detect = 1; // button play selectionnee
                    }

                    else if (detect == 1)
                    {
                        detect = 2; // button setting selectionnee
                    }
                    else if (detect == 2)
                    {
                        detect = 3; // button quit selectionnee
                    }
                    else
                        detect = 0;
                }

                break;
                //avec souris
            case SDL_MOUSEMOTION:
                if ((event.motion.x > IMAGE_PLAY_OFF.pos_img_ecran.x) && (event.motion.x < IMAGE_PLAY_OFF.pos_img_ecran.x + 340) && (event.motion.y > IMAGE_PLAY_OFF.pos_img_ecran.y) && (event.motion.y < IMAGE_PLAY_OFF.pos_img_ecran.y + 130))
                {
                    detect = 1;//button play selecctionnee
                }

                else if ((event.motion.x > IMAGE_SETTING_OFF.pos_img_ecran.x) && (event.motion.x < IMAGE_SETTING_OFF.pos_img_ecran.x + 340) && (event.motion.y > IMAGE_SETTING_OFF.pos_img_ecran.y) && (event.motion.y < IMAGE_SETTING_OFF.pos_img_ecran.y + 130))
                {
                    detect = 2;//button setting selecctionnee
                }
                else if ((event.motion.x > IMAGE_QUIT_OFF.pos_img_ecran.x) && (event.motion.x < IMAGE_QUIT_OFF.pos_img_ecran.x + 340) && (event.motion.y > IMAGE_QUIT_OFF.pos_img_ecran.y) && (event.motion.y < IMAGE_QUIT_OFF.pos_img_ecran.y + 130))
                {
                    detect = 3;//button quit selecctionnee
                }
                else
                    detect = 0;
                break;
            }
        }
        SDL_Flip(screen); // reffraichir l ecran
        // SDL_Delay(5000);
        displayText(txte,screen);
    }
    // liberer les surfaces
    printf("debug1\n");liberer_image(IMAGE);
    printf("debug1\n");liberer_image(IMAGE1);
    printf("debug1\n");liberer_image(IMAGE2);
    printf("debug1\n");liberer_image(IMAGE3);
    printf("debug1\n");liberer_image(IMAGE4);
    printf("debug1\n");liberer_image(IMAGE_PLAY_OFF);
    printf("debug1\n");liberer_image(IMAGE_SETTING_OFF);
    printf("debug1\n");liberer_image(IMAGE_QUIT_OFF);
    printf("debug1\n");liberer_image(IMAGE_PLAY_ON);
    printf("debug1\n");liberer_image(IMAGE_SETTING_ON);
    printf("debug1\n");liberer_image(IMAGE_QUIT_ON);

    // liberer la musique
    // liberer_musique(music);
    
    // liberer texte
    // liberer_texte(txte);
    freeText(txte);
    
    TTF_CloseFont(txte.font);
    
    TTF_Quit();
    // quitter SDL
    SDL_Quit();
    return 0;
}
