#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<time.h>




void initgraphic()
{
int gd=DETECT ,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
}




struct tree
{
    int user;
    char pass[20];
    struct tree *left;
    struct tree *right;
};

struct link
{
    char ename[70];
    char date[10];
    struct link *next;
};


int calendar(int m, int y);
struct tree* new_node(int data ,char p[] );
struct tree* add(struct tree *root, int val,char p[]);
void check(struct tree *root,int u);

void add_e();
struct link* create_e();
int display_e(int );



struct link *head;

int main()
{
	    int i,j,m,y,d,user,u,val,eve;
	    char week[7][10],day[4],pass[10],month_name[12][10],current[50];
	    struct tree *main=NULL,*t;
	    time_t today;
	    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	    FILE *fp;
	    clrscr();
	    putenv("TZ=IST");
	    tzset();
	    time(&today);
	  //  printf("%s", asctime(localtime(&today)));
	    //  strcpy(asctime(localtime(&today)));
	    getch();
	    strcpy(week[0], "SUN"  );
	    strcpy(week[1], "MON"  );
	    strcpy(week[2], "TUE"  );
	    strcpy(week[3], "WED"  );
	    strcpy(week[4], "THU"  );
	    strcpy(week[5], "FRI"  );
	    strcpy(week[6], "SAT"  );

	    strcpy(month_name[0],"JANUARY"   );
	    strcpy(month_name[1],"FEBRUARY"  );
	    strcpy(month_name[2],"MARCH"     );
	    strcpy(month_name[3],"APRIL"     );
	    strcpy(month_name[4],"MAY"       );
	    strcpy(month_name[5],"JUNE"      );
	    strcpy(month_name[6],"JULY"      );
	    strcpy(month_name[7],"AUGUST"    );
	    strcpy(month_name[8],"SEPTEMBER" );
	    strcpy(month_name[9],"OCTOBER"   );
	    strcpy(month_name[10],"NOVEMBER" );
	    strcpy(month_name[11],"DECEMBER" );



	   fp=fopen("username.txt","r");


	     while(fscanf(fp,"%d%s",&user,pass)!=EOF)
	   {

	       if (main==NULL)
		{
		   t = main = new_node(user,pass);
		}
	       else
		{
		   add(main, user,pass);
		}

	      fscanf(fp,"%d%s",&user,pass);
	  }



	    printf("\n\n\n");

	    printf("ENTER YOUR USERNAME: ");
	    scanf("%d",&u);
	    check(main,u);



	    printf("ENTER THE DATE IN MM-YYYY FORMAT: \n");
	    scanf("%d-%d",&m,&y);
	    clrscr();

	    initgraphic();

	    temp:
	    if((y%100!=0&&y%4==0)||y%400!=0)
	    month[1]=29;

	    fflush(stdin);
	    cleardevice();
	     d=1;
	    settextstyle(3,0,8);
	    setcolor(YELLOW);
	    outtextxy(100,5,"CALENDAR");
	    settextstyle(1,0,4);
	    setcolor(CYAN);
	    outtextxy(95,165,month_name[m-1]);
	    settextstyle(1,1,4);
	    setcolor(LIGHTRED);
	    itoa(y,day,10);
	    outtextxy(18,190,day);
	    settextstyle(1,0,1);
	    setcolor(WHITE);
	    outtextxy(310,178,asctime(localtime(&today)));
	    outtextxy(79,190,"--------------------------------------------");
	    setcolor(RED);
		outtextxy(80, 200, week[0]);
		setcolor(GREEN);
	    for (i=0; i<6; i++)
	    {
		outtextxy(160 + (80*i), 200, week[i+1]);
		}
	    setcolor(WHITE);
	    outtextxy(79,210 ,"--------------------------------------------");
	    for (i=0; i<=6; i++)
	    {
		  if (i!=0)
		  { j = 0;}
		  else
		  { j = calendar(m, y);}

			for (; j<7; j++)
		  {       if((y%100!=0&&y%4==0)||y%400==0)
			  month[1]=29;
				if(d>month[m-1])
				   {
				       break;
			     }
			itoa(d,day,10);
				outtextxy( 80*(j+1), 230+(20*i), day);
			d++;

		      }
	   }


	    settextstyle(2,0,6);
	    setcolor(WHITE);
	    outtextxy(80,355,"ENTER:-");
	    outtextxy(80,370,"0 FOR EXIT !");
	    outtextxy(80,385,"1 FOR PREVIOUS MONTH !");
	    outtextxy(80,400,"2 FOR NEXT MONTH !");
	    outtextxy(80,415,"3 TO SEE EVENTS !");
	    outtextxy(80,430,"4 TO ADD EVENTS !");
	    outtextxy(80,445,"5 TO DELETE EVENTS !");
	    outtextxy(80,460,"6 TO GO TO A MONTH !");
	    outtextxy(320,370,"7 TO GO TO PREVIOUS YEAR !" );
	    outtextxy(320,385,"8 TO GO TO NEXT YEAR !");

	  //gotoxy(120,389);
	    scanf("%s",day);
	    val=atoi(day);
	    switch(val)
	    {
	      case 0:
		cleardevice();
		settextstyle(1,0,3);
		setcolor(LIGHTGREEN);
		outtextxy(100,5,"SOFTWARE DEVELOPMENT FUNDAMENTAL- II");
		delay(3000);
		settextstyle(1,0,3);
		setcolor(LIGHTRED);
		outtextxy(150,150,"--AJAY KUMAR KUSHWAHA");
		outtextxy(180,170,"16104013");
		delay(3000);
		exit(0);
		break;
	      case 1:
		cleardevice();
		if(m==1)
		  {
		    m=12;
		    y--;
		  }
		else
		  m=m-1;
		goto temp;
		break;
	      case 2:
		cleardevice();
		if(m==12)
		  {
		    m=1;
		    y=y+1;
		  }
		else
		  m=m++;
		goto temp;
		break;
	      case 3:
		  cleardevice();
		  display_e(m);
		  goto temp;
		 break;
	      case 4:
		cleardevice();
		add_e();
		goto temp;
		break;
	  //    case 5:
	    //	cleardevice();
	      //delete_event();
	      //break;
	      case 6:
		cleardevice();
		printf("ENTER DATE IN MM-YYYY FORMAT "  );
		scanf("%d-%d",&m,&y);
		goto temp;
		break;
	      case 7:
		cleardevice();
		y--;
		goto temp;
		break;
	      case 8:
		cleardevice();
		y++;
		goto temp;
		break;
	      default:
		goto temp;
	   }




	      getch();
	    closegraph();


	      getch();

}


