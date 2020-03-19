#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
vector<int> pre, in, post, value; //ǰ�����򣬺��򣬽��ֵ
//ע�⣺���ڽ��ֵδ˵���Ƿ���ͬ��ǰ�����򡢺���Ķ�̬���顢ջ�е�Ԫ�ؾ�Ϊ���ļ���key��������ֵ�� 
void postorder(int root, int start, int end){
	if(start > end) return; //�ݹ�Ľ���������start > end ��ʱ��˵����������Ϊ���ˣ���ʱ������������� 
	int i = start;
	while (i < end && in[i] != pre[root]) i++; //�ҵ�������������е�ǰ�����ֵ�����i 
	//�������Ҫ�������ҡ�����˳����д��� 
	postorder(root + 1, start, i - 1);//������ 
	postorder(root + 1 + (i - start), i + 1, end);//������ 
	post.push_back(pre[root]); //���ʸ����,�ǲ�������дin[i]Ҳ�����أ��ǵģ��Ǹ�ѭ��������ֹ�� 
} 
int main(){
	int n;
	scanf("%d", &n); //�������� 
	char str[5]; //�о������ַ������顢�ַ������������Ҫ������ϸ�Ļع�һ�� 
	stack<int> s; //s��ջ 
	int key = 0;
	while (~scanf("%s",str)){ //while(~scanf("%s", &str))���ǵ�û�������ʱ���˳�ѭ��������������push����pop 
		if(strlen(str) == 4){ //����1������push 
			int num;
			scanf("%d", &num); //����������ֵ����Ŀ��û��˵���ֵ�Ƿ�ȫ����ͬdistinct�� 
			value.push_back(num); //�����ֵд��value��̬���� 
			pre.push_back(key);	//����key�ı���Ǵ�0��ʼ��������������������õ���ǰ������pre��
			s.push(key++); //ͬʱ�Ὣkeyѹ��ջ
			//������ʵҲ�ͽ�����key-value�����е�num��һһ��Ӧ�Ĺ�ϵ��key������ͬ�������Լ�ջ�洢��ʱ��key���������ʱ����ݶ�Ӧ��ϵ���value���� 
		} else if(strlen(str) == 3){//����2������pop 
			in.push_back(s.top());//����ջ��Ԫ��key����������in�У�������������õ�����������in�� 
			s.pop(); //�Ƴ�ջ��Ԫ��key 
		}
	} 
	postorder(0, 0, n - 1); //����ĸ���ţ������start��end 
	printf("%d", value[post[0]]); 
	for(int i = 1; i < n; i++)
		printf(" %d",value[post[i]]);//�������洢��keyֵ����post[i]����Ӧ��valueֵ����value[post[i]]�� 
	return 0; 
} 
