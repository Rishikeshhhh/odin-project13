#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right) {
    std::vector<int> result;
    unsigned left_index = 0, right_index = 0;

    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] < right[right_index]) {
            result.push_back(left[left_index]);
            left_index++;
        } else {
            result.push_back(right[right_index]);
            right_index++;
        }
    }

    while (left_index < left.size()) {
        result.push_back(left[left_index]);
        left_index++;
    }

    while (right_index < right.size()) {
        result.push_back(right[right_index]);
        right_index++;
    }

    return result;
}

std::vector<int> mergeSort(const std::vector<int> &arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    unsigned mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    return merge(mergeSort(left), mergeSort(right));
}

int main() {
    std::vector<int> arr1 = {3, 2, 1, 13, 8, 5, 0, 1};
    std::vector<int> sorted_arr1 = mergeSort(arr1);
    for (int num : sorted_arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = {105, 79, 100, 110};
    std::vector<int> sorted_arr2 = mergeSort(arr2);
    for (int num : sorted_arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
