//lab5.cpp
//COSC130
//Dai'zjon Carney
//2/15/19
//This program lets the user play a Multi-User Dungeon through entering simple commands.
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;
//created a struct named room in order to store the title, description, and directions of a room. currently have set to nothing.
struct Room{
	string title, description;
	Room *n=nullptr;
	Room *s=nullptr;
	Room *e=nullptr;
	Room *w=nullptr;
};
//created a function that returns the integer value of room numbers, used string compare to calculate number of tildas
int NumRoom(FILE *fin){
	int z = 0;
	char *imp;
	imp = new char[256];

	while(fgets(imp, 255, fin) != nullptr){
		if(strcmp( "~\n",imp)==0){
			z++;
		}
	}

	fclose(fin);
	z = z / 3;
	return z;
}


int main (int argc, char *argv[]){
	char *imp,user, dir;
	FILE *fin;
	int NUM = 0;
	Room *RoomS;
//Tests to see if there are two arguments (program name and file name)
	if(argc != 2){
		printf("error, you made a mistake pal");
		return -1;
	}
//opened the file and allocated memory for pointer RoomS of struct Room
	imp = new char[256];
	fin = fopen(argv[1], "r");
	int count = NumRoom(fin);
	RoomS = new Room[count];
	int i = 0;
//sees if file failed
	if(fopen(argv[1], "r") == nullptr){
		printf("error, seems you messed up there buddy");
		return-1;
	}
//created a nested while loop with multiple fgets statments to read from file.used string compare to comparew two strings and see if their values where equal. this was used to know when to stop
	while(true){
		if(fgets(imp, 255, fin) == nullptr){
			break;
		}
		RoomS[i].title = string(imp);
		fgets(imp, 255, fin);
		while(true){
			fgets(imp, 255, fin);
			if(strcmp( "~\n",imp)==0){
				break;
			}
			RoomS[i].description += string(imp);
		}
		while(true){
			if(fgets(imp, 255, fin)== nullptr)
				break;
			if(strcmp( "~\n",imp)==0){
				break;
			}
			sscanf(imp, "%c %d", &dir, &NUM);

			if(dir == 'n'){
				RoomS[i].n = &(RoomS[NUM]);
			}

			if(dir == 's'){
				RoomS[i].s = &(RoomS[NUM]);
			}

			if(dir == 'e'){
				RoomS[i].e = &(RoomS[NUM]);
			}

			if(dir == 'w'){
				RoomS[i].w = &(RoomS[NUM]);
			}
		}
//used i++ so the current value in  the array of RoomS increases each iteration
		i++;
	}
//closed file
	fclose(fin);
//deallocate memory
	delete[] imp;
		Room *MUD = &RoomS[0];
//Put a switch statement in a do while to let the user enter input until they were done, in which case they hit q
	do{
		string exits= "";
		printf("> ");
		scanf(" %c", &user);

		switch (user)	{
		case 'l':
			printf("%s\n \n", MUD->title.c_str());
			printf("%s\n \n", MUD->description.c_str());
			if(MUD->n != nullptr){
				exits += "n ";
			}
			if(MUD->s != nullptr){
				exits += "s ";
			}
			if(MUD->e != nullptr){
				exits += "e ";
			}
			if(MUD->w !=nullptr){
				exits+= "w ";
			}
			printf("Exits: %s\n", exits.c_str());
			break;
		case 'n':
			if (MUD->n == nullptr){
				printf("You can't go NORTH \n");
			}
			else{
				MUD = MUD->n;
			}
			break;
		case 's':
			if(MUD->s == nullptr){
				printf("You can't go SOUTH \n");
			}
			else{
				MUD = MUD->s;
			}
			break;
		case 'e':
			if(MUD->e == nullptr){
				printf("You can't go EAST \n");
			}
			else{
				MUD = MUD->e;
			}
			break;
		case 'w':
			if(MUD->w == nullptr){
				printf("You can't go WEST \n");
			}
			else{
				MUD = MUD->w;
			}
			break;
	}
	}while(user != 'q');
	return 0;
}

