#include <unordered_map>
class LRUCache
{
private:
  struct Node
  {
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k, int v):
      key(k),
      value(v),
      prev(nullptr),
      next(nullptr)
    {
    }
  };
  int capacity;
  std::unordered_map< int, Node * > cache;
  Node *head;
  Node *tail;
  void moveToHead(Node *node)
  {
    if (node == head)
    {
      return;
    }
    if (node == tail)
    {
      tail = node->prev;
    }
    else
    {
      node->next->prev = node->prev;
    }
    node->prev->next = node->next;
    node->prev = nullptr;
    node->next = head;
    head->prev = node;
    head = node;
  }
  void removeTail()
  {
    cache.erase(tail->key);
    Node *prev = tail->prev;
    delete tail;
    tail = prev;
    if (tail != nullptr)
    {
      tail->next = nullptr;
    }
  }
public:
  LRUCache(int capacity):
    capacity(capacity),
    head(nullptr),
    tail(nullptr)
  {
  }
  int get(int key)
  {
    if (cache.find(key) == cache.end())
    {
      return -1;
    }
    Node *node = cache[key];
    moveToHead(node);
    return node->value;
  }
  void put(int key, int value)
  {
    if (cache.find(key) != cache.end())
    {
      Node *node = cache[key];
      node->value = value;
      moveToHead(node);
    }
    else
    {
      Node *newNode = new Node(key, value);
      cache[key] = newNode;
      if (head == nullptr)
      {
        head = newNode;
        tail = newNode;
      }
      else
      {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      }
      if (cache.size() > capacity)
      {
        removeTail();
      }
    }
  }
};
