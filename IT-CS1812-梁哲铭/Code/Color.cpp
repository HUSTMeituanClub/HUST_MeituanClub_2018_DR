#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
cout<<"ԭɫtestCOLOR��û������������ɫ��"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|
                        FOREGROUND_GREEN|FOREGROUND_BLUE);//������ɫ���
cout<<"��ɫtestCOLOR����ɫ��ɫ��ɫ��ӣ�"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
                       //���ú�ɫ
cout<<"��ɫtestCOLOR�����õ���ɫΪ��ɫ��"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN)
                       ;//������ɫ
cout<<"��ɫtestCOLOR�����õ���ɫΪ��ɫ��"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
                       //������ɫ
cout<<"��ɫtestCOLOR�����õ���ɫΪ��ɫ��"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|
                       FOREGROUND_GREEN);//���ú�ɫ����ɫ���
cout<<"��ɫtestCOLOR����ɫ����ɫ���ɫ��"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|
                       FOREGROUND_BLUE);//���ú�ɫ����ɫ���
cout<<"��ɫtestCOLOR����ɫ����ɫ���ɫ��"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|
                       FOREGROUND_BLUE);//������ɫ����ɫ���
cout<<"��ɫtestCOLOR����ɫ����ɫ���ɫ��"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
                       //������ɫ��û�������ɫ����Ϊԭɫ
cout<<endl;
}

