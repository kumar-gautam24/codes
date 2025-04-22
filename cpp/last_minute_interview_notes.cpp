# Amazon SDE 1 Last-Minute Interview Revision Notes

## Core Data Structures & Algorithms

### Arrays & Strings
- **Two Pointers**: `int left = 0, right = n-1;` → Move toward each other
- **Sliding Window**: Fixed size `for(int i = 0; i < n; i++)` or variable size with expansion/contraction
- **Prefix Sum**: `prefix[i] = prefix[i-1] + nums[i]` → Query range sum in O(1)
- **Binary Search**: `while(left <= right) { mid = left + (right-left)/2; }`

### Linked Lists
```cpp
// Reversal (in-place)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Fast & Slow Pointers (cycle detection, middle node)
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
```

### Stacks & Queues
- **Valid Parentheses**: Push opening brackets, pop and check when closing brackets
- **Monotonic Stack**: Maintain increasing/decreasing order for O(n) solution to "next greater/smaller element"
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s; // Store indices
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && nums[s.top()] < nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return result;
}
```

### Trees & Binary Search Trees
```cpp
// Validate BST
bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX) {
    if(!root) return true;
    
    if(root->val <= min || root->val >= max) return false;
    
    return isValidBST(root->left, min, root->val) && 
           isValidBST(root->right, root->val, max);
}

// Lowest Common Ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if(left && right) return root;  // p and q are on different sides
    return left ? left : right;     // Either one of p,q is in subtree or none
}
```

### Graphs
```cpp
// DFS
void dfs(vector<vector<int>>& grid, int i, int j) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') 
        return;
    
    grid[i][j] = '0'; // Mark as visited
    
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}

// BFS
int bfs(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    
    queue<pair<int,int>> q;
    q.push({0,0}); // Starting point
    grid[0][0] = -1; // Mark visited
    
    int steps = 0;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            auto [x, y] = q.front(); q.pop();
            
            if(x == m-1 && y == n-1) return steps; // Reached destination
            
            for(auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    grid[nx][ny] = -1; // Mark visited
                }
            }
        }
        steps++;
    }
    return -1; // No path found
}
```

### Heaps & Priority Queues
```cpp
// Top K Elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for(int num : nums) count[num]++;
    
    // Min heap - keeps K largest elements
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    for(auto [num, freq] : count) {
        pq.push({freq, num});
        if(pq.size() > k) pq.pop();
    }
    
    vector<int> result;
    while(!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
```

### Hash Tables
- Two Sum: `unordered_map<int, int> map; // value -> index`
- Count frequencies: `unordered_map<int, int> count;`
- String manipulation: `unordered_map<char, int> charCount;`

### Dynamic Programming
```cpp
// 1D DP - Climbing Stairs
int climbStairs(int n) {
    if(n <= 2) return n;
    
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// 2D DP - Longest Common Subsequence
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
```

### Greedy Algorithms
```cpp
// Merge Intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    
    for(int i = 1; i < intervals.size(); i++) {
        if(result.back()[1] >= intervals[i][0]) {
            // Overlapping intervals, merge
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            // Non-overlapping interval, add to result
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}
```

## High-Priority Amazon Problems

### 1. Two Sum
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // value -> index
    
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(map.count(complement)) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    
    return {};
}
```

### 2. Number of Islands
```cpp
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()) return 0;
    
    int count = 0;
    int m = grid.size(), n = grid[0].size();
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    
    return count;
}

void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    
    if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
        return;
    
    grid[i][j] = '0'; // Mark as visited
    
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}
```

### 3. Longest Substring Without Repeating Characters
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex; // char -> position
    int maxLength = 0;
    int left = 0;
    
    for(int right = 0; right < s.size(); right++) {
        if(charIndex.count(s[right])) {
            // Move left pointer to position after the last occurrence
            // But don't move backward (hence the max)
            left = max(left, charIndex[s[right]] + 1);
        }
        
        charIndex[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}
```

### 4. LRU Cache
```cpp
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // key-value pairs, most recent at front
    unordered_map<int, list<pair<int, int>>::iterator> map; // key -> iterator
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        
        // Move to front (most recently used)
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            // Update existing & move to front
            map[key]->second = value;
            cache.splice(cache.begin(), cache, map[key]);
            return;
        }
        
        // Remove least recently used if at capacity
        if(cache.size() == capacity) {
            int lru_key = cache.back().first;
            cache.pop_back();
            map.erase(lru_key);
        }
        
        // Add new key-value to front
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};
```

### 5. Merge Sorted Lists
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Dummy head to simplify edge cases
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while(l1 && l2) {
        if(l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Attach remaining list
    tail->next = l1 ? l1 : l2;
    
    return dummy.next;
}
```

## Time & Space Complexity Cheat Sheet

### Data Structure Operations
- **Vector**
  - Access: O(1)
  - Insert/Delete at end: O(1) amortized
  - Insert/Delete at middle: O(n)
  
- **Unordered Map/Set**
  - Insert/Delete/Search: O(1) average, O(n) worst case
  
- **Map/Set**
  - Insert/Delete/Search: O(log n)
  
- **Priority Queue**
  - Insert/Delete: O(log n)
  - Top: O(1)

### Algorithm Complexities
- **Sorting**
  - Quick sort: O(n log n) average, O(n²) worst
  - Merge sort: O(n log n)
  - Heap sort: O(n log n)
  
- **Graph Traversal**
  - DFS/BFS: O(V + E)
  - Dijkstra: O((V + E) log V) with binary heap
  
- **Binary Search**: O(log n)
- **Heap Operations**: O(log n) for insert/delete, O(1) for peek

## Interview Strategy

### Problem-Solving Framework
1. **Clarify the problem**
   - Confirm inputs/outputs
   - Ask about constraints
   - Discuss edge cases
   
2. **Work through examples**
   - Use simple examples
   - Try edge cases
   
3. **Formulate approach**
   - Start with brute force
   - Optimize step by step
   - Explain tradeoffs
   
4. **Code the solution**
   - Use meaningful variable names
   - Check boundary conditions
   - Handle edge cases
   
5. **Test your code**
   - Trace through with examples
   - Catch edge cases
   - Fix bugs
   
6. **Analyze complexity**
   - Time complexity
   - Space complexity
   - Discuss optimizations

### Communication Tips
- **Think out loud**: Share your thought process
- **Be explicit about tradeoffs**: "We could use X with O(n) space or Y with O(1) space but O(n²) time"
- **Engage with the interviewer**: Ask for feedback, clarify understanding
- **Show your work**: Write clean, organized code with comments

## Amazon Leadership Principles to Highlight

### Customer Obsession
- Show how you'd consider end-users in technical decisions
- Demonstrate willingness to go beyond requirements

### Ownership
- Take responsibility for the entire solution
- Discuss how you'd handle edge cases and potential errors

### Invent and Simplify
- Offer optimizations to initial solutions
- Show how you break down complex problems

### Learn and Be Curious
- Ask good questions
- Show willingness to explore different approaches

### Dive Deep
- Demonstrate technical depth in your solutions
- Be ready to explain implementation details

### Bias for Action
- Make progress even with incomplete information
- Show how you'd validate assumptions

## Final Reminders
- Breathe and stay calm
- Focus on your problem-solving process, not just the answer
- It's okay to ask for hints if stuck
- Show passion for technology and learning
- Be confident but humble

Good luck!
