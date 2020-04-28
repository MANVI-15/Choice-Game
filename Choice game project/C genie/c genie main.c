#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<MMsystem.h>
char ctemp;
int itemp;
char stemp[100];
char userinq1[100];
int flag1;

void create(FILE *fp);
void delete(int x,char d);
void display();
void question1();
void win(char winner[20]);
void superheroes();
void cricketers();
void cartoon();
void bollywood();
void scientists();
void dispchar();
void UI();
void clrscreen();
void credits();
void delay(unsigned int ms);
void gotoxy(int x,int y);
void drawbox(int x1, int y1, int x2, int y2, int d);
void logo(int x, int y);




struct answer{
char ans;
struct answer *next;
};
struct answer *start, *temp, *end;

struct headnodes
{
    char name[20];
    struct answer* head;
    struct headnodes *next;
};
struct headnodes *headstart,*headtemp, *headtemp2,*headend;
char chtemp;



void create(FILE *fp)
{
    int i=0;
    char ch='\0';
    while(i<7)
    {   int j=-1;
        headtemp=malloc(sizeof(struct headnodes));
        headtemp->next=NULL;
        headtemp->head=NULL;
        while(1>0)
        {j++;
            ch=fgetc(fp);
            if(ch=='\n')
                break;
            else{
            headtemp->name[j]=ch;
            }
        }
        headtemp->name[j]='\0';
        while(1>0)
        {
            chtemp=fgetc(fp);
            if(chtemp=='\n')
            {
                break;
            }
            else
            {
                temp=malloc(sizeof(struct answer));
                temp->ans=chtemp;
                temp->next=NULL;
                if(headtemp->head==NULL)
                {
                    headtemp->head=temp;
                    end=temp;
                }
                else
                {
                    end->next=temp;
                    end=temp;
                }
            }
        }
        if(headstart==NULL)
        {
            headstart=headtemp;
            headend=headtemp;

        }
        else
        {
        headend->next=headtemp;
        headend=headtemp;
        }
        i++;
    }
}

void delete(int x,char d)
{int i;
headtemp=headstart;
while(headtemp!=NULL)
{
    temp=headtemp->head;
    if(headtemp==headstart)
    {
        temp=headstart->head;
        for(i=0;i<x-1;i++)
            temp=temp->next;

        if(temp->ans!=d&&temp->ans!=d-32){
        headtemp=headstart->next;
        headstart=headstart->next;
        }
        else
        {
            headtemp2=headtemp;
            headtemp=headstart->next;
        }

    }
    else
    {int i;
        for(i=0;i<x-1;i++)
            temp=temp->next;
        if(temp->ans!=d&&temp->ans!=d-32)
        {
            headtemp2->next=headtemp->next;
            headtemp=headtemp->next;
        }
        else
        {
            headtemp2=headtemp;
            headtemp=headtemp->next;
        }

    }
}headend=headtemp2;
}

void display()
{
    headtemp=headstart;
    while(headtemp!=NULL)
    {
        printf("%s\n",headtemp->name);
        temp=headtemp->head;
        while(temp!=NULL)
        {
            printf("%c",temp->ans);
            temp=temp->next;
        }
        printf("\n");
        headtemp=headtemp->next;
    }
}

void question1()
{
    char ch;
    FILE *ques1;
ques1= fopen("D:\\CS project\\question1.txt","r");
       int flag=0;
       int k;
    for(k=0;k<10;k++)
    {
        userinq1[k]=NULL;
    }
        int i;
    for(i=0;i<5;i++)
    {
        clrscreen();
        logo(32,2);
        gotoxy(45,10);

        printf("Enter 'Y' for yes and 'N' for no");
        gotoxy(45,13);
        Beep(5000,200);
        while(ch!=EOF){

        ch=fgetc(ques1);
        if(ch=='\n')
        break;
        else
        printf("%c",ch);
        }


        delay(200);

            gotoxy(60,17);

        scanf("%c",&userinq1[i]);
        Beep(6500,200);
        fflush(stdin);
        if((userinq1[0]=='Y'||userinq1[0]=='y'))
        {
            superheroes();
            flag=1;
            break;
        }
        else if((userinq1[1]=='Y'||userinq1[1]=='y'))
        {
            cricketers();
            flag=1;
            break;
        }
        else if((userinq1[2]=='Y'||userinq1[2]=='y'))
        {
            cartoon();
            flag=1;
            break;
        }
        else if((userinq1[3]=='Y'||userinq1[3]=='y'))
        {
            bollywood();
            flag=1;
            break;
        }
        else if((userinq1[4]=='Y'||userinq1[4]=='y'))
        {
            scientists();
            flag=1;
            break;
        }


    }

     if(flag==0){
            clrscreen();
    gotoxy(42,13);
            printf("Your Character Does Not Belong In The List");
            gotoxy(53,23);
        printf("WANNA PLAY AGAIN...?");
        gotoxy(60,24);
        printf("(Y/N)");
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
            {   clrscreen();
                gotoxy(46,8);
    printf("SELECT A CHARACTER IN OUR MIND");
    gotoxy(49,9);
    printf("FROM AMONG THE FOLLOWING");
    flag=0;
    dispchar();
    clrscreen();
    question1();
            }
        else
        {
            system("pause");
        }
        }
}

