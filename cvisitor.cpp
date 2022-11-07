#include <chrono>
#include <iostream>
#include <vector>

#include "classical.h"
#include "lambda_visotor.h"

const int iteration = 10000000;

void with_lambda() {
    std::cout << "with_lambda()\n";
    using vshape = std::variant<lv::Circle, lv::Hexagon, lv::Trapezium>;
    std::vector<vshape> shapes;
    for (int i = 0; i < iteration; i++) {
        if (i % 3 == 0) {
            shapes.push_back(lv::Hexagon{});
        }

        if (i % 3 == 1) {
            shapes.push_back(lv::Circle{});
        }

        if (i % 3 == 2) {
            shapes.push_back(lv::Trapezium{});
        }
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    float total = 0;
    for (auto& s : shapes) {
        auto area = std::visit(lv::AreaVisitor, s);
        auto parimeter = std::visit(lv::ParimeterVisitor, s);

        total += area;
        total += parimeter;
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "with_lambda total:" << total << ", "
              << "duration:" << duration.count() << "\n";
}

void with_classical() {
    std::cout << "with_classical()\n";
    std::vector<classical::Shape*> shapes;

    for (int i = 0; i < iteration; i++) {
        if (i % 3 == 0) {
            shapes.push_back(new classical::Hexagon());
        }

        if (i % 3 == 1) {
            shapes.push_back(new classical::Circle());
        }

        if (i % 3 == 2) {
            shapes.push_back(new classical::Trapezium());
        }
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    auto v_area = new classical::AreaVisitor{};
    auto v_parimeter = new classical::ParimeterVisitor{};

    float total = 0;
    for (auto s : shapes) {
        auto area = s->Accept(v_area);
        auto parimeter = s->Accept(v_parimeter);

        total += area;
        total += parimeter;
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "classical total:" << total << ", "
              << "duration:" << duration.count() << "\n";
}

int main() {
    using namespace std::chrono;
    auto t1 = high_resolution_clock::now();
    with_lambda();
    auto t2 = high_resolution_clock::now();
    with_classical();
    auto t3 = high_resolution_clock::now();

    duration<double> time_span_1 = duration_cast<duration<double>>(t2 - t1);

    duration<double> time_span_2 = duration_cast<duration<double>>(t3 - t2);

    std::cout << "time_span_1:" << time_span_1.count() << " time_span_2:" << time_span_2.count()
              << "\n";
}