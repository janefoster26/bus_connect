
#include<fstream>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<iomanip>
#include<vector>
#include <bits/stdc++.h>
#include<stdlib.h>


using namespace std;

//-----------------------------------------------------------------ADMIN PART START-------------------------------------------------------------------------------------------------------
void admin_work();
void  Enterdetails();
void Change();
void Deleteone();
void search_details();

class seatinfo
{
public:
    char bno[20];
    int arr[32];
    seatinfo()
    {
        for(int i=0;i<32;i++)
        {
            arr[i]=0;
        }
        strcpy(bno,"0");
    }
    void seat_display()
    {
        cout<<bno<<endl;
        cout<<"---------------------------------------------------------Seat Display System----------------------------------------------------------------------------"<<endl;
        int count=0;
            const char separator = ' ';
            const int nameWidth = 23;
            const int numWidth=6;
        for(int i=0;i<32;i++)
        {
            if(count<4)
            {
                if(arr[i]==0)
                {
                    cout << left << setw(numWidth) << setfill(separator) << (i+1);
                     cout << left << setw(nameWidth) << setfill(separator) << "availabe";

                }
                else
                {
                    cout << left << setw(numWidth) << setfill(separator) << (i+1);
                     cout << left << setw(nameWidth) << setfill(separator) <<"booked";
                }
                count++;
            }
            else
            {
                cout<<endl;
                if(arr[i]==0)
                {
                    cout << left << setw(numWidth) << setfill(separator) << (i+1);
                    cout << left << setw(nameWidth) << setfill(separator) << "availabe";
                }
                else
                {
                    cout << left << setw(numWidth) << setfill(separator) << (i+1);
                    cout << left << setw(nameWidth) << setfill(separator) <<"booked";
                }
                count=1;
            }
        }
    }

    void Enter()
    {
        cout<<"Enter bus number\n";
        cin>>bno;
    }
};

void Enter_seat()
{
  char ch;
    fstream fil3;
    fil3.open("seatres.dat",ios::binary|ios::app);
    seatinfo S;
    do
    {

     cout<<endl<<"ADDING A NEW BUS DETAILS "<<endl;
     S.Enter();
     fil3.write((char*)&S,sizeof(seatinfo));
     cout<<endl<<"More bus record?[Y/N]:";
     cin>>ch;
    }
     while(ch=='Y'||ch=='y');


  fil3.close();
}



void Seat_display()
{
    fstream fil;
    fil.open("seatres.dat",ios::binary|ios::in);
    seatinfo M;
    while(fil.read((char*)&M,sizeof(seatinfo)))
        M.seat_display();
    fil.close();
}
class driver
{
        public:
    char bus_number[20];
    int id;
    char first_name[20];
    char last_name[20];
    int age;
    int contact_number;
  int retid()
  {
      return id;
  }
  int retage()
  {
	return age;
  }
  int retcontact_number()
  {
	return contact_number;
  }
  char* retfname()
  {
	return first_name;
  }

  char* retlname()
  {
      return last_name;
  }

  char* retbus_no()
  {
      return bus_number;
  }

  void Enter()
{
    cout<<"Enter bus number:";cin>>bus_number;
    cout<<"Enter id number:"; cin>>id;
    cout<<"Enter first name:"; cin>>first_name;
    cout<<"Enter last name:";cin>>last_name;
    cout<<"Enter age:"; cin>>age;
    cout<<"Enter contact number:"; cin>>contact_number;
}

void Modi()
{
    cout<<"Enter bus number:";cout<<bus_number;
    cout<<"\nEnter id number:"; cin>>id;
    cout<<"Enter first name:"; cin>>first_name;
    cout<<"Enter last name:"; cin>>last_name;
    cout<<"Enter age:"; cin>>age;
    cout<<"Enter contact number:"; cin>>contact_number;
}

void display()
{
   const char separator    = ' ';
    const int numWidth      = 23;
    cout<<endl;
    cout << left << setw(numWidth) << setfill(separator) << bus_number;
    cout << left << setw(numWidth) << setfill(separator) << id;
    cout << left << setw(numWidth) << setfill(separator) << first_name;
    cout << left << setw(numWidth) << setfill(separator) << last_name;
    cout << left << setw(numWidth) << setfill(separator) << age;
    cout << left << setw(numWidth) << setfill(separator) << contact_number;
    cout << endl;
}
};

