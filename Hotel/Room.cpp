#include "Room.hpp"
Room::Room()
{
    number=-1;
    beds=-1;
    name="None";
    note="None";
    start={0,0,0};
    finish={0,0,0};
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
    start={0,0,0};
    finish={0,0,0};
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
/*
 bool Room::NotOccupied( Date& _start, Date& _finish)const
 {
     return name == "None" && note == "None" && (this->start>_finish || this->finish<_start);
 }
*/
