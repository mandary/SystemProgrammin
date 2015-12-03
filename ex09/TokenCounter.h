#ifndef TOKENCOUNTER_H
#define TOKENCOUNTER_H

#include <string>
#include <vector>
#include <map>

class TokenCounter {
 public:
  // Takes a vector of tokens (strings) with possible duplicates
  TokenCounter(const std::vector<std::string> &tokenCollection);
  
  // We declare the destructor in case some implementation requires one
  ~TokenCounter();
  
  // Returns the N most frequently occuring tokens in the constructor arg vector
  std::vector<std::pair<std::string,int>> getTop(int N);

 private:
  std::map<std::string,int> tokenCounts;
};

#endif // TOKENCOUNTER_H
