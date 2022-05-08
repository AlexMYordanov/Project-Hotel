#define HOTEL_HPP_INCLUDED

#include "Room.hpp"
#include "String.hpp"


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
    //Hotel(int);
    Room& operator[](int);
    Hotel& operator=(const Hotel&);


    friend std::ostream& operator<<(std::ostream&, const Hotel&);
    void reserve(const int);
    int* AvailableRooms(int&);
    void FreeRoom(const unsigned short);
    void CloseRoom(const unsigned short, Date&, Date&);
    const bool isAvailable(const unsigned short) const;
    int SuitableRoom(const unsigned short, Date& , Date& );


    ~Hotel();
};

#endif // HOTEL_HPP_INCLUDED
