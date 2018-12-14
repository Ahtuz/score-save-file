#include<stdio.h>
#include<string.h>

struct soal09{
	char nama[20];
	int avgskor;
	int play;
	int skor;
};


int main(){
	int pilih, index = 0;
	struct soal09 filee[20];
	char namatemp[30];
	int count=0;
	char deletenama[20];
	int deletetemp;
	char tambahNamaTemp[20];
	int ctr=0;


	FILE *p;
	p = fopen("soal09.txt", "r");
	while(fscanf(p, "%s %d %d\n", filee[index].nama, &filee[index].avgskor, &filee[index].play) != EOF) index++;
	fclose(p);

	do{
		for(int i=0;i<10;i++){
				printf("\n");
		}
		printf("Score Record DotA Player\n========================\n1.View Record\n2.Add Player Record\n3.Add New Player\n4.Delete Player\n5.Save and Exit");
	
		do{
			printf("\nInput your choice[1..5]:");
			scanf("%d", &pilih); fflush stdin;
		}while(pilih<1 || pilih>5);

		switch(pilih){
		case 1:
			for(int i=0;i<30;i++){
				printf("\n");
			}

			printf("Player Name     | Average Score   | Number of Playing\n=======================================================\n");
			for(int i=0;i<index;i++){
				printf("%-15s | %-15d | %-15d\n", filee[i].nama, filee[i].avgskor, filee[i].play);
			}

			printf("\n\nPress Enter to Continue...");

			getchar();

			break;

		case 2:
			for(int i=0;i<30;i++){
				printf("\n");
			}
			count=0;

			printf("Input player name[1..10]:");
			scanf("%s", namatemp); fflush stdin;

			for(int i = 0;i<index;i++){
				if(strcmpi(filee[i].nama, namatemp)==0){
					do{
						printf("Input player score[0..100]:");
						scanf("%d", &filee[i].skor); fflush stdin;
					}while(filee[i].skor > 100 || filee[i].skor < 0);
					filee[i].play++;
					filee[i].avgskor = ((filee[i].avgskor*(filee[i].play-1)) + filee[i].skor) / filee[i].play;
					printf("Data successfully updated!");
				}
				else count++;
			}

			if(count==index){
				printf("Name of %s not found!", namatemp);
				count=0;
			}

			p=fopen("soal09.txt","w");
			for(int i=0;i<index;i++){
				fprintf(p, "%s %d %d\n", filee[i].nama, filee[i].avgskor, filee[i].play);
			}
			fclose(p);

			printf("\n\nPress Enter to Continue...");

			getchar();

			break;

		case 3:
			for(int i=0;i<30;i++){
				printf("\n");
			}

			ctr=0;

			do{
				printf("Input Player's name:");
				scanf("%s", tambahNamaTemp); fflush stdin;
			}while(strlen(tambahNamaTemp)>10);

			for(int i=0;i<index;i++){
				if(strcmpi(tambahNamaTemp,filee[i].nama)==0){
					ctr=1;
				}
			}

			if(ctr==0){
				strcpy(filee[index].nama,tambahNamaTemp);
				filee[index].avgskor=0;
				filee[index].play=0;
				printf("%s successfully added!", filee[index].nama);
				index++;
			}

			if(ctr==1){
				printf("Player name already exist.");
			}

			printf("\n\nPress Enter to Continue...");

			

			getchar();

			break;

		case 4:
			for(int i=0;i<30;i++){
				printf("\n");
			}

			count = 0;

			printf("Input player name:");
			scanf("%s", deletenama); fflush stdin;

			for(int i=0;i<index;i++){
				if(strcmpi(filee[i].nama, deletenama)==0){
						deletetemp = i;
						for(int i = deletetemp; i<index;i++){
							filee[i]=filee[i+1];
						}
						index--;
						count=1;
						printf("%s successfully deleted.", deletenama);
				}
			}

			if(count==0){
				printf("Name not found!");
			}

			printf("\n\nPress Enter to Continue...");

			getchar();

			break;

		}

	}while(pilih!=5);

	p = fopen("soal09.txt","w");

	for(int i=0;i<index;i++){
		fprintf(p, "%s %d %d\n", filee[i].nama, filee[i].avgskor, filee[i].play);
	}

	fclose(p);

	printf("\n\nData successfully saved to \"soal09.txt\".\nPress Enter to exit the program.");

	getchar();
	return 0;
}