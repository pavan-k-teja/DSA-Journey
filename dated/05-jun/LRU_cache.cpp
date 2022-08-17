// Leetcode: 146

#include <iostream>
#include <unordered_map>

using namespace std;

// Doubly LinkedList Node Class Definition :
class DLL
{
public:
    int key;
    int val;
    DLL *prev;
    DLL *next;

    DLL(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
    int capacity;
    int size;

    DLL *head;
    DLL *tail;

    unordered_map<int, DLL *> umap;

    void deleteNode(DLL *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // node->prev = node->next = nullptr;
        delete node;
        size--;
    }

    void addFirst(int key, int val)
    {
        DLL *node = new DLL(key, val);
        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        node->prev->next = node;
        size++;
    }

public:
    LRUCache(int cap)
    {
        capacity = cap;
        size = 0;

        head = new DLL(-1, -1);
        tail = new DLL(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (umap.empty() || umap.find(key) == umap.end())
            return -1;

        DLL *node = umap[key];
        int res = node->val;
        umap.erase(key);

        deleteNode(node);
        addFirst(key, res);
        umap[key] = head->next;

        return res;
    }

    void put(int key, int value)
    {
        if (umap.find(key) != umap.end())
        {
            deleteNode(umap[key]);
            umap.erase(key);
        }

        if (size == capacity)
        {
            umap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addFirst(key, value);
        umap[key] = head->next;
    }
};