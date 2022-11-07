#ifndef _LAMBDA_VISITOR_H_
#define _LAMBDA_VISITOR_H_
#include <utility>

namespace lv {

class Shape {};

// class Hexagon : public Shape {};
// class Circle : public Shape {};
// class Trapezium : public Shape {};

class Hexagon {};
class Circle {};
class Trapezium {};

template <typename... Base>
struct Visitor : Base... {
    using Base::operator()...;
};

template <typename... T>
Visitor(T...) -> Visitor<T...>;

// template <typename... T>
// Visitor(T&&... t) -> Visitor<T...>;

Visitor ParimeterVisitor{
    [](Hexagon h) -> float { return 11; },
    [](Circle c) -> float { return 22; },
    [](Trapezium t) -> float { return 33; },
};

Visitor AreaVisitor{
    [](Hexagon h) -> float { return 1; },
    [](Circle c) -> float { return 2; },
    [](Trapezium t) -> float { return 3; },
};

}  // namespace lv

#endif