#include<iostream>//特点：动态数组，运行阶段设置数组的长度、在末尾增加新的数据、在中间插入新的值、长度任意改变。 
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
	vector<int> a;     //定义的时候不指定vector的大小 
	cout << a.size() << endl;//a的size为0 
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i); //在vector a的末尾添加一个元素i 
	} 
	cout << a.size() <<endl; //发现a的size变为了10
	
	
	 
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
