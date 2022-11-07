#ifndef _SHAPE_H_
#define _SHAPE_H_

namespace classical {
class Shape;
class Hexagon;
class Circle;
class Trapezium;

class Visitor {
   public:
    virtual float visit(Hexagon* h) = 0;
    virtual float visit(Circle* c) = 0;
    virtual float visit(Trapezium* t) = 0;
};

class AreaVisitor : public Visitor {
   public:
    float visit(Hexagon* h) { return 1; }
    float visit(Circle* c) { return 2; }
    float visit(Trapezium* t) { return 3; }
};

class ParimeterVisitor : public Visitor {
   public:
    float visit(Hexagon* h) { return 11; }
    float visit(Circle* c) { return 22; }
    float visit(Trapezium* t) { return 33; }
};

class Shape {
   public:
    virtual float Accept(Visitor* visitor) = 0;
    virtual ~Shape() {}
};

class Hexagon : public Shape {
   public:
    float Accept(Visitor* visitor) { return visitor->visit(this); }
};

class Circle : public Shape {
    float Accept(Visitor* visitor) { return visitor->visit(this); }
};

class Trapezium : public Shape {
    float Accept(Visitor* visitor) { return visitor->visit(this); }
};

}  // namespace classical

#endif