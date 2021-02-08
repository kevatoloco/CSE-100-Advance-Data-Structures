#include "BinaryTree.h"
#include <queue>
#include <iostream>
#include <unordered_map>

int height(BinaryTree::Node* node){
    if(node == nullptr){
        return 0;
    }
    return 1 + max(height(node->leftChild), height(node->rightChild));
}
 

/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    /* YOUR CODE HERE */
    // bf = height(leftChild) - height(rightChild)
    unordered_map<int, int> bf;
    
    queue<Node*> nodesToComputeBF;
    nodesToComputeBF.push(root);
    while(nodesToComputeBF.size() > 0){
        Node* next = nodesToComputeBF.front(); 
	nodesToComputeBF.pop();
	int leftHeight = 0;
	int rightHeight = 0;
	if(next->leftChild != nullptr){
	    nodesToComputeBF.push(next->leftChild);
	    leftHeight = height(next->leftChild);
	}
	if(next->rightChild != nullptr){
	    nodesToComputeBF.push(next->rightChild);
	    rightHeight = height(next->rightChild);
           
	}
        
	int bfValue = rightHeight - leftHeight; 
	bf[next->label] = bfValue;
       // cout<<next->label<<" "<<leftHeight<<" "<<rightHeight<<endl;
    }

    return bf;
     
}

