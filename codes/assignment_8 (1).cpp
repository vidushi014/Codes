#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
map<pair<int,int>,int>mp;
map<int,bool>visited;
vector<vector<int>>ans;
map<int,bool>vis;
map<int,int>dis;
int src,dst;

void dfs(int node,vector<int>path,int prev,int length,bool flag){
    cout << node << "\n";
    visited[node]=true;
    path.push_back(node);
    if(flag==0 && vis[node]==1){
        return;
    }
    else if(vis[node]!=1){
        flag = 1;
    }

    if(node==dst){
        visited[node]=false;
        for(int i=0;i<path.size();i++){
            vis[path[i]]=1;
        }
        ans.push_back(path);
        return ;
    }
    
    for(int i=0;i<graph[node].size();i++){
        dfs(graph[node][i],path,node,length+mp[{node,graph[node][i]}],0);
    }
    return;
}

int main(){
    cout<<"Enter number of nodes : ";
    int n; cin>>n;
    graph.resize(n+1);
    cout<<"Enter number of edges : ";
    int m; cin>>m;

    cout<<"Enter source node :";
    cin>>src;
    cout<<"Enter destination node : ";
    cin>>dst;
    cout<<"Now enter {node 1, node 2, edge length } : \n";
    vis[dst]=1;
    for(int i=0;i<m;i++){
        int x,y,e; cin>>x>>y>>e;
        graph[x].push_back(y);
        mp[{x,y}]=e;
    }


    dfs(src,{},-1,0,1);
    vector<int>answer;
    for(int i=0;i<ans.size();i++){
        int cnt=0;
        for(int j=1;j<ans[i].size();j++){
            cnt+=mp[{ans[i][j-1],ans[i][j]}];
        }
        answer.push_back(cnt);
    }
    int mn_path=INT_MAX,sec_mn=INT_MAX,sec_idx=-1,mnidx=-1;
    for(int i=0;i<answer.size();i++){
        if(answer[i]<mn_path){
            sec_mn=mn_path;
            sec_idx=mnidx;
            mnidx=i;
            mn_path=answer[i];
        }
        else if(answer[i]<sec_mn){
            sec_mn=answer[i];
            sec_idx=i;
        }
    }
    cout << mn_path << " " << mnidx << " " << sec_mn << " " << sec_idx << "\n";
    cout<<"Shortest path : ";
    for(int i=0;i<ans[mnidx].size();i++){
        cout<<ans[mnidx][i]<<" ";
    }
    cout<<"\nSecond option : ";
    if(sec_mn!=mn_path+1 || sec_idx==-1) cout<<"Doesn't exist \n";
    else {
        for(int i=0;i<ans[sec_idx].size();i++){
            cout<<ans[sec_idx][i]<<" ";
        }
        cout << endl;
    }
}