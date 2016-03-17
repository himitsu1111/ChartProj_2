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
	moo::DrawOnChart(StrToFloat(Form1->Edit4->Text), StrToFloat(Form1->Edit5->Text));
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
}
//---------------------------------------------------------------------------

