#ifndef TRI_HPP
#define TRI_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>


using namespace std;

struct lin{
    sf::Vector2i a,b;
    friend ostream& operator<<(ostream& os, const lin& r){
        int     x1 = r.a.x,
                y1 = r.a.y,
                x2 = r.b.x,
                y2 = r.b.y;
        os<<"("<<x1<<","<<y1<<")-("<<x2<<","<<y2<<")";
    }
};

class tri{
private:
    vector<sf::Vector2i> all_dots;
    vector<lin> lines;
    bool isIntersect(lin r);
    bool ch(lin r, lin f);
    bool ch2(lin r, lin f);
    int count;
public:
    void draw(sf::RenderWindow &win);
    void addDot(sf::Vector2i x);
    bool readyToDraw();
    tri(){this->count=0;}
};




#endif