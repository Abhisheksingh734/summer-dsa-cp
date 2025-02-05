#include <bits/stdc++.h>
using namespace std;

// Function to calculate the bounding box
pair<int, int> calculateBoundingBox(vector<pair<int, int>> &vertices)
{
    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;

    for (const auto &vertex : vertices)
    {
        int x = vertex.first;
        int y = vertex.second;

        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    return {maxX - minX, maxY - minY}; // Width and height of the bounding box
}

// Function to calculate the minimum presses needed
int calculateMinPresses(int width, int height, int M)
{
    // Calculate the number of presses needed
    int pressesX = (width + M - 1) / M;  // Ceiling of width / M
    int pressesY = (height + M - 1) / M; // Ceiling of height / M

    return pressesX * pressesY; // Total number of presses
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vertices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vertices[i].first >> vertices[i].second;
    }

    int M;
    cin >> M;

    // Get the bounding box dimensions
    pair<int, int> dimensions = calculateBoundingBox(vertices);
    int width = dimensions.first;
    int height = dimensions.second;

    // Calculate the result
    int result = calculateMinPresses(width, height, M);

    cout << result << endl;

    return 0;
}
