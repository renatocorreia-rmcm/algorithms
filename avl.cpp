#include <iostream>
using namespace std;


int max(int a, int b){  // auxiliar function
    if (b>a)
    {
        return b;
    }
    return a;
}


class node{
public:
    int value;
    node* left;  // left child
    node* right;  // right child
    int height;  // size of path from this to leaf

    // constructor
    node(int value): value(value){
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};


class avl{
public:
    node* root;

    void insert(int value){
        root = insert(value, root);
    }

    node* insert(int value, node* rt){  // called for each node in path from root to leaf
        /*
            insert node as in a bst
            rebalance nodes

            return: new root
        */

        // DIVING RECURSION

        // reached fringe, finally becomes leaf
        if (rt == nullptr) {
            return new node(value);
        }

        // keep diving until reach fringe
        if (value < rt->value) {
            rt->left = insert(value, rt->left);
        } 
        else {
            rt->right = insert(value, rt->right);
        }


        // EXITING RECURSION


        // update height of this node
        rt->height = 1 + max(h(rt->left), h(rt->right));
        int balance = get_balance(rt);


        // balance this node

        if (balance > 1) {
            if (value < rt->left->value) {  // new leaf went to rt->right->right 
                return right_rotate(rt);
            } 
            else {  // new leaf went to rt->left->right
                rt->left = left_rotate(rt->left);
                return right_rotate(rt);
            }
        }
        // Right Left and Right Right
        if (balance < -1) {
            if (value > rt->right->value) {  // new leaf went to rt->left->left
                return left_rotate(rt);
            } 
            else {  // new leaf went to rt->right->left
                rt->right = right_rotate(rt->right);
                return left_rotate(rt);
            }
        }

        // return subroot of the balanced subtree above this node
        return rt;
    }

    node* left_rotate(node* rt){  // transforms rt->right in new rt
        node* r = rt->right;
        node* rl = r->left;

        r->left = rt;
        rt->right = rl;
        rt->height = max(h(rt->left), h(rt->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;

        return r;
    }

    node* right_rotate(node* rt){  // transforms rt->left in new rt
        node* l = rt->left;
        node* lr = l->right;

        l->right = rt;
        rt->left = lr;

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;

        return l;
    }

    int get_balance(node* rt){
        if (rt==nullptr)
        {
            return 0;
        }
        return h(rt->left)-h(rt->right);
    }

    int h(node* rt){
        if (rt == nullptr)
        {
            return -1;
        }
        return 1 + max(h(rt->left), h(rt->right));
    }

    void clear(node* root){
        if (root->left != nullptr)
        {
            clear(root->left);
        }
        if (root->right != nullptr)
        {
            clear(root->right);
        }
        delete root;
    }

    void clear(){
        if (root!=nullptr)
        {
            clear(this->root);
            root = nullptr;
        }
    }
    
    node* min_value_node(node* rt) {
        node* current = rt;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    node* remove(int value, node* rt) {
        
        // not found. no modification in avl.
        if (rt == nullptr)
            return rt;

        // FIND
        if (value < rt->value) {
            rt->left = remove(value, rt->left);
        } 
        else if (value > rt->value) {
            rt->right = remove(value, rt->right);
        } 

        // FOUND
        else {  // value == rt->value

            if (rt->left == nullptr || rt->right == nullptr) {  // just replace with one of his childrens
                node* temp = rt->left ? rt->left : rt->right;  // get non-null child if it exists
                if (temp == nullptr) {
                    temp = rt;
                    rt = nullptr;
                } 
                else {
                    *rt = *temp;
                }
                delete temp;
            } 
            else  // replace with minimum from right subtree, then delete this minimum 
            {
                node* temp = min_value_node(rt->right);
                rt->value = temp->value;
                rt->right = remove(temp->value, rt->right);
            }
        }

        if (rt == nullptr)
            return rt;

        rt->height = 1 + max(h(rt->left), h(rt->right));

        // BALANCE 
        
        int balance = get_balance(rt);

        // Left Left
        if (balance > 1 && get_balance(rt->left) >= 0)
            return right_rotate(rt);

        // Left Right
        if (balance > 1 && get_balance(rt->left) < 0) {
            rt->left = left_rotate(rt->left);
            return right_rotate(rt);
        }

        // Right Right
        if (balance < -1 && get_balance(rt->right) <= 0)
            return left_rotate(rt);

        // Right Left
        if (balance < -1 && get_balance(rt->right) > 0) {
            rt->right = right_rotate(rt->right);
            return left_rotate(rt);
        }

        return rt;
    }

    void remove(int value) {
        root = remove(value, root);
    }

    void print(node* root){  // preorder
        cout << root-> value << " ";
        if (root->left != nullptr)
        {
            print(root->left);
        }
        if (root->right != nullptr)
        {
            print(root->right);
        }
    }

    void print(){
        if (root!=nullptr)
        {
            print(this->root);
        }
        cout << "\n";
    }

    avl(){
        root = nullptr;
    }
};


int main(){
    avl a;

    a.insert(4);
    a.print();

    a.insert(6);
    a.print();

    a.insert(8);
    a.print();

    a.insert(3);
    a.print();

    a.insert(2);
    a.print();

    a.insert(5);
    a.print();

    a.clear();
    a.print();

    a.insert(8);
    a.print();

    a.insert(3);
    a.print();

    a.insert(2);
    a.print();

    a.insert(5);
    a.print();

    a.remove(3);
    a.print();

    return 0;
}