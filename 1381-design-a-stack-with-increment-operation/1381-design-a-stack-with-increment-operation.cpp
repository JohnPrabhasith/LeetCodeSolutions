class CustomStack {
    int m;
    vector<int> vec, inc;

public:
    CustomStack(int maxSize) {
        m = maxSize;
        vec.reserve(m); 
        inc.resize(m, 0);
    }
    
    void push(int x) {
        if (vec.size() < m) {
            vec.push_back(x);
        }
    }
    
    int pop() {
        if (vec.empty()) {
            return -1;
        }
        int i = vec.size() - 1;
        if (i > 0) {
            inc[i - 1] += inc[i];
        }
        int res = vec.back() + inc[i]; 
        vec.pop_back(); 
        inc[i] = 0; 
        return res;
    }
    
    void increment(int k, int val) {
        int i = min(k, (int)vec.size()) - 1; 
        if (i >= 0) {
            inc[i] += val;
        }
    }
};
