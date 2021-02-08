#include <string>
#include <vector>
#include "SuffixArray.h"
#include <algorithm>
using namespace std;

bool compareSuffixPair(pair<unsigned int, string> a, pair<unsigned int, string> b){
    return a.second < b.second;
}
/**
 * Implement suffix_array() correctly
 */
vector<unsigned int> suffix_array(const string & s) {
    /* YOUR CODE HERE */
    vector<pair<unsigned int, string>> suffixVector;
    for (unsigned int i = 0; i < s.size(); i++) {
        string suffix = s.substr(i);
	pair<unsigned int, string> suffixPair = make_pair(i, suffix);
 	suffixVector.push_back(suffixPair);	
    }

    sort(suffixVector.begin(), suffixVector.end(), compareSuffixPair);
    vector<unsigned int> result(0);
    for (unsigned int i = 0; i< suffixVector.size(); i++){
	result.push_back(suffixVector[i].first);
    }

    return result;

}
