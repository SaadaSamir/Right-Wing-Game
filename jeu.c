#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



int i, j,k;
struct scores
{
	char s[30];
	int y, m, d;
	int sec;
	int msec;
}scr[1000];

unsigned tfinale, loadTime;
int concord[6][6];
int concordComp[6][6];
char Name[30]= "";
int m=0;
int s=0;
int ms=0;
int ss=0;
int mss=0;
extern int grid[7][7];
extern int sol[6][6];
FILE * fp;
FILE * saveFile;

// fonction qui verifie si le schéma de diagonales correspond a la solution
int jeuFin(int soluce[6][6]){
bool fin = true;;
    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            if (soluce[i][j] != concord[i][j]){
                fin = false;
                break;
            }
        }
    }

    if(fin==false){
        return 1;
    }else {

        return 0;
    }
}
int jeuFinOrdi(int soluce[6][6]){
bool fin = true;;
    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            if (soluce[i][j] != concordComp[i][j]){
                fin = false;
                break;
            }
        }
    }

    if(fin==false){
        return 1;
    }else {

        return 0;
    }
}

//procedure qui genere un schema de diagonales et la matrice de chiffres correspondante
void grillEtSoluce(int soluce[6][6], int grille[7][7])
{


     srand ((unsigned) time (NULL));

     for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            soluce[i][j] = rand() % 2 + 1;
        }
     }
for(i=0; i<7; i++){
    for(j=0; j<7; j++){
        if(i==0 && j==0){
            if(soluce[0][0]==1){
                grille[0][0]= 1;
            }else {
                grille[0][0] = 0;
            }
        }
        else if(i==0 && (j!=0 && j!=6)){
           if(soluce[0][j-1]== 1 && soluce[0][j]== 2){
            grille[i][j] = 0;
           }else if(soluce[0][j-1]== 1 && soluce[0][j]== 1){
               grille[i][j] = 1;
           }else if(soluce[0][j-1]== 2 && soluce[0][j]== 1){
               grille[i][j] = 2;
           }else if(soluce[0][j-1]== 2 && soluce[0][j]== 2){
               grille[i][j] = 1;
           }
           }
        else if((i==0 && j==6)){
            if(soluce[0][j-1]== 1){
                grille[0][j] = 0;
            } else {
                grille[0][j] = 1;
            }
        }
        else if(i==6 && j==0){
            if(soluce[5][0]== 1){
                grille[6][0] = 0;
            } else {
                grille[6][0] = 1;
            }
        }
        else if(i==6 && j==6){
            if(soluce[5][5]== 1){
                grille[6][6] = 1;
            } else {
                grille[6][6] = 0;
            }
        }
        else if((i!=0 && i!=6)&&(j==0)){
            if(soluce[i-1][j]== 1 && soluce[i][j]== 2){
            grille[i][j] = 0;
           }else if(soluce[i-1][j]== 1 && soluce[i][j]== 1){
               grille[i][j] = 1;
           }else if(soluce[i-1][j]== 2 && soluce[i][j]== 1){
               grille[i][j] = 2;
           }else if(soluce[i-1][j]== 2 && soluce[i][j]== 2){
               grille[i][j] = 1;
           }
        }
        else if((i!=0 && i!=6)&&(j==6)){
            if(soluce[i-1][5]== 1 && soluce[i][5]== 2){
            grille[i][j] = 2;
           }else if(soluce[i-1][5]== 1 && soluce[i][5]== 1){
               grille[i][j] = 1;
           }else if(soluce[i-1][5]== 2 && soluce[i][5]== 1){
               grille[i][j] = 0;
           }else if(soluce[i-1][5]== 2 && soluce[i][5]== 2){
               grille[i][j] = 1;
           }
        }

        else if((i!=0 && i!=6)&&(j!=0 && j!=6)){
            if(soluce[i-1][j-1]==1  && soluce[i-1][j]==1 && soluce[i][j-1]==1  && soluce[i][j]==1){
                grille[i][j] = 2 ;
            }
            else if(soluce[i-1][j-1]==2  && soluce[i-1][j]==2 && soluce[i][j-1]==2  && soluce[i][j]==2){
                grille[i][j] = 2 ;
            }
            else if(soluce[i-1][j-1]==1  && soluce[i-1][j]==2 && soluce[i][j-1]==1  && soluce[i][j]==2){
                grille[i][j] = 2;
            }
            else if(soluce[i-1][j-1]==2  && soluce[i-1][j]==1 && soluce[i][j-1]==2  && soluce[i][j]==1){
                grille[i][j] = 2 ;
            }
            else if(soluce[i-1][j-1]==1  && soluce[i-1][j]==2 && soluce[i][j-1]==2  && soluce[i][j]==1){
                grille[i][j] = 4 ;
            }
            else if(soluce[i-1][j-1]==2  && soluce[i-1][j]==1 && soluce[i][j-1]==1  && soluce[i][j]==2){
                grille[i][j] = 0;
            }
            else if(soluce[i-1][j-1]==1  && soluce[i-1][j]==1 && soluce[i][j-1]==2  && soluce[i][j]==2){
                grille[i][j] = 2;
            }
            else if(soluce[i-1][j-1]==2  && soluce[i-1][j]==2 && soluce[i][j-1]==1  && soluce[i][j]==1){
                grille[i][j] = 2;
            }
             else if(soluce[i-1][j-1]==2  && soluce[i-1][j]==2 && soluce[i][j-1]==1  && soluce[i][j]==2){
                grille[i][j] = 1;
            }
             else if(soluce[i-1][j-1]==1  && soluce[i-1][j]==2 && soluce[i][j-1]==2  && soluce[i][j]==2){
                grille[i][j] = 3;
            }
             else if(soluce[i-1][j-1]==2  && soluce[i-1][j]==1 && soluce[i][j-1]==2  && soluce[i][j]==2){
                grille[i][j] = 1;
            }
             else if(soluce[i-1][j-1]==2  && soluce[i-1][j]==2 && soluce[i][j-1]==2  && soluce[i][j]==1){
                grille[i][j] = 3;
            }
            else if(soluce[i-1][j-1]==1  && soluce[i-1][j]==1 && soluce[i][j-1]==2  && soluce[i][j]==1){
                grille[i][j] = 3;
            }
             else if(soluce[i-1][j-1]==2  && soluce[i-1][j]==1 && soluce[i][j-1]==1  && soluce[i][j]==1){
                grille[i][j] = 1;
            }
             else if(soluce[i-1][j-1]==1  && soluce[i-1][j]==2 && soluce[i][j-1]==1  && soluce[i][j]==1){
                grille[i][j] = 3;
            }
             else if(soluce[i-1][j-1]==1  && soluce[i-1][j]==1 && soluce[i][j-1]==1  && soluce[i][j]==2){
                grille[i][j] = 1;
            }
        }
        else if(i==6 && (j!=0 && j!=6)){
            if(soluce[5][j-1]==1 && soluce[5][j]==2){
                grille[i][j]= 2;
            }
            else if(soluce[5][j-1]==1 && soluce[5][j]==1){
                grille[i][j]= 1;
            }
            else if(soluce[5][j-1]==2 && soluce[5][j]==1){
                grille[i][j]= 0;
            }
             else if(soluce[5][j-1]==2 && soluce[5][j]==2){
                grille[i][j]= 1;
            }
        }

    }
}

}
// une fonction pour creer pour telecharger les images

SDL_Texture *initialize_texture_from_file(const char* file_name, SDL_Renderer *renderer)
{
    SDL_Surface *image = IMG_Load(file_name);
    SDL_Texture * image_texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    return image_texture;
}

// une fonction pour creer un text

SDL_Texture *initialize_texture_from_TTF(const char* name, SDL_Renderer *renderer)
{
    TTF_Font * font = TTF_OpenFont("arial.ttf",22);
    SDL_Color color = { 255,255,255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,name, color);
    SDL_Texture * text = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return text;
}

// une procedure pour copier les modification sur le renderer

 void Blit(SDL_Renderer *renderer, SDL_Texture *texture,SDL_Rect dest)
 {
      SDL_RenderCopy(renderer, texture, NULL, &dest);
 }

 // une procedure pour dessiner le plateau du jeu

 void Draw_Game(SDL_Renderer *renderer,SDL_Rect points[49],SDL_Rect cells[36])
 {


    SDL_Texture * image_texture = initialize_texture_from_file("fulltitlebar.png", renderer);

    SDL_Texture * image_texture1 = initialize_texture_from_file("timer.png", renderer);
    SDL_Texture * image_texture2 = initialize_texture_from_file("yourscoreback.png", renderer);
    SDL_Texture * image_texture3 = initialize_texture_from_file("patterncell.png", renderer);
    SDL_Texture * image_texture4 = initialize_texture_from_file("cellpoints1.png", renderer);

    SDL_Texture * image_texture0 = initialize_texture_from_file("background.png", renderer);




    // Define where on the "screen" we want to draw the texture

    SDL_Rect texture_destination,texture_destination1,texture_destination2, texture_destination0;

    texture_destination0.x = 0;
  texture_destination0.y = 0;
  texture_destination0.w = 800;
  texture_destination0.h = 600;

    texture_destination.x = 370;
    texture_destination.y = 0;
    texture_destination.w = 40;
    texture_destination.h = 40;

    texture_destination1.x = 0;
    texture_destination1.y = 0;
    texture_destination1.w = 800;
    texture_destination1.h = 67;

    texture_destination2.x = 0;
    texture_destination2.y = 0;
    texture_destination2.w = 810;
    texture_destination2.h = 650;


    // initialisation des rectangles pour contenir les cellules des cases
    cells[0].x = 172;
    cells[0].y = 116;


    int i,x=cells[0].x ;

    // une boucle pour attribuer les positions a chaque cellule
    for(i=1;i<36;i++)
        {
            cells[i].x=x+75;
            cells[i].y=cells[i-1].y;
            x=x+75;
            if(i%6==0){
                x=172;
                cells[i].y=cells[i-1].y+75;
                cells[i].x=x;
            }
        }

      // initialisation des points


    x=points[0].x = 137;
    points[0].y = 82;

      // une boucle pour attribuer les positions a chaque point
    for(i=1;i<49;i++)
        {
               points[i].x=x+75;
               points[i].y=points[i-1].y;
               x=x+75;
            if(i%7==0){
                x=137;
                points[i].y=points[i-1].y+75;
                points[i].x=x;
            }
        }
     // deux boucles pour attribuer les dimensions a chaque point et cellule
            for(i=0;i<36;i++)
               {
                  cells[i].w =75;
                  cells[i].h =75;
               }
            for(i=0;i<49;i++)
               {
                   points[i].w=70;
                   points[i].h=70;
               }
         // Draw
        Blit(renderer, image_texture0,texture_destination0);
        Blit(renderer, image_texture2,texture_destination2); //presentation du fond d'ecran
        Blit(renderer, image_texture,texture_destination1); // the watch drawing
        Blit(renderer, image_texture1,texture_destination); // les bordures

        // presentation des cellules

        for(i=0;i<36;i++)
        Blit(renderer, image_texture3,cells[i]);

        // presentation des points

        for(i=0;i<49;i++)
        Blit(renderer, image_texture4,points[i]);

    SDL_DestroyTexture(image_texture0);
    SDL_DestroyTexture(image_texture);
    SDL_DestroyTexture(image_texture1);
    SDL_DestroyTexture(image_texture2);
    SDL_DestroyTexture(image_texture3);
    SDL_DestroyTexture(image_texture4);


 }

/* Cette structure permet de représenter un carré par sa couleur et un SDL_Rect. */
struct carre {
   SDL_Rect rect;
   Uint32 couleur;
};

// une procedure pour creer icone
 int Icon(SDL_Window *window)
{
    SDL_Surface *surface;
    size_t i;
    surface = SDL_CreateRGBSurface(0, 32, 32, 32, 0, 0, 0, 0);

    /* On crée quatre carré pour notre icône. */
    struct carre carre[4] = {
        { {  4,  4, 10, 10 }, SDL_MapRGB(surface->format, 0, 0, 0) }, /* Noir */
        { {  4, 18, 10, 10 }, SDL_MapRGB(surface->format, 255, 140, 0) }, /* Orange */
        { { 18,  4, 10, 10 }, SDL_MapRGB(surface->format, 255, 140, 0) }, /* Orange */
        { { 18, 18, 10, 10 }, SDL_MapRGB(surface->format, 0, 0, 0) } /* Noir*/
    };

    /* On remplit notre surface grâce à nos carrés. */
    for(i = 0; i < 4; i++)
        SDL_FillRect(surface, &carre[i].rect, carre[i].couleur);

    SDL_SetWindowIcon(window, surface);
    SDL_FreeSurface(surface);
  return 0;
}
// affichage du timer

