#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp (int a, int b){ //cmp�������ص�ֵ��bool���� 
	return a > b; //cmp�Ӵ�С���� 
} 
int main(){
	vector<int> v(10);  //��̬����ķ��� 
	for (int i = 0; i < 10; i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < 10; i++){
		cout << v[i] << " ";
	} 
	
	int arr[10];        //��ͨ����ķ��� 
	for (int i = 0; i < 10; i++){
		cin >> v[i]; 
	}
	sort(arr, arr + 10, cmp);  
	for (int i = 0; i < 10; i++){
		cout << v[i] << " ";
	} 
} 
