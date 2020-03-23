//�����Ѿ�����������һ�����ܲ�֪��Ϊʲô��֪ʶ�㣺����+��������޷�Ψһȷ��һ�ö�������
//ע���ǿ��ܣ���Ϊ�����п��ܾ���������Ψһȷ�ϵġ�
//����1�����ܻ���ڶ��ֵ�����������������һ����Ҷ���ֻ��һ�����ӡ�������ӿ����Ǹ÷�Ҷ��������Ҳ�п����Ǹ÷�Ҷ�����Һ��ӡ�
//����2����Ψһ������ǣ�����Ҷ�ӽ�㣬ÿ����㶼�����������ӡ�
//����ǲ�Ψһ����������ǹ�����Ϊ����ǽ����Һ��ӽ��д�����ô�Ϳ��Եõ�һ��ȷ���Ķ������ˡ�
//����˼������ҵ�����ĵ����ڶ���Ԫ����ǰ���е�λ�ã��������ǰ��ĸ��ڵ�֮��û��Ԫ���˵Ļ������޷�ȷ���Ը�Ԫ��Ϊ�����������������������ˣ� 


#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post; 
bool unique = true;

void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if(preLeft == preRight) {
        in.push_back(pre[preLeft]); //�ݹ�߽��Ǹ�������ֻʣһ��Ԫ�أ�preLeft == preRight����ʵ��ʱ�� postLeft == postRight ��Ϊ�о�Ҳ���ԣ������ڵ㣺pre[preLeft] ���� post[postRight] Ҳ���ԡ� 
        return;
    }
    if(pre[preLeft] == post[postRight]) { //ǰ�������ߵĽڵ�ͺ������ұߵĽڵ���ȣ������ڵ㡣 
        int i = preLeft + 1; //��ʼ����i������߽ڵ����һ���ڵ㿪ʼ�� 
        while (i <= preRight && pre[i] != post[postRight-1]) i++; //�ҵ�����ĵ����ڶ���Ԫ����ǰ���е�λ�ã�i�������λ�� 
        if (i - preLeft > 1) //˵��ǰ���� iλ�� �����Ԫ����ǰ��ĸ��ڵ�֮�仹������Ԫ�أ��ⲿ��Ԫ�ؾ��������� 
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1); //�����������ݹ� 
        else // ǰ���� iλ�� �����Ԫ����ǰ��ĸ��ڵ�֮��û������Ԫ�أ��Ǿ��޷�ȷ��iλ��֮�󣨰���iλ�ã��ⲿ������������������������������Ͳ�Ψһ   
            unique = false;
        in.push_back(pre[preLeft]); //���ڵ���� 
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1); //�����������ݹ飺��������� unique = false �����Σ��Ǹ���ȷ���Ĳ��ֱ��ٶ�Ϊ�������� 
    }
}
int main() {
    int n;
    scanf("%d", &n); //����ڵ���Ŀ�� 
    pre.resize(n), post.resize(n); //�����С 
    for (int i = 0; i < n; i++) //����ǰ������ 
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) //����������� 
        scanf("%d", &post[i]);
    
	getIn(0, n-1, 0, n-1); //���뺯����prel = 0, prer = n - 1, postl = 0, postr = n - 1;
	   
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++) //��ʽע�� 
        printf(" %d", in[i]);
    printf("\n"); //�����Ī�������Գ����ģ����ӾͲ��� 
    return 0;
}





