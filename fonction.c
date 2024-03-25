#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

// ****** traitement des images******/////
void initialiser_imageBACK(image *imge, int x, int y, int w, int h, char emplacement[])
{
    //  changement de l image
    imge->url = emplacement;
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("unable to load background image %s \n", SDL_GetError());
        return;
    }

    imge->pos_img_ecran.x = x;
    imge->pos_img_ecran.y = y;

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = h;
    imge->pos_img_affiche.w = w;
}

void initialiser_imageBOUTON(image *imge, int x, int y, int w, int h, char emplacement[])
{
    // chargement de l image
    imge->url = emplacement;
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("unable to load bouton image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x = x;
    imge->pos_img_ecran.y = y;

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = h;
    imge->pos_img_affiche.w = w;
}
void initialiser_imageBOUTON_OP(image *imge, int x, int y, int w, int h, char emplacement[])
{
    // chargement de l image
    imge->url = emplacement;
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("unable to load bouton image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x = x;
    imge->pos_img_ecran.y = y;

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = h;
    imge->pos_img_affiche.w = w;
}

void afficher_image(SDL_Surface *screen, image imge)
{
    // Coller et afficher l image de back dans screen
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void afficher_imageBTN(SDL_Surface *screen, image imge)
{
    // Coller et Afficher 1'image du btn play dans screen
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}
void afficher_imageBTN_OP(SDL_Surface *screen, image imge)
{
    // Coller et Afficher 1'image du btn play dans screen
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void liberer_image(image imge)
{
    SDL_FreeSurface(imge.img);
}
/********************************
****** *TRAITEMENT MUSIQUE* ******/

void initialiser_audio(Mix_Music *music, char emplacement[])
{
    // initialiser les fonction audio de SDL mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadMUS(emplacement); // chargement de la musique
    Mix_PlayMusic(music, -1);         // jouer la musique
    Mix_VolumeMusic(100);
}

void liberer_musique(Mix_Music *music)
{
    Mix_FreeMusic(music);
}

void jouer_audiobref(Mix_Chunk *music, char emplacement[])
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadWAV(emplacement);
    Mix_PlayChannel(-1, music, 0);
    if (music == NULL)
        printf("%s\n", SDL_GetError());
    // liberer_musiquebref(music);
}

void liberer_musiquebref(Mix_Chunk *music)
{
    Mix_FreeChunk(music);
}

int options(SDL_Surface *screen, int volume)
{
    image IMAGE_BTN_MOIN, IMAGE_BTN_PLUS, IMAGE_BTN_ZERO, IMAGE_BTN_25, IMAGE_BTN_50, IMAGE_BTN_75, IMAGE_BTN_100, IMAGE_BTN_FULL_SCREEN, IMAGE_BTN_FULL_SCREEN_OFF, IMAGE_BTN_WINDOWED_ON, IMAGE_BTN_WINDOWED_OFF, IMAGE_BTN1;
    image IMAGE;
       Mix_Chunk *mus;
    SDL_Event event;
    initialiser_imageBACK(&IMAGE, 0, 0, 1280, 720,               "images/option2.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_MOIN, 450, 250, 130, 130,  "images/moin1.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_PLUS, 700, 250, 130, 130,  "images/plus1.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_ZERO, 500, 140, 320, 130,  "images/zero.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_25, 500, 140, 320, 130, "images/vingtcinq.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_50, 500, 140, 320, 130, "images/cinquante.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_75, 500, 140, 320, 130, "images/soixanteQuinze.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_100, 500, 140, 320, 130, "images/cent.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_FULL_SCREEN, 665, 325, 320, 320, "images/fullscreen11.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_FULL_SCREEN_OFF, 665, 325, 320, 320, "images/fullscreen11.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_WINDOWED_ON, 360, 327, 320, 320, "images/windowed11.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN_WINDOWED_OFF, 360, 327, 320, 320, "images/windowed11.png");
    int boucle = 1;
    int detecte = 0;
    while (boucle)
    {
        afficher_image(screen, IMAGE);            // afficher un back d un option
        afficher_imageBTN_OP(screen, IMAGE_BTN_MOIN); // button -
        afficher_imageBTN_OP(screen, IMAGE_BTN_PLUS); // button +
        if (volume == 0)
            afficher_imageBTN_OP(screen, IMAGE_BTN_ZERO); // image de volume=0
        if (volume == 25)
            afficher_imageBTN_OP(screen, IMAGE_BTN_25); // image de volume=25
        if (volume == 50)
            afficher_imageBTN_OP(screen, IMAGE_BTN_50); // image de volume=50
        if (volume == 75)
            afficher_imageBTN_OP(screen, IMAGE_BTN_75); // image de volume=75
        if (volume == 100)
            afficher_imageBTN_OP(screen, IMAGE_BTN_100); // image de volume=100

        afficher_imageBTN_OP(screen, IMAGE_BTN_FULL_SCREEN_OFF); // full screen off
        if (detecte == 1)
            afficher_imageBTN_OP(screen, IMAGE_BTN_FULL_SCREEN); // full screen  on
        afficher_imageBTN_OP(screen, IMAGE_BTN_WINDOWED_OFF);     // windowed off
        if (detecte == 2)
            afficher_imageBTN_OP(screen, IMAGE_BTN_WINDOWED_ON); // windowed on

        Mix_VolumeMusic(volume);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                boucle = 0;
                break;
                //avec souris
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    int x = event.button.x;
                    int y = event.button.y;

                    if (x >= IMAGE_BTN_MOIN.pos_img_ecran.x && x <= IMAGE_BTN_MOIN.pos_img_ecran.x + IMAGE_BTN_MOIN.pos_img_affiche.w && y >= IMAGE_BTN_MOIN.pos_img_ecran.y && y <= IMAGE_BTN_MOIN.pos_img_ecran.y + IMAGE_BTN_MOIN.pos_img_affiche.h)
                    {

                        volume -= 25;//if je clique sur le bouton 7"-" le volume diminue
                        if (volume <= 0)
                            volume = 0;
                        Mix_VolumeMusic(volume);
                    }
                    if (x >= IMAGE_BTN_PLUS.pos_img_ecran.x && x <= IMAGE_BTN_PLUS.pos_img_ecran.x + IMAGE_BTN_PLUS.pos_img_affiche.w && y >= IMAGE_BTN_PLUS.pos_img_ecran.y && y <= IMAGE_BTN_PLUS.pos_img_ecran.y + IMAGE_BTN_PLUS.pos_img_affiche.h)
                    {

                        volume += 25;//if je clique sur le bouton 8 "+"le volume augmante
                        if (volume >= 100)
                            volume = 100;
                        Mix_VolumeMusic(volume);
                    }
                    if (x >= IMAGE_BTN_FULL_SCREEN_OFF.pos_img_ecran.x && x <= IMAGE_BTN_FULL_SCREEN_OFF.pos_img_ecran.x + IMAGE_BTN_FULL_SCREEN_OFF.pos_img_affiche.w && y >= IMAGE_BTN_FULL_SCREEN_OFF.pos_img_ecran.y && y <= IMAGE_BTN_FULL_SCREEN_OFF.pos_img_ecran.y + IMAGE_BTN_FULL_SCREEN_OFF.pos_img_affiche.h)
                    {
                        SDL_WM_ToggleFullScreen(screen);//if je clique button 15  full screen
                        jouer_audiobref(mus, "sons/ClicDeSouris.wav");
                        detecte = 1;
                    }
                    if (x >= IMAGE_BTN_WINDOWED_OFF.pos_img_ecran.x && x <= IMAGE_BTN_WINDOWED_OFF.pos_img_ecran.x + IMAGE_BTN_WINDOWED_OFF.pos_img_affiche.w && y >= IMAGE_BTN_WINDOWED_OFF.pos_img_ecran.y && y <= IMAGE_BTN_WINDOWED_OFF.pos_img_ecran.y + IMAGE_BTN_WINDOWED_OFF.pos_img_affiche.h)
                    {
                        screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);//if je clique  bouton 17 windowed 
                       jouer_audiobref(mus, "sons/ClicDeSouris.wav");
                        detecte = 2;
                    }
                }
                break;
                //avec souris
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_KP_PLUS:
                    volume += 25;
                    if (volume >= 100) // if depasse 100 arrete  100
                        volume = 100;
                    Mix_VolumeMusic(volume);
                    break;
                case SDLK_KP_MINUS:
                    volume -= 25;    // diminue le volume avec -
                    if (volume <= 0) // if depaase 0 arret 0
                        volume = 0;
                    Mix_VolumeMusic(volume);
                    break;
                case SDLK_ESCAPE:
                    boucle = 0;
                    break;
                case SDLK_f:
                    SDL_WM_ToggleFullScreen(screen);//f full screen
                    detecte = 1;
                    break;
                case SDLK_w:
                    screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);//w windowed
                    detecte = 2;
                    break;
                }
                break;
            }
        }
        SDL_Flip(screen);// reffraichir l ecran
    }
    liberer_image(IMAGE);
    liberer_image(IMAGE_BTN_MOIN);
    liberer_image(IMAGE_BTN_PLUS);
    liberer_image(IMAGE_BTN_ZERO);
    liberer_image(IMAGE_BTN_25);
    liberer_image(IMAGE_BTN_50);
    liberer_image(IMAGE_BTN_75);
    liberer_image(IMAGE_BTN_100);
    liberer_image(IMAGE_BTN_FULL_SCREEN);
    liberer_image(IMAGE_BTN_FULL_SCREEN_OFF);
    liberer_image(IMAGE_BTN_WINDOWED_ON);
    liberer_image(IMAGE_BTN_WINDOWED_OFF);
    return volume;
}


