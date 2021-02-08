#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "BWT.h"
using namespace std;


/**
 * Implement bwt() correctly
 */
string bwt(const string & s) {
    /* YOUR CODE HERE */
    if (s.size() == 0) {
	return "";
    }
    vector<string> rotation;
    string toRotate = s;
    if(isspace(toRotate.back())){
	toRotate.pop_back();
    }
    rotation.push_back(toRotate);
    for (unsigned int i = 0; i < s.size() - 1; i++) {
	const char back = toRotate.back();
        toRotate.pop_back();
	string toInsert(1, back);
        toRotate.insert(0, toInsert);
	rotation.push_back(toRotate);
    }
    sort(rotation.begin(), rotation.end());
    string result;
    for (unsigned int i = 0; i < rotation.size(); i++) {
	result.push_back(rotation[i].back());
        
    }
    return result;

    
}