void win(char winner[20])
{   char ch;
    flag1=1;
    gotoxy(47,13);
        system("color 0C");
        printf("YOUR CHARACTER IS %s",winner);
        delay(500);
        int k;
        for(k=0;k<4;k++)
        {
        system("color 0A");
        delay(200);
        system("color 0D");
        delay(200);
        system("color 0B");
        delay(200);
        system("color 0E");
        delay(200);
        gotoxy(52,17);
        printf("...CONGRATULATIONS...");
        gotoxy(52,19);
        delay(500);
        printf("...CONGRATULATIONS...");
        gotoxy(52,21);
        delay(500);
        printf("...CONGRATULATIONS...");
        gotoxy(53,23);
        printf("WANNA PLAY AGAIN...?");
        gotoxy(60,24);
        printf("(Y/N)");
        }
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
            {   clrscreen();
                gotoxy(46,8);
    printf("SELECT A CHARACTER IN OUR MIND");
    gotoxy(49,9);
    printf("FROM AMONG THE FOLLOWING");
    flag1=0;
    dispchar();
    clrscreen();
    question1();
            }
        else
        {
            system("pause");
        }
}

void superheroes(){
   char ch;
FILE *ques;
ques=fopen("D:\\CS project\\Superheroes.txt","r");
FILE *answ;
answ=fopen("D:\\CS project\\superheroans.txt","r");

create(answ);
int flag=0;
int i;
    for(i=1;i<6;i++)
    {   clrscreen();
        logo(32,2);
        gotoxy(45,10);

        printf("Enter 'Y' for Yes and 'N' for No");
        gotoxy(44,13);

        if(headstart==headend)
        {
            win(headstart->name);
            break;
        }

        while(ch!=EOF){
        ch=fgetc(ques);
        if(ch=='\n')
        {
            printf("\n");
           break;
        }
        else
        printf("%c",ch);
        }
        Beep(5500,200);
        delay(200);
        gotoxy(60,17);
        scanf("%c",&ch);
        Beep(6500,200);
        delete(i,ch);
        fflush(stdin);
    }
    if(flag1==0)
    {
        clrscreen();
    gotoxy(42,13);
            printf("Your Character Does Not Belong In The List");
            gotoxy(53,23);
        printf("WANNA PLAY AGAIN...?");
        gotoxy(60,24);
        printf("(Y/N)");
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
            {   clrscreen();
                gotoxy(46,8);
    printf("SELECT A CHARACTER IN OUR MIND");
    gotoxy(49,9);
    printf("FROM AMONG THE FOLLOWING");
    flag=0;
    dispchar();
    clrscreen();
    question1();
    }}

}

void cricketers(){
char ch;
FILE *ques;
ques=fopen("D:\\CS project\\cricketersques.txt","r");
FILE *answ;
answ=fopen("D:\\CS project\\cricketersans.txt","r");

create(answ);
int flag=0;
int i;
    for(i=1;i<7;i++)
    {   clrscreen();
        logo(32,2);
        gotoxy(45,10);

        printf("Enter 'Y' for Yes and 'N' for No");
        gotoxy(44,13);

        if(headstart==headend)
        {
            win(headstart->name);
            break;
        }

        while(ch!=EOF){
        ch=fgetc(ques);
        if(ch=='\n')
        {
            printf("\n");
           break;
        }
        else
        printf("%c",ch);
        }
        Beep(5500,200);
        delay(200);
        gotoxy(60,17);
        scanf("%c",&ch);
        Beep(6500,200);
        delete(i,ch);
        fflush(stdin);
    }
    if(flag1==0)
    {
        clrscreen();
    gotoxy(42,13);
            printf("Your Character Does Not Belong In The List");
            gotoxy(53,23);
        printf("WANNA PLAY AGAIN...?");
        gotoxy(60,24);
        printf("(Y/N)");
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
            {   clrscreen();
                gotoxy(46,8);
    printf("SELECT A CHARACTER IN OUR MIND");
    gotoxy(49,9);
    printf("FROM AMONG THE FOLLOWING");
    flag=0;
    dispchar();
    clrscreen();
    question1();
    }}


}

