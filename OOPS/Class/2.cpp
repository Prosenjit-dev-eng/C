#include<iostream>
using namespace std;
int &max(int &a, int &b){
	if(a>b) return a;
	return b;
}

int main(){
	int a = 10, b = 5;
	
	int x = max(a,b);
	cout<<"(i) When x is a variable of type a or b: "<<x<<endl;
	x = 100;
	cout<<"Now x is: "<<x<<endl;
	cout<<" Now a is: "<<a<<" Now b is: "<<b<<endl;
	int &xr = max(a,b);
	cout<<"(ii) When xr is a referring variable of type a or b: "<<xr<<endl;
	xr = 100;
	cout<<"After reffering a is: "<<a<<" b is: "<<b<<endl;
	return 0;
}
