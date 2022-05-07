#include <iostream>
#include <fstream>
#include "Hotel.hpp"
#include "String.hpp"

const int max_room=100;

using namespace std;

   int main()
{
    /*
    Hotel h();
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
          }while(choice<1 || choice>7);



        unsigned short room_number;
        unsigned short beds;


        switch(choice)
        {
            case 1:{std::cin>>room_number;
                    Date one, two;
                    std::cin>>one.year>>one.month>>one.day;
                    std::cin>>two.year>>two.month>>two.day;
                    String name;
                    String note;
                    name.get_line();
                    note.get_line();
                    h[room_number-1].set_name(name);
                   h[room_number-1].set_note(note);
                 h[room_number-1].set_start(one);
                   h[room_number-1].set_finish(two);
                   }break;

            case 2: std::cout<<h.AvailableRooms();break;

            case 3: std::cout<<"Please enter a room number: ";
                    std::cin>>room_number;
                    h.FreeRoom(room_number);break;
            case 4: break;

            case 5: std::cout<<"Please enter the desired number of beds: ";
                    std::cin>>beds;
                    std::cout<<h.SuitableRoom(beds);break;

            case 6:  std::cout<<"Please enter a room number: ";
                    std::cin>>room_number;
                    h.CloseRoom(room_number);break;
        }
    }while(choice!=7);
     std::cout<<h;
     */
    return 0;
}
