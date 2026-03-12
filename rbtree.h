#ifndef RBTREE_H
#define RBTREE_H

#include <map>
#include <string>

using namespace std;

enum Color { RED, BLACK };

struct Node {
    int key;
    map<string,string> row;
    Color color;

    Node *left,*right,*parent;

    Node(int k,map<string,string> r){
        key = k;
        row = r;
        color = RED;
        left = right = parent = nullptr;
    }
};

class RBTree {

private:
    Node* root;

    void rotateLeft(Node*&);
    void rotateRight(Node*&);
    void fixInsert(Node*&);
    void inorder(Node*);

public:
    RBTree();

    void insert(int,map<string,string>);
    map<string,string> search(int);
    void remove(int);
    void print();
};

#endif