void Draw_Timer(SDL_Renderer *renderer, int tiempo)
{


      SDL_Rect timerpos;
        ms = tiempo % 1000;//miliseconde
        s = tiempo / 1000 ;  // seconde



      timerpos.x=360;
      timerpos.y=45;
      timerpos.w=68;
      timerpos.h=19;
      char temps[20];
      SDL_Texture *timer;
      sprintf(temps,"%d:%d", s, ms); // on sauvgarde les secondes dans le tompant temps
      timer=initialize_texture_from_TTF(temps,renderer);
      Blit(renderer,timer,timerpos);

      SDL_DestroyTexture(timer);

}

// affichage du parametre
int Draw_Settings(SDL_Renderer * renderer)
{

    SDL_Texture *textureset=initialize_texture_from_file("settingssbutton.jpg",renderer);
    SDL_Rect setpos;
    setpos.x=717;
    setpos.y=1;
    setpos.w=60;
    setpos.h=55;
    Blit(renderer,textureset,setpos);

    SDL_DestroyTexture(textureset);
    return 0;
}

void drawReturn(SDL_Renderer * renderer)
{
  SDL_Texture *textureset1=initialize_texture_from_file("return button.png",renderer);
    SDL_Rect setpos1;
    setpos1.x=5;
    setpos1.y=5;
    setpos1.w=60;
    setpos1.h=55;
    Blit(renderer,textureset1,setpos1);

    SDL_DestroyTexture(textureset1);
}

 void draw_Model(SDL_Rect points[49],SDL_Renderer * renderer, int grid[7][7])
 {
    SDL_Texture *texp0=initialize_texture_from_file("cellpoints0.png",renderer);
    SDL_Texture *texp1=initialize_texture_from_file("cellpoints1.png",renderer);
    SDL_Texture *texp2=initialize_texture_from_file("cellpoints2.png",renderer);
    SDL_Texture *texp3=initialize_texture_from_file("cellpoints3.png",renderer);
    SDL_Texture *texp4=initialize_texture_from_file("cellpoints4.png",renderer);
    SDL_Texture *texpgrid[7][7];

    for(i=0; i<7; i++){
    for(j=0; j<7; j++){

            if(grid[i][j]== 0){
                texpgrid[i][j] = texp0;
            }
            else if(grid[i][j]== 1){
                texpgrid[i][j] = texp1;

            }
            else if(grid[i][j]== 2){
                texpgrid[i][j] = texp2;
            }
            else if(grid[i][j]== 3){
                texpgrid[i][j] = texp3;
            }
            else if(grid[i][j]== 4){
                texpgrid[i][j] = texp4;
            }

    }
    }


    Blit(renderer,texpgrid[0][0],points[0]);
    Blit(renderer,texpgrid[0][1],points[1]);
    Blit(renderer,texpgrid[0][2],points[2]);
    Blit(renderer,texpgrid[0][3],points[3]);
    Blit(renderer,texpgrid[0][4],points[4]);
    Blit(renderer,texpgrid[0][5],points[5]);
    Blit(renderer,texpgrid[0][6],points[6]);
    Blit(renderer,texpgrid[1][0],points[7]);
    Blit(renderer,texpgrid[1][1],points[8]);
    Blit(renderer,texpgrid[1][2],points[9]);
    Blit(renderer,texpgrid[1][3],points[10]);
    Blit(renderer,texpgrid[1][4],points[11]);
    Blit(renderer,texpgrid[1][5],points[12]);
    Blit(renderer,texpgrid[1][6],points[13]);
    Blit(renderer,texpgrid[2][0],points[14]);
    Blit(renderer,texpgrid[2][1],points[15]);
    Blit(renderer,texpgrid[2][2],points[16]);
    Blit(renderer,texpgrid[2][3],points[17]);
    Blit(renderer,texpgrid[2][4],points[18]);
    Blit(renderer,texpgrid[2][5],points[19]);
    Blit(renderer,texpgrid[2][6],points[20]);
    Blit(renderer,texpgrid[3][0],points[21]);
    Blit(renderer,texpgrid[3][1],points[22]);
    Blit(renderer,texpgrid[3][2],points[23]);
    Blit(renderer,texpgrid[3][3],points[24]);
    Blit(renderer,texpgrid[3][4],points[25]);
    Blit(renderer,texpgrid[3][5],points[26]);
    Blit(renderer,texpgrid[3][6],points[27]);
    Blit(renderer,texpgrid[4][0],points[28]);
    Blit(renderer,texpgrid[4][1],points[29]);
    Blit(renderer,texpgrid[4][2],points[30]);
    Blit(renderer,texpgrid[4][3],points[31]);
    Blit(renderer,texpgrid[4][4],points[32]);
    Blit(renderer,texpgrid[4][5],points[33]);
    Blit(renderer,texpgrid[4][6],points[34]);
    Blit(renderer,texpgrid[5][0],points[35]);
    Blit(renderer,texpgrid[5][1],points[36]);
    Blit(renderer,texpgrid[5][2],points[37]);
    Blit(renderer,texpgrid[5][3],points[38]);
    Blit(renderer,texpgrid[5][4],points[39]);
    Blit(renderer,texpgrid[5][5],points[40]);
    Blit(renderer,texpgrid[5][6],points[41]);
    Blit(renderer,texpgrid[6][0],points[42]);
    Blit(renderer,texpgrid[6][1],points[43]);
    Blit(renderer,texpgrid[6][2],points[44]);
    Blit(renderer,texpgrid[6][3],points[45]);
    Blit(renderer,texpgrid[6][4],points[46]);
    Blit(renderer,texpgrid[6][5],points[47]);
    Blit(renderer,texpgrid[6][6],points[48]);

    SDL_DestroyTexture(texp0);
    SDL_DestroyTexture(texp1);
    SDL_DestroyTexture(texp2);
    SDL_DestroyTexture(texp3);
    SDL_DestroyTexture(texp4);
 }

void scoreBoard(SDL_Renderer*renderer, char *n, unsigned tf){

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
    int sf = tf/1000;
    int mf = tf%1000;
struct scores temp;




    fp  = fopen("scoreboard.csv", "a");




  fprintf(fp, "%s %d, %02d, %02d, %d, %d\n",Name, tm.tm_year +1900, tm.tm_mon + 1, tm.tm_mday, sf, mf);


    fclose(fp);

    fp = fopen("scoreboard.csv", "r");
    i=0;

     while(fscanf(fp, "%s %d, %02d, %02d, %d, %d", scr[i].s, &scr[i].y, &scr[i].m, &scr[i].d, &scr[i].sec, &scr[i].msec)==6)
   {
       i++;
   }
  int size = i;

  printf("%d", size);

   for(i=1; i<size; i++)
    {
        for(j=0; j<size -i; j++)
            {
               if(scr[j+1].sec == scr[j].sec)
                {
                    if(scr[j+1].msec < scr[j].msec)
                        {
                            temp = scr[j];
                            scr[j] = scr[j+1];
                            scr[j+1] = temp;
                        }

                }
                else if(scr[j+1].sec < scr[j].sec)
                    {
                        temp = scr[j];
                        scr[j] = scr[j+1];
                        scr[j+1] = temp;
                    }
            }
    }
    fclose(fp);


    fp= fopen("scoreboardSorted.csv", "w");

    for(i=0; i<size; i++)
        {
            fprintf(fp, "%s %d, %d, %d, %d, %d\n", scr[i].s, scr[i].y, scr[i].m, scr[i].d, scr[i].sec, scr[i].msec);
        }

    fclose(fp);
}


void compFin(SDL_Renderer*renderer, unsigned time)
{
    int s, ms;

    s = time/1000;
    ms = time%1000;
    char temps[20];

    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    TTF_Font * fontTitle = TTF_OpenFont("SF Atarian System.ttf", 40);
    SDL_Color color = { 255, 255, 255 };
    SDL_Color colorTitle = { 240, 120, 28 };

    SDL_Surface * surfacew1 = TTF_RenderText_Solid(fontTitle,
    "The computer finished " , colorTitle);

    SDL_Surface * surfacew2 = TTF_RenderText_Solid(font,
    "Time is:", color);

    sprintf(temps,"%d:%d", s, ms);

    SDL_Surface * surfacew3 = TTF_RenderText_Solid(font,
    temps, color);


    SDL_Texture * texturew1 = SDL_CreateTextureFromSurface(renderer, surfacew1);

    SDL_Texture * texturew2 = SDL_CreateTextureFromSurface(renderer, surfacew2);
    SDL_Texture * texturew3 = SDL_CreateTextureFromSurface(renderer, surfacew3);





    SDL_Rect dstrectw1 = { 150, 50, 500, 100 };


    SDL_Rect dstrectw2 = { 100, 200+50, 400, 90 };
    SDL_Rect dstrectw3 = { 500, 200+50, 100, 90 };



        SDL_RenderCopy(renderer, texturew1, NULL,  &dstrectw1);

        SDL_RenderCopy(renderer, texturew2, NULL,  &dstrectw2);
        SDL_RenderCopy(renderer, texturew3, NULL,  &dstrectw3);


        SDL_RenderPresent(renderer);





 SDL_DestroyTexture(texturew1);
    SDL_FreeSurface(surfacew1);

    SDL_DestroyTexture(texturew2);
    SDL_FreeSurface(surfacew2);

     SDL_DestroyTexture(texturew3);
    SDL_FreeSurface(surfacew3);



    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);

}

void errorSave(SDL_Renderer*renderer)
{


    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    TTF_Font * fontTitle = TTF_OpenFont("SF Atarian System.ttf", 40);

    SDL_Color colorTitle = { 240, 120, 28 };

    SDL_Surface * surfacew1 = TTF_RenderText_Solid(fontTitle,
    "Error, no game saved" , colorTitle);





    SDL_Texture * texturew1 = SDL_CreateTextureFromSurface(renderer, surfacew1);





    SDL_Rect dstrectw1 = { 150, 50, 500, 100 };



        SDL_RenderCopy(renderer, texturew1, NULL,  &dstrectw1);



        SDL_RenderPresent(renderer);




SDL_RenderClear(renderer);
 SDL_DestroyTexture(texturew1);
    SDL_FreeSurface(surfacew1);




    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);

}
 void youWin(SDL_Renderer*renderer, unsigned time){




    bool run = true;


    SDL_Texture *NamePlace;

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    TTF_Font * fontTitle = TTF_OpenFont("SF Atarian System.ttf", 40);
    SDL_Color color = { 255, 255, 255 };
    SDL_Color colorTitle = { 240, 120, 28 };

    SDL_Surface * surfacew1 = TTF_RenderText_Solid(fontTitle,
    "You've finished the puzzle: " , colorTitle);

    SDL_Surface * surfacew2 = TTF_RenderText_Solid(font,
    "Enter your name", color);






    SDL_Texture * texturew1 = SDL_CreateTextureFromSurface(renderer, surfacew1);

    SDL_Texture * texturew2 = SDL_CreateTextureFromSurface(renderer, surfacew2);





    SDL_Rect dstrectw1 = { 150, 50, 500, 100 };


    SDL_Rect dstrectw2 = { 150, 200+50, 500, 90 };









    SDL_StartTextInput();


while(run){
        SDL_Event e;
        SDL_RenderCopy(renderer, texturew1, NULL,  &dstrectw1);

        SDL_RenderCopy(renderer, texturew2, NULL,  &dstrectw2);
        SDL_Rect dstrectw3 =  { 365- (10*(strlen(Name)+1)), 450, 30*(strlen(Name)+1) ,  30 };
        NamePlace=initialize_texture_from_TTF(Name,renderer);
        Blit(renderer,NamePlace,dstrectw3);

        SDL_RenderPresent(renderer);


        while(SDL_PollEvent(&e)){

            if(e.type == SDL_QUIT){
                run =false;
                printf("%s", Name);
                exit(0);
            }
            else if(e.type == SDL_KEYDOWN){
                    if(e.key.keysym.sym == SDLK_BACKSPACE && strlen(Name)>0){
                Name[strlen(Name)-1] = '\0';
               }

            }



            else if(e.type == SDL_TEXTINPUT && e.key.keysym.sym != SDL_SCANCODE_SPACE){

                      strcat(Name, e.text.text);
             }

            else if(e.type == SDL_MOUSEBUTTONDOWN){

                run = false;
            }



    }

SDL_RenderClear(renderer);
}

    SDL_StopTextInput();

    SDL_DestroyTexture(texturew1);
    SDL_FreeSurface(surfacew1);

    SDL_DestroyTexture(texturew2);
    SDL_FreeSurface(surfacew2);
    SDL_DestroyTexture(NamePlace);


    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);




 }
 // creation du menu

