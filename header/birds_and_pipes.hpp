#ifndef BIRDS_AND_PIPES_HPP
#define BIRDS_AND_PIPES_HPP

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "bird.hpp"
#include "pipes.hpp"


class TxtrRecord {
public: 
    TxtrRecord();
    ~TxtrRecord() {};

    sf::Texture wbg_txtr;       // window background texture
    sf::Texture bird_txtr;
    sf::Texture pipe_txtr;
};

class MainWindow: public sf::RenderWindow {
public:
    static constexpr float win_top = 0.0f, win_height = 720.0f, win_width = 480;

    MainWindow(std::string, const TxtrRecord &);
    ~MainWindow() {};

    void event_loop();
    void window_loop();

private:
    sf::Sprite  wbg_sprt;       // window background sprite
    Bird bird;
    Pipe p1;
};

#endif /* BIRDS_AND_PIPES_HPP */