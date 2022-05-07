#include "Hotel.hpp"
#include <cstring>



Hotel::Hotel()
{
    rooms=nullptr;
    capacity=0;
}

Hotel::Hotel(Room* _rooms, int _cap )
{
    capacity=_cap;
    rooms=_rooms;
}
void Hotel::reserve(int size)
{
    if(size<capacity)
        return ;
    if(capacity!=0)
    {
       // rooms* buff=new Room[size];
        for(int i=0;i<capacity;++i)
        {
          //  buff[i]=rooms[i];
        }
    delete[] rooms;
    //rooms=buff;
   // buff=nullptr;
    capacity=size;
    }
    else
        {
        capacity=size;
        rooms=new Room[size];
        }
   for(int i=0; i<capacity;++i)
   {
       rooms[i].set_number(i+1);
   }
}

void Hotel::cpy(const Hotel& other)
{
    if(rooms!=nullptr)
    {
       delete[] rooms;
    }
    capacity=other.capacity;
    rooms= new Room[capacity];
    for(int i=0; i<capacity; ++i)
    {
        rooms[i]=other.rooms[i];
    }

}
Hotel::Hotel(const Hotel& other)
{
    cpy(other);
}

Hotel& Hotel::operator=(const Hotel& other)
{
    if(this!=&other)
    {
        cpy(other);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Hotel& other)
{
    for(int i=0;i<other.capacity; ++i)
    {
        os<<other.rooms[i]<<'\n';
    }
    return os;
}

Room& Hotel::operator[](int i)
{
    if(i<capacity)
       return rooms[i];
    else
       std::cerr<<"Room does not exist!";
}
/*
int* Hotel::AvailableRooms()
{
    int cnt=0;
    for(int i=0; i<capacity; ++i)
        {
            if(rooms[i].get_name()=="None." && rooms[i].get_note()=="None.")
                cnt++;
        }
    int* res= new int[cnt];
    int index=0;
    for(int i=0; i<capacity; ++i)
        {
            if(rooms[i].get_name()=="None." && rooms[i].get_note()=="None.")
                res[index++]=i+1;
        }
    return res;
}
*/
void Hotel::FreeRoom(const unsigned short _number)
{
   rooms[_number-1].free_room();
}

void Hotel::CloseRoom(const unsigned short _number, Date& start, Date& finish)
{
    rooms[_number-1].close(start,finish);
}
/*
const bool Hotel::isAvailable(const unsigned short _number) const
{
    for(int i=0;i<capacity;++i)
    {
        if(rooms[i].get_number()==_number && rooms[i].get_name()=="None.")
                 return true;
    }
    return false;
}
*/
 int Hotel::SuitableRoom(const unsigned short _beds)
 {
  //sort rooms by operator<
  //for if(room i.get beds()==_beds && funk dali e svobodna v reriod)
  //  return room.get num();

 }
Hotel::~Hotel()
{
    delete[] rooms;
    rooms=nullptr;
}
