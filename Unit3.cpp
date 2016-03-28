//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	//
	Form1->ListFiles("C:\\676\\");
	//	TreeView1
	TreeView1->Items->Clear();
	//����� ������ �����
	ListFilesToo(NULL,
				 "C:\\676\\");

}
//---------------------------------------------------------------------------
void TForm3::ListFilesToo(TTreeNode* TN, const String& DirName)
{
	TSearchRec sr;
	if (!FindFirst(DirName+"\\*.*", faAnyFile, sr))
	do
	{
		if (!(sr.Name == "." || sr.Name == ".."))//��� ���������� �� ����
		if (sr.Attr & faDirectory)// ������� �����
		{
			if (TN)
				ListFilesToo( TreeView1->Items->AddChild(TN, sr.Name),  DirName+"\\" + sr.Name);//�������� ���� ���� ��� ������ � ���������
			else
				ListFilesToo( TreeView1->Items->Add(TN, sr.Name),  DirName+"\\" + sr.Name);
			// List->Add(DirName+"\\" + sr.Name);//��������� �����
		}
		else// ����� ������ ����
		{
			// String Ext=ExtractFileExt(sr.Name).UpperCase();
			// if (Ext==".JPG") //����� �� ����������
		   //	List->Add(DirName+"\\" + sr.Name);//��������� �����
		}
	}
	while (!FindNext(sr));//���� �����, ���� �� ������ ���
	FindClose(sr);
}
