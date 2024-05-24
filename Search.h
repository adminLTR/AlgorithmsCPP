#include<vector>
#include<functional>

class Search
{
private:
    
public:
    template <typename T, typename F = std::function<int (const T&, const T&)>>
    static bool linearSearch(std::vector<T>vector, T element, F func=[](const T&a, const T&b) { if (a==b) return 0; else if (a<b) return -1; else return 1; }) {
        for (int i=0; i<vector.size(); i++) {
            if (func(element, vector[i])==0)
            {
                return true;
            }            
        }
        return false;
    }
    template <typename T, typename F = std::function<int (const T&, const T&)>>
    static bool binarySearch(std::vector<T>vector, T element, int start=-1, int end=-1, F func=[](const T&a, const T&b) { if (a==b) return 0; else if (a<b) return -1; else return 1; }) {
        if(start==-1 && end==-1) {
            start = 0;
            end = vector.size()-1;
        }
        if (start<=end) {
            int middle = (start + end) / 2;
            int find = func(vector[middle], element);
            if (find == 0) {
                return true;
            } else if (find == 1) {
                return binarySearch(vector, element, start, middle-1, func);
            } else {
                return binarySearch(vector, element, middle+1, end, func);
            }
        } else {
            return false;
        }
    }
};