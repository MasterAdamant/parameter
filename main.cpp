#include <iostream>
#include <string>
#include "include/parameter.hpp"

struct MyStruct {
    int a;
    float b;

    MyStruct() : a(0), b(0.0f) {}
    MyStruct(int a, float b) : a(a), b(b) {}

    // Required for streaming
    friend std::ostream& operator<<(std::ostream& os, const MyStruct& s) {
        return os << "{ a: " << s.a << ", b: " << s.b << " }";
    }
};

int main() {
    try {
        // Basic types
        Parameter p1(42);
        Parameter p2(3.14);
        Parameter p3(std::string("Hello, World!"));

        std::cout << "p1: " << p1.getValueAs<int>() << std::endl;
        std::cout << "p2: " << p2.getValueAs<double>() << std::endl;
        std::cout << "p3: " << p3.getValueAs<std::string>() << std::endl;

        // Custom struct
        MyStruct data(5, 2.71f);
        Parameter p4(data);
        std::cout << "p4: " << p4.getValueAs<MyStruct>() << std::endl;

        // Copy constructor
        Parameter copy = p3;
        std::cout << "copy of p3: " << copy.getValueAs<std::string>() << std::endl;

        // Move constructor
        Parameter moved = std::move(p2);
        std::cout << "moved p2 -> moved: " << moved.getValueAs<double>() << std::endl;

        // Safe access (wrong type)
        int safe = p3.getSafeValueAs<int>(); // Will default to 0
        std::cout << "Safe value from p3 as int (wrong type): " << safe << std::endl;

        // Type info usage
        std::cout << "p1 type: " << p1.getSafeValueAs<int>() << " [" << p1.getSafeValueAs<int>() << "]" << std::endl;

    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
