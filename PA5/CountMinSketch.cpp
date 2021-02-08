#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"
const unsigned int MAX_COUNT = 65535;
/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    /* YOUR CODE HERE */
    for (unsigned int i = 0; i < K; i++){
        //function<unsigned int(const string &)> currFunc = hash_functions[i];
        //unsigned int index = currFunc(s);

       	unsigned int index = hash_functions[i](s);
        if (index < M) {
	    count[i][index] += 1;
	}
    }

}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    /* YOUR CODE HERE */
    unsigned int estimate = MAX_COUNT; 
    for (unsigned int i = 0; i < K; i++) {
	unsigned int index = hash_functions[i](s);
	if (index <  M) {
	    unsigned int curr = count[i][index];
	    if (curr < estimate) {
		estimate = curr;
	    }
	}
    }
    return estimate;
}
