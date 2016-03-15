//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Support.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
TForm1 *Form1;
moo::ParserInterface* Obj = new moo::ParserInterface();
//moo::ParserInterface* Obj = new moo::ParserInterface();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
TStringList* ListFiles(const String &DirName)
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TStrings* List;
	String Path = "C:\\676\\";
	List = ListFiles(Path);
	for (int i = 0; i < List->Count; i++)
		ComboBox1->Items->Add(List->Strings[i]);

	Memo1->Lines->Add(List->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	Memo1->Text = "1";
	TStrings* List;
	String Path = "C:\\676\\" + ComboBox1->Items->Strings[ComboBox1->ItemIndex];
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
	String Path = "C:\\676\\" + ComboBox1->Items->Strings[ComboBox1->ItemIndex] +
				  + "\\" + ComboBox2->Items->Strings[ComboBox2->ItemIndex];
	List = ListFiles(Path);
	int z = List->Count;
    for (int i = 0; i < List->Count; i++)
		ListOfFiles->Add("C:\\676\\" + ComboBox1->Items->Strings[ComboBox1->ItemIndex] +
				  + "\\" + ComboBox2->Items->Strings[ComboBox2->ItemIndex] + "\\" + List->Strings[i]);
	Memo1->Lines->Add(ListOfFiles->Text);
	
   	Obj->setPathList(ListOfFiles);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//	TStringList* ListOfFiles = new TStringList;
//	String Path = "C:\\676\\" + ComboBox1->Items->Strings[ComboBox1->ItemIndex] +
//				  + "\\" + ComboBox2->Items->Strings[ComboBox2->ItemIndex];
//	List = ListFiles(Path);

  //	moo::ParserInterface* Obj2 = new moo::ParserInterface();

	//Obj->setChannel("asdasd");
	//Memo1->Text = Obj->getChannel();
	//Obj->setChannel("test");
  //	Obj->setChannel("test");
	Memo1->Text = Obj->getPathList()->Text;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Memo1->Text = Obj->getDateList()->Text;	
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

   //	Memo1->Text = Obj->getCoordinates()[0].Date;
	std::vector<moo::PointForChart> VPFC = Obj->getCoordinates();
	for (int i = 0; i < VPFC.size(); i++)
        Memo1->Lines[i].Text = VPFC[i].Date;
	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox4Change(TObject *Sender)
{
	Obj->setMassFreq(111.);
	Obj->setDiagnObj(ComboBox4->Text);
}
//---------------------------------------------------------------------------

