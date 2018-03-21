//make a notepad file in d drive and save the password you want to set t see the college result
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<iostream>
#include<string>
using namespace std;
fstream fout;
class stud
{
	string name;
	int roll;
	char grade;
	public:
		void password();  
		void how_to_use();
		void add_student();
		void college_result();   
		void student_account();       
		void display_1_screen(); 
		void best_3();
   }; 
    
    struct mrks
{ 
	char name[50];
	int reg;
	int cse_101[6];
	int cse_104[5];
	int ece_131[6];
	int ece_132[6];
	int mec_107[6];
	int mth_165[6];
	int che_110[6];
	int pel_121[6];
	float mark[8];
	float marks;
	float cgpa;
	//float cgpa;
} student;
 
void write()
{
	//ofstream fout;
	fout.open("D://Project.txt",ios::app|ios::out);
	fout.write((char*)&student,sizeof(student));
	fout.close();
}
void read_student()
{
	int i,sum=0;
	cout<<"\n\n\t\t\tstudent name : -\t\t"<<student.name;
	cout<<"\n\t\t\tReg No. : -\t\t\t"<<student.reg;
	 // cse - 101
	 cout<<"\n\ncse 101\t\t";  
	for(i=0;i<5;i++)
	{
	cout<<"\t"<<student.cse_101[i];      
	}// cse - 104
	cout<<"\ncse-104\t\t"; 
	for(i=0;i<5;i++)
	{
	cout<<"\t"<<student.cse_104[i];     
	}// ece - 131
	cout<<"\nece-131\t\t";
	for(i=0;i<4;i++)
	{
	cout<<"\t"<<student.ece_131[i];   
	}  // ece - 132
	cout<<"\nece-132\t\t"; 
	for(i=0;i<3;i++)
	{
	cout<<"\t"<<student.ece_132[i]; 
	}
	  // pel - 121 
	  cout<<"\npel-121\t\t";
	for(i=0;i<6;i++)
	{
	cout<<"\t"<<student.pel_121[i];
	}  // mec 107
	cout<<"\nmec 107\t\t";
	for(i=0;i<5;i++)
	{
	cout<<"\t"<<student.mec_107[i];
	}
	 // che - 110
	 cout<<"\nche-110\t\t"; 
	 for(i=0;i<3;i++)
	{
	cout<<"\t"<<student.che_110[i];
	}
	cout<<"\nmth 165\t\t";
	for(i=0;i<4;i++)
	{
	cout<<"\t"<<student.mth_165[i];
	}
	cout<<"\nstudent CGPA-\t\t"<<student.cgpa;	
    
}


