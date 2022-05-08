#include <iostream>
#include <fstream>
#include "Hotel.hpp"
#include "String.hpp"

const int max_room=100;

using namespace std;

   int main()
{

    Hotel h;
    h.reserve(max_room);
    std::ofstream file("database.txt");
    if(!file.is_open())
    {
        std::cout<<"error";
        return 1;
    }
    file<<h<<'\n';
    file.close();

    std::cout<<"Choose one of the following:\n";
    std::cout<<"1. Client registration.\n";
    std::cout<<"2. List of available rooms by date.\n";
    std::cout<<"3. Freeing a room.\n";
    std::cout<<"4. Rooms status.\n";
    std::cout<<"5. Room filter.\n";
    std::cout<<"6. Indicate maintenance.\n";
    std::cout<<"7. Exit.\n";

    unsigned short choice;
    unsigned short room_number;
    unsigned short beds;

    do{
        do{
          std::cout<<"\nEnter a command:";
          std::cin>>choice;
          }while(choice<1 || choice>7 );



        unsigned short room_number;
        unsigned short beds;


        switch(choice)
        {
            case 1:{
                    std::cout<<"Please enter a room number: ";
                    std::cin>>room_number;

                    Date one, two;
                    std::cout<<"Please enter start of reservation: ";
                    std::cin>>one.year>>one.month>>one.day;
                    std::cout<<"Please enter end of reservation: ";
                    std::cin>>two.year>>two.month>>two.day;
                    std::cout<<"Please enter guest name: ";

                    String name;
                    std::cin.ignore();
                    name.get_line();

                    std::cout<<"Please enter a note: ";
                    String note;
                    note.get_line();

                    h[room_number-1].set_name(name);
                    h[room_number-1].set_start_date(one);
                    h[room_number-1].set_finish_date(two);
                    }break;

            case 2:  {int cnt=0;
                     int* available=h.AvailableRooms(cnt);
                     for(int i=0;i<cnt;++i)
                        std::cout<<available[i]<<' ';

                     }break;

            case 3: {std::cout<<"Please enter a room number: ";
                    std::cin>>room_number;
                    h.FreeRoom(room_number);}break;

            case 4: break;

            case 5: {std::cout<<"Please enter the desired number of beds: ";
                    std::cin>>beds;
                    Date one, two;
                    std::cout<<"Please enter start of period: ";
                    std::cin>>one.year>>one.month>>one.day;
                    std::cout<<"Please enter end of period: ";
                    std::cin>>two.year>>two.month>>two.day;
                    std::cout<<h.SuitableRoom(beds,one,two);}break;

            case 6:{ std::cout<<"Please enter a room number: ";
                    std::cin>>room_number;
                    Date one, two;
                    std::cout<<"Please enter start of maintenance: ";
                    std::cin>>one.year>>one.month>>one.day;
                    std::cout<<"Please enter end of maintenance: ";
                    std::cin>>two.year>>two.month>>two.day;
                    h.CloseRoom(room_number,one,two);}break;
        }

    }while(choice!=7);
     std::cout<<h;

    return 0;
}
