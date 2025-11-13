/**
 * @author - Kaitlyn Ashby
 * @file hash_table.cpp - Implementation of the HashTable class.
 * @date 2025-03-12
 */

#include "hash_table.h"
#include <iostream> // Add this line to include iostream
#include <fstream> // Add this line to include fstream

/**
 * @brief Returns the hash table.
 * @return HashNode** Pointer to the hash table.
 */
HashNode** HashTable::getTable() {
    return table;
}

/**
 * @brief Returns the size of the hash table.
 * @return int Size of the hash table.
 */
int HashTable::getSize() {
    return numberOfBuckets;
}

/**
 * @brief Calculates the hash code for the given key.
 * @param currentKey Key to hash.
 * @return int Hash code.
 */
int HashTable::calculateHashCode(int currentKey) {
    return currentKey % numberOfBuckets;
}

/**
 * @brief Checks if the hash table is empty.
 * @return true If the hash table is empty.
 * @return false If the hash table is not empty.
 */
bool HashTable::isEmpty() {
    return numberOfItems == 0;
}

/**
 * @brief Returns the number of items in the hash table.
 * @return int Number of items.
 */
int HashTable::getNumberOfItems() {
    return numberOfItems;
}

/**
 * @brief Adds a new node to the hash table.
 * @param curKey Key of the node.
 * @param myNode Pointer to the node.
 * @return true If the node was added successfully.
 * @return false If the node could not be added.
 */
bool HashTable::add(int curKey, HashNode* myNode) {
    int hashCode = calculateHashCode(curKey);
    myNode->hashCode = hashCode;

    if (table[hashCode] == nullptr) {
        table[hashCode] = myNode;
    } else {
        HashNode* current = table[hashCode];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = myNode;
        myNode->prev = current;
    }
    numberOfItems++;
    return true;
}

/**
 * @brief Removes a node with the given key from the hash table.
 * @param curKey Key of the node to remove.
 * @return true If the node was removed successfully.
 * @return false If the node could not be found.
 */
bool HashTable::remove(int curKey) {
    int hashCode = calculateHashCode(curKey);
    HashNode* current = table[hashCode];

    while (current != nullptr) {
        if (current->key == curKey) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                table[hashCode] = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
            numberOfItems--;
            return true;
        }
        current = current->next;
    }
    return false;
}

/**
 * @brief Clears all entries from the hash table.
 */
void HashTable::clear() {
    for (int i = 0; i < numberOfBuckets; i++) {
        HashNode* current = table[i];
        while (current != nullptr) {
            HashNode* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        table[i] = nullptr;
    }
    numberOfItems = 0;
}

/**
 * @brief Returns the node with the given key.
 * @param curKey Key of the node to retrieve.
 * @return HashNode* Pointer to the node, or nullptr if not found.
 */
HashNode* HashTable::getItem(int curKey) {
    int hashCode = calculateHashCode(curKey);
    HashNode* current = table[hashCode];

    while (current != nullptr) {
        if (current->key == curKey) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

/**
 * @brief Checks if a node with the given key exists in the hash table.
 * @param curKey Key to check.
 * @return true If the node exists.
 * @return false If the node does not exist.
 */
bool HashTable::contains(int curKey) {
    return getItem(curKey) != nullptr;
}

/**
 * @brief Prints the contents of the hash table to the console and output file.
 */
void HashTable::printTable() {
    std::ofstream outFile("generatedOutputFile.txt", std::ios_base::app);
    std::cout << "Here are the Hash Table contents (" << numberOfItems << " entries):\n\n";
    outFile << "Here are the Hash Table contents (" << numberOfItems << " entries):\n\n";

    for (int i = 0; i < numberOfBuckets; i++) {
        if (table[i] == nullptr) {
            std::cout << "Bucket " << i << ": Empty\n";
            outFile << "Bucket " << i << ": Empty\n";
        } else {
            HashNode* current = table[i];
            std::cout << "Bucket " << i << ":\n";
            outFile << "Bucket " << i << ":\n";
            while (current != nullptr) {
                current->printNode();
                current = current->next;
            }
        }
    }

    std::cout << "End of table\n\n";
    outFile << "End of table\n\n";
}