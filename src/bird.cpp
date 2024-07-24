#include "birds_and_pipes.hpp"
#include "bird.hpp"

Bird::Bird(const sf::Texture &bird_txtr)
    : y {Bird::init_y}, 
    speed {Bird::init_speed}, 
    dim {bird_txtr.getSize()},
    y_range {sf::Vector2f(MainWindow::win_top+bird_txtr.getSize().y, MainWindow::win_height-bird_txtr.getSize().y)},
    normal_y_range {y_range.x, y_range.y}
{
    setTexture(bird_txtr);                   // init sprite
    setPosition(Bird::init_x, Bird::init_y);
}

sf::Vector2f Bird::get_pos() const {return sf::Vector2f(Bird::init_x, y);}
sf::Vector2f Bird::get_dim() const {return dim;}
float Bird::get_y() const {return y;}
float Bird::width() const {return dim.x;}
float Bird::height() const {return dim.y;}

void Bird::set_y_range(sf::Vector2f y_range_arg) {y_range = y_range_arg;}
void Bird::set_normal_y_range() {y_range = normal_y_range;}


void Bird::set_fly(bool val) {fly = val;}

void Bird::set_speed(float sp) {speed = sp;}

void Bird::update_pos(){
    if (fly && y-speed > y_range.x)
        y -= speed;
    else if (!fly && y+speed < y_range.y)
        y += speed;
    setPosition(Bird::init_x, y);
}
