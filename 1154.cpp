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
	cin >> n >> m;//nΪ��������mΪ���� 
	vector<node> v(m); //v���ڴ洢�� 
	for(int i = 0; i < m; i ++)
		scanf("%d %d", &v[i].t1, &v[i].t2); //�洢�ߵ�������������� 
	cin >> k;
	while(k--){ //kΪ��ɫ�������
		int a[10000] = {0};
		bool flag =	true;
		set<int> se;
		for(int i = 0; i < n; i++){	//�������еĶ�����ɫ����ͳ����ɫ���� 
			scanf("%d", &a[i]);
			se.insert(a[i]);
		}
		for(int i = 0; i < m; i++){
			if(a[v[i].t1] == a[v[i].t2]){
				flag = false;
				break; 
			}	
		}
		if(flag)//�б�flag������� 
			printf("%d-coloring\n",se.size());
		else
			printf("No\n");
	}
	return 0; 
}
