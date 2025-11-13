/**
 * @author - Kaitlyn Ashby
 * @file cache_manager.cpp - Implementation of the CacheManager class.
 * @date 2025-03-12
 */

#include "cache_manager.h"
#include "dll_node.h"

/**
 * @brief Returns the hash table.
 * @return HashTable* Pointer to the hash table.
 */
HashTable* CacheManager::getTable() {
    return hashTable;
}

/**
 * @brief Returns the FIFO list.
 * @return DoublyLinkedList* Pointer to the FIFO list.
 */
DoublyLinkedList* CacheManager::getList() {
    return doublyLinkedList;
}

/**
 * @brief Returns the number of items in the CacheManager.
 * @return int Number of items.
 */
int CacheManager::getSize() {
    return doublyLinkedList->getSize();
}

/**
 * @brief Checks if the CacheManager is empty.
 * @return true If the CacheManager is empty.
 * @return false If the CacheManager is not empty.
 */
bool CacheManager::isEmpty() {
    return doublyLinkedList->isEmpty();
}

/**
 * @brief Adds a new node to the CacheManager.
 * @param curKey Key of the node.
 * @param myNode Pointer to the node.
 * @return true If the node was added successfully.
 * @return false If the node could not be added.
 */
bool CacheManager::add(int curKey, DllNode* myNode) {
    if (hashTable->contains(curKey)) {
        return false;
    }
    if (doublyLinkedList->getSize() >= maxCacheSize) {
        DllNode* nodeToRemove = doublyLinkedList->tail;
        hashTable->remove(nodeToRemove->key);
        doublyLinkedList->removeTailNode();
    }
    doublyLinkedList->insertAtHead(curKey, myNode);
    HashNode* newHashNode = new HashNode(curKey, myNode);
    hashTable->add(curKey, newHashNode);
    return true;
}

/**
 * @brief Removes a node with the given key from the CacheManager.
 * @param curKey Key of the node to remove.
 * @return true If the node was removed successfully.
 * @return false If the node could not be found.
 */
bool CacheManager::remove(int curKey) {
    if (!hashTable->contains(curKey)) {
        return false;
    }
    DllNode* node = hashTable->getItem(curKey)->getFifoNode();
    doublyLinkedList->remove(node->key);
    hashTable->remove(curKey);
    return true;
}

/**
 * @brief Clears all entries from the CacheManager.
 */
void CacheManager::clear() {
    hashTable->clear();
    doublyLinkedList->clear();
}

/**
 * @brief Returns the node with the given key from the CacheManager.
 * @param curKey Key of the node to retrieve.
 * @return DllNode* Pointer to the node, or nullptr if not found.
 */
DllNode* CacheManager::getItem(int curKey) {
    if (!hashTable->contains(curKey)) {
        return nullptr;
    }
    return hashTable->getItem(curKey)->getFifoNode();
}

/**
 * @brief Returns the max size of the CacheManager.
 * @return int Max size of the CacheManager.
 */
int CacheManager::getMaxCacheSize() {
    return maxCacheSize;
}

/**
 * @brief Checks if a node with the given key exists in the CacheManager.
 * @param curKey Key to check.
 * @return true If the node exists.
 * @return false If the node does not exist.
 */
bool CacheManager::contains(int curKey) {
    return hashTable->contains(curKey);
}

/**
 * @brief Prints the contents of the CacheManager to the console and output file.
 */
void CacheManager::printCache() {
    std::ofstream outFile("generatedOutputFile.txt", std::ios_base::app);
    std::cout << "Printing out the cache contents\n\n";
    outFile << "Printing out the cache contents\n\n";

    std::cout << "Here are the FIFO List contents:\n";
    outFile << "Here are the FIFO List contents:\n";
    DllNode* current = doublyLinkedList->head;
    while (current != nullptr) {
        current->printNode();
        current = current->next;
    }
    std::cout << "End of FIFO List\n\n";
    outFile << "End of FIFO List\n\n";

    std::cout << "Here are the Hash Table contents (" << hashTable->getNumberOfItems() << " entries):\n\n";
    outFile << "Here are the Hash Table contents (" << hashTable->getNumberOfItems() << " entries):\n\n";
    hashTable->printTable();
}
