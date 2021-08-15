#include <iostream>
#include <vector>


int minSubArrayLenBinarySearch(int s, std::vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int ans = INT_MAX;
    std::vector<int> sums(n + 1, 0);

    for (int i = 1; i <= n; i++)
        sums[i] = sums[i - 1] + nums[i - 1];

    for (int i = 1; i <= n; i++) {
        std::cout
            << "\n\n";
        int to_find = s + sums[i - 1];
        std::cout
            << to_find
            << "----"
            << std::endl;

        auto bound = lower_bound(sums.begin(), sums.end(), to_find);
        std::cout
            << (bound - sums.begin())
            << "===="
            << std::endl;

        if (bound != sums.end())
            ans = std::min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
    }
    return (ans != INT_MAX) ? ans : 0;
}

int minSubArrayLenBruteForce(int s, std::vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int ans = INT_MAX;
    std::vector<int> sums(n);

    sums[0] = nums[0];

    for (int i = 1; i < n; i++)
        sums[i] = sums[i - 1] + nums[i];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = sums[j] - sums[i] + nums[i];
            if (sum >= s) {
                ans = std::min(ans, (j - i + 1));
                break; // Fond the smallest subarray with sum >= sstarting with
                       // index i, hence move to next index.
                       
            }
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}

int main ()
{
    std::vector<int> nums = {2, 1, 3, 4, 3};

    // int res1 = minSubArrayLenBruteForce(7, nums);
    // std::cout << res1 << std::endl;

    int res2 = minSubArrayLenBinarySearch(7, nums);
    std::cout << res2 << std::endl;
}
