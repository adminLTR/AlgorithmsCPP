#include <vector>
#include <functional>
class Sort
{
private:

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
                    aux = vector[i];
                    vector[i] = vector[j];
                    vector[j] = aux;
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
            aux = vector[smallest];
            vector[smallest] = vector[i];
            vector[i] = aux;
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
    static void mergeSort(std::vector<T>&vector, F func = [] (const T&a, const T&b) { return a>b; }) {
        
    }
};