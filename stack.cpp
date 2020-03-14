#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;    //定义一个空栈 
	for (int i = 0; i < 6; i++){
		s.push(i);   //压栈操作 
	}	
	cout << s.top() << endl;  // 访问s的栈顶元素 
	cout << s.size() << endl;  //输出s的元素个数 
	s.pop(); //移除栈顶元素，出栈操作 
	cout << s.top() << endl;
	cout << s.size() <<endl;
	return 0;
} 
