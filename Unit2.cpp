//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Support.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Chart1BeforeDrawAxes(TObject *Sender)
{
	//
//	moo::DrawOnChart(StrToFloat(Form1->Edit4->Text), StrToFloat(Form1->Edit5->Text));
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
//	TLineSeries* SS =new TLineSeries(Form2->Chart1);
//	SS->CalcXPosValue();
	TPoint yellowLevel[cGelt];
	TPoint redLevel[cKrasn];

	yellowLevel[0].x = 0;
	yellowLevel[1].x = 0;
	yellowLevel[2].x = Chart1->LeftAxis->CalcYPosValue(StrToFloat(Form1->Edit5->Text));
	yellowLevel[3].x = Chart1->LeftAxis->CalcYPosValue(StrToFloat(Form1->Edit5->Text));

	yellowLevel[0].y = 0;
	yellowLevel[1].y = Chart1->LeftAxis->CalcXPosValue(StrToFloat(Form1->Edit4->Text)); //������� �������
	yellowLevel[2].y = Chart1->LeftAxis->CalcXPosValue(StrToFloat(Form1->Edit4->Text)); //������� �������
	yellowLevel[3].y = 0;


	HRGN rg = CreateRectRgn(Chart1->BottomAxis->IStartPos,
	Chart1->LeftAxis->IStartPos+1,
	Chart1->BottomAxis->IEndPos,
	Chart1->LeftAxis->IEndPos);
	Chart1->Canvas->Brush->Color = TColor(0x0073F273);
	Chart1->Canvas->Pen->Color = TColor(0x0073F273);
	SelectClipRgn(Chart1->Canvas->Handle, rg);
	Chart1->Canvas->Polygon(yellowLevel, 4);
	SelectClipRgn(Chart1->Canvas->Handle, 0);
	DeleteObject(rg);

	
}
//---------------------------------------------------------------------------

