#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct pos
{
    int row, col;
};
position nextMove(std::string Array[27][27]);
int minimax(std::string Array[27][27],int dep,bool player);
int evaluate(std::string Array[27][27]);
std::string A[27][27],mov,omove;
int no,ab[3],depth;

int main()
{
  int p,q,i,j,l,ln,count;
  std::string type,Arr[27][27];
  std::string n,d,row;
  ifstream ifile;
  ifile.open("in.txt",ios::in);
  getline(ifile,n);
  getline(ifile,type);
  getline(ifile,mov);
  getline(ifile,d);
  i=0;
  no=atoi(n.c_str());

  for(i=0;i<no;i++)
    for(j=0;j<no;j++)
    ifile>>A[i][j];
    getline(ifile,row);

	for(i=0;i<no;i++)
  	{
    	getline(ifile,row);
    for(j=0;j<no;j++)
    {
      Arr[i][j]=row.substr(j,1);

    }
  }
    if(!mov.compare("X"))
      omove="O";
  	else
      omove="X";
  depth=atoi(d.c_str());
  i=1;
  position pos;
  pos=nextMove(Arr);
  cout<<pos.row<<"\n"<<pos.col<<"\n";
  Arr[pos.row][pos.col]=mov;
  for(i=0;i<no;i++)
  {
    for(j=0;j<no;j++)
    cout<<Arr[i][j];
    cout<<"\n";
  }
}
position nextMove(std::string Array[27][27])
{
    int v=-1000000;
    int i,j,l,m,flag=0;
    std::string AB[27][27];
    position finalposition;
    finalposition.row=-1;
    finalposition.col=-1;
    for(i=0;i<no;i++)
     {
        for(j=0;j<no;j++)
        {
            if(!Array[i][j].compare("."))
            {
                Array[i][j]=mov;

                if(i==0&&j==0&&((!Array[i][j+1].compare(mov))||(!Array[i+1][j].compare(mov))))
                {
                    if((!Array[i][j+1].compare(omove))||(!Array[i+1][j].compare(omove)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }
                    }

                }

                else if(i==no-1&&j==0&&((!Array[i][j+1].compare(mov))||(!Array[i-1][j].compare(mov))))
                {
                    if((!Array[i][j+1].compare(omove))||(!Array[i-1][j].compare(omove)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    }
                }
                else if(i==0&&j==no-1&&((!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov))))
                {
                    if((!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }
                    }
                }

                else if(i==no-1&&j==no-1&&((!Array[i][j-1].compare(mov))||(!Array[i-1][j].compare(mov))))
                {
                    if((!Array[i][j-1].compare(omove))||(!Array[i-1][j].compare(omove)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    }

                }
                else if(i==0&&j<no-1&&j>0&&((!Array[i][j+1].compare(mov)||(!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov)))))
                {
                    if((!Array[i][j+1].compare(omove)||(!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove))))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                }
                else if(i>0&&i<no-1&&j==0)&&((!Array[i][j+1].compare(mov)||(!Array[i-1][j].compare(mov))||(!Array[i+1][j].compare(mov)))))
                {
                    if((!Array[i][j+1].compare(omove)||(!Array[i-1][j].compare(omove))||(!Array[i+1][j].compare(omove))))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                }
                else if(i<no-1&&j==no-1&&((!Array[i-1][j].compare(mov)||(!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov)))))
                {
                    if((!Array[i-1][j].compare(omove)||(!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove))))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                }
                else if(i==no-1&&j<no-1&&((!Array[i][j-1].compare(mov)||(!Array[i][j+1].compare(mov))||(!Array[i-1][j].compare(mov)))))
                {
                    if((!Array[i][j-1].compare(omove)||(!Array[i][j+1].compare(omove))||(!Array[i-1][j].compare(omove))))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                    if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                }
                else
                {
                if(((!Array[i-1][j].compare(mov))||(!Array[i+1][j].compare(mov))||(!Array[i][j-1].compare(mov))||(!Array[i][j+1].compare(mov)))&&(!Array[i-1][j].compare(omove))||(!Array[i+1][j].compare(omove))||(!Array[i][j-1].compare(omove))||(!Array[i][j+1].compare(omove)))
                {
                    flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                }
            }
                int val=minimax(Array,2,false);
                if(flag==1)
                {
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        Array[l][m]=AB[l][m];
                    Array[i][j]=".";
                }
                else
                    Array[i][j]=".";

                    if(val>v)
                    {
                        finalposition.row=i;
                        finalposition.col=j;
                        v=val;
                    }

            }
        }
     }
  return finalposition;
}
int minimax(std::string Array[27][27],int dep,bool player)
{
    int i,j,l,m,flag=0;
    std::string AB[27][27];
    int score=evaluate(Array);
    if(dep>depth)
    {
        return score;
    }
    int c=0;
    for(i=0;i<no;i++)
        for(j=0;j<no;j++)
        if(!Array[i][j].compare("."))
        c++;
    if(c==0)
        return score;

    if(player)
    {

        int maximum=-100000;
        for(i=0;i<no;i++)
     {
        for(j=0;j<no;j++)
        {
            if(!Array[i][j].compare("."))
            {
                Array[i][j]=mov;
                if(i==0&&j==0&&((!Array[i][j+1].compare(mov))||(!Array[i+1][j].compare(mov))))
                {
                    if((!Array[i][j+1].compare(omove))||(!Array[i+1][j].compare(omove)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }
                    }

                }
                else if(i==no-1&&j==0&&((!Array[i][j+1].compare(mov))||(!Array[i-1][j].compare(mov))))
                {
                    if((!Array[i][j+1].compare(omove))||(!Array[i-1][j].compare(omove)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    }
                }
                else if(i==0&&j==no-1&&((!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov))))
                {
                    if((!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }
                    }
                }
                else if(i==no-1&&j==no-1&&((!Array[i][j-1].compare(mov))||(!Array[i-1][j].compare(mov))))
                {
                    if((!Array[i][j-1].compare(omove))||(!Array[i-1][j].compare(omove)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    }

                }
                else if(i==0&&j<no-1&&((!Array[i][j+1].compare(mov))||(!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov))))
                {

                    if((!Array[i][j+1].compare(omove))||(!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove)))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                }
                else if(i<no-1&&j==0&&((!Array[i][j+1].compare(mov))||(!Array[i-1][j].compare(mov))||(!Array[i+1][j].compare(mov))))
                {
                    if((!Array[i][j+1].compare(omove))||(!Array[i-1][j].compare(omove))||(!Array[i+1][j].compare(omove)))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                }
                else if(i<no-1&&j==no-1&&((!Array[i-1][j].compare(mov)||(!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov)))))
                {
                    if((!Array[i-1][j].compare(omove)||(!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove))))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                }
                else if(i==no-1&&j<no-1&&((!Array[i][j-1].compare(mov)||(!Array[i][j+1].compare(mov))||(!Array[i-1][j].compare(mov)))))
                {
                    if((!Array[i][j-1].compare(omove)||(!Array[i][j+1].compare(omove))||(!Array[i-1][j].compare(omove))))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }
                    if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                }
                else
                {
                if(((!Array[i-1][j].compare(mov))||(!Array[i+1][j].compare(mov))||(!Array[i][j-1].compare(mov))||(!Array[i][j+1].compare(mov)))&&(!Array[i-1][j].compare(omove))||(!Array[i+1][j].compare(omove))||(!Array[i][j-1].compare(omove))||(!Array[i][j+1].compare(omove)))
                {
                    flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(omove))
                    {
                        Array[i-1][j]=mov;
                    }
                    if(!Array[i+1][j].compare(omove))
                    {
                        Array[i+1][j]=mov;
                    }if(!Array[i][j-1].compare(omove))
                    {
                        Array[i][j-1]=mov;
                    }if(!Array[i][j+1].compare(omove))
                    {
                        Array[i][j+1]=mov;
                    }
                }
            }
                int val=minimax(Array,dep+1,!player);
                cout<<val<<"\n";
                if(flag==1)
                {
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        Array[l][m]=AB[l][m];
                    Array[i][j]=".";
                }
                else
                    Array[i][j]=".";

                    if(val>maximum)
                    {
                        maximum=val;
                    }

            }
        }
     }
     return maximum;
    }
    else
    {
        int minimum=1000000;
        for(i=0;i<no;i++)
     {
        for(j=0;j<no;j++)
        {
            if(!Array[i][j].compare("."))
            {
                Array[i][j]=mov;
                if(i==0&&j==0&&((!Array[i][j+1].compare(omove))||(!Array[i+1][j].compare(omove))))
                {
                    if((!Array[i][j+1].compare(mov))||(!Array[i+1][j].compare(mov)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j+1].compare(mov))
                    {
                        Array[i][j+1]=omove;
                    }
                    if(!Array[i+1][j].compare(mov))
                    {
                        Array[i+1][j]=omove;
                    }
                    }

                }
                else if(i==no-1&&j==0&&((!Array[i][j+1].compare(omove))||(!Array[i-1][j].compare(omove))))
                {
                    if((!Array[i][j+1].compare(mov))||(!Array[i-1][j].compare(mov)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j+1].compare(mov))
                    {
                        Array[i][j+1]=omove;
                    }
                    if(!Array[i-1][j].compare(mov))
                    {
                        Array[i-1][j]=omove;
                    }
                    }
                }
                else if(i==0&&j==no-1&&((!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove))))
                {
                    if((!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j-1].compare(mov))
                    {
                        Array[i][j-1]=omove;
                    }
                    if(!Array[i+1][j].compare(mov))
                    {
                        Array[i+1][j]=omove;
                    }
                    }
                }
                else if(i==no-1&&j==no-1&&((!Array[i][j-1].compare(omove))||(!Array[i-1][j].compare(omove))))
                {
                    if((!Array[i][j-1].compare(mov))||(!Array[i-1][j].compare(mov)))
                    {
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                        if(!Array[i][j-1].compare(mov))
                    {
                        Array[i][j-1]=omove;
                    }
                    if(!Array[i-1][j].compare(mov))
                    {
                        Array[i-1][j]=omove;
                    }
                    }

                }
                else if(i==0&&j<no-1&&((!Array[i][j+1].compare(omove))||(!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove))))
                {

                    if((!Array[i][j+1].compare(mov))||(!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov)))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i][j-1].compare(mov))
                    {
                        Array[i][j-1]=omove;
                    }
                    if(!Array[i+1][j].compare(mov))
                    {
                        Array[i+1][j]=omove;
                    }if(!Array[i][j+1].compare(mov))
                    {
                        Array[i][j+1]=omove;
                    }
                }
                else if(i<no-1&&j==0&&((!Array[i][j+1].compare(omove))||(!Array[i-1][j].compare(omove))||(!Array[i+1][j].compare(omove))))
                {
                    if((!Array[i][j+1].compare(mov))||(!Array[i-1][j].compare(mov))||(!Array[i+1][j].compare(mov)))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(mov))
                    {
                        Array[i-1][j]=omove;
                    }
                    if(!Array[i+1][j].compare(mov))
                    {
                        Array[i+1][j]=omove;
                    }if(!Array[i][j+1].compare(mov))
                    {
                        Array[i][j+1]=omove;
                    }
                }
                else if(i<no-1&&j==no-1&&((!Array[i-1][j].compare(omove)||(!Array[i][j-1].compare(omove))||(!Array[i+1][j].compare(omove)))))
                {
                    if((!Array[i-1][j].compare(mov)||(!Array[i][j-1].compare(mov))||(!Array[i+1][j].compare(mov))))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(mov))
                    {
                        Array[i-1][j]=omove;
                    }
                    if(!Array[i+1][j].compare(mov))
                    {
                        Array[i+1][j]=omove;
                    }if(!Array[i][j-1].compare(mov))
                    {
                        Array[i][j-1]=omove;
                    }
                }
                else if(i==no-1&&j<no-1&&((!Array[i][j-1].compare(omove)||(!Array[i][j+1].compare(omove))||(!Array[i-1][j].compare(omove)))))
                {
                    if((!Array[i][j-1].compare(mov)||(!Array[i][j+1].compare(mov))||(!Array[i-1][j].compare(mov))))
                        flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i][j-1].compare(mov))
                    {
                        Array[i][j-1]=omove;
                    }
                    if(!Array[i][j+1].compare(mov))
                    {
                        Array[i][j+1]=omove;
                    }if(!Array[i-1][j].compare(mov))
                    {
                        Array[i-1][j]=omove;
                    }
                }
                else
                {
                if(((!Array[i-1][j].compare(omove))||(!Array[i+1][j].compare(omove))||(!Array[i][j-1].compare(omove))||(!Array[i][j+1].compare(omove)))&&(!Array[i-1][j].compare(mov))||(!Array[i+1][j].compare(mov))||(!Array[i][j-1].compare(mov))||(!Array[i][j+1].compare(mov)))
                {
                    flag=1;
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        AB[l][m]=Array[l][m];
                    if(!Array[i-1][j].compare(mov))
                    {
                        Array[i-1][j]=omove;
                    }
                    if(!Array[i+1][j].compare(mov))
                    {
                        Array[i+1][j]=omove;
                    }if(!Array[i][j-1].compare(mov))
                    {
                        Array[i][j-1]=omove;
                    }if(!Array[i][j+1].compare(mov))
                    {
                        Array[i][j+1]=omove;
                    }
                }
            }
                int val=minimax(Array,dep+1,!player);
                cout<<val<<"\n";
                if(flag==1)
                {
                    for(l=0;l<no;l++)
                        for(m=0;m<no;m++)
                        Array[l][m]=AB[l][m];
                    Array[i][j]=".";
                }
                else
                    Array[i][j]=".";

                    if(val<minimum)
                    {
                        minimum=val;
                    }

            }
        }
     }
     return minimum;
    }
}
int evaluate(std::string Array[27][27])
{

    int i,j,sum1=0,sum2=0;
    for(i=0;i<no;i++)
    {
        for(j=0;j<no;j++)
        {
        if(!Array[i][j].compare("X"))
        sum1=sum1+atoi(A[i][j].c_str());
        if(!Array[i][j].compare("O"))
        sum2=sum2+atoi(A[i][j].c_str());
        }
    }
    if(!mov.compare("X"))
        return (sum1-sum2);
    else
        return (sum2-sum1);
}
