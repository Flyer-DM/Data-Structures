#include <iostream>
#include <vector>

template<typename T>
void print(std::vector<T> const &v)
{
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<T> vec(first, last);
    return vec;
}

int main() {
    /*
     * Example of realisation and using dynamic arrays in C++ and their operations
     */
    std::vector<double> digits = {1.0, 1.1, 1.2}; // array initialization
    std::vector<double> vector2 = {2.0, 2.1, 2.2};
    digits.reserve(20);

    /*
     * Writing data into dynamic array (in the end) for constant time: O(1).
     * Because command is based on Static array: array[index] = value
     */
    digits.push_back(2.0);

    /*
     * There are logical size of array (users data) and physical size of array:
     * number of cells in memory allocated for this data structure.
     */
    std::cout << "Logical size: " << digits.size() << std::endl;
    std::cout << "Physical size: " << digits.capacity() << std::endl;

    /*
     * Reading data from array for constant time: O(1).
     * Because command is based on Static array: value = array[index]
     */
    for (double digit : digits) {
        printf("%.2f ", digit);
    }

    /*
     * Inserting data into array for time depending on number of elements of the array: O(n).
     * This is because dynamic arrays use static ones in origin, so the time
     * of such operation is same.
     */
    digits.insert( digits.begin() + 1, 2.0 );
    print(digits);

    /*
     * Delete data from array for time depending on number of elements of the array: O(n).
     * This is because dynamic arrays use static ones in origin, so the time
     * of such operation is same.
     */
    digits.erase(digits.begin() + 1);
    print(digits);

    /*
     * Concatenating arrays executes depending on number of elements in both arrays: O(n + m).
     * This is because firstly new memory space is allocated for number of elements in first
     * array (n) plus number of elements in second array (m). After that all elements got copy
     * into new list.
     */
    digits.insert(digits.end(), vector2.begin(), vector2.end());
    print(digits);

    /*
     * Getting slice of list depends on number of elements in list: O(n).
     * This is because generally we can make slice of whole list, all its n elements.
     */
    int start = 1, end = 5;
    std::vector<double> sliced_array = slice(digits, start, end);
    print(sliced_array);

    /*
     * Clearing memory
     */
    digits.clear();
    digits.shrink_to_fit();

    return 0;
}