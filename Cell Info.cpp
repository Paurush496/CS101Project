#include<simplecpp>

bool play;
int A[5][5];
int count1[25], count2[25];



class CellInfo
{

public:
    float a, b, p1;

public:
    CellInfo()
    {
        int e=0;
        for(int j=0, b=50; b<=170; b=b+30, j++)
        {
            for(int k=0, a=50; a<=170; a=a+30, k++)
            {
                A[k][j]=0;
                count1[e]=0;
                count2[e]=10;
                e++;
            }
        }
    }



    void infoCell(int M)
    {
        int c1=0;
        for(int j=50, j1=0; j<=170; j=j+30, j1++)
        {
            for(int k=50, k1=0; k<=170; k=k+30, k1++)
            {
                if (a==k && b==j)
                {
                    if (M==1)
                    {
                        count1[c1]++;
                        A[k1][j1]=count1[c1];
                    }
                    else
                    {
                        count2[c1]++;
                        A[k1][j1]=count2[c1];
                    }
                    break;
                }
                c1++;
            }
        }
    }

    int get()
    {
        for(int j=50, j1=0; j<=170; j=j+30, j1++)
        {
            for(int k=50, k1=0; k<=170; k=k+30, k1++)
            {
                if (a==k && b==j)
                {
                    p1=A[k1][j1];
                    return p1;

                    break;
                }
            }
        }
    }




    void orb(int p,int q,int r,int N)
    {

        int q1, q2, q3, q4, q5, q6;
        if (N==1)
        {
            q1=11;
            q2=12;
            q3=13;
            q4=q1-10;
            q5=q2-10;
            q6=q3-10;
        }
        else
        {
            q1=1;
            q2=2;
            q3=3;
            q4=q1+10;
            q5=q2+10;
            q6=q3+10;
        }

        int click = getClick();

        while(true)
        {
            int x, y;
            x=click/65536;
            y=click%65536;
            play = (x>35) && (x<185) && (y>35) && (y<185);
            //play is the condition to ensure that the player plays inside the grid.
            if (play)
            {
                int m=0;
                m=(x-35)/30;
                //note that if m=1.451... or anything decimal then int m=0 will return g.i.f of m, for e.g [1.451..] =1
                a=50+30*m;
                m=(y-35)/30;
                //m will be redefined
                b=50+30*m;
                get();
                if(p1==q1 || p1==q2 || p1==q3)
                {
                    cout <<"Invalid Move"<<endl;
                    click=getClick();
                }
                else
                {
                    if(p1==0)
                    {


                        Circle s(a, b, 8);
                        s.setFill(true);
                        s.setColor(COLOR(p, q, r));
                        s.imprint();
                        infoCell(N);
                        break;
                    }
                    else if(p1==q4)
                    {
                        Circle s(a+5.66, b-5.66, 8);
                        s.setFill(true);
                        s.setColor(COLOR(p, q, r));
                        s.imprint();
                        infoCell(N);
                        break;
                    }
                    else if(p1==q5)
                    {
                        Circle s(a-5.66, b+5.66, 8);
                        s.setFill(true);
                        s.setColor(COLOR(p, q, r));
                        s.imprint();
                        infoCell(N);
                        break;
                    }
                    else if(p1==q6)
                    {
                        cout<<"Maximum limit of the cell reached"<<endl;
                        click=getClick();
                    }
                }


            }

            else
            {
                cout << "Please play inside the Grid"<< endl;
                click=getClick();
            }

        }
    }
};





int main()
{
    CellInfo Cell();
    CellInfo Cell1;
    int n;
    cout << "press 1 : To play very Short " << endl;
    cout << "press 2 : To play Short " << endl;
    cout << "press 3 : To play Long " << endl;
    cout << "press 4 : To play very Long " << endl;
    cin >> n;
    initCanvas (" Colour Connection ",800,600);
    if(n==1)
    {
        for(int i=50; i<=170; i=i+30)
        {
            for(int n=50; n<=170; n=n+30)
            {
                Rectangle r(n, i, 30, 30);
                r.imprint();
                //draw rectangles
            }
        }
        int d=0;
        while(d<=10)
        {
            switch(1)
            {
            case 1:
            {
                cout <<"Player1 turn"<<endl;
                Cell1.orb(255, 0, 0, 1);
            }
            case 2:
            {
                cout <<"Player2 turn"<<endl;
                Cell1.orb(0, 255, 0, 2);
            }
                //both group of statements gets executed as their is no break statement introduced after any case over each iteration
                //of switch loop

            }
            d++;
        }

    }

}
//now the further idea is to create a 2D array that would store the info about each cell of the grid
//For a.g C[i][j]=0 would mean an empty cell
//               =1            a cell with one orb of player1's color
//               =2                        two orbs
//               =3                        three orbs
//               =11                       one orb of player2's color
//               =12                       two orbs
//               =13                       three orbs
//note that 11%10=1 and so on
//baki Jenil ko bta dena vo samajh jayega..

