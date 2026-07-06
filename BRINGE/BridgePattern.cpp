#include <iostream>
#include <string>

class ISize {
public:
    virtual std::string getSize() const = 0;
    virtual ~ISize() = default;
};

class SmallSize : public ISize { public: std::string getSize() const override { return "Small "; } };
class MediumSize : public ISize { public: std::string getSize() const override { return "Medium "; } };
class LargeSize : public ISize { public: std::string getSize() const override { return "Large "; } };

class IFill {
public:
    virtual std::string getFill() const = 0;
    virtual ~IFill() = default;
};

class EmptyFill : public IFill { public: std::string getFill() const override { return "Empty "; } };
class HalfFullFill : public IFill { public: std::string getFill() const override { return "Half-full "; } };
class FullFill : public IFill { public: std::string getFill() const override { return "Full "; } };

class Shape {
protected:
    ISize* size;
    IFill* fill;
public:
    Shape(ISize* s, IFill* f) : size(s), fill(f) {}
    
    virtual void display() = 0;
    
    virtual ~Shape() {
        delete size;
        delete fill;
    }
};

class Triangle : public Shape {
public:
    Triangle(ISize* s, IFill* f) : Shape(s, f) {}
    void display() override {
        std::cout << "I am a " << size->getSize() << fill->getFill() << "Triangle" << std::endl;
    }
};

class Circle : public Shape {
public:
    Circle(ISize* s, IFill* f) : Shape(s, f) {}
    void display() override {
        std::cout << "I am a " << size->getSize() << fill->getFill() << "Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    Square(ISize* s, IFill* f) : Shape(s, f) {}
    void display() override {
        std::cout << "I am a " << size->getSize() << fill->getFill() << "Square" << std::endl;
    }
};

int main() {
    Shape* shape1 = new Triangle(new LargeSize(), new HalfFullFill());
    shape1->display();

    Shape* shape2 = new Circle(new SmallSize(), new FullFill());
    shape2->display();

    Shape* shape3 = new Square(new MediumSize(), new EmptyFill());
    shape3->display();

    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}