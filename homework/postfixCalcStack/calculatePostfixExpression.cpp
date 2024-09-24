#include <string>
#include <stack>
#include <algorithm> // find

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns an int
int calculatePostfixExpression(string expression[], int length) {
    if (length == 0) { // if empty
        return 0;
    }

    stack<int> operandStack;
    string operators[] = {"+", "-", "*", "/", "%"};

    for (int i = 0; i < length; i++) {
        string input = expression[i];

        if (isdigit(input[0])) {
            // If the input is a number
            operandStack.push(stoi(input));
        } else if (find(begin(operators), end(operators), input) != end(operators)) {
            // Make sure at least 2 operands are in the stack
            if (operandStack.size() < 2) {
                return 0;
            }

            // Pop the top 2 operands
            int rightOperand = operandStack.top();
            operandStack.pop();
            int leftOperand = operandStack.top();
            operandStack.pop();

            // Preform the operation
            if (input == operators[0]) { // +
                operandStack.push(leftOperand + rightOperand);
            } else if (input == operators[1]) { // -
                operandStack.push(leftOperand - rightOperand);
            } else if (input == operators[2]) { // *
                operandStack.push(leftOperand * rightOperand);
            } else if (input == operators[3]) { // /
                if (rightOperand == 0)
                    return 0; // cannot divide by 0

                operandStack.push(leftOperand / rightOperand);
            } else if (input == operators[4]) { // %
                if (rightOperand == 0) 
                    return 0; // cannot modulo by 0

                operandStack.push(leftOperand % rightOperand);
            }
        } else { // Unrecognized input
            return 0;
        } // end operator checking
    } // end of for loop

    // Should only be 1 result remaining
    if (operandStack.size() == 1) {
        return operandStack.top();
    } else {
        return 0;
    }
}