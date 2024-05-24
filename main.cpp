#include<iostream>
#include<vector>
#include "Sort.h"
#include "Search.h"

int main(int argc, char const *argv[])
{
    std::vector<int>v = {1, 67, 19, 3, 5, 62, 31};
    Sort::quickSort(v);

    for (auto &&i : v)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    int x;
    std::cin >> x;
    std::cout << Search::binarySearch(v, x);
    
    return 0;
}
