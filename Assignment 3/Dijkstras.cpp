#include <iostream>
using namespace std;
#define INF 100000000000
#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];

void dijkstra(int start, int numNodes) {
    int dist[MAX_NODES];   //for weight of specific node
    bool visited[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {    //setting all nodes to infinity and setting unvisited
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start] = 0;                  //then i have set sourse node as 0

    for (int count = 0; count < numNodes - 1; count++) {    //outer loop for all of checking
        int minDist = INF;
        int minIndex = -1;

        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && dist[i] <= minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }

        visited[minIndex] = true;

        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && graph[minIndex][i] && dist[minIndex] != INF && (dist[minIndex] + graph[minIndex][i] < dist[i])) {        
			//if selected node^s one adjacents node  weight+prev weight is less than weight of  others adjacent then add
                dist[i] = dist[minIndex] + graph[minIndex][i];             
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < numNodes; i++) {
        cout << "Node " << i << ": " << dist[i] <<endl;
    }
}

int main() {
    int numNodes;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cin >> graph[i][j];
        }
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    dijkstra(startNode, numNodes);

    return 0;
}
