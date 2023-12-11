// 1. Write a program to implement the following two functions on string using pointer:
// i. To calculate length of given string 
// ii. To concatenate two string
#include <iostream>
using namespace std;
int length(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}
void concat(char *str1, char *str2)
{
    while (*str1 != '\0')
    {
        str1++;
    }
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main()
{
    char str1[100], str2[100];
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;
    cout << "Length of string 1: " << length(str1) << endl;
    cout << "Length of string 2: " << length(str2) << endl;
    concat(str1, str2);
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}