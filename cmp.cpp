#include<iostream> //���ýṹ�帴������������ 
using namespace std;
struct stu{        //����һ���ṹ��stu��number��ʾѧ�ţ�score��ʾ���� 
	int number;
	int score;
};

bool cmp(stu a, stu b){ //cmp����������ֵ��bool������Ĳ�������Ӧ���ǽṹ��stu���͡� 
 
	if (a.score != b.score)  //���ѧ��������ͬ���Ͱ��շ����Ӵ�С���� 
		return a.score > b.score;
	else 					 //���ѧ��������ͬ���Ͱ���ѧ�Ŵ�С�������� 
		return a.number < b.number;
}

//���ּ򵥵�if-else��������C���Ե���Ŀ�������ʾ
bool cmp(stu a, stu b){
	return a.score != b.score ? a.score > b.score : a.number < b.number; 
} 


int main()
{
	return 0;	
} 
 
