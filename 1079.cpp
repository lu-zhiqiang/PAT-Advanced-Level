#include<iostream> 
#include<vector>
#include<cmath>
using namespace std;
struct node{
	int data; //һ��·�������� 
	vector<int> child; //�洢�ý��ĺ������ 
};
vector<node> v;
double ans = 0.0, p, r;

void dfs(int index, int depth){ //����DFS�Ļ���������indexΪ��ǰ������ţ�depth��Ŀǰ��������ȡ� 
	if(v[index].child.size() == 0){ 
	//����1��û�к��ӽ�㣬���õݹ���ڣ�ͬʱ���ش�ʱ�������ܶÿ�μ���һ����·�����۶�� 
		ans += v[index].data * pow(1 + r, depth);
		return;
	}
	for(int i = 0; i < v[index].child.size(); i++) //�������Ƕ����еĺ��ӽ����б��� 
	//����2���к��ӽ�㣬�Ǿͼ���������ȥ�������������dfs�൱�ڶ����������е����������������ȷ�����������е��������򡢺�����DFS�������������еĲ��������BFS�� 
		dfs(v[index].child[i], depth + 1);
}
int main(){
	int n, k ,c; 
	scanf("%d %lf %lf", &n, &p, &r); //����n���������������p��ԭʼ�۸�����r����ֵ�ٷֱ�r% 
	r = r / 100; //����Ǳ���Ҫȥ���ģ���������r�ǰٷֺ�ǰ������� 
	v.resize(n); //���붨����Ķ�̬�����С����Ϊ������û�������ӽ��push_back()�Ĳ�����ֻ����������ı��������node�͵�vector����Ҫ����ȥ�� 
	for (int i = 0; i < n; i++){//����v���������� 
		scanf("%d", &k); //k��ʾ��ǰ���ĺ��Ӹ��� 
		if(k == 0){ 
		//����1����k = 0ʱ�����޺��ӽ��ʱ��������Ǹ�·���������� 
			scanf("%d", &v[i].data);
		}else{
		//����2����k != 0 ʱ�����к��ӽ��ʱ��������Ǻ��ӽ�����ţ��Ѻ��ӽ�������ӵ�ÿһ�����ĺ���vector�У� 
			for(int j = 0; j < k; j++){
				scanf("%d", &c);
				v[i].child.push_back(c); 
			} 
		}
	}
	dfs(0, 0); //�Ӹ��ڵ�Ϊ0�����Ϊ0��ʼ�� 
	printf("%.1f", ans * p); //���Ҫ��һ��ԭ��p��ͬʱע������ĸ�ʽ�� 
	return 0;
}
