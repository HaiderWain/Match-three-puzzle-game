#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


using namespace std;

void create_board(char Board[][10]);
void refresh_board(char Board[][10]);
char get_random_shape();
bool check_board(char Board[][10],bool show_cin);
void swapping(char Board[][10]);
void Save_Game(char Board[][10]);
void Load_Game(char Board[][10]);


int main(){
	char Board[10][10]={};
	create_board(Board);
	swapping(Board);
	cout<<"\n***************************************************";
	cout<<"\n***       Thanks For Playing The Game.          ***";
	cout<<"\n***************************************************";
}
char get_random_shape(){
	char shape = '!';
	int random_shape=rand()%5+1;
		if (random_shape==1){
				shape='!';
			}
			else if (random_shape==2){
				shape='@';
			}
			else if (random_shape==3){
				shape='#';
			}
			else if (random_shape==4){
				shape='$';
			}
			else if (random_shape==5){
				shape='%';
			}
			return shape;
}

void create_board(char Board[][10]){
	char shape;
	srand(time(0));
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			shape = get_random_shape();			
			Board[i][j]=shape;
		}
	}
	check_board(Board,false);
}

void swapping(char Board[][10]){
	int score=0;
	int x_coor,y_coor,temp,targetCoordinatex,targetCoordinatey;
	char WSDA,game_situation;
	
	cout<<"\n******************** RULES ********************";
	cout<<"\n*      Enter W to swap with Upper symbol.     *";
	cout<<"\n*      Enter S to swap with Lower symmbol.    *";
	cout<<"\n*      Enter D to swap with Right symbol.     *";
	cout<<"\n*      Enter A to swap with Left symbol.      *";
	cout<<"\n*      Enter S to save the game.              *";
	cout<<"\n*      Enter L to load the game.              *";
	cout<<"\n*      Enter X to stop playing the game :(    *";
	cout<<"\n***********************************************";
	
	game_situation='Z';
	while (game_situation!='X'){
	cout<<"\nEnter coordinates of symbols you want to swap : ";
	cout<<"\nEnter ROW number  0-9 : ";
	cin>>x_coor;
	cout<<"Ener Coloumn number 0-9 : ";
	cin>>y_coor;
	cout<<"Now Enter W/S/D/A to swap with neighbouring symbols : ";
	cin>>WSDA;
	
	temp=Board[x_coor][y_coor];
	
	if (WSDA=='W' || WSDA == 'w'){
		targetCoordinatex=x_coor-1;
		targetCoordinatey=y_coor;
		}
	
    if (WSDA=='S' || WSDA == 's'){
    	targetCoordinatex=x_coor+1;
		targetCoordinatey=y_coor;
	}
	if (WSDA=='D' || WSDA == 'd'){
		targetCoordinatex=x_coor;
		targetCoordinatey=y_coor+1;
	}
	if (WSDA=='A' || WSDA == 'a'){
		targetCoordinatex=x_coor;
		targetCoordinatey=y_coor-1;
	}
	
	Board[x_coor][y_coor]=Board[targetCoordinatex][targetCoordinatey];
	Board[targetCoordinatex][targetCoordinatey]=temp;
	refresh_board(Board);
	Sleep(800);
	bool revert_swapping=check_board(Board,true);
	if (revert_swapping){
		temp=Board[x_coor][y_coor];
		Board[x_coor][y_coor]=Board[targetCoordinatex][targetCoordinatey];
	    Board[targetCoordinatex][targetCoordinatey]=temp;
	    refresh_board(Board);
	    score=score-10;
	}
	score=score+10;
	cout<<"Total Score : "<<score;
	cout<<"\nPress <X> to Quit. <Y> to continue. <S> to Save game. <L> to Load game.";
	cin>>game_situation;
	if (game_situation=='S'){
		Save_Game(Board);
		cout<<"\nGAME HAS BEEN SAVED.";
	}
	if (game_situation=='L'){
		Load_Game(Board);
		cout<<"\nGAME HAS BEEN LOADED.";
	}
}
}

bool check_board(char Board[][10],bool show_cin){
	bool revert_swapping=true;
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			bool combo_found=false;
		    int combo[2][2]={{0,0},{0,0}};
		    if (j<8 && Board[i][j]==Board[i][j+1] && Board[i][j]==Board[i][j+2] ){
		    	combo[0][0]=i;
		    	combo[0][1]=j;
		    	combo[1][0]=i;
		    	combo[1][1]=j+2;
		    	combo_found=true;
		    	revert_swapping=false;
		    }
		    else if (Board[i][j]==Board[i+1][j] && Board[i][j]==Board[i+2][j] && i<8){
		    	combo[0][0]=i;
		    	combo[0][1]=j;
		   	    combo[1][0]=i+2;
		   	    combo[1][1]=j;
		   	    combo_found=true;
		   	    revert_swapping=false;
		   	}
		   	if (combo_found){
		   		if (show_cin){
		   			for(int m=combo[0][0]; m<=combo[1][0];  m++){
		   				for(int n=combo[0][1]; n<=combo[1][1]; n++){
		   					Board[m][n]='-';
		   				}
		   			}
		   			refresh_board(Board);
		   			Sleep(1000);          
				}
					   srand(time(0));
					   for(int o=combo[0][0];o<=combo[1][0];o++){
					   	for(int p=combo[0][1];p<=combo[1][1];p++){
						   for (int k=o; k>=0; k--){
						   	if (k==0){
						   		Board[k][p]=get_random_shape();
						   	}
						   	else{
						   		Board[k][p]=Board[k-1][p];
							}
						}
					}
				}
				refresh_board(Board);
				check_board(Board,show_cin);
				}
			}
		}
			return revert_swapping;
}
	


void refresh_board(char Board[][10]){
	system("CLS");
		cout<<"     0  1  2  3  4  5  6  7  8  9"<<endl<<endl;
		for (int i=0; i<10; i++){
			cout<<i<<"    ";
			for (int j=0; j<10; j++){
				
				cout<<Board[i][j]<<"  ";
			}
			cout<<endl;
		}
}

void Save_Game(char Board[][10]){
	ofstream fout("SymphonyOfSymbols.txt");
	if (!fout){
		cout<<"ERROR";
	}
	else {
		for (int i=0; i<10; i++){
			for (int j=0; j<10; j++){
				fout<<Board[i][j]<<"  ";
			}
			fout<<endl;
		}
	}
}
void Load_Game(char Board[][10]){
	ifstream fin("SymphonyOfSymbols.txt");
	if (!fin){
		cout<<"ERROR";
	}
	else {
			system("CLS");
		cout<<"     0  1  2  3  4  5  6  7  8  9"<<endl<<endl;
		for (int i=0; i<10; i++){
			cout<<i<<"    ";
			for (int j=0; j<10; j++){
				fin>>Board[i][j];
				cout<<Board[i][j]<<"  ";
			}
			cout<<endl;
		}
        cout<<"\nGame has been loaded.";
	}
}
