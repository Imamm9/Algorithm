#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio; // profit-to-weight ratio
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int n, int knapsackSize, int weights[], int profits[], int selectedObjects[]) {
    Item items[n];

    // Calculate profit-to-weight ratio for each item
    for (int i = 0; i < n; ++i) {
        items[i] = {weights[i], profits[i], static_cast<double>(profits[i]) / weights[i]};
    }

    // Sort items based on profit-to-weight ratio in descending order
    sort(items, items + n, compare);

    // Debug print sorted items
    cout << "Sorted Items (by ratio):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ": Ratio = " << items[i].ratio << ", Weight = " << items[i].weight << ", Profit = " << items[i].profit << endl;
    }

    double totalProfit = 0.0;
    int currentWeight = 0;
    int selectedCount = 0;

    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= knapsackSize) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            selectedObjects[selectedCount++] = i;
        } else {
            // Take a fraction of the item
            double remainingSpace = knapsackSize - currentWeight;
            double fraction = remainingSpace / items[i].weight;
            totalProfit += fraction * items[i].profit;
            selectedObjects[selectedCount++] = i;
            break; // Knapsack is full
        }
    }

    return totalProfit;
}

int main() {
    int n, knapsackSize;

    // Input the number of objects and knapsack size
    cout << "Enter the number of objects: ";
    cin >> n;
    cout << "Enter the knapsack size: ";
    cin >> knapsackSize;

    int weights[n];
    int profits[n];
    int selectedObjects[n];

    // Input weights and profits for each object
    for (int i = 0; i < n; ++i) {
        cout << "Enter weight and profit for object " << i + 1 << ": ";
        cin >> weights[i] >> profits[i];
    }

    double maxProfit = fractionalKnapsack(n, knapsackSize, weights, profits, selectedObjects);

    // Output the maximum profit
    cout << "Maximum Profit: " << maxProfit << endl;

    // Output the selected objects
    cout << "Objects taken: ";
    for (int i = 0; i < n && selectedObjects[i] != -1; ++i) {
        cout << selectedObjects[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
