#include <bits/stdc++.h>
using namespace std;

// Structure to store graph
map<string, vector<vector<string>>> graph;

// Heuristic values
map<string, int> heuristic;

// To store solved nodes
map<string, bool> solved;

// To store best cost
map<string, int> cost;

// Function to compute minimum cost
int computeCost(string node) {
    if (graph.find(node) == graph.end()) {
        return heuristic[node];
    }

    int minCost = INT_MAX;

    // Each vector<string> is AND group
    for (auto group : graph[node]) {
        int currCost = 0;

        for (auto child : group) {
            currCost += computeCost(child);
        }

        minCost = min(minCost, currCost);
    }

    return heuristic[node] = minCost;
}

// AO* recursive function
void AOStar(string node) {
    if (solved[node]) return;

    if (graph.find(node) == graph.end()) {
        solved[node] = true;
        return;
    }

    int minCost = INT_MAX;
    vector<string> bestGroup;

    // Find best AND group
    for (auto group : graph[node]) {
        int currCost = 0;

        for (auto child : group) {
            currCost += heuristic[child];
        }

        if (currCost < minCost) {
            minCost = currCost;
            bestGroup = group;
        }
    }

    // Expand best group
    for (auto child : bestGroup) {
        AOStar(child);
    }

    // Update cost after expansion
    cost[node] = computeCost(node);
    solved[node] = true;
}

// Function to print result
void printSolution() {
    cout << "Final Costs:\n";
    for (auto it : cost) {
        cout << it.first << " -> " << it.second << endl;
    }
}

int main() {
    // Graph definition
    graph["A"] = {{"B", "C"}, {"D"}};
    graph["B"] = {{"E"}, {"F"}};
    graph["C"] = {{"G"}};

    // Heuristic values
    heuristic["A"] = 10;
    heuristic["B"] = 6;
    heuristic["C"] = 2;
    heuristic["D"] = 4;
    heuristic["E"] = 1;
    heuristic["F"] = 3;
    heuristic["G"] = 2;

    // Initialize solved
    for (auto h : heuristic) {
        solved[h.first] = false;
    }

    AOStar("A");

    printSolution();

    return 0;
}
