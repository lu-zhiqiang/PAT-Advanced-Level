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
	//�õ��������������map�����е�Ԫ�أ�����it->first��ȡ��ֵ��it->second����ȡ 
	for (auto it = m.begin(); it != m.end(); it++){    
		cout << it->first << " " << it->second << endl; //���������������Ǹ���·�� 
	}
	for (auto it : m){    
		cout << it.first << " " << it.second << endl; //���������������Ǹ���·�� 
	}
	//����map�ĵ�һ��Ԫ�أ�������ļ���ֵ
	cout << m.begin()->first<< " " << m.begin()->second << endl;
	//����map�����һ��Ԫ�أ�������ļ���ֵ (����Ҫ�ر�ע�⣡��rbegin������rend��)
	cout << m.rbegin()->first<< " " << m.rbegin()->second << endl;
	//���map��Ԫ�ظ���
	cout << m.size() <<endl;  
	
	return 0;
} 
