#include<iostream>
#include<bitset>
using namespace std;
int main(){
	 bitset<5> b("11");
	//初始化方式
	// bitset<5> b; 都为0
	// bitset<5> b(u); u为unsigned int,如果u = 1, 则被初始化为10000;如果u = 2，则被初始化为01000; 
	// bitset<5> b(s); s为字符串，如"1101" -> "10110"  
	for (int i = 0; i < 5; i++)
		cout << b[i];
	cout << endl << b.any(); //b中是否存在1的二进制位
	cout << endl << b.none(); //b中不存在1吗？
	cout << endl << b.count(); //b中1的二进制位的个数
	cout << endl << b.size(); //b中二进制位个数
	cout << endl << b.test(2) << endl; //测试下标为2处是否二进制为1
	b.set(4);//把b的下标为4处置1 
	b.reset();//所有位归零 
	b.reset(3);//b的下标为3处归0 
	b.flip();//b的所有二进制位逐位取反
	unsigned long a = b.to_ulong();//b转换为unsigned long类型 
	return 0;
}

