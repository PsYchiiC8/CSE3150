// Created by Y. Wu, Jan 31, 2023
// Merge lists (of any STL container type) into a single sorted list (of any STL container type)
// Duplicates allowed unless the output doesn't take duplicates (e.g., a map)
// Note: you should make your code as flexible as possible: you should allow all kinds of outputs: vector, set, etc 
// Make your code short: at most 10 lines of code (LOC) 

// now define ECMergeContainers ...

#include <iostream>
#include <algorithm>

using namespace std;

template <typename ContainerIn, typename ContainerOut>
void ECMergeContainers(const ContainerIn& input, ContainerOut& output) {
    for (const auto &container : input) {
        for (const auto &element : container) {
            output.insert(output.end(), element);
        }
    }
    sort(output.begin(), output.end());
}
