#ifndef DFS_H
#define DFS_H

#include <stack>
#include <unordered_set>
#include <vector>

#include "graph_.hh"

/**
 * @brief A DFS in an UG.
 *
 * @tparam T Type of vertices.
 */
template <typename T>
class dfs {
 public:
  std::vector<T> DFSResult;

  void DepthFirstSearch(undirectedGraph<T> &, T);
};

/**
 * @brief Performs a DFS in UG.
 *
 * @tparam T Type of UG.
 * @param graph UG.
 * @param startId Start vertex ID.
 */
template <typename T>
void dfs<T>::DepthFirstSearch(undirectedGraph<T> &graph, T startId) {
  vertex<T> *startVertex = graph.getVertex(startId);
  std::stack<vertex<T> *> stack;
  stack.push(startVertex);
  std::unordered_set<vertex<T> *> visited;

  while (!stack.empty()) {
    vertex<T> *currVertex = stack.top();
    stack.pop();
    visited.insert(currVertex);
    DFSResult.push_back(currVertex->id);

    for (auto adjVertex : currVertex->adjList) {
      if (!visited.count(adjVertex.first)) {
        stack.push(adjVertex.first);
      }
    }
  }
}

#endif