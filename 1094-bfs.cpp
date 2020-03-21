#include <cstdio> //学习广度搜素的套路 
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100];
int level[100];
int book[100];
int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&a, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);
        }
    }
    
    //bfs  
    queue<int> q;
    q.push(1);
    level[1] = 1;
    while(!q.empty()) {
        int index = q.front();
        q.pop();
        book[level[index]]++;
        for(int i = 0; i < v[index].size(); i++) {
            level[v[index][i]] = level[index] + 1;
            q.push(v[index][i]);
        }
        
    }
    
    int maxnum = 0, maxlevel = 1;
    for(int i = 1; i < 100; i++) {
        if(book[i] > maxnum) {
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}
