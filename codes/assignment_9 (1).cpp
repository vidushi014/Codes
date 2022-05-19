#include<bits/stdc++.h>
using namespace std;

queue <int> que;

int vertex;

int main()
{
    cout<<"\nENTER VERTICES: ";
    cin>>vertex;

    int adj[vertex][vertex];

    int topol[vertex] = {0};

    for(int i = 0;i <vertex; i++)
    {
        for(int j = 0;j < vertex; j++)
        {
            adj[i][j] = 0;
        }
    }
    int x= 0;

    while(x!=-1)
    {
        int y;

        cin >> x;
        if(x==-1)
            break;
        cin >> y;
        adj[x][y] = 1;
        topol[y] += 1;
        
      
    }

    for(int i=0;i<vertex;i++)
    {
        if(topol[i]==0)
        {
            que.push(i);
            topol[i] = -1;
        }
    }

    if(que.empty())
    {
        cout<<"\nNot an Acyclic Directed Graph!";
    }

    cout<<"Topological Sort: ";
    while(!que.empty())
    {
        int x = que.front();
        for(int i = 0; i < vertex; i++)
        {
            if(adj[x][i]==1)
            {
                topol[i] -= 1;

                if(topol[i]==0)
                {
                    topol[i] = -1;
                    que.push(i);
                }

            }
        }
        cout<<" "<<x;
        que.pop();
        
    }cout << endl;
}
