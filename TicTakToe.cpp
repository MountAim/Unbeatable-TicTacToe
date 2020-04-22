#include <bits/stdc++.h>
#include<windows.h>
#define clrscr() system("cls");
using namespace std;
void gotoxy(int x, int y);
const int space=45,new_ln=10,delay=501;

vector<vector<char>> ar(4,vector<char> (4));

/*Tic Tac Toe is a 4 Move GAME the first four move can decide the result*/

void end()
{
	char s;
	cin>>s;
	if((s=='y')||(s=='Y'))	;
	else exit(0);	
}

void player()
{
	clrscr();
	for(int i=0;i<5;++i)	cout<<"\n";
	for(int i=0;i<space-8;++i)	cout<<" ";
	cout<<"-----        -----          -----   _   \n";
	for(int i=0;i<space-8;++i)	cout<<" ";
	cout<<"  |  .  __     |  _    __     |  _ |_  \n";
	for(int i=0;i<space-8;++i)	cout<<" ";
	cout<<"  |  | |__     | |_|_ |__     | |_||_ \n\n";
	for(int i=0;i<space-8;++i)	cout<<" ";
	cout<<"                    by Siddharth Singhal";
	for(int i=0;i<5;++i)	cout<<"\n";
	for(int i=0;i<space;++i)	cout<<" ";
	cout<<"   1   2   3 \n";
	for(int i=0;i<space;++i)	cout<<" ";
	cout<<"1  "<<ar[1][1]<<" | "<<ar[1][2]<<" | "<<ar[1][3]<<" \n";
	for(int i=0;i<space;++i)	cout<<" ";
	cout<<"  ---|---|---\n";
	for(int i=0;i<space;++i)	cout<<" ";
	cout<<"2  "<<ar[2][1]<<" | "<<ar[2][2]<<" | "<<ar[2][3]<<" \n";
	for(int i=0;i<space;++i)	cout<<" ";
	cout<<"  ---|---|---\n";
	for(int i=0;i<space;++i)	cout<<" ";
	cout<<"3  "<<ar[3][1]<<" | "<<ar[3][2]<<" | "<<ar[3][3]<<" \n";
}

