#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    bool **mat;
    int vertices;

public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        mat = new bool *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            mat[i] = new bool[vertices];
            for (int j = 0; j < vertices; j++)
                mat[i][j] = false;
        }
    }
    void insert(int i, int j)
    {
        mat[i][j] = true;
        mat[j][i] = true;
    }

    void BFS(int i, int vertices)
    {
        vector<bool> mark(vertices, false);
        vector<int> v;
        v.push_back((i));

        mark[i] = true;

        int d;
        while (!v.empty())
        {
            d = v[0];
            cout << d << " ";
            v.erase(v.begin());

            for (int j = 0; j < vertices; j++)
            {
                if (mat[d][j] == 1 && (!mark[j]))
                {
                    v.push_back(j);

                    mark[j] = true;
                }
            }
        }
    }

    void DFS(int start, vector<bool> &mark)
    {
        cout << start << " ";
        mark[start] = true;

        for (int i = 0; i < 5; i++)
        {
            if (mat[start][i] == 1 && (!mark[i]))
            {
                DFS(i, mark);
            }
        }
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < vertices; j++)
                cout << mat[i][j] << " ";
            cout << "" << endl;
        }
    }

    void verify_connection()
    {
        vector<bool> mark(5, false);
        for (int i = 0; i < 5; i++)
        {
            if (mark[i] == false)
            {
                DFS(i, mark);
                cout << "" << endl;
            }
        }
    }
};

int main()
{
    int ch;
    Graph graph(5);
    do
    {
        cout << "This is by matrix graph implementation " << endl;
        cout << "What operation do you wanna perform???: " << endl;
        cout << "\t 1. Insert node into graph " << endl;
        cout << "\t 2. BFS graph implementation " << endl;
        cout << "\t 3. DFS graph implementation " << endl;
        cout << "\t 4. Display the graph " << endl;
        cout << "\t 5. Check if graph is connected " << endl;
        int _op_;
        cin >> _op_;
        switch (_op_)
        {
        case 1:
        {
            int a, b;
            cout << "Enter i and j : ";
            cin >> a >> b;
            graph.insert(a, b);
            break;
        }
        case 2:
        {
            int a;
            cout << " Starting position for BFS ? : ";
            cin >> a;
            graph.BFS(a, 5);
            break;
        }
        case 3:
        {
            vector<bool> mark(5, false);
            int a;
            cout << " Starting position for DFS ? : ";
            cin >> a;
            graph.DFS(a, mark);
            break;
        }
        case 4:
        {
            graph.display();
            break;
        }
        case 5:
        {
            graph.verify_connection();
            break;
        }
        default:
        {
            cout << "Alas!!! Wrong input!! Try again" << endl;
            break;
        }
        }
        cout << "Do You want to continue? 1 for Yes/ 0 for No" << endl;
        cin >> ch;
    } while (ch == 1);
}