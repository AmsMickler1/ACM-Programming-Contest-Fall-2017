#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool match(char open, char close) {
    if (open == '{' && close == '}')
    return true;
    else if (open == '[' && close == ']')
    return true;
    else if (open == '(' && close == ')')
    return true;
    else
    return false;
}

int main() {

    stack<char> brackets;
    stack<char> operators;
    string line;
    string psf = " ";

    while (getline(cin,line)) {
        // look for bracket
        for (int i=0; i<line.length(); i++) {
            if (line[i] == '{' || line[i] == '[' || line[i] == '(') {
                // add to Stack
                brackets.push(line[i]);
            }
            // look for matching bracket
            else if (line[i] == '}' || line[i] == ']' || line[i] == ')') {
                // if it matches, pop from Stack
                if (match(brackets.top(), line[i])) {
                    brackets.pop();
                }
                // else push onto stack & look for bracket
                else {
                    brackets.push(line[i]);
                }
            }
            // look for equation
            else if (line[i] == '=') {
                int j = i;
                j++;
                while (line[j] != ';') {
                    if (line[j] == ' ')
                        j++;
                    // if line[j] is ')' pop operators until top = '(' and then pop it away
                    if (line[j] == '(') {
                        operators.push(line[j]);
                    }
                    else if (line[j] == ')') {
                        while (operators.top() != '(') {
                            psf += operators.top();
                            psf += " ";
                            operators.pop();
                        }
                        if (!operators.empty()) {
                            operators.pop();                                         // pop & discard '(' from operator stack
                        }
                    }
                    else if (line[j] == '+' || line[j] == '-' || line[j] == '*' || line[j] == '/') {
                        if ( operators.empty() ||  operators.top() == '(') {
                            operators.push(line[j]);
                        }
                        // top has higher precedence, pop it to psf then push line[j] to stack
                        else if (( operators.top() == '*' ||  operators.top() == '/') && (line[j] == '+' || line[j] == '-')) {
                            psf += operators.top();
                            psf += " ";
                            operators.pop();
                            // if new tops are lower precedence, print them too
                            while ( !operators.empty() && (operators.top() == '+' ||  operators.top() == '-')) {
                                psf += operators.top();
                                psf += " ";
                                operators.pop();
                            }
                            operators.push(line[j]);
                        }
                        // line[j] has higher precedence, push line[j] to stack
                        else if (( operators.top() == '+' ||  operators.top() == '-') && (line[j] == '*' || line[j] == '/')) {
                            operators.push(line[j]);
                        }
                        // else operators have same precedence
                        // pop & print previous operator then push new operator to stack
                        else {
                            psf += operators.top();
                            psf += " ";
                            operators.pop();
                            operators.push(line[j]);
                        }
                    }   // end of operators if
                    else {
                        psf += line[j];
                        psf += " ";
                    }   // end of operand IF
                    j++;
                    }
                    while (!operators.empty()) {
                        psf += operators.top();
                        psf += " ";
                        operators.pop();
                }
            }
        }
    }
    if (brackets.empty())
    cout << "True" << psf << endl;
    else
    cout << "False" << psf << endl;
}

// Now that's what bob would do! ;)
