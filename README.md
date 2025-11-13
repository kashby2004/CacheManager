# CacheManager
C++ cache management system implementing a FIFO list and hash table for efficient data storage and retrieval. Includes modular classes for CacheManager, DoublyLinkedList, and HashTable with JSON-based configuration, test files, and automatic output/error logging.

## Project Structure

| File | Description |
|------|--------------|
| **cache_manager.h** | Header file containing the `CacheManager` class definition |
| **cache_manager.cpp** | Implements cache manager methods including `add`, `remove`, `clear`, `getItem`, and `contains` |
| **dll_node.cpp / dll_node.h** | Implementation and structure definition for doubly linked list nodes |
| **doubly_linked_list.h / doubly_linked_list.cpp** | Doubly linked list class with methods for insertion, removal, movement, and clearing |
| **hash_node.cpp / hash_node.h** | Implementation and structure definition for hash table nodes |
| **hash_table.h / hash_table.cpp** | Hash table class implementing core operations like hashing, insertion, lookup, and deletion |
| **json.hpp** | JSON processing library |
| **milestone3.json** | Input file containing test cases and transactions |
| **milestone3_config.json** | Configuration file specifying input, output, and error log paths |
| **generatedOutputFile.txt** | Example output file showing generated results |
| **milestone3.cpp** | Main program that loads configuration, processes test cases, and writes outputs |

---

## Core Components

### CacheManager
Manages the cache using both a hash table and a FIFO list.

**Methods:**
- `getTable()` – Returns the hash table  
- `getList()` – Returns the FIFO list  
- `getSize()` / `isEmpty()` – Get cache size or check if empty  
- `add()` / `remove()` / `clear()` – Manage cache entries  
- `getItem()` – Retrieve an item by key  
- `getMaxCacheSize()` – Return max cache capacity  
- `contains()` – Check if a key exists  

---

### DoublyLinkedList
Provides FIFO list operations and maintains order of cache entries.

**Methods:**
- `getSize()`, `isEmpty()`  
- `insertAtHead()`, `insertAtTail()`  
- `remove()`, `removeHeaderNode()`, `removeTailNode()`  
- `moveNodeToHead()`, `moveNodeToTail()`  
- `clear()`  

---

### HashTable
Implements fast key-based storage and lookup.

**Methods:**
- `getTable()`, `getSize()`, `isEmpty()`  
- `calculateHashCode()` – Compute hash key  
- `getNumberOfItems()` – Return item count  
- `add()`, `remove()`, `clear()`  
- `getItem()` – Retrieve item pointer  
- `contains()` – Check if key exists  

---

## 🧩 How It Works

1. The program reads **`milestone3_config.json`** to retrieve:
   - Input file path (test cases)  
   - Output file path  
   - Error log file path  

2. **Test cases** from `milestone3.json` are processed by the `CacheManager`.

3. Results are written to `generatedOutputFile.txt`, and errors (if any) are logged separately.

---

## 🚀 Usage

```bash
# Compile
g++ milestone3.cpp cache_manager.cpp hash_table.cpp doubly_linked_list.cpp dll_node.cpp hash_node.cpp -o cache_manager

# Run
./cache_manager
