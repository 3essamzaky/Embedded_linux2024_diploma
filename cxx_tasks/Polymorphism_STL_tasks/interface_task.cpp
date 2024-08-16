#include <iostream>

class Drawable{
    private:


    public:

    virtual void draw() = 0;

    virtual ~Drawable(){}

};
class Circle : public Drawable{

    public:

    void draw(){std::cout << "draw circle" << std::endl;}
    
};
class Rectangle : public Drawable{

    public:

    void draw(){std::cout << "draw rectangle" << std::endl;}
};
class Triangle : public Drawable{

    public:

    void draw(){std::cout << "draw triangle" << std::endl;}
};




int main()
{
    Drawable* d = new Circle();
    d->draw();
    delete d;
     
    d = new Rectangle();
    d->draw();
    delete d;

    d = new Triangle();
    d->draw();
    delete d;


    return 0;
}