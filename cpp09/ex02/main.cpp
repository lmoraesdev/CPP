#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {

    if(argc < 2)
    {
        std::cerr << "Usage: integers in arguments. Example: 0 3 2 5 6 7" << std::endl;
        return 1;
    }

    try
    {
        int nb_element = argc - 1;
        std::vector<int> unsorted;
        for (int i = 1; i < argc; i++)
            unsorted.push_back(atoi(argv[i]));
        for (size_t i = 0; i < unsorted.size(); i++)
        {
            if (std::count(unsorted.begin(), unsorted.end(), unsorted[i]) > 1)
            {
                std::cerr << "Are duplicate " << unsorted[i] << " in sequence" << std::endl;
                return 1;
            }
        }

        std::deque<int> deque;
        for (size_t i = 0; i < unsorted.size(); i++)
            deque.push_back(unsorted[i]);
        std::cout << std::string(80, '-') << std::endl << std::endl;
        std::cout << "Before: ";
        for (int i = 0; i < argc - 1; i++){

            std::cout << unsorted[i] << " ";
            if (i == argc - 2)
                std::cout << "Number elements" << i + 1 << std::endl;
        }
        std::cout << std::endl << std::endl;
        std::cout << std::string(80, '-') << std::endl << std::endl;

		std::cout << "VECTOR TESTING" << std::endl;
        PmergeMe pmergeme;
        clock_t start_time_v = clock();
        Comparator comp = compare;
        std::vector<int> sorted = pmergeme.mergeInsertionSort(comp, unsorted);
        clock_t end_time_v = clock();

        //vector sorted
        std::cout << "After: ";
        for (size_t i = 0; i < sorted.size(); i++){

            std::cout << sorted[i] << " ";
            if (i == sorted.size() - 1)
                std::cout << "Number elements" << i + 1 << std::endl;
        }
        std::cout << std::endl << std::endl;
        for (size_t i = 0; i < sorted.size() - 1; i++){
            if (sorted[i] > sorted[i + 1]){
                std::cout << "incorret order" << std::endl;
                return 1;
            }
        }
        std::cout << "CHECK VECTOR ORDER - All in correct order!!!" << std::endl << std::endl;
        std::cout << "Time to process a range of " << nb_element << " elements with std::vector sort: " << ((double)(end_time_v - start_time_v) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;

        std::cout << std::string(80, '-') << std::endl;
		std::cout << "DEQUE TESTING" << std::endl << std::endl;
        clock_t start_time_d = clock();
        Comparator comp_d = compare;
        std::deque<int> sorted_d = pmergeme.mergeInsertionSort_deque(comp_d, deque);
        clock_t end_time_d = clock();

        std::cout << "After: ";
        for (size_t i = 0; i < sorted_d.size(); i++){
            std::cout << sorted_d[i] << " ";
            if (i == sorted.size() - 1)
                std::cout << "Number elements" << i + 1 << std::endl;
        }
        std::cout << std::endl << std::endl;

        // Check order
        for (size_t i = 0; i < sorted_d.size() - 1; i++){

            if (sorted_d[i] > sorted_d[i + 1]){
                std::cout << "incorret order" << std::endl;
                return 1;
            }
        }
        std::cout << "CHECK DEQUE ORDER - All in correct order!!!" << std::endl << std::endl;
        std::cout << "Time to process a range of " << nb_element << " elements with std::deque sort:   " << ((double)(end_time_d - start_time_d) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
        std::cout << std::string(80, '-') << std::endl;

        std::cout << std::string(80, '-') << std::endl;

        if (end_time_v - start_time_v > end_time_d - start_time_d)
            std::cout << "RESULT: std::deque is " << (end_time_v - start_time_v) - (end_time_d - start_time_d) << "us faster than std::vector" << std::endl;
        if (end_time_v - start_time_v < end_time_d - start_time_d)
            std::cout << "RESULT: std::vector is  " << (end_time_d - start_time_d) - (end_time_v - start_time_v) << "us faster than std::deque" << std::endl;
        if ((end_time_v - start_time_v) == (end_time_d - start_time_d))
            std::cout << "RESULT: std::vector and std::deque works in same time" << std::endl;
        std::cout << std::string(80, '-') << std::endl;
        std::cout << std::string(80, '-') << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
