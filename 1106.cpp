#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> v[100005];
int mindepth = 99999999, minnum = 1;
void dfs(int index, int depth){ //这里的下标就是id 
	if(mindepth < depth)
		return;  //这个属于剪枝操作，可以不要，如果深度比depth更大了就不往下走了。
	if(v[index].size() == 0){
		if(mindepth == depth)
			minnum++;
		else if(mindepth > depth){
			mindepth = depth;
			minnum = 1;
		}
	} 
	for(int i = 0; i < v[index].size(); i++)
		dfs(v[index][i], depth +1);
}
int main(){
	int n, k, c;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%d",&c);
			v[i].push_back(c);
		}
	} 
	dfs(0,0);
	printf("%.4f %d", p * pow(1 + r/100, mindepth), minnum);
	return 0;
}
