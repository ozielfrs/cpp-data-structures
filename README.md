# C++ Data Structures

This repository contains implementations of various data structures in C++. Each data structure is implemented as a separate header file in the folder separated by type of data structure.

## Available Data Structures

The following data structures are currently implemented in this repository:

- Binary Search Tree
- Undirected Graph
- Vertex

## Usage

To use any of the implemented data structures in your C++ project, simply include the appropriate header file. For example, to use the Graph data structure, include the "graph.hh" header file in your project:

```cpp
#include <iostream>
#include "./Graph/graph.hh"
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
