//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "Support.h"
#include "Unit2.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "Series"
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
TStringList* TForm1::ListFiles(const String &DirName)
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

   //	Memo1->Text = Obj->getCoordinates()[0].Date;
	std::vector<moo::PointForChart> VPFC = Obj->getCoordinates();
//	String a1 = VPFC[0].Date;
//	String a2 = VPFC[1].Date;
//	String a3 = VPFC[2].Date;
//	String a4 = VPFC[3].Date;
	Form2->Chart1->SeriesList->Clear(); //������� ������������ �����, ������� ������
	TLineSeries* ls = new TLineSeries(Form2->Chart1);
   //	Chart1->AddSeries(ls);
	//Chart1->SeriesList->Clear();

    for (int i = 0; i < VPFC.size(); i++)
	{
//        Memo1->Lines->Add(VPFC[i].Date);
//		Memo1->Lines->Add(VPFC[i].B);

		ls->AddXY(StrToDate(VPFC[i].Date),VPFC[i].B, VPFC[i].Date, clRed);
	}

   //	Memo1->Lines->Add("\n");
    Form2->Chart1->View3D = false;
	Form2->Chart1->AddSeries(ls);
	Form2->Visible = true;
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
    Obj->MassFreqClearing();
	if (Key == VK_RETURN && Obj->MassFreqCount() == 0)
	{
		Obj->setMassFreq(StrToFloat(Edit1->Text));
	}
	 
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

