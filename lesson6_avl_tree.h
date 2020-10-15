#ifndef LESSON6
#include <iostream>

class AVL {
    private:
        int value;
        AVL * left;
        AVL * right;
    public:
        AVL();
        void insert_node(int, AVL *);
        void delete_node(int);
        void find_successor(int);
        void find_presuccessor(int);
        int height_of_a_node(AVL *);
        AVL * balance_tree(AVL *);
        void set_value(int num){this->value = num;}
        void set_left(AVL * node){this->left = node;}
        void set_right(AVL * node){this->right = node;}
        int get_value(){return this->value;}
        AVL * get_left(){return this->left;}
        AVL * get_right(){return this->right;}        
};

AVL * root = NULL; // root of the AVL tree

#endif