# Usage

```cpp
#include <iostream>
#include "./graph.hpp"

int main()
{
    // Creates an undirected graph where the nodes are strings
    Graph<string> graph;

    // Adds edges to the graph (node1, node2, weight)
    graph.addEdge("oradea", "zerind", 71);
    graph.addEdge("oradea", "sibiu", 151);
    graph.addEdge("zerind", "sibiu", 75);

    return 0;
}
```
