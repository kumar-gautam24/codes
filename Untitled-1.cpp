#include<iostream> 
using namespace std;
// int n=4;
void printSpace(int k){
    if(k==0)
    return;
    cout<<" "<<" ";
    printSpace(k-1);

}

void printAsterisk(int j,int i){
    if(j>i)
    return;
    cout<<"* ";
    printAsterisk(j+1,i);
}

void drawPattern(int n,int i){

    if(i>n)
    return;

    // space
    printSpace(n-i);

    // asterisk function 
    printAsterisk(1,i);
    cout<<endl;
    
    // main function
    drawPattern(n,i+1);

}


int main(){
    

    // for(int i=1;i<=n;i++){
    //     for(int k=n-i;k>0;k--){
    //         cout<<"  ";
    //     }
    //     for(int j=1;j<=i;j++)
    //     cout<<"* ";
    //     cout<<endl;
    // }
    drawPattern(4,1);
    return 0;
}


































// sonu password

sonu8711
sonu@786

Sonusoni101
S6299562578