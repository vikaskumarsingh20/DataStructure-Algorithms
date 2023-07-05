#include <iostream>
using namespace std;

int main() 
{
    
    int n; cin>>n;
     
       //pattern1
     
     for(int row =1;row<=n;row++){
       for(int col =1;col<=n;col++){
         
         char ch = 'A' + row -1; //type caste
         cout<<ch <<" ";
       }
       cout<<endl;
     }
     cout<<endl;

Output:

A A A A 
B B B B 
C C C C 
D D D D 
  
     //pattern2 
        for(int row =1;row<=n;row++){
       for(int col =1;col<=n;col++){
         
         
         char ch = 'A' + col -1; //type caste
         cout<<ch <<" ";
  
       }
       cout<<endl;
     }
     cout<<endl;

  Output:

    A B C D 
    A B C D 
    A B C D
    A B C D 
  
          //pattern3
         char start = 'A';
        for(int row =1;row<=n;row++){
       for(int col =1;col<=n;col++){
  
          cout<<start<<" ";
          
          start = start +1;
         
  
       }
       cout<<endl;
     }
     cout<<endl;

  Output:

    A B C D 
    E F G H 
    I J K L 
    M N O P 
     
               //pattern4

        for(int row = 1 ;row<=n;row++){
       for(int col =1;col<=n;col++){
        // char value = row;
        char ch  =  'A'+row+col -2;
  
          cout<<ch <<" ";
  
       }
       cout<<endl;
     }
     cout<<endl;
  
  Output:

    A B C D 
    B C D E 
    C D E F 
    D E F G 
                    //pattern5
       
        for(int row = 1 ;row<=n;row++){
       for(int col =1;col<=row;col++){
           char ch  = 'A'+ row -1;
          cout<<ch <<" ";
          ch++;
  
       }
       cout<<endl;
     }cout<<endl;

Output:

    A 
    B B 
    C C C 
    D D D D 
                         //pattern6
             char ch  = 'A';
        for(int row = 1 ;row<=n;row++){
       for(int col =1;col<=row;col++){

          cout<<ch <<" ";
          ch++;
  
       }
       cout<<endl;
     }cout<<endl;

Output:

      A 
      B C 
      D E F 
      G H I J 

     
                              //pattern7
             
        for(int row = 1 ;row<=n;row++){
       for(int col =1;col<=row;col++){
           
           char ch = 'A' + row+col -2;
          cout<<ch <<" ";
          ch++;
  
       }
       cout<<endl;
     }cout<<endl;

  Output:

      A 
      B C 
      C D E 
      D E F G 
     
                                   //pattern8
             
        for(int row = 1 ;row<=n;row++){
       for(int col =1;col<=row;col++){
           
           char ch = 'A' + n - row ;
          cout<<ch <<" ";
          
  
       }
       cout<<endl;
     }cout<<endl;

Output:

        D 
        C C 
        B B B 
        A A A A 
     
     //pattern9  space wale
     
     for(int row = 1;row <= n;row++){
       
       for(int space = 1; space <= n-row; space++){
         cout<<" ";
       }
       
       for(int col =1;col<=row;col++){
         cout<<"*";
       }
       cout<<endl;
     }cout<<endl;

  Output:


         *
        **
       ***
      ****
  
      //pattern10
     
     for(int row =1;row<=n;row++){
       for(int col =1;col<=(n-row+1);col++){
         cout<<"*";
       }
       cout<<endl;
     }
     cout<<endl;

  Output:
  
        ****
        ***
        **
        *
     
     //pattern11
          for(int row = 1;row <= n;row++){
       
       for(int space = 1; space <= row-1; space++){
         cout<<" ";
       }
       
       for(int col =1;col<=(n-row+1);col++){
         cout<<"*";
       }
       cout<<endl;
     }cout<<endl;

  Output:

      ****
       ***
        **
         *

    return 0;
}
