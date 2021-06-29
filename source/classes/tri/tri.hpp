#ifndef TRI_HPP
#define TRI_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>


using namespace std;

struct tring{
    sf::Vector2i a,b,c;
    auto operator=(const tring& x);
};

class tri{
private:
    vector<tring> possible_triangles;
    vector<sf::Vector2i> all_dots;
    int count;

public:
    void draw(sf::RenderWindow &win);
    void addDot(sf::Vector2i x);
    bool readyToDraw();
    tri(){this->count=0;}
};




#endif