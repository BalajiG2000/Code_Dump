#include <bits/stdc++.h>
using namespace std;

enum Color
{
    RED,
    BLACK,
    DOUBLE_BLACK
};

struct Node
{
    int data;
    int color;
    Node *left, *right, *parent;

    explicit Node(int);
};

class RBTree
{
private:
    Node *root;

protected:
    void rotateLeft(Node *&);
    void rotateRight(Node *&);
    void fixInsertRBTree(Node *&);
    void fixDeleteRBTree(Node *&);
    void inorderBST(Node *&);
    void preorderBST(Node *&);
    void postorderBST(Node *&);
    int getColor(Node *&);
    void setColor(Node *&, int);
    Node *minValueNode(Node *&);
    Node *maxValueNode(Node *&);
    Node *insertBST(Node *&, Node *&);
    Node *deleteBST(Node *&, int);
    Node *search(Node *&, int);
    int getBlackHeight(Node *);
    int tree_height(Node *root);
    void inorder_black_height(Node *root);

public:
    RBTree();
    void insertValue(int);
    void deleteValue(int);
    int searchvalue(int);
    int maxval();
    int minval();
    int maxheight();
    int tree_blackheight();
    int node_blackheight(int);
    int node_blackheight_right(int);
    int left_height(int);
    int right_height(int);
    void inorder();
    void preorder();
    void postorder();
    void inorder_black_ht();
    int get_root();
};

Node::Node(int data)
{
    this->data = data;
    color = RED;
    left = right = parent = nullptr;
}

RBTree::RBTree()
{
    root = nullptr;
}

int RBTree::getColor(Node *&node)
{
    if (node == nullptr)
        return BLACK;
    return node->color;
}

void RBTree::setColor(Node *&node, int color)
{
    if (node == nullptr)
        return;
    node->color = color;
}

Node *RBTree::insertBST(Node *&root, Node *&ptr)
{
    if (root == nullptr)
        return ptr;
    if (ptr->data < root->data)
    {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    }
    else if (ptr->data > root->data)
    {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }
    return root;
}

void RBTree::insertValue(int n)
{
    Node *node = new Node(n);
    root = insertBST(root, node);
    fixInsertRBTree(node);
}

void RBTree::rotateLeft(Node *&ptr)
{
    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != nullptr)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

void RBTree::rotateRight(Node *&ptr)
{
    Node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != nullptr)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}

