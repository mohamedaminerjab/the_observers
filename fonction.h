#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1080
#define SCREEN_W 1920

typedef struct
{
    char *url;
    SDL_Rect pos_img_affiche; // partie de l'image qui doit etre affiché
    SDL_Rect pos_img_ecran;   // position de l image par rapport l ecran
    SDL_Surface *img;
} image;



// image
void initialiser_imageBACK(image *imge, int x, int y, int w, int h, char emplacement[]);
void initialiser_imageBOUTON(image *imge, int x, int y, int w, int h, char emplacement[]);
void initialiser_imageBOUTON_OP(image *imge, int x, int y, int w, int h, char emplacement[]);
// image
void afficher_image(SDL_Surface *screen, image imge);

void liberer_image(image imge);
// audio
void initialiser_audio(Mix_Music *music, char emplacement[]);
void liberer_musique(Mix_Music *music);

void jouer_audiobref(Mix_Chunk *music, char emplacement[]);
void liberer_musiquebref(Mix_Chunk *music);
int options(SDL_Surface *screen, int volume);
int play(SDL_Surface *screen, int volume);


typedef struct{
        SDL_Rect position;
        TTF_Font *font;
        SDL_Surface *surfaceTexte;
        SDL_Color textColor;
        char texte[50];
}Text;

void initText(Text *A);
void freeText(Text A);
void displayText(Text t,SDL_Surface *screen);
#endif
