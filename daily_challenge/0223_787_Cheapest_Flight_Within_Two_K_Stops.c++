#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int M = 1e8;

class DiAdjacency_list {

public:
    int V; // Number of vertices
    std::vector<std::list<std::pair<int, int>>> List; // Adjacency list representation
    // Constructor
    DiAdjacency_list(int vertices) : V(vertices) {
        // Resize the adjacency list to hold 'vertices' lists
        List.resize(vertices);
    }

    // Function to add an edge between two vertices
    void addEdge(int u, int v, int weight) {
        std::pair<int, int> pr = std::make_pair(v, weight);
        List[u].push_back(pr);
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        DiAdjacency_list adjList(n);

        int flight_len = flights.size();
        int max = 0;
        vector<int> Dist(n);
        vector<int> curDist(n);

        for(int i = 0; i < n; i++){
            Dist[i] = M;
        }

        Dist[src] = 0;

        for(int i = 0; i < flight_len; i++) {
            adjList.addEdge(flights[i][0], flights[i][1], flights[i][2]);
            max = max >= flights[i][2] ? max : flights[i][2];
            if(flights[i][0] == src) {
                Dist[flights[i][1]] = flights[i][2];
            }
        }

        for(int i = 0; i < n; i++){
            cout << Dist[i] << ", ";
        }

        cout << "\nBellman\n";
        // Bellman : Dist^k[u] = min(Dist^(k-1)[v], Dist^(k-1)[u] + weight[u][v])
        curDist = Dist;
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < n; j++){
                cout << j << "node :\n";
                for (auto it = adjList.List[j].begin(); it != adjList.List[j].end(); it++) {
                    cout << (*it).first << " = min(" << Dist[(*it).first] << ", " << Dist[j] + (*it).second << "). ";
                    curDist[(*it).first] = min(curDist[(*it).first], min(Dist[(*it).first], Dist[j] + (*it).second));
                    cout << (*it).first << " = " << curDist[(*it).first] << '\n';
                }
            }
            Dist = curDist;
            for(int i = 0; i < n; i++){
                cout << Dist[i] << ", ";
            }
            cout << '\n';
        }
        return Dist[dst] == M ? -1 : Dist[dst];
    }
};

int main () {
    Solution S;
    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout << S.findCheapestPrice(n, flights, src, dst, k);
    return 0;
}