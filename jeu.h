#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


SDL_Texture *initialize_texture_from_file(const char* file_name, SDL_Renderer *renderer);
SDL_Texture *initialize_texture_from_TTF(const char* name, SDL_Renderer *renderer);
void grillEtSoluce(int soluce[6][6], int grille[7][7]);
void Blit(SDL_Renderer *renderer, SDL_Texture *texture,SDL_Rect dest);
void Draw_Game(SDL_Renderer *renderer,SDL_Rect points[49],SDL_Rect cells[36]);
int Icon(SDL_Window *window);
void Draw_Timer(SDL_Renderer *renderer, int tiempo);
int Draw_Settings(SDL_Renderer * renderer);
void draw_Model(SDL_Rect points[49],SDL_Renderer * renderer, int grid[7][7]);
void jeu(SDL_Renderer *renderer,SDL_Window * window, int grid[7][7], int sol[6][6], int mod);
void jeuOrdi(SDL_Renderer *renderer,SDL_Window * window, int grid[7][7], int sol[6][6], int mod);
void menu(SDL_Renderer*renderer);
void gameMode(SDL_Renderer*renderer);
void pauseMode(SDL_Renderer*renderer);
int jeuFin(int soluce[6][6]);
void drawReturn (SDL_Renderer * renderer);
int loadGame(FILE *f, int Gmode);
void scoreBoard(SDL_Renderer*renderer, char *n, unsigned tf);
void youWin(SDL_Renderer*renderer, unsigned time);
void scoreboardDisplay(SDL_Renderer*renderer, FILE * f);
void Displayer(SDL_Renderer*renderer, char * str);
void Draw_comps(SDL_Renderer *renderer,SDL_Window *window,SDL_Rect points[49],SDL_Rect cells[36],SDL_Rect cells2[36],SDL_Rect points2[49]);
void compvsplayer(SDL_Renderer *renderer,SDL_Window * window, int grid[7][7], int sol[6][6], int mod);
void saveGame(int savet, int conc[6][6], int concCo[6][6], int s[6][6], int g[7][7], FILE *f, int a, int Gmode);
void Draw_Timer2(SDL_Renderer *renderer, int tiempo);
int Draw_Settings2(SDL_Renderer * renderer);
void youWin2(SDL_Renderer*renderer, SDL_Window * window, unsigned tfinale);
void youLose(SDL_Renderer *renderer,SDL_Window *window);
int jeuFinOrdi(int soluce[6][6]);
void errorSave(SDL_Renderer*renderer);
void compFin(SDL_Renderer*renderer, unsigned time);
void saveOrCont(SDL_Renderer*renderer);



#endif // JEU_H_INCLUDED
