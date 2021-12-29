/* 
 * File:   Date.h
 * Author: Arlene Sagaoinit
 * Created on November 1, 2021, 6:05 PM
 * Purpose: Date class containing date member variables
 */

#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int day;    
        int month;
        int year;
    public:
        void setDay(int);       //Gives day variable a value
        void setMnth(int);      //Gives month variable a value
        void setYear(int);      //Gives year variable a value
        int getDay()const;      //Returns value of day
        int getMnth()const;     //Returns value of month
        int getYear()const;     //Returns value of year
        string strMnth()const;  //Returns string equivalent of month value
};

void Date::setDay(int d){
    while(d<1||d>31){
        cout<<"Invalid please enter a number between 1-31: ";
        cin>>d;
    }
    day=d;
}
void Date::setMnth(int m){
    while(m<1||m>12){
        cout<<"Invalid please enter a number between 1-12: ";
        cin>>m;
    }
    month=m;
}
void Date::setYear(int y){
    year=y;
}
int Date::getDay()const{
    return day;
}
int Date::getMnth()const{
    return month;
}
int Date::getYear()const{
    return year;
}
string Date::strMnth()const{
    string mnth;
    mnth=month==1?"January":
         month==2?"February":
         month==3?"March":
         month==4?"April":
         month==5?"May":
         month==6?"June":
         month==7?"July":
         month==8?"August":
         month==9?"September":
         month==10?"October":
         month==11?"November":
         month==12?"December":"";
    return mnth;
}
#endif /* DATE_H */

