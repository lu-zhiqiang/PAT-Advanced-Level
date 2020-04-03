#include<stdio.h>
#include<set>
using namespace std;
int main(){
	set<int> st;
	for(int i = 1; i <= 3; i++){
		st.insert(i);
	}
	auto it = st.find(2);
	printf("%d\n", *it);
	return 0;
}
