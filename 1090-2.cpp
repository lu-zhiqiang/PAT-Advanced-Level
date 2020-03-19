#include<iostream> //直接使用二维数组的方式。 
#include<vector>
#include<cmath>
using namespace std;
vector<int> v[100000]; 
//因为用不到节点中的数据部分，就可以直接这样干，但是呢，要特别注意，这样做必须先把动态数组长度定下来，才能像后面那样添加，还是推荐用1090-1的方式吧。 
double ans = 0.0, p, r;
int n, maxdepth = 0, maxnum = 0; 
 
void dfs(int index, int depth){ 
	if(v[index].size() == 0){ 
		if(maxdepth == depth)
			maxnum++;
		if(maxdepth < depth){
			maxdepth = depth;
			maxnum = 1; 
		}
		return;
	}
	for(int i = 0; i < v[index].size(); i++) 
		dfs(v[index][i], depth + 1);
}
int main(){
	int root, temp;//存储根节点的标号，以及输入的临时标号。 
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		if (temp == -1)
			root = i;
		else
			v[temp].push_back(i); 
	} 
	dfs(root, 0);//根节点不再像1079中那样，并不是规定好的0。 
	printf("%.2f %d", p * pow(1 + r/100, maxdepth), maxnum);
	return 0; 
} 
