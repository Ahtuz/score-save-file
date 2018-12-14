#include<stdio.h>
#include<string.h>

	int choice, index, skortemp, ctr, min;
	char namatemp[20];
	FILE*p=fopen("soal09.txt","r");

	struct player{
		char name[20];
		int avgscore;
		int numofplay;
	}player[100], temp;
	
	void sort(){
		for(int i=0;i<index;i++){
			for(int j=0;j<index-1;j++){
				if(player[j].avgscore<player[j+1].avgscore){
					temp=player[j];
					player[j]=player[j+1];
					player[j+1]=temp;
				}
			}
		}
	}

	void selsort(){
		for(int i=0;i<index;i++){
			min=i;
			for(int j=i;j<index;j++){
				if(player[min].avgscore>player[j].avgscore){
					min=j;
				}
			}
			temp=player[i];
			player[i]=player[min];
			player[min]=temp;
		}
	}

int main(){
	while(fscanf(p, "%s %d %d", player[index].name, &player[index].avgscore, &player[index].numofplay)!=EOF) index++;
	do{
		selsort();
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("Score Record DotA Player\n========================\n1.View Record\n2.Add Player Record\n3.Add New Player\n4.Delete Player\n5.Save and Exit\n\n");

		do{
			printf("Input your choice[1..5]:");
			scanf("%d", &choice); fflush stdin;
		}while(choice < 0 || choice > 5);

		switch(choice){
		case 1:
			printf("\n\n\n\n\n\n\n\n\n\n");
			printf(" Player Name     | Average Score   | Number of Playing\n=======================================================\n");
			for(int i=0;i<index;i++){
				printf(" %-15s | %-15d | %-15d\n", player[i].name, player[i].avgscore, player[i].numofplay);
			}

			getchar();
			break;
		case 2:
			printf("\n\n\n\n\n\n\n\n\n\n");
			printf("Input player name[1..10]:");
			scanf("%s", namatemp); fflush stdin;

			for(int i=0;i<index;i++){
				if(strcmpi(namatemp, player[i].name)==0){
					printf("Input player score[0..100]:");
					scanf("%d", &skortemp); fflush stdin;
					player[i].avgscore=((player[i].avgscore*player[i].numofplay)+skortemp)/(player[i].numofplay+1);
					player[i].numofplay+=1;
				}
			}

			getchar();
			break;
		case 3:
			printf("\n\n\n\n\n\n\n\n\n\n");
			printf("Input player name[1..10]:");
			scanf("%s", namatemp); fflush stdin;
			
			strcpy(player[index].name, namatemp);
			player[index].avgscore=0;
			player[index].numofplay=0;

			index++;

			getchar();
			break;
		case 4:
			printf("\n\n\n\n\n\n\n\n\n\n");
			printf("Input player name[1..10]:");
			scanf("%s", namatemp); fflush stdin;

			for(int i =0;i<index;i++){
				if(strcmp(player[i].name, namatemp)==0){
					for(int j=i;j<index;j++){
						player[j]=player[j+1];
					}
					index--;
				}
			}

			getchar();
			break;
		}
	}while(choice!=5);

	FILE*p=fopen("soal09.txt","w");
	for(int i=0;i<index;i++){
		fprintf(p, "%s %d %d\n", player[i].name, player[i].avgscore, player[i].numofplay);
	}
	fclose(p);
	getchar();
	return 0;
}