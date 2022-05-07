#include "Room.hpp"
Room::Room()
{
    number=-1;
    beds=-1;
    name="None.";
    note="None.";
    start={0,0,0};
    finish={0,0,0};
}

//fix
std::ostream& operator<<(std::ostream& os, const Room& other)
{
    os<<"Room: "<<other.number<<" - "<<other.beds;
    if(other.beds>1)
        os<<" beds";
    else
        os<<" bed";
    return os;
}

Room& Room::operator=(const Room& other)
{
    if(this!=&other)
        {
        number=other.number;
        beds=other.beds;
        //fix
    }

    return *this;
}
void Room::free_room()
{
    name="None.";
    note="None.";
    start={0,0,0};
    finish={0,0,0};
}
void Room::close(Date& _start,Date& _finish)
{
    note="In maintenance!";
    start=_start;
    finish=_finish;
    name="None.";
}
bool Room::operator<(const Room& other)
{
    return beds<other.beds;
}
