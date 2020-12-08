#include <iostream>
#include <list>
int main() {
    // Create an empty list of ints
    std::list<int> listOfInts;
    // Push back 10 elements in the list
    for (int i = 0; i < 10; i++)
        listOfInts.push_back(i);
    // Iterate over the list and display numbers
    for (int val : listOfInts)
        std::cout << val << ",";
    std::cout << std::endl;
    std::cout << listOfInts.size();
    return 0;
}
