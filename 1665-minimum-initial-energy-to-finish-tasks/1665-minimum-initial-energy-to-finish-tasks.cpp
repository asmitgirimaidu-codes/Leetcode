class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks based on the difference (minimum - actual) in descending order,
        // or based on minimum energy requirements in descending order.
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int currentEnergy = 0;
        int totalEnergy = 0;
        
        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];
            
            if (currentEnergy < minimum) {
                totalEnergy += (minimum - currentEnergy);
                currentEnergy = minimum;
            }
            
            currentEnergy -= actual;
        }
        
        return totalEnergy;
    }
};