#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    int profit;
    int weight;
    double ratio; 

    Item(int p, int w) {
        profit = p;
        weight = w;
        ratio = (double)p / w;
    }
};

double getMaxProfit(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    double totalProfit = 0.0;
    int remainingCapacity = capacity;

    for (const Item& item : items) {
        if (item.weight <= remainingCapacity) {
            totalProfit += item.profit;
            remainingCapacity -= item.weight;
        } else {
            double fraction = (double)remainingCapacity / item.weight;
            totalProfit += item.profit * fraction;
            break; 
        }
    }

    return totalProfit;
}

int main() {
    vector<int> profits = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    int n = profits.size();
    vector<Item> items;

    for (int i = 0; i < n; i++) {
        items.emplace_back(profits[i], weights[i]);
    }

    double maxProfit = getMaxProfit(items, capacity);
    cout << "Maximum Profit = " << maxProfit << endl;

    return 0;
}
