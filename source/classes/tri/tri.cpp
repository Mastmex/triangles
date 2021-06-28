#include "tri.hpp"

void tri::draw(sf::RenderWindow &win){
    for(int i=0;i<this->possible_triangles.capacity();i++)
    {
        sf::Vector2i *c = this->possible_triangles[i];
        std::cout<<c[0].x<<"-"<<c[0].y<<"      "<<c[1].x<<"-"<<c[1].y<<"      "<<c[2].x<<"-"<<c[2].y<<std::endl;
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
    cout<<"1-"<<this->all_dots.capacity()<<endl;
    this->all_dots.push_back(x);
    cout<<"2-"<<this->all_dots.capacity()<<endl;
    cout<<this->all_dots.back().x<<"-"<<this->all_dots.back().y<<endl;
    _sleep(3000);
    if(this->all_dots.capacity()>=3)
    {
        for(int i=0;i<this->all_dots.capacity();i++)
            for(int j=i+1;j<this->all_dots.capacity()-1;j++)
            {
                cout<<i<<" uuuuu "<<j<<" uuuu "<<this->all_dots.capacity()<<endl;
                _sleep(1000);
                sf::Vector2i g[3];
                g[0]=this->all_dots.back();             //Разобраться в проблеме. Непонятно откуда берутся очень большие числа.
                g[1]=this->all_dots[i];
                g[2]=this->all_dots[j];        
                std::cout<<g[0].x<<"-"<<g[0].y<<"      "<<g[1].x<<"-"<<g[1].y<<"      "<<g[2].x<<"-"<<g[2].y<<std::endl;
                //system("pause");
                this->possible_triangles.push_back(g);
            }
    }
}