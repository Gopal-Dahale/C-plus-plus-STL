#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class node
{
private:
    char data;
    bool terminal; // for terminal node
    unordered_map<char, node *> children;

public:
    node(char data) : data{data}, terminal{false} {}
    char getData()
    {
        return this->data;
    }
    void setTerminal(bool value)
    {
        this->terminal = value;
    }
    bool isTerminal()
    {
        return this->terminal;
    }
    unordered_map<char, node *> getChildren()
    {
        return this->children;
    }
    void setChildren(pair<char, node *> child)
    {
        this->children.insert(child);
    }
};

class trie
{
private:
    node *root;

public:
    trie() : root{new node('\0')} {}

    void insert(string word)
    {

        node *temp = root;

        // iterate over the string
        for (auto &ch : word)
        {

            if (temp->getChildren().count(ch)) // if key is present
            {
                temp = temp->getChildren().at(ch); // move to next node
            }

            // node is not present
            else
            {
                node *n = new node(ch);
                temp->setChildren({ch, n});
                temp = n;
            }
        }
        temp->setTerminal(true);
    }

    bool find(string word)
    {
        node *temp = root;
        for (auto &ch : word)
        {
            if (temp->getChildren().count(ch) == 0) // word not present in trie
                return false;
            else
                temp = temp->getChildren().at(ch);
        }
        return temp->isTerminal();
    }
    node *getRoot()
    {
        return this->root;
    }
};

// utitity function to print trie
void print(node *root)
{
    for_each(root->getChildren().begin(), root->getChildren().end(), [&](pair<char, node *> p) {
        cout << p.first << " ";
        print(p.second);
    });
}

// utitlity function to check whether word is present in trie and print the result
void check(string word, trie &t)
{
    cout << word << (t.find(word) ? " is present\n" : " is not present\n");
}

int main()
{
    trie t;

    vector<string> words = {
        "apple",
        "no",
        "not",
        "news",
        "ape"};

    for_each(words.begin(), words.end(), [&](string x) { t.insert(x); });

    print(t.getRoot());
    cout << "\n";

    check("apple", t);
    check("car", t);
    check("app", t);
    return 0;
}
