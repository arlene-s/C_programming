#include <iostream>
#include <iomanip>
using namespace std;

struct Machine{
    string name;    //Name of drink
    int cost;       //Price of drink
    int nDrnks;     //Number of drinks in machine
};


void print(Machine [], int);
void calChnge(Machine [], int); //Calculates change and updates number of drinks in machine
int main(){
    const int SIZE=5;
    Machine array[SIZE]={{"Cola",75,20},
                         {"Root Beer",75,20},
                         {"Lemon-Lime",75,20},
                         {"Grape Soda",80,20},
                         {"Cream Soda",80,20}};
    
    bool quit=false;
    int total=0;
    string choice;
    do{
        print(array, SIZE);
        getline(cin, choice);
        if(choice=="Cola"){
            calChnge(array, 0);
            total+=array[0].cost;
        }else if(choice=="Root Beer"){
            calChnge(array, 1);
            total+=array[1].cost;
        }else if(choice=="Lemon-Lime"){
            calChnge(array, 2);
            total+=array[2].cost;
        }else if(choice=="Grape Soda"){
            calChnge(array, 3);
            total+=array[3].cost;
        }else if(choice=="Cream Soda"){
            calChnge(array, 4);
            total+=array[4].cost;
        }else
            quit=true;
    }while(quit==false);
    cout<<total<<endl;
    
    return 0;
}

void print(Machine a[], int n){
    for(int i=0; i<n; i++){
        cout<<setw(11)<<left
            <<a[i].name<<setw(4)
            <<a[i].cost
            <<a[i].nDrnks
            <<endl;
    }
    cout<<"Quit"<<endl;
}

void calChnge(Machine a[], int choice){
    int amount, change;
    cin>>amount;
    cin.ignore();
    a[choice].nDrnks--;
    
    while(amount<0||amount>100){
        cout<<"Please enter amount between $0 and $1";
        cin>>amount;
    }
    change=amount-a[choice].cost;
    cout<<change<<endl;
}