#include<iostream>
using namespace std;

int main()
{
    int working_days_of_John;
    int working_hours_of_John;
    int working_minutes_of_John;
    int working_days_of_Bill;
    int working_hours_of_Bill;
    int working_minutes_of_Bill;
    int sum_of_hours;
    int sum_of_days;
    int sum_of_minutes;

    cout<<"Please enter the number of days John has worked: "
    <<" Please enter the number of hours John has worked: "
    <<" Please enter the number of minutes John has worked: "
    <<" Please enter the number of days Bill has worked: "
    <<" Please enter the number of hours Bill has worked: "
    <<" Please enter the number of minutess Bill has worked: "<<endl;

    cin>>working_days_of_John>>working_hours_of_John>>working_minutes_of_John>>working_days_of_Bill>>working_hours_of_Bill>>working_minutes_of_Bill;


           sum_of_days=working_days_of_John+working_days_of_Bill;
           sum_of_hours=working_hours_of_John+working_hours_of_Bill;
           sum_of_minutes=working_minutes_of_John+working_minutes_of_Bill;

    cout<<"The total both of them worked together is "<<sum_of_days<<" days, "<<sum_of_hours<<" hours and "<<sum_of_minutes<<" minutes."<<endl;

    return 0;

}