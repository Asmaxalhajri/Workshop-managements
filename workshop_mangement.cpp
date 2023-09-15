

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;	
};
struct workshops
{string workshop_name;
string workshop_place;
string workshop_presenter;
string workshop_type;
string workshop_day;
Date workshop_date;
int workshop_time;
int number_of_seats;
};

struct student
{string names;
string id;
string phone;
string workshop_name;
string participation_type;
};
void print_file_workshop(workshops arr [],int numberOfItem);//print in file
void print_file_student(student arr [],int numberOfItem);//print in file
void add_workshop_file(workshops arr [],int size,int& numberOfItem );//add in file
void add_student_file(student arr [],int size,int & numberOfItem);//add in file
void add_workshop(workshops arr [],int size,int& numberOfItem );
void add_student(student arr [],int size,int & numberOfItem);
void print(workshops arr [],int size);//overloding
void print(student arr [],int size);//overloding
void sort_workshop(workshops arr [],int size,int  num_item );
void sort_student(student arr [],int size,int  num_item);
void delete_workshop(workshops d_arr [],int &numofitem,string w_name);
void delete_student(student d_arr [],int &numofitem,string s_id);
void update_student(student arr [],int &numofitem);
void update_workshop(workshops arr[],int &numofitem );
int search_workshop(workshops arr[], int size, string workshop_name);
int search_student(student arr[], int size, string student_id);
void print_a_workshop(workshops arr[], int size, int index);
void print_a_student(student arr[], int size, int index);
void statistic_record(int workshop_realsize, int student_realsize);
int count_add_student=0,count_add_workshop=0,count_update_student=0;
int count_update_workshop=0,count_sort_student=0,count_sort_workshop=0;
int count_search_student=0,count_search_workshop=0,count_delete_student=0;
int count_delete_workshop=0,count_print_workshop=0,count_print_student=0 ;

