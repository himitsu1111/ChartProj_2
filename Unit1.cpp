//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Support.h"
#include "Unit2.h"
#include "variables.cpp"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "Series"
#pragma link "excel_xp_srvr"
#pragma resource "*.dfm"
TForm1 *Form1;
moo::ParserInterface* Obj = new moo::ParserInterface();
//String mainPath;
//moo::ParserInterface* Obj = new moo::ParserInterface();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
TStringList* TForm1::ListFiles(const String &DirName)
{
	TStringList* List = new TStringList;
	List->Clear();
	TSearchRec sr;
	if (!FindFirst(DirName+"\\*.*", faAnyFile, sr))
		do
		{
			if (!(sr.Name == "." || sr.Name == ".." || sr.Name.Pos("~$")))//это показывать не надо
			if (sr.Attr & faDirectory)// найдена папка
			{
				/*ListFiles*/ List->Add(/*DirName+"\\" +*/ sr.Name);//, List);//вызывает сама себя для поиска в подпапках
				// List->Add(DirName+"\\" + sr.Name);//добавляет папки
			}
			else// иначе найден файл
			{
				// String Ext=ExtractFileExt(sr.Name).UpperCase();
				// if (Ext==".JPG") //поиск по расширению
				List->Add(/*DirName+"\\" +*/ sr.Name);//добавляет файлы
			}
		}
		while (!FindNext(sr));//ищем опять, пока не найдем все
	FindClose(sr);
	return List;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TStrings* List;
	TStringList* sl = new TStringList();
	
	//проверка существования файла с путем
	if (!FileExists("path.path"))
	{
		sl->Add("C:\\676\\");
		sl->SaveToFile("path.path");
	}

	sl->LoadFromFile("path.path");
	too::mainPath = sl->Strings[0];
	List = ListFiles(too::mainPath);
	for (int i = 0; i < List->Count; i++)
		ComboBox5->Items->Add(List->Strings[i]);
	StaticText11->Caption = too::mainPath;
	Memo1->Lines->Add(List->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox5Change(TObject *Sender)
{
	//
    Memo1->Text = "1";
	TStrings* List;
	String Path = too::mainPath + ComboBox5->Items->Strings[ComboBox5->ItemIndex];
	List = ListFiles(Path);
	ComboBox1->Clear();
	for (int i = 0; i < List->Count; i++)
		ComboBox1->Items->Add(List->Strings[i]);
}


//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	Memo1->Text = "2";
	TStrings* List;
	String Path = too::mainPath + ComboBox5->Items->Strings[ComboBox5->ItemIndex] +
							  "\\" + ComboBox1->Items->Strings[ComboBox1->ItemIndex];
	List = ListFiles(Path);
	ComboBox2->Clear();
	for (int i = 0; i < List->Count; i++)
		ComboBox2->Items->Add(List->Strings[i]);
}    
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
	TStrings* List;
	TStringList* ListOfFiles = new TStringList;
	String Path = too::mainPath + ComboBox5->Items->Strings[ComboBox5->ItemIndex] +
				   "\\" + ComboBox1->Items->Strings[ComboBox1->ItemIndex] + "\\" +
						ComboBox2->Items->Strings[ComboBox2->ItemIndex];
	List = ListFiles(Path);
	int z = List->Count;
    for (int i = 0; i < List->Count; i++)
		ListOfFiles->Add(too::mainPath + ComboBox5->Items->Strings[ComboBox5->ItemIndex] + "\\"
				+ ComboBox1->Items->Strings[ComboBox1->ItemIndex] 
				  + "\\" + ComboBox2->Items->Strings[ComboBox2->ItemIndex] + "\\" + List->Strings[i]);
	Memo1->Lines->Add(ListOfFiles->Text);
	
   	Obj->setPathList(ListOfFiles);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form3->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	Obj->setChannel(IntToStr(RadioGroup1->ItemIndex+1));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox3Change(TObject *Sender)
{
	Obj->setRanges(ComboBox3->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
		 //ГЛАВНАЯ КНОПКА ПО КОТОРОЙ ЗАПУСКАЕТСЯ ВСЁ ДЕЛО
		 //----------------------------------------------
		 
   //	Memo1->Text = Obj->getCoordinates()[0].Date;
	std::vector<moo::PointForChart> VPFC = Obj->getCoordinates();
//	String a1 = VPFC[0].Date;
//	String a2 = VPFC[1].Date;
//	String a3 = VPFC[2].Date;
//	String a4 = VPFC[3].Date;
	Form2->Chart1->SeriesList->Clear(); //удаляет отработанные серии, очищает график
	TLineSeries* ls = new TLineSeries(Form2->Chart1);
   //	Chart1->AddSeries(ls);
	//Chart1->SeriesList->Clear();

    for (int i = 0; i < VPFC.size(); i++)
	{
//        Memo1->Lines->Add(VPFC[i].Date);
//		Memo1->Lines->Add(VPFC[i].B);

		ls->AddXY(StrToDate(VPFC[i].Date),VPFC[i].B, VPFC[i].Date, clBlue);
	}

   //	Memo1->Lines->Add("\n");
    ls->Color = clBlue;
	Form2->Chart1->View3D = false;
	Form2->Chart1->AddSeries(ls);
	Form2->Chart1->Title->Text->Strings[0] = "";
	Form2->Caption = ComboBox1->Text + ", " + ComboBox2->Text + ", " + ComboBox3->Text;
	Form2->Visible = true;
	Obj->setLevelWarn(Edit4->Text);
	Obj->setLevelCrash(Edit5->Text);
//    delete Obj;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox4Change(TObject *Sender)
{
//	Obj->setMassFreq(111.);
//	Obj->setMassFreq(121.);
//	Obj->setMassFreq(131.);

	Obj->setDiagnObj(ComboBox4->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{

	if (Key == VK_RETURN && Obj->MassFreqCount() == 0)
	{
        Obj->MassFreqClearing();
		Obj->setMassFreq(StrToFloat(Edit1->Text));
	}
	Edit2->Text = "";
	Edit3->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
	if (Key == VK_RETURN && Obj->MassFreqCount() == 1)
	{
		Obj->setMassFreq(StrToFloat(Edit2->Text));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
	if (Key == VK_RETURN && Obj->MassFreqCount() == 2)
	{
		Obj->setMassFreq(StrToFloat(Edit3->Text));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	delete Obj;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	//
	Obj->setNameDO(Edit6->Text);
	Obj->saveToFile();	
}

//---------------------------------------------------------------------------


void __fastcall TForm1::StaticText11Click(TObject *Sender)
{
	//сохранение пути к главной папке
	if (SaveDialog1->Execute())
		too::mainPath = SaveDialog1->FileName;
	too::mainPath = too::mainPath.SubString(0,too::mainPath.Length()-1);
	TStringList * sl = new TStringList();
	sl->Add(too::mainPath);
	sl->SaveToFile("path.path");

	TStringList * List;
	List = ListFiles(too::mainPath);
	ComboBox5->Items->Clear();
	for (int i = 0; i < List->Count; i++)
		ComboBox5->Items->Add(List->Strings[i]);
	StaticText11->Caption = too::mainPath;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{                         //добавление диапазона 800-1600
	int i = RadioGroup2->ItemIndex;
	if (RadioGroup2->ItemIndex != -1)
	{
		Obj->setFreqBand((RadioGroup2->ItemIndex+1)*800);
	}

}
//---------------------------------------------------------------------------



