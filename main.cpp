#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "DataGenerator.cpp"
#include "utillities.cpp"
#include "sorting_algo.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, void(*)(int[], int)> m;
    m["selection_sort"] = selectionSort;
    m["bubble_sort"] = bubbleSort;
    string mode;
    int count=argc;
    
    if (count>=2) //have input arg
    {
        mode=argv[1];
        if (mode=="-a")
        {
            
            int datatype=datatypehandler(argv[4]);
            if(count==6) //cmd 2 with 6 arg
            {   string sortalgo=argv[2];
                string datasize=argv[3];
                string outpara=argv[5];
                int n=stoi(datasize);
                int a[100000];
                GenerateData(a,n,datatype);
                m[sortalgo](a,n);
                for (int i = 0; i < n; i++)
                {
                    cout<<a[i]<<" ";
                }
                cout<<"\n"<<outpara;
            }
            else if(count==5) //cmd 1,3 with 5 arg
            {   string sortalgo=argv[2];
                string datasize=argv[3];
                //define cmd1 or cmd3
                if (numberChecker(datasize))
                {
                    //as this is a number, so it is cmd3 and datasize is datasize
                    cout<<"cmd3";
                }
                else
                {
                    //as this is not a number, so it is cmd1, and datasize is actually input file name
                    cout<<"cmd1";
                }
                
            }
            else
            {
                cout<<"Invalid number of arguments";
            }
              
           
        }
        
        else if(mode== "-c")
        {
            cout<<"c mode activated"<<endl;
        }
        else
        {
            cout<<"Invalid mode";
        }
        
        
    }
    else 
    {
        cout<<"DEFAULT RUNNING WITH NO ARG"<<endl;
    }

    return 0;
}
