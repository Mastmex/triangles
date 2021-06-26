#include "win.hpp"

win::win()
{
    this->heigth=1017;
    this->length=1920;
}

void win::start(){
    sf::RenderWindow window(sf::VideoMode(this->length,this->heigth),"triangles");
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
                {
                    vec.push_back(sf::Mouse::getPosition());
                    cout<<vec.back().x;
                }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        if(vec.capacity()>=2)
        {
            for(int i=0;i<vec.capacity()-1;i++)
                {
                    sf::Vertex line[]=
                    {
                        sf::Vertex(sf::Vector2f(vec[i].x,vec[i].y)),
                        sf::Vertex(sf::Vector2f(vec[i+1].x,vec[i+1].y))
                    };
                    window.draw(line, 2, sf::Lines);
                }
        }

        // end the current frame
        window.display();
    }
}