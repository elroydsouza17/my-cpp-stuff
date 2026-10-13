#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices);

int main() {
  std::vector<int> prices= {10, 5, 2, 4, 2, 1, 8, 3};
  int profit = maxProfit(prices);
}

int maxProfit(std::vector<int>& prices) {
  int buy = 0;
  int sell = 1;
  int max_profit = prices[sell] - prices[buy];

  while (sell < prices.size()) {

    if ((prices[sell] - prices[buy]) < 0) {
      buy = sell;
    } else if ((prices[sell] - prices[buy]) > max_profit) {
      max_profit = prices[sell] - prices[buy];
    } 
    sell++;
  }

  if (max_profit < 0) {
    max_profit = 0;
  }
  std::cout << "max profit is :" << max_profit << std::endl;
  return max_profit;
}