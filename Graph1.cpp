//----------LÊ ĐỨC MẠNH----------
//----------LỚP:ANHTTT-----------

#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
void Doc_File_Graph(int a[6][6])
{

    ifstream filein("C:\\Users\\Admin\\Desktop\\input1.txt", ios_base::in);
    if (filein.fail() == true)
    {
        cout << "Chua Ton Tai File";
    }

    while (filein.eof() == false)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                filein >> a[i][j];
                filein.ignore();
            }
        }
    }
    filein.close();
}
void Ghi_File_Ke_Graph(int a[6][6])
{
    ofstream fileout;
    fileout.open("C:\\Users\\Admin\\Desktop\\input1_1.txt", ios_base::out);
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
    cout << "Ghi ra File Thanh Cong!!!" << endl;
    fileout.close();
}
void Ghi_File_Canh_Graph(int a[6][6])
{
    ofstream fileOut;
    fileOut.open("C:\\Users\\Admin\\Desktop\\input1_2.txt", ios_base::out);
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
    cout << "Ghi ra File Thanh Cong!!!" << endl;
    fileOut.close();
}
int main()
{
    int a[6][6];
    Doc_File_Graph(a);
    Ghi_File_Canh_Graph(a);
    Ghi_File_Ke_Graph(a);
    return 0;
}