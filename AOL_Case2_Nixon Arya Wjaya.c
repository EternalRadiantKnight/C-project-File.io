#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <windows.h>
#include <conio.h>

struct storage{ //struct ini digunakan untuk menampung file yang berada dalam storage
	char location1[100];
	char location2[100];
	char price[10];
	char rooms[10];
	char bathrooms[10];
	char carparks[10];
	char type[100];
	char furnish[100];
};

struct header{ //struct ini digunakan untuk menampung line pertama pada file, disimpan jadi header aja
	char locationHeader[100];
	char cityHeader[100];
	char priceHeader[100];
	char roomsHeader[100];
	char bathroomsHeader[100];
	char carparksHeader[100];
	char typeHeader[100];
	char furnishHeader[100];
};

void displayRow(int rows, FILE* myFile){ // function ini digunakan untuk opsi pertama yaitu menampilkan banyaknya line file sesuai dengan input user
	struct storage data[rows];
	struct header top;
	
	strcpy(top.locationHeader, "Location");
	strcpy(top.cityHeader, "City");
	strcpy(top.priceHeader, "Price");
	strcpy(top.roomsHeader, "Rooms");
	strcpy(top.bathroomsHeader, "Bathroom");
	strcpy(top.carparksHeader, "Carpark");
	strcpy(top.typeHeader, "Type");
	strcpy(top.furnishHeader, "Furnish");
	
	for(int i = 0; i<rows; i++){
		fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
	}
	printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
	for(int i = 0; i<rows; i++){
		printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
	}
	rewind(myFile);
	char buffer[256];
	fgets(buffer, sizeof(buffer), myFile);
}

