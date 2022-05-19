#include "Room.hpp"
Room::Room()
{
    number=-1;
    beds=-1;
    name="None";
    note="None";
}

std::ostream& operator<<(std::ostream& os, const Room& other)
{
    os<<"Room: "<<other.number<<" - "<<other.beds;
    if(other.beds>1)
        os<<" beds";
    else
        os<<" bed";
    os<<". Guest name: "<<other.name
      <<". Note: "<<other.note
      <<". Occupation period: "<<other.start.day<<':'
                               <<other.start.month<<':'
                               <<other.start.year<<" - "
                               <<other.finish.day<<':'
                               <<other.finish.month<<':'
                               <<other.finish.year;

    return os;
}

Room& Room::operator=(const Room& other)
{
    if(this!=&other)
        {
        number=other.number;
        beds=other.beds;

        name=other.name;
        note=other.note;

        start.day=other.start.day;
        start.month=other.start.month;
        start.year=other.start.year;

        finish.day=other.finish.day;
        finish.month=other.finish.month;
        finish.year=other.finish.year;
    }

    return *this;
}
void Room::free_room()
{
    name="None";
    note="None";
    start.clearDate();
    finish.clearDate();
}
void Room::close(Date& _start,Date& _finish)
{
    note="In maintenance!";
    start=_start;
    finish=_finish;
    name="None";
}
bool Room::operator>(const Room& other)
{
    return beds>other.beds;
}

 bool Room::NotOccupied(const Date& _start, const Date& _finish)const
 {
     return name == "None" && note == "None" && (start>_finish || finish<_start);
 }

int Room::Used(unsigned short _number,const Date& _start,const Date& _finish )const
{
    Date none;

        if(this->get_number()==_number )
        {
            if(this->get_start()== none || this->get_start()>_finish || this->get_finish()<_start)
                return 0;
            else
            {
                if(this->get_start()<_start && this->get_finish()<_finish)
                    return Difference(_start,this->get_finish());

               else if(this->get_start()<_start && this->get_finish()>_finish)
                    return Difference(_start,_finish);

                else if(this->get_start()>_start && this->get_finish()<_finish)
                    return Difference(this->get_start(),this->get_finish());

                else if(this->get_start()>_start && this->get_finish()>_finish)
                    return Difference(this->get_start(),_finish);
            }
        }

}
int Room::Difference(const Date& _start,const Date& _finish) const
{

    const int month_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
   long int days_start = (_start.year * 365);

   for (int i = 0; i < _start.month - 1; i++)

        days_start += month_days[i];


   days_start += _start.day;



   long int days_finish= (_finish.year * 365);
    for (int i = 0; i < _finish.month - 1; i++)
        days_finish += month_days[i];

   days_finish += _finish.day;


   int days=days_finish -days_start;

   return  (_finish.year==2024 && _finish.month>=2) ? days + 1 : days ;

}
