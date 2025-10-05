#include<iostream>
using namespace std;
// Using deafult parameters
float calc_perc(float income, float taxrate = 0.10){
	return income*taxrate;
}

int main(){
	float income = 74500.00;
	 
	float ta = calc_perc(income,0.15);
	cout<<"Total ammount is: "<<ta<<endl;
	
	float ta2 = calc_perc(income);
	cout<<"Total (not taxrate provided) ammount is: "<<ta2<<endl;

	return 0;
}
