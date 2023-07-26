#include <iostream>
#include <cstdio>
int n;
int a[110];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int key=a[i];
        int j=i-1;
        while(j>0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        
        for(int t=1;t<=n;t++){
            if(t>1)printf(" ");
            printf("%d",a[t]);
        }
        printf("\n");
        
    }
    return 0;
}