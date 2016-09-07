//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Chart.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <ExtCtrls.hpp>
#include "Series.hpp"
#include "Unit3.h"
#include "excel_xp_srvr.h"
#include <OleServer.hpp>
#include <Dialogs.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox1;
	TListBox *ListBox1;
	TMemo *Memo1;
	TComboBox *ComboBox2;
	TButton *Button1;
	TButton *Button2;
	TComboBox *ComboBox3;
	TRadioGroup *RadioGroup1;
	TButton *Button3;
	TComboBox *ComboBox4;
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TGroupBox *GroupBox2;
	TEdit *Edit4;
	TEdit *Edit5;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TEdit *Edit6;
	TExcelApplication *ExcelApplication1;
	TGroupBox *GroupBox3;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TGroupBox *GroupBox4;
	TComboBox *ComboBox5;
	TStaticText *StaticText10;
	TStaticText *StaticText11;
	TSaveDialog *SaveDialog1;
	TRadioGroup *RadioGroup2;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall ComboBox3Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ComboBox4Change(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ComboBox5Change(TObject *Sender);
	void __fastcall StaticText11Click(TObject *Sender);
	void __fastcall RadioGroup2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TStringList* ListFiles(const String &DirName);
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
