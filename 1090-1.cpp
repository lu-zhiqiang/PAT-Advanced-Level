#include<iostream> //��ϵ1079 
#include<vector>
#include<cmath>
using namespace std;
struct node{
	int data; //����ⲻ��Ҫ����data���֣���˸ô�����ʡ�ԡ� 
	vector<int> child; //�洢�ý��ĺ�����š� 
};
vector<node> v; //�����Ļ��Ͳ���Ҫ����node���͵�vector�ˣ�ֻ��Ҫ����int���͵�vector��Ȼ���γɶ�ά����v[i][j]��v[temp].push_back(j) temp�������ָ����㣬j��ʾָ�����ĺ��ӱ��
double ans = 0.0, p, r;
int n, maxdepth = 0, maxnum = 0; 
 
void dfs(int index, int depth){ 
	if(v[index].child.size() == 0){ 
	//���ﵱǰҶ�ӽڵ㴦���������������1.�Ǹ�Ҷ�ӽڵ����С�������ȣ�2.�Ǹ�Ҷ�ӽڵ���ȵ��������ȣ�3.�Ǹ�Ҷ�ӽڵ���ȴ��������� 
	//1.Ҷ�ӽڵ����С�������ȣ����ô���ֱ������;
	//2.Ҷ�ӽڵ���ȵ��������ȣ�������maxdepthֵ���䣬�������µ��������maxnumֵҪ��1��
	//3.Ҷ�ӽڵ���ȴ��������ȣ�������maxdepth = depth (��ǰ���)���������µ��������maxnum��ֵΪ1(Ҳ���������ȸ��£����¿�ʼ��1����)�� 
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
	int root, temp;//�洢���ڵ�ı�ţ��Լ��������ʱ��� 
	scanf("%d %lf %lf", &n, &p, &r);
	v.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		if (temp == -1)
			root = i;
		else
			v[temp].child.push_back(i); 
	}
	dfs(root, 0);//���ڵ㲻����1079�������������ǹ涨�õ�0 
	printf("%.2f %d", p * pow(1 + r/100, maxdepth), maxnum);
	return 0; 
} 
