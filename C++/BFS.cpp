#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9

int n ,m;
vector<int> adj[1001];
bool visited[1001];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void bfs(int u){
    queue <int> q;
    q.push(u);
    visited[u] = true;
    //Buoc lap
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    inp();
    bfs(1);
}
