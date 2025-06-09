#include <iostream>
using namespace std;


class node{
public:
    int value;
    node* left;
    node* right;
    int height;

    node(int value): value(value){
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

class avl{
public:
    node* root;

    void print(node* root){
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

    node* insert(int value, node* rt){  // return avl new root
        if (rt == nullptr) {
            return new node(value);
        }
        if (value < rt->value) {
            rt->left = insert(value, rt->left);
        } else {
            rt->right = insert(value, rt->right);
        }

        rt->height = 1 + max(h(rt->left), h(rt->right));
        int balance = get_balance(rt);

        // Left Right and Left Left
        if (balance > 1) {
            if (value < rt->left->value) {
                return right_rotate(rt);
            } else {
                rt->left = left_rotate(rt->left);
                return right_rotate(rt);
            }
        }
        // Right Left and Right Right
        if (balance < -1) {
            if (value > rt->right->value) {
                return left_rotate(rt);
            } else {
                rt->right = right_rotate(rt->right);
                return left_rotate(rt);
            }
        }
        return rt;
    }

    void insert(int value){
        root = insert(value, root);
    }

    node* left_rotate(node* rt){
        node* r = rt->right;
        node* rl = r->left;

        r->left = rt;
        rt->right = rl;
        rt->height = max(h(rt->left), h(rt->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;

        return r;
    }

    node* right_rotate(node* rt){
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
        }
    }

    avl(){
        root = nullptr;
    }
};





int main(){

    int t; cin >> t;

    int query;

    while (t--)
    {
        cin >> query;

        if (query==1)
        {
            /* code */
        }
        if (query==2)
        {
            /* code */
        }
        
        
    }
    




    return 0;
}