void cartoon(){

char ch;
FILE *ques;
ques=fopen("D:\\CS project\\cartoonques.txt","r");
FILE *answ;
answ=fopen("D:\\CS project\\cartoonans.txt","r");

create(answ);
int flag=0;
int i;
    for(i=1;i<11;i++)
    {   clrscreen();
        logo(32,2);
        gotoxy(45,10);

        printf("Enter 'Y' for Yes and 'N' for No");
        gotoxy(37,13);

        if(headstart==headend)
        {
            win(headstart->name);
            break;
        }
        while(ch!=EOF){
        ch=fgetc(ques);
        if(ch=='\n')
        {
            printf("\n");
           break;
        }
        else
        printf("%c",ch);
        }
        Beep(5500,200);
        delay(200);
        gotoxy(60,17);
        scanf("%c",&ch);
        Beep(6500,200);
        delete(i,ch);
        fflush(stdin);
    }
    if(flag1==0)
    {
        clrscreen();
    gotoxy(42,13);
            printf("Your Character Does Not Belong In The List");
            gotoxy(53,23);
        printf("WANNA PLAY AGAIN...?");
        gotoxy(60,24);
        printf("(Y/N)");
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
            {   clrscreen();
                gotoxy(46,8);
    printf("SELECT A CHARACTER IN OUR MIND");
    gotoxy(49,9);
    printf("FROM AMONG THE FOLLOWING");
    flag=0;
    dispchar();
    clrscreen();
    question1();
    }}
}

void bollywood(){
   char ch;
FILE *ques;
ques=fopen("D:\\CS project\\actorques.txt","r");
FILE *answ;
answ=fopen("D:\\CS project\\actorans.txt","r");

create(answ);
int flag=0;
int i;
    for(i=1;i<=6;i++)
    {   clrscreen();
        logo(32,2);
        gotoxy(45,10);

        printf("Enter 'Y' for Yes and 'N' for No");
        gotoxy(32,13);

        if(headstart==headend)
        {
            win(headstart->name);
            break;
        }

        while(ch!=EOF){
        ch=fgetc(ques);
        if(ch=='\n')
        {
            printf("\n");
           break;
        }
        else
        printf("%c",ch);
        }
        Beep(5500,200);
        delay(200);
        gotoxy(60,17);
        scanf("%c",&ch);
        Beep(6500,200);
        delete(i,ch);
        fflush(stdin);
    }
    if(flag1==0)
    {
        clrscreen();
    gotoxy(42,13);
            printf("Your Character Does Not Belong In The List");
            gotoxy(53,23);
        printf("WANNA PLAY AGAIN...?");
        gotoxy(60,24);
        printf("(Y/N)");
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
            {   clrscreen();
                gotoxy(46,8);
    printf("SELECT A CHARACTER IN OUR MIND");
    gotoxy(49,9);
    printf("FROM AMONG THE FOLLOWING");
    flag=0;
    dispchar();
    clrscreen();
    question1();
    }}

}

void scientists(){
printf("scientists");}

void dispchar(){
    int n=100;
gotoxy(5,3);
Beep(200,200);
printf("WONDER WOMAN");
delay(n);

gotoxy(17,23);
Beep(200,200);
printf("BATMAN");
delay(n);

gotoxy(80,19);
Beep(200,200);
printf("TIGER SHROFF");
delay(n);

gotoxy(56,23);
Beep(200,200);
printf("CHRIS GAYLE");
delay(n);

gotoxy(89,10);
Beep(200,200);
printf("EMMA WATSON");
delay(n);

gotoxy(80,24);
Beep(200,200);
printf("SUPERMAN");
delay(n);

system("color 0D");

gotoxy(24,8);
Beep(200,200);
printf("TOM CRUISE");
delay(n);

gotoxy(30,3);
Beep(200,200);
printf("DORAEMON");
delay(n);

gotoxy(90,15);
Beep(200,200);
printf("CAPTIAN AMERICA");
delay(n);

gotoxy(14,25);
Beep(200,200);
printf("DANIEL RADCLIFFE");
delay(n);

gotoxy(15,12);
Beep(200,200);
printf("SACHIN TENDULKAR");
delay(n);

gotoxy(100,6);
Beep(200,200);
printf("IRONMAN");
delay(n);

system("color 0B");

gotoxy(93,23);
Beep(200,200);
printf("OSWALD");
delay(n);

gotoxy(50,15);
Beep(200,200);
printf("M.S. DHONI");
delay(n);

gotoxy(52,17);
Beep(200,200);
printf("SHINCHAN");
delay(n);

gotoxy(34,26);
Beep(200,200);
printf("NODDY");
delay(n);

gotoxy(75,26);
Beep(200,200);
printf("A.B.D. VILLIERS");
delay(n);

gotoxy(6,16);
Beep(200,200);
printf("RANVEER SINGH");
delay(n);

gotoxy(77,14);
Beep(200,200);
printf("CHHOTA BHEEM");
delay(n);

gotoxy(47,3);
Beep(200,200);
printf("AKSHAY KUMAR");
delay(n);

gotoxy(87,21);
Beep(200,200);
printf("HARBHAJAN SINGH");
delay(n);

system("color 0E");

gotoxy(64,18);
Beep(200,200);
printf("JERRY");
delay(n);

gotoxy(32,17);
Beep(200,200);
printf("DEEPIKA PADUKONE");
delay(n);

gotoxy(35,21);
Beep(200,200);
printf("VIRAT KOHLI");
delay(n);

gotoxy(76,4);
Beep(200,200);
printf("THOR");
delay(n);

gotoxy(100,4);
Beep(200,200);
printf("SHANE WATSON");
delay(n);

gotoxy(25,19);
Beep(200,200);
printf("KITERETSU");
delay(n);

gotoxy(80,12);
Beep(200,200);
printf("SPIDERMAN");
delay(n);

system("color 0C");
gotoxy(48,11);
Beep(200,200);Beep(200,200);
printf("PRESS ENTER WHEN SELECTED:");

scanf("%c",&ctemp);
system("color 0A");
fflush(stdin);
delay(200);


}


