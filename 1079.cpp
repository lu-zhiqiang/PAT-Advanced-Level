#include<iostream> 
#include<vector>
#include<cmath>
using namespace std;
struct node{
	int data; //一条路径的销量 
	vector<int> child; //存储该结点的孩子序号 
};
vector<node> v;
double ans = 0.0, p, r;

void dfs(int index, int depth){ //这是DFS的基本参数：index为当前结点的序号，depth是目前所处的深度。 
	if(v[index].child.size() == 0){ 
	//情形1：没有孩子结点，设置递归出口，同时返回此时的销售总额（每次加上一条链路的销售额）； 
		ans += v[index].data * pow(1 + r, depth);
		return;
	}
	for(int i = 0; i < v[index].child.size(); i++) //遍历则是对所有的孩子结点进行遍历 
	//情形2：有孩子结点，那就继续深搜下去，而这里的深搜dfs相当于二叉树遍历中的先序遍历；首先明确二叉树遍历中的先序、中序、后序都是DFS，二叉树遍历中的层序遍历是BFS。 
		dfs(v[index].child[i], depth + 1);
}
int main(){
	int n, k ,c; 
	scanf("%d %lf %lf", &n, &p, &r); //输入n：结点总数；输入p：原始价格；输入r：增值百分比r% 
	r = r / 100; //这个是必须要去做的，根据题意r是百分号前面的数字 
	v.resize(n); //必须定义结点的动态数组大小，因为这里是没有逐个添加结点push_back()的操作，只是用于下面的遍历；大概node型的vector都需要这样去做 
	for (int i = 0; i < n; i++){//遍历v这个结点数组 
		scanf("%d", &k); //k表示当前结点的孩子个数 
		if(k == 0){ 
		//情形1：当k = 0时，即无孩子结点时，输入的是该路径的销售量 
			scanf("%d", &v[i].data);
		}else{
		//情形2：当k != 0 时，即有孩子结点时，输入的是孩子结点的序号，把孩子结点序号添加到每一个结点的孩子vector中； 
			for(int j = 0; j < k; j++){
				scanf("%d", &c);
				v[i].child.push_back(c); 
			} 
		}
	}
	dfs(0, 0); //从根节点为0、深度为0开始。 
	printf("%.1f", ans * p); //最后要乘一下原价p，同时注意输出的格式； 
	return 0;
}
