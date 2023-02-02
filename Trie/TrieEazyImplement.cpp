#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *links[26];
    bool isEnd = false;
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->links[word[i] - 'a'])
                curr->links[word[i] - 'a'] = new TrieNode();
            curr = curr->links[word[i] - 'a'];
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->links[word[i] - 'a'])
                return false;
            curr = curr->links[word[i] - 'a'];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!curr->links[prefix[i] - 'a'])
                return false;
            curr = curr->links[prefix[i] - 'a'];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("hello");
    cout << trie.search("hello");
    cout << trie.startsWith("hello");
    cout << trie.search("hel");
    cout << trie.startsWith("hp");

    return 0;
}