void computer()
{
	clrscr();
	int cnt,pos;
	for(int i=1;i<=3;++i)
	{
		cnt=0,pos=0;
		for(int j=1;j<=3;++j)
		{
			if(ar[i][j]==' ')	pos=j;
			else if(ar[i][j]=='x')	++cnt;			
		}
		if((cnt==2)&&(pos))
		{
			ar[i][pos]='x';
			player();
			cout<<"\n";
			for(int i=0;i<space;++i)	cout<<" ";
			cout<<" Computer Won! ";
			exit(0);
		}
	}
	
	for(int i=1;i<=3;++i)
	{
		cnt=0,pos=0;
		for(int j=1;j<=3;++j)
		{
			if(ar[j][i]==' ')	pos=j;
			else if(ar[j][i]=='x')	++cnt;			
		}
		if((cnt==2)&&(pos))
		{
			ar[pos][i]='x';
			player();
			cout<<"\n";
			for(int i=0;i<space;++i)	cout<<" ";
			cout<<" Computer Won! ";
			exit(0);
		}
	}
	
	cnt=0,pos=0;
	for(int i=1;i<=3;++i)
	{
		if(ar[i][i]==' ')	pos=i;
		else if(ar[i][i]=='x')	++cnt;			
		if((cnt==2)&&(pos))
		{
			ar[pos][pos]='x';
			player();
			cout<<"\n";
			for(int i=0;i<space;++i)	cout<<" ";
			cout<<" Computer Won! ";
			exit(0);
		}
	}
	
	cnt=0,pos=0;
	for(int i=1;i<=3;++i)
	{
		if(ar[i][4-i]==' ')	pos=i;
		else if(ar[i][4-i]=='x')	++cnt;			
		if((cnt==2)&&(pos))
		{
			ar[pos][4-pos]='x';
			player();
			cout<<"\n";
			for(int i=0;i<space;++i)	cout<<" ";
			cout<<" Computer Won! \n\n";
			exit(0);
		}
	}
	
	/* Check if Opponent Can Win */
	

	for(int i=1;i<=3;++i)
	{
		cnt=0,pos=0;
		for(int j=1;j<=3;++j)
		{
			if(ar[i][j]==' ')	pos=j;
			else if(ar[i][j]=='o')	++cnt;			
		}
		if((cnt==2)&&(pos))
		{
			ar[i][pos]='x';
			player();
			return;
		}
	}
	
	for(int i=1;i<=3;++i)
	{
		cnt=0,pos=0;
		for(int j=1;j<=3;++j)
		{
			if(ar[j][i]==' ')	pos=j;
			else if(ar[j][i]=='o')	++cnt;			
		}
		if((cnt==2)&&(pos))
		{
			ar[pos][i]='x';
			player();
			return;
		}
	}

	cnt=0,pos=0;
	for(int i=1;i<=3;++i)
	{
		if(ar[i][i]==' ')	pos=i;
		else if(ar[i][i]=='o')	++cnt;			
		if((cnt==2)&&(pos))
		{
			ar[pos][pos]='x';
			player();
			return;
		}
	}
	
	cnt=0,pos=0;
	for(int i=1;i<=3;++i)
	{
		if(ar[i][4-i]==' ')	pos=i;
		else if(ar[i][4-i]=='o')	++cnt;			
		if((cnt==2)&&(pos))
		{
			ar[pos][4-pos]='x';
			player();
			return;
		}
	}
	
	if(ar[2][2]==' ')
	{
		if(ar[1][1]==' '&&ar[3][3]==' '&&ar[1][3]==' '&&ar[3][1]==' ')
		{
			if(ar[1][2]=='o'||ar[2][1]=='o')
				ar[1][1]='x';
			else ar[3][3]='x';	
		}
		else ar[2][2]='x';
		player();
		return;
	}
	
	else if(ar[2][2]=='x')
	{
		for(int i=1;i<=3;++i)
			if(ar[i][2]==' ')
			{
				ar[i][2]='x';
				player();
				return;
			}
			
		for(int i=1;i<=3;++i)
			if(ar[2][i]==' ')
			{
				ar[2][i]='x';
				player();
				return;
			}		
	}
	
	if(ar[1][1]==' ')
	{
		ar[1][1]='x';
		player();
		return;
	}
	if(ar[1][3]==' ')
	{
		ar[1][3]='x';
		player();
		return;
	}	
	
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			if(ar[i][j]==' ')
				ar[i][j]='x';
					return;
	
}




int main()
{
	start:
	for(char i='1';i<='3';++i)
		for(char j='1';j<='3';++j)
			ar[i-'0'][j-'0']=' ';
	
	
	int x,y;
	for(int i=0;i<=9;i+=2)
	{
	//	cout<<i<<"\n";
		player();
		for(int i=0;i<space;++i)	cout<<" ";
		cout<<"Your Turn  : ";
		bool valid=false;
		int cha=3;
		while((!valid)&&(cha))
		{
			cin>>x>>y;
			if(x>=1&&x<4&&y>=1&&y<4&&ar[x][y]==' ')	
			{
				valid=true;
				ar[x][y]='o';
			}
			else
			{
				--cha;
				if(cha==0)
				{
					player();
					cout<<"\n";
					for(int i=0;i<space-5;++i)	cout<<" ";
					cout<<"Too Many Incorrect Attempts\n ";	
					exit(0);
				}
				player();
				cout<<"\n";
				for(int i=0;i<space;++i)	cout<<" ";
				cout<<"Invalid Move!\n ";
				for(int i=0;i<space;++i)	cout<<" ";
				cout<<" Try Again\n";
				for(int i=0;i<space-1;++i)	cout<<" ";
				cout<<cha<<(cha==1?" Chance":" Chances")<<" left:";
			}
			
		}
		player();
		if(i==8)	
		{
			player();
			cout<<"\n";
			for(int i=0;i<space;++i)	cout<<" ";
			cout<<"  Match Drawn\n\n";
			for(int i=0;i<space;++i)	cout<<" ";
			cout<<"Try Again(y/n)? ";
			end();
			goto start;
		}
		for(int i=0;i<space;++i)	cout<<" ";
		cout<<"Processing.\n";
		Sleep(delay);
		player();
		for(int i=0;i<space;++i)	cout<<" ";
		cout<<"Processing .\n";
		Sleep(delay);
		player();
		for(int i=0;i<space;++i)	cout<<" ";
		cout<<"Processing  .\n";
		computer();
	}
	return 0;
}
