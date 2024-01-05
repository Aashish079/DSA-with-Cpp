// 4. Check the paired parenthesis in mathematical expression

#include <iostream>
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

bool isMatchingPair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else
        return false;
}

bool isBalanced(string s)
{
    Stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (isOpeningParenthesis(s[i]))
        {
            st.push(s[i]);
        }
        else if (isClosingParenthesis(s[i]))
        {
            if (st.isEmpty() || !isMatchingPair(st.pop(), s[i]))
            {
                return false;
            }
        }
    }
    return st.isEmpty();
}

int main()
{
    string s;
    cout<<"Enter set of Parenthesis : "<<endl;
    cin>> s;
    cout << s << " is " << (isBalanced(s) ? "balanced" : "not balanced") << endl;
    return 0;
}