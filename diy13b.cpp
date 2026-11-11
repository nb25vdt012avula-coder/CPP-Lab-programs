#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle.\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle.\n";
    }
};

// Extended with Triangle
class Triangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Triangle.\n";
    }
};

// Factory function returning a unique_ptr based on user input
std::unique_ptr<Shape> createShape(const std::string& type) {
    if (type == "circle") {
        return std::make_unique<Circle>();
    } else if (type == "rectangle") {
        return std::make_unique<Rectangle>();
    } else if (type == "triangle") {
        return std::make_unique<Triangle>();
    }
    return nullptr;
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::string input;

    std::cout << "Enter shape types ('circle', 'rectangle', 'triangle') or 'done' to stop:\n";
    while (std::cin >> input && input != "done") {
        auto shape = createShape(input);
        if (shape) {
            shapes.push_back(std::move(shape));
        } else {
            std::cout << "Unknown shape type: " << input << "\n";
        }
    }

    std::cout << "\nRendering shapes from vector:\n";
    for (const auto& s : shapes) {
        s->draw();
    }

    return 0;
}