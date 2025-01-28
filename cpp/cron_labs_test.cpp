// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>

// using namespace std;

// // Question 1: Sort array with 5s on the left and 7s on the right
// void sortFivesAndSevens(vector<int>& arr) {
//     sort(arr.begin(), arr.end());
// }

// // Question 2: Reverse the array without changing position of characters
// vector<string> reverseArray(const vector<string>& arr) {
//     vector<string> result(arr.rbegin(), arr.rend());
//     return result;
// }

// // Question 3: Reverse the whole string without reversing individual words
// string reverseStringWithExclamation(string str) {
//     reverse(str.begin(), str.end());
//     size_t start = 0, end;
//     while ((end = str.find('!', start)) != string::npos) {
//         reverse(str.begin() + start, str.begin() + end);
//         start = end + 1;
//     }
//     reverse(str.begin() + start, str.end()); // Reverse last word
//     return str;
// }

// // Question 4: Count frequency of elements from 1 to N
// vector<int> countFrequency(string num, int N) {
//     vector<int> freq(N + 1, 0);
//     for (char ch : num) {
//         int digit = ch - '0';
//         if (digit >= 1 && digit <= N) {
//             freq[digit]++;
//         }
//     }
//     return vector<int>(freq.begin() + 1, freq.end());
// }

// // Question 5: Find Kth smallest element in an array
// int kthSmallestElement(vector<int>& arr, int k) {
//     sort(arr.begin(), arr.end());
//     return arr[k - 1];
// }

// int main() {
//     // Question 1
//     vector<int> arr1 = {5, 7, 5, 7, 5, 7, 7};
//     sortFivesAndSevens(arr1);
//     cout << "Q1 Output: ";
//     for (int num : arr1) cout << num;
//     cout << endl;

//     // Question 2
//     vector<string> arr2 = {"1", "2", "A", "B", "6", "3", "X", "M", "9"};
//     vector<string> reversedArr2 = reverseArray(arr2);
//     cout << "Q2 Output: ";
//     for (const string& s : reversedArr2) cout << s << " ";
//     cout << endl;

//     // Question 3
//     string str3 = "I!am!a!coder";
//     cout << "Q3 Output: " << reverseStringWithExclamation(str3) << endl;

//     // Question 4
//     string input4 = "2033445";
//     int N = 5;
//     vector<int> freq = countFrequency(input4, N);
//     cout << "Q4 Output: ";
//     for (int f : freq) cout << f;
//     cout << endl;

//     // Question 5
//     vector<int> arr5 = {7, 6, 1, 2, 4, 5};
//     int k = 3;
//     cout << "Q5 Output: " << kthSmallestElement(arr5, k) << endl;

//     return 0;
// }
#include <iostream>
#include <vector>

using namespace std;

// Question 1: Sort array with 5s on the left and 7s on the right
void sortFivesAndSevens(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        while (arr[left] == 5)
            left++;
        while (arr[right] == 7)
            right--;
        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Question 2: Reverse the array without changing position of characters
void reverseArray(vector<string> &arr)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Question 3: Reverse the whole string without reversing individual words
void reverseStringWithExclamation(string &str)
{
    // First, reverse the whole string
    int n = str.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }

    // Now, reverse individual words separated by '!'
    int start = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == n || str[i] == '!')
        {
            int end = i - 1;
            while (start < end)
            {
                swap(str[start], str[end]);
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}

// Question 4: Count frequency of elements from 1 to N
vector<int> countFrequency(string num, int N)
{
    vector<int> freq(N + 1, 0);
    for (int i = 0; i < num.size(); i++)
    {
        int digit = num[i] - '0';
        if (digit >= 1 && digit <= N)
        {
            freq[digit]++;
        }
    }
    vector<int> result;
    for (int i = 1; i <= N; i++)
    {
        result.push_back(freq[i]);
    }
    return result;
}

// Question 5: Find Kth smallest element in an array (Using Selection Sort)
int kthSmallestElement(vector<int> &arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return arr[k - 1];
}

int main()
{
    // Question 1
    vector<int> arr1 = {5, 7, 5, 7, 5, 7, 7};
    sortFivesAndSevens(arr1);
    cout << "Q1 Output: ";
    for (int num : arr1)
        cout << num;
    cout << endl;

    // Question 2
    vector<string> arr2 = {"1", "2", "A", "B", "6", "3", "X", "M", "9"};
    reverseArray(arr2);
    cout << "Q2 Output: ";
    for (const string &s : arr2)
        cout << s << " ";
    cout << endl;

    // Question 3
    string str3 = "I!am!a!coder";
    reverseStringWithExclamation(str3);
    cout << "Q3 Output: " << str3 << endl;

    // Question 4
    string input4 = "2033445";
    int N = 5;
    vector<int> freq = countFrequency(input4, N);
    cout << "Q4 Output: ";
    for (int f : freq)
        cout << f;
    cout << endl;

    // Question 5
    vector<int> arr5 = {7, 6, 1, 2, 4, 5};
    int k = 3;
    cout << "Q5 Output: " << kthSmallestElement(arr5, k) << endl;

    return 0;
}
