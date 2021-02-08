#include "Set.h"
#include <algorithm>

/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    /* YOUR CODE HERE */
    return arr.size();
}

void ArrayListSet::insert(string s) {
    /* YOUR CODE HERE */ 
    for (unsigned int i = 0; i < arr.size(); i++) {
        if (arr[i]== s) {
            return;
        }
    }
    arr.push_back(s);  
}

void ArrayListSet::remove(const string & s) {
    /* YOUR CODE HERE */ 
    for (unsigned int i = 0; i < arr.size(); i++) {
        if (arr[i] == s) {
            arr.erase(arr.begin() + i);
        }
    }
    return; 

}

bool ArrayListSet::find(const string & s) {
    /* YOUR CODE HERE */ 
    if (std::find(arr.begin(), arr.end(), s) != arr.end()) {
	return true;
    }
    else {
	return false;
    }
} 