void Displayer(SDL_Renderer*renderer, char * str){


    SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 25);

    SDL_Color color = { 255, 255, 255 };

    SDL_Surface * surfacescore = TTF_RenderText_Solid(font,
    str, color);
    SDL_Texture * texturescore = SDL_CreateTextureFromSurface(renderer, surfacescore);
    SDL_Rect dstrectscore = { 20, 80 + (50*i), 730, 30 };
    SDL_RenderCopy(renderer, texturescore, NULL,  &dstrectscore);

    SDL_DestroyTexture(texturescore);
    SDL_FreeSurface(surfacescore);
    TTF_CloseFont(font);


}

void scoreboardDisplay(SDL_Renderer*renderer, FILE * f){

    char nom[100], data[1000];

    int aa, mm,dd,ss,mss;
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 96,115,130,255);

    TTF_Font * fontTitle = TTF_OpenFont("tahoma.ttf", 40);
    SDL_Color color = { 255, 255, 255 };

    SDL_Surface * surfacescore = TTF_RenderText_Solid(fontTitle,
    "NAME:...........DATE:..................FINISH TIME:", color);
    SDL_Texture * texturescore = SDL_CreateTextureFromSurface(renderer, surfacescore);
    SDL_Rect dstrectscore = { 20, 20, 730, 50 };
    SDL_RenderCopy(renderer, texturescore, NULL,  &dstrectscore);
    SDL_RenderPresent(renderer);

    i=0;
    fp  = fopen("scoreboardSorted.csv", "r");


    rewind(fp);
    while((fscanf(fp, "%s %d, %d, %d, %d, %d,\n", nom, &dd, &mm, &aa, &ss, &mss) == 6) && (i< 10)){

    if (i==0)
        {
            sprintf(data,"%d- %s...........%d-%d-%d...(BEST TIME)...%d:%d",i+1, nom, dd, mm, aa, ss, mss);
        }else
        {

    sprintf(data,"%d- %s...........%d-%d-%d..................%d:%d",i+1, nom, dd, mm, aa, ss, mss);
        }


    Displayer(renderer, data);
    SDL_RenderPresent(renderer);
    i++;
    memset(data, 0,strlen(data));
    }
    SDL_RenderClear(renderer);
    SDL_Delay(3000);

    fclose(fp);


    SDL_DestroyTexture(texturescore);
    SDL_FreeSurface(surfacescore);

    TTF_CloseFont(fontTitle);
}

 void menu(SDL_Renderer*renderer)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    TTF_Font * fontTitle = TTF_OpenFont("SF Atarian System.ttf", 40);
    SDL_Color color = { 255, 255, 255 };
    SDL_Color colorTitle = { 240, 120, 28 };

    SDL_Surface * surface = TTF_RenderText_Solid(fontTitle,
    "Welcome to Menu", colorTitle);
    SDL_Surface * surface1 = TTF_RenderText_Solid(font,
    "Start", color);
    SDL_Surface * surface2 = TTF_RenderText_Solid(font,
    "Score", color);
    SDL_Surface * surface3 = TTF_RenderText_Solid(font,
    "Quit", color);

    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Texture * texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Texture * texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_Texture * texture3 = SDL_CreateTextureFromSurface(renderer, surface3);


    SDL_Rect dstrect = { 219, 50, 400, 100 };

    SDL_Rect dstrect1 = { 350, 189, 100, 70 };

    SDL_Rect dstrect2 = { 350, 250+50, 100, 70 };

    SDL_Rect dstrect3 = { 350, 350+80, 100, 70 };


        SDL_RenderCopy(renderer, texture, NULL,  &dstrect);
        SDL_RenderCopy(renderer, texture1, NULL,  &dstrect1);
        SDL_RenderCopy(renderer, texture2, NULL,  &dstrect2);
        SDL_RenderCopy(renderer, texture3, NULL,  &dstrect3);

        SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture1);
    SDL_FreeSurface(surface1);
    SDL_DestroyTexture(texture2);
    SDL_FreeSurface(surface2);
    SDL_DestroyTexture(texture3);
    SDL_FreeSurface(surface3);
    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);




}

 void gameMode(SDL_Renderer*renderer)
{

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    TTF_Font * fontTitle = TTF_OpenFont("SF Atarian System.ttf", 40);
    SDL_Color color = { 255, 255, 255 };
    SDL_Color colorTitle = { 240, 120, 28 };

    SDL_Surface * surfaceA = TTF_RenderText_Solid(fontTitle,
    "Choose a game mode", colorTitle);
    SDL_Surface * surfaceB = TTF_RenderText_Solid(font,
    "One player", color);
    SDL_Surface * surfaceC = TTF_RenderText_Solid(font,
    "Computer", color);
    SDL_Surface * surfaceD = TTF_RenderText_Solid(font,
    "Player vs Computer", color);

    SDL_Texture * textureA = SDL_CreateTextureFromSurface(renderer, surfaceA);
    SDL_Texture * textureB = SDL_CreateTextureFromSurface(renderer, surfaceB);
    SDL_Texture * textureC = SDL_CreateTextureFromSurface(renderer, surfaceC);
    SDL_Texture * textureD = SDL_CreateTextureFromSurface(renderer, surfaceD);
     drawReturn(renderer);

    SDL_Rect dstrectA = { 219, 50, 400, 100 };

    SDL_Rect dstrectB = { 310, 189, 200, 70 };

    SDL_Rect dstrectC = { 310, 250+50, 200, 70 };

    SDL_Rect dstrectD = { 310, 350+80, 220, 70 };


        SDL_RenderCopy(renderer, textureA, NULL,  &dstrectA);
        SDL_RenderCopy(renderer, textureB, NULL,  &dstrectB);
        SDL_RenderCopy(renderer, textureC, NULL,  &dstrectC);
        SDL_RenderCopy(renderer, textureD, NULL,  &dstrectD);

        SDL_RenderPresent(renderer);

    SDL_DestroyTexture(textureA);
    SDL_FreeSurface(surfaceA);
    SDL_DestroyTexture(textureB);
    SDL_FreeSurface(surfaceB);
    SDL_DestroyTexture(textureC);
    SDL_FreeSurface(surfaceC);
    SDL_DestroyTexture(textureD);
    SDL_FreeSurface(surfaceD);
    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);




}
 void pauseMode(SDL_Renderer*renderer)
{

    SDL_RenderClear(renderer);
     SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    TTF_Font * fontTitle = TTF_OpenFont("SF Atarian System.ttf", 40);
    SDL_Color color = { 255, 255, 255 };
    SDL_Color colorTitle = { 240, 120, 28 };

    SDL_Surface * surface00 = TTF_RenderText_Solid(fontTitle,
    "The game is paused", colorTitle);
    SDL_Surface * surface01 = TTF_RenderText_Solid(font,
    "Resume game", color);
    SDL_Surface * surface02 = TTF_RenderText_Solid(font,
    "Save game", color);
    SDL_Surface * surface03 = TTF_RenderText_Solid(font,
    "Quit game", color);

    SDL_Texture * texture00 = SDL_CreateTextureFromSurface(renderer, surface00);
    SDL_Texture * texture01 = SDL_CreateTextureFromSurface(renderer, surface01);
    SDL_Texture * texture02 = SDL_CreateTextureFromSurface(renderer, surface02);
    SDL_Texture * texture03 = SDL_CreateTextureFromSurface(renderer, surface03);


    SDL_Rect dstrect00 = { 219, 50, 400, 100 };

    SDL_Rect dstrect01 = { 350, 189, 150, 70 };

    SDL_Rect dstrect02 = { 350, 250+50, 150, 70 };

    SDL_Rect dstrect03 = { 350, 350+80, 150, 70 };


        SDL_RenderCopy(renderer, texture00, NULL,  &dstrect00);
        SDL_RenderCopy(renderer, texture01, NULL,  &dstrect01);
        SDL_RenderCopy(renderer, texture02, NULL,  &dstrect02);
        SDL_RenderCopy(renderer, texture03, NULL,  &dstrect03);

        SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture00);
    SDL_FreeSurface(surface00);
    SDL_DestroyTexture(texture01);
    SDL_FreeSurface(surface01);
    SDL_DestroyTexture(texture02);
    SDL_FreeSurface(surface02);
    SDL_DestroyTexture(texture03);
    SDL_FreeSurface(surface03);
    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);



}
int loadGame(FILE *f, int Gmode){
    int a;


 if( Gmode == 1)
    {
        f = fopen("savedFile.txt", "r");
    }
    else if(Gmode == 2)
    {
        f = fopen("savedFileComp.txt", "r");
    }
    else if(Gmode == 3)
    {
        f = fopen("savedFileCompvsplayer.txt", "r");
    }




   fscanf(f,"%d", &a);

   for(i=0;i<7;i++){
        for(j=0;j<7;j++){

    if(!(fscanf(f,"%d", &grid[i][j]))){
     break;
    }
        }
   }

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){

    if(!(fscanf(f,"%d", &sol[i][j]))){
     break;
    }
        }
   }

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){

    if(!(fscanf(f,"%d", &concordComp[i][j]))){
     break;
    }
        }
   }
     for(i=0;i<6;i++){
        for(j=0;j<6;j++){

    if(!(fscanf(f,"%d", &concord[i][j]))){
     break;
    }
        }
   }
   fscanf(f,"%d", &loadTime);


    fclose(f);
   if(a==1)
    {
        return 1;
   }
   else if(a==2)
   {
       return 2;
   }
   else if(a==3)
    {
        return 3;
   }
