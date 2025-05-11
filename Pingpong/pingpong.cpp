#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

const int width = 45;
const int height = 10;

int ballx, bally;

int ball_velx = 1;
int ball_vely = 1;

int left_paddle, right_paddle;
const int paddleHeight = 4;

int scoreLeft = 0, scoreRight = 0;
bool paused = false;
void showGameName(){
    cout<<"*************************"<<endl;
    cout<<"welcome to PING PONG GAME"<<endl;
    cout<<"*************************"<<endl;
    Sleep(1000);
}
void playingfield() {

    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    // upper boundary line :
    for (int i = 0; i < width + 2; i++) {
        cout << "-";
    }
    cout << endl;

    // left boundary line :

    for (int i = 0; i < height; i++) {
        cout << "|";

        if (i >= left_paddle && i < left_paddle + paddleHeight) {
            cout << "|";
        }
        else {
            cout << " ";
        }

        for (int j = 1; j < width - 1; j++) {
            if (j == ballx && i == bally) {
                cout << "O";
            }
            else {
                cout << " ";
            }
        }

        if (i >= right_paddle && i < right_paddle + paddleHeight) {
            cout << "|";
        }
        else {
            cout << " ";
        }
        // right boundary line :

        cout << "|";
        cout << endl;
    }
    // lower boundary line :
    for (int i = 0; i < width + 2; i++) {
        cout << "-";
    }
    cout << endl;

    cout << "Score: Left Player: " << scoreLeft << " | Right Player: " << scoreRight << endl;
    

}
void setup() {
    // Ball position:
    ballx = width / 2;
    bally = height / 2;

    // PADDLES PLACED CENTRALLY IN THE FIELD WALL :
    left_paddle = height / 2 - paddleHeight / 2;
    right_paddle = height / 2 - paddleHeight / 2;
}
void resetball() {

    // centred  the ball horizontally and vertically as well at the starting of the game :
    ballx = width / 2;
    bally = height / 2;

    // reverse the ball direction after collision :
    ball_velx = -ball_velx;
}
void move_paddles() {

    // for paddles movement :
    if (GetAsyncKeyState('W') & 0x8000) {
        if (left_paddle > 0) left_paddle--; // Move up
    }
    if (GetAsyncKeyState('S') & 0x8000) {
        if (left_paddle < height - paddleHeight) left_paddle++; // Move down
    }
    if (GetAsyncKeyState('I') & 0x8000) {
        if (right_paddle > 0) right_paddle--; // Move up
    }
    if (GetAsyncKeyState('K') & 0x8000) {
        if (right_paddle < height - paddleHeight) right_paddle++; // Move down
    }
}

void hidecursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, & info);
}

void startgame(){
    char choice;
    cout<<"press 'Y'for start the game or 'n' for exit :"<<endl;
    cin>>choice;

    if(choice == 'n' || choice == 'N'){
        cout<<"TERE BAS KA NII HAI CHAL NIKAL BHADWE : "<<endl;
        exit(0);
    }
    else if(choice == 'y' || choice == 'Y'){
         cout<<"yee abhi mjaa aayega nhh bidu........ :"<<endl;
         Sleep(2000);
    }
    else{
        cout<<"abe andhe y or n press krne ko bola hai nhh hijde:"<<endl;
        startgame();
    }
 }

int main() {
    showGameName();
    setup();
    hidecursor();
    startgame();
    while (true) {

        if(GetAsyncKeyState('P') & 0x8000 ){
            paused = true;
        }
        if(GetAsyncKeyState ('R') & 0x8000){
            paused = false;
        }

        playingfield();

        if(!paused){
        move_paddles();

        // cout << "Ball Position: (" << ballx << ", " << bally << ")" << endl;

        Sleep(10);

        // handle collisions with walls 

        ballx += ball_velx;
        bally += ball_vely;

        if (bally == 0 || bally == height - 1) {
            ball_vely *= -1;
        }

        //Handle Collisions with the Paddles

        if (ballx == 1 && (bally >= left_paddle && bally <= left_paddle + paddleHeight)) {
            ball_velx *= -1;
        }

        if (ballx == width - 2 && (bally >= right_paddle && bally <= right_paddle + paddleHeight)) {
            ball_velx *= -1;
        }

        // for scoring

        if (ballx == 0) {
            scoreRight++;
            resetball();
        }

        if (ballx == width - 1) {
            scoreLeft++;
            resetball();
        }


    }
      Sleep(10);
    }
    return 0;
}