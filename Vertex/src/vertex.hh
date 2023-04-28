/**
 * @file vertex.hh
 * @author Oziel Ferreira (oziel@unifei.edu.br)
 * @brief Vertex Data Structure.
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023
 * ! Do not copy or distribute.
 * * Or, if you do, at least let my credits on it. ;)
 */

#ifndef VERTEX_H
#define VERTEX_H

#include <unordered_map>
#include <set>

/**
 * @brief A vertex with identifier of any type.
 *
 * @tparam T Type of the identifier.
 */
template <typename T>
class Vertex
{
public:
    T id;
    std::unordered_map<Vertex<T> *, std::set<double>> adjList;

    /**
     * @brief Construct a new Vertex< T> object
     *
     * @param id Identifier of type T.
     */
    Vertex<T>(T id) : id{id} {}
};

#endif