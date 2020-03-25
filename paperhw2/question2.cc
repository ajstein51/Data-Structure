/**
 * Paper Homework #2, Questions #2
 * AJ Stein, Data Structures, 03/25/2020
 * The question asks to write two functions (one recursive, the other iterative) to find how many nodes are in the Binary Tree.
 * Note: I used a structure to test these functions so thats how its build for
 * 
 */ 
 

int leafCount(struct Node* node){  
    // If the tree is empty
    if(node == NULL)      
        return 0;
    
    // adds 1
    if(node -> left == NULL && node -> right == NULL)  
        return 1;   
    
    // recursivly keeps going through       
    else
        return leafCount(node -> left) + leafCount(node -> right);  
}  

int nr_LeafCount(struct Node* node){
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
        
        // traverses left
        if(ptr -> left != NULL)
            store.insert(store.cend(),ptr -> left); 
        
        // traverses right
        if(ptr -> right != NULL)
            store.insert(store.cend(),ptr -> right);
        
        // Adds if its null (means its a leaf)
        if (ptr -> left == NULL && ptr -> right == NULL) 
            count++;
    } 
    return count; 
} 
 