#include<iostream>


using namespace std;

//function prototypes
void printpow (int [], int, int, int);

static int counter = 0;

int main()
{

    int elementnum = 0; //n is the last element of powerset
    cin >> elementnum;

    int* myarray = new int [elementnum]; //dynamically create integer array

    for  (int i=0; i < elementnum; i++) //populate arraye
    {
        myarray[i] = i+1;
    }

    int position = 0; //indexixng variable to keep track of where printing begins in the array
    int maximum = 1; //m denotes the first element in each subset that printings begin with

    printpow (myarray,position, maximum, elementnum); //run recursive function

    delete [] myarray; //deallocate S

    myarray = nullptr;

    return 0; //end program
}

//recursive powerset printing function
void printpow (int myarray[], int position, int maximum, int elementnum)
{

    if ( counter== 0) //this allows me to print the empty set only once
    {
        cout << "{}" << endl;//empty set handled
    }
    counter ++; //increment counter so that no issues with repeated empty set printings

    if (maximum <= elementnum) //this will check to see if the bottom bound has met the top
    {
        myarray[position] = maximum; //this specifies m as being the first value in the subset currently being printed

    cout << "{ "; //bracket to surround subsets

    //print out the subset starting in position 0 of the array
    for (int i = 0; i<=position;i++)
    {
        cout << myarray[i] << " ";
    }

    cout << "}"; //closing bracket for subset

    cout << endl;

    printpow (myarray, position+1, maximum+1, elementnum); //basically increments m and k and prints the next subset, adding an element each time up to the value n
    printpow (myarray, position, maximum+1,elementnum); //this will do the same as above, but only increment n, which prints out subsets starting with values > k
    }

    //end function

    return;
}
