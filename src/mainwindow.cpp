#include "birds_and_pipes.hpp"

const char bg_png_path[] = "bin/assets/png/background1.png";

MainWindow::MainWindow(std::string title, const TxtrRecord &txtr_record) 
    :sf::RenderWindow{sf::VideoMode(480, 720), title}, 
    bird {txtr_record.bird_txtr},
    p1 {sf::Vector2f(240, 360), PipeDir::down}
{
    setKeyRepeatEnabled(false);
    setFramerateLimit(60);
    wbg_sprt.setTexture(txtr_record.wbg_txtr);
}

void MainWindow::event_loop(){
    sf::Event event;
    while (pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.scancode == sf::Keyboard::Scancode::Escape)
                    close();
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    bird.set_fly(true);
                break;
            case sf::Event::KeyReleased:
                if (event.key.scancode == sf::Keyboard::Scancode::Space)
                    bird.set_fly(false);
                break;
            default:
                break;
        }
    }
}

void MainWindow::window_loop()
{
    while (isOpen()) {
        event_loop();

        bird.update_pos();
        clear();

        // window.draw(sprite);
        draw(wbg_sprt);
        draw(bird);
        p1.draw(this);

        display();
    }
}

