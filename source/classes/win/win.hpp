#ifndef WIN_HPP
#define WIN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;




class win{
private:
int heigth,length;
vector<sf::Vector2i> vec;
public:
    win();
    void start();
};


#endif