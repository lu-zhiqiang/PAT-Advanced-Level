#include<iostream> //设置结构体复合条件的排序 
using namespace std;
struct stu{        //定义一个结构体stu，number表示学号，score表示分数 
	int number;
	int score;
};

bool cmp(stu a, stu b){ //cmp函数，返回值是bool，传入的参数类型应该是结构体stu类型。 
 
	if (a.score != b.score)  //如果学生分数不同，就按照分数从大到小排列 
		return a.score > b.score;
	else 					 //如果学生分数相同，就按照学号从小到大排列 
		return a.number < b.number;
}

//这种简单的if-else语句可以用C语言的三目运算符表示
bool cmp(stu a, stu b){
	return a.score != b.score ? a.score > b.score : a.number < b.number; 
} 


int main()
{
	return 0;	
} 
 
