#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <limits>
#include <queue>
#include <vector>

#include "graph_.hh"

/**
 * @brief A MDS in an UG.
 *
 * @tparam T Type of vertices.
 */
template <typename T>
class dijkstra {
 public:
  std::unordered_map<T, double> shortestDistances;
  std::unordered_map<T, T> previousVertices;

  void findShortestPaths(undirectedGraph<T> &, T, T);
};

/**
 * @brief Performs a MDS in UG for given start and end vertices.
 *
 * @tparam T Type of UG.
 * @param graph UG.
 * @param startId Start vertex ID.
 * @param endId End vertex ID.
 */
template <typename T>
void dijkstra<T>::findShortestPaths(undirectedGraph<T> &graph, T startId,
                                    T endId) {
  shortestDistances.clear();
  previousVertices.clear();
  std::priority_queue<std::pair<double, vertex<T> *>,
                      std::vector<std::pair<double, vertex<T> *>>,
                      std::greater<>>
      pq;

  for (auto &[id, vertex] : graph.vertices) {
    shortestDistances[id] = std::numeric_limits<double>::infinity();
    previousVertices[id] = -1;
    pq.push({shortestDistances[id], vertex});
  }

  shortestDistances[startId] = 0;
  pq.push({shortestDistances[startId], graph.getVertex(startId)});

  while (!pq.empty()) {
    vertex<T> *currVertex = pq.top().second;
    pq.pop();

    if (currVertex->id == endId) {
      if (pq.empty() || shortestDistances[currVertex->id] <= pq.top().first) {
        break;
      }
    }

    for (auto &[adjVertex, weight] : currVertex->adjList) {
      double newDistance =
          shortestDistances[currVertex->id] + *(weight.begin());

      if (newDistance < shortestDistances[adjVertex->id]) {
        shortestDistances[adjVertex->id] = newDistance;
        previousVertices[adjVertex->id] = currVertex->id;
        pq.push({shortestDistances[adjVertex->id], adjVertex});
      }
    }
  }
}

#endif