struct link * create_e()
{
   struct link *node;
   char string[70],std[10];
   cleardevice();
   node=(struct link *)malloc(sizeof(struct link));
   printf("ENTER EVENT NAME: " );
   scanf("%s",string);
   strcpy(node->ename,string);
   fflush(stdin);
   printf("EVENT MONTH: ");
   scanf("%s",std);
   strcpy(node->date,std);
   node->next=NULL;
   return node;

}

//FUNCTION USED TO ADD AN EVENT IN A PARTICULAR MONTH
void add_e()
{

   FILE *fp;
   int mn,dt;
   char eve[100];
   fp=fopen("events.txt","a");
   printf("ENTER EVENT DATE IN  MM-DD: - " );
   scanf("%d%d",&mn,&dt);
   printf("ENTER EVENT NAME:- ");
   scanf("%s",eve);
   fprintf(fp,"\n%d %d %s",mn,dt,eve);
   fclose(fp);

}




   /*
   struct link* n,*tmp,*t;
   cleardevice();
   if(head==NULL)
   {
     head=create_e();
   }
   else
   {
	n=create_e();
	tmp=head;
	while(tmp!=NULL)
	{
	   t=tmp;
	   tmp=tmp->next;
	}
	tmp=n;
	t->next=tmp;
   }
   tmp=head;
*/




