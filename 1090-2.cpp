#include<iostream> //ֱ��ʹ�ö�ά����ķ�ʽ�� 
#include<vector>
#include<cmath>
using namespace std;
vector<int> v[100000]; 
//��Ϊ�ò����ڵ��е����ݲ��֣��Ϳ���ֱ�������ɣ������أ�Ҫ�ر�ע�⣬�����������ȰѶ�̬���鳤�ȶ����������������������ӣ������Ƽ���1090-1�ķ�ʽ�ɡ� 
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
	int root, temp;//�洢���ڵ�ı�ţ��Լ��������ʱ��š� 
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		if (temp == -1)
			root = i;
		else
			v[temp].push_back(i); 
	} 
	dfs(root, 0);//���ڵ㲻����1079�������������ǹ涨�õ�0�� 
	printf("%.2f %d", p * pow(1 + r/100, maxdepth), maxnum);
	return 0; 
} 
