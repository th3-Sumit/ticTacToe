#include<iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row, column;
char turn = 'X';
bool draw = false;

void display_board(){
	system("cls");
	    	
	cout<<"******************** T I C   T A  C   T O E ***********************"<<endl<<endl<<endl;
    cout<<"\t\tPLAYER 1 [X]"<<endl;
    cout<<"\t\tPLAYER 2 [O]"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"\t\t     |     |     "<<endl;

    
	
}

void player_turn(){
	int option;
	
	if (turn == 'X')
	cout<<"\n\t Player1 [X] turn : ";
	
	if (turn == 'O')
	cout<<"\n\t Player 2 [O] turn : ";
	
	cin>>option;
	
	switch(option){
		case 1: row = 0; column = 0; break;
		case 2: row = 0; column = 1; break;
		case 3: row = 0; column = 2; break;
		case 4: row = 1; column = 0; break;
		case 5: row = 1; column = 1; break;
		case 6: row = 1; column = 2; break;
		case 7: row = 2; column = 0; break;
		case 8: row = 2; column = 1; break;
		case 9: row = 2; column = 2; break;
		
		default:
			cout<<"Invalid option";
			break;
			
	}
	if(turn == 'X'&& board[row][column] != 'X'&& board[row][column] != 'O'){
	
		board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O'&& board[row][column] != 'X'&& board[row][column] != 'O')
	{
		board[row][column] = 'O';
		turn = 'X';
	}
	
	else{
		cout<<"Box already filled...!!!";
		cout<<"please try Again";
		player_turn();
	}
	
}

bool gameover(){
	for(int i=0; i<3; i++){
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
		return false;
		
	}
	for(int i=0; i<3; i++){
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
		return false;
		
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return false;

	
	
	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++)
	if (board[i][j] != 'x' && board[i][j] != 'O')
	return true;

	draw = true;
	return false;
}

int main(){
    while(gameover()){
    	
    	display_board();
    	player_turn();
    	gameover();
    	display_board();
    	
    	   
	}
	
	
	if(turn == 'X' && draw == false)
	cout<<"Player 2 wins :";

	else if (turn == 'O' && draw == false)
	cout<<"Player 1 Wins : ";

	else 
	cout<<"DRAW GAME";

    return 0;
}
