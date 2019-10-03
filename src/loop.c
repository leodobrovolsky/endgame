#include "endgame.h"

void loop(SDL_Renderer *rend, obj *all_objects[], int obj_num, SDL_Texture** texbkground,
        SDL_Texture* texmainship, SDL_Texture** texenemy, SDL_Texture** texasteroid,
        SDL_Texture** texexplosion, SDL_Texture** texbullet, int *obj_count)

    {
        
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

    int menu = 0;
    double enemy_time = (double) clock();

    while (!is_quit()) {


    	// рендер бэкграунда
        SDL_RenderCopy(rend, texbkground[1], NULL, NULL);
        // write(1, "p2\n",4);
        keyboard_move_read(all_objects[0]); // чтение управления нашим кораблем с клавиатуры
        border_of_move(all_objects[0]); // ограничение движения корабля по периметру окна
        obj_overwrite(all_objects, obj_num, obj_count, enemy_time); // генерация врагов и астероидов
        // write(1, "p3\n",4);


        // создание пули врагов
        for (int i = 1; i < obj_num; i++) {
            
            if (all_objects[i] -> clas == 1 && is_obj_at_map(all_objects[i])) // если враг на видимой части карты
                if (get_obj_delay(all_objects[i]) > get_std_delay(all_objects[i])) {
                    set_obj_timer(all_objects[i]);
                    deploy_bullet(all_objects[i], all_objects[*obj_count], obj_count);
                }
        }
        // write(1, "p4\n",4);
        // создание пули нами
        if(keyboardState[SDL_SCANCODE_SPACE])
            if (get_obj_delay(all_objects[0]) > get_std_delay(all_objects[0])) {
                set_obj_timer(all_objects[0]);
                deploy_bullet(all_objects[0], all_objects[*obj_count], obj_count);
            }

        /*mx_printchar('>');
        for (int i = 0; i < obj_num; i++){
            //mx_printint(*obj_count);
            mx_printint(all_objects[i] -> present);
            mx_printchar(' ');

        }
            mx_printchar('\n');*/



        // write(1, "p5\n",4);
        // Определение угла врагов и ракет
        for (int i = 1; i < obj_num; i++){
            set_direction_enemy(all_objects[i], all_objects[0]);
            set_direction_rocket(all_objects[i], all_objects[0]);
        }


        if(all_objects[0] -> direction > 360)
                all_objects[0] -> direction %= 360;
            if(all_objects[0] -> direction < 0)
                all_objects[0] -> direction = 360 - all_objects[0] -> direction;

            

        // write(1, "p6\n",4);
        //  движение объектов
        for (int i = 1; i < obj_num; i++) {
            move_obj(all_objects[i]);
        }

        // write(1, "p7\n",4);
        collisions(obj_num, all_objects, obj_count); // проверка объектов на столкновения, их уничтожение

        for (int i = 1; i < obj_num; i++)
            border_destroy(all_objects[i]);





        






        
for(int i = 1; i < *obj_count; i++)
           if((all_objects[i] -> present == 0) && (all_objects[i] -> clas == 1 || all_objects[i] -> clas == 2)){
               all_objects[i] -> present = -23;
           }
       for (int i = 0; i < *obj_count; i++)
           if (all_objects[i] -> present < 0){
               all_objects[i] -> present++;
               SDL_RenderCopy(rend, texexplosion[all_objects[i] -> present + 23], NULL, all_objects[i] -> rect);
           }
       // write(1, “p8\n”,4);
       array_zip(all_objects, obj_count); // смещение массива объектов влево, убирая все 0 объекты вправо
       //write(1, “p9\n”,4);
       if (is_mainship_destroy(all_objects[0]))
           menu = 2;


        
        // изменение угла текстуры корабля при повороте лево/право
        SDL_RenderCopyEx(rend, texmainship, NULL, all_objects[0] -> rect, all_objects[0] -> direction, NULL, SDL_FLIP_NONE);
        //write(1, "p11\n",4);
for(int i = 1; i < *obj_count; i++) {
          if (all_objects[i] -> present > 0) {
           if(all_objects[i] -> clas == 1 && all_objects[i] -> type == 0)
               SDL_RenderCopyEx(rend, texenemy[2], NULL, all_objects[i] -> rect, all_objects[i] -> direction, NULL, SDL_FLIP_NONE);
           if(all_objects[i] -> clas == 1 && all_objects[i] -> type == 1)
               SDL_RenderCopyEx(rend, texenemy[3], NULL, all_objects[i] -> rect, all_objects[i] -> direction, NULL, SDL_FLIP_NONE);
           if(all_objects[i] -> clas == 1 && all_objects[i] -> type == 2)
               SDL_RenderCopyEx(rend, texenemy[5], NULL, all_objects[i] -> rect, all_objects[i] -> direction, NULL, SDL_FLIP_NONE);
           if(all_objects[i] -> clas == 1 && all_objects[i] -> type == 3)
               SDL_RenderCopyEx(rend, texenemy[4], NULL, all_objects[i] -> rect, all_objects[i] -> direction, NULL, SDL_FLIP_NONE);
           if(all_objects[i] -> clas == 2)
               SDL_RenderCopyEx(rend, texasteroid[0], NULL, all_objects[i] -> rect, all_objects[i] -> direction, NULL, SDL_FLIP_NONE);
           if(all_objects[i] -> clas == 3 && all_objects[i] -> type == 1)
               SDL_RenderCopyEx(rend, texbullet[0], NULL, all_objects[i] -> rect, all_objects[i] -> direction, NULL, SDL_FLIP_NONE);
           if(all_objects[i] -> clas == 3 && all_objects[i] -> type == 2)
               SDL_RenderCopyEx(rend, texbullet[3], NULL, all_objects[i] -> rect, all_objects[i] -> direction, NULL, SDL_FLIP_NONE);
           if(all_objects[i] -> clas == 3 && all_objects[i] -> type == 3)
               SDL_RenderCopyEx(rend, texbullet[2], NULL, all_objects[i] -> rect, all_objects[i] -> direction, NULL, SDL_FLIP_NONE);
         }
       }
        //write(1, "p12\n",4);
        SDL_RenderPresent(rend); // рендерим всё в конце цикла
        SDL_Delay(1000 / 60); // задержка 1/60 секунды
        //write(1, "p13\n",4);
    }

}

