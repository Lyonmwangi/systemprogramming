#include<windows.h>
#include<iostream>
#include<time.h>
#include<fstream>
#include<cstdlib>
#include <dirent.h>
using namespace std;
int main()
{
	int j;
		cout<<"tasks that can be performed under Information Maintainance include :\n";
		cout<<"**********************************************************\n";
		cout<<"1. Get files in the computer\n";
		cout<<"2. Sleep a process and get its sleep time\n";
		cout<<"3. Get current process ID in a sublime text\n";
		cout<<"4. Get system date\n";
		cout<<"**********************************************************\n";
		cout<<"which is your choice?\n";
		cin>>j;
				
			
			
			switch(j)
		{
			case 1:
			{
				
		
				struct dirent *de;  // Pointer for directory entry 
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir("."); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
        return 0; 
    } 
  
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
    // for readdir() 
    while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name); 
  
    closedir(dr);
    			};
 			break;
		
		  case 2:
		    {
				//FILETIME ftime,fsys,fuser;
				SYSTEMTIME stime;
			// how the sleep() function works
			int i,i2;
			 GetSystemTime(&stime);
		
			
			i=stime.wSecond;
			std::cout<<"\nTime before sleeping:"<<i;
		    Sleep(2000);// 2sec=2000 millisecs;
		    GetSystemTime(&stime);

		    i2=stime.wSecond;
		     std::cout<<"\nTime after sleeping:"<<i2;
			std::cout<<"\nThe program sleep time is :"<<i2-i<<endl<<endl;
			getchar() ;//in milliseconds

			
		   };
		   break; 
	   	case 3:
			{
				DWORD id=GetCurrentProcessId();//the getCurrentprocessid ()  takes no  parameter
				char buf[sizeof(DWORD)*8+1];
				ulltoa(id,buf,2);
				ofstream f("D:\abi.txt");
				f<<id;
				cout<<id<<endl;
		   }; 
		   break;
		  
	   case 4:
	   {
	   	time_t now = time(0);
				char * dt = ctime(&now);
				cout << dt;
	   }
	  	   break;
	   
	   
}
			
		//	{break;	};
		
		int x;
			

do{
	cout<<" DO YOU WANT TO CONTINUE? \n\t";
	cout<<"1.Yes\n\t";
	cout<<"2.No";
	cout<<"\n\t";
	cin>>x;
	
	if (x==1){
		 main();
	}
}
while (x == 1);
	
/*	
	else if(x==2){
		exit(0);
				
	} else {|
		cout<<"Invalid choice, Choose again";
		 main();
		

	}
*/	
}	

