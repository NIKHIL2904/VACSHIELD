#include <ctime>
#include <iostream>
#include<bits/stdc++.h>
#include <unistd.h>

using namespace std;
struct date
{
    int day;
    int month;
    int year;
};

class database
{
    public:
    string name;
    int age;
    unsigned long long int phoneNo;
    unsigned long long int aadhar;
    database *next;
    int vaccine; //no of vaccines given to the person (0,1,2)
    date date1;
    date date2; //slot to be taken by the user
    string time1;
    string time2;
    string uc;
    database()
    {
        name="";
        age=0;
        phoneNo=0;
        aadhar=0;
        next=NULL;
        vaccine=0;

    }
};
database* start=NULL;
map<int long,string>m;
map<int long,string>m1;
void certificate(int long aa){
    string status;
    database* node=start;
    while(node!=NULL)
    {
        if(node->aadhar==aa)
        {
            break;
        }
        node=node->next;
    }
    if(node->vaccine==0)
    {
        status="Not vaccinated";

    }
    else if(node->vaccine ==1)
    {
        status="Partially Vaccinated";
    }
    else if(node->vaccine ==2)
    {
        status ="Fully Vaccinated";
    }
    cout<<endl<<endl;
    cout<<"*************************************************************"<<endl<<endl;
    cout<<"                    VACCINATION CERTIFICATE "<<endl<<endl<<endl;
    cout<<"        NAME                  :"<<node->name<<endl<<endl;
    cout<<"        Age                   :"<<node->age<<endl<<endl;
    cout<<"        Aadhar number         :"<<node->aadhar<<endl<<endl;
    cout<<"        Unique Key            :"<<node->uc<<endl<<endl;
    cout<<"        Phone number          :"<<node->phoneNo<<endl<<endl;
    cout<<"        Doses taken           :"<<node->vaccine<<endl<<endl;
    if(node->vaccine==1)
    {
    cout<<"        1st Dose taken on     :"<<node->date1.year<<"-"<<node->date1.month<<"-"<<node->date1.day<<endl<<endl;
    cout<<"        2nd Dose taken on     :Not taken yet"<<endl<<endl;
    }
    if(node->vaccine==2)
    {
    cout<<"        1st Dose taken on     :"<<node->date1.year<<"-"<<node->date1.month<<"-"<<node->date1.day<<endl<<endl;
    cout<<"        2nd Dose taken on     :"<<node->date2.year<<"-"<<node->date2.month<<"-"<<node->date2.day<<endl<<endl;

    }
    if(node->vaccine==0)
    {
        cout<<"        1st Dose taken on     :Not taken yet"<<endl<<endl;
        cout<<"        2nd Dose taken on     :Not taken yet"<<endl<<endl;
    }
    cout<<"        Status                :"<<status<<endl<<endl;
    cout<<endl<<endl<<"        TOGETHER, INDIA WILL DEFEAT COVID-19"<<endl<<endl;
    cout<<"*************************************************************"<<endl;
    cout<<"        NOTE : In case of any adverse events, kindly contact nearest \n        Public Health Center\n"<<endl;
    cout<<"        HELPLINE NUMBER : 1075"<<endl;
    cout<<"*************************************************************"<<endl<<endl;

    return;
}


void authenticity()
{

    cout<<endl<<endl;
    int long phoneNumber;
    string uniqueCode;
    int long aadhar_number;
    cout<<"************************************************************"<<endl<<endl;
    cout<<"WE ARE HERE TO VERIFY YOUR CERTIFICATE"<<endl;
    cout<<"PLEASE ENTER YOUR PHONE NUMBER :";
    cin>>phoneNumber;
    cout<<"PLEASE ENTER YOUR UNIQUE CODE :";
    cin>>uniqueCode;
    cout<<"PLEASE ENTER YOUR AADHAR NUMBER :";
    cin>>aadhar_number;
    if(m[phoneNumber]==uniqueCode&&m1[aadhar_number]==uniqueCode)
    {
        cout<<"CONGRATULATION !! YOU HAVE A VALID CERTIFICATE "<<endl<<endl;
    }
    else
    {
        cout<<"SORRY YOU DONT HAVE A VALID CERTIFICATE !!"<<endl;
    }
}




