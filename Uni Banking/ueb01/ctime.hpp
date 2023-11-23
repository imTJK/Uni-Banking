//
//  ctime.h
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#ifndef ctime_h
#define ctime_h

class CTime{
    private:
        int hour_, minute_, second_;
        
    public:
        // Constructors
        CTime();
        CTime(int, int, int = 0);

        // Setter
        void set_hour(const int hour)     { hour_ = hour;     }
        void set_minute(const int minute) { minute_ = minute; }
        void set_second(const int second) { second_ = second; }
        void set_time(int, int, int);
        void set_current_time();

        // Getter
        int get_hour() const { return hour_; }
        int get_minute() const { return minute_; }
        int get_second() const { return second_; }

        // Display
        void print() const;
};
#endif 