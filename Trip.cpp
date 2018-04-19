#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define MAX_CHILD 26
class TrieNode {
    public:
        class TrieNode * child[MAX_CHILD];
        int node_stat;
        TrieNode() {
            for (int i = 0; i < MAX_CHILD; ++i) {
                child[i] = NULL;


            }
            node_stat = 0;

        }
        ~TrieNode(){
            for (int i = 0; i < MAX_CHILD; ++i) {
                if (child[i] != NULL)
                {
                    delete child[i];

                }


            }


        }

};

class Trie {
    public:
        /** Initialize your data structure here. */
        Trie() {
            root = new TrieNode();


        }
        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode* p = root;
            for (size_t i = 0; i < word.length(); ++i) {
                int index = (word[i] - 'a') % MAX_CHILD;
                if (p->child[index] == NULL) {
                    p->child[index] = new TrieNode();

                }
                p = p->child[index];


            }
            p->node_stat = 1;


        }
        /** Returns if the word is in the trie. */
        bool search(string word) {
            TrieNode* p = root;
            for (size_t i = 0; i < word.length(); ++i) {
                int index = (word[i] - 'a') % MAX_CHILD;
                if (p->child[index] == NULL)
                    return false;
                p = p->child[index];


            }
            if (p->node_stat == 1)
                return true;
            return false;


        }
        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            TrieNode * p = root;
            for (size_t i = 0; i < prefix.length(); ++i) {
                int index = (prefix[i] - 'a')  % MAX_CHILD;
                if (p->child[index] == NULL)
                    return false;
                p = p->child[index];
            }
            return true;


        }
    private:
        TrieNode *root;



};


int main()
{
    Trie *obj = new Trie();
    string word = "solooo";
    obj->insert(word);
    bool find_word = obj->search(word);
    printf("find word:%s\n", find_word ? "true" : "false");
    find_word = obj->search("so");
    printf("find word:%s\n", find_word ? "true" : "false");
    bool find_prefix = obj->startsWith("su");
    printf("find prefix:%s\n", find_prefix ? "true" : "false");
    return 0;

}
