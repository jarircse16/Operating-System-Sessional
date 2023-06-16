#include<bits/stdc++.h>
#include<string>
#include<graphics.h>
using namespace std;

bool allzero(vector<pair<int,int>> check,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(check[i].second!=0)
            break;
    }
    if(i==n)
        return true;
    else
        return false;
}

int main()
{
    int burst[100],n,i,wait[100],priority[100],p,q;
    double avg_wait=0,avg_turnaround;
    vector<pair<int,int>>vect,gantt;
    wait[0]=0;
    cout<<"Enter the number of processes:";
    cin>>n;
    cout<<"Enter the process number with their corresponding burst time:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>p;
        cin>>burst[i];
        vect.push_back(make_pair(p,burst[i]));
    }
    cout<<"Enter time quantum:";
    cin>>q;
    i=0;
    while(!allzero(vect,n))
    {
        cout<<i<<endl;
       if(vect[i].second>=q)
       {
           vect[i].second-=q;
           if(i==0)
           gantt.push_back(make_pair(vect[i].first,q));
           else
            gantt.push_back(make_pair(vect[i].first,vect[i-1].second+q));
       }
       else if(vect[i].second>0)
       {
           if(i==0)
           gantt.push_back(make_pair(vect[i].first,vect[i].second));
           else
            gantt.push_back(make_pair(vect[i].first,vect[i].second+vect[i-1].second));
           vect[i].second=0;

       }
       else
       {

       }
       if(i>=n-1)
        i=-1;
       i++;
    }
  cout<<endl<<endl;
    for(i=0;i<n;i++)
    {
        cout<<gantt[i].second<<endl;
    }

  /*  for(i=1;i<=n;i++)
    {
        wait[i]=vect[i-1].second+wait[i-1];
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
    closegraph();*/
    return 0;
}