void read()
{
	//ifstream fin;
	int count1,count2;
	fout.open("D://Project.txt",ios::in);
	if(fout.fail())
	cout<<"\n\t\t\tNO RECORD FOUND....\n\n\t\t\t";	
	while(!fout.eof())
	{ count1++;  
	    fflush(stdin);
		fout.read((char*)&student,sizeof(student));
	//	read_student();
	}
	fout.close();
	fout.open("D://Project.txt",ios::in);
	while(!fout.eof()&&(count2<count1))
	{  
	    count2++;  
	    fflush(stdin);
		fout.read((char*)&student,sizeof(student));
		read_student();
	}
	fout.close();
}
void total_marks()
{
	
	int i;
	float sum=0;
	float w1=0,w2=0,w3=0;
	 // cse - 101  
       for(i=0;i<5;i++)
	{
		if(i<3)
	   w1=(w1+student.cse_101[i]);  // working    
	    if(i==3)                                         
	     w2 = 0.025*25*(student.cse_101[i]);             
		  if(i>3)
		 w3 = 0.0142*50*(student.cse_101[i]);     
	}    
	student.mark[0] = (0.011*20*w1)+w2+w3;
	w1=0,w2=0,w3=0;
	// cse - 104 
	for(i=0;i<4;i++)
	{if(i<3)
	      w1=w1+student.cse_104[i];
	else if(i==3)
	      w2=55*0.01*student.cse_104[i]; 
		}
		student.mark[1]=(40*0.0067*w1)+w2;  // working
		
		// ece - 131
	w1=0,w2=0,w3=0;
	for(i=0;i<4;i++)
	{
		if(i<2)
	w1=w1+student.ece_131[i]; 
	    else if(i==3)
	w2=25*0.025*student.ece_131[i];                //working
	      else
	w3=50*0.01429*student.ece_131[i];	           
	}  
student.mark[2]=(20*w1*0.0167)+w2+w3;
	// ece - 132 

	w1=0;
	for(i=0;i<3;i++)
	{ 
	if(i<2)
	w1=w1+student.ece_132[i];  //        working 
	    if(i==2)
	w3=55*0.01*student.ece_132[i];	
	}  
	student.mark[3]=(20*w1*0.0167)+17+w3;

	  // pel - 121 
	w1=0,w2=0,w3=0;
	for(i=0;i<6;i++)
	{ 
    	 if(i<4)
	   w1=(w1+student.pel_121[i]); 	                                                                  
	    if(i==4)                                         
	     w2 = 0.02*15*(student.pel_121[i]);           //  working             
		  if(i==5)
		 w3 = 0.01*40*(student.pel_121[i]); 
		   
	  }  
	     student.mark[4]=(30*0.008334*w1)+w2+w3;
	     
	  // mec 107
		w1=0,w2=0,w3=0;
	for(i=0;i<4;i++)
	{
		if(i<2)
	w1=w1+student.mec_107[i]; 
	    if(i==2)
	w2=25*0.025*student.mec_107[i];             //working
	       if(i>2)
	w3=50*0.01429*student.mec_107[i];	       
	}  
	student.mark[5]=(20*w1*0.0167)+w2+w3;
	 // che - 110 
	w1=0,w2=0,w3=0;
	 for(i=0;i<3;i++)
	{ 
	   if(i==0)
	   w1=40*0.01*student.che_110[i];    //   working 
	   else if(i==1)
	   w2=20*0.025*student.che_110[i];
	   else 
	   w3=35*0.0142*student.che_110[i];
	}
	student.mark[6]=w1+w2+w3; 
	//mth
	w1=0,w2=0,w3=0;
	for(i=0;i<4;i++)
	{
		if(i<2)
	w1=w1+student.mth_165[i]; 
	    if(i==2)
	w2=25*0.025*student.mth_165[i];             //working
	       if(i>2)
	w3=50*0.01429*student.mth_165[i];	       
	}  
	student.mark[7]=(20*w1*0.0167)+w2+w3;
	student.marks=sum;
//*************************************************************************************************************
        // calculating CGPA
// cout<<"\nchecking...\n\n";
	sum=0;
    fflush(stdin);
	for(i=0;i<=7;i++)
	{   if(i==2||i==5||i==6||i==7)
		sum=sum+(4*(student.mark[i]));
		if(i==0||i==4)
		sum=sum+(3*(student.mark[i]));
		if(i==1||i==3)
		sum=sum+(1*(student.mark[i]));
	}
	student.cgpa=((sum/9)/240)*10;
//***************************************************************************************************************	
	write();


}

