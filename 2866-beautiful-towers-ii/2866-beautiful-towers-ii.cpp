class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> left(n), right(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = 1LL * maxHeights[i] * (i + 1);
            } else {
                int prev = st.top();
                left[i] = left[prev] + 1LL * maxHeights[i] * (i - prev);
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = 1LL * maxHeights[i] * (n - i);
            } else {
                int next = st.top();
                right[i] = right[next] + 1LL * maxHeights[i] * (next - i);
            }
            st.push(i);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, left[i] + right[i] - maxHeights[i]);
        }

        return result;
    }
};