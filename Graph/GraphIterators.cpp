#include "pch.h"
#include "framework.h"

#include "GraphIterators.h"

template<typename EdgeType>
AdjencyMatrixNeighborsIterator<EdgeType>::AdjencyMatrixNeighborsIterator(const AdjencyMatrixNeighborsIterator<EdgeType>& it): p(it.p)
{}

template<typename EdgeType>
bool AdjencyMatrixNeighborsIterator<EdgeType>::operator!=(AdjencyMatrixNeighborsIterator<EdgeType> const& other) const
{
	return other.p != p;
}

template<typename EdgeType>
bool AdjencyMatrixNeighborsIterator<EdgeType>::operator==(AdjencyMatrixNeighborsIterator<EdgeType> const& other) const
{
	return other.p == p;
}

template<typename EdgeType>
typename AdjencyMatrixNeighborsIterator<EdgeType>::reference AdjencyMatrixNeighborsIterator<EdgeType>::operator*() const
{
	return *p;
}

template<typename EdgeType>
AdjencyMatrixNeighborsIterator<EdgeType> & AdjencyMatrixNeighborsIterator<EdgeType>::operator++()
{
	do {
		p++;
	} while (*p == 0);
	return *this;
}

template<typename EdgeType>
AdjencyMatrixNeighborsIterator<EdgeType>::AdjencyMatrixNeighborsIterator(typename std::vector<EdgeType>::iterator p) : p(p)
{}