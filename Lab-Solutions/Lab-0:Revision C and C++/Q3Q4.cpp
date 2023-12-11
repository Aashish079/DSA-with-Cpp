// 3. WAP to swap the values (of type int, double, char) using function template.
// 4. Perform no.3 using class template.

#include <iostream>
using namespace std;

// Using Class Template
template <class T>
class Swap
{
private:
    T a, b;
public:
    Swap(T a, T b){
        this->a = a;
        this->b = b;
    }
    void swap(){
        T temp = a;
        a = b;
        b = temp;
        cout<<"Swapped"<<endl;
    }
    void display(){
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }
};

int main(){
    Swap<int> s1(1, 2);
    Swap<double> s2(1.1, 2.2);
    Swap<char> s3('a', 'b');
    s1.display();
    s1.swap();
    s1.display();

    s2.display();
    s2.swap();
    s2.display();

    s3.display();
    s3.swap();
    s3.display();

}