
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

#include "TokenCounter.h"

// Yufang Sun
// 1334960
// mandary@uw.edu

using namespace std;

TokenCounter::TokenCounter(const vector<string> &tokenCollection) {
	tokenCounts = map<string, int>();
	for (auto itr = tokenCollection.begin(); itr != tokenCollection.end(); itr++) {
		tokenCounts[*itr] += 1;
	}
}

TokenCounter::~TokenCounter() {
}

vector<pair<string,int>> TokenCounter::getTop(int N) {
	vector<pair<string,int>> result;
	if (!tokenCounts.empty()) {
		vector<pair<string,int>> all;
		for (auto itr = tokenCounts.begin(); itr != tokenCounts.end(); itr++) {
			pair<string, int> temp(itr->first, itr->second);
			all.push_back(temp);
		}
		sort(all.begin(), all.end(), [](const pair<string,int> &left, 
			const pair<string,int> &right) { return left.second > 
			right.second; });
		for (auto itr = all.begin(); itr < N + all.begin(); itr++) {
			result.push_back(*itr);
		}
	}
	return result;
}