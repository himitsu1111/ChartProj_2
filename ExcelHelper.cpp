

#include <vcl.h>
#include <vector>

//#include <algorithm>
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
	int myRange; //диапазон значений для выборки из Xls. 800 || 1600
	int rangeOfMidValue; //указывает +/- диапазон значений выборки из столбца B
	float searchingValueL; //индекс найденного числа
	float searchingValueR; //соответсвенное индексу число в столбце B
	float searchingValue; //приходящее число, которое необходимо найти, одно из 800.
	std::vector<float> Column;

 //   std::vector<float> ColumnRight;


	public:
	XlsHelper();
	~XlsHelper();
	std::vector<float> MakeMas(AnsiString);

	int LogSearching(Variant& a, float StartingPoint);//возвращает индекс найденного элемента

	void setMyRange(int a) { myRange = a; } ;
	int getMyRange() { return myRange; };

	float getSearchingValueL() { return searchingValueL; };
};
XlsHelper::XlsHelper()
{
	myRange = 800;
	searchingValue = 111.;
	rangeOfMidValue = 3;
//	RangeLeft = "A";
//	RangeRight = "B";
//	XlsApp = NULL;
//	XlsBook = NULL;
//	XlsSheet = NULL;
	//XlsApp->Range->get_Range()->get_value()
}
XlsHelper::~XlsHelper()
{
   	delete XlsApp;
	delete XlsBook;
	delete XlsSheet;
}
std::vector<float> XlsHelper::MakeMas(AnsiString PathToFile)
{
   //	delete XlsApp;
	XlsApp = new TExcelApplication(NULL);
	XlsApp->Visible[0] = false;
	String Str = PathToFile.SubString(0, PathToFile.Length()-2);
	XlsApp->Workbooks->Open(WideString(PathToFile.SubString(0, PathToFile.Length()-2)));//"c:\\676\\Chiron FZ15W\\0120272323\\2_СВС_03.06.13.xlsx"));

	Variant A = XlsApp->Range[Variant("A" + IntToStr(14) +
							  ":B" + IntToStr(myRange) + IntToStr(13))]->get_Value();
							  //получение массива Variant из диапазона файла Xls
	//A.GetElement(index,column); начинают отсчет с 1!
	searchingValueL = LogSearching(A, searchingValue);
//	}                                590
	int c = rangeOfMidValue;
	for (int i = 0; i < rangeOfMidValue*2+1; i++)
		Column.push_back(A.GetElement(searchingValueL-(--c),2));
	int si = Column.size();	                        // ^ разница в индексах с ренжой из экселя. не забудь!!!
	float a1 = Column[0];
	float a2 = Column[1];
	float a3 = Column[2];
	float a4 = Column[3];
	float a5 = Column[4];
	float a6 = Column[5];
	float a7 = Column[6];
	return Column;
}
int XlsHelper::LogSearching(Variant& a, float StartingPoint)
{   //возвращает индекс найденного элемента.
//	div_t x;
//	x = div(StartingPoint/2);
//	x.quot;
	std::vector<float> ColumnLeft;
	for (int i = 0; i < myRange; i++)
		ColumnLeft.push_back(a.GetElement(i+1,1));
	int iteration = 0, left = 0,
		right = ColumnLeft.size()-1, mid;
		int e = ColumnLeft[0];
		int e1 = ColumnLeft[13];
		int e2 = ColumnLeft[14];
		int e3 = ColumnLeft[799];
		int e4 = ColumnLeft[399];
	  //	bool Boo = binary_search(ColumnLeft.begin(),ColumnLeft.end(),StartingPoint);
	while(left <= right)
	{
		iteration++;
		mid = (int)((left + right)/2);
		float d = ColumnLeft[mid];

		if (StartingPoint == ColumnLeft[mid])
		{
			
			//return ColumnLeft[mid];
			return mid;
		}
		else
		{
			if (StartingPoint > ColumnLeft[mid])
			{
            	left = mid + 1;
			}
			else
			{
            	right = mid - 1;
			}
		}
	}
	//return ColumnLeft[mid];
	return mid;
}
