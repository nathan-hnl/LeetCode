/*
 *
 Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

 Implement the LRUCache class:

 LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
 void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 The functions get and put must each run in O(1) average time complexity.
*/
#include <unordered_map>

using namespace std;

struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev, *next;
    DLinkedNode():key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int key_, int value_):key(key_), value(value_), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cacheMap;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int capacity_)
    : capacity(capacity_)
    , size(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key)
    {
        if (!cacheMap.count(key))
        {
            return -1;
        }
        DLinkedNode* node = cacheMap[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value)
    {
        if (!cacheMap.count(key))
        {
            DLinkedNode* node =  new DLinkedNode(key, value);
            cacheMap[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity)
            {
                DLinkedNode* removedNode = removeTail();
                cacheMap.erase(removedNode->key);
                delete removedNode;
                removedNode = nullptr;
                --size;
            }
        }
        else
        {
            DLinkedNode* node = cacheMap[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node)
    {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail()
    {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};