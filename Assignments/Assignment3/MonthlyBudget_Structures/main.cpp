/* 
 * File:   
 * Author: Arlene Sagaoinit
 * Created on October 4,2021 4:15pm
 * Purpose: To record whether users budget is over or under their established monthly budget
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct MthlyBgt{        //Structure for monthley budget
    float housng;       //Housing
    float utlites;      //Transportaiton
    float expnses;      //Household expenses
    float trnsprtn;     //Transportation
    float food;
    float medical;
    float insrnce;      //Insurance
    float entrtnmnt;    //Entertainment
    float clthng;       //Clothing
    float mscllnous;    //Miscellaneious
};

void getBdget(MthlyBgt &);
void dsplyRprt(const MthlyBgt);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    MthlyBgt budget;
    
    //Initialize Variables
     
    //Process or map Inputs to Outputs
    getBdget(budget);   //Get input from user
    
    //Display Outputs
    dsplyRprt(budget);  //Display over or under in each category, and the total over or under in budget
    //Exit stage right!
    return 0;
}

void getBdget(MthlyBgt &n){
    cout<<"Enter housing cost for the month:$"<<endl;
    cin>>n.housng;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cin>>n.utlites;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin>>n.expnses;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cin>>n.trnsprtn;
    cout<<"Enter food cost for the month:$"<<endl;
    cin>>n.food;
    cout<<"Enter medical cost for the month:$"<<endl;
    cin>>n.medical;
    cout<<"Enter insurance cost for the month:$"<<endl;
    cin>>n.insrnce;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin>>n.entrtnmnt;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cin>>n.clthng;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;
    cin>>n.mscllnous;
}

void dsplyRprt(const MthlyBgt n){
    float total=1420;   //Total amount of monthly expenses
    float userTot=0;    //Users total amount of expenses 
    if(n.housng>500){
        cout<<"Housing Over"<<endl;
        userTot+=n.housng;
    }
    else if(n.housng<500){
        cout<<"Housing Under"<<endl;
        userTot+=n.housng;
    }
    else{
        cout<<"Housing Even"<<endl;
        userTot+=n.housng;
    } 
    if(n.utlites>150){
        cout<<"Utilities Over"<<endl;
        userTot+=n.utlites;
    }
    else if(n.utlites<150){
        cout<<"Utilities Under"<<endl;
        userTot+=n.utlites;
    }
    else{
        cout<<"Utilities Even"<<endl;
        userTot+=n.utlites;
    }
    if(n.expnses>65){
        cout<<"Household Expenses Over"<<endl;
        userTot+=n.expnses;
    }
    else if(n.expnses<65){
        cout<<"Household Expenses Under"<<endl;
        userTot+=n.expnses;
    }
    else{
        cout<<"Household Expenses Even"<<endl;
        userTot+=n.expnses;
    }
    if(n.trnsprtn>50){
        cout<<"Transportation Over"<<endl;
        userTot+=n.trnsprtn;
    }
    else if(n.trnsprtn<50){
        cout<<"Transportation Under"<<endl;
        userTot+=n.trnsprtn;
    }
    else{
        cout<<"Transportation Even"<<endl;
        userTot+=n.trnsprtn;
    }
    if(n.food>250){
        cout<<"Food Over"<<endl;
        userTot+=n.food;
    }
    else if(n.food<250){
        cout<<"Food Under"<<endl;
        userTot+=n.food;
    }
    else{
        cout<<"Food Even"<<endl;
        userTot+=n.food;
    }
    if(n.medical>30){
        cout<<"Medical Over"<<endl;
        userTot+=n.medical;
    }
    else if(n.medical<30){
        cout<<"Medical Under"<<endl;
        userTot+=n.medical;
    }
    else{
        cout<<"Medical Even"<<endl;
        userTot+=n.medical;
    }
    if(n.insrnce>100){
        cout<<"Insurance Over"<<endl;
        userTot+=n.insrnce;
    }
    else if(n.insrnce<100){
        cout<<"Insurance Under"<<endl;
        userTot+=n.insrnce;
    }
    else{
        cout<<"Insurance Even"<<endl;
        userTot+=n.insrnce;
    }
    if(n.entrtnmnt>150){
        cout<<"Entertainment Over"<<endl;
        userTot+=n.entrtnmnt;
    }
    else if(n.entrtnmnt<150){
        cout<<"Entertainment Under"<<endl;
        userTot+=n.entrtnmnt;
    }
    else{
        cout<<"Entertainment Even"<<endl;
        userTot+=n.entrtnmnt;
    } 
    if(n.clthng>75){
        cout<<"Clothing Over"<<endl;
        userTot+=n.clthng;
    }
    else if(n.clthng<75){
        cout<<"Clothing Under"<<endl;
        userTot+=n.clthng;
    }
    else{
        cout<<"Clothing Even"<<endl;
        userTot+=n.clthng;
    }
    if(n.mscllnous>50){
        cout<<"Miscellaneous Over"<<endl;
        userTot+=n.mscllnous;
    }
    else if(n.mscllnous<50){
        cout<<"Miscellaneous Under"<<endl;
        userTot+=n.mscllnous;
    }
    else{
        cout<<"Miscellaneous Even"<<endl;
        userTot+=n.mscllnous;
    }
    cout<<fixed<<setprecision(2)<<showpoint;    //Output amount over or under with 2 digits after decimal
    if((total-userTot)>0)
        cout<<"You were $"<<total-userTot<<" under budget";
    else
        cout<<"You were $"<<userTot-total<<" over budget";
}
