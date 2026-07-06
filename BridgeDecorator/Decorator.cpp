#include <iostream>
#include <string>


class Shape {
public:
    virtual void display() const {
        std::cout << "I am a " << getDescription() << std::endl;
    }
    
    virtual std::string getDescription() const = 0;
    virtual ~Shape() = default;
};


class Triangle : public Shape {
public:
    std::string getDescription() const override { return "Triangle"; }
};

class Circle : public Shape {
public:
    std::string getDescription() const override { return "Circle"; }
};

class Square : public Shape {
public:
    std::string getDescription() const override { return "Square"; }
};


class ShapeDecorator : public Shape {
protected:
    Shape* wrappee; 
public:
    ShapeDecorator(Shape* s) : wrappee(s) {}
    
    std::string getDescription() const override {
        return wrappee->getDescription();
    }
    
    ~ShapeDecorator() {
        delete wrappee; 
    }
};

class LargeDecorator : public ShapeDecorator {
public:
    LargeDecorator(Shape* s) : ShapeDecorator(s) {}
    std::string getDescription() const override {
        return "Large " + wrappee->getDescription();
    }
};

class SmallDecorator : public ShapeDecorator {
public:
    SmallDecorator(Shape* s) : ShapeDecorator(s) {}
    std::string getDescription() const override {
        return "Small " + wrappee->getDescription();
    }
};


class HalfFullDecorator : public ShapeDecorator {
public:
    HalfFullDecorator(Shape* s) : ShapeDecorator(s) {}
    std::string getDescription() const override {
        return "Half-full " + wrappee->getDescription();
    }
};

class FullDecorator : public ShapeDecorator {
public:
    FullDecorator(Shape* s) : ShapeDecorator(s) {}
    std::string getDescription() const override {
        return "Full " + wrappee->getDescription();
    }
};

class EmptyDecorator : public ShapeDecorator {
public:
    EmptyDecorator(Shape* s) : ShapeDecorator(s) {}
    std::string getDescription() const override {
        return "Empty " + wrappee->getDescription();
    }
};


int main() {
    
    Shape* shape1 = new LargeDecorator(new HalfFullDecorator(new Triangle()));
    shape1->display();

   
    Shape* shape2 = new SmallDecorator(new FullDecorator(new Circle()));
    shape2->display();

    
    Shape* shape3 = new EmptyDecorator(new Square());
    shape3->display();

    
    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}