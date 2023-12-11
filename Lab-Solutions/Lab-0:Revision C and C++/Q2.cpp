// 2. a. WAP to create a structure DATE with its member: day, month and year. Write a function which takes two pointer variables of type DATE to calculate the age of person 
// (i.e. pass structure by reference)
// b. Perform no. 2.a. with the concept of classes and objects.

#include <iostream>
using namespace std;

struct DATE
{
    int day, month, year;
};

void calculateAge(DATE *dob, DATE *today)
{
    int age = today->year - dob->year;
    if(today->month < dob->month)
        age--;
    else if(today->month == dob->month && today->day < dob->day)
        age--; 
};

// int main()
// {
//     DATE dob, today;
//     cout << "Enter your date of birth (dd mm yyyy): "<<endl;
//     cin >> dob.day >> dob.month >> dob.year;
//     cout << "Enter today's date (dd mm yyyy): "<<endl;
//     cin >> today.day >> today.month >> today.year;

//     calculateAge(&dob, &today);

//     return 0;
// }

class Date{
    private:
        int day, month, year;
    public:
        Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
        void calculateAge(Date today){
            int age = today.year - year;
            if(today.month < month)
                age--;
            else if(today.month == month && today.day < day)
                age--; 
            cout << "Age: " << age << endl;
            
}
};

int main(){
    Date dob(1, 1, 2000);
    Date today(1, 1, 2020);
    dob.calculateAge(today);
    
    return 0;
}