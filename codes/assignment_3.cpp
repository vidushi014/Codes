#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class tree : public node
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }
    node *return_root()
    {
        return root;
    }
    int return_root_data()
    {
        return root->data;
    }
    void insert_iterative(int);
    void insert_recursive(node *, int);
    void insert_binary_tree(int);
    void preorder_recursive(node *n);
    void inorder_recursive(node *n);
    void postorder_recursive(node *n);
    void preorder_iterative(node *);
    void inorder_iterative(node *);
    void postorder_iterative(node *);
    node *search_node(node *, int);
    void delete_node(int);
    int height(node *);
    int number_of_nodes(node *);
    node *copy_tree(node *);
    node *mirror_image(node *);
    bool check_for_equal();
    void level_order();
};

void tree::insert_iterative(int key)
{
    if (root == NULL)
    {
        root = new node;
        root->data = key;
        root->left = NULL;
        root->right = NULL;
        cout << "\t Element Inserted!! \n";
        return;
    }
    node *temp = root;
    while (true)
    {
        if (temp->data == key)
        {
            cout << "\n\t Error: No duplicate values can be inserted!! \n";
            return;
        }
        else if (temp->data > key)
        {
            if (temp->left == NULL)
            {
                temp->left = new node;
                temp->left->data = key;
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = new node;
                temp->right->data = key;
                break;
            }
            else
                temp = temp->right;
        }
    }
    cout << "\t Element Inserted!! \n";
}

/* void tree::insert_recursive(node *root, int value)
{
    if(root == NULL)
    {

    }
    if(value > root->data)
    {
        root->right = insert_recursive(root->right, value);
    }
    if(value < root->data)
    {
        root->left = insert_recursive(root->left, value);
    }
} */

