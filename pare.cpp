#include<iostream>
#include<stack>
using namespace std;

int main() {
    string exp;
    cout << "enter the expression: ";
    cin >> exp;

    stack<char> s;
    bool balanced = true;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                balanced = false;
                break;
            }

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                balanced = false;
                break;
            }
        }
    }

    if (!s.empty())
        balanced = false;

    if (balanced)
        cout << "well parenthesized";
    else
        cout << "not well parenthesized";

    return 0;
}