int play(SDL_Surface *screen, int volume)
{
    image IMAGE ;
    SDL_Event event;
 initialiser_imageBACK(&IMAGE, 0, 0, 1280, 720, "images/cheela.png");
int boucle =1; 
while (boucle)
{
   afficher_image(screen, IMAGE);
   SDL_Flip(screen);
   while (SDL_PollEvent(&event))
   {
    switch (event.type)
    {
    case  SDL_QUIT : 
    boucle = 0 ;
        break;
    
    default:
        break;
        //avec souris
    case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE :
                    boucle = 0 ; //espace retour au menu
                    break ; 
                }
    }
   }
   
}
liberer_image(IMAGE);
return volume ; 
}
void initText(Text *A)
{
A->position.x=1000;
A->position.y=680;

A->textColor.r=225;
A->textColor.g=225;
A->textColor.b=0;

A->font = TTF_OpenFont("fonts/NextBravo.ttf",30);
}
void freeText(Text A)
{
            SDL_FreeSurface(A.surfaceTexte);
}
void displayText(Text t, SDL_Surface *screen)
{
    t.surfaceTexte=TTF_RenderText_Solid(t.font," THE OBSERVERS",t.textColor);
    SDL_BlitSurface(t.surfaceTexte,NULL,screen,&t.position);
}
