#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int target;
struct NODE{
	int w; //该结点权重 
	vector<int> child;//该结点的孩子序号数组 
}; 
vector<NODE> v;	 //存放结点 
vector<int> path;//存放路径中结点的序号 
void dfs(int index, int nodeNum, int sum){ //index是当前结点的ID；nodeNum是记录当前路径下，这是第几个结点；sum是累加器。 
	if(sum > target) return;
	//return 语句是提前结束函数的唯一办法:后面可以跟一份数据，表示将这份数据返回到函数外面；后面也可以不跟任何数据，表示什么也不返回，仅仅用来结束函数。 
	if(sum == target){
		if(v[index].child.size() != 0) return;  //如果说sum == target时，孩子结点不为空，那说明这不是一条完整的路径，就要结束掉。 
		for(int i = 0; i < nodeNum; i++)		//如果说sum == target时，孩子结点已经为空，说明这是一条完整的路径，要进行输出。 
			printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
		return;
	}
	//从此处往上其实是函数是否可以结束的判断语句，因为递归总要设置函数出口的，上面就设置了三种情形的出口。 
	for(int i = 0; i < v[index].child.size(); i++){
		int node = v[index].child[i]; //node等于遍历的该孩子结点的序号 
		path[nodeNum] = node;  //nodeNum从1开始，记录当前路径下，这是第几个结点。 
		dfs(node, nodeNum + 1, sum + v[node].w); //将该孩子结点为当前结点序号，然后nodeNum+1，sum + 该孩子结点的权重 
	}
}  
int cmp(int a, int b){		//复合条件的排序 
	return v[a].w > v[b].w;   
} 
int main(){
	int n, m, node, k;
	scanf("%d %d %d", &n, &m, &target); //n表示树中的节点个数，m表示非叶子结点的个数，target表示输入的路径权值 
	v.resize(n), path.resize(n); //结点数组的大小设置为n，路径数组的大小设置为n； 
	for(int i = 0; i < n; i++)   //输入每一个结点的权重，结点ID建立起对应关系 
		scanf("%d", &v[i].w);
	for(int i = 0; i < m; i++){  
		scanf("%d %d", &node, &k); //node表示输入非叶子结点的ID；k表示该节点的孩子的数量 
		v[node].child.resize(k);   //该结点的孩子结点数组大小设置为k个 
		for(int j = 0; j < k; j++)
			scanf("%d", &v[node].child[j]); //将孩子结点的ID存入该结点的孩子结点数组 
		sort(v[node].child.begin(), v[node].child.end(), cmp); //实际上这里是在树的一层按照权重从大到小对ID进行排序 
	}
	dfs(0, 1, v[0].w); //一个路径中nodeNum为0的初始情形 
	return 0;
}




