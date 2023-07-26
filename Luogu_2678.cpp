#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN=50010,MAX=1e9;

int suml,n,m;
int d[MAXN],dist[MAXN],tmp_dist[MAXN];;

bool check(int minDist){
    //printf("check:%d\n",minDist);

    int delNum=m;
    
    for(int i=1;i<=n+1;i++) tmp_dist[i]=dist[i];

    for(int i=1;i<=n+1;i++){
        //printf("tmp_dist[%d]:%d\n",i,tmp_dist[i]);
        if(tmp_dist[i] < minDist){
            
            if(delNum <= 0) {
                //printf("false\n");
                return false;
                
            }            
            delNum--;
            //printf("Delete\n");
            tmp_dist[i+1]+=tmp_dist[i];
        }
    }
    //printf("true\n");
    
    return true;
}

int binary_sort(int l,int r){

    if(l>=r)return l;

    int mid= (l+r+1) >> 1;

    //printf("l:%d r:%d \n",l,r);
    
    if( check(mid) ){
        return binary_sort(mid,r);
    }
    else{
        return binary_sort(l,mid-1);
    }
}




int main(){
    scanf("%d%d%d",&suml,&n,&m);
    d[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
        dist[i] = d[i]-d[i-1];
    }
    //不能只到N！还有最后一个石头到终点这一段！！！
    dist[n+1]=suml-d[n];

    cout<<binary_sort(0,suml);

    return 0;
}