#ifndef PIPES_HPP 
#define PIPES_HPP

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/* A pipe has a direction:
    up      from the bottom to the top of the window;
    down    form top to bottom of the window
*/
enum class PipeDir {up, down};

class Pipe {
public: 
    static constexpr float init_speed = -2.0f;
    static constexpr float head_height = 40.0f, head_width = 100.0f,  pipe_width = 40.0f;
    static constexpr float speed_increment = -1.0f;

    Pipe(sf::Vector2f pos, PipeDir dir);
    ~Pipe() {}

    void draw(sf::RenderWindow *window);
private: 
    sf::Vector2f pos;
    sf::RectangleShape pipe, head;

    PipeDir dir;
    sf::Color c1;

    inline void setup_head();
    inline void setup_pipe();
};

#endif /* PIPES_HPP */