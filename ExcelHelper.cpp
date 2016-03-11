#include "Excel_XP_srvr.h"
#include <OleServer.hpp>
#include "excel_xp_srvr.h"
#include <vector>

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
 //   std::vector<float> ColumnRight;


	public:
	XlsHelper();
	~XlsHelper();
	void MakeMas(AnsiString);
	String getColumnLeft()
	{
		String Z = "";
		for (std::vector<float>::iterator it = ColumnLeft.begin(); it != ColumnLeft.end(); ++it)
			Z = Z + FloatToStr(*it);
			
		return Z;
	}
};
XlsHelper::XlsHelper()
{
	RangeLeft = "A";
    RangeRight = "B";
	XlsApp = NULL;
	XlsBook = NULL;
	XlsSheet = NULL;
	//XlsApp->Range->get_Range()->get_value()
}
XlsHelper::~XlsHelper()
{
	delete XlsApp;
	delete XlsBook;
	delete XlsSheet;
}
void XlsHelper::MakeMas(AnsiString PathToFile)
{
	wchar_t wstr[50];
	delete XlsApp;
	XlsApp = new TExcelApplication(NULL);
	XlsApp->Visible[0] = false;
	PathToFile.WideChar(wstr, 50);
	XlsApp->Workbooks->Open(PathToFile.WideChar(wstr, 50));
	for (int i = 13; i < 815; i++)
	{

	   Variant A = XlsApp->Range[Variant(RangeLeft + IntToStr(i))]->get_Value(); //ןונובמנ כוגמדמ סעמכבצא
	   Variant B = XlsApp->Range[Variant(RangeRight + IntToStr(i))]->get_Value();//ןונובמנ ןנאגמדמ סעמכבצא
       float C = A;
	   ColumnLeft.push_back(C);


	}
		
}
