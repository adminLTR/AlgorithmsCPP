#include<iostream>
#include<vector>
#include "Sort.h"

int main(int argc, char const *argv[])
{
    std::vector<int>v = {1, 67, 19, 3, 5, 62, 31};
    Sort::selectionSort(v);

    for (auto &&i : v)
    {
        std::cout<<i<<" ";
    }
    
    return 0;
}