class bus_detail
{
     public:
    char bname[20];
    char bno[20];
    char bstart[20];
    char bend[20];
    char btime[20];
    int seat;
    int price;

    char* retbname()

    {
        return bname;
    }

     char* retbusno()
    {
        return bno;
    }

     char* retbstart()
    {
        return bstart;
    }

     char* retbend()
    {
        return bend;
    }

     char* retbtime()
    {
        return btime;
    }

    int retseat()
    {
        return seat;
    }

    int retprice()
    {
        return price;
    }

    void enter()
    {
        cout<<"Enter bus name\n";
        cin>>bname;
        cout<<"Enter bus number\n";
        cin>>bno;
        cout<<"Enter bus starting location\n";
        cin>>bstart;
        cout<<"Enter bus ending location\n";
        cin>>bend;
        cout<<"Enter bus timing\n";
        cin>>btime;
        cout<<"Enter bus total no. seats\n";
        cin>>seat;
          cout<<"Enter price of one ticket\n";
        cin>>price;
    }

    void modi()
    {
        cout<<"Enter bus name\n";
        cin>>bname;
        cout<<"Enter bus starting location\n";
        cin>>bstart;
        cout<<"Enter bus ending location\n";
        cin>>bend;
        cout<<"Enter bus timing\n";
        cin>>btime;
        cout<<"Enter bus total no. seats\n";
        cin>>seat;
          cout<<"Enter price of one ticket\n";
        cin>>price;
    }

    void display()
    {
    const char separator    = ' ';
    const int numWidth      = 23;
    cout << left << setw(numWidth) << setfill(separator) << bname;
    cout << left << setw(numWidth) << setfill(separator) << bno;
    cout << left << setw(numWidth) << setfill(separator) << bstart;
    cout << left << setw(numWidth) << setfill(separator) << bend;
    cout << left << setw(numWidth) << setfill(separator) << btime;
    cout << left << setw(numWidth) << setfill(separator) << seat;
    cout << left << setw(numWidth) << setfill(separator) << price;
    cout << endl;

    }


    void increase_ticket(int quan)
    {
        seat+=quan;
    }

    void cancel_ticket(int quan)
    {
        seat-=quan;
    }

};


void bus_display()
{
    cout<<"\nAVAILABLE BUSES:\n\n";
    fstream fil;
    fil.open("whyus.dat",ios::binary|ios::in);
    bus_detail M;
    int Count=0;
     const char separator    = ' ';
    const int nameWidth     = 23;
    while(fil.read((char*)&M,sizeof(M)))
    {
        if(Count==0)
        {
    cout << left << setw(nameWidth) << setfill(separator) << "bus name";
    cout << left << setw(nameWidth) << setfill(separator) <<"bus number";
    cout << left << setw(nameWidth) << setfill(separator) << "bus starting location";
    cout << left << setw(nameWidth) << setfill(separator) << "bus ending location";
    cout << left << setw(nameWidth) << setfill(separator) << "bus timing";
    cout << left << setw(nameWidth) << setfill(separator) << "bus total no. seats";
    cout << left << setw(nameWidth) << setfill(separator) <<"price of one ticket";
    cout<<endl;
        }
     M.display();
     cout<<endl;
     Count++;
   }
   cout<<Count<<" Buses Available.."<<endl;
   fil.close();

        cout<<"Press any key to continue...";
       getch();
      system("cls");
}

void driver_display()
{
    cout<<"\nAVAILABLE DRIVERS:\n";
    fstream fil;
    fil.open("driver.dat",ios::binary|ios::in);
    driver M;
    int Count=0;
    const char separator    = ' ';
    const int nameWidth     = 23;
    while(fil.read((char*)&M,sizeof(M)))
    {
        if(Count==0)
        {
        cout << left << setw(nameWidth) << setfill(separator) << "bus number:";
        cout << left << setw(nameWidth) << setfill(separator) <<"id number:";
        cout << left << setw(nameWidth) << setfill(separator) << "first name:";
        cout << left << setw(nameWidth) << setfill(separator) << "last name:";
        cout << left << setw(nameWidth) << setfill(separator) << "age:";
        cout << left << setw(nameWidth) << setfill(separator) << "contact number:";
        cout<<endl;
        }
     M.display();
     cout<<endl;
     Count++;
   }
   cout<<Count<<" Drivers Available.."<<endl;
   fil.close();

        cout<<"Press any key to continue...";
       getch();
      system("cls");
}

