//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "Chart.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <ExtCtrls.hpp>
#include "Series.hpp"
#include <Menus.hpp>
#include <CheckLst.hpp>

//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TTreeView *TreeView1;
	TGroupBox *GroupBox4;
	TStaticText *StaticText4;
	TGroupBox *GroupBox5;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TGroupBox *GroupBox6;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TStaticText *StaticText10;
	TButton *Button1;
	TChart *Chart1;
	TButton *Button2;
	TLineSeries *Series1;
	TStaticText *StaticText5;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TGroupBox *GroupBox7;
	TStaticText *StaticText3;
	TStaticText *StaticText11;
	TStaticText *StaticText12;
	TButton *Button3;
	TCheckListBox *CheckListBox1;
	TMenuItem *N3;
	TButton *Button4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall TreeView1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Chart1BeforeDrawAxes(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	void ListFilesToo(TTreeNode* TN, const String& DirName);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
