#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "jeu.h"

extern char *Name;
extern unsigned tfinale;
extern FILE *fp;
extern FILE *saveFile;
extern int savedG;
 int grid[7][7];
int sol[6][6];
extern int concord[6][6];
extern int concordComp[6][6];
int screen;

int main(int argc, char **argv)
{

    int width = 800;
    int height = 600;
    int i,j;
    int x, y;


    // génèrer la matrice de nombres et la solution de la partie


    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("modele de droite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 96,115,130,255);

    // Initialize support for loading PNG and JPEG images
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

     // Initialize support for loading TTF
    TTF_Init();

    //affichage du menu

        for(i=0; i<6; i++){
        for(j=0; j<6; j++){
        concord[i][j]= 0;
        concordComp[i][j]= 0;
    }
}
returnMenu:
       menu(renderer);
       screen = 0;

    bool running = true;
    SDL_Event event;

while (running) {

   while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT)
            {
                running = false;
            }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if((event.button.x >350 && event.button.x < 350+100)&&(event.button.y >189 && event.button.y <189+70))
                {
                    gamemode:
                    gameMode(renderer);
                    screen =1;
                while(screen == 1 && running == true)
                    {
                    while(SDL_PollEvent(&event))
                        {
                            if(event.type == SDL_QUIT)
                                {
                                    running = false;
                                }
                            else if(event.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >189 && event.button.y <189+70))
                                        {
                                            SDL_RenderClear(renderer);
                                            saveOrCont(renderer);

                                            screen = 2;
                                            while(screen == 2 && running == true)
                                                {
                                                    while(SDL_PollEvent(&event))
                                                        {
                                                            if(event.type == SDL_QUIT)
                                                                {
                                                                    running = false;
                                                                    screen = 0;
                                                                }
                                                            else if(event.type == SDL_MOUSEBUTTONDOWN)
                                                                {
                                                                    if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >189 && event.button.y <189+70))
                                                                        {
                                                                            grillEtSoluce(sol, grid);
                                                                            jeu(renderer,window,grid,sol, 0);
                                                                            if(jeuFin(sol)==0)
                                                                                {
                                                                                    SDL_Delay(500);
                                                                                    youWin(renderer, tfinale);
                                                                                    SDL_RenderPresent(renderer);
                                                                                    scoreBoard(renderer, Name, tfinale);
                                                                                    scoreboardDisplay(renderer, fp);
                                                                                    SDL_Delay(4000);

                                                                                    screen = 0;
                                                                                    goto returnMenu;
                                                                                }
                                                                        }
                                                                    else if((event.button.x >300 && event.button.x < 350+100)&&(event.button.y >450 && event.button.y <500))
                                                                        {
                                                                            if(loadGame(saveFile, 1)==1)
                                                                                {
                                                                                    grillEtSoluce(sol, grid);
                                                                                    jeu(renderer,window,grid,sol, 1);
                                                                                    if(jeuFin(sol)==0)
                                                                                {
                                                                                    SDL_Delay(500);
                                                                                    youWin(renderer, tfinale);
                                                                                    SDL_RenderPresent(renderer);
                                                                                    scoreBoard(renderer, Name, tfinale);
                                                                                    scoreboardDisplay(renderer, fp);
                                                                                    SDL_Delay(4000);

                                                                                    screen = 0;
                                                                                    goto returnMenu;
                                                                                }
                                                                                }
                                                                            else
                                                                                {
                                                                                    errorSave(renderer);
                                                                                    SDL_Delay(4000);
                                                                                    screen = 0;
                                                                                    goto returnMenu;
                                                                                }
                                                                        }
                                                                        else if((event.button.x >5 && event.button.x < 65)&&(event.button.y >5 && event.button.y <60))
                                                                            {
                                                                                screen = 1;
                                                                                goto gamemode;
                                                                            }
                                                                }
                                                        }
                                                }
                                        }
                                    else if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >320 && event.button.y <370))
                                        {
                                            SDL_RenderClear(renderer);
                                            saveOrCont(renderer);
                                            screen = 3;
                                                while(screen == 3 && running == true)
                                                {
                                                    while(SDL_PollEvent(&event))
                                                        {
                                                            if(event.type == SDL_QUIT)
                                                                {
                                                                    running = false;
                                                                }
                                                            else if(event.type == SDL_MOUSEBUTTONDOWN)
                                                                {
                                                                    if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >189 && event.button.y <189+70))
                                                                        {
                                                                            grillEtSoluce(sol, grid);
                                                                            jeuOrdi(renderer,window,grid,sol, 0);
                                                                            if(jeuFinOrdi(sol)==0)
                                                                                {

                                                                                    screen = 0;

                                                                                    goto returnMenu;
                                                                                }
                                                                        }
                                                                    else if((event.button.x >300 && event.button.x < 350+100)&&(event.button.y >450 && event.button.y <500))
                                                                        {
                                                                            if(loadGame(saveFile, 2)==1)
                                                                                {
                                                                                    grillEtSoluce(sol, grid);
                                                                                    jeuOrdi(renderer,window,grid,sol, 1);
                                                                                }
                                                                            else
                                                                                {
                                                                                    errorSave(renderer);
                                                                                    SDL_Delay(4000);
                                                                                    screen = 0;

                                                                                    goto returnMenu;
                                                                                }

                                                                        }
                                                                    else if((event.button.x >5 && event.button.x < 65)&&(event.button.y >5 && event.button.y <60))
                                                                            {
                                                                                screen = 1;
                                                                                goto gamemode;
                                                                            }
                                                                }
                                                        }
                                                }



                                        }
                                    else if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >450 && event.button.y <500))
                                        {
                                           SDL_RenderClear(renderer);
                                           saveOrCont(renderer);
                                           screen = 4;
                                             while(screen == 4 && running == true)
                                                {
                                                    while(SDL_PollEvent(&event))
                                                        {
                                                            if(event.type == SDL_QUIT)
                                                                {
                                                                    running = false;
                                                                }
                                                            else if(event.type == SDL_MOUSEBUTTONDOWN)
                                                                {
                                                                    if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >189 && event.button.y <189+70))
                                                                        {
                                                                            grillEtSoluce(sol, grid);
                                                                            compvsplayer(renderer,window,grid,sol, 0);


                                                                                    screen = 0;
                                                                                    goto returnMenu;



                                                                        }
                                                                    else if((event.button.x >300 && event.button.x < 350+100)&&(event.button.y >450 && event.button.y <500))
                                                                        {
                                                                            if(loadGame(saveFile, 3)==1)
                                                                                {
                                                                                    grillEtSoluce(sol, grid);
                                                                                    compvsplayer(renderer,window,grid,sol, 1);



                                                                                    screen = 0;
                                                                                    goto returnMenu;

                                                                                }
                                                                            else
                                                                                {
                                                                                    errorSave(renderer);
                                                                                    SDL_Delay(4000);
                                                                                    screen = 0;
                                                                                    goto returnMenu;
                                                                                }
                                                                        }
                                                                    else if((event.button.x >5 && event.button.x < 65)&&(event.button.y >5 && event.button.y <60))
                                                                            {
                                                                                screen = 1;
                                                                                goto gamemode;
                                                                            }
                                                                }
                                                        }
                                                }
                                        }
                                        else if((event.button.x >5 && event.button.x < 65)&&(event.button.y >5 && event.button.y <60))
                                                                            {
                                                                                screen = 0;
                                                                                goto returnMenu;
                                                                            }

                                }
                        }
                    }
                }
                else if((event.button.x >300 && event.button.x < 350+100)&&(event.button.y >320 && event.button.y <370))
                {
                    scoreboardDisplay(renderer, fp);
                    SDL_Delay(4000);
                    screen = 0;
                    goto returnMenu;
                }
                else if((event.button.x >300 && event.button.x < 350+100)&&(event.button.y >450 && event.button.y <500))
                {
                    running = false;
                }
            }
}
}





    // Release resources

    IMG_Quit();
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);


    SDL_Quit();

    return 0;
}













