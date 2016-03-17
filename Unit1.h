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
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
