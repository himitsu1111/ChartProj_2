

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
 //	TExcelWorksheet * XlsSheet;
	String RangeLeft;
	String RangeRight;
	int myRange; //диапазон значений для выборки из Xls. 800 || 1600
	int rangeOfMidValue; //указывает +/- диапазон значений выборки из столбца B
	float searchingValueL; //индекс найденного числа
	float searchingValueR; //соответсвенное индексу число в столбце B
  //	float searchingValue; //приходящее число, которое необходимо найти, одно из 800.


 //   std::vector<float> ColumnRight;


	public:
	XlsHelper();
	~XlsHelper();
	inline std::vector<float> MakeMas(AnsiString, float); //возвращает вектор из 7 значений
										//выбранных из 800. каждый раз обращается к Xls
	float MakeSqrtSum(String); //суммирует все 800 значений и возвращает среднеквадратичное

	int LogSearching(Variant& a, float StartingPoint);//возвращает индекс найденного элемента

	void setMyRange(int a) { myRange = a; } ;
	int getMyRange() { return myRange; };

	float getSearchingValueL() { return searchingValueL; };
};
XlsHelper::XlsHelper()
{
	myRange = 800;
   //	searchingValue = 111.;
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
//	delete XlsBook;
 //	delete XlsSheet;
}
std::vector<float> XlsHelper::MakeMas(AnsiString PathToFile, float searchingValue)
{
   //	delete XlsApp;
	XlsApp = new TExcelApplication(NULL);
	std::vector<float> Column;
	XlsApp->Visible[0] = false;
	if (PathToFile.Pos("\r\0"))
		PathToFile = PathToFile.SubString(0, PathToFile.Length()-2);
	XlsApp->Workbooks->Open(WideString(PathToFile));//"c:\\676\\Chiron FZ15W\\0120272323\\2_СВС_03.06.13.xlsx"));

	Variant A = XlsApp->Range[Variant("A" + IntToStr(14) +
							  ":B" + IntToStr(myRange) + IntToStr(13))]->get_Value();
							  //получение массива Variant из диапазона файла Xls
	//A.GetElement(index,column); начинают отсчет с 1!
	searchingValueL = LogSearching(A, searchingValue);
//	}                                590
	int c = rangeOfMidValue;
	for (int i = 0; i < rangeOfMidValue*2+1; i++)
		Column.push_back(A.GetElement(searchingValueL-(--c),2));
													// ^ разница в индексах с ренжой из экселя. не забудь!!!
	int si = Column.size();	                        

  //	delete XlsApp;
	A.Empty();
	return Column;
}

float XlsHelper::MakeSqrtSum(String PathToFile)
{
	XlsApp = new TExcelApplication(NULL);
    if (PathToFile.Pos("\r\0"))
		PathToFile = PathToFile.SubString(0, PathToFile.Length()-2);
	XlsApp->Workbooks->Open(WideString(PathToFile));
    Variant A = XlsApp->Range[Variant("A" + IntToStr(14) +
							  ":B" + IntToStr(myRange) + IntToStr(13))]->get_Value();
	float X = 0;
	for (int i = 0; i < myRange; i++)
		X = X + (A.GetElement(i+1,2)*A.GetElement(i+1,2));
	X = Sqrt(X);
	A.Clear();
	return X;
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
	  //	bool Boo = binary_search(ColumnLeft.begin(),ColumnLeft.end(),StartingPoint);
	while(left <= right)
	{
		iteration++;
		mid = (int)((left + right)/2);

		if (StartingPoint == ColumnLeft[mid])
		{
			ColumnLeft.clear();
			ColumnLeft.swap(ColumnLeft);
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
	ColumnLeft.clear();
	ColumnLeft.swap(ColumnLeft);
	return mid;
}
