#include <iostream>
#include <queue>
//#include <limits.h>
using namespace std;

int n,m;
int dist[1000];
int x,y,price;
vector<pair<int,int>> adj[1000];

void dijkstra(int v){
    for(int i = 0; i < n; ++i){
        dist[i]=INT_MAX;
    }
    dist[v] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({v,0});

    while(!pq.empty()){
        int v = pq.top().first;
        pq.pop();

        for(pair<int,int> neighbour: adj[v]){
            int w = neighbour.first;
            int price = neighbour.second;
            if(dist[v] + price < dist[w]){
                dist[w] = dist[v] + price;
                pq.push({w, dist[w]});
            }
        }
    }
}


int main()
{
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> x >> y >> price;
        adj[x].push_back({y,price});
        adj[y].push_back({x,price});
    }
    dijkstra(0);
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

*/
