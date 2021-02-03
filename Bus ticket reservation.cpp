/******************************************************************************
This project was done only for learning purposes.
References:https://www.studynr.com/2020/01/Bus-Reservation-System-C-Programming-Source-Code.html

*******************************************************************************/
#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

int b = 0;

class rtk
{

  char busn[5], driver[10], arrival[10], depart[10], from[10], to[10],
    seatn[8][4][10];

public:
// Adds a New Bus 
  void installBus ();		

  void Seatallotment ();	

  void emptyseat ();	

  void Availableseats ();	

  void Availablebuses ();	

  void Reservedseats (int i);	
}

bus[10];			


void vline (char ch)
{

  for (int i = 80; i > 0; i--)
    {
      cout << ch;
    }
  cout << endl;

}

void rtk::installBus ()
{

  cout << "Please choose  bus number: ";

  cin >> bus[b].busn;

  cout << "Select Driver's name: \n";

  cin >> bus[b].driver;

  cout << "Arrival :\n ";

  cin >> bus[b].arrival;

  cout << "Departure:\n ";

  cin >> bus[b].depart;

  cout << "\nFrom: \t\t\t";

  cin >> bus[b].from;

  cout << "\nTo: \t\t\t";

  cin >> bus[b].to;

  bus[b].emptyseat ();		

  b++;				

}

// allocate seat in a bus
void rtk::Seatallotment()

{

  int seatn;  

  char number[5]; 

  top:

  cout<<"Bus number: ";

  cin>>number;

  int n;

  for(n=0;n<=b;n++)

  {

    if(strcmp(bus[n].busn, number)==0) //Check if bus number exist or not

    break;

  }

  while(n<=b)

  {

    cout<<"Seat Number:\n ";

    cin>>seatn;

    if(seatn>32) //Can't allocate as there are only 32 seats
    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seatn[seatn/4][(seatn%4)-1], "Empty")==0) // used to break the seat number in row-column basis.

      {

        cout<<"Write your name: ";

        cin>>bus[n].seatn[seatn/4][(seatn%4)-1];

        break;

      }

    else

      cout<<"This seat is reserved.\n";

      }

      }

    if(n>b)

    {

      cout<<"Enter correct bus no.\n";

      goto top;

    }

  }
  
 //Makes all the seats empty
void rtk::emptyseat()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[b].seatn[i][j], "Empty");

    }

  }

}


// check available seats in a bus
void rtk::Availableseats()

{

  int n;

  char number[5];

  cout<<"Please choose  bus number: ";

  cin>>number;

  for(n=0;n<=b;n++)

  {

    if(strcmp(bus[n].busn, number)==0) 

    break;

  }

while(n<=b)

{

  vline('-'); // Prints a line with '-'
  cout<<"\nBus number: \t"<<bus[n].busn

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('-');

  bus[0].Reservedseats(n); //Checks for reserved seats in the current bus.

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seatn[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seatn[i][j]<<".";

    }

  }

  break;

  }

  if(n>b)

    cout<<"Enter correct bus no: ";

}

//check empty and reserved seats 
void rtk::Reservedseats(int l)
{

  int s=0,h=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seatn[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seatn[i][j];

          h++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seatn[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<h<<" seats empty in Bus number: "<<bus[l].busn;

  }

//check all buses 
void rtk::Availablebuses()

{

  for(int n=0;n<b;n++)

  {

    vline('-');

    cout<<"Bus number: \t"<<bus[n].busn<<"\nDriver name: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    vline('*');

    vline('_');

  }

}


//Main function
int main()

{

system("cls");
  
 int w;

while(1)

{

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.Install\n\t\t\t"

  <<"2.Reservation\n\t\t\t"

  <<"3.Show\n\t\t\t"

  <<"4.Buses Available. \n\t\t\t"

  <<"5.Exit";

  cout<<"\n\t\t\tPlease choose  bus number ";

  cin>>w;

  switch(w)

  {

    case 1:  bus[b].installBus();

      break;

    case 2:  bus[b].Seatallotment();

      break;

    case 3:  bus[0].Availableseats();

      break;

    case 4:  bus[0].Availablebuses();

      break;

    case 5:  {
      
      exit(0);
    };

  }

}

return 0;

}

 

