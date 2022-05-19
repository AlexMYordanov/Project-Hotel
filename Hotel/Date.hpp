#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

class Date
{
    public:
    int year;
    int month;
    int day;

    Date():year(0),month(0), day(0){};
    void clearDate();
    bool operator<( const Date& )const;
    bool operator>( const Date&  )const;
    bool operator>=( const Date&  )const;
    bool operator==( const Date& )const;
    bool isValidDate()const;
};

#endif // DATE_HPP_INCLUDED
