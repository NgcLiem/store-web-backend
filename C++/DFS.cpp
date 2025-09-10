#include <iostream>
#include <vector>
#include <cstring>

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
bool check[1001];

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

void dfs(int u){
    cout << u <<" ";
    // Danh dau u la da duoc tham
    visited[u] = true;
    for(int v : adj[u]){
        //Neu v chua duoc tham
        if(!visited[v]){
            dfs(v);
        }
    }
}

void connectedComponent(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++ans;
            cout<<"Cac dinh thuoc thanh phan lien thong thu "<< ans <<":\n";
            dfs(i);
            cout << endl;
        }
    }
    cout<<"So thanh phan lien thong: "<< ans << endl;
}

void dinhtru()
{
    int ans=0;
    int tplt=0;;
    memset(check,false,sizeof(check));
    for(int i=1;i<=n;i++)
    {
        if(!check[i])
            {
            dfs(i);
            tplt++;
        }
    }
    for(int i=1;i<=n;i++)
        {
            memset(check,false,sizeof(check));
            check[i]=true;
            int dem=0; //dem tplt sau khi bo di i;
            for(int j=1;j<=n;j++)
            {
                if(!check[j])
                {
                    ++dem;
                    dfs(j);
                }
            }
            if(dem>tplt)
            {
                ++ans;
            }
        }
        cout<<ans<<endl;
}

int main(){
    inp();
    //dinhtru();
    connectedComponent();
}
