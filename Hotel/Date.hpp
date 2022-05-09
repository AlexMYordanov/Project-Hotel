#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

struct Date
{
    int year;
    int month;
    int day;
    // void set_year(const int _year){year=_year;}
    //  void set_month(const int _month){month=_month;}
    //   void set_day(const int _day){day=_day;}


    bool operator<( const Date& )const;
    bool operator>( const Date&  )const;
    bool operator==( const Date& )const;
    int get_day()const;
    bool isValidDate()const;
    //bool LeapYearDay(const Date&,const Date&) const;
    //int Difference(Date& , Date&);



};

#endif // DATE_HPP_INCLUDED
