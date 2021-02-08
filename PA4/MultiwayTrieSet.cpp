#include "Set.h"

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    /* YOUR CODE HERE */
    root = new Node();
    numElements = 0;
}

/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    /* YOUR CODE HERE */
    vector<Node*> deleteNodes;
    deleteNodes.push_back(root);
    while(deleteNodes.size() > 0){
	Node* toDelete = deleteNodes.back();
	deleteNodes.pop_back();
	for (auto it = toDelete->children.begin(); it != toDelete->children.end(); ++it){
	    deleteNodes.push_back(it->second);
	}
	delete toDelete;
    } 
}

/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    /* YOUR CODE HERE */
    return numElements;
    
}

void MultiwayTrieSet::insert(string s) {
    /* YOUR CODE HERE */
    if (s == "" || find(s) == true) {
	return;
    }
  
      
    MultiwayTrieSet::Node* curr = root;
    for (char c: s) {
	if (curr->children.find(c) != curr->children.end()) {
	    curr = curr->children[c];
	}
	else {
	    MultiwayTrieSet::Node* newInsertNode = new MultiwayTrieSet::Node();
	    curr->children.insert(std::make_pair<char&, Node*&>(c, newInsertNode));
	    curr = curr->children[c];
	}
    }
    curr->isWord = true;
    numElements += 1;
}

void MultiwayTrieSet::remove(const string & s) {
    /* YOUR CODE HERE */
    MultiwayTrieSet::Node* curr = root;
    for (char c: s) {
	if (curr->children.find(c) != curr->children.end()) {
	    curr = curr->children[c];
	}
	else {
	    return;    
	}
    }
    if (curr->isWord == true) {
	numElements -= 1;
	curr->isWord = false;
    }

}

bool MultiwayTrieSet::find(const string & s) {
    /* YOUR CODE HERE */
    MultiwayTrieSet::Node* curr = root;
    for (char c: s) {
	if (curr->children.find(c) != curr->children.end()) {
	    curr = curr->children[c];
	}
	else {
	    return false;    
	}
    }
    return curr->isWord;
}
