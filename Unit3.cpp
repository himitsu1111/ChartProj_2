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
#pragma link "Series"
#pragma resource "*.dfm"
TForm3 *Form3;
String pathToFile = "C:\\676"; //нужна для работы нескольким методам, поэтому глобальная,
								//а не просто путь содержит
const cGelt = 4;          //для рисования на канве чарта
double Gelt[cGelt][2] =
{ 	//x      y
	150000,    20,   //правый верхний угол   //прямоугольник
	0,    		20,    //левый верхний
	0,    		12,     //левый нижний
	150000,    12     //правый нижний
};
const cKrasn = 4;          //для рисования на канве чарта
double Krasn[cKrasn][2] =
{ 	//x      y
	150000,    30,   //правый верхний угол   //прямоугольник
	0,    		30,    //левый верхний
	0,    		20,     //левый нижний
	150000,    20     //правый нижний
};

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
		3 - уровень предупреждение
		4 - уровень авария
		5 -	fx1, должен быть всегда
		6 - fx2 либо ""
		7 - fx3 либо ""
		8 - результат расчета 1 файла Xls
		9 - дата этого файла
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

		StaticText8->Caption = "fx1 = " + listFromFileOD->Strings[5];
		//диагностический признак fx1

		StaticText9->Caption = "fx2 = " + listFromFileOD->Strings[6];
		//диагностический признак fx2

		StaticText10->Caption = "fx3 = " + listFromFileOD->Strings[7];
		//диагностический признак fx3

		StaticText6->Caption = listFromFileOD->Strings[3];
		//уровень предупреждение

		StaticText7->Caption = listFromFileOD->Strings[4];
		//уровень авария

		//
		for (int i = 8; i < listFromFileOD->Count; i++)
		{
			ls->AddXY(StrToDate(listFromFileOD->Strings[i+1]),StrToFloat(listFromFileOD->Strings[i]), listFromFileOD->Strings[i+1], clRed);
        	i++;
		}
		Form3->Chart1->View3D = false;
		Form3->Chart1->AddSeries(ls);

		markOfClick = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{              //функция для удаления файлов
	//
  //  AnsiString str1 = "C:\\676\\Chiron FZ15W\\012027\\test№1.od";
	AnsiString str = pathToFile += '\0'; //добавляет в строку второй нулевой символ для работы
										// SHFileOperation()
//	const char * ch1 = pathToFile.c_str();
//	const char * ch = str1.c_str();
	SHFILEOPSTRUCT fStrukt;
	fStrukt.wFunc = FO_DELETE;
	fStrukt.pFrom = str.c_str();
	fStrukt.hwnd = 0;
	fStrukt.fFlags = FOF_ALLOWUNDO;

	SHFileOperation(&fStrukt);
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Chart1BeforeDrawAxes(TObject *Sender)
{


		TPoint yellowLevel[cGelt];
		TPoint redLevel[cKrasn];


		Gelt[1][1] = StrToFloat(StaticText6->Caption);
		Gelt[0][1] = StrToFloat(StaticText6->Caption);

		for (int i = 0; i < cGelt; ++i)
		{
			yellowLevel[i].x = Series1->CalcXPosValue(Gelt[i][0]);
			yellowLevel[i].y = Series1->CalcYPosValue(Gelt[i][1]);
		}

		HRGN rg = CreateRectRgn(Chart1->BottomAxis->IStartPos,
		Chart1->LeftAxis->IStartPos+1,
		Chart1->BottomAxis->IEndPos,
		Chart1->LeftAxis->IEndPos);
		Chart1->Canvas->Brush->Color = TColor(clYellow);
		Chart1->Canvas->Pen->Color = TColor(clYellow);
		SelectClipRgn(Chart1->Canvas->Handle, rg);
		Chart1->Canvas->Polygon(yellowLevel, 4);
		SelectClipRgn(Chart1->Canvas->Handle, 0);
		DeleteObject(rg);

		//рисуем второй красный полигон
		Krasn[1][1] = StrToFloat(StaticText7->Caption);
		Krasn[0][1] = StrToFloat(StaticText7->Caption);

		for (int i = 0; i < cGelt; ++i)
		{
			redLevel[i].x = Series1->CalcXPosValue(Krasn[i][0]);
			redLevel[i].y = Series1->CalcYPosValue(Krasn[i][1]);
		}

		HRGN rg2 = CreateRectRgn(Chart1->BottomAxis->IStartPos,
		Chart1->LeftAxis->IStartPos+1,
		Chart1->BottomAxis->IEndPos,
		Chart1->LeftAxis->IEndPos);
		Chart1->Canvas->Brush->Color = TColor(clMaroon);
		Chart1->Canvas->Pen->Color = TColor(clMaroon);
		SelectClipRgn(Chart1->Canvas->Handle, rg2);
		Chart1->Canvas->Polygon(redLevel, 4);
		SelectClipRgn(Chart1->Canvas->Handle, 0);
		DeleteObject(rg2);

}
//---------------------------------------------------------------------------

