
// only quick sort is remaining
//objectives of assignment - 
// a) Implemented in the display function.
// b)remaining (insertion sort)
// c)remaining (quick sort)
// d)remaining (Display student list according to sgpa)
// e)Implemented in searching
#include<iostream>
#include<string.h>
using namespace std;

struct Student{
char Sname[10];
int SRoll;
float sgpa;
};
void Sort_rollno(int size, struct Student* array)// uses bubble sort

{   int temp;
    for(int i = 1;i<size;i++)
    {
        for(int k=0;k<size-i;k++)
        {
            if(array[k+1].SRoll<array[k].SRoll)
            {
                temp = array[k+1].SRoll;
                array[k+1].SRoll = array[k].SRoll;
                array[k].SRoll = temp;
            }
        }
    }
}
void Sort_sgpa(int size, struct Student* array)// uses bubble sort

{   int temp;
    for(int i = 1;i<size;i++)
    {
        for(int k=0;k<size-i;k++)
        {
            if(array[k+1].sgpa>array[k].sgpa)
            {
                temp = array[k+1].sgpa;
                array[k+1].sgpa = array[k].sgpa;
                array[k].sgpa = temp;
            }
        }
    }
}
class Student_details // this class has methods to search by name using linear search and search by roll no using binary search
{
public:
	struct Student s[10];
	int n = 0,c;              // how many students data entered
public:
	void InsertData();
	void Display();
	void Search_name(char array[10])// uses linear search
	{	int k, i;
		for(i=0; i <n + c;i++)
		{
			k = strcmp(s[i].Sname, array);
			if(k == 0)
			{
				cout<<"key "<<array<<" found at "<<i + 1<<endl;
				cout<<"Details of student Searched - \nName = "<<s[i].Sname<<"\nRoll no = "<<s[i].SRoll<<endl; 
				break;
			}

		}
		if(i == n)
		{
			cout<<"key \""<<array<<"\" not found"<<endl;
		}
	}
	void Search_rollno(int roll)// uses binary search
	{
		Sort_rollno(n+c,s);
		static int left = 0, right = c,mid = (left + right)/2,found = 0;
		// cout<<"In the roll no search"<<endl;
		// cout<<left<<" ,"<<right<<endl;
		while(left < right)
		{
			if(s[mid].SRoll > roll)
			{
				right = mid - 1;
				mid = (left + right)/2;
				// cout<<" in s[mid].SRoll > roll "<<endl;
			}
			else if (s[mid].SRoll < roll)
			{
				left = mid + 1;
				mid = (left + right)/2;
				// cout<<"s[mid].SRoll < roll"<<endl;
			}
			else
			{
				cout<<"Roll no - "<<roll<<" found at "<<mid + 1<<" position!"<<endl;
				cout<<"Details of student Searched - \nName = "<<s[mid].Sname<<"\nRoll no = "<<s[mid].SRoll<<endl;
				found = 1; 
				break;
			}
		}
			if(found ==0)
			{
				cout<<"Entered roll no "<<roll<<" not found!";
			}
	}
};


void Student_details::InsertData()
{
	int i;
	cout<<"Enter number of students to be added";
	cin>>c;

	for (i=n;i<n+c;i++)
	{
		cout<<"Enter name  "<< i+1;
		cin>> s[i].Sname;
		cout<<"Enter Roll number ";
		cin>> s[i].SRoll;
		cout<<"Enter sgpa ";
		cin>> s[i].sgpa;
	  }
	n=n+c;      // update number of students
};

void Student_details::Display()
{
	int i;
	cout<<"\n";
	for (i=0;i<n;i++){
	// 	Sort_rollno(n, s);
		cout<<"name - \t";
		cout<< s[i].Sname<<"\t";
		cout<<"Roll number - \t\t";
		cout<<s[i].SRoll;
		cout<<"\tSgpa - ";
		cout<<s[i].sgpa<<endl;
	  }
};

int main()
{
	Student_details Sclass;char name[10];int k,roll_no;
	Sclass.InsertData();
	Sort_rollno(Sclass.c, Sclass.s);
	Sclass.Display();
	cout<<"Enter - 1)to search by name\t2)to search by roll no.\t3)list sorted wrt sgpa";
	cin>>k;
	switch (k)
	{
	case 1:
		cout<<"Enter a name to search - "<<endl;
		cin>>name;
		Sclass.Search_name(name);
		break;
	case 2:
		cout<<"Enter a roll no to search - "<<endl;
		cin>>roll_no;
		Sclass.Search_rollno(roll_no);
		cin>>roll_no;
	case 3:
		cout<<"Sorted wrt to sgpa - ";
		Sort_sgpa(Sclass.c, Sclass.s);
		Sclass.Display();
		
	default:
		break;
	}
	
   // cin>> s[2].name ;

    return 0;
}
