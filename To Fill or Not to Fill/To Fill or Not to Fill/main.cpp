//
//  main.cpp
//  To Fill or Not to Fill
//
//  Created by APTX on 6/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//原文地址：https://blog.csdn.net/bourbon_whiskey_/article/details/86741046
//此题代码非原创
//贪心

//解题思路
//
//先录入加油站信息，并依据距离进行排序（数据均使用double型）；
//如果第一个加油站位置非0则移动距离为0（边界条件之一）；
//贪心法：在每个加油站寻找最大可达距离中比当前油价低的加油站，或可达距离中油价最低的加油站作为下一次加油的目的地；
//如果当前油价比目标油价高，则加油到恰好到达，否则加满油；
//依次直到无法到达下一个点或者到达目的地；
//输出结果并返回0值。
//---------------------
//作者：Bourbon_Whiskey_
//来源：CSDN
//原文：https://blog.csdn.net/bourbon_whiskey_/article/details/86741046
//版权声明：本文为博主原创文章，转载请附上博文链接！

#include<cstdio>
#include<algorithm>
#define maxn 510
#define INF 100000000
using namespace std;

struct St{
    double dis,price;
}Sat[maxn];

bool cmp(St a,St b){
    return a.dis<b.dis;
}

int N;
double C,D,Da;

int main(){
    int i,j,k;//k为当前站点
    double remain=0,Max,fee,minprice,need;
    scanf("%lf%lf%lf%d",&C,&D,&Da,&N);
    for(i=0;i<N;i++){
        scanf("%lf%lf",&Sat[i].price,&Sat[i].dis);
    }
    Sat[N].dis=D;
    Sat[N].price=0.0;
    sort(Sat,Sat+N,cmp);
    if(Sat[0].dis!=0){
        printf("The maximum travel distance = 0.00\n");
    }else{
        k=0;
        fee=0.0;
        Max=C*Da;
        remain=0.0;
        
        while(k<N){
            i=-1; minprice=INF;
            for(j=k+1;j<=N&&Sat[j].dis-Sat[k].dis<=Max;j++){ //在每个加油站寻找最大可达距离中比当前油价低的加油站，或可达距离中油价最低的加油站作为下一次加油的目的地；
                if(Sat[j].price<minprice){
                    i=j;
                    minprice=Sat[i].price;
                    if(minprice<Sat[k].price){               //如果找到的加油站价格比当前的低，则停止查找，加满刚好的油，去下一个加油站加油更划算
                        break;
                    }
                }
            }
            if(i==-1){                                        //如果可达距离内找不到加油站，则退出
                break;
            }
            //在第k站 做决策
            need=Sat[i].dis-Sat[k].dis;                         //去下一个目标加油站需要走的距离
            if(minprice<Sat[k].price){                          //如果当前的价格比找到的目标加油站价格高，则只买刚好的油
                //只购买恰好的的油
                if(remain<need){                                //如果剩余油量走不到目标加油站
                    fee+=(need-remain)*Sat[k].price;            //加到能到目标加油站即可
                    remain=0;                                   //到达目标加油站，剩余油量可走的里程数为0
                }else{
                    remain-=need;
                }
            }else{                                              //如果当前价格比找到的最便宜的目标加油站的价格还低，则直接加满油
                fee+=(Max-remain)*Sat[k].price;
                remain=Max-need;
            }
            k=i;                                                //走到目标加油站
        }
        if(k==N){
            printf("%.2lf\n",fee/Da);
        }else{
            printf("The maximum travel distance = %.2lf\n",Sat[k].dis+Max); //目标加油站距离加上 装满油的最大里程
        }
    }
    return 0;
}


