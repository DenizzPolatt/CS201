/**
 * Deniz Polat
 * Section 1
 * 22103590
 * Homework 4
*/


#ifndef ALGEBRAICEXPRESSION_H
#define ALGEBRAICEXPRESSION_H

#include <string>
#include <stack> //std stack

std::string infix2postfix(const std::string& exp);
double evaluatePostfix(const std::string& exp);

#endif 
