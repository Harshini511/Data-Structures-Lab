#include<string.h>
#define MAX 50

int dijkstra_shortest_time(char names[MAX][MAX],int adj[MAX][MAX],char start[MAX],char end[MAX],int no_of_vertices,int max){
	int i,j,s,e,flags=0,flage=0;
	for(i=0;i<no_of_vertices;i++){
		if(strcmpi(names[i],start)==0){
			s=i;flags=1;}
		if(strcmpi(names[i],end)==0){
			e=i;flage=1;}
	}
	if(flags==0 && flage==0){
		printf("\nLocations not found");
		return -1;
	}
	if(flags==0){
		printf("\nSource not found.");
		return -1;
	}
	if(flage==0){
		printf("\nDestination not found.");
		return -1;
	}

	
	int tab[MAX][3],place=s,flag,min,dist,count=0,prev_dist=0,ind;
	for(i=0;i<no_of_vertices;i++){
		tab[i][0]=0;
		if(i!=s){
			tab[i][1]=max*2;
			tab[i][2]=-1;}
		else{
			tab[i][1]=0;
			tab[i][2]=-1;
		}
	}
	
	do{
		tab[place][0]=1;count++;
		for(j=0;j<no_of_vertices;j++){
			if(adj[place][j]!=0){
				dist=adj[place][j]+prev_dist;
				if(dist<tab[j][1]){
					tab[j][1]=dist;
					tab[j][2]=place;
				}
			}
		}
	//find least dist. unknown node
		min=max*2;
		for(i=0;i<no_of_vertices;i++){
			if(tab[i][0]==0){
				if(tab[i][1]<min){
					place=i;prev_dist=tab[place][1];min=tab[i][1];
				}
			}
		}
	}while(count<=no_of_vertices);
		
	char path[MAX][MAX];
	int distance[MAX],ind1=0;ind=0;
	place=e;dist=tab[e][1];
	strcpy(path[ind],names[place]);ind++;
	while(place!=-1){
		strcpy(path[ind],names[tab[place][2]]);ind++;
		distance[ind1]=adj[place][tab[place][2]];ind1++;
		place=tab[place][2];
	}
	strcpy(path[ind],names[place]);
	printf("\n\n\nDESIRED PATH: ");
	for(i=ind-2;i>0;i--){
		printf("%s->",path[i]);
	}
	printf("%s\n",path[i]);
	for(i=ind1-2;i>=0;i--)
		printf("%d hour(s)||",distance[i]);
	return(dist);
}


int dijkstra_shortest_cost(char names[MAX][MAX],int adj[MAX][MAX],char start[MAX],char end[MAX],int no_of_vertices,int max){
	int i,j,s,e,flags=0,flage=0;
	for(i=0;i<no_of_vertices;i++){
		if(strcmpi(names[i],start)==0){
			s=i;flags=1;}
		if(strcmpi(names[i],end)==0){
			e=i;flage=1;}
	}
	if(flags==0 && flage==0){
		printf("\nLocations not found");
		return -1;
	}
	if(flags==0){
		printf("\nSource not found.");
		return -1;
	}
	if(flage==0){
		printf("\nDestination not found.");
		return -1;
	}

	
	int tab[MAX][3],place=s,flag,min,dist,count=0,prev_dist=0,ind;
	for(i=0;i<no_of_vertices;i++){
		tab[i][0]=0;
		if(i!=s){
			tab[i][1]=max*2;
			tab[i][2]=-1;}
		else{
			tab[i][1]=0;
			tab[i][2]=-1;
		}
	}
	
	do{
		tab[place][0]=1;count++;
		for(j=0;j<no_of_vertices;j++){
			if(adj[place][j]!=0){
				dist=adj[place][j]+prev_dist;
				if(dist<tab[j][1]){
					tab[j][1]=dist;
					tab[j][2]=place;
				}
			}
		}
	//find least dist. unknown node
		min=max*2;
		for(i=0;i<no_of_vertices;i++){
			if(tab[i][0]==0){
				if(tab[i][1]<min){
					place=i;prev_dist=tab[place][1];min=tab[i][1];
				}
			}
		}
	}while(count<=no_of_vertices);
		
	char path[MAX][MAX];
	int distance[MAX],ind1=0;ind=0;
	place=e;dist=tab[e][1];
	strcpy(path[ind],names[place]);ind++;
	while(place!=-1){
		strcpy(path[ind],names[tab[place][2]]);ind++;
		distance[ind1]=adj[place][tab[place][2]];ind1++;
		place=tab[place][2];
	}
	strcpy(path[ind],names[place]);
	printf("\n\n\nDESIRED PATH: ");
	for(i=ind-2;i>0;i--){
		printf("%s->",path[i]);
	}
	printf("%s\n",path[i]);
	for(i=ind1-2;i>=0;i--)
		printf("Rs.%d thousand(s)||",distance[i]);
	return(dist);
}


