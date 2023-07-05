#include <iostream>
using namespace std;

int main() 
{
  
    int n; cin>>n; 
    int count =1;
    int ct =1 ;
    
    //pattern1
    for(int row=1; row<=n;row++){                              
      for(int col =1;col<=n;col++){
        cout<<col <<" ";
      }
      cout<<endl;
    }
    cout<<endl<<endl;

  Output:

1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4 

    //pattern 2
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cout<<n-j+1<<" ";
      }
      cout<<endl;
    }
    
        cout<<endl<<endl;
  
 output:
4 3 2 1 
4 3 2 1 
4 3 2 1 
4 3 2 1 

  
        
        //pattern3
       for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cout<<count<<" ";
        count++;
      }
      cout<<endl;
    }
    cout<<endl<<endl;

  output:
  1 2 3 4 
  5 6 7 8 
  9 10 11 12 
  13 14 15 16 
  
    
    //pattern4 
    for(int row =1; row<=n;row++){
      for(int col = 1 ;col <= row;col++){
        cout<<"*"<<" ";
      }
      cout<<endl;
    }

   output:
    * 
    * * 
    * * * 
    * * * * 
    
    //pattern5 
    for(int row =1; row<=n;row++){
      for(int col = 1 ;col <= row;col++){
        cout<<row<<" ";
      }
      cout<<endl;
    }
      cout<<endl<<endl;
output:
1 
2 2 
3 3 3 
4 4 4 4 
  
      
      //pattern6 
      for(int row =1; row<=n;row++){
      for(int col = 1 ;col <= row;col++){
        cout<<ct<<" ";
        ct++;
      }
      cout<<endl;
    }
      cout<<endl<<endl;

    output:
    1 
    2 3 
    4 5 6 
    7 8 9 10 
      
      //pattern7 
       for(int row =1; row<=n;row++){
            int value = row;
      for(int col = 1 ;col <= row;col++){
        cout<<value<<" ";
        value++;
      }
      cout<<endl;
    }
      cout<<endl<<endl;

  output:
    1 
    2 3 
    3 4 5 
    4 5 6 7 
      
      //pattern8 
      
      for(int row =1; row<=n;row++){
            int value = row;
      for(int col = 1 ;col <= row;col++){
        cout<< n - row+1 <<" ";
        // value--;
      }
      cout<<endl;
    }
      cout<<endl<<endl;
    return 0;
}
output:
4 
3 3 
2 2 2 
1 1 1 1 

