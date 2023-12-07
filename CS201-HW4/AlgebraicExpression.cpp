/**
 * Deniz Polat
 * Section 1
 * 22103590
 * Homework 4
*/

#include "AlgebraicExpression.h"

/**
 * This function determines the precedence of the opeator.
 * '*' and '/' have higher precedence, so hey have an integer value of 2.
*/
int operatorPrecedence(char op) {
    if (op == '*' || op == '/') //division and multiplication
        return 2;
    else if (op == '+' || op == '-') 
        return 1;
    return 0;
}

std::string infix2postfix(const std::string& exp) {
    std::stack<char> stack;
    std::string postfix;

    for (long unsigned int i = 0; i < exp.length(); ++i) 
    {
        char c = exp[i];
        if (isdigit(c)) 
        {
            postfix += c;
        } 
        else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            //correct order check
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }

            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            //correct order check
            while (!stack.empty() && stack.top() != '(' 
                && operatorPrecedence(c) <= operatorPrecedence(stack.top())) 
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

double evaluatePostfix(const std::string& exp) {
    std::stack<double> stack;

    for (long unsigned int i = 0; i < exp.length(); ++i)
    {
        char c = exp[i];

        if (isdigit(c)) //if c is a digit from 1 to 9
        { 
            stack.push(c - '0'); //ascii
        } 

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            double operand1 = stack.top();
            stack.pop();
            double operand2 = stack.top();
            stack.pop();

            double result;
            if (c == '+') {
                result = operand2 + operand1;
            } else if (c == '-') {
                result = operand2 - operand1;
            } else if (c == '*') {
                result = operand2 * operand1;
            } else if (c == '/') {
                result = operand2 / operand1;
            }

            stack.push(result);
        }
    }

    return stack.top();
}