return 0;
}
void saveOrCont(SDL_Renderer*renderer){
SDL_RenderClear(renderer);
     SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);

    SDL_Color color = { 255, 255, 255 };



    SDL_Surface * surface01 = TTF_RenderText_Solid(font,
    "New Game", color);

    SDL_Surface * surface03 = TTF_RenderText_Solid(font,
    "Load Game", color);


    SDL_Texture * texture01 = SDL_CreateTextureFromSurface(renderer, surface01);

    SDL_Texture * texture03 = SDL_CreateTextureFromSurface(renderer, surface03);




    SDL_Rect dstrect01 = { 350, 189, 150, 70 };



    SDL_Rect dstrect03 = { 350, 350+80, 150, 70 };



        SDL_RenderCopy(renderer, texture01, NULL,  &dstrect01);

        SDL_RenderCopy(renderer, texture03, NULL,  &dstrect03);

        drawReturn(renderer);

        SDL_RenderPresent(renderer);


    SDL_DestroyTexture(texture01);
    SDL_FreeSurface(surface01);

    SDL_DestroyTexture(texture03);
    SDL_FreeSurface(surface03);
    TTF_CloseFont(font);




}
void saveGame(int savet, int conc[6][6], int concCo[6][6], int s[6][6], int g[7][7], FILE *f, int a, int Gmode){
    if( Gmode == 1)
    {
        f = fopen("savedFile.txt", "w");
    }
    else if(Gmode == 2)
    {
        f = fopen("savedFileComp.txt", "w");
    }
    else if(Gmode == 3)
    {
        f = fopen("savedFileCompvsplayer.txt", "w");
    }

    fprintf(f, "%d\n", a);

      for(i=0;i<7;i++){
        for(j=0;j<7;j++){
           fprintf(f, "%d\n", g[i][j]);
        }
    }

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
           fprintf(f, "%d\n", s[i][j]);
        }
    }

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
           fprintf(f, "%d\n", concCo[i][j]);
        }
    }
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
           fprintf(f, "%d\n", conc[i][j]);
        }
    }
     fprintf(f, "%d\n", savet);
    fclose(f);
}
void jeu(SDL_Renderer *renderer,SDL_Window * window, int grid[7][7], int sol[6][6], int mod)
 {
    SDL_Rect points[49],cells[36];
    bool running=true;
    int I,J,x,y,e, lock;
    int tquit=1;
    bool pause = true;




    //int now =100, before=95,delta=50;
    unsigned now, start, ptime, savedtime;
    //delta = 0;
    SDL_Texture * t2 = initialize_texture_from_file("patterncellrl.png", renderer);
    SDL_Texture * t1 = initialize_texture_from_file("patterncelllr.png", renderer);
    SDL_Texture * t0 = initialize_texture_from_file("patterncell.png", renderer);
    SDL_Texture * t=t0;
    // drawing the game
    Icon(window);
      // draw timer
SDL_Texture *table[6][6];
     // draw icone



    if(mod==1){

      for (i=0; i<6; i++)
        {
           for(j=0; j<6; j++){
            if (concord[i][j] == 0){
                table[i][j] = t0;
            }
            else if(concord[i][j] == 1){
               table[i][j] = t1;

           } else if(concord[i][j] == 2){
               table[i][j] = t2;
        }
        }
        }
    }
    else{

      for (i=0; i<6; i++)
        {
           for(j=0; j<6; j++)
            {
             table[i][j] = t0;
            }
       }
    }



SDL_Event event;


start = SDL_GetTicks();



    while(running)
    {
    pause = true;
    lock = 0;
        SDL_PumpEvents();  // make sure we have the latest mouse state.

     SDL_GetMouseState(&x, &y);

    //SDL_Log("Mouse cursor is at %d, %d", x, y);

    if(x>cells[0].x && x<cells[0].x + cells[0].w){J = 0;}
    else if(x>cells[1].x && x<cells[1].x + cells[1].w){J = 1;}
    else if(x>cells[2].x && x<cells[2].x + cells[2].w){J = 2;}
    else if(x>cells[3].x && x<cells[3].x + cells[3].w){J = 3;}
    else if(x>cells[4].x && x<cells[4].x + cells[4].w){J = 4;}
    else if(x>cells[5].x && x<cells[5].x + cells[5].w){J = 5;}


    if(y>cells[0].y && y < cells[0].y + cells[0].h){I = 0;}
    else if(y>cells[6].y && y< cells[6].y + cells[6].h){I = 1;}
    else if(y>cells[12].y && y< cells[12].y + cells[12].h){I = 2;}
    else if(y>cells[18].y && y< cells[18].y + cells[18].h){I = 3;}
    else if(y>cells[24].y && y< cells[24].y + cells[24].h){I = 4;}
    else if(y>cells[30].y && y< cells[30].y + cells[30].h){I = 5;}


if(mod == 1){
    now = SDL_GetTicks() - start + loadTime;
}else{
     now = SDL_GetTicks()- start;
}

    Draw_Game(renderer,points,cells);
    Draw_Timer(renderer, now);




   while(SDL_PollEvent(&event) && jeuFin(sol)!=0)
        {


            if(event.type == SDL_QUIT)
            {
                running = false;
                tquit = 0;
            }


            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if((event.button.x >715 && event.button.x < 775)&&(event.button.y >0 && event.button.y <55)){
                    ptime = now;
                    if(lock != 1){
                        savedtime = now;
                        lock = 1;
                    }
                    pauseMode(renderer);

                    while(pause == true){

                    ptime = SDL_GetTicks() - now;
                    while(SDL_PollEvent(&event)){


                         if(event.type == SDL_QUIT)
                       {
                            pause = false;
                            running = false;
                            tquit = 0;
                       }
                       else if(event.type ==  SDL_MOUSEBUTTONDOWN){
                        if((event.button.x >350 && event.button.x < 350+150)&&(event.button.y >189 && event.button.y <189+70)){
                        if(mod ==1){
                            ptime += loadTime;
                            start = ptime;
                        }else{
                            start = ptime;
                        }

                        pause = false;
                        }
                        else if((event.button.x >350 && event.button.x < 350+150)&&(event.button.y >320 && event.button.y <370)){

                            saveGame(savedtime, concord, concordComp, sol, grid, saveFile, 1, 1);

                            pause = false;
                            running = false;
                            tquit = 0;

                        }
                        else if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >450 && event.button.y <500)){
                            exit(0);
                        }
                       }
                    }

                    }
                }

                else if(event.button.button == SDL_BUTTON_LEFT && table[I][J] == t0)
                {
                    if((event.button.x >cells[0].x && event.button.x < cells[0].x+cells[0].w)&&(event.button.y > cells[0].y && event.button.y <cells[0].y+cells[0].h))
                    {
                         table[I][J]=t1;
                         concord[I][J]=1;
                    }
                    else if((event.button.x >cells[1].x && event.button.x < cells[1].x+cells[1].w)&&(event.button.y > cells[1].y && event.button.y <cells[1].y+cells[1].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[2].x && event.button.x < cells[2].x+cells[2].w)&&(event.button.y > cells[2].y && event.button.y <cells[2].y+cells[2].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[3].x && event.button.x < cells[3].x+cells[3].w)&&(event.button.y > cells[3].y && event.button.y <cells[3].y+cells[3].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[4].x && event.button.x < cells[4].x+cells[4].w)&&(event.button.y > cells[4].y && event.button.y <cells[4].y+cells[4].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[5].x && event.button.x < cells[5].x+cells[5].w)&&(event.button.y > cells[5].y && event.button.y <cells[5].y+cells[5].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[6].x && event.button.x < cells[6].x+cells[6].w)&&(event.button.y > cells[6].y && event.button.y <cells[6].y+cells[6].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[7].x && event.button.x < cells[7].x+cells[7].w)&&(event.button.y > cells[7].y && event.button.y <cells[7].y+cells[7].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[8].x && event.button.x < cells[8].x+cells[8].w)&&(event.button.y > cells[8].y && event.button.y <cells[8].y+cells[8].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[9].x && event.button.x < cells[9].x+cells[9].w)&&(event.button.y > cells[9].y && event.button.y <cells[9].y+cells[9].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[10].x && event.button.x < cells[10].x+cells[10].w)&&(event.button.y > cells[10].y && event.button.y <cells[10].y+cells[10].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[11].x && event.button.x < cells[11].x+cells[11].w)&&(event.button.y > cells[11].y && event.button.y <cells[11].y+cells[11].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[12].x && event.button.x < cells[12].x+cells[12].w)&&(event.button.y > cells[12].y && event.button.y <cells[12].y+cells[12].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[13].x && event.button.x < cells[13].x+cells[13].w)&&(event.button.y > cells[13].y && event.button.y <cells[13].y+cells[13].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[14].x && event.button.x < cells[14].x+cells[14].w)&&(event.button.y > cells[14].y && event.button.y <cells[14].y+cells[14].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[15].x && event.button.x < cells[15].x+cells[15].w)&&(event.button.y > cells[15].y && event.button.y <cells[15].y+cells[15].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[16].x && event.button.x < cells[16].x+cells[16].w)&&(event.button.y > cells[16].y && event.button.y <cells[16].y+cells[16].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[17].x && event.button.x < cells[17].x+cells[17].w)&&(event.button.y > cells[17].y && event.button.y <cells[17].y+cells[17].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[18].x && event.button.x < cells[18].x+cells[18].w)&&(event.button.y > cells[18].y && event.button.y <cells[18].y+cells[18].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[19].x && event.button.x < cells[19].x+cells[19].w)&&(event.button.y > cells[19].y && event.button.y <cells[19].y+cells[19].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[20].x && event.button.x < cells[20].x+cells[20].w)&&(event.button.y > cells[20].y && event.button.y <cells[20].y+cells[20].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[21].x && event.button.x < cells[21].x+cells[21].w)&&(event.button.y > cells[21].y && event.button.y <cells[21].y+cells[21].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[22].x && event.button.x < cells[22].x+cells[22].w)&&(event.button.y > cells[22].y && event.button.y <cells[22].y+cells[22].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[23].x && event.button.x < cells[23].x+cells[23].w)&&(event.button.y > cells[23].y && event.button.y <cells[23].y+cells[23].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[24].x && event.button.x < cells[24].x+cells[24].w)&&(event.button.y > cells[24].y && event.button.y <cells[24].y+cells[24].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[25].x && event.button.x < cells[25].x+cells[25].w)&&(event.button.y > cells[25].y && event.button.y <cells[25].y+cells[25].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[26].x && event.button.x < cells[26].x+cells[26].w)&&(event.button.y > cells[26].y && event.button.y <cells[26].y+cells[26].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[27].x && event.button.x < cells[27].x+cells[27].w)&&(event.button.y > cells[27].y && event.button.y <cells[27].y+cells[27].h))
                    {
                       table[I][J]=t1;
                       concord[I][J]=1;
                    }
                    else if((event.button.x >cells[28].x && event.button.x < cells[28].x+cells[28].w)&&(event.button.y > cells[28].y && event.button.y <cells[28].y+cells[28].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[29].x && event.button.x < cells[29].x+cells[29].w)&&(event.button.y > cells[29].y && event.button.y <cells[29].y+cells[29].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[30].x && event.button.x < cells[30].x+cells[30].w)&&(event.button.y > cells[30].y && event.button.y <cells[30].y+cells[30].h))
                    {
                       table[I][J]=t1;
                       concord[I][J]=1;
                    }
                    else if((event.button.x >cells[31].x && event.button.x < cells[31].x+cells[31].w)&&(event.button.y > cells[31].y && event.button.y <cells[31].y+cells[31].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[32].x && event.button.x < cells[32].x+cells[32].w)&&(event.button.y > cells[32].y && event.button.y <cells[32].y+cells[32].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[33].x && event.button.x < cells[33].x+cells[33].w)&&(event.button.y > cells[33].y && event.button.y <cells[33].y+cells[33].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[34].x && event.button.x < cells[34].x+cells[34].w)&&(event.button.y > cells[34].y && event.button.y <cells[34].y+cells[34].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[35].x && event.button.x < cells[35].x+cells[35].w)&&(event.button.y > cells[35].y && event.button.y <cells[35].y+cells[35].h))
                    {
                       table[I][J]=t1;
                       concord[I][J]=1;
                    }
                }
                else if(event.button.button == SDL_BUTTON_LEFT && table[I][J] == t1)
                {
                     if((event.button.x >cells[0].x && event.button.x < cells[0].x+cells[0].w)&&(event.button.y > cells[0].y && event.button.y <cells[0].y+cells[0].h))
                    {
                        table[I][J]=t2;
                        concord[I][J]=2;
                    }
                    else if((event.button.x >cells[1].x && event.button.x < cells[1].x+cells[1].w)&&(event.button.y > cells[1].y && event.button.y <cells[1].y+cells[1].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[2].x && event.button.x < cells[2].x+cells[2].w)&&(event.button.y > cells[2].y && event.button.y <cells[2].y+cells[2].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[3].x && event.button.x < cells[3].x+cells[3].w)&&(event.button.y > cells[3].y && event.button.y <cells[3].y+cells[3].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[4].x && event.button.x < cells[4].x+cells[4].w)&&(event.button.y > cells[4].y && event.button.y <cells[4].y+cells[4].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[5].x && event.button.x < cells[5].x+cells[5].w)&&(event.button.y > cells[5].y && event.button.y <cells[5].y+cells[5].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[6].x && event.button.x < cells[6].x+cells[6].w)&&(event.button.y > cells[6].y && event.button.y <cells[6].y+cells[6].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[7].x && event.button.x < cells[7].x+cells[7].w)&&(event.button.y > cells[7].y && event.button.y <cells[7].y+cells[7].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[8].x && event.button.x < cells[8].x+cells[8].w)&&(event.button.y > cells[8].y && event.button.y <cells[8].y+cells[8].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[9].x && event.button.x < cells[9].x+cells[9].w)&&(event.button.y > cells[9].y && event.button.y <cells[9].y+cells[9].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[10].x && event.button.x < cells[10].x+cells[10].w)&&(event.button.y > cells[10].y && event.button.y <cells[10].y+cells[10].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[11].x && event.button.x < cells[11].x+cells[11].w)&&(event.button.y > cells[11].y && event.button.y <cells[11].y+cells[11].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[12].x && event.button.x < cells[12].x+cells[12].w)&&(event.button.y > cells[12].y && event.button.y <cells[12].y+cells[12].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[13].x && event.button.x < cells[13].x+cells[13].w)&&(event.button.y > cells[13].y && event.button.y <cells[13].y+cells[13].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[14].x && event.button.x < cells[14].x+cells[14].w)&&(event.button.y > cells[14].y && event.button.y <cells[14].y+cells[14].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[15].x && event.button.x < cells[15].x+cells[15].w)&&(event.button.y > cells[15].y && event.button.y <cells[15].y+cells[15].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[16].x && event.button.x < cells[16].x+cells[16].w)&&(event.button.y > cells[16].y && event.button.y <cells[16].y+cells[16].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[17].x && event.button.x < cells[17].x+cells[17].w)&&(event.button.y > cells[17].y && event.button.y <cells[17].y+cells[17].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[18].x && event.button.x < cells[18].x+cells[18].w)&&(event.button.y > cells[18].y && event.button.y <cells[18].y+cells[18].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[19].x && event.button.x < cells[19].x+cells[19].w)&&(event.button.y > cells[19].y && event.button.y <cells[19].y+cells[19].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[20].x && event.button.x < cells[20].x+cells[20].w)&&(event.button.y > cells[20].y && event.button.y <cells[20].y+cells[20].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[21].x && event.button.x < cells[21].x+cells[21].w)&&(event.button.y > cells[21].y && event.button.y <cells[21].y+cells[21].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[22].x && event.button.x < cells[22].x+cells[22].w)&&(event.button.y > cells[22].y && event.button.y <cells[22].y+cells[22].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[23].x && event.button.x < cells[23].x+cells[23].w)&&(event.button.y > cells[23].y && event.button.y <cells[23].y+cells[23].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[24].x && event.button.x < cells[24].x+cells[24].w)&&(event.button.y > cells[24].y && event.button.y <cells[24].y+cells[24].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[25].x && event.button.x < cells[25].x+cells[25].w)&&(event.button.y > cells[25].y && event.button.y <cells[25].y+cells[25].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[26].x && event.button.x < cells[26].x+cells[26].w)&&(event.button.y > cells[26].y && event.button.y <cells[26].y+cells[26].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[27].x && event.button.x < cells[27].x+cells[27].w)&&(event.button.y > cells[27].y && event.button.y <cells[27].y+cells[27].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[28].x && event.button.x < cells[28].x+cells[28].w)&&(event.button.y > cells[28].y && event.button.y <cells[28].y+cells[28].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[29].x && event.button.x < cells[29].x+cells[29].w)&&(event.button.y > cells[29].y && event.button.y <cells[29].y+cells[29].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[30].x && event.button.x < cells[30].x+cells[30].w)&&(event.button.y > cells[30].y && event.button.y <cells[30].y+cells[30].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[31].x && event.button.x < cells[31].x+cells[31].w)&&(event.button.y > cells[31].y && event.button.y <cells[31].y+cells[31].h))
                    {
                      table[I][J]=t2;
                      concord[I][J]=2;
                    }
                    else if((event.button.x >cells[32].x && event.button.x < cells[32].x+cells[32].w)&&(event.button.y > cells[32].y && event.button.y <cells[32].y+cells[32].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[33].x && event.button.x < cells[33].x+cells[33].w)&&(event.button.y > cells[33].y && event.button.y <cells[33].y+cells[33].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[34].x && event.button.x < cells[34].x+cells[34].w)&&(event.button.y > cells[34].y && event.button.y <cells[34].y+cells[34].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[35].x && event.button.x < cells[35].x+cells[35].w)&&(event.button.y > cells[35].y && event.button.y <cells[35].y+cells[35].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                }
                else if(event.button.button == SDL_BUTTON_LEFT && table[I][J] == t2)
                {
                     if((event.button.x >cells[0].x && event.button.x < cells[0].x+cells[0].w)&&(event.button.y > cells[0].y && event.button.y <cells[0].y+cells[0].h))
                    {
                        table[I][J]=t0;
                        concord[I][J]=0;
                    }
                    else if((event.button.x >cells[1].x && event.button.x < cells[1].x+cells[1].w)&&(event.button.y > cells[1].y && event.button.y <cells[1].y+cells[1].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[2].x && event.button.x < cells[2].x+cells[2].w)&&(event.button.y > cells[2].y && event.button.y <cells[2].y+cells[2].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[3].x && event.button.x < cells[3].x+cells[3].w)&&(event.button.y > cells[3].y && event.button.y <cells[3].y+cells[3].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[4].x && event.button.x < cells[4].x+cells[4].w)&&(event.button.y > cells[4].y && event.button.y <cells[4].y+cells[4].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[5].x && event.button.x < cells[5].x+cells[5].w)&&(event.button.y > cells[5].y && event.button.y <cells[5].y+cells[5].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[6].x && event.button.x < cells[6].x+cells[6].w)&&(event.button.y > cells[6].y && event.button.y <cells[6].y+cells[6].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[7].x && event.button.x < cells[7].x+cells[7].w)&&(event.button.y > cells[7].y && event.button.y <cells[7].y+cells[7].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[8].x && event.button.x < cells[8].x+cells[8].w)&&(event.button.y > cells[8].y && event.button.y <cells[8].y+cells[8].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[9].x && event.button.x < cells[9].x+cells[9].w)&&(event.button.y > cells[9].y && event.button.y <cells[9].y+cells[9].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[10].x && event.button.x < cells[10].x+cells[10].w)&&(event.button.y > cells[10].y && event.button.y <cells[10].y+cells[10].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[11].x && event.button.x < cells[11].x+cells[11].w)&&(event.button.y > cells[11].y && event.button.y <cells[11].y+cells[11].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[12].x && event.button.x < cells[12].x+cells[12].w)&&(event.button.y > cells[12].y && event.button.y <cells[12].y+cells[12].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[13].x && event.button.x < cells[13].x+cells[13].w)&&(event.button.y > cells[13].y && event.button.y <cells[13].y+cells[13].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[14].x && event.button.x < cells[14].x+cells[14].w)&&(event.button.y > cells[14].y && event.button.y <cells[14].y+cells[14].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[15].x && event.button.x < cells[15].x+cells[15].w)&&(event.button.y > cells[15].y && event.button.y <cells[15].y+cells[15].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[16].x && event.button.x < cells[16].x+cells[16].w)&&(event.button.y > cells[16].y && event.button.y <cells[16].y+cells[16].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[17].x && event.button.x < cells[17].x+cells[17].w)&&(event.button.y > cells[17].y && event.button.y <cells[17].y+cells[17].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[18].x && event.button.x < cells[18].x+cells[18].w)&&(event.button.y > cells[18].y && event.button.y <cells[18].y+cells[18].h))
                    {
                      table[I][J]=t0;
                      concord[I][J]=0;
                    }
                    else if((event.button.x >cells[19].x && event.button.x < cells[19].x+cells[19].w)&&(event.button.y > cells[19].y && event.button.y <cells[19].y+cells[19].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[20].x && event.button.x < cells[20].x+cells[20].w)&&(event.button.y > cells[20].y && event.button.y <cells[20].y+cells[20].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[21].x && event.button.x < cells[21].x+cells[21].w)&&(event.button.y > cells[21].y && event.button.y <cells[21].y+cells[21].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[22].x && event.button.x < cells[22].x+cells[22].w)&&(event.button.y > cells[22].y && event.button.y <cells[22].y+cells[22].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[23].x && event.button.x < cells[23].x+cells[23].w)&&(event.button.y > cells[23].y && event.button.y <cells[23].y+cells[23].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[24].x && event.button.x < cells[24].x+cells[24].w)&&(event.button.y > cells[24].y && event.button.y <cells[24].y+cells[24].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[25].x && event.button.x < cells[25].x+cells[25].w)&&(event.button.y > cells[25].y && event.button.y <cells[25].y+cells[25].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[26].x && event.button.x < cells[26].x+cells[26].w)&&(event.button.y > cells[26].y && event.button.y <cells[26].y+cells[26].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[27].x && event.button.x < cells[27].x+cells[27].w)&&(event.button.y > cells[27].y && event.button.y <cells[27].y+cells[27].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[28].x && event.button.x < cells[28].x+cells[28].w)&&(event.button.y > cells[28].y && event.button.y <cells[28].y+cells[28].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[29].x && event.button.x < cells[29].x+cells[29].w)&&(event.button.y > cells[29].y && event.button.y <cells[29].y+cells[29].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[30].x && event.button.x < cells[30].x+cells[30].w)&&(event.button.y > cells[30].y && event.button.y <cells[30].y+cells[30].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[31].x && event.button.x < cells[31].x+cells[31].w)&&(event.button.y > cells[31].y && event.button.y <cells[31].y+cells[31].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[32].x && event.button.x < cells[32].x+cells[32].w)&&(event.button.y > cells[32].y && event.button.y <cells[32].y+cells[32].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[33].x && event.button.x < cells[33].x+cells[33].w)&&(event.button.y > cells[33].y && event.button.y <cells[33].y+cells[33].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[34].x && event.button.x < cells[34].x+cells[34].w)&&(event.button.y > cells[34].y && event.button.y <cells[34].y+cells[34].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[35].x && event.button.x < cells[35].x+cells[35].w)&&(event.button.y > cells[35].y && event.button.y <cells[35].y+cells[35].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                }
            }
        }






//if(now-before<delta)
	//SDL_Delay(delta-(now-before));



     e=0;
     for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
           Blit(renderer,table[i][j],cells[e]);
           e++;
        }

    }

if(jeuFin(sol)==0){
tfinale = now;
running = false;
}
                 //drawing the points


                draw_Model(points,renderer,grid);
                 //draw settings
                 Draw_Settings(renderer);

// Show what was drawn
                SDL_RenderPresent(renderer);

  //  before=now;





    }
    SDL_DestroyTexture(t);
    SDL_DestroyTexture(t0);
    SDL_DestroyTexture(t1);
    SDL_DestroyTexture(t2);

