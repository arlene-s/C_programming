#include <iostream>
#include <iomanip> //To use setprecision() 
using namespace std;

//Function prototypes
struct MovData{              //Structure of movie information
    string title;
    char *dirctr;            //Dynamic array in structure
    unsigned short year;     //Year never negative, don't need more than 4 digits
    unsigned short runTime;  //Movie run time in minutes never negative
};

struct Movies{               //Sructure holding movies in an array and size of array
    int nMovies; 
    MovData *mveInfo;        //Dynamic array points to the MovData structure
};

Movies *fillDat();           //Fill structure with movie data
void prntDat(Movies *);      //Display movie information
void destroy(Movies *);      //Deallocate memory

int main(){
    //your code here
    Movies *movies;          //Create a pointer to movies structure
    //Variable declarations
    movies=fillDat();        //Fill structure
    //Outputs
    prntDat(movies);
    //Clean up
    destroy(movies);
    //Exit

    return 0;
}

void destroy(Movies *movies){
    for(int i=0; i<movies->nMovies;i++){
        //Deallocate char arrays in mveInfo structure
        delete [] movies->mveInfo[i].dirctr;
    }
    delete [] movies->mveInfo; //Deallocate array in movies structure
    delete movies;             //Deallocate structure
}

Movies *fillDat(){
    //Create a pointer to movies structure
    Movies *movies=new Movies;
    
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)."<<endl;
    cin>>movies->nMovies;
    
    //Dynamically allocate an array of structures
    movies->mveInfo=new MovData[movies->nMovies];
    
    for(int i=0;i<movies->nMovies;i++){
        cin.ignore();
        getline(cin, movies->mveInfo[i].title);
        int size=80;
        //For each structure in each element in mveInfo array,
        //dynamically allocate a character array
        movies->mveInfo[i].dirctr=new char[size];
        cin.getline(movies->mveInfo[i].dirctr,size-1);
        cin>>movies->mveInfo[i].year;
        cin>>movies->mveInfo[i].runTime;
    }
    
    return movies;
}

void prntDat(Movies *movies){
    for(int i=0; i<movies->nMovies;i++){
        cout<<left
            <<setw(11)<<"Title:"<<movies->mveInfo[i].title<<endl
            <<setw(11)<<"Director:"<<movies->mveInfo[i].dirctr<<endl
            <<setw(11)<<"Year:"<<movies->mveInfo[i].year<<endl
            <<setw(11)<<"Length:"<<movies->mveInfo[i].runTime<<endl;
    }
}
