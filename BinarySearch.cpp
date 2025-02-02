
#include <iostream>
using namespace std;
int main(){
int a[7]={30,89,6,12,34,54,90};
int first=0;
int last=6;
int mid;
int num=12;
do{
mid=(first+last)/2;
if(a[mid]==num)
{
cout<<"found at "<<mid+1;
break;
}
else if(a[mid<num]){
first=mid+1; }
else{
last=mid-1;
}
}
while(first<=last);
if(first>last){
cout<<"not found"<<endl;
}