void Book_Ticket()
{
  cout<<endl<<"Book your ticket here..."<<endl;
  int ticket;
  char number[20];
  bus_display();
  int count=0;
  cout<<"\nBus number :";cin>>number;
  cout<<"Quantity in Number:";cin>>ticket;
  fstream fil,fil2;
  fil.open("whyus.dat",ios::binary|ios::in|ios::out);
  fil2.open("seatres.dat",ios::binary|ios::in|ios::out);
  bus_detail M;
  seatinfo S;
  int seat;
  float amt=0;
   while(fil2.read((char*)&S,sizeof(seatinfo)))
  {
    if(strcmpi(S.bno,number)==0)
    {
       S.seat_display();
       int i=0;
       while(i<ticket)
       {
           cout<<"\nEnter seat number:";
           cin>>seat;
           if(S.arr[seat-1]==1)
            cout<<"Already booked\n";
           else
           {
           S.arr[seat-1]=1;
           cout<<"\nYour Customer ID is:"<<"CM"<<seat<<endl;
           i++;
           }
       }
       S.seat_display();
      fil2.seekp(fil2.tellg()-sizeof(S));
      fil2.write((char*)&S,sizeof(S));
    }
  }

  while(fil.read((char*)&M,sizeof(M)))
  {
    if(strcmpi(M.retbusno(),number)==0)
    {
        count++;
      M.cancel_ticket(ticket);
      fil.seekp(fil.tellg()-sizeof(M));
      fil.write((char*)&M,sizeof(M));

      amt=((M.retprice())*ticket);

    }
  }
    if(count)
    {
      cout<<endl<<"Seat booked!"<<endl;
        cout<<"Hey User!"<<endl;
        cout<<"Amount to be paid:"<<amt;
       cout<<"\nGet ur ORDERCODE and pay for ur booking"<<endl;
    }else{
    cout<<"No such record found!";
    }

  fil.close();

       cout<<"Press any key to continue...";
       getch();
      system("cls");
}

void Cancel_ticket()
{
  cout<<endl<<"You can cancel your ticket here!"<<endl;
  bus_display();
  int cancelquan,found=0;
  char cancelno[20];
  fstream fil,fil2;
  fil.open("whyus.dat",ios::binary|ios::in|ios::out);
  fil2.open("seatres.dat",ios::binary|ios::in|ios::out);
  bus_detail M;
  seatinfo S;
  float AMT;
  cout<<"Bus Number:";cin>>cancelno;
  cout<<"Quantity to be Cancelled:";cin>>cancelquan;
  while(!found && fil2.read((char*)&S,sizeof(seatinfo)))
  {
    if(strcmp(S.bno,cancelno)==0)
    {
      found++;
      for(int i=0;i<cancelquan;i++)
      {
          int seat;
          cout<<"Enter last digit of your customer id:";
          cin>>seat;
          S.arr[seat-1]=0;
      }
      fil2.seekp(fil2.tellg()-sizeof(S));
      fil2.write((char*)&S,sizeof(seatinfo));
    }
  }
  found=0;
  while(!found && fil.read((char*)&M,sizeof(M)))
  {
    if(strcmp(M.retbusno(),cancelno)==0)
    {
      found++;
      M.increase_ticket(cancelquan);
      fil.seekp(fil.tellg()-sizeof(M));
      fil.write((char*)&M,sizeof(M));
      AMT=((M.retprice())*cancelquan);
    }
  }
  fil.close();
  if(found)
  {
     cout<<endl<<"Booking Cancelled"<<endl;
    cout<<endl<<"Hey User!"<<endl;
      cout<<"Enter ur ORDERCODE and get back ur paid money\n"<<AMT<<endl;
  }
  else
   cout<<"Booking not Found..."<<endl;

        cout<<"Press any key to continue...";
       getch();
      system("cls");
}

int admin()
{
    string a_name;
    char password[5];
    string A[]={"Abhay","Abhinav","Aastha","Reshu","Neha"};
    char B[10][10]={"3242","3251","3239","3243","3254"};
    int f=0;
    cout<<"Enter Admin Name:";
    cin>>a_name;
    cout<<"Enter Password:";
    for(int i=0;i<4;i++)
    {
        password[i]=getch();
        cout<<"*";
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        if((a_name==A[i])&&(strcmp(password,B[i])==0))
        {
            f=1;
        }
    }
    return f;
         cout<<"Press any key to continue...";
       getch();
      system("cls");
}


