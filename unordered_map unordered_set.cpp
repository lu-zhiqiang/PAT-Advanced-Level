#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<iostream>
using namespace std; 
int main(){
	unordered_map<string, int> m;
	m["Mike"] = 99;
	m["Victor LU"] = 100;
	m["Amy"] = 88;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	
	unordered_set<int> s;
	s.insert(1);
	cout << *(s.begin()) << endl;
	for (int i = 0; i < 6; i++)
	{	
		s.insert(i);
	}
	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << (s.find(2) != s.end()) << endl;
	cout << (s.find(10) != s.end()) << endl;
	
	return 0;
} 
