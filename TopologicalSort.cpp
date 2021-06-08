#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

int n,m;
int dist[1000], br, used[1000];
int x,y,price;
vector<pair<int,int>> adj[1000];
int sorted[1000];

void topsort(int v){
    used[v] = 1;
    for(auto x: adj[v]){
        int w=x.first;
        if(!used[w]){
            topsort(w);
        }
    }
    sorted[br--] = v;

}



int main()
{
    cin >> n >> m;
    br = n -1;
    for(int i = 0; i < m; ++i){
        cin >> x >> y >> price;
        adj[x].push_back({y,price});
        adj[y].push_back({x,price});
    }
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for(int i = 0; i < n; i++){
        for(auto x:adj[i]){
            int next = x.first;
            dist[next] = min(dist[next], dist[i] + x.second);
        }
    }

    cout << dist[5]<< endl;
}
/**
6 10
0 1 1
0 2 3
1 4 4
1 3 5
1 2 2
2 4 1
2 3 2
4 3 6
4 5 1
3 5 5


8 10
0 1 3
0 2 1
2 3 2
1 3 1
3 4 4
3 5 2
3 6 1
4 7 1
5 7 4
6 7 3
*/
