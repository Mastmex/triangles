#ifndef CFG_HPP
#define CFG_HPP

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class cfg{
private:
int height, length,aal,fps;
public:
cfg();
int getHeight(){return this->height;}
int getLength(){return this->length;}
int getAAL(){return this->aal;}
int getFPS(){return this->fps;}
};



#endif