void admin_work()
{
    if(admin())
    {
        int t;
     do
     {
     cout<<"\n1.To Enter  Details\n";
     cout<<"2.To Change Details\n";
     cout<<"3.To Delete Details\n";
     cout<<"4.To Display bus records\n";
     cout<<"5.To Display driver records\n";
     cout<<"6.Quit\n";
     cout<<"Enter option:";
     cin>>t;
     switch(t)
     {
        case 1:Enterdetails();
        break;
        case 2:Change();
        break;
        case 3: Deleteone();
        break;
        case 4:bus_display();
        break;
        case 5:driver_display();
        break;
        case 6:cout<<"Quitting!..";
     }
     }while(t!=6);
    }
    else
        cout<<"Invalid password!..try again!\n";

       cout<<"Press any key to continue...";
       getch();
      system("cls");
}

void Enterdetails()
{
    char ch;
    fstream fil,fil2,fil10;
    bus_detail M;
    driver D;
    seatinfo S;
    fil.open("whyus.dat",ios::binary|ios::app);
    do
    {
    cout<<endl<<"ADDING A NEW BUS DETAILS "<<endl;
     M.enter();
     fil.write((char*)&M,sizeof(bus_detail));
     cout<<endl<<"More bus record?[Y/N]:";
     cin>>ch;
    }
     while(ch=='Y'||ch=='y');
     fil.close();
      fil10.open("seatres.dat",ios::binary|ios::app);
     do
     {
    cout<<endl<<"ADDING NEW SEAT RECORD\n"<<endl;
      S.Enter();
     fil10.write((char*)&S,sizeof(seatinfo));
     cout<<endl<<"More seat record\n";
     cin>>ch;
     }
     while(ch=='Y'||ch=='y');
       fil10.close();
       fil2.open("driver.dat",ios::binary|ios::app);
     do
     {
     cout<<endl<<"ADDING A NEW DRIVER RECORD"<<endl;
     D.Enter();
     fil2.write((char*)&D,sizeof(driver));
     cout<<endl<<"More driver record?[Y/N]:";
     cin>>ch;
     }
     while(ch=='y' || ch=='Y');


  fil2.close();

       cout<<"Press any key to continue...";
       getch();
      system("cls");
}

void Change()
{
  cout<<endl<<"MODIFICATION DETAILS OF BUS"<<endl;
  char modno[20];
  int found=0;
  char ch;
  fstream fil;
  fil.open("whyus.dat",ios::binary|ios::in|ios::out);
  bus_detail M;
  bus_display();
  cout<<"Bus Number(requiring modification):";cin>>modno;
  while(!found && fil.read((char*)&M,sizeof(M)))
  {
    if(strcmp(M.retbusno(),modno)==0)
    {
      found++;
      cout<<endl<<"New details of the product"<<endl;
      M.modi();
      fil.seekp(fil.tellg()-sizeof(M));
      fil.write((char*)&M,sizeof(M));
      cout<<endl<<"Bus Info Updated..."<<endl;
    }
  }
  fil.close();
  if(!found)
    cout<<endl<<"Oops!!...Bus not Found...."<<endl;
    else
    {
      int t;
      cout<<"Enter 1 to change the details of a bus driver or else any number:";
      cin>>t;
      if(t==1)
      {
      driver_display();
       fstream fil2;
        driver D;
       fil2.open("driver.dat",ios::binary|ios::in|ios::out);
      while(fil2.read((char*)&D,sizeof(D)))
       {
         if(strcmp(D.retbus_no(),modno)==0)
         {
           cout<<endl<<"New details of the driver"<<endl;
           D.Modi();
           fil.seekp(fil.tellg()-sizeof(D));
           fil.write((char*)&D,sizeof(D));
           cout<<endl<<"Driver Info Updated..."<<endl;
         }
        }
      fil2.close();
     }
     cout<<"Enter 1 to change in seating:";
     int p;
     cin>>p;
     if(p==1)
     {
       fstream fil3;
        seatinfo S;
       fil3.open("seatres.dat",ios::binary|ios::in|ios::out);
      while(fil3.read((char*)&S,sizeof(S)))
       {
         if(strcmp(S.bno,modno)==0)
         {
             int n;
             cout<<"\nEnter number of seats to modified:";
             cin>>n;
           cout<<endl;
           for(int i=0;i<n;i++)
           {
               int seat,x;
               cout<<"Enter seat number:";
               cin>>seat;
               cout<<"Enter 1 to make it as booked and 0 to make it as not booked:";
               cin>>x;
               cout<<endl;
               S.arr[seat-1]=x;
           }
           fil3.seekp(fil3.tellg()-sizeof(seatinfo));
           fil3.write((char*)&S,sizeof(seatinfo));
           cout<<endl<<"Driver Info Updated..."<<endl;
         }
        }
      fil3.close();
  }
       cout<<"Press any key to continue...";
       getch();
      system("cls");
}
}


