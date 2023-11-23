#include <iostream>
#include <ctime>  
#include "ctime.hpp"

using namespace std;


// Constructors
CTime::CTime(){
    // Default Constructor, initializing with the current Time
	tm newtime;
    const time_t now = time(nullptr);
    localtime_s(&newtime, &now);

    hour_ = newtime.tm_hour;
    minute_ = newtime.tm_min;
    second_ = newtime.tm_sec;
}

CTime::CTime(const int h,const int m,const int s)
: hour_(h), minute_(m), second_(s)
{
    // Basic Custom Constructor
}



void CTime::set_time(const int h,const int m,const int s){
    hour_ = h;
    minute_ = m;
    second_ = s;
}

void CTime::set_current_time(){
	tm newtime;
    const time_t now = time(nullptr);
    localtime_s(&newtime, &now);

    hour_ = newtime.tm_hour;
    minute_ = newtime.tm_min;
    second_ = newtime.tm_sec;
}



// Display
void CTime::print() const {
    if (second_ != 0) {
        printf("%02i:%02i:%02i", hour_, minute_, second_);
    }
    else {
        printf("%02i:%02i", hour_, minute_);
    }
}
