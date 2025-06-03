#include <iostream>
using namespace std;

int max(int a, int b){
    if (b>a)
    {
        return b;
    }
    return a;
}


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

    void insert(int value, node* rt){


        // insert as normal bst

        if (value < rt->value)
        {
            
            if (rt->left == nullptr)
            {
                rt->left = new node(value);
            }
            else {
                insert(value, rt->left);
            }
            
        }

        else  // value >= root
        {

            if (rt->right == nullptr)
            {
                rt->right = new node(value);
            }
            else {
                insert(value, rt->right);
            }
            
        }


        // refresh traversed nodes heights

        rt->height = 1 + max(h(rt->left), h(rt->right));


        // check traversed nodes balances and rotate if necessary

        int balance = get_balance(rt);

        if (balance < -1 && value >= rt->right->value) left_rotate(rt) ;
        
        else if (balance > 1 && value < rt->left->value) right_rotate(rt) ;
        
        else if (balance > 1 && value >= rt->left->value){
            left_rotate(rt->left);
            right_rotate(rt);
        }
        else if (balance < -1 && value < rt->right->value){
            right_rotate(rt->right);
            left_rotate(rt);
        }

    }

    void left_rotate(node* rt){
        node* r = rt->right;
        node* rl = r->left;

        r->left = rt;
        rt->right = rl;
        rt->height = max(h(rt->left),h(rt->right))+1;
        r->height = max(h(r->left),h(r->right))+1;

        this->root = r;
    }
    void right_rotate(node* rt){
        node* l = rt->left;
        node* lr = l->right;

        l->right = rt;
        rt->left = lr;
        rt->height = max(h(rt->left), h(rt->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;
        this->root = l;
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

    void insert(int value){
        if (root == nullptr)
        {
            root = new node(value);
            return;        
        }
        else
        {
            insert(value, this->root);
        } 
    }

    avl(){
        root = nullptr;
    }
    
};



int main(){


    avl a;

    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);

    a.print();






    return 0;
}