#include <iostream>
#include <fstream>
#include "Hotel.hpp"

const int max_room=100;


   int main()
{

    Hotel h;
    h.reserve(max_room);

    std::ofstream file("Valid_rooms.txt");
    if(!file.is_open())
    {
        std::cout<<"error";
        return 1;
    }
    file<<"List of valid rooms:\n";
    int cnt=0;
    int* valid=h.AvailableRooms(cnt);
       for(int i=0;i<cnt;++i)
         file<<"Room: "<<valid[i]<<'\n';
    file.close();
    delete[] valid;
    valid=nullptr;


    std::cout<<"Choose one of the following:\n";
    std::cout<<"1. Client registration.\n";
    std::cout<<"2. List of available rooms by date.\n";
    std::cout<<"3. Freeing a room.\n";
    std::cout<<"4. List of rooms and days of occupation.\n";
    std::cout<<"5. Find most suitable room.\n";
    std::cout<<"6. Indicate maintenance.\n";
    std::cout<<"7. List of all rooms and current status.\n";
    std::cout<<"8. Exit.\n";

    unsigned short choice;
    unsigned short room_number;
    unsigned short beds;

    do{
        do{
          std::cout<<"\nEnter a command:";
          std::cin>>choice;
          }while(choice<1 || choice>8  || !std::cin);


        switch(choice)
        {
            case 1:{
                    std::cout<<"Please enter a room number: ";
                    std::cin>>room_number;

                    Date one, two;

                    do{
                    std::cout<<"Please enter start of reservation: ";
                    std::cin>>one.day>>one.month>>one.year;
                    std::cout<<"Please enter end of reservation: ";
                    std::cin>>two.day>>two.month>>two.year;

                    }while(!one.isValidDate() ||  !two.isValidDate() || one>=two);

                    std::cout<<"Please enter guest name: ";
                    String name;
                    std::cin.ignore();
                    name.get_line();

                    h[room_number-1].set_name(name);
                    h[room_number-1].set_start_date(one);
                    h[room_number-1].set_finish_date(two);
                    }break;

            case 2:  {
                    Date one;
                    do{
                    std::cout<<"Please enter date: ";
                    std::cin>>one.day>>one.month>>one.year;
                    }while(!one.isValidDate());
                     int cnt=0;
                     int* available=h.AvailableRoomsByDate(cnt,one);
                     for(int i=0;i<cnt;++i)
                        std::cout<<available[i]<<' ';
                     delete[] available;
                     available=nullptr;
                     }break;

            case 3: {std::cout<<"Please enter a room number: ";
                    std::cin>>room_number;
                    h.FreeRoom(room_number);}break;

            case 4: {
                    Date one, two;

                    do{
                    std::cout<<"Please enter start of period: ";
                    std::cin>>one.day>>one.month>>one.year;
                    std::cout<<"Please enter end of period: ";
                    std::cin>>two.day>>two.month>>two.year;
                    }while(!one.isValidDate() ||  !two.isValidDate() || one>=two);


                     char title[22]="report-";

                     char c;
                     for(int i=0, j=10; i<4 && j>6;++i,--j)
                     {
                          c=one.year%10+48;
                          title[j]=c;
                         one.year/=10;
                     }
                     title[11]='-';
                     for(int i=0, j=13; i<2 && j>11;++i,--j)
                     {
                          c=one.month%10+48;
                         title[j]=c;
                         one.month/=10;
                     }
                      title[14]='-';
                      for(int i=0, j=16; i<2 && j>14;++i, --j)
                     {
                          c=one.day%10+48;
                         title[j]=c;
                         one.day/=10;
                     }

                     title[18]='.';
                     title[19]='t';
                     title[20]='x';
                     title[21]='t';


                    std::ofstream file(title);
                        if(!file.is_open())
                        {
                            std::cerr<<"error";
                            return 1;
                        }
                        for(int i=0;i<max_room;++i)
                                file<<"Room "<<h[i].get_number()<<":  "
                                   <<h[i].Used(h[i].get_number(),one,two)<<" days\n";
                        file.close();}break;

            case 5: {std::cout<<"Please enter the desired number of beds: ";
                    std::cin>>beds;

                    if(!std::cin)
                       std::cerr<<"Not a number!\n";
                    Date one, two;

                     do{
                    std::cout<<"Please enter start of period: ";
                    std::cin>>one.day>>one.month>>one.year;
                    std::cout<<"Please enter end of period: ";
                    std::cin>>two.day>>two.month>>two.year;
                    }while(!one.isValidDate() ||  !two.isValidDate() || one>=two);

                    std::cout<<"Number of a suitable room: ";
                    std::cout<<h.SuitableRoom(beds,one,two);}break;

            case 6:{ std::cout<<"Please enter a room number: ";
                    std::cin>>room_number;
                    Date one, two;
                     do{
                    std::cout<<"Please enter start of maintenance: ";
                    std::cin>>one.day>>one.month>>one.year;
                    std::cout<<"Please enter end of maintenance: ";
                    std::cin>>two.day>>two.month>>two.year;
                    }while(!one.isValidDate() ||  !two.isValidDate()|| one>=two);

                    h.CloseRoom(room_number,one,two);}break;

           case 7:{std::cout<<h;}break;
        }

    }while(choice!=8);


    return 0;
}
