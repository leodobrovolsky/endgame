NAME = endgame

INC = inc/endgame.h

SRC = src/array_zip.c src/award_choose.c src/border_destroy.c src/border_of_move.c src/collision_asteroids.c src/collisions.c src/create_asteroid.c src/create_bullet.c src/create_enemy.c src/create_hero.c src/create_obj.c src/create_rect.c src/damage_choose.c src/deploy_bullet.c src/get_obj_delay.c src/get_std_delay.c src/h_from_size.c src/health_choose.c src/init_obj.c src/init_rect.c src/is_mainship_destroy_c.c src/is_obj_at_map.c src/is_quit.c src/keyboard_move_read.c src/loop.c src/main.c src/move_hero_down.c src/move_hero_up.c src/move_obj.c src/move_x.c src/move_y.c src/mx_actan.c src/mx_atan.c src/mx_cos.c src/mx_ctan.c src/mx_sin.c src/mx_skin_asteroid.c src/mx_skin_bkground.c src/mx_skin_bullet.c src/mx_skin_explosion.c src/mx_skin_ships.c src/mx_tan.c src/obj_overwrite.c src/radius_from_size.c src/review_from_radius.c src/rotate_speed_choose.c src/set_direction_enemy.c src/set_direction_rocket.c src/set_obj_timer.c src/speed_choose.c src/w_from_size.c src/weapon_choose.c src/xy_obj_rect_sync.c

SRCS = array_zip.c award_choose.c border_destroy.c border_of_move.c collision_asteroids.c collisions.c create_asteroid.c create_bullet.c create_enemy.c create_hero.c create_obj.c create_rect.c damage_choose.c deploy_bullet.c get_obj_delay.c get_std_delay.c h_from_size.c health_choose.c init_obj.c init_rect.c is_mainship_destroy_c.c is_obj_at_map.c is_quit.c keyboard_move_read.c loop.c main.c move_hero_down.c move_hero_up.c move_obj.c move_x.c move_y.c mx_actan.c mx_atan.c mx_cos.c mx_ctan.c mx_sin.c mx_skin_asteroid.c mx_skin_bkground.c mx_skin_bullet.c mx_skin_explosion.c mx_skin_ships.c mx_tan.c obj_overwrite.c radius_from_size.c review_from_radius.c rotate_speed_choose.c set_direction_enemy.c set_direction_rocket.c set_obj_timer.c speed_choose.c w_from_size.c weapon_choose.c xy_obj_rect_sync.c

SDLF =  -I ./framework/SDL2.framework/Versions/A/Headers -F ./framework -framework SDL2 -rpath ./framework -I ./framework/SDL2_image.framework/Versions/A/Headers -F ./framework -framework SDL2_image -rpath ./framework 

SDLM = -I ./framework/SDL2_mixer.framework/Versions/A/Headers -F ./framework -framework SDL2_mixer -rpath ./framework

SDLT = -I ./framework/SDL2_ttf.framework/Versions/A/Headers -F ./framework -framework SDL2_ttf -rpath ./framework

CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@cp $(SRC) .
	
	@cp $(INC) .
	@clang $(CFLAG) $(SDLM) $(SRCS) $(SDLF) $(SDLT) -o $(NAME) -I $(INC)
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(SRCS)
	@rm -rf endgame.h
reinstall: uninstall all
