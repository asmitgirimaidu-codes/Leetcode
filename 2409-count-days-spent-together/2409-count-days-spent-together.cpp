#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
private:
    // Helper function to convert "MM-DD" to the day of the year (1 to 365)
    int parseDay(const string& date) {
        static const vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int dayOfYear = day;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonths[i];
        }
        return dayOfYear;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrival = parseDay(arriveAlice);
        int aliceLeave = parseDay(leaveAlice);
        int bobArrival = parseDay(arriveBob);
        int bobLeave = parseDay(leaveBob);
        
        // Find the overlap range
        int latestArrival = max(aliceArrival, bobArrival);
        int earliestLeave = min(aliceLeave, bobLeave);
        
        // Calculate overlapping days
        if (latestArrival <= earliestLeave) {
            return earliestLeave - latestArrival + 1;
        }
        
        return 0;
    }
};