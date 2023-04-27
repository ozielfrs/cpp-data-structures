#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph_.hpp"
#include <vector>
#include <queue>
#include <limits>

template <typename T>
class Dijkstra
{
public:
    std::unordered_map<T, double> shortestDistances;
    std::unordered_map<T, T> previousVertices;

    void findShortestPaths(Graph<T> &, T, T);
};

template <typename T>
void Dijkstra<T>::findShortestPaths(Graph<T> &graph, T startId, T endId)
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
            double newDistance = shortestDistances[currVertex->id] + weight;

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