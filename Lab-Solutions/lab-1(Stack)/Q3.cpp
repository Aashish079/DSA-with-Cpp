// 3. Evaluate the postfix expression

#include <iostream>
#include "stack.hpp"
using namespace std;

bool isdigit(char c){
    return c >= '0' && c <= '9';
}


int evaluatePostfix(string s)
{
    Stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.pop();
            int op1 = st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(op1 ^ op2);
                break;
            }
        }
    }
    return st.pop();
}

int main(){
    string s = "231*+9-";
    cout <<"231*+9- = "<< evaluatePostfix(s) << endl;
    return 0;
}