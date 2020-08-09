#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>

class hotel
{
    int room_no;
    char rtype[30];
    char name[30];
    char address[50];
    char phone[10];
    int nights;

    public:
    void main_menu();    //DONE to dispay the main menu
    void add();        //to book a room
    void display();    //to display the customer record
    void rooms();    //to display alloted rooms
    void typesofrooms();//DONE
    void bill();
    void edit();    //to edit the customer record
    int check(int);    //to check room status
    void modify(int);    //to modify the record
    void delete_rec(int);

}h;
void hotel::typesofrooms()
{ clrscr();
  cout<<"\n\n\tWe here at Enchanted Isle Resort offer our guests a variety of rooms:";
  cout<<"\n\t 1. Single - Rs.2999 per night";
  cout<<"\n\t 2. Double - Rs.3999 per night";
  cout<<"\n\t 3. Mini Suite - Rs.7999 per night";
  cout<<"\n\t 4. Grand Suite - Rs.9999 per night";
  cout<<"\n\t 5. The Enchanted Suite - Rs.12000 per night";
  cout<<"\n\n\n\t The prices mentioned above include access to hotel wifi, B&B, tranport to and from airport.";
  getch();
}
void hotel::bill()
{ clrscr();
  fstream fin ("Record2.dat", ios::in|ios::out);
  int sum=0,flag=0,r;
  cout<<"Enter room number";
  cin>>r;
    while(!fin.eof())
    {
	fin.read((char*)&h,sizeof(hotel));
	if(room_no==r)
	{
	    clrscr();
	    cout<<"\n Customer Details";
	    cout<<"\n ****************";
	    cout<<"\n\n Room no: "<<room_no;
	    cout<<"\nRoom type:"<<rtype;
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone no: "<<phone;
	    cout<<"\n No. of nights: "<<nights;
	       if(strcmpi(rtype,"Single"))
	       {
		sum=sum+(nights*2999);
	       }
	     else if(strcmpi(rtype,"Double"))
	       {
		sum=sum+(nights*3999);
	       }
	      else if(strcmpi(rtype,"Mini suite"))
	       {
		sum=sum+(nights*7999);
	       }
	      else if(strcmpi(rtype,"Grand Suite"))
	       {
		sum=sum+(nights*9999);
	       }
	      else if(strcmpi(rtype,"The enchanted suite"))
	       {
		sum=sum+(nights*12000);
	       }

	    cout<<"\n\n TOTAL AMOUNT: "<<sum;
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";
    getch();
 }

void hotel::main_menu()
{
    int choice;

    do
    {
	clrscr();
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\t\t\t\t* MAIN MENU *";
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\n\n\t\t\t1.Rooms and Amenities";
	cout<<"\n\t\t\t2.Book A Room";
	cout<<"\n\t\t\t3.Customer Record";
	cout<<"\n\t\t\t4.Rooms Allotted";
	cout<<"\n\t\t\t5.Edit Record";
	cout<<"\n\t\t\t6.Display Bill";
	cout<<"\n\t\t\t7.Exit";
	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>choice;

	switch(choice)
	{
	    case 1: typesofrooms();
		    break;
	    case 2: add();
		    break;
	    case 3: display();
		    break;
	    case 4: rooms();
		    break;
	    case 5: edit();
		    break;
	    case 6: bill();
		    break;
	    case 7: exit(0);
	    default:
		    {
			cout<<"\n\n\t\t\tWrong choice!!!";
			cout<<"\n\t\t\tPress any key to continue!!";
			getch();
		    }
	}
    } while (choice!=6);
}

void hotel::add()
{
    int opt,r,flag,rt;
    char password[10];
    char *phoneNumber;
    ofstream fout("Record2.dat",ios::out|ios::app);
    typesofrooms();
    cout<<"\n Enter Customer Detalis";
    cout<<"\n **********************";
    cout<<"\n\n Room Type: ";
    ent: cin>>rt;
    switch(rt)
    { case 1: strcpy(rtype,"Single");
	   break;
      case 2: strcpy(rtype,"Double");break;
      case 3: strcpy(rtype,"Mini Suite");break;
      case 4: strcpy(rtype,"Grand Suite"); break;
      case 5: strcpy(rtype,"Enchanted Suite");break;
      default:{"Enter correct option"; goto ent;}
    }
    cout<<"\n Room no: ";
    cin>>r;
    flag=check(r);

    if(flag)
	cout<<"\n Sorry..!!!Room is already booked";
     else
     {
	room_no=r;
	cout<<" Name: ";
	gets(name);
	cout<<" Address: ";
	gets(address);
	cout<<" Phone No: ";
	ag:gets(phoneNumber);
	// Check whether phone number is 10 digits
	if(strlen(phoneNumber) != 10) {
		cout<<"Enter valid phone number";
		goto ag;
	} else {
		strcpy(phoneNumber, phone);
	}
	//gets(phone);// pcheck();
	cout<<" Number of nights: ";
	cin>>nights;
	fout.write((char*)&h,sizeof(hotel));
	cout<<"\n Room is booked!!!";
     }

    cout<<"\n Press any key to continue!!";
    getch();
    fout.close();
     }

void hotel::display()
{
    clrscr();
    ifstream fin("Record2.dat",ios::in);
    int r,flag;
    cout<<"\n Enter room no: ";
    cin>>r;

    while(!fin.eof())
    {
	fin.read((char*)&h,sizeof(hotel));
	if(h.room_no==r)
	{
	    clrscr();
	    cout<<"\n Customer Details";
	    cout<<"\n ****************";
	    cout<<"\n\n Room no: "<<room_no;
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone no: "<<phone;
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";

    cout<<"\n\n Press any key to continue!!";
    getch();
    fin.close();
}

void hotel::rooms()
{
    clrscr();
    ifstream fin("Record2.dat",ios::in);
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\t\t\t*********************";
    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

    while(1)
    {
	fin.read((char*)&h,sizeof(hotel));
	if(fin.eof()) {
		break;
	}
	cout<<"\n\n "<<h.room_no<<"\t\t"<<h.name;
	cout<<"\t\t"<<h.address<<"\t\t"<<h.phone;
	}

    cout<<"\n\n\n\t\t\tPress any key to continue!!";
    getch();
    fin.close();
}

void hotel::edit()
{
    clrscr();
    int choice,r;

    cout<<"\n EDIT MENU";
    cout<<"\n *********";
    cout<<"\n\n 1.Modify Customer Record";
    cout<<"\n 2.Delete Customer Record";

    cout<<"\n Enter your choice: ";
    cin>>choice;

    clrscr();
    cout<<"\n Enter room no: ";
    cin>>r;

    switch(choice)
    {
	case 1: modify(r);
		break;
	case 2: delete_rec(r);
		break;
	default: cout<<"\n Wrong Choice!!";
    }

    cout<<"\n Press any key to continue!!!";
    getch();
}

int hotel::check(int r)
{
    int flag=0;
    ifstream fin("Record2.dat",ios::in);
    while(!fin.eof())
    {  // for(int i=0; i<25; i++)
	fin.read((char*)&h,sizeof(hotel));
	if(h.room_no==r)
	{
	    flag=1;
		break;
	}
    }

    fin.close();
    return(flag);
}

void hotel::modify(int r)
{
    long pos,flag=0;
    fstream file("Record2.dat",ios::in|ios::out|ios::binary);

    while(!file.eof())
    {
	pos=file.tellg();
	file.read((char*)&h,sizeof(hotel));
	if(h.room_no==r)
	{
	    cout<<"\n Enter New Details";
	    cout<<"\n *****************";
	    cout<<"\n Name: ";
	    gets(name);
	    cout<<" Address: ";
	    gets(address);
	    cout<<" Phone no: ";
	    gets(phone);
	    cout<<" Number of nights: ";
	    cin>>nights;

	    file.seekg(pos);
	    file.write((char*)&h,sizeof(hotel));
	    cout<<"\n Record is modified!!";
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";

    file.close();
}

void hotel::delete_rec(int r)
{
    int flag=0;
    char ch;
    ifstream fin("Record2.dat",ios::in);
    ofstream fout("temp.dat",ios::out);

    while(1)
    {
	fin.read((char*)&h,sizeof(hotel));
	if(fin.eof()) break;
	if(h.room_no==r)
	{
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone No: "<<phone;
	    cout<<"\n\n Do you want to delete this record(y/n): ";
	    cin>>ch;

	    if(ch=='n')
	    fout.write((char*)&h,sizeof(hotel));

	    flag=1;
	}
	else
	    fout.write((char*)&h,sizeof(hotel));
    }

    fin.close();
    fout.close();

    if(flag==0)
	cout<<"\n Sorry room no. not found or vacant!!";
    else
    {
	remove("Record2.dat");
	rename("temp.dat","Record2.dat");
    }
}

void main()
{
    textmode(C80);
    textbackground(BLACK);
    textcolor(RED);

    clrscr();
    cout<<"\n\t\t\t****************************";
    cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
    cout<<"\n\t\t\t****************************";
    sleep(2);

    cout<<"\n\n\n\n\t\tMade By:";
    sleep(2);
    cout<<" Anweshaa Baruah & Rishika T D";
    sleep(2);
    cout<<"\n\n\n\n\n\t\t\t\tPress any key to continue!!";
    getch();
    h.main_menu();

}









