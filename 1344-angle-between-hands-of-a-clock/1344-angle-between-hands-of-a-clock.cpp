class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Each minute the minute hand moves 360 / 60 = 6 degrees
        double minuteAngle = minutes * 6.0;
        
        // Each hour the hour hand moves 360 / 12 = 30 degrees, 
        // plus an additional 30 / 60 = 0.5 degrees per minute
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        
        double diff = abs(hourAngle - minuteAngle);
        
        // Return the smaller angle
        return min(diff, 360.0 - diff);
    }
};