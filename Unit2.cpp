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

	TPoint yellowLevel[cGelt];
	TPoint redLevel[cKrasn];

	yellowLevel[0].x = 0;
	yellowLevel[1].x = 0;
	yellowLevel[2].x = 1000;
	yellowLevel[3].x = 1000;

	yellowLevel[0].y = 0;
	yellowLevel[1].y = 20; //верхняя граница
	yellowLevel[2].y = 20;
	yellowLevel[3].y = 0;


	HRGN rg = CreateRectRgn(1, 2, 3, 4);
	Chart1->Canvas->Brush->Color = TColor(0x0073F273);
	Chart1->Canvas->Pen->Color = TColor(0x0073F273);
	SelectClipRgn(Chart1->Canvas->Handle, rg);
	Chart1->Canvas->Polygon(yellowLevel, 4);
	SelectClipRgn(Chart1->Canvas->Handle, 0);
	DeleteObject(rg);

	
}
//---------------------------------------------------------------------------

