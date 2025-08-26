#include<iostream>
using namespace std; 
int today = 0; 

class sub
{
public: 
string subname; 
int total_classes; 
float min = 80.00; //percent 
int progress; 
int attended; 
float attendance; //percent
int bunkable; 
int bunked; 

sub(string subname,int total)
{
    this->subname = subname; 
    total_classes = total; 
    attended = 0; 
    progress = 0; 
    bunkable = int(0.2*total_classes);
    cout<<"For the subject "<<subname<<" the total no. of classes is "<<total_classes<<endl<<endl; 
}
void mark_present()
{attended ++; 
    progress++;
    attendance = (float(attended)/progress)*100; 
    int bunked = progress-attended; 
    bunkable = bunkable - bunked; 
    if(bunkable<0)
    {
        cout<<"Well for subject: "<<subname<<endl<<"Bro you are cooked: Your attendance is: "<<attendance<<"\n You now have bunked: "<<bunked<<" classes"<<"\nYou can now bunked: "<<-bunkable<<"extra classes \n\n"; 
    }
    else
        cout<<"Well for subject: "<<subname<<endl<<"Bro you are NOT cooked: Your attendance is: "<<attendance<<"you now have bunked: "<<bunked<<" classes"<<"\nYou can now bunk: "<<bunkable<<" classes\n\n"; 


}
void mark_absent()
{
    progress++;
    attendance = (float(attended)/progress)*100; 
    int bunked = progress-attended; 
    bunkable = bunkable - bunked; 
    if(bunkable<0)
    {
        cout<<"Well for subject: "<<subname<<endl<<"Bro you are cooked: Your attendance is: "<<attendance<<"\n You now have bunked: "<<bunked<<" classes"<<"\nYou have bunked: "<<-bunkable<<"extra classes \n\n"; 
    }
    else
        cout<<"Well for subject: "<<subname<<endl<<"Bro you are NOT cooked: Your attendance is: "<<attendance<<"you now have bunked: "<<bunked<<" classes"<<"\nYou can now bunk: "<<bunkable<<" classes\n\n"; 
}
};
sub dsa("Data Structures & Algorithms", 13);
sub dbms("Database Management Systems", 14);
sub oops("Object Oriented Programming", 12);
sub dld("Digital Logic Design", 15);
sub dms("Discrete Mathematics", 10);

sub subjects[5] = {dsa, dbms, oops, dld, dms};
string timetable[6][5] = {
    {"Monday",   "Tuesday",   "Wednesday",   "Thursday",   "Friday"},
    {"Data Structures & Algorithms", "Database Management Systems", "Object Oriented Programming", "Digital Logic Design", "Discrete Mathematics"},
    {"Database Management Systems",  "Object Oriented Programming", "Digital Logic Design",        "Discrete Mathematics", "Data Structures & Algorithms"},
    {"Object Oriented Programming",  "Digital Logic Design",        "Discrete Mathematics",        "Data Structures & Algorithms", "Database Management Systems"},
    {"Digital Logic Design",         "Discrete Mathematics",        "Data Structures & Algorithms","Database Management Systems", "Object Oriented Programming"},
    {"Discrete Mathematics",         "Data Structures & Algorithms","Database Management Systems", "Object Oriented Programming", "Digital Logic Design"}
};

class date
{
    public: 
    int dd; //1-Mon,2-Tues...5-Friday
    string day; 
    int day_marker; 

    date()
    {
        today++;
        dd = today; 
        if (dd%7==0)
        {
            day = "Sunday";
            day_marker = 7; 
        }
        else if(dd%6==0)
        {
            day = "Saturday";
            day_marker = 6; 
        }
        else if (dd%5 == 0)
        {
            day = "Friday";
            day_marker = 5; 
        }
        else if(dd%4==0)
        {
            day = "Thursday"; 
            day_marker = 4; 
        }
        else if (dd%3==0)
        {
            day = "Wednesday"; 
            day_marker = 3; 
        }
        else if(dd%2==0)
        {
            day = "Tuesday";
            day_marker = 2; 
        }
        else
        {
            day = "Monday";
            day_marker = 1; 
        }


    }

    void present(bool is_present)
    {
        if(is_present)
        {
            for (int i =1;i<=6;i++)
            {
                for(int j =0;j<5;j++)
                {
                    if(timetable[i][day_marker-1] == subjects[j].subname)
                    {
                        subjects[j].mark_present();
                    }

                }

            }

            
        }
        else
        {
            cout<<"Marked absent on date: "<<dd;
            for (int i =1;i<=6;i++)
            {
                for(int j =0;j<5;j++)
                {
                    if(timetable[i][day_marker-1] == subjects[j].subname)
                    {
                        subjects[j].mark_absent();
                    }

                }

            }
        }

    }
};

int main(void)
{
    for(int i =0;i<30;i++)
    {
        date d;
        cout<<"Hey Good morning!\nToday is: "<<d.day<<" and date is: "<<d.dd<<endl; 
        char presence; 
        cout<<"Are you present today (P/A): "; 
        cin>>presence; 
        if (presence =='P')
        {
            d.present(true); 
        }
        else
        {
            d.present(false);
        }
    }
    
}
