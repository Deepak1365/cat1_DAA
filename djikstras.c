\* for this code , djikstra's works as we give a penalty to the negative weight to penalise it . but other than that , the graph is fine .
if we dont penalise the negative weight , the code doesn't work *\



#include <stdio.h>
int main()
{
	int g[5][5]={{0,4,2,0,0},{0,0,3,2,3},{0,1,0,4,5},{0,0,0,0,0},{0,0,0,-5,0}};
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(g[i][j]<0)
			{
				g[i][j]*=g[i][j];		//Penalising -ve edges
			}
			else if(g[i][j]==0)
			{
				g[i][j]=100;			//Setting no edge values to 100 to stop interference
			}
		}
	}
	int order[5]={0},dist[5],visit[5]={0},min,node;
	for(int i=0;i<5;i++)		//Initialising distance array
	{
		dist[i]=g[0][i];
	}
	for(int c=0;c<5;c++)
	{
    	min=100;
		for(int i=0;i<5;i++)
		  	if(dist[i]<min && !visit[i]) 
		  	{
		    	min=dist[i];
		    	node=i;
		  	}
		visit[node] = 1;
		for(int i=0;i<5;i++)
		{
		  	if(!visit[i])
		  	{
		    	if(min+g[node][i]<dist[i])
		    	{
		      		dist[i]=min+g[node][i];
		    	}
		    }
  		}
  	}
  	for(int i=1;i<5;i++)
      	printf("Distance from 1 to %d is %d\n",i+1,dist[i]);