void menu(){ // function ini digunakan untuk menampilkan menu yang bisa user pilih
	printf("What do you want to do?\n");
	printf("1.  Display data\n");
	printf("2.  Search Data\n");
	printf("3.  Sort Data\n");
	printf("4.  Export Data\n");
	printf("5.  Exit\n");

}
void selectRow(char column[100], FILE* myFile){ // function ini digunakan untuk menampilkan isi file yang sesuai dengan input dari user, contoh user input "Location" dan "Kepong", maka sistem akan menampilkan "Kepong" dari kolom "Location"
	
	char word[100];
	struct storage data[4000];
	struct header top;
	strcpy(top.locationHeader, "Location");
	strcpy(top.cityHeader, "City");
	strcpy(top.priceHeader, "Price");
	strcpy(top.roomsHeader, "Rooms");
	strcpy(top.bathroomsHeader, "Bathroom");
	strcpy(top.carparksHeader, "Carpark");
	strcpy(top.typeHeader, "Type");
	strcpy(top.furnishHeader, "Furnish");
	int i, j, k, s;
	
	
	if(strcmp(column, "Location") == 0){
		printf("What data do you want to find? ");
		scanf("%[^\n]", word);
		i=0;
		j=0;
		k=0;
		s=0;
		
		while(!feof(myFile)){
			fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
			if(strcmp(word, data[i].location1) == 0){
			 	k = 1;
				if(s == 0){
					printf("Data found. Detail of data:\n");
					printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
					s = 1;
				}
				printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
			} 
			i++;
		}
		if(k == 0){
			printf("Data not found!\n");
		}
		rewind(myFile);
		char buffer[256];
		fgets(buffer, sizeof(buffer), myFile);
	
	}else if(strcmp(column, "City") == 0){
		printf("What data do you want to find? ");
		scanf("%[^\n]", word);
		i=0;
		j=0;
		k=0;
		s=0;
		
		while(!feof(myFile)){
			fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
			if(strcmp(word, data[i].location2) == 0){
			 	k = 1;
				if(s == 0){
					printf("Data found. Detail of data:\n");
					printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
					s = 1;
				}
				printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
			} 
			i++;
		}
		if(k == 0){
			printf("Data not found!\n");
		}
		rewind(myFile);
		char buffer[256];
		fgets(buffer, sizeof(buffer), myFile);
		
	}else if(strcmp(column, "Price") == 0){
		printf("What data do you want to find? ");
		scanf("%[^\n]", word);
		i=0;
		j=0;
		k=0;
		s=0;
		
		while(!feof(myFile)){
			fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
			if(strcmp(word, data[i].price) == 0){
			 	k = 1;
				if(s == 0){
					printf("Data found. Detail of data:\n");
					printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
					s = 1;
				}
				printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
			} 
			i++;
		}
		if(k == 0){
			printf("Data not found!\n");
		}
		rewind(myFile);
		char buffer[256];
		fgets(buffer, sizeof(buffer), myFile);
	
		
	}else if(strcmp(column, "Rooms") == 0){
		printf("What data do you want to find? ");
		scanf("%[^\n]", word);
		i=0;
		j=0;
		k=0;
		s=0;
		
		while(!feof(myFile)){
			fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
			if(strcmp(word, data[i].rooms) == 0){
			 	k = 1;
				if(s == 0){
					printf("Data found. Detail of data:\n");
					printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
					s = 1;
				}
				printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
			} 
			i++;
		}
		if(k == 0){
			printf("Data not found!\n");
		}
		rewind(myFile);
		char buffer[256];
		fgets(buffer, sizeof(buffer), myFile);
		
	}else if(strcmp(column, "Bathroom") == 0){
		printf("What data do you want to find? ");
		scanf("%[^\n]", word);
		i=0;
		j=0;
		k=0;
		s=0;
		
		while(!feof(myFile)){
			fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
			if(strcmp(word, data[i].bathrooms) == 0){
			 	k = 1;
				if(s == 0){
					printf("Data found. Detail of data:\n");
					printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
					s = 1;
				}
				printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
			} 
			i++;
		}
		if(k == 0){
			printf("Data not found!\n");
		}
		rewind(myFile);
		char buffer[256];
		fgets(buffer, sizeof(buffer), myFile);
	
		
	}else if(strcmp(column, "Carpark") == 0){
		printf("What data do you want to find? ");
		scanf("%[^\n]", word);
		i=0;
		j=0;
		k=0;
		s=0;
		
		while(!feof(myFile)){
			fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
			if(strcmp(word, data[i].carparks) == 0){
			 	k = 1;
				if(s == 0){
					printf("Data found. Detail of data:\n");
					printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
					s = 1;
				}
				printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
			} 
			i++;
		}
		if(k == 0){
			printf("Data not found!\n");
		}
		rewind(myFile);
		char buffer[256];
		fgets(buffer, sizeof(buffer), myFile);
		
	}else if(strcmp(column, "Type") == 0){
		printf("What data do you want to find? ");
		scanf("%[^\n]", word);
		i=0;
		j=0;
		k=0;
		s=0;
		
		while(!feof(myFile)){
			fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
			if(strcmp(word, data[i].type) == 0){
			 	k = 1;
				if(s == 0){
					printf("Data found. Detail of data:\n");
					printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
					s = 1;
				}
				printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
			} 
			i++;
		}
		if(k == 0){
			printf("Data not found!\n");
		}
		rewind(myFile);
		char buffer[256];
		fgets(buffer, sizeof(buffer), myFile);
		
		
	}else if(strcmp(column, "Furnish") == 0){
			printf("What data do you want to find? ");
		scanf("%[^\n]", word);
		i=0;
		j=0;
		k=0;
		s=0;
		
		while(!feof(myFile)){
			fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
			if(strcmp(word, data[i].furnish) == 0){
			 	k = 1;
				if(s == 0){
					printf("Data found. Detail of data:\n");
					printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
					s = 1;
				}
				printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
			} 
			i++;
		}
		
		if(k == 0){
			printf("Data not found!\n");
		}
		rewind(myFile);
		char buffer[256];
		fgets(buffer, sizeof(buffer), myFile);
	}
}

