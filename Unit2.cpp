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
}
//---------------------------------------------------------------------------

