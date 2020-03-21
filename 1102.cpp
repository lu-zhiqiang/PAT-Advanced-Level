#include<vector>
//�������ֱ�Ӹ��������Ľṹ�����������Ҫ��תdfs�����������õ��ڵ�����v1�����������Ҫ�Խڵ�����v1�ĸ���v2���и�����������(�����ǵ�һ����/����ǵڶ�����)������1020��ϵ�� 
#include<algorithm> 
#include<iostream>
using namespace std;
struct node{
	int id, l, r, index, level;  
}a[100]; //�洢ÿ������id�����ҽڵ��id���±�ֵ�͵�ǰ������ 

vector<node> v1; //���Ǵ洢�����ڵ������õ� 

void dfs(int root, int index, int level){ //root�Ǹ��ڵ�� id��index��λ���±ꣻlevel�ǲ�����  
	if(a[root].r != -1) dfs(a[root].r, index * 2 + 2, level + 1); //�� ע��λ������ǲ��ܱ�ģ�������index * 2 + 2����Ϊ������������׼���� 
	v1.push_back({root, 0, 0, index, level}); //���ڵ㣬��������½ڵ�ķ�ʽҪע�⡣ 
	if(a[root].l != -1) dfs(a[root].l, index * 2 + 1, level + 1); //�� ע��λ������ǲ��ܱ�ģ�������index * 2 + 1����Ϊ������������׼���� 
}  
//������ʵ����ʵ���˴洢ʱ���ҽڵ㽻�����洢������v1���Ƿ�ת��Ķ������������С�  

bool cmp(node a, node b){
	return a.level != b.level? a.level < b.level : a.index > b.index; //����ʽ������С����ǰ�棬��ͬ����ʱ��index�����ǰ�棬 
}

int main(){
	int n, have[100]={0}, root = 0;//have�ĳ�ʼ���˽�һ��  
	cin >> n;//����ڵ���Ŀ 
	for (int i = 0; i < n; i++){
		a[i].id = i; //�����������Ϣ����i�о��ǵ�i���ڵ��id 
		string l, r; //����string��ԭ���ǣ��п�����idҲ�п����� - ��������� - �����������id������Ҫ��stoi���ַ�������ת��Ϊ������ 
		cin >> l >> r; //����ڵ�idΪi�����Һ��ӵ�id 
		if(l != "-"){
			a[i].l = stoi(l); //���ڵ������id����Ϊ�����l 
			have[stoi(l)] = 1; //�������ã�����Ϊ1˵�����ӽڵ��д��ڸ�id��Ҳ���ǲ�����Ϊ�������ĸ��ڵ㡣 
		}else{
			a[i].l = -1;//�����ӽڵ㣬������Ϊ-1  
		}
		if(r != "-"){
			a[i].r = stoi(r); //���ڵ���Һ���id����Ϊ�����r 
			have[stoi(r)] = 1; //�������ã�����Ϊ1˵�����ӽڵ��д��ڸ�id��Ҳ���ǲ�����Ϊ�������ĸ��ڵ㡣 
		}else{
			a[i].r = -1;//���Һ��ӽڵ㣬������Ϊ-1  
		}
	}
	
	while(have[root] == 1) root++; //�����Ҹ����������ؽ���� have[root] == 0 ʱ�� root Ҳ�����������ĸ��ڵ�  
	
	dfs(root, 0, 0); //dfs�����������root��index = 0��level = 0�� 
	vector<node> v2(v1); //v2��v1��һ������
	
	sort(v2.begin(), v2.end(), cmp); //����Ϊ��һ���������Ϊ�ڶ���������v2������������ֱ�ӵõ��ľ��ǲ����� 
	
	for(int i = 0; i < v2.size(); i++){ //�����ڵ㣬������� 
		if(i != 0) cout << " "; //���������ʽ������ 
		cout << v2[i].id;
	}
	cout << endl;
	for(int i = 0; i < v1.size(); i++){ //�����ڵ㣬������� 
		if(i != 0) cout << " "; //���������ʽ������ 
		cout << v1[i].id;
	}
	return 0;
} 
