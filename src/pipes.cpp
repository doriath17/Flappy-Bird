#include "birds_and_pipes.hpp"
#include "pipes.hpp"

/*
 *         |----|
 *         |    |
 *         |    |
 *         |    |
 *  pos ---------------
 *   |                |
 *   ------------------
 *
*/

constexpr float x_offset_pipe = (Pipe::head_width - Pipe::pipe_width) / 2;

/*
 * setup_head and setup_height set the size and posizion of head and pipe 
 * relative to the current value of the instance variable pos.
 *
*/

inline void Pipe::setup_head()
{
    head.setSize(sf::Vector2f(Pipe::head_width, Pipe::head_height));
    head.setPosition(pos);
    head.setFillColor(c1);
}

inline void Pipe::setup_pipe()
{
    switch (dir) {
        case PipeDir::up:
            pipe.setSize(sf::Vector2f(Pipe::pipe_width, MainWindow::win_height - pos.y - Pipe::head_height));
            pipe.setPosition(sf::Vector2f(pos.x + x_offset_pipe, pos.y + Pipe::head_height));
            break;
        case PipeDir::down:
            pipe.setSize(sf::Vector2f(Pipe::pipe_width, pos.y));
            pipe.setPosition(sf::Vector2f(pos.x + x_offset_pipe, MainWindow::win_top));
            break;
    }
    pipe.setFillColor(sf::Color::Red);
}

Pipe::Pipe(sf::Vector2f pos, PipeDir dir)
    : pos {pos},
    head {sf::Vector2f(Pipe::head_width, Pipe::head_height)},
    dir {dir},
    c1 {sf::Color::Green}
{
    setup_head();
    setup_pipe();
}


void Pipe::draw(sf::RenderWindow *window)
{
    window->draw(head);
    window->draw(pipe);
}

