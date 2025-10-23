#include "custom_body_2d.hpp"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

CustomBody2D::CustomBody2D() {
    speed = 300.0;
}

CustomBody2D::~CustomBody2D() {
}

void CustomBody2D::precise_move_and_slide(Vector2 destination_position, double delta) {
    Vector2 current_position = get_position();
    Vector2 direction_vector = destination_position - current_position;
    Vector2 motion_vector;

    if (std::abs(direction_vector.x) > std::abs(direction_vector.y)) {
        motion_vector = Vector2(direction_vector.x, 0);
    }
    else {
        motion_vector = Vector2(0, direction_vector.y);
    }

    double distance_to_go = motion_vector.length();


    if (distance_to_go < 1.0) { 
        set_velocity(Vector2(0, 0));
    }
    else {
        double potential_travel_distance = speed * delta;
        if (potential_travel_distance >= distance_to_go) {
            set_velocity(motion_vector / delta);
        }
        else {
            set_velocity(motion_vector.normalized() * speed);
        }
    }
    move_and_slide();
}

void CustomBody2D::_bind_methods() {
    ClassDB::bind_method(D_METHOD("precise_move_and_slide", "destination_position", "delta"), &CustomBody2D::precise_move_and_slide);
    ClassDB::bind_method(D_METHOD("get_speed"), &CustomBody2D::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &CustomBody2D::set_speed);
    ClassDB::add_property("CustomBody2D", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

void CustomBody2D::set_speed(const double p_speed) {
    speed = p_speed;
}

double CustomBody2D::get_speed() const {
    return speed;
}