void UI(){

    system("color 0A");
    drawbox(1,0,117,29,5);
    system("color 0C");
    delay(90);
    system("color 0A");
    delay(90);
    logo(32,4);
    PlaySound(TEXT("D:\\CS project\\PTT-20180730-WA0017 (1).wav"),NULL,SND_SYNC);
    system("color 0C");
    delay(90);
    drawbox(30,3,87,11,5);
    drawbox(28,2,89,12,5);
    system("color 0C");
    delay(90);
    system("color 0A");
    delay(90);
    system("color 0C");
    delay(90);
    system("color 0D");
    delay(90);
    gotoxy(48,20);
    printf("PRESS ENTER TO CONTINUE");
    scanf("%c",&ctemp);
    delay(500);
    clrscreen();
    /*delay(500);
    credits();
    delay(500);
    clrscreen();*/

}
COORD coord;
void clrscreen()
{
    system("cls");
    drawbox(1,0,117,29,0);
}

void credits()
{
    gotoxy(50,6);
    printf("PRESENTED TO YOU BY:-");
    delay(200);
    gotoxy(44,8);
    Beep(5500,200);
    printf("* Chitrank Mishra    (17103103)");
    delay(200);
    gotoxy(44,9);
    Beep(5500,200);
    printf("* Atharva Tripathi   (17103127)");
    delay(200);
    gotoxy(44,10);
    Beep(5500,200);
    printf("* Naman Vyas         (17103132)");
    delay(200);
    gotoxy(44,11);
    Beep(5500,200);
    printf("* Shivanshi Arora    (17103116)");
    delay(200);
    system("color 0C");
    delay(300);
    system("color 0A");
    delay(300);
    scanf("%c",&ctemp);
}

void delay(unsigned int ms)
{
    clock_t goal=ms+clock();
    while(goal>clock());
}

void gotoxy(int x,int y)
{
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void logo(int x, int y)
{
    gotoxy(x,y);
    printf("   ___         ___      ____            __  __   ____");
    gotoxy(x,y+1);
    printf(" //   \\\\     //   \\\\  ||      ||\\\    ||   ||   ||    ");
    gotoxy(x,y+2);
    printf(" ||         ||        ||      || \\\   ||   ||   ||    ");
    gotoxy(x,y+3);
    printf(" ||     --- ||   __   ||===   ||  \\\  ||   ||   ||=== ");
    gotoxy(x,y+4);
    printf(" ||         ||    ||  ||      ||   \\\ ||   ||   ||    ");
    gotoxy(x,y+5);
    printf(" \\\\___//     \\\\___//  ||____  ||    \\\|| __||__ ||____");
    }

void drawbox(int x1, int y1, int x2, int y2, int d)
{
    gotoxy(x1,y1);
    printf("+");
    delay(d);
    gotoxy(x2,y2);
    printf("+");
    delay(d);
    int i;
    for(i=1;i<x2-x1;i++)
    {   gotoxy(x1+i,y1);
        printf("-");
        printf("\a");
        delay(d);
        gotoxy(x2-i,y2);
        printf("-");
        delay(d);
    }
    gotoxy(x1,y2);
    printf("+");
    gotoxy(x2,y1);
    printf("+");
    int j;
    for(j=1;j<y2-y1;j++)
        {
            gotoxy(x2,y1+j);
            printf("|");
            delay(d);
            gotoxy(x1,y2-j);
            printf("|");
            delay(d);
        }
}
void main()
{

    UI();
    gotoxy(46,8);
    printf("SELECT A CHARACTER IN OUR MIND");
    gotoxy(49,9);
    printf("FROM AMONG THE FOLLOWING");
    dispchar();
    clrscreen();
    flag1=0;
    question1();
}