int housecmp(const struct storage *a, const struct storage *b, const char *col){ //fungsi dari function ini sebenarnya sama saja dengan strcmp. Namun, bedanya adalah kalau strcmp mengcompare string, maka function ini mengcompare isi dari struct
	
    if (strcmp(col, "Location") == 0) {
        return strcmp(a->location1, b->location1);
    } else if (strcmp(col, "City") == 0) {
        return strcmp(a->location2, b->location2);
    } else if (strcmp(col, "Price") == 0) {
        return atoi(a->price) - atoi(b->price);
    } else if (strcmp(col, "Rooms") == 0) {
        return atoi(a->rooms) - atoi(b->rooms);
    } else if (strcmp(col, "Bathroom") == 0) {
        return atoi(a->bathrooms) - atoi(b->bathrooms);
    } else if (strcmp(col, "Carpark") == 0) {
        return atoi(a->carparks) - atoi(b->carparks);
    } else if (strcmp(col, "Type") == 0) {
        return strcmp(a->type, b->type);
    } else if (strcmp(col, "Furnish") == 0) {
        return strcmp(a->furnish, b->furnish);
    }
    return 0;
}
void bubbleSortAsc(char column[], FILE* myFile){// function ini digunakan untuk sort data sesuai dengan keinginan user, contoh, jika user input "Location" dan "asc", maka di kolom Location akan disortir dari kecil ke besar
	rewind(myFile);
	char buffer[256];
	fgets(buffer, sizeof(buffer), myFile);
	struct storage data[4000];
	struct header top;
	strcpy(top.locationHeader, "Location");
	strcpy(top.cityHeader, "City");
	strcpy(top.priceHeader, "Price");
	strcpy(top.roomsHeader, "Rooms");
	strcpy(top.bathroomsHeader, "Bathroom");
	strcpy(top.carparksHeader, "Carpark");
	strcpy(top.typeHeader, "Type");
	strcpy(top.furnishHeader, "Furnish");
	
	for(int i = 0; !feof(myFile); i++){
		fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
	}
	
	for(int i = 0; i<3939 - 1; i++){
		for(int j = 0; j<3939 - i - 1; j++){
			if(housecmp(&data[j], &data[j+1], column)>0){
				struct storage temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	printf("Data found. Detail of data:\n");
	printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
	for(int i = 0; i<10; i++){
		printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
	}
	rewind(myFile);
}

void bubbleSortDes(char column[], FILE* myFile){// function ini digunakan untuk sort data sesuai dengan keinginan user, contoh, jika user input "Location" dan "des", maka di kolom Location akan disortir dari besar ke kecil
	rewind(myFile);
	char buffer[256];
	fgets(buffer, sizeof(buffer), myFile);
	struct storage data[4000];
	struct header top;
	strcpy(top.locationHeader, "Location");
	strcpy(top.cityHeader, "City");
	strcpy(top.priceHeader, "Price");
	strcpy(top.roomsHeader, "Rooms");
	strcpy(top.bathroomsHeader, "Bathroom");
	strcpy(top.carparksHeader, "Carpark");
	strcpy(top.typeHeader, "Type");
	strcpy(top.furnishHeader, "Furnish");
	
	for(int i = 0; !feof(myFile); i++){
		fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
	}
	
	for(int i = 0; i<3939 - 1; i++){
		for(int j = 0; j<3939 - i - 1; j++){
			if(housecmp(&data[j], &data[j+1], column)<0){
				struct storage temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	printf("Data found. Detail of data:\n");
	printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", top.locationHeader, top.cityHeader, top.priceHeader, top.roomsHeader, top.bathroomsHeader, top.carparksHeader, top.typeHeader, top.furnishHeader);
	for(int i = 0; i<10; i++){
		printf("%-30s%-20s%-15s%-7s%-12s%-12s%-10s%-10s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
	}
	rewind(myFile);
	
}



void exportFile(char file[50], FILE* myFile){//function ini digunakan untuk meng export data sesuai dengan kata yang user input, contoh jika user input kata "myFile" maka file tersebut akan di export ke file lain dengan nama "export.csv"
	struct storage data[4000];
	struct header top[100];
	rewind(myFile);
	char buffer[256];
	fgets(buffer, sizeof(buffer), myFile);
	
	int i;
	int count = 0;
	for(i = 0; !feof(myFile); i++){
		fscanf(myFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", data[i].location1, data[i].location2, &data[i].price, &data[i].rooms, &data[i].bathrooms, &data[i].carparks, data[i].type, data[i].furnish);
		count++;
	}
	
	fclose(myFile);
	
	strcat(file, ".csv");
	FILE* transfer = fopen(file, "w");
	fprintf(transfer, "Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");
	for(int i = 0; i<count; i++){
		fprintf(transfer, "%s,%s,%s,%s,%s,%s,%s,%s\n", data[i].location1, data[i].location2, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
	}
	
	fclose(transfer);
	printf("Data successfully written to file %s!\n", file);
	
}

	


int main(){ //ini merupakan function awal yang menjalankan semuanya
	
	FILE* myFile = fopen("file.csv", "r");
	
	char buffer[256];
	fgets(buffer, sizeof(buffer), myFile);
	
	int flag = 1;
	while(flag){
		menu();
		printf("Your Choice: ");
		int choice;
		scanf("%d%*c", &choice);
		while(choice < 1 || choice > 5){
			printf("Your Choice: ");
			scanf("%d%*c", &choice);
		}
	
	
		switch(choice){
			case 1:	
				int rows;
				printf("Number of rows: ");
				scanf("%d", &rows);
				
				while(rows < 1){
					printf("Number of rows: ");
					scanf("%d", &rows);
				}
				if (rows >= 3939) { 
	    			rows = 3939;
				}
				displayRow(rows, myFile); //function yang digunakan untuk menampilkan banyaknya row yang user pilih	
				break;
			case 2:
				char column[100];
				printf("Choose column: ");
				scanf("%s%*c", column);
				while(strcmp(column, "Location") != 0 && strcmp(column, "City") != 0 && strcmp(column, "Price") != 0 && strcmp(column, "Rooms") != 0 && strcmp(column, "Bathroom") != 0 && strcmp(column, "Carpark") != 0 && strcmp(column, "Type") != 0 && strcmp(column, "Furnish") != 0){
					printf("Choose column: ");
					scanf("%s%*c", column);
				}
				selectRow(column, myFile); //function yang digunakan untuk menampilkan row dan nama data yang user pilih
				break;
			case 3:
				char direct[20];
				printf("Choose column: ");
				scanf("%s%*c", column);
				while(strcmp(column, "Location") != 0 && strcmp(column, "City") != 0 && strcmp(column, "Price") != 0 && strcmp(column, "Rooms") != 0 && strcmp(column, "Bathroom") != 0 && strcmp(column, "Carpark") != 0 && strcmp(column, "Type") != 0 && strcmp(column, "Furnish") != 0){
					printf("Choose column: ");
					scanf("%s%*c", column);
				}
				printf("Sort ascending or descending? ");
				scanf("%s%*c", direct);
				while(strcmp(direct, "asc") != 0 && strcmp(direct, "des") != 0){
					printf("Sort ascending or descending? ");
					scanf("%s%*c", direct);
				}
				if(strcmp(direct,"asc") == 0){
					bubbleSortAsc(column, myFile); //function ini digunakan untuk sortir data dari kolom yang user pilih menjadi kecil ke besar
				}
				
				if(strcmp(direct, "des") == 0){ 
					bubbleSortDes(column, myFile); //function ini digunakan untuk sortir data dari kolom yang user pilih menjadi besar ke kecil
				}
				
				
				break;
			case 4:
				printf("File name: ");
				char file[50];
				scanf("%[^\n]", file);
				exportFile(file, myFile); // function ini digunakan untuk export file ke file lain sesuai dengan kata yang user input
				break;
				
			case 5:
				flag = 0;
				
		}
	}	
	fclose(myFile);
	return 0;
}
