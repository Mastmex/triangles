#ifndef TRI_HPP
#define TRI_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>


using namespace std;

struct lin{
    sf::Vector2i a,b;
};

class tri{
private:
    vector<sf::Vector2i> all_dots;
    vector<lin> lines;
    bool isIntersect(lin r);
    bool ch(lin r, lin f);
    bool ch2(lin r, lin f);
public:
    void draw(sf::RenderWindow &win);
    void addDot(sf::Vector2i x);
    bool readyToDraw();
    
};




#endif