void set_slots(int long aadhar1)
{
    database* temp=start;
    while(temp->aadhar!=aadhar1)
    {
        temp=temp->next;
    }
    database* node=temp;
    here:
    cout<<"*******************************************"<<endl<<endl;

    cout<<"PLEASE BOOK YOUR SLOT :"<<endl;
    cout<<"CURRENT DATE & TIME IS :";

    time_t t =time(0);   // get time now
    char* date_time=ctime(&t);
    cout<<date_time;
    // tm* now = localtime(&t);
    // cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday<< "\n";
    cout<<endl<<endl;
    cout<<"PLEASE SELECT A DATE :"<<endl;
    tm* now = localtime(&t);
    for(int i=1;i<=7;i++)
    {

    if(now->tm_mday+i<=30)
    cout <<i<<". "<< (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday+i<< "\n";
    else
    cout <<i<<". "<< (now->tm_year + 1900) << '-' << (now->tm_mon + 1+1) << '-'<<  now->tm_mday+i-30<< "\n";

    }
    int ch;
    cin>>ch;
    int year,month,day;
    string slot;
    year=now->tm_year+1900;
    if(now->tm_mday+ch<=30)
    {
        month=now->tm_mon+1;
        day=now->tm_mday+ch;
    }
    else
    {
        month=now->tm_mon+2;
        day=now->tm_mday+ch-30;
    }

    cout<<endl<<endl;
    cout<<"PLEASE SELCT YOUR TIME :"<<endl;
    cout<<"1. 10:00 AM to 12:15 PM"<<endl;
    cout<<"2. 12:30 PM to 01:45 PM"<<endl;
    cout<<"3. 02:00 PM to 04:00 PM"<<endl;
    int cht;
    cin>>cht;
    string yt;
    switch(cht)
    {
        case 1:
        {
            yt="10:00 AM to 12:15 PM";
            break;
        }
        case 2:
        {
            yt="12:30 PM to 01:45 PM";
            break;
        }
        case 3:
        {
            yt="02:00 PM to 04:00 PM";
            break;
        }
    }
    cout<<endl<<endl;
    cout<<"PLEASE CONFIRM YOUR SLOT :"<<endl;
    cout<<"DATE : "<<year<<'-'<<month<<'-'<<day<<endl;
    cout<<"TIME : "<<yt<<endl;
    cout<<"1. TO CONTINUE BOOKING"<<endl;
    cout<<"2. TO RESTART THE PROCESS"<<endl;

    int b;
    cin>>b;
    if(b==1)

    {
        node->vaccine++;
        if(node->vaccine==1)
        {
            node->date1.year=year;
            node->date1.month=month;
            node->date1.day=day;
        }
        if(node->vaccine==2)
        {
            node->date2.year=year;
            node->date2.month=month;
            node->date2.day=day;
        }
        cout<<"Congratulation !! YOUR BOOKING WAS SUCCESSFUL"<<endl;
        // certificate(node);
    }
    else
    {
        cout<<endl;
        goto here;
    }
}
string generateUniqueKey(const int len) {
    static const char alphanum[] = "0123456789""ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijklmnopqrstuvwxyz";
string tmp_s;
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    } return tmp_s;
}


void data_entry(database* &temp1)
{
    database* temp=new database;
    cout<<"ENTER THE DETAILS OF THE USER :"<<endl;
    cout<<"ENTER YOUR NAME : ";
    cin>>temp->name;
    cout<<"Enter you age : ";
    cin>>temp->age;
    cout<<"ENTER YOUR PHONE NUMBER :";
    cin>>temp->phoneNo;
    cout<<"ENTER YOUR ADHAAR NUMBER :";
    cin>>temp->aadhar;
    temp->uc=generateUniqueKey(16);
    temp->vaccine=0;
    temp->next=NULL;
    temp1=temp;
    m[temp->phoneNo]=temp->uc;
    m1[temp->aadhar]=temp->uc;
    return;
}



void modify_data(int aadhar1)
{
    cout<<"***********************************************************"<<endl<<endl;
    cout<<"YOU CAN MODIFY YOUR DATA HERE :"<<endl<<endl;
    cout<<"NOTE : YOU CANNOT CHANGE YOUR 'NAME' AND 'AADHAR NUMBER'"<<endl<<endl;
    int ch;
    database *t=start;
    if(start==NULL)
    {
        cout<<"No database exists";
        return;
    }
        while(t!=NULL)
        {
            if(t->aadhar==aadhar1)
            {
                cout<<"1. TO CHANGE AGE"<<endl<<"2. TO CHANGE PHONE NUMBER"<<endl<<"3. TO CHANGE THE DATE OF 1st SLOT"<<endl<<"3. TO CHANGE THE DATE OF 2nd SLOT"<<endl;
                cin>>ch;
                switch(ch)
                {
                    case 1:cout<<"ENTER THE NEW AGE :";
                           cin>>t->age;
                           break;
                    case 2:cout<<"ENTER THE NEW PHONE NUMBER :";
                           cin>>t->phoneNo;
                           break;
                    case 3:set_slots(aadhar1);
                           break;
                    case 4:set_slots(aadhar1);
                    break;
                }
                return;
            }
            t=t->next;
        }


}
void display()
{

    cout<<"*******************************************************************"<<endl<<endl;
    cout<<"                          vacShield"<<endl;
    cout<<"      WELCOME TO ONLINE PORTAL TO REGISTER FOR VACCINATION"<<endl<<endl;
    here:
    cout<<"MAKE YOUR CHOICE "<<endl;
    cout<<"1. NEW DATA ENTRY"<<endl;
    cout<<"2. MODIFY PERSONAL DATA "<<endl;
    cout<<"3. BOOK A SLOT FOR VACCINATION"<<endl;
    cout<<"4. PRINT YOUR VACCINATION CERTIFICATE"<<endl;
    cout<<"5. AUTHENTICATE YOUR CERTIFICATE"<<endl;
    int ch;
    cin>>ch;
    if(ch==1)
    {
        database* node=NULL;
        data_entry(node);
        database* &temp=start;
        if(start==NULL)
        {
            start=node;
        }
        else{
        node->next=start;
        start=node;

        }

        cout<<endl<<endl;
        goto here;
    }
    if(ch==2)
    {
        int long aa;
        cout<<"ENTER YOUR AADHAR NUMBER :";
        cin>>aa;
        modify_data(aa);
        cout<<endl<<endl;
        goto here;
    }
    if(ch==3)
    {
        int long aa;
        cout<<"ENTER YOUR AADHAR NUMBER :";
        cin>>aa;
        set_slots(aa);
        cout<<endl<<endl;
        goto here;
    }
    if(ch==4)
    {int long aa;
        cout<<"ENTER YOUR AADHAR NUMBER :";
        cin>>aa;
        certificate(aa);
    cout<<endl<<endl;
    goto here;}

    if(ch==5)
    {
        authenticity();
    cout<<endl<<endl;
    goto here;}

}
int main() {

    srand((unsigned)time(NULL) * getpid());

    display();

}
