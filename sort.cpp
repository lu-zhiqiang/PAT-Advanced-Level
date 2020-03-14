#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp (int a, int b){ //cmp函数返回的值是bool类型 
	return a > b; //cmp从大到小排列 
} 
int main(){
	vector<int> v(10);  //动态数组的方法 
	for (int i = 0; i < 10; i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < 10; i++){
		cout << v[i] << " ";
	} 
	
	int arr[10];        //普通数组的方法 
	for (int i = 0; i < 10; i++){
		cin >> v[i]; 
	}
	sort(arr, arr + 10, cmp);  
	for (int i = 0; i < 10; i++){
		cout << v[i] << " ";
	} 
} 
