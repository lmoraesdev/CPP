#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <functional>
#include <cmath>

int compare(int x, int y);
typedef int (*Comparator)(int, int);

class PmergeMe
{

public:
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);
	~PmergeMe();

    int compare(int x, int y);
    int jacobsthal(int n);

    typedef int (*Comparator)(int, int);
    struct ComparatorSort {
        Comparator comp;

        ComparatorSort(Comparator c) : comp(c) {}

        bool operator()(const std::pair<int, int>& x, const std::pair<int, int>& y) const {
            return comp(x.first, y.first) < 0;
        }
    };

    // vector
    std::vector<int> pendingElementOrder(int n);
    int binarySearchInsertionPoint(Comparator comp, int n, const std::vector<int>& coll, int lowerBound, int upperBound);
    std::vector<int> mainChainUntil(int aIndex, const std::vector<int>& mainChain, const std::vector<int>& aPositions);
    void binaryInsertLambda(int bIndex, Comparator comp, std::vector<int>& mainChain, std::vector<int>& aPositions, std::vector<int>& pendingElements);
    std::vector<int> binaryInsert(Comparator comp, int n, const std::vector<int>& coll);
    std::vector<int> mergeInsertionSort(Comparator comp, const std::vector<int>& coll);

    // deque
    std::deque<int> pendingElementOrder_deque(int n);
    int binarySearchInsertionPoint(Comparator comp, int n, const std::deque<int>& coll, int lowerBound, int upperBound);
    std::deque<int> binaryInsert(Comparator comp, int n, const std::deque<int>& coll);
    std::deque<int> mainChainUntilFunction(int aIndex, const std::deque<int>& mainChain, const std::deque<int>& aPositions);
    void binaryInsertLambda(int bIndex, Comparator comp, std::deque<int>& mainChain, std::deque<int>& aPositions, std::deque<int>& pendingElements);
    std::deque<int> mergeInsertionSort_deque(Comparator comp, const std::deque<int>& coll);

};

#endif
