
/*
 * GccApplication20.c
 *
 * Created: 1/13/2018 9:21:53 AM
 * Author : ANTAREEP SINGHA
 */





#include <iostream>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 
void delay(unsigned int millis)
{
    clock_t reqd_clock = millis + clock();
    while (reqd_clock > clock());
}


void DINO_Setup()
{
    system("cls");
    gotoxy(20,1);
    cout<<"DINO DASH: THE STORY OF A T-REX";
    gotoxy(25,3);
    cout<<"DEVELOPER:ANTAREEP SINGHA";
    gotoxy(20,5);
    printf("Press X to Exit, Press Space to Jump");
    gotoxy(62,2);
    printf("SCORE : ");
    gotoxy(1,25);
    for(int x=0;x<79;x++)
    printf("ß");
}
 
int t,speed=20;
//bool speed_decrement=true;

class Dino_Controls{
public:
void Display_Grid(int jump=0)
{
    static int a=1;
 
    if(jump==0)
        t=0;
    else if(jump==2){
        t--;}
    else {t++;;}
    //DISPLAYING DINO
    //##############################################
    //##############################################
    gotoxy(2,15-t);
    printf("                 ");
    gotoxy(2,16-t);
    cout<<"         ÜÛßÛÛÛÛÜ";
    gotoxy(2,17-t);
    cout<<"         ÛÛÛÛÛÛÛÛ";
    gotoxy(2,18-t);
    cout<<"         ÛÛÛÛÛßßß";
    gotoxy(2,19-t);
    cout<<" Û      ÜÛÛÛÛßßß ";
    gotoxy(2,20-t);
    cout<<" ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ";
    gotoxy(2,21-t);
    cout<<" ßÛÛÛÛÛÛÛÛÛÛÛ  ß ";
    gotoxy(2,22-t);
    cout<<"   ßÛÛÛÛÛÛÛß     ";
    gotoxy(2,23-t);
    if(jump==1 || jump==2){
    cout<<"    ÛÛß ßÛ       ";
    gotoxy(2,24-t);
    cout<<"    ÛÜ   ÛÜ      ";
    }else if(a==1)
    {
    cout<<"    ßÛÛß  ßßß    ";
    gotoxy(2,24-t);
    cout<<"      ÛÜ         ";
    a=2;
    }
    else if(a==2)
    {
    cout<<"     ßÛÜ ßÛ      ";
    gotoxy(2,24-t);
    cout<<"          ÛÜ     ";
    a=1;
    }
    gotoxy(2,25-t);
    if(jump!=0){
    cout<<"                ";
    }
    else
    {
         
    cout<<"ßßßßßßßßßßßßßßßßß";
    }
      //##############################################
     //##############################################
    delay(speed);
}

void DINO_Move()
{
    static int x=0,scr=0;
    if(x==56 && t<4)
    {
    speed=20;
    //if(speed_decrement){
   // if(scr%5==0)speed-=10;}
   // if(speed==10)speed_decrement =false;
    gotoxy(36,13);
    cout<<"Game Over";
    getch();
    gotoxy(36,8);
    cout<<"         ";
    gotoxy(36,10);
    }
    //DISPLAYING GRASS
    //######################
    gotoxy(74-x,20);
    cout<<"Û    Û ";
    gotoxy(74-x,21);
    cout<<"Û    Û ";
    gotoxy(74-x,22);
    cout<<"ÛÜÜÜÜÛ ";
    gotoxy(74-x,23);
    cout<<"  Û    ";
    gotoxy(74-x,24);
    cout<<"  Û  " ;
    //#######################
    x++;
    scr++;
    gotoxy(70,2);
    cout<<scr;
    
    cout<<"     ";
    if(x==73)
    {
    x=0;
    gotoxy(70,2);
    printf("%d",scr);
    if(speed>3)
    speed-=1;
    }
}
}DINO;



int main()
{
    system("mode con: lines=29 cols=82");
    char ch;
    int i;
    DINO_Setup();
    while(true)
    {
        while(!kbhit())
        {
           DINO.Display_Grid();
           DINO.DINO_Move();
        }
        ch=getch();
        if(ch==' ')
        {
            for(i=0;i<10;i++)
            {
           DINO.Display_Grid(1);
           DINO.DINO_Move();
            }
            for(i=0;i<10;i++)
            {
           DINO.Display_Grid(2);
           DINO.DINO_Move();
            }
        }
        else if (ch=='x')
            return(0);
    } 
     
}
