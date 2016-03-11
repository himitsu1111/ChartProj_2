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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox1;
	TListBox *ListBox1;
	TMemo *Memo1;
	TComboBox *ComboBox2;
	TChart *Chart1;
	TButton *Button1;
	TButton *Button2;
	TComboBox *ComboBox3;
	TRadioGroup *RadioGroup1;
	TButton *Button3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall ComboBox3Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
