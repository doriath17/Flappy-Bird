#include "birds_and_pipes.hpp"

const char wbg_txtr_file[]  = "bin/assets/png/background1.png";
const char bird_txtr_file[] = "bin/assets/png/bird1.png";
// const char pipe_txtr_file[] = 


TxtrRecord::TxtrRecord()
{
    if (!wbg_txtr.loadFromFile(wbg_txtr_file))
        std::cout << "Error in loading background texture.\n";
    if (!bird_txtr.loadFromFile(bird_txtr_file))
        std::cout << "Error loading bird texture.\n";
    // if (!bird_txtr.loadFromFile(bird_txtr_file))
    //     std::cout << "Error loading bird texture.\n";
}