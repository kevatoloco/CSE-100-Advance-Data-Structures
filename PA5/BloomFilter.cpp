#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    /* YOUR CODE HERE */ 
    for (unsigned int i = 0; i < K; i++){
	function<unsigned int(const string &)> currFunc = hash_functions[i];
	unsigned int index = currFunc(s);
	if (index >= M) {
	    continue;
	}
	bits[index] = true;
    }  
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    /* YOUR CODE HERE */  
    //bool result = true;
    for (unsigned int i = 0; i < K; i++){
        //function<unsigned int(const string &)> currFunc = hash_functions[i];
        //unsigned int index = currFunc(s);
	unsigned int index = hash_functions[i](s);
	if (index >= M) {
	    continue;
	}
	if (bits[index] == false){
	    return false;
	}
    }
    return true; 

    /*for (auto hash_function : hash_functions) {
	unsigned int index = hash_function(s);
	if (index > M || bits[index] == false) {
	    return false;
	}
    }
    return true; */
}
