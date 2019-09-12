#include <stdio.h>
#include <limits.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>

#define pb push_back
#define ll long long
#define endl "\n"
#define mp make_pair
#define all(c) c.begin(),c.end()
#define hell 100001
#define V 10

using namespace std;

ll m=0,n=0,start=0,eend=0;
ll dist[hell];


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

return min_index;
}

long printSolution(int dist[], int n)
{
    long t=0;
for (int i = 0; i < V; i++){
        t=t+dist[i];

}
    return t;
}

int dijkstra(int graph[V][V], int src)
{
    long t;
	int dist[V];	 // The output array. dist[i] will hold the shortest
					// distance from src to i

	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V-1; count++)
	{
	// Pick the minimum distance vertex from the set of vertices not
	// yet processed. u is always equal to src in the first iteration.
	int u = minDistance(dist, sptSet);

	// Mark the picked vertex as processed
	sptSet[u] = true;

	// Update dist value of the adjacent vertices of the picked vertex.
	for (int v = 0; v < V; v++)

		// Update dist[v] only if is not in sptSet, there is an edge from
		// u to v, and total weight of path from src to v through u is
		// smaller than current value of dist[v]
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
									&& dist[u]+graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	t=printSolution(dist, V);
	return t;
}
double p()
{
     return (static_cast<double>(rand()%INT_MAX)/INT_MAX);

}
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
void addedge(int g[V][V])
{
    ll m=0,n=0,j=0,ans=0,num=0,cnt=0;
    for(m=0;m<V;m++)
    {

      int t=dijkstra(g,m);
       vector <pair<ll,ll> >v;
       for(int k=0;k<V;k++)
       {
           v.pb(mp(dist[k],k));
       }
       num=V-1;
       sort(all(v));
       while(true)
       {
           cnt=0;
           if(g[m][num--]==0)
           {
               n=num+1;
               cnt=v[n].first;
               break;
           }

       }
       if(ans<cnt)
       {
           start=m;
           eend=n;
           ans=cnt;

       }

    }

}

int main()
{
    int e=10,x;
    srand(time(0));
   double d=.5;
    cout<<"graph density(0,1) and egde"<<endl;
    cin>>d;
    cin>>e;

    for(x=0;x<10;x++){
/* Let us create the example graph discussed above */

 int i,j,lsc,lc,z=0;
 long k=0;
 vector< pair <int, int> > vect;
 double l,lg,ut,pu;


    int g[V][V]={0};
    for(int i=0;i<V;i++)
    for(int j=i+1;j<V;j++)
    if(p()<d)
    g[i][j]=g[j][i]=1;
     for(i=0;i<V;i++){
	k=k+dijkstra(g, i);
	//cout<<k<<endl;

    }
    for(i=0;i<e;i++)
    {
        addedge(g);
        g[start][eend]=g[eend][start]=1;

    }
    for(j=0;j<V;j++){

    z=z+dijkstra(g,j);
    }
    l=(double)(k)/(double)(V*(V-1));
    cout<<l<<endl;
    lg=(double)(z)/(double)(V*(V-1));
    cout<<lg<<endl;
    ut=l-lg;
    cout<<ut<<endl;
    pu=(ut/l)*100;
    cout<<pu<<endl<<endl;
}
	return 0;

}
