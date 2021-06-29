#include "tri.hpp"

void tri::draw(sf::RenderWindow &win){
    for(int i=0;i<this->possible_triangles.capacity();i++)
    {
        vector <sf::Vector2i> c;
        c.resize(3);
        c[0]=this->possible_triangles[i].a;
        c[1]=this->possible_triangles[i].b;
        c[2]=this->possible_triangles[i].c;
        sf::Vertex line1[] = {sf::Vertex(sf::Vector2f(c[0].x,c[0].y)),sf::Vertex(sf::Vector2f(c[1].x,c[1].y))};
        win.draw(line1,2,sf::Lines);
        sf::Vertex line2[] = {sf::Vertex(sf::Vector2f(c[1].x,c[1].y)),sf::Vertex(sf::Vector2f(c[2].x,c[2].y))};
        win.draw(line2,2,sf::Lines);
        sf::Vertex line3[] = {sf::Vertex(sf::Vector2f(c[2].x,c[2].y)),sf::Vertex(sf::Vector2f(c[0].x,c[0].y))};
        win.draw(line3,2,sf::Lines);
    }
}

bool tri::readyToDraw()
{
    if(this->all_dots.capacity()>=3)
        return true;
    else
        return false;
}

void tri::addDot(sf::Vector2i x){
    this->all_dots.push_back(x);
    this->count++;
    if(this->all_dots.capacity()>=3)
    {
        //if(this->all_dots.capacity()!=count)
        this->all_dots.shrink_to_fit();
        for(int i=0;i<this->all_dots.capacity();i++)
            for(int j=i+1;j<this->all_dots.capacity()-1;j++)
            {
                tring g;
                g.a=this->all_dots.back();             //Разобраться в проблеме. Непонятно откуда берутся очень большие числа.
                g.b=this->all_dots[i];
                g.c=this->all_dots[j];        
                this->possible_triangles.push_back(g);
            }
    }
}


auto tring::operator=(const tring& x)
{
    this->a=x.a;
    this->b=x.b;
    this->c=x.c;
}