int main()
{

	cout<<" WELCOME TO WORK SHOP MANAGMENT \n";
	cout<<"___________________________________\n";
	 int size_student;
	 int size_workshop;
	 cout<<"Enter The maximum number of students that you will enter:";cin>>size_student;
	 cout<<"Enter The maximum number of workshop that you will enter:"; cin>>size_workshop;
	 
	student * stu_details;
	stu_details=new student[size_student];
	workshops * work_details;
	work_details= new workshops[size_workshop];
	
	int choice;
	bool Exit=false;
	int workshop_realsize=0;
	int student_realsize=0;
	char check;
	add_workshop_file(work_details,size_workshop,workshop_realsize );
	 add_student_file(stu_details,size_student,student_realsize);

	do
	{
cout<<"\nChoose the operation  from a menu as shown :\n 0.To Exit the program\n"
	<<" 1.To add workshops details or students' details for those who had booked seats"
	<<"\n 2.To search for workshop or  for student\n 3.To update workshop details or  students' details"
	<<"\n 4.To delete workshop or  student \n 5.To Sort workshop details or  students' details \n"
	<<" 6.To Display workshop details or  students' details.";
	cout<<"\n Enter your choice:";
	cin>>choice;

	switch (choice)
	{
		case 0:
		 Exit=true;
		 print_file_workshop(work_details,workshop_realsize);//print in file
          print_file_student(stu_details,student_realsize);//print in file
         break;
         case 1://add
         	{	
       		 cout<<"Do You want to add workshop press(W)or student details press (S).\n";cin>>check;
       		 if (check=='W' || check=='w')
       		 add_workshop(work_details,size_workshop,workshop_realsize );
       		 else if (check=='S' ||check=='s')
       		 add_student(stu_details,size_student,student_realsize);
        	 break;
         	}
         case 2://search
          	cout << "Do You want to search for  workshop press(W)or student details press (S)\n"; cin >> check;
			if (check == 'W' || check == 'w')
			{	string search_wordshop_name;
				cout << "Enter the name that you want to search his information" << endl;
				cin.ignore(30,'\n');getline(cin,search_wordshop_name);
				int found_workshop_index = search_workshop(work_details, workshop_realsize, search_wordshop_name);
				if (found_workshop_index >= 0)
					print_a_workshop(work_details, workshop_realsize, found_workshop_index);
				else
					cout << "There is no workshop in this name .\n";
					}
			else if (check == 'S' || check == 's') {
				string search_student_id;
				cout << "Enter the id that you want to search his information" << endl; cin >> search_student_id;
				int found_student_index = search_student(stu_details, student_realsize, search_student_id);
				if (found_student_index >= 0)
					print_a_student(stu_details, student_realsize, found_student_index);
				else
					cout << "There is no student like this id.\n";
			}
         break;
         case 3://update
			{
				cout<<"Do You want to update for  workshop press(W)or student details press (S)\n";cin>>check;
        			if (check=='w' || check=='W')  
						update_workshop(work_details, workshop_realsize );
	   					
       			 else if (check=='s' || check=='S')
						update_student(stu_details,student_realsize);
			}
         break;
         case 4://delete
		 {
         	string w_name;
         	string s_id;
        cout<<"Do You want to delete workshop press(W)or student  press (S)\n";cin>>check;
       		 if (check=='W' || check=='w')
					{
			if(workshop_realsize>0)
				 {	
       				 cout<<"Enter the name of the workshop you want to delete:\n"<<endl;
						cin.ignore(30,'\n');getline(cin,w_name);
        				delete_workshop(work_details,workshop_realsize,w_name);
        		 }
        	 else
        		 cout<<"The is no workshop to delete.\n";
       			 }
       	 else if (check=='S' || check=='s')
       		 {	if(student_realsize>0)
        		{	
				cout<<"Enter the id of the student you want to delete:"<<endl;cin>>s_id;
       			 delete_student(stu_details,student_realsize,s_id);
                }
                else
                cout<<"The is no student to delete.";
        }
        break;
    }
         case 5://sort
		 	
        	cout<<"Do you want to sort workshop by number of seats press(W) or sort student name press (S)\n";cin>>check;
        	if (check=='W' || check=='w')
        		sort_workshop(work_details,size_workshop,workshop_realsize);
       		 else if (check=='S' || check=='s')
       		 	sort_student(stu_details,size_student,student_realsize);
         break;
         case 6: //print
			 cout<<"Do You want to display workshop press(W)or student details press (S) or both (B)\n";
			 cin>>check;
			 if (check=='W' || check=='w')
              print(work_details,workshop_realsize);

              else if (check=='S' || check=='s')
              print(stu_details,student_realsize);
              else
              { print(work_details,workshop_realsize);
                print(stu_details,student_realsize);
			  }
        break;
         default:
                cout<<"You entered wrong number!";
	}
 }while(!Exit);
 
 string stat;
 cout<<"Do you want to record the statctic for tody (yes ,no)"<<endl;
 cin>>stat;
 if(stat=="yes"||stat=="YES"||stat=="Yes")
 {
 	statistic_record(workshop_realsize , student_realsize);	
 }
 else if(stat=="no"||stat=="NO"||stat=="No")
 {
 	cout<<"Thanks";
 }
 
	delete []stu_details;
	delete []work_details;
	stu_details=NULL;
	work_details=NULL;
return 0;}

//functions:

//add in work file
void add_workshop_file( workshops arr[],int size,int& numberOfItem )
{ifstream inwork;
inwork.open("work.txt",ios::in);

if(numberOfItem<size && inwork.is_open()){
	while(inwork)
	{
    getline(inwork,arr[numberOfItem].workshop_name,'\n');
    getline(inwork,arr[numberOfItem].workshop_place,'\n') ;
	getline(inwork,arr[numberOfItem].workshop_presenter,'\n') ;
	getline(inwork,arr[numberOfItem].workshop_type,'\n');
    getline(inwork,arr[numberOfItem].workshop_day,'\n');
	inwork>>arr[numberOfItem].workshop_date.day;inwork.ignore(2,'/');
	inwork>>arr[numberOfItem].workshop_date.month;inwork.ignore(2,'/') ;
	inwork>>arr[numberOfItem].workshop_date.year;inwork.ignore(4,'\n');
	inwork>>arr[numberOfItem].workshop_time;inwork.ignore(2,'\n');
	inwork>>arr[numberOfItem].number_of_seats;inwork.ignore();
numberOfItem++;
if(inwork.eof())
		break;
}
}
	inwork.close();
}

//add in file student
void add_student_file(student arr [],int size,int & numberOfItem)
{
	ifstream instudent;
	instudent.open("student.txt",ios::in);
	if(numberOfItem<size && instudent.is_open())
	{
		while(instudent)
	{
		getline(instudent,arr[numberOfItem].names,'\n') ;
		getline(instudent,arr[numberOfItem].id,'\n');
		getline(instudent,arr[numberOfItem].phone,'\n');
		getline(instudent,arr[numberOfItem].workshop_name,'\n');
		getline(instudent,arr[numberOfItem].participation_type,'\n');
		
	numberOfItem++;
	if(instudent.eof())
		break;
	}}
		instudent.close();
	}

