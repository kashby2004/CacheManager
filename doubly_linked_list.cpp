/**
 * @author - Kaitlyn Ashby
 * @file doubly_linked_list.cpp - Implementation of the DoublyLinkedList class.
 * @date 2025-03-12
 */

#include "doubly_linked_list.h"
#include "dll_node.h"

/**
 * @brief Default constructor to initialize an empty doubly linked list.
 */
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

/**
 * @brief Destructor to clear the list.
 */
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

/**
 * @brief Returns the number of entries in the list.
 * @return int Number of entries in the list.
 */
int DoublyLinkedList::getSize() {
    return size;
}

/**
 * @brief Checks if the list is empty.
 * @return true If the list is empty.
 * @return false If the list is not empty.
 */
bool DoublyLinkedList::isEmpty() {
    return head == nullptr;
}

/**
 * @brief Inserts a new node at the head of the list.
 * @param key Key of the new node.
 * @param newNode Pointer to the new node.
 */
void DoublyLinkedList::insertAtHead(int key, DllNode* newNode) {
    newNode->key = key;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    size++;
}

/**
 * @brief Inserts a new node at the tail of the list.
 * @param key Key of the new node.
 * @param newNode Pointer to the new node.
 */
void DoublyLinkedList::insertAtTail(int key, DllNode* newNode) {
    newNode->key = key;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    size++;
}

/**
 * @brief Removes a node with the specific key from the list.
 * @param key Key of the node to remove.
 */
void DoublyLinkedList::remove(int key) {
    DllNode* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

/**
 * @brief Removes the header node (first node).
 */
void DoublyLinkedList::removeHeaderNode() {
    if (head == nullptr) {
        return;
    }
    DllNode* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    size--;
}

/**
 * @brief Removes the tail node (last node).
 */
void DoublyLinkedList::removeTailNode() {
    if (tail == nullptr) {
        return;
    }
    DllNode* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    size--;
}

/**
 * @brief Moves a specific node to the head of the list.
 * @param key Key of the node to move.
 */
void DoublyLinkedList::moveNodeToHead(int key) {
    DllNode* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                return;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            current->prev = nullptr;
            current->next = head;
            head->prev = current;
            head = current;
            return;
        }
        current = current->next;
    }
}

/**
 * @brief Moves a specific node to the tail of the list.
 * @param key Key of the node to move.
 */
void DoublyLinkedList::moveNodeToTail(int key) {
    DllNode* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                return;
            }
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            current->next = nullptr;
            current->prev = tail;
            tail->next = current;
            tail = current;
            return;
        }
        current = current->next;
    }
}

/**
 * @brief Clears the list by deleting all nodes.
 */
void DoublyLinkedList::clear() {
    DllNode* current = head;
    while (current != nullptr) {
        DllNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * @brief Prints the list from head to tail.
 */
void DoublyLinkedList::printList() {
    DllNode* current = head;
    while (current != nullptr) {
        current->printNode();
        current = current->next;
    }
}

/**
 * @brief Prints the list from tail to head.
 */
void DoublyLinkedList::reversePrintList() {
    DllNode* current = tail;
    while (current != nullptr) {
        current->printNode();
        current = current->prev;
    }
}