//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
#include "Support.h"
#include "variables.cpp"
#include "Math.hpp"

#include "ShellAPI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "Series"
#pragma resource "*.dfm"
TForm3 *Form3;
int x1;
int y1;
String pathToFile = ""; //нужна для работы нескольким методам, поэтому глобальная,
								//а не просто путь содержит

const cGelt = 4;          //для рисования на канве чарта
double Gelt[cGelt][2] =
{ 	//x      y
	150000,    20,   //правый верхний угол   //прямоугольник
	0,    		20,    //левый верхний
	0,    		200,     //левый нижний
	150000,    200     //правый нижний
};
const cKrasn = 4;          //для рисования на канве чарта
double Krasn[cKrasn][2] =
{ 	//x      y
	150000,    30,   //правый верхний угол   //прямоугольник
	0,    		30,    //левый верхний
	0,    		200,     //левый нижний
	150000,    200     //правый нижний
};
const cZelen = 4;          //для рисования на канве чарта
double Zelen[cZelen][2] =
{ 	//x      y
	150000,    12,   //правый верхний угол   //прямоугольник
	0,    		12,    //левый верхний
	0,    		0,     //левый нижний
	150000,    0     //правый нижний
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
				 Form1->StaticText11->Caption);

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
				{
//					if (DirName.Length() == 6)
//					{
//						ListFilesToo( TreeView1->Items->Add(TN, sr.Name)->SelectedIndex = 1, DirName+"\\" + sr.Name);
//					}
                    ListFilesToo( TreeView1->Items->Add(TN, sr.Name),  DirName+"\\" + sr.Name);
				}
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
	x1 = X;
	y1 = Y;
	if (TreeView1->GetNodeAt(X,Y)->Text.Pos(".od"))
	{
		TStringList* listFromFileOD = new TStringList();
		pathToFile = Form1->StaticText11->Caption.SubString(0,Form1->StaticText11->Caption.Length()-1);
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
		1 - канал типа "1_" + количество линий типа "800 или 1600"
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
        TLineSeries* ls2 = new TLineSeries(Form3->Chart1);
		Form3->Chart1->AddSeries(ls);
	   	Form3->Chart1->AddSeries(ls2);
		StaticText1->Caption = fileName;
		//НАИМЕНОВАНИЕ(имя файла) добавляется на форму из файла

		StaticText4->Caption = listFromFileOD->Strings[0].SubString(2, listFromFileOD->Strings[0].Length() - 2);
		//СПЕКТР (СВС)

		StaticText2->Caption = listFromFileOD->Strings[2];
		//ТИП ОБЪЕКТА (Муфта)

		if (listFromFileOD->Strings[5].Pos("."))
		{
			double D = StrToFloat(listFromFileOD->Strings[5]);
			D = RoundTo(D , -1);
			StaticText8->Caption = "fx1 = " + FloatToStr(D);//listFromFileOD->Strings[5].SubString(1, listFromFileOD->Strings[5].Pos(".")+1);
		}
		else
			StaticText8->Caption = "fx1 = " + listFromFileOD->Strings[5];
		//диагностический признак fx1

		if (listFromFileOD->Strings[6].Pos("."))
		{
			double D = StrToFloat(listFromFileOD->Strings[6]);
			D = RoundTo(D , -1);
			StaticText9->Caption = "fx2 = " + FloatToStr(D);//listFromFileOD->Strings[6].SubString(1, listFromFileOD->Strings[6].Pos(".")+1);

		}
		else
			StaticText9->Caption = "fx2 = " + listFromFileOD->Strings[6];
		//диагностический признак fx2

		if (listFromFileOD->Strings[7].Pos("."))
		{
			double D = StrToFloat(listFromFileOD->Strings[7]);
			D = RoundTo(D , -1);
			StaticText10->Caption = "fx3 = " + FloatToStr(D);//listFromFileOD->Strings[7].SubString(1, listFromFileOD->Strings[7].Pos(".")+1);
		}
		else
            StaticText10->Caption = "fx3 = " + listFromFileOD->Strings[7];
		//диагностический признак fx3

		StaticText6->Caption = listFromFileOD->Strings[3];
		//уровень предупреждение

		StaticText7->Caption = listFromFileOD->Strings[4];
		//уровень авария

		StaticText3->Caption = listFromFileOD->Strings[1].SubString(3, listFromFileOD->Strings[1].Length() - 2);
		//КАНАЛ и количество линий пересчета 800/1600
		//
		for (int i = 8; i < listFromFileOD->Count; i++)
		{
			ls->AddXY(StrToDate(listFromFileOD->Strings[i+1]),StrToFloat(listFromFileOD->Strings[i]), listFromFileOD->Strings[i+1], clBlue);
			ls2->AddXY(StrToDate(listFromFileOD->Strings[i+1]), 0.05*i, "test",clRed);
			ls2->AddXY(StrToDate(listFromFileOD->Strings[i+1]), 0.09*i, "test",clRed);
			i++;
		}
        Form3->Chart1->Title->Text->Strings[0] = "TREND";
		Form3->Chart1->View3D = false;
		Form3->Chart1->AddSeries(ls);
	  //	Chart1->Title->Text->Strings[0] = "";
	}

	if (TreeView1->GetNodeAt(X,Y)->Text.Length() == 6)
	{
        N1->Visible = true;
		N1->Caption = "Копировать";
	}
	else
	   // N1->Caption = "Выберите инвентарный";
	   N1->Visible = false;

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

		TPoint greenLevel[cZelen];
		TPoint yellowLevel[cGelt];
		TPoint redLevel[cKrasn];


		Zelen[1][1] = StrToFloat(StaticText6->Caption);
		Zelen[0][1] = StrToFloat(StaticText6->Caption);

		for (int i = 0; i < cZelen; ++i)
		{
			greenLevel[i].x = Series1->CalcXPosValue(Zelen[i][0]);
			greenLevel[i].y = Series1->CalcYPosValue(Zelen[i][1]);
		}

		HRGN rg1 = CreateRectRgn(Chart1->BottomAxis->IStartPos,
		Chart1->LeftAxis->IStartPos+1,
		Chart1->BottomAxis->IEndPos,
		Chart1->LeftAxis->IEndPos);
		Chart1->Canvas->Brush->Color = TColor(clGreen);
		Chart1->Canvas->Pen->Color = TColor(clGreen);
		SelectClipRgn(Chart1->Canvas->Handle, rg1);
		Chart1->Canvas->Polygon(greenLevel, 4);
		SelectClipRgn(Chart1->Canvas->Handle, 0);
		DeleteObject(rg1);


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


