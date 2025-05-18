class Solution {
private:
    bool isPrime(int n) {
        if(n == 0 || n == 1) return false;
        if(n == 2) return true;
        int sq = sqrt(n);
        for(int i=2; i<=sq; i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> GeneratePrimes(int n) {
        vector<int> prime;
        for(int i = 2; i<n; i++) {
            if(isPrime(i)) prime.push_back(i);
        }
        return prime;
    }
    int findX(int curr, int prec, int next) {
        vector<int> primes = GeneratePrimes(curr);
        int l = 1;
        int r = primes.size() - 1;

        while(l <= r) {
            int mid = (l+r) / 2;
            int midElement = primes[mid];
            if(((curr - midElement) > prec) and ((curr - midElement) > next)) {
                return midElement;
            }
            else if( (curr - midElement)<=prec){
                r = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
public:
    bool primeSubOperation(vector<int>& arr) {
        int n = arr.size();
        if(n == 0 || n == 1) return true;
        int m = *max_element(arr.begin(), arr.end());

        vector<int> prime = GeneratePrimes(m);

        for(int i=n-2; i>=0; i--) {
            if(arr[i] < arr[i+1]) continue;
            auto it = upper_bound(prime.begin(), prime.end(), arr[i]-arr[i+1]);
            if(it == prime.end()) return false;
            int p = *it;
            arr[i] -= p;
            if(arr[i] <= 0) return false;
        }
        return true;
    }
};