#include<iostream>
#include<vector>
using namespace std;
struct node{
	int data;
	vector<int> child; 
};
vector<node> v;
int num[100];

void dfs(int index, int depth){
	//cout << index <<"!!"<<depth<<endl; 
	num[depth]++; 
	//����Ҫ���������num[depth]++; ��λ���൱��Ҫ��һ��Ҫ�ŵ�returnǰ��forѭ�������棬ÿ����һ���ڵ㶼Ҫ���д����������if-return��ĺ���Ļ�����û�м���Ҷ�ӽڵ㡣 
	if(v[index].child.size() == 0){
		return;
	}
	//num[depth]++;//���� 
	for(int i = 0; i < v[index].child.size(); i++){
		//num[depth]++;//���� 
		dfs(v[index].child[i], depth + 1);
	}
}

int main()
{
	int n, m, k, node;
	scanf("%d%d", &n, &m);
	v.resize(n + 1);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &node, &k);
		v[node].child.resize(k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d",&v[node].child[j]);
		}
	}
	dfs(1, 1);
	int maxnum = 0, maxnumdepth = 1;
	for(int i = 1; i <= n; i++){ 
	//��Ŀ��It is assumed that such a generation is unique����˵�����ڵ��ֻ��һ����Ҫ��������������������ֻ��һ���ڵ���������Ҳ���ǵ�����һ����������� 
		if(num[i] > maxnum)
		{
			maxnum = num[i];
			maxnumdepth = i; 
		}
	}
	printf("%d %d", maxnum, maxnumdepth);
	return 0;
}
