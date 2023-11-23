#include <iostream>
#include <ctime>
#include "cdate.hpp"

using namespace std;

// Constructors
CDate::CDate(){
    // Default Constructor, initializing with the current Date
	tm newtime;
    const time_t now = time(nullptr);
    localtime_s(&newtime, &now);

    day_ = newtime.tm_mday;
    month_ = newtime.tm_mon + 1;
    year_ = newtime.tm_year + 1900;
}

CDate::CDate(const int d, const int m, const int y)
: year_(y), month_(m), day_(d)
{
    // Basic Custom Constructor
}

// Setters
void CDate::set_date(const int d,const int m,const int y){
    year_ = y;
    month_ = m;
    day_ = d;
}

void CDate::set_current_date(){
	tm newtime;
    const time_t now = time(nullptr);
    localtime_s(&newtime, &now);

    day_ = newtime.tm_mday;
    month_ = newtime.tm_mon + 1;
    year_ = newtime.tm_year + 1900;
}



// Display
void CDate::print() const { printf("%02i.%02i.%02i", day_, month_, year_); }
