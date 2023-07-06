# DABANG PATTERN
#include <iostream>

int main() {
    int n = 5;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            std::cout << j << " ";
        }
        for (int k = 0; k < 2 * i; k++) {
            std::cout << "* ";
        }
        for (int l = n - i; l >= 1; l--) {
            std::cout << l << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

output : 

1 2 3 4 5 5 4 3 2 1 
1 2 3 4 * * 4 3 2 1 
1 2 3 * * * * 3 2 1 
1 2 * * * * * * 2 1 
1 * * * * * * * * 1 

//2nd pattern
  #include <iostream>
using namespace std;

int main() 
{
  
  int n;cin>>n;
  
  for(int  row=1;row<=n;row++){
    
    //space print
    for(int space = 1;space<=n-row;space++){
      cout<<" ";
    }
    
    //1st trialge print
    
    for(int col =1;col<=row;col++){
      cout<<col;
    }
    // 2nd triangle
    
    for(int start = row-1;start>=1;start--){
      cout<<start;
     
    }
    cout<<endl;
  }
   
    return 0;
}

output:

    1
   121
  12321
 1234321
123454321
