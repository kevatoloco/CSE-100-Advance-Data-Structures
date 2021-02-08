#include "BST.h"
#include <vector>

/**
 * Implement the BST constructor
 */
BST::BST() {
    /* YOUR CODE HERE */
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    /* YOUR CODE HERE */
    clear();
    
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    /* YOUR CODE HERE */
    numElements = 0;
    if(root == nullptr){
        return;
    }
    
    vector<Node*> nodesToDelete;
    nodesToDelete.push_back(root);
    while(nodesToDelete.size() > 0){
        Node* nextToDelete = nodesToDelete.back(); 
	nodesToDelete.pop_back();
	if(nextToDelete->leftChild != nullptr){
	    nodesToDelete.push_back(nextToDelete->leftChild);
	}
	if(nextToDelete->rightChild != nullptr){
	    nodesToDelete.push_back(nextToDelete->rightChild);
	}
	delete nextToDelete;
    }
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    /* YOUR CODE HERE */
    
    // empty tree case
    if(numElements == 0){
	root = new Node(element);
        numElements += 1;
	return true;
    }
    
    Node* ptr = root;
    
    // traverse tree
    while(ptr->data != element){
	// if element is less than ptrent node then traverse left subtree
        if(element < ptr->data){
            if(ptr->leftChild == nullptr){
		
	        ptr->leftChild = new Node(element);
    		numElements += 1;
		return true;	
            }
	    else{
		ptr = ptr->leftChild;
	    }
	}
        // if element is greater than ptrent node then traverse right subtree
	else if(element > ptr->data){
	    if(ptr->rightChild == nullptr){
		ptr->rightChild = new Node(element);
		numElements += 1;
		return true;
	    }
	    else{
		ptr = ptr->rightChild;
	    }
	}
    }
    return false;
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    /* YOUR CODE HERE */

    Node* ptr = root;
    while(ptr->data != query){
        if(query < ptr->data){
	    ptr = ptr->leftChild;
	}
	else if(query > ptr->data){
	    ptr = ptr->rightChild;
	}
	if(ptr == nullptr){
	    return false;
	}
    }
    return true;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */
    if(root == nullptr){
        return nullptr;
    }
    Node* ptr = root;
    while(ptr->leftChild != nullptr){
	ptr = ptr->leftChild;
    }
    return ptr;
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */
    Node* ptr = this; 
    /* case 1: sucessor is a descendant of the ptrnode (leftmost
	node in ptrent nodes right subtree */
    if(this->rightChild != nullptr) {
        ptr = ptr->rightChild;
	while(ptr->leftChild != nullptr) {
	    ptr = ptr->leftChild; 
	}
	return ptr;
    }
    /* case 2: successor is parent node to the left side */
    else {
        while(ptr->parent != nullptr) {
	    if(ptr == ptr->parent->leftChild){
	        return ptr->parent;
	    }
	    else{
	        ptr = ptr->parent;
	    }
        }
    }
    return nullptr; 
} 
