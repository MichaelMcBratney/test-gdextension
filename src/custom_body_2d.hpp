#pragma once

#include <godot_cpp/classes/character_body2d.hpp>

using namespace godot;

    class CustomBody2D : public CharacterBody2D {
        GDCLASS(CustomBody2D, CharacterBody2D)

    private:
        double speed;

    protected:
        static void _bind_methods();

    public:
        CustomBody2D();
        ~CustomBody2D();

        void precise_move_and_slide(Vector2 destination_position, double delta);

        void set_speed(const double p_speed);
        double get_speed() const;
    };
