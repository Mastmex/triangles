#ifndef WIN_HPP
#define WIN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "./../cfg/cfg.hpp"


using namespace std;




class win{
private:
cfg *cf;
vector<sf::Vector2i> vec;
public:
    win();
    void start();
};


#endif