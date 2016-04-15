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
String pathToFile = "C:\\676"; //����� ��� ������ ���������� �������, ������� ����������,
								//� �� ������ ���� ��������
const cGelt = 4;          //��� ��������� �� ����� �����
double Gelt[cGelt][2] =
{ 	//x      y
	150000,    20,   //������ ������� ����   //�������������
	0,    		20,    //����� �������
	0,    		12,     //����� ������
	150000,    12     //������ ������
};
const cKrasn = 4;          //��� ��������� �� ����� �����
double Krasn[cKrasn][2] =
{ 	//x      y
	150000,    30,   //������ ������� ����   //�������������
	0,    		30,    //����� �������
	0,    		20,     //����� ������
	150000,    20     //������ ������
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
			if (TN) //������� ��� ������� �����. �������� ��������� �������� ������ ������� ��� ���� ������ ������
				ListFilesToo( TreeView1->Items->AddChild(TN, sr.Name),  DirName+"\\" + sr.Name);//�������� ���� ���� ��� ������ � ���������
			else
				ListFilesToo( TreeView1->Items->Add(TN, sr.Name),  DirName+"\\" + sr.Name);
			// List->Add(DirName+"\\" + sr.Name);//��������� �����
		}
		else if (sr.Name.Pos(".od"))// ����� ������ ����
		{
			// String Ext=ExtractFileExt(sr.Name).UpperCase();
			// if (Ext==".JPG") //����� �� ����������
		   //	List->Add(DirName+"\\" + sr.Name);//��������� �����
        	TreeView1->Items->AddChild(TN, sr.Name);
		}
	}
	while (!FindNext(sr));//���� �����, ���� �� ������ ���
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
		String fileName = TN->Text.SubString(0, TN->Text.Pos(".")-1); //��� ����� � �������
		while (TN->Parent)
		{
			TN = TN->Parent;
//			pathToFile = pathToFile + "\\" + TN->Text;
			listFromFileOD->Add("\\" + TN->Text);
		}
		for (int i = listFromFileOD->Count-1; i >= 0; i--)
			pathToFile += listFromFileOD->Strings[i];

		listFromFileOD->LoadFromFile(pathToFile); //������ �� ����� � �������
		/*
		��������� �����:
		0 - ������ ���� "_���_"
		1 - ����� ���� "1_"
		2 - ���� ������� �����. "�����"
		3 - ������� ��������������
		4 - ������� ������
		5 -	fx1, ������ ���� ������
		6 - fx2 ���� ""
		7 - fx3 ���� ""
		8 - ��������� ������� 1 ����� Xls
		9 - ���� ����� �����
		��� - ��������� �������
		����� - ����
		*/
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		Form3->Chart1->SeriesList->Clear(); //������� ������������ �����, ������� ������

		TLineSeries* ls = new TLineSeries(Form3->Chart1);

		StaticText1->Caption = fileName;
		//������������(��� �����) ����������� �� ����� �� �����

		StaticText4->Caption = listFromFileOD->Strings[0].SubString(2,3);
		//������ (���)

		StaticText2->Caption = listFromFileOD->Strings[2];
		//��� ������� (�����)

		StaticText8->Caption = "fx1 = " + listFromFileOD->Strings[5];
		//��������������� ������� fx1

		StaticText9->Caption = "fx2 = " + listFromFileOD->Strings[6];
		//��������������� ������� fx2

		StaticText10->Caption = "fx3 = " + listFromFileOD->Strings[7];
		//��������������� ������� fx3

		StaticText6->Caption = listFromFileOD->Strings[3];
		//������� ��������������

		StaticText7->Caption = listFromFileOD->Strings[4];
		//������� ������

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
{              //������� ��� �������� ������
	//
  //  AnsiString str1 = "C:\\676\\Chiron FZ15W\\012027\\test�1.od";
	AnsiString str = pathToFile += '\0'; //��������� � ������ ������ ������� ������ ��� ������
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

		//������ ������ ������� �������
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

