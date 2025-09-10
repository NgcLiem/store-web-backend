#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n ,m;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
}

void dfs(int u){
    //cout << u <<" ";
    // Danh dau u la da duoc tham
    visited[u] = true;
    for(int v : adj[u]){
        //Neu v chua duoc tham
        if(!visited[v]){
            //Ghi nhan cha cua v la u
            parent[v] = u;
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}

void Path(int s, int t){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);
    //bfs(s);
    if(!visited[t]){
        cout<< "Khong co duong di" << endl;
    }
    else{
        vector<int> path;

        while(t != s){
            path.push_back(t);
            //Lan nguoc lai
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int x : path){
            cout << x <<" ";
        }
    }
}

int main(){
    int s ,t;
    inp();

    cin >> s >> t;
    Path(s,t);
}

// 10 8
// 1 2
// 2 3 
// 2 4
// 3 6
// 6 7
// 5 8
// 3 7
// 8 9
// 1 7

