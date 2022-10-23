//----------LÊ ĐỨC MẠNH----------
//----------LỚP:ANHTTT-----------

#include <iostream>
#include <fstream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;
void Doc_File_Graph(int a[6][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            a[i][j] = 0;
        }
    }
    ifstream filein("C:\\Users\\Admin\\Desktop\\input1_2.txt", ios_base::in);
    if (filein.fail() == true)
    {
        cout << "Chua Ton Tai File";
    }
    while (filein.eof() == false)
    {
        int x, x1;
        filein >> x;
        filein.ignore();
        filein >> x1;
        a[x - 1][x1 - 1] = a[x1 - 1][x - 1] = 1;
    }
    filein.close();
}
void Ghi_File_MaTran_DanhSachKe_Graph(int a[6][6])
{
    ofstream fileout;
    fileout.open("C:\\Users\\Admin\\Desktop\\output1_2.txt", ios_base::out);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            fileout << a[i][j] << " ";
        }
        fileout << endl;
    }
    for (int i = 0; i < 6; i++)
    {
        fileout << i + 1 << ":";
        for (int j = 0; j < 6; j++)
        {
            if (a[i][j] == 1)
            {
                fileout << j + 1 << ",";
            }
        }
        fileout << endl;
    }
    for (int i = 0; i < 6; i++)
    {
        int s = 0;
        string x = "deg";
        fileout << x << "(" << i + 1 << ")=";
        for (int j = 0; j < 6; j++)
        {
            s += a[i][j];
        }
        fileout << s << endl;
    }
    cout << "Ghi ra File Thanh Cong!!!" << endl;
    fileout.close();
}
int main()
{
    int a[6][6];
    Doc_File_Graph(a);
    Ghi_File_MaTran_DanhSachKe_Graph(a);
    return 0;
}