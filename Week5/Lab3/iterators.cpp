#include <iostream>
#include <vector>
#include <algorithm>


/**
 * Filter and Copy:
 * Given a vector of elements, filter out the elements that match the filter value and copy the rest to the output vector.
 * Use a template to do this for any container type.
 * @param input The input vector
 * @param output The output vector
 * @param filterValue The value to filter out
 */
template <typename T>
void filterAndCopy(const std::vector<T>& input, std::vector<T>& output, const T& filterValue) {
     std::copy_if(input.begin(), input.end(), std::back_inserter(output),
                  [filterValue](const T& element) { return element != filterValue; });
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 3, 6, 7, 8, 3};
    std::vector<int> filteredNumbers;

    int filterValue = 3;
    filterAndCopy(numbers, filteredNumbers, filterValue);

    std::cout << "Original Numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }

    // Show that the filtered value is removed from the numbers vector
    std::cout << "\nFiltered Numbers (excluding " << filterValue << "): ";
    for (const auto& num : filteredNumbers) {
        std::cout << num << " ";
    }

    return 0;
}
