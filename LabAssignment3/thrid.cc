#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

double evaluatePostfix(const string &postfix) {
    stack<double> st;

    for (char c : postfix) {          // read one char at a time
        if (c == ' ') continue;       // ignore spaces

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else {
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();

            if (c == '+') st.push(b + a);
            else if (c == '-') st.push(b - a);
            else if (c == '*') st.push(b * a);
            else if (c == '/') st.push(b / a);
            else if (c == '^') st.push(pow(b, a));
        }
    }

    return st.top();
}

int main() {
    string postfix = "5 1 2 + 4 * + 3 -";  
    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}