//print in file workshop
void print_file_workshop(workshops arr [],int numberOfItem)
{
ofstream outwork;
outwork.open("work.txt",ios::out);
if(outwork.is_open()){
 for(int i=0;i<numberOfItem ;i++)
  {
   outwork<<arr[i].workshop_name<<"\n";
   outwork<<arr[i].workshop_place<<"\n";
   outwork<<arr[i].workshop_presenter<<"\n";
   outwork<<arr[i].workshop_type<<"\n";
   outwork<<arr[i].workshop_day<<"\n";
   outwork<<arr[i].workshop_date.day<<"/"<<arr[i].workshop_date.month<<"/"<<arr[i].workshop_date.year<<"\n";
   outwork<<arr[i].workshop_time<<"\n";
   outwork<<arr[i].number_of_seats<<"\n";
   
  }
  
}
else
cout<<"The file does not open \n";
  
  outwork.close();
}

//print in file student
void print_file_student(student arr [],int numberOfItem)
{ofstream outstudent;
outstudent.open("student.txt",ios::out);
if(outstudent.is_open())
{
	for(int i=0;i<numberOfItem;i++)
  {
  	outstudent<<arr[i].names<<"\n";
  	outstudent<<arr[i].id<<"\n";
  	outstudent<<arr[i].phone<<"\n";
  	outstudent<<arr[i].workshop_name<<"\n";
  	outstudent<<arr[i].participation_type<<"\n";
    }
 
}
else
cout<<"The file does not open \n";
outstudent.close();
}


void add_workshop( workshops arr[],int size,int& numberOfItem )
{
if(numberOfItem<size)
{
	cout<<"\n Enter workshop name :";cin.ignore(20,'\n');getline(cin,arr[numberOfItem].workshop_name);
	cout<<"\n Enter workshop place :";getline(cin,arr[numberOfItem].workshop_place) ;
	cout<<"\n Enter workshop presenter :"; getline(cin,arr[numberOfItem].workshop_presenter) ;
	cout<<"\n Enter workshop type :";getline(cin,arr[numberOfItem].workshop_type);
	cout<<"\n Enter workshop day:";getline(cin,arr[numberOfItem].workshop_day);
	cout<<"\n Enter workshop date (day/ month/ year) :";
	cin>>arr[numberOfItem].workshop_date.day;cin.ignore(2,'/');
	cin>>arr[numberOfItem].workshop_date.month;cin.ignore(2,'/');
	cin>>arr[numberOfItem].workshop_date.year;cin.ignore(2,'\n');
	cout<<"\n Enter workshop time:";cin>>arr[numberOfItem].workshop_time;
	cout<<"\n Enter workshop number of seats :";cin>>arr[numberOfItem].number_of_seats;
	
	numberOfItem++;
}
count_add_workshop++;
}

void add_student(student arr [],int size,int & numberOfItem)
{

	int ch;
	if(numberOfItem<size )
	{
		cout<<"\n Enter students name:";cin.ignore(20,'\n');getline(cin,arr[numberOfItem].names,'\n');
		cout<<"\n Enter students ID:";getline(cin,arr[numberOfItem].id);cin.ignore(10,'\n');
		cout<<"\n Enter students phone:";getline(cin,arr[numberOfItem].phone);cin.ignore(10,'\n');
		cout<<"\n Enter workshop name:";getline(cin,arr[numberOfItem].workshop_name);cin.ignore(20,'\n');
		cout<<"\n Enter participation type (1)attendee (2)co-presenter:";cin>>ch;
		if(ch==1)
		arr[numberOfItem].participation_type="attendee";
		else
		arr[numberOfItem].participation_type="co-presenter";
		numberOfItem++;
	}
	count_add_student++;
}

void print(workshops arr [],int size)
{
 for(int i=0;i<size ;i++)
  {cout<<"\n Workshop #"<<i+1;
   cout<<"\n  Workshop name: "<<arr[i].workshop_name;
   cout<<"\n  Workshop place: "<<arr[i].workshop_place;
   cout<<"\n  Workshop presenter: "<<arr[i].workshop_presenter;
   cout<<"\n  Workshop type: "<<arr[i].workshop_type;
   cout<<"\n  Workshop day: "<<arr[i].workshop_day;
   cout<<"\n  Workshop date (day/month/year): "<<arr[i].workshop_date.day<<"/"<<arr[i].workshop_date.month<<"/"<<arr[i].workshop_date.year;
   cout<<"\n  Workshop time: "<<arr[i].workshop_time;
   cout<<"\n  Workshop number of seats: "<<arr[i].number_of_seats;
   
  }
  cout<<endl;
  count_print_workshop++;
}
void print(student arr [],int size)
{
	for(int i=0;i<size;i++)
  { cout<<"\n Student #"<<i+1;
  	cout<<"\n Students name: "<<arr[i].names;
  	cout<<"\n ID: "<<arr[i].id;
  	cout<<"\n Phone number: "<<arr[i].phone;
  	cout<<"\n Workshop name: "<<arr[i].workshop_name;
  	cout<<"\n Participation type: "<<arr[i].participation_type;
    }
  cout<<endl;
  count_print_student++;
}


