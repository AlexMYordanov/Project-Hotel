#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

#include <iostream>
#include "String.hpp"
struct Date
{
    int year;
    int month;
    int day;
    bool operator<( Date& other)
    {
        if(year<other.year)
            return true;
        else if(month<other.month)
            return true;
        else if(day<other.day)
            return true;
      return false;
    }

    bool operator>( Date& other )
    {

        if(year>other.year)
            return true;
        else if(month>other.month)
            return true;
        else if(day>other.day)
            return true;
      return false;
    }


};
class Room
{
    private:
        unsigned short number;
        unsigned short beds;
        String name;
        String note;
        Date start;
        Date finish;

    public:
        Room();
        Room(unsigned short _number, unsigned short _beds,String _name,String _note, Date _start, Date _finish): number(_number), beds(_beds), name(_name),note(_note),start(_start),finish(_finish){}

        void set_number(unsigned short _number)
        {
            number=_number;
            beds=number%3+1;
        }
        void set_name(const String& _name){name=_name;}
        void set_note(const String&  _note){note=_note;}
        void set_start_date(const Date& _start){start=_start;}
        void set_finish_date(const Date& _finish){finish=_finish;}


         String get_name()const {return name;}
         String get_note()const {return note;}
        const unsigned short get_number()const {return number;}
        const unsigned short get_beds()const {return beds;}

        Room& operator=(const Room&);
        bool operator>(const Room&);
        bool NotOccupied( Date& , Date& )const;
        void free_room();
        void close(Date& , Date& );
        friend std::ostream& operator<<(std::ostream&, const Room&);

};

#endif // ROOM_HPP_INCLUDED
