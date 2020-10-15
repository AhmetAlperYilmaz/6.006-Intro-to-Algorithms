#include <lesson6_avl_tree.h>

int main() {
    root->insert_node(54, root);
    // Still implementing
    return 0;
}

AVL::AVL(){
    //this->value = 0;
    this->left = NULL;
    this->right = NULL;
}

void AVL::insert_node(int number, AVL * node){
    if (node == NULL)
    {
        node = new AVL;
        node->set_value(number);
    }
    else if (number < node->get_value()) 
    {
        node->get_left() = insert_node(number, node->get_left());
    } 
    else if (number >= node->get_value()) 
    {
        node->get_right() = insert_node(number, node->get_right());
    }
}

int AVL::height_of_a_node(AVL * node){
    int height = 0;
    if (node != NULL) 
    {
        int left_node_height = height(node->get_left());
        int right_node_height = height(node->get_right());
        int max_height = max(left_node_height, right_node_height);
        height = max_height + 1;
    }
    return height;
}