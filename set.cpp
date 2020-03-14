#include<iostream>//特点：各元素是各不相同的，而且set会按照元素进行从小到大排序 
#include<set>
using namespace std;
int main(){
	set<int> s; //定义一个空集合s 
	s.insert(1);//向集合s里面插入一个1 
	cout << *(s.begin()) <<endl;
	for (int i = 0; i < 6; i++){
		s.insert(i);
	} 
	for (auto it = s.begin(); it != s.end(); it++){
		cout << *it << " ";
	}
	cout << endl << (s.find(2) != s.end()) << endl; //这个查找元素操作是是套路，输出为1表示可以找到，输出为0表示找不到. 
	cout << (s.find(10) != s.end()) << endl;
	s.erase(1);//删除集合s中的1这个元素 
	cout << (s.find(1) != s.end()) << endl;  
	return 0;
} 