// FUNCTION USED TO DISPLAY THE EVENTS IN A MONTH
int display_e(int m)
{
	  FILE *fp,*fa;
	  int mn,dt,f=1, x= 80, y=60;
	  char ev[100], line[120];
	  fp=fopen("events.txt","r");
	  settextstyle(1,0,4);
	  setcolor(GREEN);
	  outtextxy(80,20,"EVENTS:-");
	  settextstyle(2,0,8);
	  setcolor(WHITE);
	  while(!feof(fp))
	  {
	       fscanf(fp,"%d%d%s",&mn,&dt,ev);
	       if(mn==m)
	       {
		  itoa(dt, line, 10);
		  strcat(line, " ");
		  strcat(line, ev);
		  outtextxy(x,y , line);
		  y+=20;
		  f=0;
	       }
	  }

	  if(f!=0)
	  {
	     outtextxy(x, y, "OOPs! NO EVENTS THIS MONTH !" );
	  }
	 getch();

	 fclose(fp);
	 return 0;

}

       /*
       struct link *tmp;
       int f=0;
       printf("GOING");
       tmp=head;
       while(tmp!=NULL)
       {
	   if(strcmp(m,tmp->date)==0)
	     {
		  printf("%s",tmp->ename);
		  f=1;
	     }
	   tmp=tmp->next;
       }
       if(f!=1)
       {
	    printf("NO EVENTS THIS MONTH: ");
       }
	 */



//FUNCTION TO RETURN THE DAY NO. OF A MONTH DATE
int calendar(int m, int y)
{
		int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
		char week[7][10];
		int flag,i,s;
		s=0;
		flag=0;
		strcpy(week[0],"SUNDAY"   );
		strcpy(week[1],"MONDAY"   );
		strcpy(week[2],"TUESDAY"  );
		strcpy(week[3],"WEDNESDAY");
		strcpy(week[4],"THURSDAY" );
		strcpy(week[5],"FRIDAY"   );
		strcpy(week[6],"SATURDAY" );



		if((y%100!=0&&y%4==0)||(y%400==0))
		{
		   flag=1;
		   month[1]=29;
		}

		for(i=0;i<m-1;i++)
		{
		   s=s+month[i];
		   s=s+(1+y+(y/4)-2);
		   s=s%7;
		}

	    if(flag==1)
	    {
		s=s-1;
	    }

	    return s;
}


//FUNCTION TO CREATE BINARY SEARCH TREE USING USERNAME
struct tree* new_node(int data,char p[])
{
    struct tree` * t;
    t = (struct tree*) malloc(sizeof(struct tree));
    t->user = data;
    strcpy(t->pass,p);
    t->left = t->right = NULL;
    return t;
}


struct tree* add(struct tree *root, int val,char p[])
{
    if (!root)
    {
	root = new_node(val,p);
	return root;
    }
    if (root->user>val)
    {
	root->left = add(root->left, val,p);
    }
    else
    {
	root->right = add(root->right, val,p);
    }
    return root;

}

//FUNCTION USED TO CHECK WETHER THE USERNAME AND PASSWORD ARE CORRECT
void check(struct tree *root,int u)
{
    char s[10];
    fflush(stdin);
    if(root!=NULL)
    {   if(u==root->user)
	 {
	   printf("ENTER YOUR PASSWORD: ");
	   scanf("%s",s);

	   if(strcmp(s,root->pass)==0)
		    printf("WELCOME!!\n\n");
	   else
	      {
		printf("WRONG PASSWORD!\n\n");
		delay(2000);
		exit(0);
	      }
	 }

	else if( u>root->user)
	{
	  check(root->right,u);
	}
	else
	{
	  check(root->left,u);
	}
    }
    else
       {
	printf("INVALID USERNAME!\n\n " );
	delay(2000);
	exit(0);

       }
}




