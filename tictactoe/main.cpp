#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char motO[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char luot = 'X';

bool Win();
bool isMine(char a, char b);
bool isYours(char a, char b);
char Winner();
int Attack();
void Draw();
void DanhO();
void Doicho();

void PlayWithComputer();
void PlayWithHuman();

int main()
{

    int chon = 0;
    do{
          cout << "====TRO=CHOI=TIC=TAC=TOE====" << endl;
          cout << "1. Choi voi nguoi ke ben. " << endl;
          cout << "2. Choi voi may tinh. " << endl;
          cout << "Chon : " ;
          cin >> chon;
          if (chon == 1) PlayWithHuman();
          else if (chon == 2) PlayWithComputer();
    }while(true);
    return 0;
}

void Draw()
{
    #ifdef linux
    system("tput clear");
    #endif
    #ifdef _WIN32
    system("cls");
    #endif
    for (int i = 0; i < 9 ; i++)
    {
        cout << motO[i] << " ";
        if (((i + 1) % 3 == 0) && ((i + 1) > 0)) cout << endl;
    }
}

void Doicho()
{
    if (luot == 'X'){
        luot = 'O';
    }
    else if (luot == 'O') luot = 'X';
}

void Danh()
{
    int a;
    do {
        cout << "Danh vao o so : " ;
        cin >> a;
    }while ((a < 1) || (a > 9) || motO[a-1] == 'X' || motO[a-1] == 'O');
    motO[a-1] = luot;
}
bool Win(){

    if ((motO[0]==motO[4]) && (motO[4]==motO[8])) {
        return true;
    }
    if ((motO[2]==motO[4]) && (motO[4]==motO[6])) {
        return true;
    }
    for (int i = 0; i <=6 ; i=i+3)
    {
        if ((motO[i] == motO[i+1]) && (motO[i+1] == motO[i+2]))
        {
            return true;
        }
    }
    for (int i = 0 ; i < 3 ; i++ )
    {
        if ((motO[i]==motO[i+3]) && (motO[i+3] == motO[i+6]))
        {
            return true;
        }
    }
    return false;
}

char Winner()
{
    if ((motO[0]==motO[4]) && (motO[4]==motO[8])) {
        return motO[0];
    }
    if ((motO[2]==motO[4]) && (motO[4]==motO[6])) {
        return motO[2];
    }
    for (int i = 0; i <=6 ; i=i+3)
    {
        if ((motO[i] == motO[i+1]) && (motO[i+1] == motO[i+2]))
        {
            return motO[i];
        }
    }
    for (int i = 0 ; i < 3 ; i++ )
    {
        if ((motO[i]==motO[i+3]) && (motO[i+3] == motO[i+6]))
        {
            return motO[i];
        }
    }
    return 'X';
}

void PlayWithHuman()
{
    while (!Win()){

        Draw();
        Danh();
        Doicho();
    }
    cout << Winner() << "chien thang !!!"<< endl;
}

bool isMine(char a, char b)
{
    if (( b == 'O') && (a == 'O')) return true;
    else
    return false;
}

bool isYours(char a, char b)
{
    if ((b == 'X') && (a == 'X')) return true;
    else
    return false;
}


int Attack()
{
    for (int i = 0; i < 3; i++)
    {
        if (isMine(motO[i],motO[i+3])) return (i+6);
        else if (isMine(motO[i+3],motO[i+6])) return (i);
        else if (isMine(motO[i+6],motO[i])) return (i+3);

        else if (isMine(motO[i*3],motO[i*3+1])) return i*3+2;
        else if (isMine(motO[i*3+1],motO[i*3+2])) return i*3;
        else if (isMine(motO[i*3],motO[i*3+2])) return i*3+1;

    }
    if (isMine(motO[0],motO[4])) return 8;
    else if (isMine(motO[4],motO[8])) return 0;
    else if (isMine(motO[0],motO[8])) return 4;
    else if (isMine(motO[2],motO[4])) return 6;
    else if (isMine(motO[4],motO[6])) return 2;
    else if (isMine(motO[6],motO[2])) return 4;
    else

    for (int i = 0; i < 3; i++)
      {
          if (isYours(motO[i],motO[i+3])) return (i+6);
          else if (isYours(motO[i+3],motO[i+6])) return (i);
          else if (isYours(motO[i+6],motO[i])) return (i+3);

          else if (isYours(motO[i*3],motO[i*3+1])) return i*3+2;
          else if (isYours(motO[i*3+1],motO[i*3+2])) return i*3;
          else if (isYours(motO[i*3],motO[i*3+2])) return i*3+1;

      }

    if (isYours(motO[0],motO[4])) return 8;
    else if (isYours(motO[4],motO[8])) return 0;
    else if (isYours(motO[0],motO[8])) return 4;

    else if (isYours(motO[2],motO[4])) return 6;
    else if (isYours(motO[4],motO[6])) return 2;
    else if (isYours(motO[6],motO[2])) return 4;
        else

    for (int i = 0; i < 9; i++)
      {
        if ((motO[i] != 'X') && (motO[i] != 'O')) return i;
      }
    return 0;
}

void PlayWithComputer()
{
    do {
    int a;
    do {
        cout << "Danh vao o so : " ;
        cin >> a;
    }while ((a < 1) || (a > 9) || motO[a-1] == 'X' || motO[a-1] == 'O');
    motO[a-1] = 'X';
    Draw();
    DanhO();
    Draw();
    }while (!Win());
    cout << Winner() << " chien thang !!!" << endl;
}

void DanhO()
{
    int o = Attack();
    motO[o] = 'O';
}

