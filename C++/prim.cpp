#include<bits/stdc++.h>
using namespace std;

struct canh{
    int x,y,z;
};

int n,m;
vector<pair<int,int>> adj[1001];
bool check[1001];

void input(){
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y, z; 
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    memset(check, 0, sizeof(check));
}

vector<canh> MST; 

void prim(int u){
    //cay khung
    int d = 0; // chieu dai cay khung
    check[u] = 1;
    while(MST.size() < n - 1){
        int min = INT_MAX;
        int U , V; // luu 2 dinh cua canh e
        for(int i = 1 ; i <= n ; i++){ //duyet ds canh
            if(check[i]){
                for(pair<int,int> it : adj[i]){
                    int j = it.first, trongso = it.second;
                    if(!check[j] && trongso < min){
                        min = trongso;
                        U = j ;V = i;
                    }
                }
            }
        }
        MST.push_back({U, V, min});
        d += min;
        check[U] = 1;
    }
    cout << d << endl;
    cout<<"Cay Khung: "<<endl;
    for(canh e: MST){
        cout<<e.x<<" - "<<e.y<<endl;
    }
}
int main(){
    input();
    prim(1);
    
}