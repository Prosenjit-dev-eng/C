#include<bits/stdc++.h>
using namespace std;
// 7.	Design a class TIME which stores hour, minute and second. The class should have the methods to support the following:
// •	User may give the time value in 24-hour format.
// •	User may give the time value in AM/PM format
// •	Display the time in 24-hour format.
// •	Display the time in AM/PM format.
// •	User may like to add minute with a time value.

class TIME{
    int hour;
    int minute;
    int second;
    public:
    void giveTimeValin24hrFormat(int h, int m, int s){
        hour = h%24;
        minute = m%24;
        second = s%24;
    }
    void giveTimeInAmPm(int hour, int minute, int second,string ampm){
        if(ampm == "AM" || ampm == "am"){
            if (hour == 12)
            {
                this->hour = 0;
            }
            else this->hour = hour%12; 
        }
        else if (ampm == "PM" || ampm == "pm")
        {
            if(hour == 12) this->hour = 12;
            else
            {
                this->hour = (hour%12)+12;
            }
            
        }
        this->minute = minute%60;
        this->second = second%60;
        
    }
    void displayTimein24hr() const{
        // cout << setfill('0') << setw(4) << 23;  // prints "0023"
        cout<< setfill('0') << setw(2)<<this->hour<<":"<<
        setw(2)<<this->minute<<":"<<setw(2)<<this->second<<endl;
    }
    void displayampm() const{
        int h12 = hour%12;
        if (h12 == 0)
        {
            h12 = 12;
        }
        string ampm = (hour>=12)? "PM" : "AM";

        cout<< setfill('0') << setw(2)<<h12<<":"<<
        setw(2)<<minute<<":"<<setw(2)<<second<<ampm<<endl;
    }

        // ---- Modifier ----
    void addMinutes(int m) {
        int totalSeconds = hour * 3600 + minute * 60 + second;
        totalSeconds += m * 60; // add minutes in seconds
        totalSeconds %= 24 * 3600; // keep within a day

        hour = totalSeconds / 3600;
        minute = (totalSeconds % 3600) / 60;
        second = totalSeconds % 60;
    }
};
int main()
{
    TIME t;
    t.giveTimeValin24hrFormat(23,24,25);
    t.giveTimeInAmPm(11,25,26,"pm");
    t.displayampm();
    t.displayTimein24hr();

    t.addMinutes(68);
    t.displayampm();
    t.displayTimein24hr();

    return 0;
}