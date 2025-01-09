#include <bits/stdc++.h>
#include <vector>

using namespace std;

int minShifts(vector<char> &arts)
{
    // Initialize a dictionary to keep track of the frequency of each art type.
    map<char, int> artCounts;
    artCounts['H'] = 0;
    artCounts['S'] = 0;
    artCounts['P'] = 0;
    artCounts['D'] = 0;

    // Initialize two variables to track the left and right boundaries of the sorted region.
    int sortedLeft = 0;
    int sortedRight = 0;

    // Initialize the minimum number of shifts.
    int minShifts = 0;

    for (int i = 0; i < arts.size(); ++i)
    {
        // Update the frequency of the current art type.
        ++artCounts[arts[i]];

        // Check if the current art belongs to the sorted region.
        if (i < sortedRight)
        {
            continue;
        }

        // Find the next art that should be in the sorted region.
        while (sortedRight < arts.size() && artCounts[arts[sortedRight]] == 0)
        {
            ++sortedRight;
        }

        // If we reached the end of the list, break.
        if (sortedRight == arts.size())
        {
            break;
        }

        // Calculate the number of shifts required to place the next art in the sorted region.
        int shifts = sortedRight - i;

        // Update the minimum number of shifts.
        minShifts += shifts;

        // Swap the current art with the art at the right boundary of the sorted region.
        swap(arts[i], arts[sortedRight]);

        // Update the sorted right boundary.
        ++sortedRight;
    }

    return minShifts;
}

int main()
{
    // Read the input
    int n;
    cin >> n;

    vector<char> arts(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arts[i];
    }

    // Find the minimum number of shifts
    int minShift = minShifts(arts);

    // Print the output
    cout << minShift << endl;

    return 0;
}
