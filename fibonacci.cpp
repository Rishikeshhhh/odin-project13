#include <iostream>
#include <vector>

std::vector<int> fibsRecHelper(int n, int a, int b, std::vector<int> &sequence) {
    if (n == 0) {
        return sequence;
    }
    if (sequence.size() == 0) {
        sequence.push_back(a);
    } else if (sequence.size() == 1) {
        sequence.push_back(b);
    } else {
        sequence.push_back(sequence[sequence.size() - 1] + sequence[sequence.size() - 2]);
    }
    return fibsRecHelper(n - 1, a, b, sequence);
}

std::vector<int> fibsRec(int n) {
    std::vector<int> sequence;
    return fibsRecHelper(n, 0, 1, sequence);
}

int main() {
    std::vector<int> result = fibsRec(8);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
