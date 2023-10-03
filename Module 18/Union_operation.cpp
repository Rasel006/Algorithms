#include <bits/stdc++.h>
using namespace std;
int parent[1000]; // Create the arry of parent

int Dsu_Find(int Node)
{ // Create the leader find funtion
    while (parent[Node] != -1)
    {
        Node = parent[Node];
    }
    return Node;
}

void Dsu_Set(int n)
{ // Create the -1 set funtion
    while (n--)
    {
        parent[n] = -1;
    }
}

void Dsu_Union(int a, int b)
{ // Create Union Funtion

    int Leader_Of_A = Dsu_Find(a);
    int Leader_Of_B = Dsu_Find(b);

    if (Leader_Of_A != Leader_Of_B)
    {
        parent[Leader_Of_B] = Leader_Of_A;
    }
}

int main()
{

    // Take input
    int n, e;
    cin >> n >> e;

    // Set the default
    Dsu_Set(n + 1);

    // Make the union
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        Dsu_Union(a, b);
    }


     for (int i = 0; i < 8; i++)
    {
        cout << "Leader Of " << i << " is : " << Dsu_Find(i) << endl;
    
    }
    

    return 0;
}