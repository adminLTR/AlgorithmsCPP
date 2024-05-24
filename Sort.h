#include <vector>
#include <functional>
class Sort
{
private:
    template <typename T>
    static void swap(T&a, T&b) {
        T aux = a;
        a = b;
        b = aux;
    }
    template <typename T, typename F>
    static void merge(std::vector<T>&vector, int left, int middle, int right, F func) {
        std::vector<T> leftVector = std::vector<T>();
        std::vector<T> rightVector = std::vector<T>();
        int k = left;
        for (int i = left; i <= middle; i++)
        {
            leftVector.push_back(vector[i]);
            std::cout<<vector[i]<<" ";
        }
        for (int i = middle+1; i <= right; i++)
        {
            rightVector.push_back(vector[i]);
            std::cout<<vector[i]<<" ";
        }
        int i = 0;
        int j = 0;
        while (i<leftVector.size() && j<rightVector.size())
        {
            if (func(rightVector[j], leftVector[i]))
            {
                vector[k] = leftVector[i];
                i++;
            } else {
                vector[k] = rightVector[j];
                j++;
            }
            k++;
        }
        while (i<leftVector.size())
        {
            vector[k] = leftVector[i];
            i++;
            k++;
        }
        while (j<rightVector.size())
        {
            vector[k] = rightVector[j];
            j++;
            k++;
        } 
    }
    template <typename T, typename F = std::function<bool(const T&, const T&)>>
    static void heapify(std::vector<T>&vector, int n, int i, F func) {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        T aux;
        if (left<n && func(vector[left], vector[largest]))
        {
            largest = left;
        }
        if (right<n && func(vector[right], vector[largest]))
        {
            largest = right;
        }
        if (largest!=i)
        {
            swap(vector[largest], vector[i]);
            heapify(vector, n, largest, func);
        }        
    }
public:
    /**
     * 
    */
    template <typename T, typename F = std::function<bool(const T&, const T&)>>
    static void bubbleSort(std::vector<T>&vector, F func = [](const T& a, const T& b) { return a > b; }){
        T aux;
        for (int i = 0; i < vector.size()-1; i++)
        {
            for (int j = i+1; j < vector.size(); j++)
            {
                if (func(vector[i], vector[j]))
                {
                    swap(vector[i], vector[j]);
                } 
            }            
        }        
    }
    /**
     * This method consists on SELECTING the smallest element in the list. In each iteration, 
     * you find this smallest element and change it with the current one
    */
    template <typename T, typename F = std::function<bool(const T&, const T&)>>
    static void selectionSort(std::vector<T>&vector, F func = [](const T& a, const T& b) { return a > b; }) {
        T smallest;
        T aux;
        for (int i = 0; i < vector.size()-1; i++)
        {
            smallest = i;
            for (int j = i+1; j < vector.size(); j++)
            {
                if (func(vector[smallest], vector[j]))
                {
                    smallest = j;
                }
            }            
            swap(vector[smallest], vector[i]);
        }        
    }
    template<typename T, typename F = std::function<bool(const T&, const T&)>>
    static void insertionSort(std::vector<T>&vector, F func = [](const T& a, const T& b) { return a>b; }) {
        T key;
        int j;
        for (int i = 1; i < vector.size(); i++)
        {
            j = i - 1;
            key = vector[i];
            while (j>=0 && vector[j]>key) {
                vector[j+1] = vector[j];
                j--;
            }
            vector[j+1] = key;
        }
    }
    template<typename T, typename F = std::function<bool(const T&, const T&)>>
    static void mergeSort(std::vector<T>&vector, int left = 0, int right = -1, F func = [] (const T&a, const T&b) { return a>b; }) {
        right = right==-1?vector.size()-1:right;
        if (left<right)
        {
            const int middle = (left+right)/2;
            mergeSort(vector, left, middle, func);
            mergeSort(vector, middle+1, right, func);   
            merge(vector, left, middle, right, func);
        }
    }
    // matriz = [[0 for i in range(9)] for j in range(9)]
    template<typename T, typename F = std::function<bool(const T&, const T&)>>
    static void heapSort(std::vector<T>&vector, F func = [](const T&a, const T&b){ return a>b; }) {
        int n = vector.size();
        for (int i = n/2-1; i >= 0; i--)
        {
            heapify(vector, n, i, func);
        }
        for (int i = n - 1; i > 0; i--)
        {
            swap(vector[i], vector[0]);
            heapify(vector, i, 0, func);
        }
        
    }
};