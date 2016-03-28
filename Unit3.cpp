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
	//перва¤ группа нодов
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
		if (!(sr.Name == "." || sr.Name == ".."))//это показывать не надо
		if (sr.Attr & faDirectory)// найдена папка
		{
			if (TN)
				ListFilesToo( TreeView1->Items->AddChild(TN, sr.Name),  DirName+"\\" + sr.Name);//вызывает сама себя для поиска в подпапках
			else
				ListFilesToo( TreeView1->Items->Add(TN, sr.Name),  DirName+"\\" + sr.Name);
			// List->Add(DirName+"\\" + sr.Name);//добавляет папки
		}
		else// иначе найден файл
		{
			// String Ext=ExtractFileExt(sr.Name).UpperCase();
			// if (Ext==".JPG") //поиск по расширению
		   //	List->Add(DirName+"\\" + sr.Name);//добавляет файлы
		}
	}
	while (!FindNext(sr));//ищем опять, пока не найдем все
	FindClose(sr);
}
