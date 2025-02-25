#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <vector>
#include <utility>  // For std::pair
#include <stdexcept>
#include <functional>  // For std::hash
#include <string>

template <typename K, typename V>
class HashTable {
private:
    // Entry status: EMPTY, OCCUPIED, or DELETED
    enum EntryStatus { EMPTY, OCCUPIED, DELETED };
    
    // Entry structure to store key-value pairs and status
    struct Entry {
        K key;
        V value;
        EntryStatus status;
        
        Entry() : status(EMPTY) {}
    };
    
    std::vector<Entry> table;      // Array to store entries
    size_t num_elements;           // Number of elements stored
    double load_factor_threshold;  // Threshold for resizing
    
    // Hash function to get index from key
    size_t hash_function(const K& key) const {
        std::hash<K> hasher;
        return hasher(key) % table.size();
    }
    
    // Rehash the table when it gets too full
    void rehash() {
        std::vector<Entry> old_table = table;
        
        // Double the size of the table
        table = std::vector<Entry>(old_table.size() * 2);
        num_elements = 0;
        
        // Reinsert all elements
        for (const auto& entry : old_table) {
            if (entry.status == OCCUPIED) {
                insert(entry.key, entry.value);
            }
        }
    }
    
    // Find the index for a key (for internal use)
    size_t find_index(const K& key) const {
        size_t index = hash_function(key);
        size_t original_index = index;
        size_t i = 0;
        
        // Linear probing to handle collisions
        do {
            if (table[index].status == EMPTY) {
                return table.size();  // Key not found
            }
            
            if (table[index].status == OCCUPIED && table[index].key == key) {
                return index;  // Key found
            }
            
            // Move to the next slot (with wrapping)
            i++;
            index = (original_index + i) % table.size();
        } while (index != original_index);
        
        return table.size();  // Table is full and key not found (should not happen)
    }
    
public:
    // Constructor with initial capacity and load factor
    HashTable(size_t initial_capacity = 16, double load_factor = 0.75)
        : table(initial_capacity), num_elements(0), load_factor_threshold(load_factor) {}
    
    // Insert or update a key-value pair
    void insert(const K& key, const V& value) {
        // Check if we need to resize
        if (static_cast<double>(num_elements + 1) / table.size() > load_factor_threshold) {
            rehash();
        }
        
        // Find the index to insert
        size_t index = hash_function(key);
        size_t original_index = index;
        size_t i = 0;
        size_t first_deleted = table.size();  // To track first deleted slot
        
        // Find the right spot for insertion
        do {
            // If we find an empty slot or a slot with the same key, use it
            if (table[index].status == EMPTY) {
                break;
            }
            
            // Track the first deleted slot we see
            if (table[index].status == DELETED && first_deleted == table.size()) {
                first_deleted = index;
            }
            
            // If we find the same key, update it
            if (table[index].status == OCCUPIED && table[index].key == key) {
                table[index].value = value;
                return;
            }
            
            // Move to the next slot (with wrapping)
            i++;
            index = (original_index + i) % table.size();
        } while (index != original_index);
        
        // If we found a deleted slot earlier, use that instead
        if (first_deleted != table.size()) {
            index = first_deleted;
        }
        
        // Insert the new entry
        table[index].key = key;
        table[index].value = value;
        table[index].status = OCCUPIED;
        num_elements++;
    }
    
    // Remove a key-value pair
    bool remove(const K& key) {
        size_t index = find_index(key);
        
        if (index == table.size()) {
            return false;  // Key not found
        }
        
        // Mark the entry as deleted
        table[index].status = DELETED;
        num_elements--;
        return true;
    }
    
    // Get value for a key
    V get(const K& key) const {
        size_t index = find_index(key);
        
        if (index == table.size()) {
            throw std::out_of_range("Key not found in hash table.");
        }
        
        return table[index].value;
    }
    
    // Check if a key exists
    bool contains(const K& key) const {
        return find_index(key) != table.size();
    }
    
    // Get the number of elements
    size_t size() const {
        return num_elements;
    }
    
    // Check if the hash table is empty
    bool is_empty() const {
        return num_elements == 0;
    }
    
    // Clear the hash table
    void clear() {
        table = std::vector<Entry>(table.size());
        num_elements = 0;
    }
};

#endif 