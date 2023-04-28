/**
 * @file graph_.hh
 * @author Oziel Ferreira (oziel@unifei.edu.br)
 * @brief Undirected Graph (UG) Data Structure.
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023
 * ! Do not copy or distribute.
 * * Or, if you do, at least let my credits on it. ;)
 */

#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <vector>
#include <cmath>
#include "../../Vertex/vertex.hh"

/**
 * @brief A UG.
 *
 * @tparam T Type of vertices.
 */
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

/**
 * @brief Getter for Vertex.
 *
 * @tparam T Type of UG.
 * @param id ID of vertex.
 * @return Vertex<T>* Pointer to vertex.
 */
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

/**
 * @brief Adder for Edges.
 *
 * @tparam T Type of UG.
 * @param id1 ID of vertex.
 * @param id2 ID of vertex.
 * @param weight Weight of connection.
 */
template <typename T>
void UndirectedGraph<T>::addEdge(T id1, T id2, double weight)
{
    Vertex<T> *v1 = getVertex(id1);
    Vertex<T> *v2 = getVertex(id2);
    v1->adjList[v2].insert(weight);
    v2->adjList[v1].insert(weight);
}

/**
 * @brief Destroy Undirected Graph< T>:: Undirected Graph object
 *
 * @tparam T Type of UG.
 */
template <typename T>
UndirectedGraph<T>::~UndirectedGraph()
{
    for (std::pair<T, Vertex<T> *> vertex : vertices)
    {
        delete vertex.second;
    }
}

/**
 * @brief Getter for Adjacency Matrix (AM) of UG. Returns AM with smaller distance between vertices.
 *
 * @tparam T Type of UG.
 * @return std::vector<std::vector<double>> Adjacency Matrix
 */
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
                    matrix[i][j] = INFINITY;
            }
        }
    }

    return matrix;
}

#endif