void delete_workshop(workshops d_arr[],int &numofitem,string w_name)
{
	int i,j;
	for (i=0;i<numofitem;i++)
	{
		if(d_arr[i].workshop_name==w_name)
		{
			for(j=i;j<numofitem-1;j++)
			{
			d_arr[j]=d_arr[j+1];	
			}
			numofitem--;
			cout<<"Number of workshops now is :"<<numofitem;
			break;
		}
	}
	count_delete_workshop++;	
}

void delete_student(student d_arr[],int &numofitem,string s_id)
{
	int i,j;
	for (i=0;i<numofitem;i++)
	{
		if(d_arr[i].id==s_id)
		{
			for(j=i;j<numofitem-1;j++)
			{
			d_arr[j]=d_arr[j+1];	
			}
			numofitem--;
			cout<<"Number of student now is :"<<numofitem;
			break;
		}
	}
		count_delete_student++;
}


void sort_workshop(workshops arr [],int size,int num_item )
{
int i, j;
for (i =0; i <num_item-1; i++)
for (j =0; j<num_item-1; j++)
	if (arr[j].number_of_seats >arr[j+1].number_of_seats )
	{
		workshops temp=arr[j];
		arr[j]= arr[j+1];
		arr[j+1] = temp;
	}
	cout<<"The sorting workshops was completed successfully\n";
	count_sort_workshop++;	
}

void sort_student(student arr [],int size,int num_item)
{
int i, j;
for (i =0; i <num_item-1; i++)
for (j =0; j<num_item-1; j++)
	if(arr[j].names.compare(arr[j+1].names)>0)
	{
		student temp = arr[j];
		arr[j]= arr[j+1];
		arr[j+1] = temp;
	}
	count_sort_student++;
	cout<<"The sorting student was completed successfully\n";		
}



void update_workshop(workshops arr[],int &numofitem ){
	bool found=false;
	string update_name;
 cout<<"Enter the name that you want to update his information"<<endl;
	cin.ignore(30,'\n');getline(cin,update_name);
	for(int i=0;i<numofitem;i++){
			if(update_name.compare(arr[i].workshop_name)==0)
			{
				found=true;
			}
		}
	
				if(found==true){
				cout<<"\n Enter workshop name :";getline(cin,arr[numofitem].workshop_name);cin.ignore(30,'\n') ;
            	cout<<"\n Enter workshop place :";getline(cin,arr[numofitem].workshop_place);cin.ignore(30,'\n') ;
            	cout<<"\n Enter workshop presenter :";getline(cin,arr[numofitem].workshop_presenter);cin.ignore(30,'\n') ;
            	cout<<"\n Enter workshop type :";getline(cin,arr[numofitem].workshop_type);cin.ignore(30,'\n') ;
            	cout<<"\n Enter workshop day:";cin>>arr[numofitem].workshop_day;
            	cout<<"\n Enter workshop date (day/month/year) :";
                cin>>arr[numofitem].workshop_date.day;cin.ignore(2,'/');
            	cin>>arr[numofitem].workshop_date.month;cin.ignore(2,'/');
            	cin>>arr[numofitem].workshop_date.year;cin.ignore(2,'\n');
            	cout<<"\n Enter workshop time:";cin>>arr[numofitem].workshop_time;
            	cout<<"\n Enter workshop number of seats :";cin>>arr[numofitem].number_of_seats;	
		}
			else
			cout<<"not found";
				
		

	count_update_workshop++;
}

