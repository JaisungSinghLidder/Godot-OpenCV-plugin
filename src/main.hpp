#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class Main : public Node {
    GDCLASS(Main, Node)

private:
    Main();
    ~Main();
    static void _bind_methods();
};
