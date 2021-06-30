#include "tri.hpp"

// void tri::draw(sf::RenderWindow &win)
// {
//     for(int i=0;i<this->all_dots.capacity();i++)
//         for(int j=i+1;j<this->all_dots.capacity();j++){
//             if(i==(this->count-1)||j==(this->count-1)||this->count==0)
//                 lines.push_back({this->all_dots[i],this->all_dots[j]});
//             //if(!this->isIntersect({this->all_dots[i],this->all_dots[j]}))
//             {
//                 sf::Vertex line[] = {sf::Vertex(sf::Vector2f(this->all_dots[i].x,this->all_dots[i].y)),sf::Vertex(sf::Vector2f(this->all_dots[j].x,this->all_dots[j].y))};
//                 win.draw(line,2,sf::Lines);
                
//             }
//         }
//     count=this->all_dots.capacity();
// }

bool tri::readyToDraw()
{
    if(this->all_dots.capacity()>=3)
        return true;
    else
        return false;
}

void tri::addDot(sf::Vector2i x)
{
    // this->all_dots.push_back(x);
    // this->all_dots.shrink_to_fit();
    if(this->all_dots.capacity()==0)
        {
            this->all_dots.push_back(x);
            this->all_dots.shrink_to_fit();
            return;
        }
    for(sf::Vector2i t:this->all_dots)
    {
        lines.push_back({t,x});
        this->lines.shrink_to_fit();
    }
    this->all_dots.push_back(x);
    this->all_dots.shrink_to_fit();
}


void tri::draw(sf::RenderWindow &win)
{
    for(lin t: this->lines)
    {
        sf::Vertex line[] = {sf::Vertex(sf::Vector2f(t.a.x,t.a.y)),sf::Vertex(sf::Vector2f(t.b.x,t.b.y))};
        win.draw(line,2,sf::Lines);
    }
}

bool tri::isIntersect(lin r)
{
    for(lin f: this->lines)
    {
        //cout<<r<<"   =========   "<<f;
        //system("pause");
        if(r.a==f.a||r.b==f.b/*||r.a==f.b||r.b==f.a*/)
            continue;
        if(this->ch(r,f))
            return true;
    }
    return false;
}

bool tri::ch(lin r, lin f){
    auto v1=(f.b.x-f.a.x)*(r.a.y-f.a.y)-(f.b.y-f.a.y)*(r.a.x-f.a.x);
    auto v2=(f.b.x-f.a.x)*(r.b.y-f.a.y)-(f.b.y-f.a.y)*(r.b.x-f.a.x);
    auto v3=(r.b.x-r.a.x)*(f.a.y-r.a.y)-(r.b.y-r.a.y)*(f.a.x-r.a.x);
    auto v4=(r.b.x-r.a.x)*(f.b.y-r.a.y)-(r.b.y-r.a.y)*(f.b.x-r.a.x);
    if(v1*v2<0 && v3*v4<0)
        return true;
    else return false;
}
bool tri::ch2(lin r, lin f){
    //   r.a    r.b    f.a    f.b
    //{(x1,y1)(x2,y2)(x3,y3)(x4,y4)}
    float   x1 = r.a.x,
            y1 = r.a.y,
            x2 = r.b.x,
            y2 = r.b.y,
            x3 = f.a.x,
            y3 = f.a.y,
            x4 = f.b.x,
            y4 = f.b.y;
    float k1,k2,b1,b2;
    if (x1>x2) swap(x1,x2); //2
    if (x3>x4) swap(x3,x4); //3
    if (y1==y2) k1=0; else if (x1==x2) k1=__FLT_MAX__; else k1=(y2-y1)/(x2-x1); //4
    if (y3==y4) k2=0; else if (x3==x4) k2=__FLT_MAX__; else k2=(y4-y3)/(x4-x3); //5
    if (k1==k2) return false; //6
    b1= y1 - k1*x1; //7
    b2= y3 - k2*x3; //
    float x=(b2-b1)/(k1-k2);    //8
    float y=k1*x+b1;            //
    if(((x1<=x&&x<=x2))||(x3<=x&&x<=x4))
        return true;
    else return false;
}
