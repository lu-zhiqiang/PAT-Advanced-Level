#include<iostream> //这是中序和后序 转 前序 
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int index, value;
};
bool cmp(node a, node b){
	return a.index < b.index;
} 
vector<int> post,in;
vector<node> ans;
void pre(int root, int start, int end, int index){  //root是 后序 中的根位置，start是 中序 中的起始点，end是 中序 中的结束点 index是为了层序输出而设置的。 
	if(start > end) return;//迭代终止的条件 
	int i = start;
	while (i < end && in[i] != post[root]) i++; //找到中序中根节点的下标 
	ans.push_back({index, post[root]});//可以看出index是当前根节点的下标(从0开始)，因为每一个节点都会遍历成为一次根节点。  
	pre(root - 1 - (end - i), start, i - 1, 2 * index + 1);
	pre(root - 1, i + 1, end, 2 * index + 2);
}
int main(){
	int n;
	scanf("%d", &n); //不用malloc，轻松实现
	post.resize(n);
	in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	pre (n - 1, 0, n - 1, 0); 
	//后序序列中，n-1为根节点；中序序列中，由0开始，到n-1结束；index从0开始，表示当前节点序号；这样便得到了结果序列ans。 
	sort(ans.begin(), ans.end(), cmp); 
	for (int i = 0; i <ans.size(); i++){
		if(i != 0) cout << " "; //这样就只有第一个前面没有空格；
		cout << ans[i].value; 
	} 
	return 0;
} 







