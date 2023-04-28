/**
 * @file graph_dijkstra.hh
 * @author Oziel Ferreira (oziel@unifei.edu.br)
 * @brief Dijkstra [Minimal Distance Search] (MDS) for Undirected Graph (UG) Data Structure.
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023
 * ! Do not copy or distribute.
 * * Or, if you do, at least let my credits on it. ;)
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph_.hh"
#include <vector>
#include <queue>
#include <limits>

/**
 * @brief A MDS in an UG.
 *
 * @tparam T Type of vertices.
 */

template <typename T>
class Dijkstra
{
public:
    std::unordered_map<T, double> shortestDistances;
    std::unordered_map<T, T> previousVertices;

    void findShortestPaths(UndirectedGraph<T> &, T, T);
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
void Dijkstra<T>::findShortestPaths(UndirectedGraph<T> &graph, T startId, T endId)
{
    shortestDistances.clear();
    previousVertices.clear();
    std::priority_queue<std::pair<double, Vertex<T> *>, std::vector<std::pair<double, Vertex<T> *>>, std::greater<>> pq;

    for (auto &[id, vertex] : graph.vertices)
    {
        shortestDistances[id] = std::numeric_limits<double>::infinity();
        previousVertices[id] = -1;
        pq.push({shortestDistances[id], vertex});
    }

    shortestDistances[startId] = 0;
    pq.push({shortestDistances[startId], graph.getVertex(startId)});

    while (!pq.empty())
    {
        Vertex<T> *currVertex = pq.top().second;
        pq.pop();

        if (currVertex->id == endId)
        {
            if (pq.empty() || shortestDistances[currVertex->id] <= pq.top().first)
            {
                break;
            }
        }

        for (auto &[adjVertex, weight] : currVertex->adjList)
        {
            double newDistance = shortestDistances[currVertex->id] + *(weight.begin());

            if (newDistance < shortestDistances[adjVertex->id])
            {
                shortestDistances[adjVertex->id] = newDistance;
                previousVertices[adjVertex->id] = currVertex->id;
                pq.push({shortestDistances[adjVertex->id], adjVertex});
            }
        }
    }
}

#endif