#include "endgame.h"

// чтение управления нашим кораблем с клавиатуры
void keyboard_move_read(obj *mainship) {
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

	// влево/вправо
    if((keyboardState[SDL_SCANCODE_LEFT]) || (keyboardState[SDL_SCANCODE_A]))
        mainship -> direction -= mainship -> rotate_speed;
    if((keyboardState[SDL_SCANCODE_RIGHT]) || (keyboardState[SDL_SCANCODE_D]))
        mainship -> direction += mainship -> rotate_speed;

    // вперед/назад
    if((keyboardState[SDL_SCANCODE_DOWN]) || (keyboardState[SDL_SCANCODE_S]))
        move_hero_down(mainship);
    if((keyboardState[SDL_SCANCODE_UP]) || (keyboardState[SDL_SCANCODE_W]))
        move_hero_up(mainship);
}

