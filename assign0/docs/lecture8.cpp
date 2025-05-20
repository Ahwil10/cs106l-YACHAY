#include <iostream>
#include <cstdlib>
#include <concepts>
#include <type_traits>
using namespace std;

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T maxValue(T a, T b, T c) {
    return maxValue(maxValue(a,b),c);
}

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << maxValue(5, 10) << endl;
    cout << maxValue(3.5, 2.1) << endl;
    cout << maxValue(string("apple"), string("orange")) << endl;
    cout << maxValue(1, 5, 3) << endl;          // Should print 5
    cout << maxValue(2.1, 3.7, 1.9) << endl; 
    return 0;
}