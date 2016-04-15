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
#pragma link "Series"
#pragma resource "*.dfm"
TForm2 *Form2;

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
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Chart1BeforeDrawAxes(TObject *Sender)
{
	//
//	moo::DrawOnChart(StrToFloat(Form1->Edit4->Text), StrToFloat(Form1->Edit5->Text));

//	TLineSeries* SS =new TLineSeries(Form2->Chart1);
//	SS->CalcXPosValue();
	TPoint yellowLevel[cGelt];
	TPoint redLevel[cKrasn];


//	yellowLevel[0].x = 0;
//	yellowLevel[1].x = 0;
//	yellowLevel[2].x = Series1->CalcYPosValue(StrToFloat(Form1->Edit5->Text));
//	yellowLevel[3].x = Series1->CalcYPosValue(StrToFloat(Form1->Edit5->Text));
//
//	yellowLevel[0].y = 0;
//	yellowLevel[1].y = Series1->CalcXPosValue(StrToFloat(Form1->Edit4->Text)); //верхняя граница
//	yellowLevel[2].y = Series1->CalcXPosValue(StrToFloat(Form1->Edit4->Text)); //верхняя граница
//	yellowLevel[3].y = 0;

	Gelt[1][1] = StrToFloat(Form1->Edit4->Text);
	Gelt[0][1] = StrToFloat(Form1->Edit4->Text);

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
	Krasn[1][1] = StrToFloat(Form1->Edit5->Text);
	Krasn[0][1] = StrToFloat(Form1->Edit5->Text);

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



