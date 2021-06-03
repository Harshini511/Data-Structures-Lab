#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include"admin.h"
#include"dijkstra.h"
#include"GraphADT.h"

#define cityfile "cities.txt"
#define timefile "hours.txt"
#define costfile "cost.txt"
#define MAX 50
#define Infinity 100000
#define PASS "ssnds"

void main(){

	printf("\n\n------WELCOME TO DOMESTIC FLIGHT ITENERARY PLANNER------\n");
	int init=0,ch=0,i,j;
	while(init!=3){
	printf("\n\nEnter 1.USER\n2.ADMIN\n3.EXIT:");
	scanf("%d",&init);
	switch(init){
	case 1:
	ch=0;
	while(ch!=5){
	printf("\n\nEnter 1.Least cost route\n2.Least time route\n3.Economy package (best of both) \n4.Minimum no. of flights\n5.Exit:");
	int val,no_of_vertices=0,i,j,adj[MAX][MAX]={0},row=0,col=0,adj1[MAX][MAX]={0},dist,dist1,adj2[MAX][MAX]={0};
	char names[MAX][MAX],str[MAX],start[MAX],end[MAX];
	scanf("%d",&ch);
	FILE *fp,*fp1;
	if(ch!=5){
	/*Retreiving city name*/
	fp=fopen(cityfile,"r");
	while(!feof(fp)){
		fscanf(fp,"%s",names[no_of_vertices]);
		no_of_vertices++;
	}
	fclose(fp);
	no_of_vertices--;
	
	printf("\n\nEnter Source:");
	scanf("%s",start);
	printf("\n\nEnter Destination:");
	scanf("%s",end);
	}
	/*Preparing the adjacency matrix*/
	switch(ch){
		case 1://Least cost
			matrix(costfile,adj,no_of_vertices);
			dist=dijkstra_shortest_cost(names,adj,start,end,no_of_vertices,Infinity);
			if(dist!=-1)
				printf("\n\nTotal Cost: %d thousand",dist);
		break;

		case 2://Least Time
			matrix(timefile,adj,no_of_vertices);
			dist=dijkstra_shortest_time(names,adj,start,end,no_of_vertices,Infinity);
			if(dist!=-1)
				printf("\n\nTotal Time: %d hours",dist);
		break;
		
		case 3://Economical
			matrix(timefile,adj2,no_of_vertices);
			matrix(costfile,adj1,no_of_vertices);
			for(i=0;i<no_of_vertices;i++)
				for(j=0;j<no_of_vertices;j++)
				adj[i][j]=adj1[i][j]+adj2[i][j];
			dist=dijkstra_shortest_economy(names,adj,adj1,adj2,start,end,no_of_vertices,Infinity);
		break;
	
		case 4:
			matrix(timefile,adj,no_of_vertices);
			for(i=0;i<no_of_vertices;i++)
				for(j=0;j<no_of_vertices;j++)
					if(adj[i][j]!=0)
							adj[i][j]=1;
			dist=dijkstra_shortest_flight(names,adj,start,end,no_of_vertices,Infinity);
			if(dist!=-1)
				printf("\n\nMin. Flights: %d",dist);
		break;
			
	}
	}
	break;
	case 2:
		printf("\nEnter password:");char password[50]; 
  
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*"); 
        } 
        p++; 
    }while(password[p-1]!='\r');
    password[p-1]='\0'; 
		if(strcmp(password,PASS)==0)
			main_admin();
		else
			printf("\nWrong password:");
		break;
	}
	}
}
