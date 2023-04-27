#ifndef DFS_H
#define DFS_H

#include "graph_.hh"
#include <stack>
#include <vector>
#include <unordered_set>

template <typename T>
class DFS
{
public:
    std::vector<T> DFSResult;

    void DepthFirstSearch(UndirectedGraph<T> &, T);
};

template <typename T>
void DFS<T>::DepthFirstSearch(UndirectedGraph<T> &graph, T startId)
{
    Vertex<T> *startVertex = graph.getVertex(startId);
    std::stack<Vertex<T> *> stack;
    stack.push(startVertex);
    std::unordered_set<Vertex<T> *> visited;

    while (!stack.empty())
    {
        Vertex<T> *currVertex = stack.top();
        stack.pop();
        visited.insert(currVertex);
        DFSResult.push_back(currVertex->id);

        for (auto adjVertex : currVertex->adjList)
        {
            if (!visited.count(adjVertex.first))
            {
                stack.push(adjVertex.first);
            }
        }
    }
}

#endif