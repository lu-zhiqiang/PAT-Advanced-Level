#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;    //����һ����ջ 
	for (int i = 0; i < 6; i++){
		s.push(i);   //ѹջ���� 
	}	
	cout << s.top() << endl;  // ����s��ջ��Ԫ�� 
	cout << s.size() << endl;  //���s��Ԫ�ظ��� 
	s.pop(); //�Ƴ�ջ��Ԫ�أ���ջ���� 
	cout << s.top() << endl;
	cout << s.size() <<endl;
	return 0;
} 
