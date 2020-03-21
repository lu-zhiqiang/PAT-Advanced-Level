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
	//很重要！！！这个num[depth]++; 的位置相当重要，一定要放到return前，for循环的外面，每遇到一个节点都要进行处理。如果放在if-return块的后面的话，就没有计入叶子节点。 
	if(v[index].child.size() == 0){
		return;
	}
	//num[depth]++;//错误 
	for(int i = 0; i < v[index].child.size(); i++){
		//num[depth]++;//错误 
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
	//题目中It is assumed that such a generation is unique，就说明最大节点层只有一个，要警惕出现特殊情况：比如只有一个节点的情况。这也算是单链的一个特殊情况。 
		if(num[i] > maxnum)
		{
			maxnum = num[i];
			maxnumdepth = i; 
		}
	}
	printf("%d %d", maxnum, maxnumdepth);
	return 0;
}
