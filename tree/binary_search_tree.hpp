#ifndef CUCUMBERLIST_BINARY_SEARCH_TREE_HPP
#define CUCUMBERLIST_BINARY_SEARCH_TREE_HPP

#include <stdexcept>
#include <sstream>
#include "../list/list.hpp"

template<class C>
class BinarySearchTree {
private:
    class TreeNode {
    public:
        C* key_;
        TreeNode* left_;
        TreeNode* right_;
        TreeNode* p_;

    public:
        TreeNode();
        ~TreeNode();
        explicit TreeNode(C element);
        void family(TreeNode* child);
    };

    TreeNode* root_;

    void insert(TreeNode* target, BinarySearchTree::TreeNode* element); // adds element recursively (inner)
    int nodes(TreeNode* target);
    int dig(TreeNode* target);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void put(C element); // adds element iteratively
    void add(C element); // adds element recursively
    bool has(C element);
    C getNext(C element);

    int count();
    int height();

    void remove(C element);

    std::string* out(ostream& out, int elementNumber);
    std::string* out(ostream& out);
};



template<class C>
BinarySearchTree<C>::TreeNode::TreeNode() {
    this->key_ = nullptr;
    this->left_ = this->right_ = nullptr;
    this->p_ = nullptr;
}

template<class C>
BinarySearchTree<C>::TreeNode::TreeNode(C element) : TreeNode() {
    this->key_ = new C(element); // WARNING!!! Only works with "C" with defined copy constructor!!
}

template<class C>
void BinarySearchTree<C>::TreeNode::family(BinarySearchTree::TreeNode* child) {
    child->p_ = this;
    if (*(child->key_) > *key_) right_ = child;
    else left_ = child;
}

template<class C>
BinarySearchTree<C>::TreeNode::~TreeNode() {
    delete key_;
    delete right_;
    delete left_;
}



template<class C>
BinarySearchTree<C>::BinarySearchTree() {
    this->root_ = nullptr;
}

template<class C>
void BinarySearchTree<C>::put(C element) {
    TreeNode* newNode = new TreeNode(element);
    TreeNode* current, * next;
    current = next = root_;

    while (next) {
        current = next;
        if (*(current->key_) > *(newNode->key_)) next = current->left_;
        else next = current->right_;
    }

    if (root_) current->family(newNode);
    else root_ = newNode;
}

template<class C>
void BinarySearchTree<C>::add(C element) {
    TreeNode* newNode = new TreeNode(element);
    if (root_) insert(root_, newNode);
    else root_ = newNode;
}

template<class C>
void BinarySearchTree<C>::insert(BinarySearchTree::TreeNode* target, BinarySearchTree::TreeNode* element) {
    if (*(target->key_) > *(element->key_)) {
        if (target->left_) insert(target->left_, element);
        else target->family(element);
    } else {
        if (target->right_) insert(target->right_, element);
        else target->family(element);
    }
}

template<class C>
bool BinarySearchTree<C>::has(C element) {
    if (!root_) return false;

    TreeNode* current = root_;
    while (current) {
        if (*(current->key_) == element) return true;
        else if (*(current->key_) > element) current = current->left_;
        else if (*(current->key_) < element) current = current->right_;
    }

    return false;
}

template<class C>
C BinarySearchTree<C>::getNext(C element) {
    if (!root_) throw std::runtime_error("No elements found!");

    TreeNode* current = root_;
    while (current) {
        if (*(current->key_) == element) break;
        else if (*(current->key_) > element) current = current->left_;
        else if (*(current->key_) < element) current = current->right_;
    }

    if (!current) throw std::runtime_error("*This* element not found!");

    current = current->p_;
    while (current) {
        if (*(current->key_) > element) return *(current->key_);
        else current = current->p_;
    }

    throw std::runtime_error("*This* element was the biggest one!");
}



template<class C>
int BinarySearchTree<C>::count() {
    return nodes(root_);
}

template<class C>
int BinarySearchTree<C>::nodes(BinarySearchTree::TreeNode *target) {
    if (!target) return 0;
    return nodes(target->left_) + nodes(target->right_) + 1;
}



template<class C>
int BinarySearchTree<C>::height() {
    return dig(root_);
}

template<class C>
int BinarySearchTree<C>::dig(BinarySearchTree::TreeNode *target) {
    if (!target) return 0;
    int leftWing = dig(target->left_) + 1;
    int rightWing = dig(target->right_) + 1;
    return leftWing > rightWing ? leftWing : rightWing;
}



template<class C>
void BinarySearchTree<C>::remove(C element) {
    if (!root_) throw std::runtime_error("Tree is empty!");

    TreeNode* current = root_;
    while (current) {
        if (*(current->key_) == element) break;
        else if (*(current->key_) > element) current = current->left_;
        else if (*(current->key_) < element) current = current->right_;
    }

    if (!current) throw std::runtime_error("Element not found!");

    TreeNode* parent = current->p_;
    bool amRight = parent->right_ == current;
    TreeNode* rightWing = current->right_;
    TreeNode* leftWing  = current->left_;

    if (leftWing) {
        if (amRight) parent->right_ = leftWing;
        else parent->left_ = leftWing;
        leftWing->p_ = parent;

        insert(leftWing, rightWing);
    } else {
        if (amRight) parent->right_ = rightWing;
        else parent->left_ = rightWing;
    }
}



template<class C>
std::string *BinarySearchTree<C>::out(ostream& out, int elementNumber) {
    return nullptr;
}

template<class C>
std::string *BinarySearchTree<C>::out(ostream& out) {
    List<TreeNode*>* current = new List<TreeNode*>();
    List<TreeNode*>* next = new List<TreeNode*>();

    current->add_unsorted(root_);
    bool added = true;

    while (added) {
        added = false;

        for (int i = 0; i < current->Size; ++i) {
            if (current->get(i)) {
                next->add_unsorted(current->get(i)->left_);
                next->add_unsorted(current->get(i)->right_);
                added = true;
                std::cout << *(current->get(i)->key_);
            } else {
                next->add_unsorted(nullptr);
                next->add_unsorted(nullptr);
                std::cout << '%';
            }

            std::cout << "   ";
        }

        current = next;
        next = new List<TreeNode*>();
        std::cout << std::endl;
    }

    return nullptr;
}



template<class C>
BinarySearchTree<C>::~BinarySearchTree() {
    delete root_;
}


#endif //CUCUMBERLIST_BINARY_SEARCH_TREE_HPP
