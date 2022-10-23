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
    ifstream filein("C:\\Users\\Admin\\Desktop\\input1_1.txt", ios_base::in);
    if (filein.fail() == true)
    {
        cout << "Chua Ton Tai File";
    }
    while (filein.eof() == false)
    {

        int x;
        filein >> x;
        filein.ignore();
        string s, num;
        getline(filein, s);
        stringstream ss(s);
        while (getline(ss, num, ','))
        {
            a[x - 1][stoi(num) - 1] = 1;
        }
    }
    filein.close();
}
void Ghi_File_MaTran_DanhSachKe_Graph(int a[6][6])
{
    ofstream fileOut;
    fileOut.open("C:\\Users\\Admin\\Desktop\\output1_1.txt", ios_base::out);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            fileOut << a[i][j] << " ";
        }
        fileOut << endl;
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i <= j)
            {
                if (a[i][j] == 1)
                {
                    fileOut << i + 1 << ":" << j + 1;
                    fileOut << endl;
                }
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        int s = 0;
        string x = "deg";
        fileOut << x << "(" << i + 1 << ")=";
        for (int j = 0; j < 6; j++)
        {
            s += a[i][j];
        }
        fileOut << s << endl;
    }
    cout << "Ghi ra File Thanh Cong!!!" << endl;
    fileOut.close();
}
int main()
{
    int a[6][6];
    Doc_File_Graph(a);
    Ghi_File_MaTran_DanhSachKe_Graph(a);
    return 0;
}