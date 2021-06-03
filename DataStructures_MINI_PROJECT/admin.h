#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//to get the total no of cities
int vertices(){
	int i=0;
	char city[30];
	FILE *fp= fopen("cities.txt", "r");
	if(fp==NULL){printf("error"); exit(0);}

	// for getting to know the number of cities available
	while( fscanf( fp,"%s", city) !=EOF ){
		i++;
	}
	fclose(fp);
	return i;
}
//to get the index value of a particular city
int indexOf(char city[]){
	int index=0;
	char Gcity[30];
	FILE *fp= fopen("cities.txt", "r");
	if(fp==NULL){printf("error"); exit(0);}

	// for getting to know the number of cities available
	while( fscanf( fp,"%s", Gcity) !=EOF ){
		if(strcmpi(Gcity,city)==0)
			return index;
		index++;
	}
	fclose(fp);
	return -1;
	
}

void addCity(char city[]){
	
	int index=vertices();
	int col_t[50],col_c[50],row_t[50],row_c[50];


	printf("TIME:-\n");
	printf("enter %d values for flights to %s\n",index,city);
	for (int i=0; i< vertices();i++)
		scanf("%d",&col_t[i]);
	for (int i=0; i< vertices();i++)
		row_t[i]=col_t[i];

	printf("COST:-\n");
	printf("enter %d values for flights to %s\n",index,city);
	for (int i=0; i< vertices();i++)
		scanf("%d",&col_c[i]);
	for (int i=0; i< vertices();i++)
		row_c[i]=col_c[i];
	

	FILE *fpt= fopen("hours.txt", "r");
	if(fpt==NULL){printf("error"); exit(0);}
	
	int time;
	int a[50][50];
	//gets the existent parameters of timeto an array
	for(int loop=0;loop<index;loop++){
		for(int temp=0;temp<index;temp++ ){
			fscanf( fpt,"%d", &a[loop][temp]);
		}
	}
	fclose(fpt);


	fpt= fopen("cost.txt", "r");
	if(fpt==NULL){printf("error"); exit(0);}
	
	int c[50][50];
	//gets the existent parameters of cost to an array
	for(int loop=0;loop<index;loop++){
		for(int temp=0;temp<index;temp++ ){
			fscanf( fpt,"%d", &c[loop][temp]);
		}
	}
	fclose(fpt);

	FILE *newt= fopen("hours.txt", "w");
	FILE *newc= fopen("cost.txt", "w");
	if(newt==NULL || newc==NULL){printf("error"); exit(0);}
	for(int loop=0;loop<index;loop++){
		for(int temp=0;temp<index;temp++ ){
			fprintf( newt,"%d ", a[loop][temp]);
			fprintf( newc,"%d ", c[loop][temp]);
		}
		fprintf(newt,"%d\n",col_t[loop]);
		fprintf(newc,"%d\n",col_c[loop]);
	}

	for(int loop=0;loop<index;loop++){
		fprintf(newt,"%d ",row_t[loop]);
		fprintf(newc,"%d ",row_c[loop]);
	}
	fprintf(newt,"%d ",0);
	fprintf(newc,"%d ",0);
	fclose(newt);
	fclose(newc);
	//to add the city into the list
	int i=0;
	FILE *fp= fopen("cities.txt", "a");
	if(fp==NULL){printf("error"); exit(0);}
	fprintf(fp,"\n");
	fprintf(fp,"%s",city);
	fclose(fp);
	
}

void changeCost(char src[],char dest[]){

	int indexSrc=indexOf(src);
	int indexDest=indexOf(dest);
	if( indexSrc==-1 || indexDest==-1){
		printf("flight not available\n");
		return;
	}

	int cost;
	printf("Enter cost to be added/changed:");
	scanf(" %d",&cost);

	FILE *fpt= fopen("cost.txt", "r");
	if(fpt==NULL){printf("error"); exit(0);}
	int total=vertices();
	int a[50][50];
	//gets the existent parameters to an array
	for(int loop=0;loop<total;loop++){
		for(int temp=0;temp<total;temp++ ){
			fscanf( fpt,"%d", &a[loop][temp]);
		}
	}
	fclose(fpt);

	FILE *new= fopen("cost.txt", "w");
	if(new==NULL){printf("error"); exit(0);}
	for(int i=0;i<total;i++){
		for(int j=0;j<total;j++ ){
			if(i==indexSrc && j==indexDest)
				fprintf( new,"%d ",cost);
			else
				fprintf(new,"%d ",a[i][j]);
		}
		fprintf(new,"\n");
	}
	fclose(new);
}

void changeTime(char src[],char dest[]){
	
	
	int indexSrc=indexOf(src);
	int indexDest=indexOf(dest);
	if( indexSrc==-1 || indexDest==-1){
		printf("flight not available\n");
		return;
	}

	int time;
	printf("Enter time to be changed:");
	scanf(" %d",&time);

	FILE *fpt= fopen("hours.txt", "r");
	if(fpt==NULL){printf("error"); exit(0);}
	int total=vertices();
	int a[50][50];
	//gets the existent parameters to an array
	for(int loop=0;loop<total;loop++){
		for(int temp=0;temp<total;temp++ ){
			fscanf( fpt,"%d", &a[loop][temp]);
		}
	}
	fclose(fpt);

	FILE *new= fopen("hours.txt", "w");
	if(new==NULL){printf("error"); exit(0);}
	for(int i=0;i<total;i++){
		for(int j=0;j<total;j++ ){
			if(i==indexSrc && j==indexDest && a[i][j]!=0)
				fprintf( new,"%d ",time);
			else
				fprintf(new,"%d ",a[i][j]);
		}
		fprintf(new,"\n");
	}
	fclose(new);
}

void main_admin(){
	int choice;
	int loop=1;
	char city[50],src[50],dest[50];
	do{
		printf("\n\nMENU:\n1.Add City and respected Flights\n2.Add new Flight\n3.Change Cost of existing flight\n4.Change Time of existing flight\n");
		printf("5.Quit\nEnter Choice:");choice=0;
		scanf("%d",&choice);
		switch(choice){
		case 1:	
			printf("enter city to be added:");
			scanf(" %[^\n]",city);
			addCity(city);
			break;
		case 2: 
			printf("enter source:");
			scanf(" %[^\n]",src);
			printf("enter destination:");
			scanf(" %[^\n]",dest);
			changeCost(src,dest);
			changeTime(src,dest);
			break;
		case 3:	
			printf("enter source:");
			scanf(" %[^\n]",src);
			printf("enter destination:");
			scanf(" %[^\n]",dest);
			changeCost(src,dest);break;
		case 4:	
			printf("enter source:");
			scanf(" %[^\n]",src);
			printf("enter destination:");
			scanf(" %[^\n]",dest);
			changeTime(src,dest);break;
		case 5:	loop=0;	
		}
	}while(loop);
}