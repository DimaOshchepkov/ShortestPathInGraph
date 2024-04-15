#pragma once
#include "Graph.h"


template<typename EdgeType>
class AdjencyMatrixNeighborsIterator final: public std::iterator<std::input_iterator_tag, EdgeType>
{
    //friend class AdjencyMatrix<EdgeType>;
private:
    AdjencyMatrixNeighborsIterator(typename std::vector<EdgeType>::iterator p);
public:
    AdjencyMatrixNeighborsIterator(const AdjencyMatrixNeighborsIterator& it);

    bool operator!=(AdjencyMatrixNeighborsIterator<EdgeType> const& other) const;
    bool operator==(AdjencyMatrixNeighborsIterator<EdgeType> const& other) const; //need for BOOST_FOREACH
    typename AdjencyMatrixNeighborsIterator<EdgeType>::reference operator*() const;
    AdjencyMatrixNeighborsIterator<EdgeType>& operator++();
private:
    typename std::vector<EdgeType>::iterator p;
};