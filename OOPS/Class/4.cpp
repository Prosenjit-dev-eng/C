#include<iostream>
using namespace std;
void f(int a){
    cout<<"Inside f(int)"<<endl;
}

void f(float f){
    cout<<"Inside f(float)"<<endl;
}


int main()
{
    int i = 10;
    char c = 'A';     // ASCII value = 65
    float fnum = 5.5f;
    double dnum = 3.14159;

    cout << "---- First case: Only f(int) ----" << endl;
    // Only f(int) is defined, so everything tries to convert to int

    f(i);    // exact match → f(int)
    f(c);    // char promoted to int → f(int)
    f(fnum); // float converted to int → f(int)
    f(dnum); // double converted to int → f(int)

    cout << "\n---- Second case: f(int) and f(float) ----" << endl;
    // Now compiler chooses best match

    f(i);    // exact match → f(int)
    f(c);    // char promoted to int → f(int)
    f(fnum); // exact match → f(float)
    f(dnum); // double → can go to float or int, but float is "better"
             // so → f(float)
    return 0;
}