#include<bits/stdc++.h>
using namespace std;
void f(int a, int b){
    cout<<"Inside (int,int)"<<endl;
}
void f(char c, int b){
    cout<<"Inside (char,int)"<<endl;
}
int main()
{
    int a = 5;
    char ch = 'a';
    // float f = 1.0;
    f(a,ch);
    f(ch,ch);
    // f(f,f);

    return 0;
}