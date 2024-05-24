// Hard 
// BS
// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1


// Striver answer noy working for full test cases

class Solution {
private:
    int numberOfGasStationsRequired(long double dist, const std::vector<int> &arr) {
        int n = arr.size(); // size of the array
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            int numberInBetween = static_cast<int>(std::ceil((arr[i] - arr[i - 1]) / dist)) - 1;
            cnt += numberInBetween;
        }
        return cnt;
    }

    long double minimiseMaxDistance(const std::vector<int> &arr, int k) {
        int n = arr.size(); // size of the array
        long double low = 0;
        long double high = 0;

        // Find the maximum distance:
        for (int i = 0; i < n - 1; i++) {
            high = std::max(high, static_cast<long double>(arr[i + 1] - arr[i]));
        }

        // Apply Binary search:
        long double diff = 1e-6;
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return high;
    }

public:
    double findSmallestMaxDist(std::vector<int> &stations, int k) {
        return minimiseMaxDistance(stations, k);
    }
};

// Code from editorial there is video exp watch again
class Solution {
public:
    bool check(vector<int> &stations, int k, double mid) {
        int count = 0;
        int n = stations.size();
        for (int i = 1; i < n; i++) {
            int diff = stations[i] - stations[i - 1];
            if (diff > mid) {
                count += diff / mid;
            }
        }
        if (count > k) {
            return false;
        }
        return true;
    }

    double findSmallestMaxDist(vector<int> &stations, int k) {
        double lo = 0;
        int n = stations.size();
        double hi = stations[n - 1] - stations[0];
        double ans = 0;

        while (lo < hi) {
            double mid = (lo + hi) / 2;
            if (check(stations, k, mid) == true) {
                ans = mid;
                hi = mid - 0.000001;
            } else {
                lo = mid + 0.000001;
            }
        }
        return ans;
    }
};

