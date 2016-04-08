//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
#include "ShellAPI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
TForm3 *Form3;
String pathToFile = "C:\\676";
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	//
   //	Form1->ListFiles("C:\\676\\");
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
			if (TN) //условие для первого звена. решается добавлять потомков первых звеньев или сами первые звенья
				ListFilesToo( TreeView1->Items->AddChild(TN, sr.Name),  DirName+"\\" + sr.Name);//вызывает сама себя для поиска в подпапках
			else
				ListFilesToo( TreeView1->Items->Add(TN, sr.Name),  DirName+"\\" + sr.Name);
			// List->Add(DirName+"\\" + sr.Name);//добавляет папки
		}
		else if (sr.Name.Pos(".od"))// иначе найден файл
		{
			// String Ext=ExtractFileExt(sr.Name).UpperCase();
			// if (Ext==".JPG") //поиск по расширению
		   //	List->Add(DirName+"\\" + sr.Name);//добавляет файлы
        	TreeView1->Items->AddChild(TN, sr.Name);
		}
	}
	while (!FindNext(sr));//ищем опять, пока не найдем все
	FindClose(sr);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::TreeView1MouseDown(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)
{
	if (TreeView1->GetNodeAt(X,Y)->Text.Pos(".od"))
	{
		TStringList* listFromFileOD = new TStringList();
		pathToFile = "C:\\676";
		TTreeNode * TN;
		TN = TreeView1->GetNodeAt(X,Y);
		listFromFileOD->Add("\\" + TN->Text);
		String fileName = TN->Text.SubString(0, TN->Text.Pos(".")-1); //имя файла с замером
		while (TN->Parent)
		{
			TN = TN->Parent;
//			pathToFile = pathToFile + "\\" + TN->Text;
			listFromFileOD->Add("\\" + TN->Text);
		}
		for (int i = listFromFileOD->Count-1; i >= 0; i--)
			pathToFile += listFromFileOD->Strings[i];

		listFromFileOD->LoadFromFile(pathToFile); //строки из файла с замером
		/*
		Структура строк:
		0 - спектр типа "_СВС_"
		1 - канал типа "1_"
		2 - типа объекта диагн. "Муфта"
		3 -	fx1, должен быть всегда
		4 - fx2 либо ""
		5 - fx3 либо ""
		6 - результат расчета 1 файла Xls
		7 - дата этого файла
		чет - результат расчета
		нечет - дата
		*/
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		Form3->Chart1->SeriesList->Clear(); //удаляет отработанные серии, очищает график

		TLineSeries* ls = new TLineSeries(Form3->Chart1);

		StaticText1->Caption = fileName;
		//НАИМЕНОВАНИЕ(имя файла) добавляется на форму из файла

		StaticText4->Caption = listFromFileOD->Strings[0].SubString(2,3);
		//СПЕКТР (СВС)

		StaticText2->Caption = listFromFileOD->Strings[2];
		//ТИП ОБЪЕКТА (Муфта)

		StaticText8->Caption = "fx1 = " + listFromFileOD->Strings[3];
		//диагностический признак fx1

		StaticText9->Caption = "fx2 = " + listFromFileOD->Strings[4];
		//диагностический признак fx2

		StaticText10->Caption = "fx3 = " + listFromFileOD->Strings[5];
		//диагностический признак fx3

		//
		for (int i = 6; i < listFromFileOD->Count; i++)
		{
			ls->AddXY(StrToDate(listFromFileOD->Strings[i+1]),StrToFloat(listFromFileOD->Strings[i]), listFromFileOD->Strings[i+1], clRed);
        	i++;
		}
		Form3->Chart1->View3D = false;
		Form3->Chart1->AddSeries(ls);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	//
    AnsiString str1 = "C:\\676\\Chiron FZ15W\\012027\\test№1.od";
	AnsiString str = pathToFile;
	const char * ch1 = pathToFile.c_str();
	const char * ch = str1.c_str();
	SHFILEOPSTRUCT fStrukt;
	fStrukt.wFunc = FO_DELETE;
	fStrukt.pFrom = str.c_str();
	fStrukt.hwnd = 0;
	fStrukt.fFlags = FOF_ALLOWUNDO;
	
	SHFileOperation(&fStrukt);
}
//---------------------------------------------------------------------------

