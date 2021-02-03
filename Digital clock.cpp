/******************************************************************************

This project was done only for learning purpose
references (1) https://www.codespeedy.com/digital-clock-in-cpp/
           (2)https://www.codespeedy.com/date-and-time-in-cpp/

*******************************************************************************/


#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    int sec_inti=0;
    while(1)
    {
        int hr,min, sec;
        string str;
        //time(0) is called to store total seconds in total_seconds variable.
        time_t total_seconds=time(0);
        //localtime()function splits the seconds into hours, minutes and seconds and returns a structure tm*
        struct tm* ct=localtime(&total_seconds);
        //extract the time value from the structure variable
        hr=ct->tm_hour; //get hours in hr
        min=ct->tm_min; // get minutes 
        sec=ct->tm_sec; // get seconds


        //showing output time
        if(sec==sec_inti+1 || (sec_inti==59 && sec==0))
        {
        system("CLS"); //statement to clear the screen for each interval
        cout<< (hr<10?"0":"") << hr <<":" << (min<10?"0":"") << min << ":" << (sec<10?"0":"") << sec << " " << str <<endl;
        }
    
        sec_inti=sec;
    
         }
    return 0;
}

