#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
  int src, dest, weight;
};

// Function to compare edges by weight
bool compare(const Edge& a, const Edge& b) {
  return a.weight < b.weight;
}

// Function to find the root of a vertex in the disjoint-set
int find(int parent[], int i) {
  if (parent[i] == i)
    return i;
  return find(parent, parent[i]);
}

// Function to perform union of two sets represented by their roots
void Union(int parent[], int rank[], int x, int y) {
  int xroot = find(parent, x);
  int yroot = find(parent, y);

  // Attach the smaller rank tree under the root of the larger rank tree
  if (rank[xroot] < rank[yroot])
    parent[xroot] = yroot;
  else if (rank[xroot] > rank[yroot])
    parent[yroot] = xroot;
  else {
    parent[yroot] = xroot;
    rank[xroot]++;
  }
}

// Function to construct MST using Kruskal's algorithm
void KruskalsMST(vector<Edge>& edges, int V) {
  // Sort edges by weight
  sort(edges.begin(), edges.end(), compare);

  // Allocate memory for creating V sets
  int parent[V];
  int rank[V];

  // Initialize all sets as single element sets
  for (int i = 0; i < V; i++) {
    parent[i] = i;
    rank[i] = 0;
  }

  // Include edges in MST
  vector<Edge> result;
  int i = 0, e = 0;
  while (e < V - 1) {
    Edge currentEdge = edges[i++];

    int x = find(parent, currentEdge.src);
    int y = find(parent, currentEdge.dest);

    // If including this edge doesn't cause a cycle
    if (x != y) {
      result.push_back(currentEdge);
      e++;
      Union(parent, rank, x, y);
    }
  }

  // Print MST edges
  cout << "Following are the edges in the constructed MST\n";
  for (Edge edge : result)
    cout << edge.src << " -- " << edge.dest << "   " << edge.weight << endl;
}

int main() {
  int V, E;
  cout << "Enter the number of vertices and edges: ";
  cin >> V >> E;

  vector<Edge> edges(E);
  cout << "Enter source, destination and weight of each edge:\n";
  for (int i = 0; i < E; i++) {
    cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
  }

  KruskalsMST(edges, V);

  return 0;
}
