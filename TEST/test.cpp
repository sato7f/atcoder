#include <functional>
#include <iostream>

/*
std::function<int(int)> createMultiple(int mp) {
    return [mp](int i) { return i * mp; };
}
*/



int main() {
    auto createMultiple = [](int i) { return i * 2; };
    auto triple = createMultiple(3);
    auto quadruple = createMultiple(4);
    int x = 2;
    std::cout << x << "の三倍は" << triple(x) << "で、四倍は" << quadruple(x)
              << "です" << std::endl;
    return 0;
}
