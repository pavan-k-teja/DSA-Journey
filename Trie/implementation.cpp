#include <bits/stdc++.h>
using namespace std;

class Node // fully encapsulated class = all private data members
{
private:
    Node *links[26];
    bool flag = false;

public:
    // checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // creating reference trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // setting flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }

    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};


class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // creating new obejct
        root = new Node();
    }

    void insert(string word)
    {
        // initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("hello");
    cout<< trie.search("hello");
    cout<< trie.startsWith("hello");
    cout<< trie.search("hel");
    cout<< trie.startsWith("hp");


    return 0;
}