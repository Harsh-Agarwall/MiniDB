#include "rbtree.h"
#include <iostream>

RBTree::RBTree(){
    root = nullptr;
}

void RBTree::rotateLeft(Node*& pt){
    Node* right = pt->right;

    pt->right = right->left;

    if(right->left)
        right->left->parent = pt;

    right->parent = pt->parent;

    if(!pt->parent)
        root = right;

    else if(pt == pt->parent->left)
        pt->parent->left = right;

    else
        pt->parent->right = right;

    right->left = pt;
    pt->parent = right;
}

void RBTree::rotateRight(Node*& pt){
    Node* left = pt->left;

    pt->left = left->right;

    if(left->right)
        left->right->parent = pt;

    left->parent = pt->parent;

    if(!pt->parent)
        root = left;

    else if(pt == pt->parent->left)
        pt->parent->left = left;

    else
        pt->parent->right = left;

    left->right = pt;
    pt->parent = left;
}

void RBTree::fixInsert(Node*& pt){

    while(pt != root && pt->parent->color == RED){

        Node* parent = pt->parent;
        Node* grandparent = parent->parent;

        if(parent == grandparent->left){

            Node* uncle = grandparent->right;

            if(uncle && uncle->color == RED){

                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                pt = grandparent;
            }

            else{

                if(pt == parent->right){

                    rotateLeft(parent);
                    pt = parent;
                }

                rotateRight(grandparent);

                swap(parent->color,grandparent->color);

                pt = parent;
            }
        }

        else{

            Node* uncle = grandparent->left;

            if(uncle && uncle->color == RED){

                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                pt = grandparent;
            }

            else{

                if(pt == parent->left){

                    rotateRight(parent);
                    pt = parent;
                }

                rotateLeft(grandparent);

                swap(parent->color,grandparent->color);

                pt = parent;
            }
        }
    }

    root->color = BLACK;
}

void RBTree::insert(int key,map<string,string> row){

    Node* node = new Node(key,row);

    Node* parent = nullptr;
    Node* curr = root;

    while(curr){

        parent = curr;

        if(key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    node->parent = parent;

    if(!parent)
        root = node;

    else if(key < parent->key)
        parent->left = node;

    else
        parent->right = node;

    fixInsert(node);
}

map<string,string> RBTree::search(int key){

    Node* curr = root;

    while(curr){

        if(key == curr->key)
            return curr->row;

        if(key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return {};
}

void RBTree::remove(int key){

    Node* curr = root;
    Node* parent = nullptr;

    while(curr && curr->key != key){

        parent = curr;

        if(key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(!curr){
        std::cout<<"Record not found\n";
        return;
    }

    if(!curr->left && !curr->right){

        if(curr == root)
            root = nullptr;

        else if(parent->left == curr)
            parent->left = nullptr;

        else
            parent->right = nullptr;

        delete curr;
    }

    else if(!curr->left || !curr->right){

        Node* child = curr->left ? curr->left : curr->right;

        if(curr == root)
            root = child;

        else if(parent->left == curr)
            parent->left = child;

        else
            parent->right = child;

        child->parent = parent;

        delete curr;
    }

    std::cout<<"Deleted\n";
}

void RBTree::inorder(Node* node){

    if(!node) return;

    inorder(node->left);

    std::cout<<node->key<<" -> ";

    for(auto &p:node->row)
        std::cout<<p.first<<"="<<p.second<<" ";

    std::cout<<std::endl;

    inorder(node->right);
}

void RBTree::print(){
    inorder(root);
}