#include<iostream>//�ص㣺��Ԫ���Ǹ�����ͬ�ģ�����set�ᰴ��Ԫ�ؽ��д�С�������� 
#include<set>
using namespace std;
int main(){
	set<int> s; //����һ���ռ���s 
	s.insert(1);//�򼯺�s�������һ��1 
	cout << *(s.begin()) <<endl;
	for (int i = 0; i < 6; i++){
		s.insert(i);
	} 
	for (auto it = s.begin(); it != s.end(); it++){
		cout << *it << " ";
	}
	cout << endl << (s.find(2) != s.end()) << endl; //�������Ԫ�ز���������·�����Ϊ1��ʾ�����ҵ������Ϊ0��ʾ�Ҳ���. 
	cout << (s.find(10) != s.end()) << endl;
	s.erase(1);//ɾ������s�е�1���Ԫ�� 
	cout << (s.find(1) != s.end()) << endl;  
	return 0;
} 