if(tquit == 0){
exit(0);

}


 }

 void jeuOrdi(SDL_Renderer *renderer,SDL_Window * window, int grid[7][7], int sol[6][6], int mod)
 {


    SDL_Rect points[49],cells[36];
    bool running=true;
    int x,y,e, randI,randJ, randA, lock;
    int tquit=1;
    bool pause = true;




    //int now =100, before=95,delta=50;
    unsigned now, start, ptime, savedtime;
    //delta = 0;
    SDL_Texture * t2 = initialize_texture_from_file("patterncellrl.png", renderer);
    SDL_Texture * t1 = initialize_texture_from_file("patterncelllr.png", renderer);
    SDL_Texture * t0 = initialize_texture_from_file("patterncell.png", renderer);
    SDL_Texture * t=t0;
    // drawing the game

      // draw timer

     // draw icone
      Icon(window);

     SDL_Texture *table[6][6];
      if(mod==1){

      for (i=0; i<6; i++)
        {
           for(j=0; j<6; j++){
            if (concordComp[i][j] == 0){
                table[i][j] = t0;
            }
            else if(concordComp[i][j] == 1){
               table[i][j] = t1;

           } else if(concordComp[i][j] == 2){
               table[i][j] = t2;
        }
        }
        }
    }
    else{

      for (i=0; i<6; i++)
        {
           for(j=0; j<6; j++)
            {
             table[i][j] = t0;
            }
       }
    }


       SDL_Event event;
    start = SDL_GetTicks();



    while(running)
    {
lock =0;
Draw_Game(renderer,points,cells);
if(mod == 1){
    now = SDL_GetTicks() - start + loadTime;
}else{
     now = SDL_GetTicks()- start;
}
Draw_Timer(renderer, now);
    pause = true;
        SDL_PumpEvents();  // make sure we have the latest mouse state.

     SDL_GetMouseState(&x, &y);








   while(SDL_PollEvent(&event) && jeuFin(sol)!=0)
        {


            if(event.type == SDL_QUIT)
            {
                running = false;
                tquit = 0;
            }


            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                    if((event.button.x >715 && event.button.x < 775)&&(event.button.y >0 && event.button.y <55)){
                    ptime = now;
                    if(lock != 1){
                        savedtime = now;
                        lock = 1;
                    }
                    pauseMode(renderer);

                    while(pause == true){

                    ptime = SDL_GetTicks() - now;
                    while(SDL_PollEvent(&event)){


                         if(event.type == SDL_QUIT)
                       {
                            pause = false;
                            running = false;
                            tquit = 0;
                       }
                       else if(event.type ==  SDL_MOUSEBUTTONDOWN){
                        if((event.button.x >350 && event.button.x < 350+150)&&(event.button.y >189 && event.button.y <189+70)){
                        if(mod ==1){
                            ptime += loadTime;
                            start = ptime;
                        }else{
                            start = ptime;
                        }

                        pause = false;
                        }
                        else if((event.button.x >350 && event.button.x < 350+150)&&(event.button.y >320 && event.button.y <370)){

                            saveGame(savedtime, concord, concordComp, sol, grid, saveFile, 1, 2);

                            pause = false;
                            running = false;
                            tquit = 0;

                        }
                        else if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >450 && event.button.y <500)){
                            exit(0);
                        }
                       }
                    }

                    }
                }


                }
            }


