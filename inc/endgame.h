#ifndef MYHEADERS_H
#define MYHEADERS_H

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <fcntl.h>
#include <math.h>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_mixer/SDL_mixer.h"

#define MAX_SND_CHANNELS 10

static const char *BLAST1 = "textures/sound/blast1.mp3";

typedef struct s_obj{
    int x;
    int y;
    int direction; // Направление. 0 - 360 вправо
    int radius; //радиус объекта
    int review; //радиус обзора
    int size;//размер объекта
    int speed; // текущая скорость
    int max_speed; //максимальная скорость
    int rotate_speed; // градусов на секунду
    int clas; // астероид, враг, пуля
    int type; //тип объекта: враг, астероид, пуля
    int weapon_type; //тип оружия
    int health; //шкала здоровья
    int armor; //броня
    int damage; //количество урона
    int award; //награда за уничтожение
	int present; //проверка на существование на карте
	int level; //уровень объекта
	clock_t obj_timer;
    SDL_Rect *rect; //положение объекта на окне
} obj;

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT  1080
#define Pi  3.14159265359

void array_zip(obj *objects[], int *obj_count);
int award_choose(int clas, int type, int level);
void border_of_move(obj *mainship);
void collisions(int obj_num, obj *objects[], int *obj_count);
void create_asteroid(obj *asteroid, int x, int y, int direction, int size, int level, int *obj_count);
void create_bullet(obj *bullet, int x, int y, int direction, int type, int level, int *obj_count);
void create_enemy(obj *object, int x, int y, int size, int type, int level, int *obj_count);
void create_hero(obj *object, int x, int y, int level, int *obj_count);
void create_obj(obj *object, int x, int y, int size, int clas, int type, int level, int *obj_count);
void create_rect(SDL_Rect *rect, int x, int y, int w, int h);
int damage_choose(int clas, int type, int level);
void deploy_bullet(obj *object, obj *bullet, int *obj_count);
void border_destroy(obj *object);
int get_obj_delay(obj *object);
int get_std_delay(obj *object);
int h_from_size(obj *object);
int health_choose(int clas, int type, int level);
obj *init_obj();
SDL_Rect *init_rect();
int is_mainship_destroy(obj *mainship);
int is_obj_at_map(obj *object);
int is_quit();
void keyboard_move_read(obj *mainship);
void loop(SDL_Renderer *rend, obj *all_objects[], int obj_num, SDL_Texture** texbkground,
        SDL_Texture* texmainship, SDL_Texture** texenemy, SDL_Texture** texasteroid,
        SDL_Texture** texexplosion, SDL_Texture** texbullet, int *obj_count);
int main ();
void move_hero_down(obj *object);
void move_hero_up(obj *object);
void move_obj (obj *object);
int move_x(obj *object);
int move_y(obj *object);
int mx_actan(double ratio);
int mx_atan(double ratio);
double mx_cos(int degree);
double mx_ctan(int degree);
double mx_sin(int degree);
SDL_Surface** mx_skin_asteroid(void);
SDL_Surface** mx_skin_bkground(void);
SDL_Surface** mx_skin_bullet(void);
SDL_Surface** mx_skin_explosion(void);
SDL_Surface** mx_skin_ships(void);
double mx_tan(int degree);
void obj_overwrite(obj **object, int obj_num, int *obj_count, double enemy_time);
int radius_from_size(obj *object);
int review_from_radius(int radius);
int rotate_speed_choose(int clas, int type);
void set_direction_enemy(obj *p_obj, obj *p_me);
void set_direction_rocket(obj *p_obj, obj *p_me);
void set_obj_timer(obj *object);
int speed_choose(int clas, int type);
int w_from_size(obj *object);
int weapon_choose(int clas, int type);
void xy_obj_rect_sync (obj *object);

int collision_check(int x1, int y1, int r1, int x2, int y2, int r2);

void mx_printchar(char c);
void mx_printint(int n);

void collision_asteroids(obj *obj1, obj *obj2);

void loadSounds(void);
void initSounds(void);
void loadMusic(char *filename);
void playMusic(int loop);
void playSound(int id, int channel);



#endif

