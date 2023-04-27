#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>

template <typename T>
class Vertex
{
public:
    T id;
    std::unordered_map<Vertex<T> *, double> adjList;

    Vertex<T>(T id) : id{id} {}
};

template <typename T>
class Graph
{
public:
    std::unordered_map<T, Vertex<T> *> vertices;
    Vertex<T> *getVertex(T);
    void addEdge(T, T, double);
    ~Graph();
};

template <typename T>
Vertex<T> *Graph<T>::getVertex(T id)
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
void Graph<T>::addEdge(T id1, T id2, double weight)
{
    Vertex<T> *v1 = getVertex(id1);
    Vertex<T> *v2 = getVertex(id2);
    v1->adjList[v2] = weight;
    v2->adjList[v1] = weight;
}

template <typename T>
Graph<T>::~Graph()
{
    for (auto vertex : vertices)
    {
        delete vertex.second;
    }
}

#endif