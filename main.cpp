#include <iostream>
#include <map>
#include <string>

#include "DataGenerator.cpp"
#include "utillities.cpp"
#include "sorting_algo.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, void(*)(int[], int)> m;
    m["selection-sort"] = selectionSort;
    m["bubble-sort"] = bubbleSort;
    string mode;
    int count=argc;
    
    if (count>=2) //have input arg
    {
        mode=argv[1];
        if (mode=="-a") // ALGO MODE
        {
            
            
            if(count==6) //cmd 2 with 6 arg
            {   string sortalgo=argv[2];
                string datasize=argv[3];
                int datatype=datatypehandler(argv[4]); //only cmd 2 has fixed datatype
                string outpara=argv[5];
                int n=stoi(datasize);
                int a[100000];
                GenerateData(a,n,datatype);
                m[sortalgo](a,n);
                for (int i = 0; i < n; i++)
                {
                    cout<<a[i]<<" ";
                }
                //cout<<"\n"<<outpara; //just for testing
                cout<<"cmd 2";
            }
            else if(count==5) //cmd 1,3 with 5 arg
            {   string sortalgo=argv[2];
                string datasize=argv[3];
                string outpara=argv[4];
                //define cmd1 or cmd3
                if (numberChecker(datasize))
                {
                    //as this is a number, so it is cmd3 and datasize is datasize
                    int n=stoi(datasize);
                    int a[100000];
                    for (int datatype = 0; datatype < 4; datatype++)
                    {
                        GenerateData(a,n,datatype);
                        m[sortalgo](a,n);
                        printarray(a,n);
                        cout<<endl;
                    } 
                    
                    cout<<"cmd3"; //just for testing
                }
                else
                {   
                    //as this is not a number, so it is cmd1 and datasize is filename
                    int n;
                    int a[100000];
                    string filename=datasize;
                    filehandler(filename,a,n);
                    m[sortalgo](a,n);
                    printarray(a,n);
                    cout<<"cmd1"; //just for testing
                }
                
            }
            else
            {
                cout<<"Invalid number of arguments";
            }
              
           
        }
        
        else if(mode== "-c") //COMPARISON MODE
        {
            cout<<"c mode activated"<<endl;
            // comparison mode is not completed yet, will do it later
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
