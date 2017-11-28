#include <iostream>
#include <fstream>
using namespace std;
typedef struct
{
    int col;
    int row;
    int value;

} term;

void transpose(term a[], term b[])
{
    int n,i,j,currentb=1;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    if(n>0){
        for(i=0;i< a[0].col ;i++)
            for(j=1;j<=n;j++)
            if( a[j].col == i){
                b[currentb].row = a[j].col;
                b[currentb].col = a[j].row;
                b[currentb].value = a[j].value;
                currentb++;
            }
    }
}

int main()
{
    char filename[20]= {};
    cout << "Please enter file name: " ;
    cin >> filename;

    ifstream ifs(filename,ios::in);
    char ch;
    string str="",str2[2];
    int col[2]= {0},row[2]= {0},i=0,k=0,num[2]= {0};
    int leng,leng0;
    bool flag = true;

    while(ifs.get(ch))
    {
        if(ch=='|')
        {
            k=1; //準備換到下一個矩陣，用來控制flag
            i++; //換到下一個矩陣
        }

        if(ch=='\n')
        {

            flag = false; //把flag設成false是因為每一個矩陣的col數只要在第一次換行前就能確認
            row[i]++;
            if(k>0)
            {
                flag = true;
                k--;
            }

        }

        if( (ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9')
           &&flag == true)
        {
            col[i]++;

        }
        if( (ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9'))
        {
            if(ch!='0')
                num[i]++;
            str2[i]+=ch; //之後再轉換成整數
        }

    }

    cout << "col[0]: " << col[0] << " col[1]: " << col[1] << endl;
    cout << "row[0]: " << row[0] << " row[1]: " << row[1] << endl;
    cout << "num[0]: " << num[0] << " num[1]: " << num[1] << endl;

    leng0 = num[0];
    leng = num[1];
    leng0++;
    leng++;
    term C[leng0];
    term A[leng],B[leng]; //A之後會被transpose成B，所以兩者的大小一樣

    int N=1,n=1,w=0,z=0;
    /*開始將讀檔所得的資料輸入到矩陣中*/
    for(int x=0; x<row[0]; x++)
    {
        for(int y=0; y<col[0]; y++)
        {
            if(str2[0].at(w)!='0')
            {
                //cout << str2[1].at(z) << endl;
                C[N].row = x;
                C[N].col = y;
                C[N].value = (str2[0].at(w))-48;

                N++;
            }
            w++;
        }
    }

    for(int x=0; x<row[1]; x++)
    {
        for(int y=0; y<col[1]; y++)
        {
            if(str2[1].at(z)!='0')
            {
                //cout << str2[1].at(z) << endl;
                A[n].row = x;
                A[n].col = y;
                A[n].value = (str2[1].at(z))-48;

                n++;
            }
            z++;
        }
    }
    //開始將A矩陣轉置成B矩陣
    transpose(A,B);
return 0;
}


