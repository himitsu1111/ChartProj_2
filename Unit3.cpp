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
	Form1->ListFiles("C:\\676");
   //	TreeView1
}
//---------------------------------------------------------------------------
void TForm3::ListFilesToo(const String &DirName)
{
	TStringList* List = new TStringList;

	List->Clear();
	TSearchRec sr;
	if (!FindFirst(DirName+"\\*.*", faAnyFile, sr))
		do
		{
			if (!(sr.Name == "." || sr.Name == ".." || sr.Name.Pos("~$")))//��� ���������� �� ����
			if (sr.Attr & faDirectory)// ������� �����
			{
				/*ListFiles*/ List->Add(/*DirName+"\\" +*/ sr.Name);//, List);//�������� ���� ���� ��� ������ � ���������
				// List->Add(DirName+"\\" + sr.Name);//��������� �����
			}
			else// ����� ������ ����
			{
				// String Ext=ExtractFileExt(sr.Name).UpperCase();
				// if (Ext==".JPG") //����� �� ����������
				List->Add(/*DirName+"\\" +*/ sr.Name);//��������� �����
			}
		}
		while (!FindNext(sr));//���� �����, ���� �� ������ ���
	FindClose(sr);
}
