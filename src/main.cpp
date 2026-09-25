#include <bn_backdrop.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>

#include "bn_sprite_items_bun.h"

#define FLOOR (80 - 8)

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(20, 0, 10));

    auto dot = bn::sprite_items::bun.create_sprite(0, 0);

    bn::fixed speed = 2.5;

    bn::fixed dy = 0;
    bn::fixed gravity = .03;

    bn::fixed jump_strength = 1.3;

    int minimum_x = -110;
    int maximum_x = 110;
    int minimum_y = -80;

    while(true) {
        if(bn::keypad::left_held()) {
            dot.set_x(dot.x() - speed);
        }
        if(bn::keypad::right_held()) {
            dot.set_x(dot.x() + speed);
        }
        if(bn::keypad::a_pressed()) {
            dy -= jump_strength;
        }

        dy += gravity;

        dot.set_y(dot.y() + dy);

        if(dot.y() > FLOOR) {
            dot.set_y(FLOOR);
            dy = 0;
        }
        bn::core::update();

        if(dot.x() > maximum_x){
            //horizontal boundary right
            dot.set_x(maximum_x);
        }

        if(dot.x() < minimum_x){
            //horizontal boundary left
            dot.set_x(minimum_x);
        }

        if(dot.y() < minimum_y){
            //vertical boundary up
            dot.set_y(minimum_y);
            dy = 0;
        }
    }
}