void cse_cse202()
{
 int a,i=0;	
 system("cls");
 cout<<"\n\n\n\t\t\tEnter your name\n\t\t\t";
 cin>>student.name;
 cout<<"\n\t\t\tEnter your reg No : -\n\t\t\t";
 cin>>student.reg;
 fflush(stdin);
 system("cls");
 cout<<"\n\t\tEnter your marks\n\t\tCSE-101\n\n\t\tCA-1"; 
    // cse **** 101 
  dx:
	cout<<"\n\t\t";
 cin>>student.cse_101[i];
 if(student.cse_101[i]>30||student.cse_101[i]<0)              //ca - 1 
 { 
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto dx;
} i++;
 cout<<"\n\t\tCA-2\n\t\t";
 gx:
 cin>>student.cse_101[i];;
 if(student.cse_101[i]>30||student.cse_101[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";          // ca - 2
 getch();
 goto gx;
} i++;
 cout<<"\n\t\tCA-3\n\t\t";
 dx2:
 cin>>student.cse_101[i];
 if(student.cse_101[i]>30||student.cse_101[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";         // ca - 3
 getch();
 goto dx2;
} i++;
 cout<<"\n\t\tCA-4\n\t\t";
  pf:
 cin>>student.cse_101[i];;
 if(student.cse_101[i]>40||student.cse_101[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";          // ca - 4 
 getch();
 goto pf;
 } i++;
 cout<<"\n\t\tMid Term Examination\n\t\t";
 mte:
 cin>>student.cse_101[i];;
 if(student.cse_101[i]>70||student.cse_101[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";           // MTE 
 
 getch();
 goto mte;
} i++;
 cout<<"\n\t\tEnd Term Examination( OBJECTIVE + THEORY )\n\t\t";   // ete 
 ete:
 cin>>student.cse_101[i];;
 if(student.cse_101[i]>70||student.cse_101[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto ete;
} i=0;

//ECE - 213

 cout<<"\n\t\tECE-131\n\n\t\tCA-1";                 //ca - 1
 d:
 	cout<<"\n\t\t";
 cin>>student.ece_131[i];
 if(student.ece_131[i]>30||student.ece_131[i]<0)
 { 
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto d;
} i++;
 cout<<"\n\t\tCA-2\n\t\t";
 g: 
 cin>>student.ece_131[i];
 if(student.ece_131[i]>30||student.ece_131[i]<0)                     // ca - 2 
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto g;
} i++;
 cout<<"\n\t\tCA-3\n\t\t";    
 w:
 cin>>student.ece_131[i];
 if(student.ece_131[i]>30||student.ece_131[i]<0)                   // ca - 3 
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto w;
} i++;
 cout<<"\n\t\tMid Term Examination\n\t\t";
 //**********************************************************************************************
 int q,j,temp; 
for(q=0;q<3;q++)
        {
          for(j=0;j<3-i;j++)
        {
          if(student.ece_131[j]>student.ece_131[j+1])
          {
            temp=student.ece_131[j];
            student.ece_131[j]=student.ece_131[j+1];
            student.ece_131[j+1]=temp;
          }
        }
   }
   i--;
 
 //**********************************************************************************************
 mt:
 cin>>student.ece_131[i];
 if(student.ece_131[i]>40||student.ece_131[i]<0)
 {
 cout<<"\n\t\t\student.ece_131Invalid Marks Please enter correct marks\n\t\t";   // mte 
 getch();
 goto mt;
}i++ ;
 cout<<"\n\t\tEnd Term Examination( OBJECTIVE + THEORY )\n\t\t";   
 et:
 cin>>student.ece_131[i];
 if(student.ece_131[i]>70||student.ece_131[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";       // ETE 
 getch();
 goto et;
}  i=0;               // initlizing the counter again with zero 

// MATH 165

cout<<"\n\t\tMATH-165\n\n\t\tCA-1";
 da:
 	cout<<"\n\t\t";
 cin>>student.mth_165[i];
 if(student.mth_165[i]>30||student.mth_165[i]<0)
 { 
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto da;
} i++;
 cout<<"\n\t\tCA-2";
 ga:
 cout<<"\n\t\t";	
 cin>>student.mth_165[i];
 if(student.mth_165[i]>30||student.mth_165[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto ga;
} i++;
 cout<<"\n\t\tCA-3\n\t\t";
 wa:
 cin>>student.mth_165[i];
 if(student.mth_165[i]>40||student.mth_165[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto wa;
}  i++;
//**********************************************************************************************
 
for(q=0;q<3;q++)
        {
          for(j=0;j<3-i;j++)
        {
          if(student.mth_165[j]>student.mth_165[j+1])
          {
            temp=student.mth_165[j];
            student.mth_165[j]=student.mth_165[j+1];
            student.mth_165[j+1]=temp;
          }
        }
   }
   i--;
 
 //**********************************************************************************************



 cout<<"\n\t\tMid Term Examination";
 cout<<"\n\t\t";
 m:
 cin>>student.mth_165[i];
 if(student.mth_165[i]>70||student.mth_165[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto m;
}i++;
 cout<<"\n\t\tEnd Term Examination( OBJECTIVE + THEORY )";
 e:
 cout<<"\n\t\t";
 cin>>student.mth_165[i];
 if(student.mth_165[i]>70||student.mth_165[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto e;
} i=0; 
//PEL - 121
cout<<"\n\t\tPEL -121\n\n\t\tCA-1";
 da1:
 	cout<<"\n\t\t";
 cin>>student.pel_121[i];
 if(student.pel_121[i]>30||student.pel_121[i]<0)
 { 
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto da1;
} i++;
 cout<<"\n\t\tCA-2\n\t\t";
 ga1:
 cin>>student.pel_121[i];
 if(student.pel_121[i]>30||student.pel_121[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto ga1;
} i++;
 cout<<"\n\t\tCA-3\n\t\t";
 wa1:
 cin>>student.pel_121[i];
 if(student.pel_121[i]>30||student.pel_121[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto wa1;
}i++;
cout<<"\n\t\tCA-4\n\t\t";
 pf1:
 cin>>student.pel_121[i];
 if(student.pel_121[i]>30||student.pel_121[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto pf1;
 } i++;

 cout<<"\n\t\tMid Term Examination";
 cout<<"\n\t\t";
 m1:
 cin>>student.pel_121[i];
 if(student.pel_121[i]>50||student.pel_121[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto m1;
}i++;
 cout<<"\n\t\tEnd Term Examination( OBJECTIVE + THEORY )";
 cout<<"\n\t\t";
 e1:
 cin>>student.pel_121[i];
 if(student.pel_121[i]>100||student.pel_121[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto e1;
}i=0;
   // MEC 
   
cout<<"\n\t\tMEC-166\n\n\t\tCA-1";
 da2:
 	cout<<"\n\t\t";
 cin>>student.mec_107[i];
 if(student.mec_107[i]>30||student.mec_107[i]<0)
 { 
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto da2;
}i++;
 cout<<"\n\t\tCA-2\n\t\t";
 ga2:
 cin>>student.mec_107[i];
 if(student.mec_107[i]>30||student.mec_107[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto ga2;
} i++;
 cout<<"\n\t\tCA-3\n\t\t";
 wa2:
 cin>>student.mec_107[i];
 if(student.mec_107[i]>40||student.mec_107[i]<0)
 {  
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto wa2;
} i++;
 cout<<"\n\t\tMid Term Examination";
 cout<<"\n\t\t";
 m2:
 cin>>student.mec_107[i];
 if(student.mec_107[i]>70||student.mec_107[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto m2;
} i++;
 cout<<"\n\t\tEnd Term Examination( OBJECTIVE + THEORY )";
 cout<<"\n\t\t";
 e2:
 cin>>student.mec_107[i];
 if(student.mec_107[i]>70||student.mec_107[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto e2;
}i=0;
   // ECE 132 LAB
   
  cout<<"\n\t\tECE-132\n\n\t\tWTP-1";
 da5:
 	cout<<"\n\t\t";
 cin>>student.ece_132[i];
 if(student.ece_132[i]>30||student.ece_132[i]<0)
 { 
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto da5;
}i++;
 cout<<"\n\t\tWTP-2\n\t\t";
 ga5:
 cin>>student.ece_132[i];
 if(student.ece_132[i]>30||student.ece_132[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto ga5;
} i++;
 cout<<"\n\t\tEnd Term Examination(THEORY+PRACTICAL+VIVA)";
 e91:
 	cout<<"\n\t\t";
 cin>>student.ece_132[i];
 if(student.ece_132[i]>100||student.ece_132[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto e91;
}i=0;
  // ENVIORMENTAL
  
  cout<<"\n\t\tCHE-110\n\n\t\tASSIGMENT WORK";
 da0:
 	cout<<"\n\t\t";
 cin>>student.che_110[i];
 if(student.che_110[i]>100||student.che_110[i]<0)
 { 
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto da0;
}i++;

cout<<"\n\n\tMid Term Examination";
  da7:
	cout<<"\n\t\t";
	cin>>student.che_110[i];
	if(student.che_110[i]>40||student.che_110[i]<0)
{
	cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
    getch();
    goto da7;
}i++;
	
 cout<<"\n\t\tEnd Term Examination( OBJECTIVE + THEORY )\n\t\t";
 e90:
 	cout<<"\n\t\t";
 cin>>student.che_110[i];
 if(student.che_110[i]>70||student.che_110[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto e90;
}i=0;
 //CSE 104
  cout<<"\n\t\tCSE-104\n\n\t\tLAB EVULATION-1";
 dax:
 	cout<<"\n\t\t";
	 cin>>student.cse_104[i];
 if(student.cse_104[i]>50||student.cse_104[i]<0)
 { 
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto dax;
}i++;
 cout<<"\n\t\tLAB EVULATION-2";
 cout<<"\n\t\t";
 gax:
 cin>>student.cse_104[i];
 if(student.cse_104[i]>50||student.cse_104[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto gax;
} i++;
 cout<<"\n\t\tLAB EVULATION-3";
 cout<<"\n\t\t";
 wax:
 cin>>student.cse_104[i];
 if(student.cse_104[i]>50||student.cse_104[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto wax;
}i++;
 cout<<"\n\t\tLAB EVULATION-4";
 cout<<"\n\t\t";
 pfx:
 cin>>student.cse_104[i];
 if(student.cse_104[i]>50||student.cse_104[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto pfx;
 } i++;
  cout<<"\n\t\tEnd Term Examination( OBJECTIVE + THEORY )";
  cout<<"\n\t\t";
  e9x:
 cin>>student.cse_104[i];
 if(student.cse_104[i]>100||student.cse_104[i]<0)
 {
 cout<<"\n\t\t\aInvalid Marks Please enter correct marks\n\t\t";
 getch();
 goto e9x;
}i=0;
cout<<"\n\t\tRECORD ADDED SUCCESSFULLY\n";
total_marks();
getch();
system("cls");
}
    
 void stud::password()
 {
    int i,j,k,l=1;
	char ch[10];
	ifstream fin;
	fin.open("D://password.txt",ios::in);
    fin>>ch;
	system("cls");
	printf("\n\t\t\tTHIS IS PASSWORD PROTECTED\n\t\t\tenter password\n\t\t\t");
	char df[500];
    for(i=0;i<i+1;i++)
 {  dx:
	df[i]=getch();
      l++; 
	if(df[i]==13)
	{  df[i]='\0';
       break;
}
       else if(df[i]==8)
       {
       	system("cls");
       	if(i>0)
       	i=i-1;
       	printf("\n\t\t\tTHIS IS PASSWORD PROTECTED\n\t\t\tenter password\n\t\t\t");
       	for(j=0;j<i;j++)
       	{  if(i<0)
		   printf(" "); 
		   printf("*");
		   }
       	goto dx;
	   }
	   printf("*");
	
 }  printf("\n");
	int count=0;
	for(i=0;i<5;i++)
	{
		if(ch[i]==df[i])
		count++;
	}
	if(count==5&&strlen(df)==strlen(ch))
	{
     cout<<"\n\t\t\tyou are authorised to view college results\n\a\n\t\t\tpress any key to view result......\n";
     getch();
     system("cls");
	}
	else
	{
		cout<<"\n\t\t\tINVALID PASSWORD\n\a";
		getch();
		system("cls");
		display_1_screen();
  }
	
}
    
 void stud::how_to_use()
 {
 	system("cls");
 	cout<<"\n\n\n\t\tTHIS SOFTWARE IS ABOUT ADDING NEW STUDENTS WITH HIS/HER MARKS TO OUR DATABASE\n\t\tBY USINNG OPTION 2 - 'ADD STUDENT'";
 	cout<<".BY USING OPTION 1 YOU  CAN FIND RESULT\n\t\tOF ANY STUDENT ENTERED IN OUR DATABASE.USING OPTION 3 - 'COLLEGE RESULT' YOU CAN \n";
 	cout<<"\t\tSEE RESULT OF WHOLE STUDENTS ENTERED IN OUR DATABASE(PASSWORD PROTECTED ONLY\n\t\tACCESSIABLE TO AUTHORISED PERSONALS)";
 	cout<<"PLZ GIVE US FEEDBACK ABOUT THIS SOFTWARE .\n\t\tHOPE YOU LIKE THIS APP\n";
	}   
 void stud::add_student()
 {  
    int i,j;
	string name ;
	system("cls");
 	cout<<"\n\n\n\t\tEnter student's name\n\n\t\t";
 	cin>>name;
 //	get_marks();
 
	}   

void stud::display_1_screen()
{
	int choice,j,k;
	//gotoxy(50,10);
	cout<<"\n\n\t\t\t\t\t\t\tLOVELY PROFESSIONAL UNIVERSITY";
	cout<<"\n\n\t\t\t1-Faculty account\n\n\t\t\t2-college result\n\n\t\t\t";
	cout<<"3-add student\n\n\t\t\t4-how to use this app\n\n\t\t\t5-EXIT\n\n\t\t\t";
	cin>>choice;
	if (choice==1)
	student_account();
	else if (choice==2)
	{
	password();	
 	read();
 	cout<<"\n\n\t\tPress any key return back Menu\n\t\t";
 	getch();
 	system("cls");
    display_1_screen();
 	
    }
	else if(choice == 3)
    {
	cse_cse202();
    cout<<"\n\n\t\tPress any key to return back menu\n\n\t\t";
	getch();
	system("cls");
	display_1_screen(); 
}
	else if(choice == 4)
	{
		char choice;
		dx:
	how_to_use();
	cout<<"\n\n\n\t\t want to go main menu (Y) for yes\n\n\t\t\t";
	cin>>choice;
	if(choice=='Y'||choice=='y')
	{
		system("cls");
		display_1_screen();
	}
	else 
	{
	cout<<"\a";
	goto dx;
	
	
   }
 }
     else if(choice==5)
     {
     	system("cls");
     	int i,j;
     	cout<<"\n\n\n\t\t\t\t\t\tSAVING YOUR DATA TO HARDDISK\n\n\n\n\t\t";
     	for(i=0;i<50;i++)
     	{   
     	   Sleep(40);
     	   cout<<"__";	
		 }
	   cout<<"\n\n\t\tpress any key to EXIT\n\n\n\t\t";
	   getch();
	   exit(0); 
	 }
}
void stud:: student_account()
{
	system("cls");
	int reg_no,a,b,choice,d;
    //ifstream fin ;
    //fout.open("D://Project.txt",ios::in);
	cout<<"\n\n\n\t\t1-marks/CGPA\n\n\t\t2-delete any record\n\n\t\t3-update any record\n\n\t\t";
    cin>>choice;
    if(choice == 1)
    {
    	cout<<"\n\n\t\tenter students regestration number\n\t\t";
    	cin>>reg_no;
    	fout.open("D://Project.txt",ios::in|ios::app);
    	while(fout.eof())
    {    
		fout.read((char*)&student,sizeof(student));
		if(student.reg==reg_no)		
        {
		read_student();
        cout<<"\n\n\t\tPress any key to return ...\n\t\t";
    	getch();
    	system("cls");
    	display_1_screen();
        fout.close();
	}
		else
		{
		cout<<"\n\n\t\tRecord not found\n\n\t\tPress any key to return...";
		getch();
		system("cls"); 
		display_1_screen();    
     }
   }
    
    fout.close();	
			}
	
	else if(choice == 2)
	{   
	    string user ;
		int  pass ; 
	    cout<<"\n\n\t\tThis is passord protected\n\n\t\t";
		cout<<"\n\t\tenter your username\n\t\t";
		cin>>user;
		cout<<"\n\n\t\tenter your password\n\t\t";
	    password();
		cout<<"\n\t\tUNDER CONSTRUCTION";
    	exit(0);
		cout<<"\n\n\t\tenter students regestration number\n";
    	cin>>reg_no;
	}
         
	else if(choice == 3)
	{
		string user;
		//int  password ;
		cout<<"\n\n\t\tThis is passord protected\n\n\t\t";
		cout<<"\n\t\tenter your username\n\t\t";
		cin>>user;
		cout<<"\n\n\t\tenter your password\n\t\t";
		password();
		cout<<"\n\t\tUNDER CONSTRUCTION";
    	exit(0);
		cout<<"\n\n\t\tenter students regestration number\n";
    	cin>>reg_no;
	}
}
int main()
{
	stud a1;
	a1.display_1_screen();
}
