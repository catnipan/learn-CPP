#include <algorithm>
#include <iostream>
#include "../util/print_int_array.h"

void bubbleSort1A(int array[], int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n; i++) {
            if (array[i-1] > array[i]) {
                std::swap(array[i - 1], array[i]);
                sorted = false;
            }
        }
        n--;
    }
}

int main() {
    int testArray[] = {7,6,5,4,3,2,1};
    const int len = sizeof(testArray) / sizeof(*testArray);
    print(testArray, len);
    bubbleSort1A(testArray, len);
    // std::cout << *testArray << std::endl;
    // TODO: toggle the above line will make print result different, wtf??
    print(testArray, len);
}

// g++ bubbleSort.cpp ../util/print_int_array.cpp -o ../build/bubbleSort && ../build/bubbleSort