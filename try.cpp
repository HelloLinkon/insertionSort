#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include <fstream>

using namespace std;

int main ()
{

  int a, range =1000;
  int i,j,key;
  clock_t t;
  int myArray[range];


  //write in file
  ofstream myfile;
  myfile.open ("example.txt");
  for(a =0; a<range; a++)
  {
       myfile << rand() << "\n";
  }

  myfile.close();
    //read from file and make array;
    ifstream file("example.txt");
    if(file.is_open())
    {


        for(int i = 0; i < range; ++i)
        {
            file >> myArray[i];
        }
    }
    //time start
    t = clock();

    //insertion sort
    for(j=1; j<range; j++)
    {
        key = myArray[j];
        i = j-1;
        while(i >= 0 && myArray[i] > key )
        {
            myArray[i+1] = myArray[i];
            i--;
        }
        myArray[i+1] = key;
    }

    //sorted array
    for(a=0; a<range; a++)
    {
        printf("%d\n", myArray[a]);
    }

    //end time
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

    return 0;
}
