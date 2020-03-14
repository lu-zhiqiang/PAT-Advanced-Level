#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	map<string, int> m;
	m["hello"] = 2;
	cout << m["hello"] << endl;
	cout << m["world"] << endl;
	m["world"] ++;
	m[","] = 1;
	//用迭代器遍历，输出map中所有的元素，键用it->first获取，值用it->second来获取 
	for (auto it = m.begin(); it != m.end(); it++){    
		cout << it->first << " " << it->second << endl; //这个迭代器的输出是个套路。 
	}
	for (auto it : m){    
		cout << it.first << " " << it.second << endl; //这个迭代器的输出是个套路。 
	}
	//访问map的第一个元素，输出它的键和值
	cout << m.begin()->first<< " " << m.begin()->second << endl;
	//访问map的最后一个元素，输出它的键和值 (这里要特别注意！是rbegin，而非rend。)
	cout << m.rbegin()->first<< " " << m.rbegin()->second << endl;
	//输出map的元素个数
	cout << m.size() <<endl;  
	
	return 0;
} 
