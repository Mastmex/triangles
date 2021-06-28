#include "win.hpp"

win::win(){
    this->cf=new cfg();
}

void win::start(){
    cout<<this->cf->getLength()<<"X"<<this->cf->getHeight()<<endl;
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
                    this->t.addDot(sf::Mouse::getPosition(window));
                }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        if(this->t.readyToDraw())
            this->t.draw(window);
        // end the current frame
        window.display();
    }
}