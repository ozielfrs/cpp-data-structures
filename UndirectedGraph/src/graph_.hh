#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <set>
#include <vector>
#include <limits>
#include <cmath>
#include "../../Vertex/vertex.hh"

template <typename T>
class UndirectedGraph
{
public:
    std::unordered_map<T, Vertex<T> *> vertices;
    Vertex<T> *getVertex(T);
    void addEdge(T, T, double);
    std::vector<std::vector<double>> adjMatrix();
    std::vector<std::pair<double, double>> positions();
    ~UndirectedGraph();
};

template <typename T>
Vertex<T> *UndirectedGraph<T>::getVertex(T id)
{
    auto it = vertices.find(id);
    if (it == vertices.end())
    {
        Vertex<T> *v = new Vertex(id);
        vertices[id] = v;
        return v;
    }
    return it->second;
}

template <typename T>
void UndirectedGraph<T>::addEdge(T id1, T id2, double weight)
{
    Vertex<T> *v1 = getVertex(id1);
    Vertex<T> *v2 = getVertex(id2);
    v1->adjList[v2].insert(weight);
    v2->adjList[v1].insert(weight);
}

template <typename T>
UndirectedGraph<T>::~UndirectedGraph()
{
    for (std::pair<T, Vertex<T> *> vertex : vertices)
    {
        delete vertex.second;
    }
}

template <typename T>
std::vector<std::vector<double>> UndirectedGraph<T>::adjMatrix()
{
    std::vector<std::vector<double>> matrix(vertices.size(), std::vector<double>(vertices.size(), 0));
    std::vector<T> vertexIds;
    for (std::pair<T, Vertex<T> *> vertex : vertices)
    {
        vertexIds.push_back(vertex.first);
    }

    for (int i = 0; i < vertexIds.size(); i++)
    {
        for (int j = 0; j < vertexIds.size(); j++)
        {
            if (i == j)
                matrix[i][j] = 0;
            else
            {
                Vertex<T> *v1 = vertices.at(vertexIds[i]);
                Vertex<T> *v2 = vertices.at(vertexIds[j]);

                auto it = v1->adjList.find(v2);
                if (it != v1->adjList.end())
                    matrix[i][j] = *(it->second.begin());
                else
                    matrix[i][j] = std::numeric_limits<double>::infinity();
            }
        }
    }

    return matrix;
}

template <typename T>
std::vector<std::pair<double, double>> UndirectedGraph<T>::positions()
{
    std::vector<std::pair<double, double>> estimatives(vertices.size());
    std::vector<std::vector<double>> adjacencyMatrix = adjMatrix();
    estimatives[0] = std::make_pair(0.0, 0.0);
    double x = 0.0, y = 0.0;
    for (int i = 1; i < vertices.size(); i++)
    {
        double distance = adjacencyMatrix[0][i];
        x += distance;
        estimatives[i] = std::make_pair(distance, 0.0);
    }
    x /= (vertices.size() - 1);
    for (int i = 1; i < vertices.size(); i++)
    {
        double distance = adjacencyMatrix[0][i];
        double angle = 2 * M_PI * (i - 1) / (vertices.size() - 1);
        double dx = x - distance;
        double dy = y + distance * tan(angle);
        estimatives[i] = std::make_pair(dx, dy);
    }

    // Print estimatives
    std::cout << "Estimated distances:\n";
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i]->id << ": (" << estimatives[i].first << ", " << estimatives[i].second << ")\n";
    }

    return estimatives;
}

#endif