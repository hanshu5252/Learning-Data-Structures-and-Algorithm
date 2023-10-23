#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid, int r){
    int an =mid-l+1;
    int bn =r-mid;
    // create two  temporary arrays
    int a[an];
    int b[bn];
    for(int i =0;i<an;i++){ 
        a[i]=arr[l+i];
    }
    for(int j=0;j<bn;j++){
        b[j] =arr[mid+1+j];
    }
    int i=0; // initial index of first subarray ,a
    int j=0; // initial index of second subarray, b
    int k=l; // initial index of merged subarray
    while(i<an&&j<bn){
        if(a[i]<b[j]){
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    while(i<an){
        arr[k++]=a[i++];
    }
    while(j<bn){
        arr[k++]=b[j++];
    }

}
void merge_sort(int arr[],int l,int r){
   // base case
   if(l>=r){
   return;
   }
   int mid =(l+r)/2;
   merge_sort(arr,l,mid);
   merge_sort(arr,mid+1,r);
   merge(arr,l,mid,r);

}
int main(){
    int arr[]={9,2,6,4,7,3,8,1};
    int n= sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}