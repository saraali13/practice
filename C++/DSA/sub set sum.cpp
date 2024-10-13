#include <iostream>
#include <vector>
using namespace std;

class SumOfSubsets 
{
private:
    vector<int> set; // The set of numbers
    int target; // The target sum
    vector<int> solution; // To store the current subset

    // Backtracking function to find all subsets that sum to the target
    void sumOfSubsetsUtil(int index, int currentSum) 
{
        if (currentSum == target) 
        {
            // Print the current subset
            cout << "{ ";
            for (int num : solution)
                cout << num << " ";
            cout << "}" << endl;
            return;
        }

        if (index == set.size() || currentSum > target)
            return;

        // Include the current element
        solution.push_back(set[index]);
        sumOfSubsetsUtil(index + 1, currentSum + set[index]);

        // Exclude the current element (backtrack)
        solution.pop_back();
        sumOfSubsetsUtil(index + 1, currentSum);
    }

public:
    SumOfSubsets(vector<int> inputSet, int sum) 
{
        set = inputSet;
        target = sum;
  }

    void findSubsets() 
{
        sumOfSubsetsUtil(0, 0);
    }
};

int main() 
{
    vector<int> set = {10, 7, 5, 18, 12, 20, 15};
    int targetSum = 35;

    SumOfSubsets ss(set, targetSum);
    cout << "Subsets with sum " << targetSum << ":" << endl;
    ss.findSubsets();

    return 0;
}
