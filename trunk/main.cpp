#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "main.h"

int main(int argc, char* argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *image_test = NULL;
    SDL_Rect position;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    ecran = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("Test_Sdl",NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));//remplissage de la fenetre


    position.x = (640/2) - (220 / 2);
    position.y = (480 /2) - (180 / 2);

    image_test = IMG_Load("images.png");//chargement de l'image
    SDL_BlitSurface(image_test, NULL, ecran, &position);

    SDL_Flip(ecran);


    pause();

    SDL_FreeSurface(image_test);
    SDL_Quit();

    return EXIT_SUCCESS;
}
void pause()
{
    int continuer = 1;
    SDL_Event event;

    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
        }
    }
}

