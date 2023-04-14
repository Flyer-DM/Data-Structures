#include <iostream>

int main() {
/*
 * Example of realisation and using static arrays in C++ and their operations
 * (Arrays in C++ is already static, so there is no need to
 * implement a data structure from scratch)
 * */
    float k = 0.5f, b = -1.5f;
    int n = 10;  // array dimensionality

    auto* y = new float[n]; // array initialization
/*
 * Writing data into array for constant time: O(1)
 * because operation is simple command "array[index] = value"
 */
    for (int x = 0; x < n; x++) {
        y[x] = k * (float) x + b;
    }
/*
 * Reading data from array for constant time: O(1)
 * because operation is simple command "value = array[index]"
 */
    for (int x = 0; x < n; x++) {
        printf("%.2f ", y[x]);
    }
    printf("\n");

    delete[] y; // clearing memory


    // another example of different operations

    const int N = 20;  // array dimensionality
    char marks[N] = {2, 2, 3}; // array initialization
    int marks_number = 3;  // number of array values already written
    int index_insert = 1;  // index to insert an element
    int end = (marks_number < N ? marks_number : N - 1);
    /*
     * Inserting data into array for time depending on number of elements of the array: O(n).
     * This is because operation is loop for n elements in the array to move minus index of the array where
     * inserting will be, that means index is constant value that varies from 0 to n - 1.
     * The worst time will be if we insert into index equal zero, and we have already n - 1 elements in array,
     * so we have to move n - 1 elements to the new position.
     * Complexity of the algorithm: O(n - 1) = O(n).
     */
    // moving all elements after index to insert to the right before inserting new element
    for (int i = end; i > index_insert; i--) {
        marks[i] = marks[i - 1];
    }
    // inserting element in index
    marks[index_insert] = 4;
    // updating variable that contains number of array`s elements
    if(marks_number < N) marks_number++;

    for (int i = 0; i < marks_number; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");


    int index_delete = 0;
    /*
     * Delete data from array for time depending on number of elements of the array: O(n).
     * Operation complexity is similar to inserting element into array, because the worst situation is when we have to
     * move n - 1 element of the array.
     */
    // moving all elements to the left after index of deleting element (element is deleted automatically)
    for (int i = index_delete; i < marks_number; i++) {
        marks[i] = marks[i + 1];
    }
    // updating variable that contains number of array`s elements
    if(marks_number > 0) marks_number--;

    for (int i = 0; i < marks_number; i++) {
        printf("%d ", marks[i]);
    }

    return 0;
}
