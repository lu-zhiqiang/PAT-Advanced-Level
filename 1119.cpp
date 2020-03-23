//我们已经熟练掌握了一个可能不知道为什么的知识点：先序+后序可能无法唯一确认一棵二叉树。
//注意是可能，因为还是有可能就是能做到唯一确认的。
//情形1：可能会存在多种的情况，这种情况就是一个非叶结点只有一个孩子。这个孩子可能是该非叶结点的左孩子也有可能是该非叶结点的右孩子。
//情形2：而唯一的情况是，除了叶子结点，每个结点都是有两个孩子。
//如果是不唯一的情况，我们姑且认为这个是结点的右孩子进行处理，那么就可以得到一个确定的二叉树了。
//核心思想就是找到后序的倒数第二个元素在前序中的位置，如果它和前序的根节点之间没有元素了的话，就无法确定以该元素为到底是左子树还是右子树了！ 


#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post; 
bool unique = true;

void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if(preLeft == preRight) {
        in.push_back(pre[preLeft]); //递归边界是该子树中只剩一个元素，preLeft == preRight（其实这时候 postLeft == postRight 作为判据也可以）。根节点：pre[preLeft] 换成 post[postRight] 也可以。 
        return;
    }
    if(pre[preLeft] == post[postRight]) { //前序的最左边的节点和后序最右边的节点相等，即根节点。 
        int i = preLeft + 1; //初始化：i从最左边节点的下一个节点开始。 
        while (i <= preRight && pre[i] != post[postRight-1]) i++; //找到后序的倒数第二个元素在前序中的位置，i就是这个位置 
        if (i - preLeft > 1) //说明前序中 i位置 的这个元素与前面的根节点之间还有其他元素，这部分元素就是左子树 
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1); //对于左子树递归 
        else // 前序中 i位置 的这个元素与前面的根节点之间没有其他元素，那就无法确定i位置之后（包括i位置）这部分是左子树还是右子树，中序输出就不唯一   
            unique = false;
        in.push_back(pre[preLeft]); //根节点插入 
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1); //对于右子树递归：如果出现了 unique = false 的情形，那个不确定的部分被假定为了右子树 
    }
}
int main() {
    int n;
    scanf("%d", &n); //输入节点数目； 
    pre.resize(n), post.resize(n); //定义大小 
    for (int i = 0; i < n; i++) //输入前序序列 
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) //输入后序序列 
        scanf("%d", &post[i]);
    
	getIn(0, n-1, 0, n-1); //代入函数：prel = 0, prer = n - 1, postl = 0, postr = n - 1;
	   
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++) //格式注意 
        printf(" %d", in[i]);
    printf("\n"); //这个是莫名其妙试出来的，不加就不对 
    return 0;
}





