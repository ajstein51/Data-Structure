/**
 * Paper Homework #2, Questions #1
 * AJ Stein, Data Structures 3/25/20202
 * The questions asks to make two functions (one recursive, one iterative) to go through a Binary Tree and find half childs
 * Note: I used a structure to test these functions so there may be a few different things that what the book uses.
 * 
 */ 

int Iterative_singleParent(struct Node* node){ 
    // If the tree is empty (NULL)
    if(node == NULL)
        return 0; 
  
    // Counts the nodes with 1 child
    int count = 0;
    
    vector<Node *> store; 
    store.insert(store.cend(), node); 

    while(!store.empty()){ 
        struct Node *ptr = store.front(); 
        store.erase(store.begin()); 
  
        // Increases count if only one or the other has one node
        if((ptr -> left == NULL && ptr -> right) || (ptr -> left && ptr -> right == NULL)) 
            count++; 
        
        // traverses left
        if(ptr -> left != NULL)
            store.insert(store.cend(),ptr -> left); 
        
        // traverses right
        if(ptr -> right != NULL)
            store.insert(store.cend(),ptr -> right);
    } 
    return count; 
} 

int singleParent(struct Node* root){
    // If the tree is empty (null)
    if(root == NULL)
        return 0;
    
    int recursive = 0;
    if((root -> left != NULL && root -> right == NULL) || (root -> left == NULL && root -> right != NULL))
        recursive++;
    
    recursive = recursive + singleParent(root -> left) + singleParent(root -> right);

    return recursive;
}