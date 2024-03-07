#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(PmergeMe const &other){
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other){
	(void)other;
	return (*this);
}

int compare(int x, int y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int PmergeMe::jacobsthal(int n) {
    return round((std::pow(2, n) + std::pow(-1, n - 1)) / 3);
}

//vector
std::vector<int> PmergeMe::pendingElementOrder(int n) {
    std::vector<int> result;
    for (int i = 0; jacobsthal(i) > n; ++i) {
        result.push_back(jacobsthal(i));
    }
    result.push_back(n);
    std::vector<int> order;
    for (size_t i = 1; i < result.size(); ++i) {
        int a = result[i - 1];
        int b = result[i];
        for (int j = b - 1; j >= a; --j) {
            order.push_back(j);
        }
    }
    return order;
}

//deque
std::deque<int> PmergeMe::pendingElementOrder_deque(int n) {
    std::vector<int> result;
    for (int i = 0; jacobsthal(i) > n; ++i) {
        result.push_back(jacobsthal(i));
    }
    result.push_back(n);
    std::deque<int> order;
    for (size_t i = 1; i < result.size(); ++i) {
        int a = result[i - 1];
        int b = result[i];
        for (int j = b - 1; j >= a; --j) {
            order.push_back(j);
        }
    }
    return order;
}

// vector
int PmergeMe::binarySearchInsertionPoint(Comparator comp, int n, const std::vector<int>& coll, int lowerBound, int upperBound) {
    if (lowerBound > upperBound) {
        return lowerBound;
    } else {
        int midIndex = (lowerBound + upperBound) / 2;
        int compResult = comp(n, coll[midIndex]);
        if (compResult == 1) {
            return binarySearchInsertionPoint(comp, n, coll, midIndex + 1, upperBound);
        } else if (compResult == 0) {
            return midIndex;
        } else {
            return binarySearchInsertionPoint(comp, n, coll, lowerBound, midIndex - 1);
        }
    }
}

//deque
int PmergeMe::binarySearchInsertionPoint(Comparator comp, int n, const std::deque<int>& coll, int lowerBound, int upperBound) {
    if (lowerBound > upperBound) {
        return lowerBound;
    } else {
        int midIndex = (lowerBound + upperBound) / 2;
        int compResult = comp(n, coll[midIndex]);
        if (compResult == 1) {
            return binarySearchInsertionPoint(comp, n, coll, midIndex + 1, upperBound);
        } else if (compResult == 0) {
            return midIndex;
        } else {
            return binarySearchInsertionPoint(comp, n, coll, lowerBound, midIndex - 1);
        }
    }
}

//vector
std::vector<int> PmergeMe::mainChainUntil(int aIndex, const std::vector<int>& mainChain, const std::vector<int>& aPositions) {
    int end = aPositions[aIndex];
    return std::vector<int>(mainChain.begin(), mainChain.begin() + end);
}

//vector
void PmergeMe::binaryInsertLambda(int bIndex, Comparator comp, std::vector<int>& mainChain, std::vector<int>& aPositions, std::vector<int>& pendingElements) {
    int n = pendingElements[bIndex];
    int insertIndex = binarySearchInsertionPoint(comp, n, mainChain, 0, mainChainUntil(bIndex, mainChain, aPositions).size() - 1);
    for (size_t i = 0; i < aPositions.size(); ++i) {
        if (aPositions[i] >= insertIndex) {
            ++aPositions[i];
        }
    }
    mainChain.insert(mainChain.begin() + insertIndex, n);
}

// vector
std::vector<int> PmergeMe::binaryInsert(Comparator comp, int n, const std::vector<int>& coll) {
    std::vector<int> newColl = coll;
    int insertIndex = binarySearchInsertionPoint(comp, n, coll, 0, coll.size() - 1);
    newColl.insert(newColl.begin() + insertIndex, n);
    return newColl;
}

// deque
std::deque<int> PmergeMe::binaryInsert(Comparator comp, int n, const std::deque<int>& coll) {
    std::deque<int> newColl = coll;
    int insertIndex = binarySearchInsertionPoint(comp, n, coll, 0, coll.size() - 1);
    newColl.insert(newColl.begin() + insertIndex, n);
    return newColl;
}

std::vector<int> PmergeMe::mergeInsertionSort(Comparator comp, const std::vector<int>& coll) {
    if (coll.size() < 2) {
        return coll;
    } else {
        std::vector<int> mainChain;
        std::vector<int> pendingElements;

        for (size_t i = 0; i < coll.size(); i++) {
            int n = coll[i];
            size_t insertIndex = binarySearchInsertionPoint(comp, n, mainChain, 0, mainChain.size() - 1);
            mainChain.insert(mainChain.begin() + insertIndex, n);
            pendingElements.push_back(n);
        }

        std::vector<int> aPositions(mainChain.size());
        for (size_t i = 0; i < mainChain.size(); ++i) {
            aPositions[i] = i;
        }

        std::vector<int> order = pendingElementOrder(pendingElements.size());
        for (size_t i = 0; i < order.size(); ++i) {
            binaryInsertLambda(order[i], comp, mainChain, aPositions, pendingElements);
        }

        return mainChain;
    }
}

//deque
// Função auxiliar para mainChainUntil
std::deque<int> PmergeMe::mainChainUntilFunction(int aIndex, const std::deque<int>& mainChain, const std::deque<int>& aPositions) {
    int end = aPositions[aIndex];
    return std::deque<int>(mainChain.begin(), mainChain.begin() + end);
}

// Função auxiliar para binaryInsertLambda
void PmergeMe::binaryInsertLambda(int bIndex, Comparator comp, std::deque<int>& mainChain, std::deque<int>& aPositions, std::deque<int>& pendingElements) {
    int n = pendingElements[bIndex];
    int insertIndex = binarySearchInsertionPoint(comp, n, mainChain, 0, mainChainUntilFunction(bIndex, mainChain, aPositions).size() - 1);
    for (size_t i = 0; i < aPositions.size(); ++i) {
        if (aPositions[i] >= insertIndex) {
            ++aPositions[i];
        }
    }
    mainChain.insert(mainChain.begin() + insertIndex, n);
}

std::deque<int> PmergeMe::mergeInsertionSort_deque(Comparator comp, const std::deque<int>& coll) {
    if (coll.size() < 2) {
        return coll;
    } else {
        std::deque<int> mainChain;
        std::deque<int> pendingElements;

        for (size_t i = 0; i < coll.size(); i++) {
            int n = coll[i];
            size_t insertIndex = binarySearchInsertionPoint(comp, n, mainChain, 0, mainChain.size() - 1);
            mainChain.insert(mainChain.begin() + insertIndex, n);
            pendingElements.push_back(n);
        }

        std::deque<int> aPositions(mainChain.size());
        for (size_t i = 0; i < mainChain.size(); ++i) {
            aPositions[i] = i;
        }

        std::deque<int> order = pendingElementOrder_deque(pendingElements.size());
        for (size_t i = 0; i < order.size(); ++i) {
            binaryInsertLambda(order[i], comp, mainChain, aPositions, pendingElements);
        }

        return mainChain;
    }
}
