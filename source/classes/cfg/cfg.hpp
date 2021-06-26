#ifndef CFG_HPP
#define CFG_HPP

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class cfg{
private:
int height, length;
public:
cfg();
int getHeight(){return this->height;}
int getLength(){return this->length;}
};



#endif