int dijkstra_shortest_flight(char names[MAX][MAX],int adj[MAX][MAX],char start[MAX],char end[MAX],int no_of_vertices,int max){
	int i,j,s,e,flags=0,flage=0;
	for(i=0;i<no_of_vertices;i++){
		if(strcmpi(names[i],start)==0){
			s=i;flags=1;}
		if(strcmpi(names[i],end)==0){
			e=i;flage=1;}
	}
	if(flags==0 && flage==0){
		printf("\nLocations not found");
		return -1;
	}
	if(flags==0){
		printf("\nSource not found.");
		return -1;
	}
	if(flage==0){
		printf("\nDestination not found.");
		return -1;
	}

	
	int tab[MAX][3],place=s,flag,min,dist,count=0,prev_dist=0,ind;
	for(i=0;i<no_of_vertices;i++){
		tab[i][0]=0;
		if(i!=s){
			tab[i][1]=max*2;
			tab[i][2]=-1;}
		else{
			tab[i][1]=0;
			tab[i][2]=-1;
		}
	}
	
	do{
		tab[place][0]=1;count++;
		for(j=0;j<no_of_vertices;j++){
			if(adj[place][j]!=0){
				dist=adj[place][j]+prev_dist;
				if(dist<tab[j][1]){
					tab[j][1]=dist;
					tab[j][2]=place;
				}
			}
		}
	//find least dist. unknown node
		min=max*2;
		for(i=0;i<no_of_vertices;i++){
			if(tab[i][0]==0){
				if(tab[i][1]<min){
					place=i;prev_dist=tab[place][1];min=tab[i][1];
				}
			}
		}
	}while(count<=no_of_vertices);
		
	char path[MAX][MAX];
	int distance[MAX],ind1=0;ind=0;
	place=e;dist=tab[e][1];
	strcpy(path[ind],names[place]);ind++;
	while(place!=-1){
		strcpy(path[ind],names[tab[place][2]]);ind++;
		distance[ind1]=adj[place][tab[place][2]];ind1++;
		place=tab[place][2];
	}
	strcpy(path[ind],names[place]);
	printf("\n\n\nDESIRED PATH: ");
	for(i=ind-2;i>0;i--){
		printf("%s->",path[i]);
	}
	printf("%s\n",path[i]);
	return(dist);
}



int dijkstra_shortest_economy(char names[MAX][MAX],int adj[MAX][MAX],int time[MAX][MAX],int cost[MAX][MAX],char start[MAX],char end[MAX],int no_of_vertices,int max){
	int i,j,s,e,flags=0,flage=0,t,c;
	for(i=0;i<no_of_vertices;i++){
		if(strcmpi(names[i],start)==0){
			s=i;flags=1;}
		if(strcmpi(names[i],end)==0){
			e=i;flage=1;}
	}
	if(flags==0 && flage==0){
		printf("\nLocations not found");
		return -1;
	}
	if(flags==0){
		printf("\nSource not found.");
		return -1;
	}
	if(flage==0){
		printf("\nDestination not found.");
		return -1;
	}

	
	int tab[MAX][3],place=s,flag,min,dist,count=0,prev_dist=0,ind;
	for(i=0;i<no_of_vertices;i++){
		tab[i][0]=0;
		if(i!=s){
			tab[i][1]=max*2;
			tab[i][2]=-1;}
		else{
			tab[i][1]=0;
			tab[i][2]=-1;
		}
	}
	
	do{
		tab[place][0]=1;count++;
		for(j=0;j<no_of_vertices;j++){
			if(adj[place][j]!=0){
				dist=adj[place][j]+prev_dist;
				if(dist<tab[j][1]){
					tab[j][1]=dist;
					tab[j][2]=place;
				}
			}
		}
	//find least dist. unknown node
		min=max*2;
		for(i=0;i<no_of_vertices;i++){
			if(tab[i][0]==0){
				if(tab[i][1]<min){
					place=i;prev_dist=tab[place][1];min=tab[i][1];
				}
			}
		}
	}while(count<=no_of_vertices);
		
	char path[MAX][MAX];
	int distancet[MAX],distancec[MAX],ind1=0;ind=0;
	place=e;dist=tab[e][1];
	strcpy(path[ind],names[place]);ind++;
	while(place!=-1){
		strcpy(path[ind],names[tab[place][2]]);ind++;
		distancet[ind1]=time[place][tab[place][2]];distancec[ind1]=cost[place][tab[place][2]];ind1++;
		place=tab[place][2];
	}
	strcpy(path[ind],names[place]);
	printf("\n\n\nDESIRED PATH: ");
	for(i=ind-2;i>0;i--){
		printf("%s->",path[i]);
	}
	printf("%s\n\n",path[i]);
	t=0;c=0;
	for(i=ind1-2;i>=0;i--){
		t+=distancet[i];
		printf("Rs.%d thousand(s)||",distancet[i]);
	}
	printf("\n\n");
	for(i=ind1-2;i>=0;i--){
		c+=distancec[i];
		printf("%d hour(s)||",distancec[i]);
	}
	
	printf("\n\nTotal cost: %d thousand",t);
	printf("\n\nTotal time: %d hours",c);
	return(dist);
}
