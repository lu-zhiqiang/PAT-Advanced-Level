#include<iostream> //��������ͺ��� ת ǰ�� 
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int index, value;
};
bool cmp(node a, node b){
	return a.index < b.index;
} 
vector<int> post,in;
vector<node> ans;
void pre(int root, int start, int end, int index){  //root�� ���� �еĸ�λ�ã�start�� ���� �е���ʼ�㣬end�� ���� �еĽ����� index��Ϊ�˲�����������õġ� 
	if(start > end) return;//������ֹ������ 
	int i = start;
	while (i < end && in[i] != post[root]) i++; //�ҵ������и��ڵ���±� 
	ans.push_back({index, post[root]});//���Կ���index�ǵ�ǰ���ڵ���±�(��0��ʼ)����Ϊÿһ���ڵ㶼�������Ϊһ�θ��ڵ㡣  
	pre(root - 1 - (end - i), start, i - 1, 2 * index + 1);
	pre(root - 1, i + 1, end, 2 * index + 2);
}
int main(){
	int n;
	scanf("%d", &n); //����malloc������ʵ��
	post.resize(n);
	in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	pre (n - 1, 0, n - 1, 0); 
	//���������У�n-1Ϊ���ڵ㣻���������У���0��ʼ����n-1������index��0��ʼ����ʾ��ǰ�ڵ���ţ�������õ��˽������ans�� 
	sort(ans.begin(), ans.end(), cmp); 
	for (int i = 0; i <ans.size(); i++){
		if(i != 0) cout << " "; //������ֻ�е�һ��ǰ��û�пո�
		cout << ans[i].value; 
	} 
	return 0;
} 







