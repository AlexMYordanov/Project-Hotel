#include "Date.hpp"
void Date::clearDate()
{
    year=0;
    month=0;
   day=0;
}

bool Date::operator<(const Date& other) const
{
   if (year < other.year)
      return true;
   if (year == other.year && month < other.month)
      return true;
   if (year == other.year && month == other.month && day < other.day)
      return true;
   return false;
}

    bool Date::operator>( const Date& other )const
    {

        if (year >other.year)
      return true;
   if (year == other.year && month > other.month)
      return true;
   if (year == other.year && month == other.month && day > other.day)
      return true;
   return false;
    }

    bool Date::operator>=( const Date& other )const
    {
       return !(*this<other);
    }
     bool Date::operator==( const Date& other)const
     {
         return day==other.day && month==other.month && year==other.year;
     }


   //  int Date::get_day()const {return day;}
    // int Date::get_month()const{return month;}
    // int Date::get_year()const{return year;}


    bool Date::isValidDate()const
    {

      if(2022 >year || year > 2024)
           return false;

      if(1 >month || month > 12)
           return false;

      switch(month)
      {
      case 1:case 3:case 5:case 7: case 8: case 10: case 12:
             {
               if(1>day || day>31)
                  return false;
             }break;
      case 4: case 6: case 9: case 11:
             {
              if(1>day || day>30)
                 return false;
             }break;
      case 2:
            {
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            {
               if(1>day || day>29)
                 return false;
            }
            else
            {
                 if(1>day || day>28)
                   return false;
            }
            }break;
      }

      return true;
    }







