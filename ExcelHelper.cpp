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

	public:
	XlsHelper();
	~XlsHelper();
};
XlsHelper::XlsHelper()
{

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
