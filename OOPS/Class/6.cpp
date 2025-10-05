#include<bits/stdc++.h>
using namespace std;
// 6.	Define a structure student with roll and score as attributes and with two member functions to take input and to show the data. Use the member functions to take data for a structure variable and to show. Write global function i) to modify score and ii) to show the data again.
struct Student
{
    int roll;
    float score;

    void getData(){
        cout<<"Given roll: \n";
        cin>>roll;
        cout<<"Given score: \n";
        cin>>score;
    }
    void showData(){
        cout<<"Roll: "<<roll<<endl;
        cout<<"Score: "<<score<<endl;
    }
};
float modifyScore(Student &s,float x){
    return s.score = x;   
}
void showAgain(Student s){
        cout<<"Roll: "<<s.roll<<endl;
        cout<<"Score: "<<s.score<<endl;
}
int main()
{
    Student s;

    s.getData();
    s.showData();

    float x = 98.2;
    cout<<"New score: "<<modifyScore(s,x)<<endl;

    showAgain(s);
    s.showData();
    return 0;
}