#ifndef TRI_HPP
#define TRI_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>


using namespace std;



class tri{
private:
    vector<sf::Vector2i*> possible_triangles;
    vector<sf::Vector2i> all_dots;
public:
    void draw(sf::RenderWindow &win);
    void addDot(sf::Vector2i x);
    bool readyToDraw();
};




#endif