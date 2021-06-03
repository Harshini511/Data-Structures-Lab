#define MAX 50
void matrix(char file[],int adj[MAX][MAX],int no_of_vertices){
	FILE *fp;int row,col,i,j;char str[MAX];
	fp=fopen(file,"r");row=0;
			while(!feof(fp)){
				fgets(str,(no_of_vertices*2),fp);
				col=0;
				if(strlen(str)>=no_of_vertices*2-1){
					for(i=0;col<no_of_vertices;i++){
						j=i;
						while(isdigit(str[j])){
							adj[row][col]*=10;
							adj[row][col]+=(int)str[j];
							adj[row][col]-=48;
							j++;
						}
						i=j;col++;
					}
					row++;
				}
			}
			fclose(fp);
}