void update_student(student arr [],int &numofitem){
		bool found_s=false;
		int ch;
		string id_u;
 cout<<"Enter ID that you want to update his information"<<endl;
	cin>>id_u;
	for(int i=0;i<numofitem;i++){
			if(id_u.compare(arr[i].id)==0)
			{
				found_s=true;
	}
	
	}
	if(found_s==true){
		cout<<"\n Enter students name:";getline(cin,arr[numofitem].names);cin.ignore(30,'\n') ;
		cout<<"\n Enter students ID:";cin>>arr[numofitem].id;
		cout<<"\n Enter students phone:";cin>>arr[numofitem].phone;
		cout<<"\n Enter workshop name:";cin.ignore(30,'\n') ;getline(cin,arr[numofitem].workshop_name);
		cout<<"\n Enter participation type (1)attendee (2)co-presenter:";cin>>ch;
		if(ch==1)
			arr[numofitem].participation_type="attendee";
		else
			arr[numofitem].participation_type="co-presenter";	
	}		
	else
		cout<<"not found!";
count_update_student++;
} 



int search_workshop(workshops arr[], int size, string workshop_name)
{
	count_search_workshop++;
	for (int i = 0; i < size; i++)
	if (arr[i].workshop_name==workshop_name) return i;
	return -1;
	
}

int search_student(student arr[], int size, string student_id)
{
	count_search_student++;
	for (int i = 0; i < size; i++)
		if (arr[i].id == student_id)return i;
	return -1;
	
}

void print_a_workshop(workshops arr[], int size, int index)
{
	if (index < 0 || index >= size)return;
	cout << "\n Workshop #" << index + 1;
	cout << "\n  Workshop name: " << arr[index].workshop_name;
	cout << "\n  Workshop place: " << arr[index].workshop_place;
	cout << "\n  Workshop presenter: " << arr[index].workshop_presenter;
	cout << "\n  Workshop type: " << arr[index].workshop_type;
	cout << "\n  Workshop day: " << arr[index].workshop_day;
	cout << "\n  Workshop date (day/month/year): " << arr[index].workshop_date.day << "/" << arr[index].workshop_date.month << "/" << arr[index].workshop_date.year;
	cout << "\n  Workshop time: " << arr[index].workshop_time;
	cout << "\n  Workshop number of seats: " << arr[index].number_of_seats;
	cout << "\n\n";
	
}

void print_a_student(student arr[], int size, int index)
{
	if (index < 0 || index >= size)return;
	cout << "\n Student #" << index + 1;
	cout << "\n Students name: " << arr[index].names;
	cout << "\n ID: " << arr[index].id;
	cout << "\n Phone number: " << arr[index].phone;
	cout << "\n Workshop name: " << arr[index].workshop_name;
	cout << "\n Participation type: " << arr[index].participation_type;
	cout << "\n\n";

}


void statistic_record(int workshop_realsize, int student_realsize){
 	string day;
 	int day_num,month,year;
 	ofstream statistic;
 	statistic.open("statistic.txt",ios::out);
 	if(statistic.is_open()==true)
	 {
 		cout<<" file is opened successfully"<<endl;
 		cout<<"enter the day"<<endl;
 		cin>>day;
 		cout<<"enter the date (day,month,year)"<<endl;
 		cin>>day_num>>month>>year;
 		statistic<<endl;
 		statistic<<" date :";
 		statistic<<endl;
 		statistic<<day<<endl;
 		statistic<<day_num<<"/"<<month<<"/"<<year<<endl;
 		statistic<<"the statistic is:"<<endl;
 		statistic<<"#Nummber of enter the information for student is: "<<count_add_student<<endl;
         statistic<<"#Nummber of enter the information for workshop is: "<<count_add_workshop<<endl;
         statistic<<"#Nummber of update the information for student is: "<<count_update_student<<endl;
         statistic<<"#Nummber of update the information for workshop is: "<<count_update_workshop<<endl;
         statistic<<"#Nummber of sort the information for student is: "<<count_sort_student<<endl;
         statistic<<"#Nummber of sort the information for workshop is: "<<count_sort_workshop<<endl;
         statistic<<"#Nummber of search the information for student is: "<<count_search_student<<endl;
	     statistic<<"#Nummber of search the information for workshop is: "<<count_search_workshop<<endl;
	     statistic<<"#Nummber of Delete the information for student is: "<<count_delete_student<<endl;
		 statistic<<"#Nummber of Delete the information for workshop is: "<<count_delete_workshop<<endl;
		 statistic<<"#Nummber of print the information for student is: "<<count_print_student<<endl;
		 statistic<<"#Nummber of print the information for workshop is: "<<count_print_workshop<<endl;
		 statistic<<"#Nummber of  information in workshops is: "<<workshop_realsize<<endl;
		 statistic<<"#Nummber of  information for studens is: "<<student_realsize<<endl;
		 statistic.close();
 		
	 }
	 else
	 	cout<<"Failed";    
	 }
           



