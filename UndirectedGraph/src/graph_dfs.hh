/**
 * @file graph_dfs.hh
 * @author Oziel Ferreira (oziel@unifei.edu.br)
 * @brief Depth First Search (DFS) for Undirected Graph (UG) Data Structure.
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023
 * ! Do not copy or distribute.
 * * Or, if you do, at least let my credits on it. ;)
 */

#ifndef DFS_H
#define DFS_H

#include "graph_.hh"
#include <stack>
#include <vector>
#include <unordered_set>

/**
 * @brief A DFS in an UG.
 *
 * @tparam T Type of vertices.
 */
template <typename T>
class DFS
{
public:
    std::vector<T> DFSResult;

    void DepthFirstSearch(UndirectedGraph<T> &, T);
};

/**
 * @brief Performs a DFS in UG.
 *
 * @tparam T Type of UG.
 * @param graph UG.
 * @param startId Start vertex ID.
 */
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