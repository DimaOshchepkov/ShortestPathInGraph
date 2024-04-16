#pragma once
#include "Graph.h"
#include <type_traits>

template<class ContImpl>
class Iterator {
    static_assert(std::is_base_of<IGraph<ContImpl>, ContImpl>::value,
        "ContImpl not derived from Container");
public:

    virtual Iterator<ContImpl>& operator++() = 0;
    virtual bool operator!=(const Iterator<ContImpl>& rhs) const = 0;
};


template<typename EdgeType>
class Iterator<AdjencyMatrix<EdgeType>> {
public:

    Iterator<AdjencyMatrix<EdgeType>>& operator++();
    bool operator!=(const Iterator<AdjencyMatrix<EdgeType>>& rhs) const;
};