void RBTree::fixInsertRBTree(Node *&ptr)
{
    Node *parent = nullptr;
    Node *grandparent = nullptr;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED)
    {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;
            if (getColor(uncle) == RED)
            {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else
            {
                if (ptr == parent->right)
                {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
        else
        {
            Node *uncle = grandparent->left;
            if (getColor(uncle) == RED)
            {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else
            {
                if (ptr == parent->left)
                {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
}

void RBTree::fixDeleteRBTree(Node *&node)
{
    if (node == nullptr)
        return;

    if (node == root)
    {
        root = nullptr;
        return;
    }

    if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED)
    {
        Node *child = node->left != nullptr ? node->left : node->right;

        if (node == node->parent->left)
        {
            node->parent->left = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
        else
        {
            node->parent->right = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
    }
    else
    {
        Node *sibling = nullptr;
        Node *parent = nullptr;
        Node *ptr = node;
        setColor(ptr, DOUBLE_BLACK);
        while (ptr != root && getColor(ptr) == DOUBLE_BLACK)
        {
            parent = ptr->parent;
            if (ptr == parent->left)
            {
                sibling = parent->right;
                if (getColor(sibling) == RED)
                {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateLeft(parent);
                }
                else
                {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
                    {
                        setColor(sibling, RED);
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    }
                    else
                    {
                        if (getColor(sibling->right) == BLACK)
                        {
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);
                            rotateRight(sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->right, BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            }
            else
            {
                sibling = parent->left;
                if (getColor(sibling) == RED)
                {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                }
                else
                {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
                    {
                        setColor(sibling, RED);
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    }
                    else
                    {
                        if (getColor(sibling->left) == BLACK)
                        {
                            setColor(sibling->right, BLACK);
                            setColor(sibling, RED);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        delete (node);
        setColor(root, BLACK);
    }
}

Node *RBTree::deleteBST(Node *&root, int data)
{
    if (root == nullptr)
        return root;

    if (data < root->data)
        return deleteBST(root->left, data);

    if (data > root->data)
        return deleteBST(root->right, data);

    if (root->left == nullptr || root->right == nullptr)
        return root;

    Node *temp = maxValueNode(root->left);
    root->data = temp->data;
    return deleteBST(root->left, temp->data);
}

void RBTree::deleteValue(int data)
{
    Node *node = deleteBST(root, data);
    fixDeleteRBTree(node);
}

Node *RBTree::search(Node *&ptr, int key)
{
    if (ptr == NULL || ptr->data == key)
        return ptr;
    if (key > ptr->data)
        return search(ptr->right, key);
    else
        return search(ptr->left, key);
}

int RBTree::searchvalue(int key)
{
    Node *val = search(root, key);
    if (val == NULL)
        return -1;
    else
        return val->data;
}

void RBTree::inorderBST(Node *&ptr)
{
    if (ptr == nullptr)
        return;

    inorderBST(ptr->left);
    if (ptr->color == 0)
        cout << ptr->data << ": Red"
             << "\n";
    else
        cout << ptr->data << ": Black"
             << "\n";
    inorderBST(ptr->right);
}

void RBTree::inorder()
{
    inorderBST(root);
}

void RBTree::preorderBST(Node *&ptr)
{
    if (ptr == nullptr)
        return;

    if (ptr->color == 0)
        cout << ptr->data << ": Red"
             << "\n";
    else
        cout << ptr->data << ": Black"
             << "\n";
    preorderBST(ptr->left);
    preorderBST(ptr->right);
}

void RBTree::preorder()
{
    preorderBST(root);
}

void RBTree::postorderBST(Node *&ptr)
{
    if (ptr == nullptr)
        return;
    postorderBST(ptr->left);
    postorderBST(ptr->right);
    if (ptr->color == 0)
        cout << ptr->data << ": Red"
             << "\n";
    else
        cout << ptr->data << ": Black"
             << "\n";
}

void RBTree::postorder()
{
    postorderBST(root);
}

Node *RBTree::minValueNode(Node *&node)
{
    Node *ptr = node;
    while (ptr->left != nullptr)
        ptr = ptr->left;
    return ptr;
}

int RBTree::minval()
{
    Node *val = minValueNode(root);
    return val->data;
}

Node *RBTree::maxValueNode(Node *&node)
{
    Node *ptr = node;

    while (ptr->right != nullptr)
        ptr = ptr->right;

    return ptr;
}

int RBTree::maxval()
{
    Node *val = maxValueNode(root);
    return val->data;
}

int RBTree::tree_height(Node *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int lDepth = tree_height(root->left);
        int rDepth = tree_height(root->right);
        return max(lDepth, rDepth) + 1;
    }
}

int RBTree::maxheight()
{
    return tree_height(root);
}

int RBTree::getBlackHeight(Node *node)
{
    int blackheight = 0;
    while (node != nullptr)
    {
        if (getColor(node) == BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight + 1; //include null node
}

int RBTree::tree_blackheight()
{
    return getBlackHeight(root) - 1;
}

int RBTree::node_blackheight(int val)
{
    Node *rt = search(root, val);
    int blackheight = 0;
    Node *temp = rt;
    while (temp != nullptr)
    {
        if (getColor(temp) == BLACK)
            blackheight++;
        temp = temp->left;
    }
    if (getColor(rt) == BLACK)
        return blackheight;
    else
        return blackheight + 1;
}

int RBTree::node_blackheight_right(int val)
{
    Node *rt = search(root, val);
    int blackheight = 0;
    Node* temp = rt;
    while (temp != nullptr)
    {
        if (getColor(temp) == BLACK)
            blackheight++;
        temp = temp->right;
    }
    if (getColor(rt) == BLACK)
        return blackheight;
    else
        return blackheight + 1;
}

int RBTree::left_height(int val)
{
    Node *rt = search(root, val);
    int leftheight = 0;
    while (rt != nullptr)
    {
        rt = rt->left;
        leftheight++;
    }
    return leftheight;
}

int RBTree::right_height(int val)
{
    Node *rt = search(root, val);
    int rightheight = 0;
    while (rt != nullptr)
    {
        rt = rt->right;
        rightheight++;
    }
    return rightheight;
}

int RBTree::get_root()
{
    return root->data;
}

void RBTree::inorder_black_height(Node *ptr)
{
    if (ptr == nullptr)
        return;

    inorder_black_height(ptr->left);
    if (ptr->color == 0)
        cout << ptr->data << ": Red : ";
    else
        cout << ptr->data << ": Black : ";
    cout<<node_blackheight(ptr->data)<<endl;
    inorder_black_height(ptr->right);
}

void RBTree::inorder_black_ht()
{
    inorder_black_height(root);
}

int main()
{
    RBTree rb;
    int i = 0;

    int node_arr[] = {4, 7, 12, 15, 3, 5, 14, 18, 16, 17};
    while (i < 10)
    {
        rb.insertValue(node_arr[i]);
        i++;
    }

    cout << "\nPreorder:colour \n";
    rb.preorder();

    cout << "\nInorder:colour \n";
    rb.inorder();

    cout << "\nPostorder:colour \n";
    rb.postorder();

    int find_val = rb.searchvalue(11);
    if (find_val == -1)
        cout << "\n11 Not found";
    else
        cout << "\nFound " << find_val;

    find_val = rb.searchvalue(18);
    if (find_val == -1)
        cout << "\n18 Not found"<<endl;
    else
        cout << "\nFound " << find_val<<endl;

    cout<<"\nMinimum value: "<<rb.minval();
    cout<<"\nMaximum value: "<<rb.maxval()<<endl;

    rb.deleteValue(3);
    cout << "\nAfter deleting 3..." << endl;
    cout << "\nPreorder:colour \n";
    rb.preorder();

    cout << "\nInorder:colour \n";
    rb.inorder();

    cout << "\nPostorder:colour \n";
    rb.postorder();

    rb.deleteValue(14);
    cout << "\nAfter deleting 14..." << endl;
    cout << "\nPreorder:colour \n";
    rb.preorder();

    cout << "\nInorder:colour \n";
    rb.inorder();

    cout << "\nPostorder:colour \n";
    rb.postorder();

    cout << "\n-------------- Part c ---------" << endl;
    cout << "\nMaximum Height of RB Tree: " << rb.maxheight() << endl;

    int tree_black_height = rb.tree_blackheight();
    int root_black_height = rb.node_blackheight(rb.get_root());
    if (tree_black_height == root_black_height)
        cout << "\nBlack height of the root node is same as that of the black-height of the entire tree-->" << tree_black_height << endl;
    else
        cout << "\nBlack height of the root node is NOT same as that of the black-height of the entire tree." << endl;

    cout << "\ncase 1: No. of Black nodes on the leftmost path: " << rb.node_blackheight(rb.get_root()) << endl;
    cout << "case 1: Total No. of nodes on the leftmost path: " << rb.left_height(rb.get_root()) << endl;
    cout << "\ncase 2: No. of Black Nodes on the rightmost path: " << rb.node_blackheight_right(rb.get_root()) << endl;
    cout << "case 2: Total No. of nodes on the rightmost path: " << rb.right_height(rb.get_root()) << endl;

    cout << "\nInference: From the above two paths examined,"; 
    cout<<"\n          There are at least half the nodes on any single path from root to leaf that are black ignoring the root"<<endl;

    cout<<"\nNode : colour : black height"<<endl;
    rb.inorder_black_ht();
}