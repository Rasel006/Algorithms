#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> Pii;

const int N = 1e5 + 10;
vector<Pii> Graph_List[N];
bool visited[N];

class Edges {
public:
    int u, v, w;
    Edges(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class cmp {
public:
    bool operator()(Edges a, Edges b) {
        return a.w > b.w;
    }
};

long long Prims_Alogorithm(int s) {
    priority_queue<Edges, vector<Edges>, cmp> pq;
    pq.push(Edges(s, s, 0));
    vector<Edges> Spanning_Tree;
    while (!pq.empty()) {
        Edges parent = pq.top();
        pq.pop();

        if (visited[parent.v]) continue;
        visited[parent.v] = true;
        Spanning_Tree.push_back(parent);

        for (auto&& child : Graph_List[parent.v]) {
            if (!visited[child.first]) {
                pq.push(Edges(parent.v, child.first, child.second));
            }
        }
    }

    long long Sum = 0;
    for (auto&& ed : Spanning_Tree) {
        Sum += (long long)(ed.w);
    }
    return Sum;
}

int main() {
    int n, e;
    cin >> n >> e;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;

        Graph_List[u].push_back({ v, w });
        Graph_List[v].push_back({ u, w });
    }

    long long Result = Prims_Alogorithm(1);
    cout << Result << endl;

    return 0;
}
