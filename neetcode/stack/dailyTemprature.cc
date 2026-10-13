#include <iostream>
#include <utility>
#include <stack>
#include <vector>

class Solution {
  public:
  std::vector<int> dailyTemp(std::vector<int>& temps) {
    std::vector<int> result(temps.size(), 0);
    std::stack<std::pair<int, int>> stack;
    for (int i = 0; i < temps.size(); i++) {
      while (!stack.empty() && stack.top().first < temps[i]) {
        result[stack.top().second] = i - stack.top().second;
        stack.pop();
      }
      stack.push({temps[i], i}); // you can also push just the index and use it to reference the value.
    }


    for (int i = 0; i < result.size(); i++) {
      std::cout << result[i] << " ";
      if (i == result.size() - 1) {
        std::cout << std::endl;
      }
    }
    return result;
  }
};

int main () {
  std::vector<int> tempratures = {30,38,30,36,36,40,28,23,22,39};
  Solution solution;
  solution.dailyTemp(tempratures);
}