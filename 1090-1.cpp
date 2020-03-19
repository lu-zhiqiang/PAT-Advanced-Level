#include<iostream> //联系1079 
#include<vector>
#include<cmath>
using namespace std;
struct node{
	int data; //这道题不需要结点的data部分，因此该处可以省略。 
	vector<int> child; //存储该结点的孩子序号。 
};
vector<node> v; //这样的话就不需要定义node类型的vector了，只需要定义int类型的vector，然后形成二维数组v[i][j]。v[temp].push_back(j) temp是输入的指定结点，j表示指定结点的孩子编号
double ans = 0.0, p, r;
int n, maxdepth = 0, maxnum = 0; 
 
void dfs(int index, int depth){ 
	if(v[index].child.size() == 0){ 
	//到达当前叶子节点处，会有三个情况：1.是该叶子节点深度小于最大深度；2.是该叶子节点深度等于最大深度；3.是该叶子节点深度大于最大深度 
	//1.叶子节点深度小于最大深度，不用处理，直接跳过;
	//2.叶子节点深度等于最大深度，最大深度maxdepth值不变，这个深度下的最大数量maxnum值要加1。
	//3.叶子节点深度大于最大深度，最大深度maxdepth = depth (当前深度)，这个深度下的最大数量maxnum赋值为1(也就是最大深度更新，重新开始从1计数)。 
		if(maxdepth == depth)
			maxnum++;
		if(maxdepth < depth){
			maxdepth = depth;
			maxnum = 1; 
		}
		return;
	}
	for(int i = 0; i < v[index].child.size(); i++) 
		dfs(v[index].child[i], depth + 1);
}
int main(){
	int root, temp;//存储根节点的标号，以及输入的临时标号 
	scanf("%d %lf %lf", &n, &p, &r);
	v.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		if (temp == -1)
			root = i;
		else
			v[temp].child.push_back(i); 
	}
	dfs(root, 0);//根节点不再像1079中那样，并不是规定好的0 
	printf("%.2f %d", p * pow(1 + r/100, maxdepth), maxnum);
	return 0; 
} 
