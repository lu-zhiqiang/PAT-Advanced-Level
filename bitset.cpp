#include<iostream>
#include<bitset>
using namespace std;
int main(){
	 bitset<5> b("11");
	//��ʼ����ʽ
	// bitset<5> b; ��Ϊ0
	// bitset<5> b(u); uΪunsigned int,���u = 1, �򱻳�ʼ��Ϊ10000;���u = 2���򱻳�ʼ��Ϊ01000; 
	// bitset<5> b(s); sΪ�ַ�������"1101" -> "10110"  
	for (int i = 0; i < 5; i++)
		cout << b[i];
	cout << endl << b.any(); //b���Ƿ����1�Ķ�����λ
	cout << endl << b.none(); //b�в�����1��
	cout << endl << b.count(); //b��1�Ķ�����λ�ĸ���
	cout << endl << b.size(); //b�ж�����λ����
	cout << endl << b.test(2) << endl; //�����±�Ϊ2���Ƿ������Ϊ1
	b.set(4);//��b���±�Ϊ4����1 
	b.reset();//����λ���� 
	b.reset(3);//b���±�Ϊ3����0 
	b.flip();//b�����ж�����λ��λȡ��
	unsigned long a = b.to_ulong();//bת��Ϊunsigned long���� 
	return 0;
}

