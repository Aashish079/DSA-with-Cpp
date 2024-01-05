// 2. Convert :
// a. Infix expression to postfix expression
// b. Infix expression to prefix expression
#include <iostream>
#include <algorithm>
#include "stack.hpp"
using namespace std;

bool isOpeningParenthesis(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool isClosingParenthesis(char c)
{
    return c == ')' || c == '}' || c == ']';
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getPrecedance(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixtoPrefix(string s)
{
    reverse(s.begin(), s.end()); // reverse the string and consider opening parenthesis as closing and vice versa
    Stack<char> st; // stack to store operators
    string preFix = "";

    for (int i = 0; i < s.length(); i++)
    {

        if (isClosingParenthesis(s[i]))
        {
            st.push(s[i]);
        }
        else if (isOpeningParenthesis(s[i]))
        {
            while ( !st.isEmpty() &&!isClosingParenthesis(st.peek()))
            {
                preFix += st.pop();
            }
            if (!st.isEmpty())
                st.pop(); // to pop the opening parenthesis
        }
        else if (isOperator(s[i]))
        {
            while (!st.isEmpty() && getPrecedance(s[i]) <= getPrecedance(st.peek()))
            {
                preFix += st.pop();
            }
            st.push(s[i]);
        }
        else
        {
            preFix += s[i];
        }
    }
    while (!st.isEmpty())
    {
        preFix += st.pop();
    }
    reverse(preFix.begin(), preFix.end());
    return preFix;
}

string infixtoPostfix(string s)
{
    Stack<char> st; // stack to store operators
    string postFix = "";

    for (int i = 0; i < s.length(); i++)
    {

        if (isOpeningParenthesis(s[i]))
        {
            st.push(s[i]);
        }
        else if (isClosingParenthesis(s[i]))
        {
            while ( !st.isEmpty() &&!isOpeningParenthesis(st.peek()))
            {
                postFix += st.pop();
            }
            if (!st.isEmpty())
                st.pop(); // to pop the opening parenthesis
        }
        else if (isOperator(s[i]))
        {
            while (!st.isEmpty() && getPrecedance(s[i]) <= getPrecedance(st.peek()))
            {
                postFix += st.pop();
            }
            st.push(s[i]);
        }
        else
        {
            postFix += s[i];
        }
    }
    while (!st.isEmpty())
    {
        postFix += st.pop();
    }

    return postFix;
}

int main()
{
    string infix, postfix, prefix;
    cout << "Enter Infix expression" << endl;
    cin >> infix;
    postfix = infixtoPostfix(infix);
    prefix = infixtoPrefix(infix);
    cout << "Postfix Expression:" << postfix<<endl;
    cout << "Prefix Expression:" << prefix<<endl;
    return 0;
}