void tree::preorder_recursive(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

void tree::inorder_recursive(node *root)
{
    if (root == NULL)
        return;
    inorder_recursive(root->left);
    cout << root->data << " ";
    inorder_recursive(root->right);
}

void tree::postorder_recursive(node *root)
{
    if (root == NULL)
        return;
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout << root->data << " ";
}

void tree::preorder_iterative(node *r)
{
    stack<node *> s;
    node *temp = r;
    do
    {

        while (temp != NULL)
        {
            cout << temp->data << " ";
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        temp = temp->right;

    } while (temp != NULL || s.size() != 0);
}

void tree::inorder_iterative(node *r)
{
    stack<node *> s;
    node *temp = r;
    do
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout << temp->data << " ";
        temp = temp->right;

    } while (temp != NULL || s.size() != 0);
}

void tree::postorder_iterative(node *r)
{
    stack<node *> s1, s2;
    node *t = NULL;
    s1.push(r);
    while (s1.size() != 0)
    {
        t = s1.top();
        s1.pop();
        s2.push(t);
        if (t->left != NULL)
            s1.push(t->left);
        if (t->right != NULL)
            s1.push(t->right);
    }
    while (s2.size() != 0)
    {
        t = s2.top();
        s2.pop();
        cout << t->data << " ";
    }
}

void tree::level_order()
{
    queue<node *> q;
    q.push(root);
    while (q.size() != 0)
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void tree::delete_node(int value)
{
    node *searched_parent = search_node(root, value);
    node *to_delete = NULL;
    if (searched_parent == NULL)
    {
        cout << "\n The Node is not Present in the Tree!!\n";
        return;
    }
    else
    {
        int flag = 1;
        if (searched_parent->left->data == value)
        {
            flag = 0;
            to_delete = searched_parent->left;
        }
        else
            to_delete = searched_parent->right;
        if (flag == 0)
        {
            // The node does not have any children
            if (to_delete->left == NULL && to_delete->right == NULL)
            {
                searched_parent->left = NULL;
                delete (to_delete);
            }
            // The node has only one Child
            if (to_delete->left != NULL && to_delete->right == NULL)
            {
                searched_parent->left = to_delete->left;
                delete (to_delete);
            }
            if (to_delete->left == NULL && to_delete->right != NULL)
            {
                searched_parent->left = to_delete->right;
                delete (to_delete);
            }
        }
        if (flag == 1)
        {
            // The node does not have any children
            if (to_delete->left == NULL && to_delete->right == NULL)
            {
                searched_parent->right = NULL;
                delete (to_delete);
            }
            // The node has only one Child
            if (to_delete->left != NULL && to_delete->right == NULL)
            {
                searched_parent->right = to_delete->left;
                to_delete->left = NULL;
                delete (to_delete);
            }
            if (to_delete->left == NULL && to_delete->right != NULL)
            {
                searched_parent->right = to_delete->right;
                to_delete->right = NULL;
                delete (to_delete);
            }
        }
    }
    cout << "\n\t Element Deleted!!";
}

int tree::height(node *r)
{
    if (r == NULL)
        return 0;
    return 1 + max(height(r->left), height(r->right));
}

int tree::number_of_nodes(node *r)
{
    if (r == NULL)
        return 0;
    return 1 + number_of_nodes(r->left) + number_of_nodes(r->right);
}

node *tree::copy_tree(node *r)
{
    if (r == NULL)
        return NULL;
    node *t = new node;

    t->data = r->data;
    t->left = copy_tree(r->left);
    t->right = copy_tree(r->right);

    return t;
}

node *tree::mirror_image(node *r)
{
    if (r == NULL)
        return NULL;
    node *t = new node;

    t->data = r->data;
    t->right = copy_tree(r->left);
    t->left = copy_tree(r->right);

    return t;
}

node *tree::search_node(node *root, int value)
{

    if (root->data > value)
    {
        if (root->left == NULL)
            return NULL;
        if (root->left->data == value)
            return root;
        else
            return search_node(root->left, value);
    }
    else
    {
        if (root->right == NULL)
            return NULL;
        if (root->right->data == value)
            return root;
        else
            return search_node(root->right, value);
    }
}

void tree::insert_binary_tree(int value)
{
    if (root == NULL)
    {
        root = new node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        cout << "\t Element Inserted!! \n";
        return;
    }
    node *temp = root;
    while (true)
    {
        if (temp->data == value)
        {
            cout << "\n\t Error: No duplicate values can be inserted!! \n";
            return;
        }
        int choice;
        cout << "\t Where do you want to Insert?\n\t 1. Left of " << temp->data << "\t 2. Right of " << temp->data;
        cout << "\n\t Enter Your Choice :: ";
        cin >> choice;
        if (choice == 1)
        {
            if (temp->left == NULL)
            {
                temp->left = new node;
                temp->left->data = value;
                break;
            }
            else
                temp = temp->left;
        }
        else if (choice == 2)
        {
            if (temp->right == NULL)
            {
                temp->right = new node;
                temp->right->data = value;
                break;
            }
            else
                temp = temp->right;
        }
    }
    cout << "\t Element Inserted!! \n";
}

int main()
{
    tree bst, bt;
    int op_choice = 0;
    cout << "\n Choose from the following ::";
    cout << "\n 1. Insert \n 2. Display \n 3. Search \n 4. Delete \n 5. Number of Nodes";
    cout << "\n 6. Height \n 7. Copy Tree \n 8. Mirror Image \n 9. Check if Equal";
    cout << "\n 10. Insert in Binary Tree \n 11. Display Binary Tree \n 12. Exit";
    while (op_choice != 12)
    {
        cout << "\n Your Choice --> ";
        cin >> op_choice;
        switch (op_choice)
        {
        case 1:
        {
            int insert_choice = 0;
            cout << "\n\t 1. Insert Iteratively \t 2. Insert Recursively";
            cout << "\n\t Enter Your Choice :: ";
            cin >> insert_choice;
            int key;
            cout << "\t Enter the value to Insert :: ";
            cin >> key;
            switch (insert_choice)
            {
            case 1:
                bst.insert_iterative(key);
                break;
            case 2:
                // bst.insert_recursive(t.return_root(), key);
                break;
            default:
                cout << "\n No Such Choice!!";
                break;
            }
        }
        break;
        case 2:
        {
            int traversal_choice = 0;
            cout << "\n\t 1. PreOrder \t 2. InOrder \t 3. PostOrder \t 4. LevelOrder";
            cout << "\n\t Enter Your Choice :: ";
            cin >> traversal_choice;
            switch (traversal_choice)
            {
            case 1:
                cout << " -------------- PRE-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bst.preorder_iterative(bst.return_root());
                cout << "\n\t RECURSIVE :: ";
                bst.preorder_recursive(bst.return_root());
                cout << endl;
                break;
            case 2:
                cout << " -------------- IN-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bst.inorder_iterative(bst.return_root());
                cout << "\n\t RECURSIVE :: ";
                bst.inorder_recursive(bst.return_root());
                cout << endl;
                break;
            case 3:
                cout << " -------------- POST-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bst.postorder_iterative(bst.return_root());
                cout << "\n\t RECURSIVE :: ";
                bst.postorder_recursive(bst.return_root());
                cout << endl;
                break;
            case 4:
                cout << " -------------- LEVEL-ORDER TRAVERSAL ---------------- \n\t";
                bst.level_order();
                cout << endl;
                break;
            default:
                cout << "\n No Such Choice!!";
                break;
            }
        }
        break;
        case 3:
            int v;
            cout << "\t Enter the Value to Search :: ";
            cin >> v;
            if (bst.return_root_data() == v)
            {
                cout << "\t Value is Present in the Tree!! \n";
                break;
            }
            if (bst.search_node(bst.return_root(), v) != NULL)
            {
                cout << "\t Value is Present in the Tree!! \n";
            }
            else
            {
                cout << "\t Value is !Present in the Tree!! \n";
            }
            break;
        case 4:
        case 5:
            cout << "\t The Number of Nodes in the tree are --> " << bst.number_of_nodes(bst.return_root()) << endl;
            break;
        case 6:
            cout << "\t The Height of the tree is --> " << bst.height(bst.return_root()) << endl;
            break;
        case 7:
            cout << "\n The Clone of the Tree is :: ";
            cout << "\n\t PRE-ORDER --> ";
            bst.preorder_iterative(bst.copy_tree(bst.return_root()));
            cout << "\n\t IN-ORDER --> ";
            bst.inorder_iterative(bst.copy_tree(bst.return_root()));
            cout << "\n\t POST-ORDER --> ";
            bst.postorder_iterative(bst.copy_tree(bst.return_root()));
            cout << endl;
            break;
        case 8:
            cout << "\n The Mirror Image of the Tree is :: ";
            cout << "\n\t PRE-ORDER --> ";
            bst.preorder_iterative(bst.mirror_image(bst.return_root()));
            cout << "\n\t IN-ORDER --> ";
            bst.inorder_iterative(bst.mirror_image(bst.return_root()));
            cout << "\n\t POST-ORDER --> ";
            bst.postorder_iterative(bst.mirror_image(bst.return_root()));
            cout << endl;
            break;
        case 9:
            int va;
            cout << "\t Enter the Value to Delete :: ";
            cin >> va;
            bst.delete_node(va);
            break;
        case 10:
            int val;
            cout << "\t Enter the value to Insert :: ";
            cin >> val;
            bt.insert_binary_tree(val);
            break;
        case 11:
            cout << "\n\t PRE-ORDER --> ";
            bt.preorder_iterative(bt.return_root());
            cout << "\n\t IN-ORDER --> ";
            bt.inorder_iterative(bt.return_root());
            cout << "\n\t POST-ORDER --> ";
            bt.postorder_iterative(bt.return_root());
            cout << "\n\t LEVEL-ORDER --> ";
            bt.level_order();
            cout << endl;
        case 12:
            break;
        }
    }
    return 0;
}