void __fastcall TForm3::N2Click(TObject *Sender)
{                      //вставить+++++++++++++++++
	TStringList* list = new TStringList();
    TTreeNode * TN;                                    
	TN = TreeView1->GetNodeAt(x1,y1);
	pathToFile = "";
	list->Add("\\" + TN->Text + "\\");
    while (TN->Parent)
	{
		TN = TN->Parent;
//			pathToFile = pathToFile + "\\" + TN->Text;
		list->Add("\\" + TN->Text);
	}
	for (int i = list->Count-1; i >= 0; i--)
		pathToFile += list->Strings[i];
	pathToFile = Form1->StaticText11->Caption.SubString(0,Form1->StaticText11->Caption.Length()-1) + pathToFile;
	//это ^ путь к директории В КОТОРОЙ будут создаваться новые файлы ОД с замерами

	TStringList* listXlsFiles = new TStringList();
	listXlsFiles = Form1->ListFiles(pathToFile);
	list->Clear();
	for (int i = 0; i < listXlsFiles->Count; i++)
		if (listXlsFiles->Strings[i].Pos("xls") && !listXlsFiles->Strings[i].Pos("~$"))
			list->Add(pathToFile +listXlsFiles->Strings[i]); //теперь тут список путей к Xls файлам

	too::objForMany = new moo::ParserInterface();
	too::objForMany->setPathList(list);
		//мега цикл перебора ОД файлов, выбора из них параметров
		//для просчета, и собственно просчета всех 88 (в тестовом прогоне)
		//экселевских файлов
	for (int i = 0; i < too::listFromFileODGlobal->Count; i++)
	{
		TStringList* bufferForOdFile = new TStringList();
		//это список, в который будет загружаться содержимое ОД файла за каждый виток цикла
		bufferForOdFile->LoadFromFile(too::listFromFileODGlobal->Strings[i]);
		//теперь тут будет 1 ОД файл, из которого выбираются нужные параметры поиска
		too::objForMany->setChannel(bufferForOdFile->Strings[1].SubString(1, 1));
		too::objForMany->setRanges(bufferForOdFile->Strings[0].SubString(2, bufferForOdFile->Strings[0].Length()-2));
		too::objForMany->setDiagnObj(bufferForOdFile->Strings[2]);
		too::objForMany->MassFreqClearing();
		too::objForMany->setMassFreq(StrToFloat(bufferForOdFile->Strings[5]));
		if (bufferForOdFile->Strings[6] != "")
			too::objForMany->setMassFreq(StrToFloat(bufferForOdFile->Strings[6]));
		if (bufferForOdFile->Strings[7] != "")
			too::objForMany->setMassFreq(StrToFloat(bufferForOdFile->Strings[7]));
		too::objForMany->setLevelWarn(bufferForOdFile->Strings[3]);
		too::objForMany->setLevelCrash(bufferForOdFile->Strings[4]);
		too::objForMany->setFreqBand(StrToInt(bufferForOdFile->Strings[1].SubString(3, bufferForOdFile->Strings[1].Length() - 2)));
		too::objForMany->getCoordinates();
		String s2 = too::listODGlobalNames->Strings[i];
		too::objForMany->setNameDO(too::listODGlobalNames->Strings[i] + "(c)");
		too::objForMany->saveToFile();

		//отладочные переменные-------------
	 //	int z = bufferForOdFile->Strings[0].Length()-1;
	 //	String s = bufferForOdFile->Strings[0].SubString(2, bufferForOdFile->Strings[0].Length()-2);
		
		//----------------------------------end-
	}
		
	//
	//тут должна быть функция, организующая перебор файлов .xls по параметрам, заданным
	//в файлах .od, в директории, в которую осуществляется вставка



	
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N1Click(TObject *Sender)
{                     //копировать ++++++++++++++++++++++++++++++++

   // too::objForMany->setPathList(); //установка путей к xls файлам для пересчета
	//
	pathToFile = "";
	TStringList* listFromFileOD = new TStringList();
	TStringList* listFilesOD = new TStringList();
	TTreeNode * TN;
	TN = TreeView1->GetNodeAt(x1,y1);
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
	pathToFile = Form1->StaticText11->Caption.SubString(0,Form1->StaticText11->Caption.Length()-1) + pathToFile;
	too::listODGlobalNames = new TStringList(); //это список ТОЛЬКО ИМЕН од файлов для удобства
	listFromFileOD->Clear();
	listFilesOD = Form1->ListFiles(pathToFile);
	
	for (int i = 0; i < listFilesOD->Count; i++)
		if (listFilesOD->Strings[i].Pos(".od"))
		{
			listFromFileOD->Add(pathToFile + "\\" +listFilesOD->Strings[i]); //теперь тут список od файлов
			too::listODGlobalNames->Add(listFilesOD->Strings[i]);
		}
	too::listFromFileODGlobal = listFromFileOD;
//	String s = too::listFromFileODGlobal->Strings[0];
//	String s1 = too::listODGlobalNames->Strings[0];
	 //состав файла .od
   //	String s = TreeView1->GetNodeAt(x1,y1)->Text;

}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button3Click(TObject *Sender)
{
		//
	Form1->Visible = true;	
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N3Click(TObject *Sender)
{    //копировать несколько ++++++++++++++++++++++
	Form3->N1->Click(); //прогон нужен для заполнения too::listODGlobalNames
	// тут будет выборка ОД файлов, которые отмечены галочкой в ЧекЛистБоксе
    CheckListBox1->Clear();
	CheckListBox1->Visible = true;
	Button4->Visible = true;
	TTreeNode * TN;
	TN = TreeView1->GetNodeAt(x1,y1)->getFirstChild();

	for (int i = 0; i < too::listODGlobalNames->Count; i++)
		CheckListBox1->Items->Add(too::listODGlobalNames->Strings[i]);

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
	//тут будет корректировка списка ОД файлов
	//обоих списков, путей и просто названий
	CheckListBox1->Visible = false;
	Button4->Visible = false;
	TStringList* bufferListODpath = new TStringList();
	TStringList* bufferListODname = new TStringList();
	for (int i = 0; i < too::listFromFileODGlobal->Count; i++)
	{
		if (CheckListBox1->Checked[i])
		{
			bufferListODpath->Add(too::listFromFileODGlobal->Strings[i]);
			bufferListODname->Add(too::listODGlobalNames->Strings[i]);
		}
	}
	if (bufferListODpath->Count)
	{
		too::listFromFileODGlobal = bufferListODpath;
		too::listODGlobalNames = bufferListODname;
	}
	
	// CheckListBox1->Checked[i];
}
//---------------------------------------------------------------------------

