#include<bits/stdc++.h>
#include<string>
#include<graphics.h>
using namespace std;

int main()
{
    string process[100],p;
    int burst[100],n,i,wait[100];
    double avg_wait=0,avg_turnaround;
    wait[0]=0;
    cout<<"Enter the number of processes:";
    cin>>n;
    cout<<"Enter the process names with their corresponding burst time:"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>process[i];
        cin>>burst[i];
        wait[i]=burst[i]+wait[i-1];
        avg_wait+=wait[i];
    }
    avg_turnaround=(double)avg_wait/n;
    avg_wait-=wait[i-1];
    avg_wait=(double)avg_wait/n;
    cout<<"Average waiting time:"<<avg_wait<<endl;
    cout<<"Average turnaround time:"<<avg_turnaround;

    int gd = DETECT, gm;
    int left = 10, top = 150;
    int right = (wait[n]*20)+10, bottom = 50;
    initgraph(&gd, &gm, "");
    rectangle(left, top, right, bottom);
    for(i=1;i<=n;i++)
    {
      line((wait[i]*20+10),150,(wait[i]*20+10),50);
    }
    getch();
    closegraph();
    return 0;
}
