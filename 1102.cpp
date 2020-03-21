#include<vector>
//这道题是直接给出了树的结构，中序遍历需要反转dfs的左右子树得到节点序列v1，层序遍历需要对节点序列v1的副本v2进行复合条件排序(层数是第一条件/序号是第二条件)。【与1020联系】 
#include<algorithm> 
#include<iostream>
using namespace std;
struct node{
	int id, l, r, index, level;  
}a[100]; //存储每个结点的id，左右节点的id，下标值和当前层数。 

vector<node> v1; //这是存储遍历节点序列用的 

void dfs(int root, int index, int level){ //root是根节点的 id；index是位置下标；level是层数；  
	if(a[root].r != -1) dfs(a[root].r, index * 2 + 2, level + 1); //右 注意位置序号是不能变的：依旧是index * 2 + 2，是为输出层序遍历做准备。 
	v1.push_back({root, 0, 0, index, level}); //根节点，这种添加新节点的方式要注意。 
	if(a[root].l != -1) dfs(a[root].l, index * 2 + 1, level + 1); //左 注意位置序号是不能变的：依旧是index * 2 + 1，是为输出层序遍历做准备。 
}  
//这样其实就是实现了存储时左右节点交换，存储下来的v1就是反转后的二叉树中序序列。  

bool cmp(node a, node b){
	return a.level != b.level? a.level < b.level : a.index > b.index; //排序方式：层数小的排前面，相同层数时，index大的排前面， 
}

int main(){
	int n, have[100]={0}, root = 0;//have的初始化了解一下  
	cin >> n;//输入节点数目 
	for (int i = 0; i < n; i++){
		a[i].id = i; //这就是隐含信息：第i行就是第i个节点的id 
		string l, r; //设置string的原因是，有可能是id也有可能是 - ；如果不是 - ，即输入的是id，则需要用stoi将字符串进行转化为整数。 
		cin >> l >> r; //输入节点id为i的左右孩子的id 
		if(l != "-"){
			a[i].l = stoi(l); //将节点的左孩子id设置为输入的l 
			have[stoi(l)] = 1; //这样设置，设置为1说明孩子节点中存在该id，也就是不可能为整棵树的根节点。 
		}else{
			a[i].l = -1;//无左孩子节点，则设置为-1  
		}
		if(r != "-"){
			a[i].r = stoi(r); //将节点的右孩子id设置为输入的r 
			have[stoi(r)] = 1; //这样设置，设置为1说明孩子节点中存在该id，也就是不可能为整棵树的根节点。 
		}else{
			a[i].r = -1;//无右孩子节点，则设置为-1  
		}
	}
	
	while(have[root] == 1) root++; //这是找根操作：返回结果是 have[root] == 0 时的 root 也就是整棵树的根节点  
	
	dfs(root, 0, 0); //dfs的输入参数：root，index = 0，level = 0； 
	vector<node> v2(v1); //v2是v1的一个副本
	
	sort(v2.begin(), v2.end(), cmp); //层数为第一条件，序号为第二条件，对v2进行排序；这样直接得到的就是层序了 
	
	for(int i = 0; i < v2.size(); i++){ //遍历节点，输出层序 
		if(i != 0) cout << " "; //这是输出格式的问题 
		cout << v2[i].id;
	}
	cout << endl;
	for(int i = 0; i < v1.size(); i++){ //遍历节点，输出中序 
		if(i != 0) cout << " "; //这是输出格式的问题 
		cout << v1[i].id;
	}
	return 0;
} 