void Deleteone()
 {
  int count=0;
  cout<<endl<<"TO DELETE A SPECIFIC BUS AND DRIVER RECORD"<<endl;
  string del;
  fstream fil1,fil2;
  fil1.open("whyus.dat",ios::binary|ios::in);
  fil2.open("abhay.dat",ios::binary|ios::out);
  bus_detail M;
  cout<<"Bus no. of the Record to be deleted"<<endl;
  cin>>del;

  while(fil1.read((char*)&M,sizeof(M)))
  {
      string v(M.retbusno());
    if((v!=del))
    {
     fil2.write((char*)&M,sizeof(M));
    }
    if(v==del)
        count++;
  }
  fil1.close();
  fil2.close();
  remove("whyus.dat");
  rename("abhay.dat","whyus.dat");
  fstream fil3,fil4;;
  fil3.open("driver.dat",ios::binary|ios::in);
  fil4.open("newdriver.dat",ios::binary|ios::out);
  driver D;
  while(fil3.read((char*)&D,sizeof(D)))
  {
    string v(D.retbus_no());
    if(v!=del)
     fil4.write((char*)&D,sizeof(D));

  }
  fil3.close();
  fil4.close();
  remove("driver.dat");
  rename("newdriver.dat","driver.dat");
  if(count){
  cout<<"Bus Record deleted"<<endl;
  cout<<"Driver Record deleted"<<endl;
  }
  else
    cout<<"No record found\n";

    cout<<"Press any key to continue...";
       getch();
      system("cls");
}

 void heapify2(vector<bus_detail> &arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l].price > arr[largest].price)
        largest = l;

    if (r < n && arr[r].price > arr[largest].price)
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify2(arr, n, largest);
    }
}


void heapSort2(vector<bus_detail> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify2(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0],arr[i]);
        heapify2(arr, i, 0);
    }
}

void price_sort(char startloc[20],char endloc[20] )
{
    int Count=0;
     const char separator    = ' ';
    const int nameWidth     = 23;
    fstream fil3;
    vector<bus_detail> pq;
    int count1=0;
    bus_detail b;
    int x=0;
    fil3.open("whyus.dat",ios::binary|ios::in);
    while(fil3.read((char*)&b,sizeof(b)))
    {
        if((strcmp(b.retbstart(),startloc)==0)&&(strcmp(b.retbend(),endloc)==0))
        {
            pq.push_back(b);
        count1++;
        }
    }
    int n=count1;
    if(pq.empty()==false)
    {
        heapSort2(pq,count1);
    }
    fil3.close();
    while (pq.empty() == false)
    {
        bus_detail bd = pq.back();
        if(x==0)
        {
        cout << left << setw(nameWidth) << setfill(separator) << "bus name";
        cout << left << setw(nameWidth) << setfill(separator) <<"bus number";
        cout << left << setw(nameWidth) << setfill(separator) << "bus starting location";
        cout << left << setw(nameWidth) << setfill(separator) << "bus ending location";
        cout << left << setw(nameWidth) << setfill(separator) << "bus timing";
        cout << left << setw(nameWidth) << setfill(separator) << "bus total no. seats";
        cout << left << setw(nameWidth) << setfill(separator) <<"price of one ticket";
        x++;
        }
        cout<<endl;
        bd.display();
        cout << endl;
        pq.pop_back();
    }
}

   void heapify1(vector<bus_detail> &arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && strcmp(arr[l].btime,arr[largest].btime)>0)
        largest = l;


    if (r < n && strcmp(arr[r].btime,arr[largest].btime)>0)
        largest = r;


    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify1(arr, n, largest);
    }
}

void heapSort1(vector<bus_detail> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify1(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0],arr[i]);

        heapify1(arr, i, 0);
    }
}

