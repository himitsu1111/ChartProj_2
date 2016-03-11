

#include <vcl.h>
#include <vector>
#include "Excel_XP_srvr.h"
#include <OleServer.hpp>
#include "excel_xp_srvr.h"


#pragma link "Excel_XP_srvr"
#pragma link "excel_xp_srvr"
class XlsHelper
{
	private:
	TExcelApplication * XlsApp;
	TExcelWorkbook * XlsBook;
	TExcelWorksheet * XlsSheet;
	String RangeLeft;
	String RangeRight;
	std::vector<float> ColumnLeft;
	float C;
 //   std::vector<float> ColumnRight;


	public:
	XlsHelper();
	~XlsHelper();
	void MakeMas(AnsiString);
	float getC()
	{

			
		return C;
	}
};
XlsHelper::XlsHelper()
{
//	RangeLeft = "A";
//	RangeRight = "B";
//	XlsApp = NULL;
//	XlsBook = NULL;
//	XlsSheet = NULL;
	//XlsApp->Range->get_Range()->get_value()
}
XlsHelper::~XlsHelper()
{
   //	delete XlsApp;
	delete XlsBook;
	delete XlsSheet;
}
void XlsHelper::MakeMas(AnsiString PathToFile)
{
   //	delete XlsApp;
	XlsApp = new TExcelApplication(NULL);
	XlsApp->Visible[0] = false;

	XlsApp->Workbooks->Open(WideString("c:\\676\\Chiron FZ15W\\0120272323\\2_ÑÂÑ_03.06.13.xlsx"));
//	for (int i = 13; i < 815; i++)
//	{

	   Variant A = XlsApp->Range[Variant("A" + IntToStr(14))]->get_Value(); //ןונובמנ כוגמדמ סעמכבצא
//	   Variant B = XlsApp->Range[Variant(RangeRight + IntToStr(i))]->get_Value();//ןונובמנ ןנאגמדמ סעמכבצא
	   C = A;
//	   ColumnLeft.push_back(C);


//	}
		
}
