#include <iostream>
using std::cout;

template <typename IntDouble>
struct TreeNode
{
    IntDouble data;
    TreeNode<IntDouble> *left = nullptr;
    TreeNode<IntDouble> *right = nullptr;
};

template <typename IntDouble>
class BST
{
private:
    TreeNode<IntDouble> *root = nullptr;

    void destroyNodes (TreeNode<IntDouble> *node){
        if(!node) return;

        destroyNodes(node->left);
        destroyNodes(node->right);
        delete node;
    }

public:
    BST(){}
    ~BST(){
        this->destroyNodes(this->root);
        this->root = nullptr;
    }

    void insert(IntDouble value){
        TreeNode<IntDouble>* newNode = new TreeNode<IntDouble>();
        newNode->data = value;
        if(this->root == nullptr){
            this->root = newNode;
            return;
        }
        TreeNode<IntDouble>* current = this->root;
        TreeNode<IntDouble>* parent = nullptr;
        while(current){
            if(value < current->data){
                parent = current;
                current = current->left;
            }else if(value > current->data){
                parent = current;
                current = current->right;
            }else{
                delete newNode;
                newNode = nullptr;
                return;
            }
        }
        if(!parent){
            this->root = newNode;
        }else if(value < parent->data){
            parent->left = newNode;
        }else if(value > parent->data){
            parent->right = newNode;
        }
    }
    TreeNode<IntDouble>* remove(TreeNode<IntDouble>* node, IntDouble val){
        if(!node) return nullptr;
        if(val < node->data){
            node->left = this->remove(node->left,val);
        }else if(val > node->data){
            node->right = this->remove(node->right,val);

        }else{
            if(!node->left && !node->right){
                delete node;
                return nullptr;
            } 
            if(node->left || node->right){
                if(node->left){
                    TreeNode<IntDouble>* temp = node->right;
                    delete node;
                    return temp;
                } 
                else{
                    TreeNode<IntDouble>* temp = node->left;
                    delete node;
                    return temp;
                } 
            } 
            else{
                node->data = this->getMax(node->left);
                node->left = this->remove(node->left,node->data);
            }
        }
        return node;
    }
    
    IntDouble getMax(TreeNode<IntDouble>* node){
        TreeNode<IntDouble>* cur = node;
        while(cur->right){
            node = node->right;
        }
        return cur->data;
    }
    void removeRecursive(IntDouble value){
        if(!this->root)return;
        this->root = this->remove(this->root,value);
    }

    void print(TreeNode<IntDouble>* node){
            if(!node)return;
            print(node->left);
            cout << node->data << " ";
            print(node->right);
    }
    void printInorder(){
        cout << "Here are the elements of BST:" << "\n";
        
        this->print(this->root);
        cout << "\n";
    }

};

int main() {
    BST<int> bst;

    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(12);
    bst.insert(17);
    bst.insert(25);

    bst.removeRecursive(12);

    bst.printInorder();

    return 0;
}