if(now < 5000)
    {
        randA = rand()%75;
    }
else if(now >= 5000 && now < 15000)
    {
        randA = rand()%45;
    }
else if(now >= 15000 && now < 35000)
    {
        randA = rand()%35;
    }
else if(now >= 35000)
    {
        randA = rand()%20;
    }
if(randA<10){
randI = rand()%6;
randJ = rand()%6;

if(concordComp[randI][randJ]!= sol[randI][randJ]){




        concordComp[randI][randJ] = rand()%2 +1;
        if(concordComp[randI][randJ] == 1){

            table[randI][randJ] = t1;
        } else if(concordComp[randI][randJ] == 2){

            table[randI][randJ] = t2;
        }



}
}

//if(now-before<delta)
	//SDL_Delay(delta-(now-before));



     e=0;
     for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
           Blit(renderer,table[i][j],cells[e]);
           e++;
        }

    }

if(jeuFinOrdi(sol)==0){
tfinale = now;
running = false;
}


                 //drawing the points


                draw_Model(points,renderer,grid);
                 //draw settings
                 Draw_Settings(renderer);
                SDL_RenderPresent(renderer);
// Show what was drawn
                SDL_RenderClear(renderer);

  //  before=now;



    }


    SDL_DestroyTexture(t);
    SDL_DestroyTexture(t0);
    SDL_DestroyTexture(t1);
    SDL_DestroyTexture(t2);
if(jeuFinOrdi(sol)==0){
    compFin(renderer, tfinale);
    SDL_RenderPresent(renderer);
    SDL_Delay(4000);
}


if(tquit == 0){
exit(0);

}

}





void youWin2(SDL_Renderer*renderer, SDL_Window * window, unsigned tfinale)
{

SDL_SetWindowSize(window,800,600);
SDL_SetWindowPosition(window,50,50);

    bool run = true;


    SDL_Texture *NamePlace;

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    TTF_Font * fontTitle = TTF_OpenFont("SF Atarian System.ttf", 40);
    SDL_Color color = { 255, 255, 255 };
    SDL_Color colorTitle = { 240, 120, 28 };

    SDL_Surface * surfacew1 = TTF_RenderText_Solid(fontTitle,
    "You have beaten the computer!" , colorTitle);

    SDL_Surface * surfacew2 = TTF_RenderText_Solid(font,
    "Enter your name", color);






    SDL_Texture * texturew1 = SDL_CreateTextureFromSurface(renderer, surfacew1);

    SDL_Texture * texturew2 = SDL_CreateTextureFromSurface(renderer, surfacew2);





    SDL_Rect dstrectw1 = { 150, 50, 500, 100 };


    SDL_Rect dstrectw2 = { 150, 200+50, 500, 90 };









    SDL_StartTextInput();


while(run){
        SDL_Event e;
        SDL_RenderCopy(renderer, texturew1, NULL,  &dstrectw1);

        SDL_RenderCopy(renderer, texturew2, NULL,  &dstrectw2);
        SDL_Rect dstrectw3 =  { 365- (10*(strlen(Name)+1)), 450, 30*(strlen(Name)+1) ,  30 };
        NamePlace=initialize_texture_from_TTF(Name,renderer);
        Blit(renderer,NamePlace,dstrectw3);

        SDL_RenderPresent(renderer);


        while(SDL_PollEvent(&e)){

            if(e.type == SDL_QUIT){
                run =false;
                printf("%s", Name);
                exit(0);
            }
            else if(e.type == SDL_KEYDOWN){
                    if(e.key.keysym.sym == SDLK_BACKSPACE && strlen(Name)>0){
                Name[strlen(Name)-1] = '\0';
               }

            }



            else if(e.type == SDL_TEXTINPUT && e.key.keysym.sym != SDLK_KP_ENTER){
                      strcat(Name, e.text.text);
             }

            else if(e.type == SDL_MOUSEBUTTONDOWN){
                run = false;
            }



    }

SDL_RenderClear(renderer);
}

    SDL_StopTextInput();

    SDL_DestroyTexture(texturew1);
    SDL_FreeSurface(surfacew1);

    SDL_DestroyTexture(texturew2);
    SDL_FreeSurface(surfacew2);
    SDL_DestroyTexture(NamePlace);


    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);




 }


// drawing settings for new mode
int Draw_Settings2(SDL_Renderer * renderer)
{

    SDL_Texture *textureset=initialize_texture_from_file("settingssbutton.jpg",renderer);
    SDL_Rect setpos;
    setpos.x=1170;
    setpos.y=1;
    setpos.w=60;
    setpos.h=55;
    Blit(renderer,textureset,setpos);

    SDL_DestroyTexture(textureset);
    return 0;
}

// drawing timer for new mode
void Draw_Timer2(SDL_Renderer *renderer, int tiempo)
{


      SDL_Rect timerpos;
        mss = tiempo % 1000;//miliseconde
        ss = tiempo / 1000 ;  // seconde



      timerpos.x=600;
      timerpos.y=45;
      timerpos.w=68;
      timerpos.h=19;
      char temps[20];
      SDL_Texture *timer;
      sprintf(temps,"%d:%d", ss, mss); // on sauvgarde les secondes dans le tompant temps
      timer=initialize_texture_from_TTF(temps,renderer);
      Blit(renderer,timer,timerpos);

      SDL_DestroyTexture(timer);

}

///rawing the new game
void Draw_comps(SDL_Renderer *renderer,SDL_Window *window,SDL_Rect points[49],SDL_Rect cells[36],SDL_Rect cells2[36],SDL_Rect points2[49])
{
    SDL_SetWindowSize(window,1230,600);
    SDL_SetWindowPosition(window,50,50);
    SDL_Texture * image_texture = initialize_texture_from_file("fulltitlebar.png", renderer);

    SDL_Texture * image_texture1 = initialize_texture_from_file("timer.png", renderer);
    SDL_Texture * image_texture2 = initialize_texture_from_file("yourscoreback.png", renderer);
    SDL_Texture * image_texture3 = initialize_texture_from_file("patterncell.png", renderer);
    SDL_Texture * image_texture4 = initialize_texture_from_file("cellpoints1.png", renderer);
    SDL_Texture * image = initialize_texture_from_file("bs.png", renderer);
    SDL_Texture * image_texture0 = initialize_texture_from_file("background.png", renderer);




    // Define where on the "screen" we want to draw the texture

    SDL_Rect texture_destination,texture_destination1,texture_destination2, texture_destination0,bs;

    texture_destination0.x =0;
  texture_destination0.y = 0;
  texture_destination0.w = 1260;
  texture_destination0.h = 600;

  bs.x =628;
  bs.y =67;
  bs.w = 2;
  bs.h = 600;



    texture_destination.x = 615;
    texture_destination.y = 0;
    texture_destination.w = 40;
    texture_destination.h = 40;

    texture_destination1.x = 0;
    texture_destination1.y = 0;
    texture_destination1.w = 1260;
    texture_destination1.h = 67;

    texture_destination2.x = 0;
    texture_destination2.y = 0;
    texture_destination2.w = 1300;
    texture_destination2.h = 650;


    // initialisation des rectangles pour contenir les cellules des cases
    cells2[0].x = 100;
    cells2[0].y =cells[0].y= 116;
    cells[0].x=700;


    int i,x=cells2[0].x,j=cells[0].x ;

    // une boucle pour attribuer les positions a chaque cellule
    for(i=1;i<36;i++)
        {
            cells2[i].x=x+75;
            cells2[i].y=cells2[i-1].y;
            x=x+75;
            if(i%6==0){
                x=100;
                cells2[i].y=cells2[i-1].y+75;
                cells2[i].x=x;
            }
        }

        // une boucle pour attribuer les positions a chaque cellule
    for(i=1;i<36;i++)
        {
            cells[i].x=j+75;
            cells[i].y=cells[i-1].y;
            j=j+75;
            if(i%6==0){
                j=700;
                cells[i].y=cells[i-1].y+75;
                cells[i].x=j;
            }
        }

      // initialisation des points


    x=points2[0].x = 65;
    points2[0].y =points[0].y= 82;
    j=points[0].x=665;
      // une boucle pour attribuer les positions a chaque point
    for(i=1;i<49;i++)
        {
               points2[i].x=x+75;
               points2[i].y=points2[i-1].y;
               x=x+75;
            if(i%7==0){
                x=65;
                points2[i].y=points2[i-1].y+75;
                points2[i].x=x;
            }
        }
           // une boucle pour attribuer les positions a chaque point
    for(i=1;i<49;i++)
        {
               points[i].x=j+75;
               points[i].y=points[i-1].y;
               j=j+75;
            if(i%7==0){
                j=665;
                points[i].y=points[i-1].y+75;
                points[i].x=j;
            }
        }

     // deux boucles pour attribuer les dimensions a chaque point et cellule
            for(i=0;i<36;i++)
               {
                  cells2[i].w =cells[i].w=75;
                  cells2[i].h =cells[i].h=75;
               }
            for(i=0;i<49;i++)
               {
                   points2[i].w=points[i].w=70;
                   points2[i].h=points[i].h=70;
               }
         // Draw
        Blit(renderer, image_texture0,texture_destination0);
        Blit(renderer, image_texture2,texture_destination2); //presentation du fond d'ecran
        Blit(renderer, image_texture,texture_destination1); // the watch drawing
        Blit(renderer, image_texture1,texture_destination); // les bordures

        // presentation des cellules

        for(i=0;i<36;i++)
        Blit(renderer, image_texture3,cells2[i]);

        for(i=0;i<36;i++)
        Blit(renderer, image_texture3,cells[i]);

        // presentation des points

        for(i=0;i<49;i++)
        Blit(renderer, image_texture4,points2[i]);

        for(i=0;i<49;i++)
        Blit(renderer, image_texture4,points[i]);

        Blit(renderer,image,bs);

    SDL_DestroyTexture(image_texture0);
    SDL_DestroyTexture(image_texture);
    SDL_DestroyTexture(image_texture1);
    SDL_DestroyTexture(image_texture2);
    SDL_DestroyTexture(image_texture3);
    SDL_DestroyTexture(image_texture4);

}


void youLose(SDL_Renderer *renderer,SDL_Window *window){

SDL_SetWindowSize(window,800,600);
SDL_SetWindowPosition(window,50,50);




    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,96,115,130,255);
    TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    TTF_Font * fontTitle = TTF_OpenFont("SF Atarian System.ttf", 40);
    SDL_Color color = { 255, 255, 255 };
    SDL_Color colorTitle = { 240, 120, 28 };

    SDL_Surface * surfacew1 = TTF_RenderText_Solid(fontTitle,
    "Sorry, the program defeated you" , colorTitle);

    SDL_Surface * surfacew2 = TTF_RenderText_Solid(font,
    "Better luck next time", color);






    SDL_Texture * texturew1 = SDL_CreateTextureFromSurface(renderer, surfacew1);

    SDL_Texture * texturew2 = SDL_CreateTextureFromSurface(renderer, surfacew2);





    SDL_Rect dstrectw1 = { 150, 50, 500, 100 };


    SDL_Rect dstrectw2 = { 150, 200+50, 500, 90 };












        SDL_RenderCopy(renderer, texturew1, NULL,  &dstrectw1);

        SDL_RenderCopy(renderer, texturew2, NULL,  &dstrectw2);



        SDL_RenderPresent(renderer);




SDL_RenderClear(renderer);
 SDL_DestroyTexture(texturew1);
    SDL_FreeSurface(surfacew1);

    SDL_DestroyTexture(texturew2);
    SDL_FreeSurface(surfacew2);



    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);

}




