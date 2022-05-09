#ifndef HOTEL_HPP_INCLUDED
#define HOTEL_HPP_INCLUDED

#include "Room.hpp"



class Hotel
{
    private:
    Room* rooms;
    int capacity;

    void cpy(const Hotel&);

    public:
    Hotel();
    Hotel(Room*,int);
    Hotel(const Hotel&);
    Room& operator[](int);
    Hotel& operator=(const Hotel&);


    friend std::ostream& operator<<(std::ostream&, const Hotel&);
    void reserve(const int);
    int* AvailableRooms(int&);
    void FreeRoom(const unsigned short);
    void CloseRoom(const unsigned short, Date&, Date&);
     bool isAvailable(const unsigned short) const;
    int SuitableRoom(const unsigned short,const Date& ,const Date& );

    ~Hotel();
};

#endif // HOTEL_HPP_INCLUDED
