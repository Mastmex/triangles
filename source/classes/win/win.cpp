#include "win.hpp"

win::win(){
    this->cf=new cfg();
}

void win::start(){
    cout<<this->cf->getLength()<<"X"<<this->cf->getHeight();
    sf::RenderWindow window(sf::VideoMode(this->cf->getLength(),this->cf->getHeight()),"triangles");
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
                    vec.push_back(sf::Mouse::getPosition(window));
                    cout<<vec.back().x<<endl;
                }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // end the current frame
        window.display();
    }
}