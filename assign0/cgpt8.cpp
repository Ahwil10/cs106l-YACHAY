#include <iostream>
#include <concepts>

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
    concept Numeric = std::integral<T> || std::floating_point<T>;
}




template <Numeric T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Max of 3, 5: " << maxValue(3, 5) << '\n';
    std::cout << "Max of 3.2, 5.6, 4.8: " << maxValue(3.2, 5.6, 4.8) << '\n';
    std::cout << "Sum of 4 and 7: " << add(4, 7) << '\n';
    return 0;
}