//数据本身来说的话，按整数部分是否为0来分情况讨论：
//1)整数部分为0(小于1) 
//2)整数部分非0(大于1) 
#include<iostream>
#include<string>
using namespace std;
int n; //有效位数 
string deal(string s, int& e){ //s是原字符串，e是指数部分 
	int k = 0; //s的下标
	
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin()); //去掉s的前导零 
	}
	 
	if(s[0] == '.' ){ //去掉前导零后是小数点，说明s是小于1的小数，是属于第一种情形 1) 
		s.erase(s.begin());//去除小数点 
		while(s.length() > 0 && s[0] == '0'){
			s.erase(s.begin());//去掉小数点后非零位前的所有零 
			e--;//每去掉一个0，指数e减去1 
		} 
	}else{ //去掉前导零后不是小数点，说明s是大于1的数，是属于第二种情形 2) 
		while(k < s.length() && s[k] != '.'){ //寻找小数点，注意这里的条件：k < s.length()，而不是上面的s.length() > 0 
			k++;
			e++;//只要碰不到小数点就让指数 e++ 
		}//如果有小数点，循环终止时，k便为小数点的下标
		if(k < s.length()){ //说明能找到小数点 
			s.erase(s.begin() + k); //清除掉下标为k的小数点 
		} 
	} 
	
	if(s.length() == 0){
		e = 0; //如果去除前导零后s的长度变为0，说明这个数是0	
	}
	
	int num = 0; 
	k = 0;
	string res;
	
	//这里要注意了，没有说明n与s.length()的大小关系！~可能精度n要比s.length()小，这时候直接chop砍一下；也可能精度比s.length()大，这时候位数不足要补零。 
	while(num < n){ //只要精度还没有到n 
		if(k < s.length()){ //当前精确到的位数比s的长度小的话，继续添加就ok。 
			res += s[k]; //string类型就可以直接使用加法，在后面添加。 
			k++;
		}else res += '0';   //当前精确到的位数比s的长度大的话，补0即可。 
		num++; //当前精确到的位数加1，到下一位；（精度加1） 
	}
	return res;//返回本体部分 
} 
int main(){
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2; 
	int e1 = 0, e2 = 0;//e1和e2为s1和s2的指数。
	s3 = deal(s1,e1); //返回s1本体位 
	s4 = deal(s2,e2); //返回s2本体位
	if(s3 == s4 && e1 == e2){ //主体相同且指数相同则YES 
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;  
	}else{
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" "<<"0."<<s4<<"*10^"<<e2<<endl;
	} 
	return 0;
} 
