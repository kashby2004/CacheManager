/**
*
* hash_node.cpp : This implementation file contains the methods declared in the hash_node.h file.
*
* 09/23/24 - Created by ChatGPT
* 10/17/24 - Modified by jhui
* 01/11/25 - Modified by hhui; 1) 1) added calculateHashCode, 2) modified methods to include hash table size parameter
*/

#include "hash_node.h"
#include "dll_node.h"

// Constructor to initialize a new node with values
HashNode::HashNode(int val, DllNode* myFifoNode) : key(val), fifoNode(myFifoNode), prev(nullptr), next(nullptr) {}

DllNode* HashNode::getFifoNode() {
	return fifoNode;
}

void HashNode::printNode() {
	bool verbose = false;
	if (verbose) {
		logToFileAndConsole("FIFO info from cacheManager.  Node key: " + std::to_string(key) + "; name: " + fifoNode->fullName + "; address: " + fifoNode->address + "; city: " + fifoNode->city + "; state: " + fifoNode->state + "; zip: " + fifoNode->zip);
	}
	else {
		logToFileAndConsole("FIFO info from cacheManager:  Node key: " + std::to_string(key));
	}
}