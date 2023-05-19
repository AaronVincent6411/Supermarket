#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
#include<stdlib.h>
 class Supermarket
  {
    public:
     char name[10];
     char password[10];
   };
 class Intro
  {
   public:
    void welcome();
  };
 class C_user
  {
    protected:
     int pno;
     char pname[50];
     float price;
     char name[10];
     char Gender;
     int Age;
     char City_name[15];
  };
 class User
  {
   protected:
    char name[10];
    char Gender;
    int Age;
    char City_name[15];
   public:
    void User_Create_Details();
    void User_Show_Details();
    char* getname()
     {
      return name;
     }
    char* getcity()
     {
      return City_name;
     }
    char getgender()
     {
      return Gender;
     }
    int getage()
     {
      return Age;
     }
  };
  void User::User_Create_Details()
     {
      clrscr();
      settextstyle(2,0,4);
      outtextxy(100,100,"Enter the Customer Name");
      gets(name);
      clrscr();
      outtextxy(100,100,"Enter the Gender");
      cin>>Gender;
      clrscr();
      outtextxy(100,100,"Enter the Age");
      cin>>Age;
      clrscr();
      outtextxy(100,100,"Enter the Home Place");
      gets(City_name);
      clrscr();
     }
  void User::User_Show_Details()
     {
      clrscr();
      setcolor(6);
      cout<<"Customer's Name  ="<<name<<endl;
      cout<<"Customer's Gender="<<Gender<<endl;
      cout<<"Customer's Age   ="<<Age<<endl;
      cout<<"Customer's City  ="<<City_name<<endl;
     }
 fstream fp2;
 User u;
 void User_Insert_Details()
  {
    char ch;
    fp2.open("Customer.dat",ios::out);
    setcolor(4);
    outtextxy(100,100,"Enter The Details Of The Customer");
    do
     {
       u.User_Create_Details();
       fp2.write((char*)&u,sizeof(User));
       cout<<"Do You Wish To Move Forward \nPress Any Alphabet"<<endl;
       cin>>ch;
     }while(!isalpha(ch));
    fp2.close();
    getch();
   }
 void User_Display_Details()
  {
    int f=0;
    fp2.open("Customer.dat",ios::in);
    clrscr();
    if(!fp2)
      {
       setcolor(6);
       outtextxy(200,100,"Error File Coud Not Be Opened");
       getch();
     }
     cleardevice();
     setcolor(4);
     outtextxy(100,100,"Customer List");
     setcolor(2);
     settextstyle(3,0,2);
     outtextxy(0,130,"CUSTOMER NAME   CITY NAME    GENDER     AGE");
     setcolor(7);
     while(fp2.read((char*)&u,sizeof(User)))
      {
	 gotoxy(1,15+f);
	 cout<<u.getname();
	 gotoxy(9,15+f);
	 puts(u.getcity());
	 gotoxy(26,15+f);
	 cout<<u.getgender();
	 gotoxy(35,15+f);
	 cout<<u.getage();
	 f++;
      }
    fp2.close();
    getch();
  }
 void Delete_User_Details()
  {
    char no[10];
    clrscr();
    setcolor(8);
    settextstyle(8,0,4);
    outtextxy(200,100,"Delete Record");
    setcolor(4);
    outtextxy(30,150,"Please Enter the Customer Name You Want to Delete");
    gets(no);
    fp2.open("Customer.dat",ios::binary|ios::in);
    fstream fp3("Temp.dat",ios::out);
    while(fp2.read((char*)&u,sizeof(User)))
     {
      if(strcmpi(u.getname(),no)!=0)
       {
	fp3.write((char*)&u,sizeof(User));
       }
      }
     fp3.close();
     fp2.close();
     remove("Customer.dat");
     rename("Temp.dat","Customer.dat");
     outtextxy(200,200,"Record Deleted");
     getch();
  }
 void Delete_all()
  {
    clrscr();
    char okay[5];
    setcolor(3);
    outtextxy(200,100,"Delete All Record!!!");
    setcolor(2);
    outtextxy(30,150,"Enter ('okay'/'OKAY')");
    setcolor(1);
    outtextxy(60,180," If You Want to Delete All Record");
    gets(okay);
    if(strcmpi(okay,"okay")==0)
     {
      fp2.open("User.dat",ios::binary|ios::in);
      fstream fp3("Temp.dat",ios::out);
      fp3.close();
      fp2.close();
      remove("Customer.dat");
      rename("Temp.dat","Customer.dat");
      outtextxy(200,200,"Record Deleted");
      getch();
    }
  }
 class product
  {
    protected:
     int pno;
     char pname[50];
     float price;
    public:
     void create_product()
	{
	  cleardevice();
	  setcolor(7);
	  settextstyle(6,0,4);
	  outtextxy(250,100,"Enter the Product no");
	  cin>>pno;
	  cleardevice();
	  settextstyle(6,0,4);
	  outtextxy(250,100,"Enter the Product name");
	  gets(pname);
	  cleardevice();
	  settextstyle(6,0,4);
	  outtextxy(250,100,"Enter the Price of the Product");
	  cin>>price;
	}
     void show_product()
	{
	   cleardevice();
	   setcolor(4);
	   cout<<"The Product No   ="<<pno<<endl;
	   cout<<"The Product Name ="<<pname<<endl;
	   cout<<"The Product Price="<<price<<endl;
	}
     int retpno()
	{
	 return pno;
	}
     float retprice()
	{
	 return price;
	}
     char* retname()
	{
	 return pname;
	}
      };
  fstream fp;
  product pr;
  void write_product()
   {
    int n;
    char cr;
    clrscr();
    settextstyle(5,0,5);
    setcolor(0);
    outtextxy(100,100,"Do You Wish To Continue");
    outtextxy(100,150,"Press Any Alphabet Except (n/N)");
    setcolor(4);
    settextstyle(3,0,2);
    outtextxy(150,200,"Warning:-Existing Data Will Be Erased");
    outtextxy(150,250,"To Avoid It Press (n/N)");
    cin>>cr;
    if(cr=='n'||cr=='N')
     {
      clrscr();
      outtextxy(100,100,"Existing Data Is Safe");
     }
    else
     {
      clrscr();
      fp.open("Supermarket.dat",ios::out);
      setcolor(2);
      outtextxy(0,100,"Enter the No of Products You Like To Insert");
      cin>>n;
      for(int i=0;i<n;i++)
       {
	pr.create_product();
	fp.write((char*)&pr,sizeof(pr));
       }
      fp.close();
      cleardevice();
      settextstyle(3,0,5);
      setcolor(7);
      outtextxy(0,100,"The Products have been created");
      getch();
     }
   }
  void display_all()
   {
    cleardevice();
    for(int i=0;i<8;i++)
     {
      setcolor(i);
      outtextxy(250,100,"Displaying all the record");
     }
    fp.open("Supermarket.dat",ios::binary|ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
     {
      pr.show_product();
      getch();
     }
    fp.close();
    getch();
   }
  void display_sp(int n)
   {
    int flag=0;
    fp.open("Supermarket.dat",ios::binary|ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
     {
      if(pr.retpno()==n)
       {
	cleardevice();
	pr.show_product();
	flag=1;
       }
      }
    fp.close();
    if(!flag)
     outtextxy(250,100,"Record does not exist");
     getch();
    }
  void modify_product()
   {
    int no,found=0;
    cleardevice();
    outtextxy(250,100,"To moldify");
    outtextxy(250,150,"Please Enter the Product No");
    cin>>no;
    fp.open("Supermarket.dat",ios::binary|ios::in);
    while(fp.read((char*)&pr,sizeof(pr)))
     {
      if(pr.retpno()==no)
       {
	clrscr();
	pr.show_product();
	outtextxy(250,200,"Please Enter the new Details of the Product");
	pr.create_product();
	int pos=-1*sizeof(pr);
	fp.seekp(pos,ios::cur);
	fp.write((char*)&pr,sizeof(product));
	outtextxy(250,250,"Record Updated");
	found=1;
       }
      }
     if(!found)
      outtextxy(250,100,"Record not found");
      getch();
     }
  void append_product()
   {
    char ch;
    clrscr();
    fp.open("Supermarket.dat",ios::app|ios::in);
    fstream fp3("Temp.dat",ios::out);
    do
     {
      cout<<"Enter the Record to be Appended"<<endl;
      pr.create_product();
      int pos=-1*sizeof(pr);
      fp.seekp(pos,ios::end);
      fp.write((char*)&pr,sizeof(product));
      cout<<"Do You Wish To Continue \nPress (y/Y) To Continue"<<endl;
      cin>>ch;
     }while(ch=='y'||ch=='Y');
    fp.close();
    cleardevice();
    settextstyle(2,0,5);
    outtextxy(100,100,"Product Appended");
    getch();
   }
  void delete_product()
   {
    int no;
    clrscr();
    settextstyle(8,0,4);
    outtextxy(200,100,"Delete Record");
    outtextxy(0,150,"Please Enter the Product No You Want to Delete");
    cin>>no;
    fp.open("Supermarket.dat",ios::binary|ios::in);
    fstream fp2("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&pr,sizeof(product)))
     {
      if(pr.retpno()!=no)
       {
	fp2.write((char*)&pr,sizeof(product));
       }
      }
     fp2.close();
     fp.close();
     remove("Supermarket.dat");
     rename("Temp.dat","Supermarket.dat");
     outtextxy(200,200,"Record Deleted");
     getch();
    }
   void menu()
    {
     cleardevice();
     int e=0;
     fp.open("Supermarket.dat",ios::binary|ios::in);
     if(!fp)
      {
       outtextxy(200,100,"Error File Coud Not Be Opened");
       getch();
     }
     cleardevice();
     settextstyle(5,0,3);
     outtextxy(100,120,"Product Menu");
     outtextxy(50,140,"P.NO    NAME    TPRICE");
     for(int j=0;j<35;j++)
     cout<<endl;
     while(fp.read((char*)&pr,sizeof(product)))
      {
       gotoxy(1,7+e);
       cout<<pr.retpno();
       gotoxy(9,7+e);
       cout<<pr.retname();
       gotoxy(30,7+e);
       cout<<pr.retprice();
       e++;
      }
    fp.close();
   }
 void place_order()
   {
     cleardevice();
     int item;
     int order_arr[10],quan[10];
     float amt,total=0;
     int c=0;
     char ch;
     menu();
     cout<<"\n\nHow Many Items"<<endl;
     cin>>item;
     cout<<"Place your Order"<<endl;
     for( ;c<item;c++)
      {
       cout<<"Enter the Product no"<<endl;
       cin>>order_arr[c];
       cout<<"Quantity"<<endl;
       cin>>quan[c];
      }
     cout<<"Do You Want To Order Another Product \nPress (y/Y)"<<endl;
     cin>>ch;
     if(ch=='y'||ch=='Y')
      {
	do
	 {
	   cout<<"Enter the Product no"<<endl;
	   cin>>order_arr[c];
	   cout<<"Quantity"<<endl;
	   cin>>quan[c];
	   cout<<"Do You Want To Order Another Product \nPress (y/Y)"<<endl;
	   cin>>ch;
	   ++c;
       }while(ch=='y'||ch=='Y');
    }
    clrscr();
    setcolor(4);
    outtextxy(0,50,"Thank You For Placing the Order");
    User_Display_Details();
    clrscr();
    setbkcolor(2);
    cout<<"Product No     Product Name      Quantity      Price"<<endl;
    for(int x=0;x<c;x++)
     {
      fp.open("Supermarket.dat",ios::in);
      while(fp.read((char*)&pr,sizeof(product)))
       {
	if(pr.retpno()==order_arr[x])
	 {
	  gotoxy(1,6+x);
	  cout<<pr.retpno()<<"\t";
	  gotoxy(10,6+x);
	  cout<<pr.retname()<<"\t";
	  gotoxy(40,6+x);
	  cout<<quan[x]<<"\t";
	  gotoxy(50,6+x);
	  cout<<pr.retprice()<<"\t";
	  gotoxy(60,6+x);
	  amt=pr.retprice()*quan[x];
	  cout<<amt<<"\t";
	  total+=amt;
	}
      }
     fp.close();
    }
  cout<<"\n\tTotal="<<total<<endl;
  getch();
 }
 char name[10];
 char password[10];
 void admin_expansion()
  {
    int ch2;
    char ch3;
    cleardevice();
    settextstyle(5,0,7);
    outtextxy(100,20,"Hello Administrator");
     do
      {
       settextstyle(2,0,5);
       outtextxy(100,120,"Admin Menu");
       outtextxy(50,140,"1.Create Product");
       outtextxy(50,160,"2.Display Products");
       outtextxy(50,180,"3.Query");
       outtextxy(50,200,"4.Modify Product");
       outtextxy(50,220,"5.Delete Product");
       outtextxy(50,240,"6.Append Product");
       outtextxy(50,260,"7.View Product Menu");
       outtextxy(50,280,"8.Back To Main Menu");
       outtextxy(50,300,"9.Show the Name Of the Customers Who Placed Order");
       outtextxy(50,320,"Please Enter Your Choice");
       cin>>ch2;
       clrscr();
       switch(ch2)
	{
	 case 1:write_product();
		break;
	 case 2:display_all();
		break;
	 case 3:int num;
		cleardevice();
		cout<<"Please Enter the Product No"<<endl;
		cin>>num;
		display_sp(num);
		break;
	 case 4:setbkcolor(BLACK);
		setcolor(RED);
		modify_product();
		break;
	 case 5:delete_product();
		break;
	 case 6:setbkcolor(BLACK);
		setcolor(RED);
		append_product();
		break;
	 case 7:setcolor(2);
		menu();
		getch();
		setcolor(7);
	 case 8:break;
	 case 9:clrscr();
		int op;
		setbkcolor(WHITE);
		setcolor(BLACK);
		settextstyle(5,0,4);
		outtextxy(50,100,"Enter the option");
		outtextxy(100,130,"1.View Customer List");
		outtextxy(100,160,"2.Delete Customer Details");
		outtextxy(100,190,"3.Delete All Customer Details");
		cin>>op;
		if(op==1)
		 User_Display_Details();
		else if(op==2)
		 Delete_User_Details();
		else if(op==3)
		 Delete_all();
		else
		 {
		  clrscr();
		  cout<<"Wrong option"<<endl;
		 }
		 break;
	 default:cout<<"\a";
	}
	clrscr();
	settextstyle(1,0,5);
	setcolor(BLACK);
	outtextxy(100,100,"Do You Wish To Continue");
	outtextxy(100,150,"Press (Y/y) for 'Yes'");
	settextstyle(3,0,2);
	outtextxy(150,200,"Note: Pressing Any Other Characters Indicates No");
	cin>>ch3;
	clrscr();
       }while(ch3=='y'||ch3=='Y');
       clrscr();
       settextstyle(6,0,7);
       outtextxy(50,100,"You Are Out Of Admin Menu");
       delay(800);
       clrscr();
     }
 void admin_menu()
  {
   cleardevice();
   setbkcolor(RED);
   setcolor(7);
   settextstyle(6,0,5);
   outtextxy(100,100,"Enter your Name");
   for(int l=0;l<15;l++)
   cout<<endl;
   gets(name);
   if((strcmpi(name,"Aaron"))==0||(strcmpi(name,"sooraj"))==0)
    {
     for(int i=0;i<2;i++)
      {
       delay(100);
       settextstyle(5,0,5);
       setcolor(7);
       outtextxy(100,250,"Enter  your password");
       gets(password);
	if(strcmpi(password,"1a2b3c4d")==0)
	 {
	  admin_expansion();
	  break;
	 }
	else
	{
	  cleardevice();
	  settextstyle(4,0,4);
	  outtextxy(100,250,"Wrong PASSWORD");
	}
	if(i<1)
	{
	 cleardevice();
	 settextstyle(7,0,2);
	 outtextxy(150,200,"RETRY");
	}
	else
	 outtextxy(100,200,"Sorry");
       }
     }
  }
 void Intro::welcome()
  {
     int g=getmaxx()/2;
     int h=getmaxy()/2;
     settextstyle(6,0,8);
     setbkcolor(BLACK);
     outtextxy(250,100,"Loading.");
     for(int j=20;j<25;j++)
      {
       setcolor(j/5);
       int count=5;
       while(count--)
	{
	 sound(10*random(100));
	 delay(75);
	 nosound();
	}
       for(int k=0;k<360;k++)
	{
	 delay(1);
	 arc(g,h,0,k,j-10);
	}
      }
     delay(800);
     cleardevice();
     settextstyle(6,0,8);
     outtextxy(250,100,"Loading..");
     for(j=20;j<25;j++)
      {
       setcolor(7);
       int count=5;
       while(count--)
	{
	 sound(10*random(100));
	 delay(75);
	 nosound();
	}
       for(int k=0;k<360;k++)
       {
	delay(1);
	arc(g,h,0,k,j-10);
       }
      }
     delay(800);
     cleardevice();
     settextstyle(6,0,8);
     outtextxy(250,100,"Loading...");
     for(j=20;j<25;j++)
      {
       setcolor(j/4);
       int count=5;
       while(count--)
	{
	 sound(10*random(100));
	 delay(75);
	 nosound();
	}
       for(int k=0;k<360;k++)
	{
	 delay(1);
	 arc(g,h,0,k,j-10);
	}
      }
     delay(800);
     cleardevice();
     settextstyle(7,0,8);
     outtextxy(250,150,"\t\tWelcome");
     delay(1000);
     cleardevice();
   }
   void main()
   {
    clrscr();
    int ch;
    char ch5;
    fstream fp5;
    fp5.open("C_products.dat",ios::in);
    int gdriver=DETECT,gmode,errorcode;
    int x,y;
    int midx,midy;
    initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
    Intro i;
    Supermarket s;
    do
     {
	i.welcome();
	setcolor(5);
	setbkcolor(BLUE);
	settextstyle(7,HORIZ_DIR,4);
	outtextxy(100,100,"Main Menu");
	settextstyle(1,0,5);
	setcolor(7);
	outtextxy(50,180,"1.Customer");
	outtextxy(50,220,"2.Administrator");
	outtextxy(50,260,"3.Exit");
	setcolor(8);
	outtextxy(50,320,"Enter the option");
	cin>>ch;
	setcolor(7);
	switch(ch)
	{
	 case 1:cleardevice();
		if(ch==1)
		 {
		  User_Insert_Details();
		  place_order();
		  fp5.write((char*)&u,sizeof(User));
		 }
		getch();
		break;
	 case 2:admin_menu();
		break;
	 case 3:exit(0);
	 default:cout<<"\a";
	}
     cleardevice();
     if(ch==1||ch==2)
      {
       setbkcolor(WHITE);
       setcolor(BLUE);
       settextstyle(1,0,5);
       outtextxy(100,100,"Do You Wish To Continue");
       outtextxy(100,150,"Press (Y/y) for 'Yes'");
       outtextxy(10,190,"Else You Will Be Out Of Program");
       settextstyle(3,0,2);
       outtextxy(150,240,"Note: Pressing Any Other Characters Indicates No");
       cin>>ch5;
      }
     }while(ch5=='Y'||ch5=='y');
     getch();
   }
