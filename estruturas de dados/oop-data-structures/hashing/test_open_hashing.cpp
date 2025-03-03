#include <iostream>
#include <optional>
#include "open_hashing.hpp"

int main() {
    // Create a hash table with default size (10)
    HashTable hashTable;
    
    // Test with user input
    std::cout << "Enter number of elements to insert: ";
    int n;
    std::cin >> n;
    
    std::cout << "Enter " << n << " pairs of key-value (key value):\n";
    for (int i = 0; i < n; i++) {
        int key, value;
        std::cin >> key >> value;
        hashTable.inserir(key, value);
    }
    
    // Print the hash table
    std::cout << "\nHash Table Contents:\n";
    hashTable.imprimir();
    
    // Test search functionality
    std::cout << "\nEnter a key to search: ";
    int searchKey;
    std::cin >> searchKey;
    
    auto result = hashTable.buscar(searchKey);
    if (result.has_value()) {
        std::cout << "Found: Key = " << searchKey << ", Value = " << result.value() << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found in the hash table." << std::endl;
    }
    
    // Test with predefined values
    std::cout << "\n--- Testing with predefined values ---\n";
    HashTable testTable(5); // Create a smaller table for demonstration
    
    int testKeys[] = {10, 21, 32, 15, 7, 12, 13, 42};
    int testValues[] = {100, 210, 320, 150, 70, 120, 130, 420};
    int numValues = sizeof(testKeys) / sizeof(testKeys[0]);
    
    for (int i = 0; i < numValues; i++) {
        testTable.inserir(testKeys[i], testValues[i]);
        std::cout << "Inserted: Key = " << testKeys[i] << ", Value = " << testValues[i] << std::endl;
    }
    
    std::cout << "\nTest Hash Table Contents:\n";
    testTable.imprimir();
    
    // Test a few searches
    int searchTestKeys[] = {21, 50, 7};
    for (int key : searchTestKeys) {
        auto val = testTable.buscar(key);
        if (val.has_value()) {
            std::cout << "Search: Key = " << key << ", Found Value = " << val.value() << std::endl;
        } else {
            std::cout << "Search: Key = " << key << ", Not found" << std::endl;
        }
    }
    
    return 0;
}
