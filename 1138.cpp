#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
vector<int> pre, in, post;
void postorder(int root, int start, int end){
	if(start > end) return;
	int i = start;
	while(i < end && in[i] != pre[root]) i++; //这里的找中序遍历序列中的根节点下标 
	postorder(root + 1, start, i - 1);
	postorder(root + 1 + i - start, i + 1, end);
	post.push_back(pre[root]);
}

int main(){
	int n;
	scanf("%d", &n);
	pre.resize(n);
	in.resize(n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	postorder(0, 0, n-1);
	printf("%d", post[0]);
	return 0;
}
 
