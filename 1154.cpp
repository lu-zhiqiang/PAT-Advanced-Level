#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct node
{
	int t1;
	int t2;
};
int main(){
	int n, m, k;
	cin >> n >> m;//n为顶点数，m为边数 
	vector<node> v(m); //v用于存储边 
	for(int i = 0; i < m; i ++)
		scanf("%d %d", &v[i].t1, &v[i].t2); //存储边的两个顶点的索引 
	cin >> k;
	while(k--){ //k为着色组的数量
		int a[10000] = {0};
		bool flag =	true;
		set<int> se;
		for(int i = 0; i < n; i++){	//存下所有的顶点颜色，并统计颜色数量 
			scanf("%d", &a[i]);
			se.insert(a[i]);
		}
		for(int i = 0; i < m; i++){
			if(a[v[i].t1] == a[v[i].t2]){
				flag = false;
				break; 
			}	
		}
		if(flag)//判别flag进行输出 
			printf("%d-coloring\n",se.size());
		else
			printf("No\n");
	}
	return 0; 
}
