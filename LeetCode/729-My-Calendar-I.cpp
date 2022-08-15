// LeetCode: 729. My Calendar I
// 729-My-Calendar-I.cpp
// Created by Victor Rogulenko
// [2022-08-15 14:54]	

// You are implementing a program to use as your calendar. We can add 
// a new event if adding the event will not cause a double booking.
// A double booking happens when two events have some non-empty intersection 
// (i.e., some moment is common to both events.).
// The event can be represented as a pair of integers start and end that 
// represents a booking on the half-open interval [start, end), the range 
// of real numbers x such that start <= x < end.
// Implement the MyCalendar class:
// MyCalendar() Initializes the calendar object.
// boolean book(int start, int end) Returns true if the event can be added 
// to the calendar successfully without causing a double booking. Otherwise, 
// return false and do not add the event to the calendar.
// 0 <= start < end <= 10^9
// At most 1000 calls will be made to book.

// MAJOR IDEA: Store the events as a sorted list of intervals. If none of 
// the events conflict, then the new event can be added.
// Time: O(N log N). Space: O(N)

#include <map>

class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto iter = calendarMap.upper_bound(start);
        if (iter != calendarMap.begin()) {
            --iter;
        }
        if (iter != calendarMap.end() && iter->second <= start) {
            ++iter;
        }
        
        // Check intersection
        if (iter != calendarMap.end() && 
            ((iter->first <= start && iter->second > start) ||
            (start <= iter->first && end > iter->first))) {
            return false;
        } else {
            calendarMap[start] = end;
            return true;
        }     
    }
    
private:
    std::map<int,int> calendarMap;   
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// #bugs = 0