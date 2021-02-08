#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    /* YOUR CODE HERE */
    return rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    /* YOUR CODE HERE */
    rbt.insert(s);
}

void RedBlackTreeSet::remove(const string & s) {
    /* YOUR CODE HERE */
    for (auto it = rbt.begin(); it != rbt.end(); ++it) {
	if (*it == s) {
	    rbt.erase(it);
	} 
    }
}

bool RedBlackTreeSet::find(const string & s) {
    /* YOUR CODE HERE */
    if (rbt.find(s) == rbt.end()){
        return false;    
    }
    else {
	return true;
    }
}
