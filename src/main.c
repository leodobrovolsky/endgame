#include "endgame.h"

enum
{
    CH_ANY = -1, // enemie_DIE
    CH_HERO,
    CH_ENEMIE_FIRE,
};

enum
{
    SND_HERO_GUN,
    SND_ENEMIE_GUN,
    SND_HERO_DIE,
    SND_ENEMIE_DIE,
   SND_GET_READY,
   SND_GAME_SOUND,
   SND_GAME_OVER,
    SND_MAX
};


static Mix_Chunk *sounds[SND_MAX];
static Mix_Music *music;

void loadSounds(void)
{
   sounds[SND_HERO_GUN] = Mix_LoadWAV("sound/blast1.mp3");
 
}

void initSounds(void)
{
    memset(sounds, 0, sizeof(Mix_Chunk*) * SND_MAX);
    
    music = NULL;
    
    loadSounds();
}
void loadMusic(char *filename)
{
    if (music != NULL)
    {
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = NULL;
    }
    music = Mix_LoadMUS(filename);
}

void playMusic(int loop)
{
    Mix_PlayMusic(music, (loop) ? -1 : 0);
}
void playSound(int id, int channel)
{
    Mix_PlayChannel(channel, sounds[id], 0);
}


int main () {
    // инициализация библиотеки SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    if(Mix_OpenAudio(10000, MIX_DEFAULT_FORMAT, 2, 1024) == -1) // the frequency, format, channels, and chunkSize.
        {
            printf("Couldn't initialize SDL Mixer\n");
            exit(1);
        }
    Mix_AllocateChannels(MAX_SND_CHANNELS); //We now play 10 sound effects at the same time.
    initSounds();
    loadMusic("sound/space.mp3");
    playMusic(-1); // allows music to loop

    // подключение клавиатуры
    //const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

    srand ( time(NULL) ); 

    // инициализация переменных текстур
    SDL_Texture** texbkground = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 4);
    SDL_Texture* texmainship;
    SDL_Texture** texenemy = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 7);
    SDL_Texture** texasteroid = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 9);
    SDL_Texture** texexplosion = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 25);
    SDL_Texture** texbullet = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 3);

    SDL_Surface** surfbkground = mx_skin_bkground();
    SDL_Surface** surfship = mx_skin_ships();
    SDL_Surface** surfasteroid = mx_skin_asteroid();
    SDL_Surface** surfexplosion = mx_skin_explosion();
    SDL_Surface** surfbullet = mx_skin_bullet();

    
    // создание массива всех объектов
    int obj_num = 500;
    obj *all_objects[500];
    for (int i = 0; i < obj_num; i++) {
        all_objects[i] = init_obj();
    }
    int obj_count = 0;
    create_hero(all_objects[0], WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 1, &obj_count);

    // создание окна
    SDL_Window *win = SDL_CreateWindow("endgame", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    // ошибка, если окно не создалось
    if (!win) {    
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // создание рендера
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend) {
        printf("error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }









    
    // подгрузка текстур объектов
       texmainship = SDL_CreateTextureFromSurface(rend, surfship[0]);
   for(int i =0; i < 4; i++)
       texbkground[i] = SDL_CreateTextureFromSurface(rend, surfbkground[i]);
       SDL_FreeSurface(*surfbkground);
   for(int i =0; i < 7; i++)
       texenemy[i] = SDL_CreateTextureFromSurface(rend, surfship[i]);
       SDL_FreeSurface(*surfship);
   for(int i =0; i < 9; i++)
       texasteroid[i] = SDL_CreateTextureFromSurface(rend, surfasteroid[i]);
       SDL_FreeSurface(*surfasteroid);
   for(int i =0; i < 3; i++)
       texbullet[i] = SDL_CreateTextureFromSurface(rend, surfbullet[i]);
       SDL_FreeSurface(*surfbullet);
   // подгрузка текстур взрыва (25 кадров)
   for(int i =0; i < 24; i++)
       texexplosion[i] = SDL_CreateTextureFromSurface(rend, surfexplosion[i]);
       SDL_FreeSurface(*surfexplosion);





    //write(1, "p1\n",4);

//-----------------------------------------------------------------------
    loop(rend, all_objects, obj_num, texbkground, texmainship, texenemy,
        texasteroid, texexplosion, texbullet, &obj_count); // цикл анализа и отрисовки
//-----------------------------------------------------------------------



    //удаление objects
   for (int i = 0; i < obj_num; i++)
       free(all_objects[i]);
       //free(all_objects);
   //удаление подгруженых текстур
   SDL_DestroyTexture(texmainship);
   SDL_DestroyTexture(*texenemy);
   SDL_DestroyTexture(*texbkground);
   SDL_DestroyTexture(*texasteroid);
   SDL_DestroyTexture(*texbullet);
   SDL_DestroyTexture(*texexplosion);

    Mix_FreeMusic(music);

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}

