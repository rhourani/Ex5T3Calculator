/*
This program handles the following errors:

Addition overflow
Addition underflow
Subtraction overflow
Subtraction underflow
Multiplication overflow
Multiplication underflow
Division by zero
Invalid operator

Overflow: result of the operation exceeds the maximum limit that can be stored in the variable type.
Underflow: result of the operation is less than the minimum limit that can be stored in the variable type.
*/
#include <iostream>
#include <limits>
#include <stdexcept>

double add(double a, double b) {
    if ((b > 0) && (a > std::numeric_limits<double>::max() - b)) {
        throw std::overflow_error("Addition overflow");
    }
    if ((b < 0) && (a < std::numeric_limits<double>::lowest() - b)) {
        throw std::underflow_error("Addition underflow");
    }
    return a + b;
}

double subtract(double a, double b) {
    if ((b > 0) && (a < std::numeric_limits<double>::lowest() + b)) {
        throw std::underflow_error("Subtraction underflow");
    }
    if ((b < 0) && (a > std::numeric_limits<double>::max() + b)) {
        throw std::overflow_error("Subtraction overflow");
    }
    return a - b;
}

double multiply(double a, double b) {
    if (a > std::numeric_limits<double>::max() / b) {
        throw std::overflow_error("Multiplication overflow");
    }
    if (a < std::numeric_limits<double>::lowest() / b) {
        throw std::underflow_error("Multiplication underflow");
    }
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        double a, b;
        char op;
        std::cout << "Enter an expression in the format a op b: ";
        std::cin >> a >> op >> b;

        switch (op) {
        case '+':
            std::cout << "Result: " << add(a, b) << std::endl;
            break;
        case '-':
            std::cout << "Result: " << subtract(a, b) << std::endl;
            break;
        case '*':
            std::cout << "Result: " << multiply(a, b) << std::endl;
            break;
        case '/':
            std::cout << "Result: " << divide(a, b) << std::endl;
            break;
        default:
            std::cerr << "Invalid operator" << std::endl;
            return 1;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
