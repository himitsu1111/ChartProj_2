//---------------------------------------------------------------------------

#ifndef ExcelHelperH
#define ExcelHelperH
//---------------------------------------------------------------------------
#include <vector>

#include "Excel_XP_srvr.h"
#include <OleServer.hpp>
#include "excel_xp_srvr.h"


#pragma link "Excel_XP_srvr"
#pragma link "excel_xp_srvr"
//---------------------------------------------------------------------------
class XlsHelper
{
	private:
	TExcelApplication * XlsApp;
	TExcelWorkbook * XlsBook;
 //	TExcelWorksheet * XlsSheet;
	String PathToLastFile;
	int myRange; //диапазон значений для выборки из Xls. 800 || 1600
	int rangeOfMidValue; //указывает +/- диапазон значений выборки из столбца B
	float searchingValueL; //индекс найденного числа
	float searchingValueR; //соответсвенное индексу число в столбце B
  //	float searchingValue; //приходящее число, которое необходимо найти, одно из 800.
    std::vector<float> ColumnLeft; //массив значений выбранных из Xls
    Variant XlsRange;
 //   std::vector<float> ColumnRight;


	public:
	XlsHelper();
	~XlsHelper();
	std::vector<float> MakeMas(AnsiString, float); //возвращает вектор из 7 значений
										//выбранных из 800. каждый раз обращается к Xls
	float MakeSqrtSum(String); //суммирует все 800 значений и возвращает среднеквадратичное

	int LogSearching(float StartingPoint);//возвращает индекс найденного элемента

	void setMyRange(int a) { myRange = a; } ;
	int getMyRange() { return myRange; };

	float getSearchingValueL() { return searchingValueL; };
};


//---------------------------------------------------------------------------
#endif
