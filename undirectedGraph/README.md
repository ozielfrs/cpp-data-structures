# Usage

```cpp
#include <iostream>
#include "./src/graph.hh"
using namespace std;

int main()
{
    // Creates an undirected graph where the vertices are strings
    Graph<string> graph;

    // Adds edges to the graph (vertex1, vertex2, weight)
    graph.addEdge("oradea", "zerind", 71);
    graph.addEdge("oradea", "sibiu", 151);
    graph.addEdge("zerind", "sibiu", 75);

    return 0;
}
```
