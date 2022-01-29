//Linked list node
struct node {
    int value;
    struct node* next;
};

//searching for a value in a linked list.
//returns the place of te value in the list, or -1 if search fails.
//will work on sorted or unsorted linked list
int linear_search_linkedlist(node* head, int val)
{
    int place = 0;
    for (node* itr = head; itr != nullptr; itr = itr->next)
    {
        if (val == itr->value)
        {
            return place;
        }
        place++;
    }
    return -1;
}


//returns the array index of the value searched for, -1 if not found
//will work on sorted or unsorted arrays
int linear_search_array(int arr[], size_t sz, int val)
{
    for (int i = 0; i < sz; i++)
    {
        if (val == arr[i])
           return i;
    }
    return -1;
}

//returns the array index of the value searched for -1 if not found
//works for sorted arrays only
int binary_search(int arr, size_t sz, int val)
{
    int l = 0;
    int h = sz;
    while (l < h)
    {
        int mid = (l+h)/2;
        if (val == arr[mid])
          return mid;
        if (val < arr[mid]) h = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

//binary tree node
struct treenode {
    int value;
    struct treenode* left;
    struct treenode* right;
};


//searching a binary search tree
//returns the node if the value is found,
//returns NULL if search fails
//works on binary SEARCH trees because BST's are ordered collections
//this will NOT work on binary trees that dont adhere to the BST property.
treenode* tree_search(treenode* t, int val)
{
    if (t == NULL) return;
    treenode* x = t;
    while (x != NULL)
    {
        if (val == t->value)
         return t;
       X = (val < x->value) ? x->left:x->right;
    } 
    return NULL;
}
