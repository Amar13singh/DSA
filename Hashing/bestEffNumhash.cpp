#include <iostream>
#include <vector>
#include <unordered_map>
 

//best code for hashing using input separated by space
//input separated by space 1 2 3 4 5 6 7 8 9 10 -1
int main() {
    std::vector<int> arr;
    std::cout << "Enter numbers (type -1 to stop): ";//give input separated by space
    int num;
    
    while (std::cin >> num && num != -1) {
        arr.push_back(num);
    }

    // Precompute frequency using an unordered_map
    //array is more efficient if input is smaller
    std::unordered_map<int, int> hash;
    for (int i = 0; i < arr.size(); i++) {
        hash[arr[i]]++;
    }

    // Queries for the number of occurrences
    int q;
    std::cout << "Enter the number of queries: ";
    std::cin >> q;

    while (q--) {
        int number;
        std::cout << "Enter the number: ";
        std::cin >> number;
        
        // Check if the number exists in the map
        if (hash.find(number) != hash.end()) {
            std::cout << hash[number] << std::endl;
        } else {
            std::cout << "0" << std::endl;
        }
    }

    return 0;
}
