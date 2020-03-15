#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int target;
struct NODE{
	int w; //�ý��Ȩ�� 
	vector<int> child;//�ý��ĺ���������� 
}; 
vector<NODE> v;	 //��Ž�� 
vector<int> path;//���·���н������ 
void dfs(int index, int nodeNum, int sum){ //index�ǵ�ǰ����ID��nodeNum�Ǽ�¼��ǰ·���£����ǵڼ�����㣻sum���ۼ����� 
	if(sum > target) return;
	//return �������ǰ����������Ψһ�취:������Ը�һ�����ݣ���ʾ��������ݷ��ص��������棻����Ҳ���Բ����κ����ݣ���ʾʲôҲ�����أ������������������� 
	if(sum == target){
		if(v[index].child.size() != 0) return;  //���˵sum == targetʱ�����ӽ�㲻Ϊ�գ���˵���ⲻ��һ��������·������Ҫ�������� 
		for(int i = 0; i < nodeNum; i++)		//���˵sum == targetʱ�����ӽ���Ѿ�Ϊ�գ�˵������һ��������·����Ҫ��������� 
			printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
		return;
	}
	//�Ӵ˴�������ʵ�Ǻ����Ƿ���Խ������ж���䣬��Ϊ�ݹ���Ҫ���ú������ڵģ�������������������εĳ��ڡ� 
	for(int i = 0; i < v[index].child.size(); i++){
		int node = v[index].child[i]; //node���ڱ����ĸú��ӽ������ 
		path[nodeNum] = node;  //nodeNum��1��ʼ����¼��ǰ·���£����ǵڼ�����㡣 
		dfs(node, nodeNum + 1, sum + v[node].w); //���ú��ӽ��Ϊ��ǰ�����ţ�Ȼ��nodeNum+1��sum + �ú��ӽ���Ȩ�� 
	}
}  
int cmp(int a, int b){		//�������������� 
	return v[a].w > v[b].w;   
} 
int main(){
	int n, m, node, k;
	scanf("%d %d %d", &n, &m, &target); //n��ʾ���еĽڵ������m��ʾ��Ҷ�ӽ��ĸ�����target��ʾ�����·��Ȩֵ 
	v.resize(n), path.resize(n); //�������Ĵ�С����Ϊn��·������Ĵ�С����Ϊn�� 
	for(int i = 0; i < n; i++)   //����ÿһ������Ȩ�أ����ID�������Ӧ��ϵ 
		scanf("%d", &v[i].w);
	for(int i = 0; i < m; i++){  
		scanf("%d %d", &node, &k); //node��ʾ�����Ҷ�ӽ���ID��k��ʾ�ýڵ�ĺ��ӵ����� 
		v[node].child.resize(k);   //�ý��ĺ��ӽ�������С����Ϊk�� 
		for(int j = 0; j < k; j++)
			scanf("%d", &v[node].child[j]); //�����ӽ���ID����ý��ĺ��ӽ������ 
		sort(v[node].child.begin(), v[node].child.end(), cmp); //ʵ����������������һ�㰴��Ȩ�شӴ�С��ID�������� 
	}
	dfs(0, 1, v[0].w); //һ��·����nodeNumΪ0�ĳ�ʼ���� 
	return 0;
}




