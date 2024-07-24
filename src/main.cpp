#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "birds_and_pipes.hpp"

int main(){
    TxtrRecord txtr_record;
    MainWindow window {"Flappy Birds", txtr_record};

    window.window_loop();

    return 0;
}
