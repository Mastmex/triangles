#ifndef WIN_HPP
#define WIN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "./../cfg/cfg.hpp"
#include "./../tri/tri.hpp"


using namespace std;




class win{
private:
cfg *cf;
tri t;
public:
    win();
    void start();
};


#endif