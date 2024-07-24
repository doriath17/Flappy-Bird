#ifndef BIRDS_HPP 
#define BIRDS_HPP 

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Bird: public sf::Sprite {
public:
    static float constexpr init_x = 10.0f, init_y = 360.0f, init_speed = 4.0f;

    Bird(const sf::Texture &txtr);
    ~Bird() {}

    sf::Vector2f get_pos() const;
    sf::Vector2f get_dim() const;
    float get_y() const;
    float width() const;
    float height() const;
    
    void set_y_range(sf::Vector2f y_range);
    void set_normal_y_range();
    void set_fly(bool val);
    void set_speed(float sp);
    void update_pos();

private:
    //  fly=false -> gravity (no fly so the bird falls down)
    //  fly=true  -> go up (actually fly and the bird goes up)
    bool fly {false};      

    float y, speed;
    sf::Vector2f dim, y_range, normal_y_range;      
    // y_range.x = min_y; y_range.y = max_y;  
    // dim.x = width, dim.y = height
};

#endif /* BIRDS_HPP */