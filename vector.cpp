#include<iostream>//�ص㣺��̬���飬���н׶���������ĳ��ȡ���ĩβ�����µ����ݡ����м�����µ�ֵ����������ı䡣 
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cctype>
#include<unordered_map>
using namespace std;
int main(){
	vector<int> a;     //�����ʱ��ָ��vector�Ĵ�С 
	cout << a.size() << endl;//a��sizeΪ0 
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i); //��vector a��ĩβ���һ��Ԫ��i 
	} 
	cout << a.size() <<endl; //����a��size��Ϊ��10
	
	
	 
	vector<int> b(15);
	cout << b.size() <<endl;  
	for (int i = 0; i < b.size(); i++)
	{
		b[i] = 2;
	}
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	
	
	
	vector<int> c(20, 2);
	for (int i = 0; i < c.size(); i++){
		cout << c[i] <<" ";
	}
	cout << endl;
	for (auto it = c.begin(); it != c.end(); it++){
		cout << *it << " ";
	}
	
	return 0;
} 
