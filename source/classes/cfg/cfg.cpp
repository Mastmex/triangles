#include "cfg.hpp"
cfg::cfg(){
    ifstream config;
    int choose;
    string line;
    config.open("./../triangles.cfg");
    if(config.is_open())
        cout<<"Configuration file loaded successful"<<endl;
    while (!config.eof())
    {
        bool flag=false;
        string in="";
        getline(config,line);
        if(line.starts_with("height"))
            choose=0;
        if(line.starts_with("length"))
            choose=1;
        if(line.starts_with("antialiasingLevel"))
            choose=2;
        if(line.starts_with("fps"))
            choose=3;
        for(char p:line)
        {
            if(flag)
            {
                in.push_back(p);
            }
            if(p==':')
                flag=true;
        }
        flag=false;
        int hh = stoi(in);
        in="";
        switch (choose)
        {
        case 0:
            this->height=hh;
            break;
        case 1:
            this->length=hh;
            break;
        case 2:
            this->aal=hh;
            break;
        case 3:
            this->fps=hh;
            break;
        default:
            break;
        }
    }
    cout<<this->length<<"X"<<this->height;
}