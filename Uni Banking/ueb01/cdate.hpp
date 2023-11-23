//
//  cdate.h
//  Uni Banking
//
//  Created by Tj on 16.10.23.
//

#ifndef cdate_h
#define cdate_h

class CDate {
    private:
        int year_, month_, day_;

    public:
        // Constructors
        CDate();
        CDate(int, int, int);

        // Setter
        void set_date(int, int, int);
        void set_current_date();

        // Getter
        int get_day() const { return day_; }
        int get_month() const { return month_; }
        int get_year() const { return year_; }

        // Display
        void print() const;
};
#endif