/// mode computer
void compvsplayer(SDL_Renderer *renderer,SDL_Window * window, int grid[7][7], int sol[6][6], int mod)
{
   SDL_Rect points[49],cells[36],points2[49],cells2[36];
    bool running=true;
    bool pause = true;
    int I,J,i,j,x,y,e, randI,randJ, randA, lock;
    int tquit=1;



    //int now =100, before=95,delta=50;
    unsigned now, start, tfinal, savedtime, ptime;
    SDL_Texture * t2 = initialize_texture_from_file("patterncellrl.png", renderer);
    SDL_Texture * t1 = initialize_texture_from_file("patterncelllr.png", renderer);
    SDL_Texture * t0 = initialize_texture_from_file("patterncell.png", renderer);
    SDL_Texture * t=t0;
    // drawing the game

      // draw timer

     // draw icone
      Icon(window);

     SDL_Texture *table[6][6];

          SDL_Texture *table2[6][6];
      for (i=0; i<6; i++)
        {
           for(j=0; j<6; j++)
            {
             table2[i][j] = t0;
            }
       }
    if(mod==1){

      for (i=0; i<6; i++)
        {
           for(j=0; j<6; j++){
            if (concord[i][j] == 0){
                table[i][j] = t0;
            }
            else if(concord[i][j] == 1){
               table[i][j] = t1;

           } else if(concord[i][j] == 2){
               table[i][j] = t2;
        }
            if (concordComp[i][j] == 0){
                table2[i][j] = t0;
            }
            else if(concordComp[i][j] == 1){
               table2[i][j] = t1;

           } else if(concordComp[i][j] == 2){
               table2[i][j] = t2;
        }
        }
        }
    }
    else{

      for (i=0; i<6; i++)
        {
           for(j=0; j<6; j++)
            {
             table[i][j] = t0;
             table2[i][j] = t0;
            }
       }
    }


       SDL_Event event;
    start = SDL_GetTicks();



while(running)
    {
pause = true;
lock =0;
if(mod == 1){
    now = SDL_GetTicks() - start + loadTime;
}else{
     now = SDL_GetTicks()- start;
}
        SDL_PumpEvents();  // make sure we have the latest mouse state.

     SDL_GetMouseState(&x, &y);

    //SDL_Log("Mouse cursor is at %d, %d", x, y);

    if(x>cells[0].x && x<cells[0].x + cells[0].w){J = 0;}
    else if(x>cells[1].x && x<cells[1].x + cells[1].w){J = 1;}
    else if(x>cells[2].x && x<cells[2].x + cells[2].w){J = 2;}
    else if(x>cells[3].x && x<cells[3].x + cells[3].w){J = 3;}
    else if(x>cells[4].x && x<cells[4].x + cells[4].w){J = 4;}
    else if(x>cells[5].x && x<cells[5].x + cells[5].w){J = 5;}


    if(y>cells[0].y && y < cells[0].y + cells[0].h){I = 0;}
    else if(y>cells[6].y && y< cells[6].y + cells[6].h){I = 1;}
    else if(y>cells[12].y && y< cells[12].y + cells[12].h){I = 2;}
    else if(y>cells[18].y && y< cells[18].y + cells[18].h){I = 3;}
    else if(y>cells[24].y && y< cells[24].y + cells[24].h){I = 4;}
    else if(y>cells[30].y && y< cells[30].y + cells[30].h){I = 5;}


    Draw_comps(renderer,window,points,cells,cells2,points2);
    Draw_Timer2(renderer, now);




   while(SDL_PollEvent(&event))
        {


            if(event.type == SDL_QUIT)
            {
                running = false;
                tquit = 0;
                exit(0);
            }



            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {

                if((event.button.x >1170 && event.button.x < 1230)&&(event.button.y >0 && event.button.y <55)){
                    ptime = now;
                    if(lock != 1){
                        savedtime = now;
                        lock = 1;
                    }
                    pauseMode(renderer);

                    while(pause == true){

                    ptime = SDL_GetTicks() - now;
                    while(SDL_PollEvent(&event)){


                         if(event.type == SDL_QUIT)
                       {
                            pause = false;
                            running = false;
                            tquit = 0;
                       }
                       else if(event.type ==  SDL_MOUSEBUTTONDOWN){
                        if((event.button.x >350 && event.button.x < 350+150)&&(event.button.y >189 && event.button.y <189+70)){
                        if(mod ==1){
                            ptime += loadTime;
                            start = ptime;
                        }else{
                            start = ptime;
                        }

                        pause = false;
                        }
                        else if((event.button.x >350 && event.button.x < 350+150)&&(event.button.y >320 && event.button.y <370)){

                            saveGame(savedtime, concord, concordComp, sol, grid, saveFile, 1, 3);

                            pause = false;
                            running = false;
                            tquit = 0;

                        }
                        else if((event.button.x >300 && event.button.x < 350+150)&&(event.button.y >450 && event.button.y <500)){
                            exit(0);
                        }
                       }
                    }

                    }
                }



                else if(event.button.button == SDL_BUTTON_LEFT && table[I][J] == t0)
                {
                    if((event.button.x >cells[0].x && event.button.x < cells[0].x+cells[0].w)&&(event.button.y > cells[0].y && event.button.y <cells[0].y+cells[0].h))
                    {
                         table[I][J]=t1;
                         concord[I][J]=1;
                    }
                    else if((event.button.x >cells[1].x && event.button.x < cells[1].x+cells[1].w)&&(event.button.y > cells[1].y && event.button.y <cells[1].y+cells[1].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[2].x && event.button.x < cells[2].x+cells[2].w)&&(event.button.y > cells[2].y && event.button.y <cells[2].y+cells[2].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[3].x && event.button.x < cells[3].x+cells[3].w)&&(event.button.y > cells[3].y && event.button.y <cells[3].y+cells[3].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[4].x && event.button.x < cells[4].x+cells[4].w)&&(event.button.y > cells[4].y && event.button.y <cells[4].y+cells[4].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[5].x && event.button.x < cells[5].x+cells[5].w)&&(event.button.y > cells[5].y && event.button.y <cells[5].y+cells[5].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[6].x && event.button.x < cells[6].x+cells[6].w)&&(event.button.y > cells[6].y && event.button.y <cells[6].y+cells[6].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[7].x && event.button.x < cells[7].x+cells[7].w)&&(event.button.y > cells[7].y && event.button.y <cells[7].y+cells[7].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[8].x && event.button.x < cells[8].x+cells[8].w)&&(event.button.y > cells[8].y && event.button.y <cells[8].y+cells[8].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[9].x && event.button.x < cells[9].x+cells[9].w)&&(event.button.y > cells[9].y && event.button.y <cells[9].y+cells[9].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[10].x && event.button.x < cells[10].x+cells[10].w)&&(event.button.y > cells[10].y && event.button.y <cells[10].y+cells[10].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[11].x && event.button.x < cells[11].x+cells[11].w)&&(event.button.y > cells[11].y && event.button.y <cells[11].y+cells[11].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[12].x && event.button.x < cells[12].x+cells[12].w)&&(event.button.y > cells[12].y && event.button.y <cells[12].y+cells[12].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[13].x && event.button.x < cells[13].x+cells[13].w)&&(event.button.y > cells[13].y && event.button.y <cells[13].y+cells[13].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[14].x && event.button.x < cells[14].x+cells[14].w)&&(event.button.y > cells[14].y && event.button.y <cells[14].y+cells[14].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[15].x && event.button.x < cells[15].x+cells[15].w)&&(event.button.y > cells[15].y && event.button.y <cells[15].y+cells[15].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[16].x && event.button.x < cells[16].x+cells[16].w)&&(event.button.y > cells[16].y && event.button.y <cells[16].y+cells[16].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[17].x && event.button.x < cells[17].x+cells[17].w)&&(event.button.y > cells[17].y && event.button.y <cells[17].y+cells[17].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[18].x && event.button.x < cells[18].x+cells[18].w)&&(event.button.y > cells[18].y && event.button.y <cells[18].y+cells[18].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[19].x && event.button.x < cells[19].x+cells[19].w)&&(event.button.y > cells[19].y && event.button.y <cells[19].y+cells[19].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[20].x && event.button.x < cells[20].x+cells[20].w)&&(event.button.y > cells[20].y && event.button.y <cells[20].y+cells[20].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[21].x && event.button.x < cells[21].x+cells[21].w)&&(event.button.y > cells[21].y && event.button.y <cells[21].y+cells[21].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[22].x && event.button.x < cells[22].x+cells[22].w)&&(event.button.y > cells[22].y && event.button.y <cells[22].y+cells[22].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[23].x && event.button.x < cells[23].x+cells[23].w)&&(event.button.y > cells[23].y && event.button.y <cells[23].y+cells[23].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[24].x && event.button.x < cells[24].x+cells[24].w)&&(event.button.y > cells[24].y && event.button.y <cells[24].y+cells[24].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[25].x && event.button.x < cells[25].x+cells[25].w)&&(event.button.y > cells[25].y && event.button.y <cells[25].y+cells[25].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[26].x && event.button.x < cells[26].x+cells[26].w)&&(event.button.y > cells[26].y && event.button.y <cells[26].y+cells[26].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[27].x && event.button.x < cells[27].x+cells[27].w)&&(event.button.y > cells[27].y && event.button.y <cells[27].y+cells[27].h))
                    {
                       table[I][J]=t1;
                       concord[I][J]=1;
                    }
                    else if((event.button.x >cells[28].x && event.button.x < cells[28].x+cells[28].w)&&(event.button.y > cells[28].y && event.button.y <cells[28].y+cells[28].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[29].x && event.button.x < cells[29].x+cells[29].w)&&(event.button.y > cells[29].y && event.button.y <cells[29].y+cells[29].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[30].x && event.button.x < cells[30].x+cells[30].w)&&(event.button.y > cells[30].y && event.button.y <cells[30].y+cells[30].h))
                    {
                       table[I][J]=t1;
                       concord[I][J]=1;
                    }
                    else if((event.button.x >cells[31].x && event.button.x < cells[31].x+cells[31].w)&&(event.button.y > cells[31].y && event.button.y <cells[31].y+cells[31].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[32].x && event.button.x < cells[32].x+cells[32].w)&&(event.button.y > cells[32].y && event.button.y <cells[32].y+cells[32].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[33].x && event.button.x < cells[33].x+cells[33].w)&&(event.button.y > cells[33].y && event.button.y <cells[33].y+cells[33].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[34].x && event.button.x < cells[34].x+cells[34].w)&&(event.button.y > cells[34].y && event.button.y <cells[34].y+cells[34].h))
                    {
                        table[I][J]=t1;
                        concord[I][J]=1;
                    }
                    else if((event.button.x >cells[35].x && event.button.x < cells[35].x+cells[35].w)&&(event.button.y > cells[35].y && event.button.y <cells[35].y+cells[35].h))
                    {
                       table[I][J]=t1;
                       concord[I][J]=1;
                    }
                }
                else if(event.button.button == SDL_BUTTON_LEFT && table[I][J] == t1)
                {
                     if((event.button.x >cells[0].x && event.button.x < cells[0].x+cells[0].w)&&(event.button.y > cells[0].y && event.button.y <cells[0].y+cells[0].h))
                    {
                        table[I][J]=t2;
                        concord[I][J]=2;
                    }
                    else if((event.button.x >cells[1].x && event.button.x < cells[1].x+cells[1].w)&&(event.button.y > cells[1].y && event.button.y <cells[1].y+cells[1].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[2].x && event.button.x < cells[2].x+cells[2].w)&&(event.button.y > cells[2].y && event.button.y <cells[2].y+cells[2].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[3].x && event.button.x < cells[3].x+cells[3].w)&&(event.button.y > cells[3].y && event.button.y <cells[3].y+cells[3].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[4].x && event.button.x < cells[4].x+cells[4].w)&&(event.button.y > cells[4].y && event.button.y <cells[4].y+cells[4].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[5].x && event.button.x < cells[5].x+cells[5].w)&&(event.button.y > cells[5].y && event.button.y <cells[5].y+cells[5].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[6].x && event.button.x < cells[6].x+cells[6].w)&&(event.button.y > cells[6].y && event.button.y <cells[6].y+cells[6].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[7].x && event.button.x < cells[7].x+cells[7].w)&&(event.button.y > cells[7].y && event.button.y <cells[7].y+cells[7].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[8].x && event.button.x < cells[8].x+cells[8].w)&&(event.button.y > cells[8].y && event.button.y <cells[8].y+cells[8].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[9].x && event.button.x < cells[9].x+cells[9].w)&&(event.button.y > cells[9].y && event.button.y <cells[9].y+cells[9].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[10].x && event.button.x < cells[10].x+cells[10].w)&&(event.button.y > cells[10].y && event.button.y <cells[10].y+cells[10].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[11].x && event.button.x < cells[11].x+cells[11].w)&&(event.button.y > cells[11].y && event.button.y <cells[11].y+cells[11].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[12].x && event.button.x < cells[12].x+cells[12].w)&&(event.button.y > cells[12].y && event.button.y <cells[12].y+cells[12].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[13].x && event.button.x < cells[13].x+cells[13].w)&&(event.button.y > cells[13].y && event.button.y <cells[13].y+cells[13].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[14].x && event.button.x < cells[14].x+cells[14].w)&&(event.button.y > cells[14].y && event.button.y <cells[14].y+cells[14].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[15].x && event.button.x < cells[15].x+cells[15].w)&&(event.button.y > cells[15].y && event.button.y <cells[15].y+cells[15].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[16].x && event.button.x < cells[16].x+cells[16].w)&&(event.button.y > cells[16].y && event.button.y <cells[16].y+cells[16].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[17].x && event.button.x < cells[17].x+cells[17].w)&&(event.button.y > cells[17].y && event.button.y <cells[17].y+cells[17].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[18].x && event.button.x < cells[18].x+cells[18].w)&&(event.button.y > cells[18].y && event.button.y <cells[18].y+cells[18].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[19].x && event.button.x < cells[19].x+cells[19].w)&&(event.button.y > cells[19].y && event.button.y <cells[19].y+cells[19].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[20].x && event.button.x < cells[20].x+cells[20].w)&&(event.button.y > cells[20].y && event.button.y <cells[20].y+cells[20].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[21].x && event.button.x < cells[21].x+cells[21].w)&&(event.button.y > cells[21].y && event.button.y <cells[21].y+cells[21].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[22].x && event.button.x < cells[22].x+cells[22].w)&&(event.button.y > cells[22].y && event.button.y <cells[22].y+cells[22].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[23].x && event.button.x < cells[23].x+cells[23].w)&&(event.button.y > cells[23].y && event.button.y <cells[23].y+cells[23].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[24].x && event.button.x < cells[24].x+cells[24].w)&&(event.button.y > cells[24].y && event.button.y <cells[24].y+cells[24].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[25].x && event.button.x < cells[25].x+cells[25].w)&&(event.button.y > cells[25].y && event.button.y <cells[25].y+cells[25].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[26].x && event.button.x < cells[26].x+cells[26].w)&&(event.button.y > cells[26].y && event.button.y <cells[26].y+cells[26].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[27].x && event.button.x < cells[27].x+cells[27].w)&&(event.button.y > cells[27].y && event.button.y <cells[27].y+cells[27].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[28].x && event.button.x < cells[28].x+cells[28].w)&&(event.button.y > cells[28].y && event.button.y <cells[28].y+cells[28].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[29].x && event.button.x < cells[29].x+cells[29].w)&&(event.button.y > cells[29].y && event.button.y <cells[29].y+cells[29].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[30].x && event.button.x < cells[30].x+cells[30].w)&&(event.button.y > cells[30].y && event.button.y <cells[30].y+cells[30].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[31].x && event.button.x < cells[31].x+cells[31].w)&&(event.button.y > cells[31].y && event.button.y <cells[31].y+cells[31].h))
                    {
                      table[I][J]=t2;
                      concord[I][J]=2;
                    }
                    else if((event.button.x >cells[32].x && event.button.x < cells[32].x+cells[32].w)&&(event.button.y > cells[32].y && event.button.y <cells[32].y+cells[32].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[33].x && event.button.x < cells[33].x+cells[33].w)&&(event.button.y > cells[33].y && event.button.y <cells[33].y+cells[33].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[34].x && event.button.x < cells[34].x+cells[34].w)&&(event.button.y > cells[34].y && event.button.y <cells[34].y+cells[34].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                    else if((event.button.x >cells[35].x && event.button.x < cells[35].x+cells[35].w)&&(event.button.y > cells[35].y && event.button.y <cells[35].y+cells[35].h))
                    {
                       table[I][J]=t2;
                       concord[I][J]=2;
                    }
                }
                else if(event.button.button == SDL_BUTTON_LEFT && table[I][J] == t2)
                {
                     if((event.button.x >cells[0].x && event.button.x < cells[0].x+cells[0].w)&&(event.button.y > cells[0].y && event.button.y <cells[0].y+cells[0].h))
                    {
                        table[I][J]=t0;
                        concord[I][J]=0;
                    }
                    else if((event.button.x >cells[1].x && event.button.x < cells[1].x+cells[1].w)&&(event.button.y > cells[1].y && event.button.y <cells[1].y+cells[1].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[2].x && event.button.x < cells[2].x+cells[2].w)&&(event.button.y > cells[2].y && event.button.y <cells[2].y+cells[2].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[3].x && event.button.x < cells[3].x+cells[3].w)&&(event.button.y > cells[3].y && event.button.y <cells[3].y+cells[3].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[4].x && event.button.x < cells[4].x+cells[4].w)&&(event.button.y > cells[4].y && event.button.y <cells[4].y+cells[4].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[5].x && event.button.x < cells[5].x+cells[5].w)&&(event.button.y > cells[5].y && event.button.y <cells[5].y+cells[5].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[6].x && event.button.x < cells[6].x+cells[6].w)&&(event.button.y > cells[6].y && event.button.y <cells[6].y+cells[6].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[7].x && event.button.x < cells[7].x+cells[7].w)&&(event.button.y > cells[7].y && event.button.y <cells[7].y+cells[7].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[8].x && event.button.x < cells[8].x+cells[8].w)&&(event.button.y > cells[8].y && event.button.y <cells[8].y+cells[8].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[9].x && event.button.x < cells[9].x+cells[9].w)&&(event.button.y > cells[9].y && event.button.y <cells[9].y+cells[9].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[10].x && event.button.x < cells[10].x+cells[10].w)&&(event.button.y > cells[10].y && event.button.y <cells[10].y+cells[10].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[11].x && event.button.x < cells[11].x+cells[11].w)&&(event.button.y > cells[11].y && event.button.y <cells[11].y+cells[11].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[12].x && event.button.x < cells[12].x+cells[12].w)&&(event.button.y > cells[12].y && event.button.y <cells[12].y+cells[12].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[13].x && event.button.x < cells[13].x+cells[13].w)&&(event.button.y > cells[13].y && event.button.y <cells[13].y+cells[13].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[14].x && event.button.x < cells[14].x+cells[14].w)&&(event.button.y > cells[14].y && event.button.y <cells[14].y+cells[14].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[15].x && event.button.x < cells[15].x+cells[15].w)&&(event.button.y > cells[15].y && event.button.y <cells[15].y+cells[15].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[16].x && event.button.x < cells[16].x+cells[16].w)&&(event.button.y > cells[16].y && event.button.y <cells[16].y+cells[16].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[17].x && event.button.x < cells[17].x+cells[17].w)&&(event.button.y > cells[17].y && event.button.y <cells[17].y+cells[17].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[18].x && event.button.x < cells[18].x+cells[18].w)&&(event.button.y > cells[18].y && event.button.y <cells[18].y+cells[18].h))
                    {
                      table[I][J]=t0;
                      concord[I][J]=0;
                    }
                    else if((event.button.x >cells[19].x && event.button.x < cells[19].x+cells[19].w)&&(event.button.y > cells[19].y && event.button.y <cells[19].y+cells[19].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[20].x && event.button.x < cells[20].x+cells[20].w)&&(event.button.y > cells[20].y && event.button.y <cells[20].y+cells[20].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[21].x && event.button.x < cells[21].x+cells[21].w)&&(event.button.y > cells[21].y && event.button.y <cells[21].y+cells[21].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[22].x && event.button.x < cells[22].x+cells[22].w)&&(event.button.y > cells[22].y && event.button.y <cells[22].y+cells[22].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[23].x && event.button.x < cells[23].x+cells[23].w)&&(event.button.y > cells[23].y && event.button.y <cells[23].y+cells[23].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[24].x && event.button.x < cells[24].x+cells[24].w)&&(event.button.y > cells[24].y && event.button.y <cells[24].y+cells[24].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[25].x && event.button.x < cells[25].x+cells[25].w)&&(event.button.y > cells[25].y && event.button.y <cells[25].y+cells[25].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[26].x && event.button.x < cells[26].x+cells[26].w)&&(event.button.y > cells[26].y && event.button.y <cells[26].y+cells[26].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[27].x && event.button.x < cells[27].x+cells[27].w)&&(event.button.y > cells[27].y && event.button.y <cells[27].y+cells[27].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[28].x && event.button.x < cells[28].x+cells[28].w)&&(event.button.y > cells[28].y && event.button.y <cells[28].y+cells[28].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[29].x && event.button.x < cells[29].x+cells[29].w)&&(event.button.y > cells[29].y && event.button.y <cells[29].y+cells[29].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[30].x && event.button.x < cells[30].x+cells[30].w)&&(event.button.y > cells[30].y && event.button.y <cells[30].y+cells[30].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[31].x && event.button.x < cells[31].x+cells[31].w)&&(event.button.y > cells[31].y && event.button.y <cells[31].y+cells[31].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[32].x && event.button.x < cells[32].x+cells[32].w)&&(event.button.y > cells[32].y && event.button.y <cells[32].y+cells[32].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[33].x && event.button.x < cells[33].x+cells[33].w)&&(event.button.y > cells[33].y && event.button.y <cells[33].y+cells[33].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[34].x && event.button.x < cells[34].x+cells[34].w)&&(event.button.y > cells[34].y && event.button.y <cells[34].y+cells[34].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                    else if((event.button.x >cells[35].x && event.button.x < cells[35].x+cells[35].w)&&(event.button.y > cells[35].y && event.button.y <cells[35].y+cells[35].h))
                    {
                       table[I][J]=t0;
                       concord[I][J]=0;
                    }
                }
            }
        }


if(now < 5000)
    {
        randA = rand()%75;
    }
else if(now >= 5000 && now < 15000)
    {
        randA = rand()%45;
    }
else if(now >= 15000 && now < 35000)
    {
        randA = rand()%35;
    }
else if(now >= 35000)
    {
        randA = rand()%20;
    }
if(randA<10){
randI = rand()%6;
randJ = rand()%6;

if(concordComp[randI][randJ]!= sol[randI][randJ]){




        concordComp[randI][randJ] = rand()%2 +1;
        if(concordComp[randI][randJ] == 1){

            table2[randI][randJ] = t1;
        } else if(concordComp[randI][randJ] == 2){

            table2[randI][randJ] = t2;
        }



}
}

//if(now-before<delta)
	//SDL_Delay(delta-(now-before));



     e=0;
     for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
           Blit(renderer,table[i][j],cells[e]);
           Blit(renderer,table2[i][j],cells2[e]);
           e++;
        }

    }








                 //drawing the points
                draw_Model(points,renderer,grid);
                draw_Model(points2,renderer,grid);
                 //draw settings
                 Draw_Settings2(renderer);

// Show what was drawn
                SDL_RenderPresent(renderer);


    //before=now;


if(jeuFin(sol)==0){
tfinal = now;
running = false;
} else if (jeuFinOrdi(sol)==0){
tfinal = now;
running = false;
}


}

    SDL_DestroyTexture(t);
    SDL_DestroyTexture(t0);
    SDL_DestroyTexture(t1);
    SDL_DestroyTexture(t2);
if(jeuFinOrdi(sol)==0)
{

SDL_RenderPresent(renderer);
SDL_Delay(500);
youLose(renderer, window);
SDL_Delay(4000);
}
else if(jeuFin(sol)==0)
{
   youWin2(renderer, window, tfinale);
   SDL_RenderPresent(renderer);
   scoreBoard(renderer, Name, tfinale);
   scoreboardDisplay(renderer, fp);
   SDL_Delay(4000);
}



if(tquit == 0){
        IMG_Quit();
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);


    SDL_Quit();

}

}
