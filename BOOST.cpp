#include<bits/stdc++.h>

using namespace std;

class boost
{
	int player[4][4];
	string name[4];
	public:
		void start();
		void getinfo();
		void shuffle();
		void game();
		void display(int i);
		void conv(int num);
		void change(int i,int num);
		int winchk(int i);
		
		
};




void boost::start()
{
	cout<<"\n\t\t*************************\n\t\t\tBOOST ARENA\n\t\t*************************";
	cout<<"\n\nWELCOME TO BOOST ARENA\n\nABOUT BOOST :-\n\nTHERE ARE TOTAL FOUR PLAYERS.\nTHREE RANDOM CARDS WILL BE GIVEN TO EACH.\nTHE CARDS NAME WILL BE ROSE, JASMINE, LILY, LOTUS.\nYOUR JOB IS TO MAKE THAT ALL CARDS SAME\nBY SWAPING THE CARDS WITH THE PLAYER NEXT TO YOU ONE BY ONE.\n\n\tALRIGHT LET'S GET STARTED.\n\tARE YOU READY?";
	cout<<"\n\tPRESS ENTER TO START";
	cin.get();
	getinfo();
}




void boost::getinfo()
{
	system("cls");
	cout<<"\n\t\t*************************\n\t\t\tBOOST ARENA\n\t\t*************************"<<endl;
	int i=1;
	while(i<=4)
	{
		cout<<"\nPLAYER "<<i<<" ENTER YOUR NAME : ";
		cin>>name[i-1];
		i++;
	}
	
	cout<<"\n\nALL SET LET'S MOVE TO THE GAME";
	cin.ignore();
	cin.get();
	shuffle();
	game();
}




void boost::shuffle()
{
	system("cls");
	int a[12]={1,1,1,2,2,2,3,3,3,4,4,4};
	int t1=4, idx1=0, idx2=0, t2, r;
	while(t1--)
	{
		t2=3;
		idx2=0;
		srand(time(NULL));
		while(t2--)
		{
			do
			{
				r=rand()%12;
				
			}while(a[r]==0);
			
			player[idx1][idx2]=a[r];
			
			a[r]=0;
			
			idx2++;
		}
		
		idx1++;
		
	}
	player[1][3]=0;
}



void boost::game()
{
	int i=0, num, win=-1;
	do
	{
		
	system("cls");
	cout<<"\n\t\t*************************\n\t\t\tBOOST ARENA\n\t\t*************************";
	
		cout<<endl<<name[i]<<" IT'S YOUR TURN. PRESS ENTER TO SEE YOUR CARDS.\nMAKE SURE OTHERS NOT SEEING YOUR YOUR CARDS\n";
		
		cin.ignore();
		cin.get();
		
		display(i);
		
		cout<<"\nENTER THE CARD NUMBER YOU ARE GOING TO SWAP : ";
		cin>>num;
		while( (player[i][num-1]==0) || num>4 || num<0 )
		{
			cout<<"\n** INVALID CHOICE **";
			cout<<"\n\nENTER A VALID CHOICE : ";
			cin>>num;
		}
		
		change(i , num);
		
		win=winchk(i);
		
		i=i==3?0:i+1;
		
	}while(win);
		
}




void boost::display(int i)
{
	system("cls");
	cout<<"\n\t\t*************************\n\t\t\tBOOST ARENA\n\t\t*************************";
	cout<<"\n\n*********************************************************\n*             *             *             *             *\n";
	
	cout<<"*";
	conv(player[i][0]);
	cout<<"*";
	conv(player[i][1]);
	cout<<"*";
	conv(player[i][2]);
	cout<<"*";
	conv(player[i][3]);
	cout<<"*";
	cout<<"\n*             *             *             *             *\n***** 1 *********** 2 *********** 3 ************* 4 *****\n";
	
}




void boost::conv(int num)
{
	switch(num)
	{
		case 1:
			cout<<"   JASMINE   ";break;
		case 2:
			cout<<"     ROSE    ";break;
		case 3:
			cout<<"     LILY    ";break;
		case 4:
			cout<<"     LOTUS   ";break;
		default:
			cout<<"       -     ";break;
	}
}



void boost::change(int i,int num)
{
	int idx=i==3?0:i+1;
	
	player[idx][3]=player[i][num-1];
	
	player[i][num-1]=player[i][3];
	
	player[i][3]=0;
	
}



int boost::winchk(int i)
{
	if(player[i][0]==player[i][1] && player[i][1]==player[i][2] )
	{
		system("cls");
		
		cout<<"\n\t\t*************************\n\t\t\tBOOST ARENA\n\t\t*************************";
		
		cout<<"\n\n\n\t\t-------------------------\n\t\t\t"<<name[i]<<"\n\t\t    YOU WON THE MATCH\n\t\t-------------------------";
		
		return 0;
	}
	else
	{
		return 1;
	}
	
}

int main()
{
	boost a;
	a.start();
}