void time_sort(char startloc[20],char endloc[20])
{
  int Count=0;
     const char separator    = ' ';
    const int nameWidth     = 23;
    fstream fil3;
    vector<bus_detail> pq3;
    int count1=0;
    bus_detail b;
    int x=0;
    fil3.open("whyus.dat",ios::binary|ios::in);
    while(fil3.read((char*)&b,sizeof(b)))
    {
        if((strcmp(b.retbstart(),startloc)==0)&&(strcmp(b.retbend(),endloc)==0))
        {
            pq3.push_back(b);
            count1++;
        }
    }
    fil3.close();

    if(pq3.empty()==false)
    {
        heapSort1(pq3,count1);
    }
    while (pq3.empty() == false)
    {
        bus_detail bd = pq3.back();
        if(x==0)
        {
        cout << left << setw(nameWidth) << setfill(separator) << "bus name";
        cout << left << setw(nameWidth) << setfill(separator) <<"bus number";
        cout << left << setw(nameWidth) << setfill(separator) << "bus starting location";
        cout << left << setw(nameWidth) << setfill(separator) << "bus ending location";
        cout << left << setw(nameWidth) << setfill(separator) << "bus timing";
        cout << left << setw(nameWidth) << setfill(separator) << "bus total no. seats";
        cout << left << setw(nameWidth) << setfill(separator) <<"price of one ticket";
        }
         cout<<endl;
        bd.display();
        cout << endl;
        pq3.pop_back();
    }
}

void more_display()
{
    int Count=0;
     const char separator    = ' ';
    const int nameWidth     = 23;
    char ch;
    cout<<"\nEnter y/Y if you want to search on the basis of location\n";
    cin>>ch;
    if(ch=='y' || ch=='Y')
    {
     char  floaction[20];
     char llocation[20];
     cout<<"\nEnter starting point:";
     cin>>floaction;
     cout<<"\nEnter ending point:";
     cin>>llocation;
     bus_detail b;
     fstream fil;
     int count2=0;
     fil.open("whyus.dat",ios::binary|ios::in);
     while(fil.read((char*)&b,sizeof(b)))
     {

        if((strcmp(b.retbstart(),floaction)==0)&&(strcmp(b.retbend(),llocation)==0))
        {
        cout << left << setw(nameWidth) << setfill(separator) << "bus name";
        cout << left << setw(nameWidth) << setfill(separator) <<"bus number";
        cout << left << setw(nameWidth) << setfill(separator) << "bus starting location";
        cout << left << setw(nameWidth) << setfill(separator) << "bus ending location";
        cout << left << setw(nameWidth) << setfill(separator) << "bus timing";
        cout << left << setw(nameWidth) << setfill(separator) << "bus total no. seats";
        cout << left << setw(nameWidth) << setfill(separator) <<"price of one ticket";
        cout<<endl;
        b.display();
         count2++;
        }
     }
     fil.close();
     if(count2)
     {
         int ch2;
       do
       {
           cout<<"\n1:Sorted on the basis of price\n";
           cout<<"2:Sorted on the basis of time\n";
           cout<<"3:Book your ticket\n";
           cout<<"4:Exit\n\n";
           cout<<"Enter Option:";
           cin>>ch2;
           switch(ch2)
           {
               case 1 :price_sort(floaction,llocation);
               break;
              case 2:time_sort(floaction,llocation);
               break;
               case 3:Book_Ticket();
               break;
               case 4 :cout<<"Exit!\n";
               break;
               default:cout<<"Invalid Option..."<<endl;
           }
       }while(ch2!=4);
     }
     else
        cout<<"Bus not found\n";
     }
     cout<<"Press any key to continue...";
       getch();
      system("cls");
}

int main()
{
  int choice;
  do
  {
	cout<<"\n1.BOOK YOUR TICKET"<<endl;
	cout<<"2.CANCEL YOUR TICKET "<<endl;
	cout<<"3.ADMIN"<<endl;
	cout<<"4.BUS INFO"<<endl;
	cout<<"5.EXIT"<<endl<<endl;
	cout<<"Your Option?:";cin>>choice;
	switch(choice)
	{
	 case 1 :Book_Ticket();break;
	 case 2 :Cancel_ticket();break;
	 case 3 :admin_work();break;
	 case 4:{
	          bus_display();
	          more_display();
            }
	        break;
	 case 5:cout<<"Quitting!!!..."<<endl;break;
	 default:cout<<"Invalid Option..."<<endl;
	}
  }
  while(choice!=5);
  return 0;
}

