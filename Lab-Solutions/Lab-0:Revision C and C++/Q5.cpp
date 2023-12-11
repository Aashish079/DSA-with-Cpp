// 5. а.
// Write a C+t program to perform arithmetic operations on two numbers and throw an necessary exceptions (if the dividend is zerofor division). Enter the input as a+b, where 'a' and 'b' are input numbers and '+' as operator. Check for the valid operators and perform the different operations like addition, subtraction, multiplication and division accordingly.
// b. Perform no.5.a. with and without using Exception Class.

#include <iostream>
#include <stdexcept>

double performOperation(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::invalid_argument("Divisor cannot be zero");
            }
            return a / b;
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

int main() {
    double a, b;
    char op;

    std::cout << "Enter operation in the format a+b: ";
    std::cin >> a >> op >> b;

    try {
        double result = performOperation(a, b, op);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}