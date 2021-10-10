/* 
 * Author: Arlene Sagaoinit
 * Created on October 10, 2021, 8:06 AM
 * Purpose: Keep track of a speakers bureau and display speaker's information
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //setw()
using namespace std;  //Libraries compiled under std

//User Level Libraries/Includes here.  On Code-E we have to put
//structures and classes here before main but you would never do this
//for normal projects.  We would just include many .h files
struct SpkrDat{       //Structure holding speakers data
    string name;
    string telNum;
    char *topic;      //Array holding speaking topic
    unsigned short fee;
};

struct Speakrs{       //Structure holding array of speakers and the size of array
    int nSpkrs;       //Number of speakers
    SpkrDat *speakr;  //Pointer to speaker data struct
};

//Global Constants Only - Science/Math Related, Conversions, Higher
//Dimensions.  Put Global Variables anywhere in your program i.e. variables
//not contained in functions and I will give you an F!  Local variables
//only allowed.

//Function Prototypes here, Function implementations after main!
void getData(Speakrs *, int &);  //Grabs data from user and implement into struct
int findIdx(Speakrs *, string);  //Find and return element of speaker user wants to modify
void modInfo(Speakrs *);         //Modify speaker info if speaker found
void display(Speakrs *);            
void destroy(Speakrs *);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here.  No-where else.  Only done once!
    
    //Variable Declarations
    int size=10;                     //Greatest size array of speakers can be
    Speakrs *spkrs;
    bool quit=false;                 
    int count=0;                     //Holds index for each new speaker added
    
    //Variable Initialization
    spkrs=new Speakrs;
    spkrs->speakr=new SpkrDat[size]; //Allocate memory to pointer to speaker data struct
    
    //Mapping Process Inputs to Outputs
    do{
        cout<<"Enter the option you would like to perform: "<<endl
            <<"1) Enter a new speaker"<<endl
            <<"2) Modify a speakers info"<<endl
            <<"3) Display all speakers and their info"<<endl
            <<"4) Quit"<<endl;
        char choice;
        cin>>choice;
        switch(choice){
            case '1': cin.ignore();
                      getData(spkrs, count);
                      count++;
                      spkrs->nSpkrs=count;
                      break;
            case '2': modInfo(spkrs);
                      break;
            case '3': display(spkrs);
                      break;
            case '4': quit=true;
                      break;
            default:  cout<<"Invalid choice"<<endl;
        }
    }while(quit==false);
    //Clean Up
    destroy(spkrs);
    //Exit stage right!
    return 0;
}
void destroy(Speakrs *spkrs){
    for(int i=0; i<spkrs->nSpkrs;i++){
        delete []spkrs->speakr[i].topic;    //Deallocate topic array in structure
    }
    delete []spkrs->speakr;                 //Deallocate pointer to structure
    delete spkrs;                           //Deallocate structure
}

void display(Speakrs *spkrs){
    if(spkrs->nSpkrs>0){
        for(int i=0; i<spkrs->nSpkrs; i++){
            cout<<left
                <<setw(12)<<"Name: "<<spkrs->speakr[i].name<<endl
                <<setw(12)<<"Telephone: "<<spkrs->speakr[i].telNum<<endl
                <<setw(12)<<"Topic: "<<spkrs->speakr[i].topic<<endl
                <<setw(12)<<"Fee: "<<spkrs->speakr[i].fee<<endl
                <<endl;
        }
    }else
        cout<<"No speakers listed"<<endl;
}

int findIdx(Speakrs *spkrs, string name){
    if(spkrs->nSpkrs>0){
        for(int i=0; i<spkrs->nSpkrs;i++){
            if(spkrs->speakr[i].name==name) //Search for match
                return i;                   //if found return index
        }
    }
    return -1;                              //Otherwise return -1
}                                           //if no speakers listed or found

void modInfo(Speakrs *spkrs){
    if(spkrs->nSpkrs>0){    
        string name;
        cout<<"Enter name of speaker to modify: ";
        cin.ignore();
        getline(cin, name);
        if(findIdx(spkrs, name)==-1)            //Pass in name to find
            cout<<"No speakers found"<<endl;
        else{
            int index=findIdx(spkrs, name);     //Return index found
            getData(spkrs, index);              //Grab new info 
        }
    }else
        cout<<"No speakers listed"<<endl;
}

void getData(Speakrs *spkrs, int &index){
    cout<<"Enter name of speaker: ";
    getline(cin, spkrs->speakr[index].name);
    cout<<"Enter speaker's telephone: ";
    cin>>spkrs->speakr[index].telNum;
    int num=81;
    spkrs->speakr[index].topic=new char[num];
    cout<<"Enter speaking topic: ";
    cin.ignore();
    cin.getline(spkrs->speakr[index].topic, num-1);
    cout<<"Enter fee required: ";
    cin>>spkrs->speakr[index].fee;
}
