#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str = "123";
	int a = stoi(str);
	cout << a << endl;
	str = "123.44";
	double b = stod(str);
	cout << b << endl;
	return 0;
}
