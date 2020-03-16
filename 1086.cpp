#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
vector<int> pre, in, post, value; //前序，中序，后序，结点值
//注意：由于结点值未说明是否相同，前序、中序、后序的动态数组、栈中的元素均为结点的键（key）即索引值。 
void postorder(int root, int start, int end){
	if(start > end) return; //递归的结束条件当start > end 的时候，说明左右子树为空了，此时便可以跳出来了 
	int i = start;
	while (i < end && in[i] != pre[root]) i++; //找到中序遍历序列中当前根结点值的序号i 
	//下面后序要满足左、右、根的顺序进行处理： 
	postorder(root + 1, start, i - 1);//左子树 
	postorder(root + 1 + (i - start), i + 1, end);//右子树 
	post.push_back(pre[root]); //访问根结点,是不是这里写in[i]也可以呢？是的，那个循环条件终止嘛 
} 
int main(){
	int n;
	scanf("%d", &n); //结点的数量 
	char str[5]; //感觉这里字符串数组、字符串的输入输出要更加详细的回顾一下 
	stack<int> s; //s堆栈 
	int key = 0;
	while (~scanf("%s",str)){ //while(~scanf("%s", &str))就是当没有输入的时候退出循环，这里是输入push或者pop 
		if(strlen(str) == 4){ //情形1：输入push 
			int num;
			scanf("%d", &num); //接着输入结点值（题目中没有说结点值是否全部不同distinct） 
			value.push_back(num); //将结点值写入value动态数组 
			pre.push_back(key);	//但是结点键key的编号是从0开始的整数 
			s.push(key++); //同时会将key压入栈
			 
		} else if(strlen(str) == 3){//情形2：输入pop 
			in.push_back(s.top());//保存栈顶元素key 
			s.pop(); //移除栈顶元素key 
		}
	} 
	postorder(0, 0, n - 1);
	printf("%d", value[post[0]]);
	for(int i = 1; i < n; i++)
		printf(" %d",value[post[i]]);
	return 0; 
} 
