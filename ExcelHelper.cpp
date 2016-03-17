//---------------------------------------------------------------------------


#pragma hdrstop

#include "ExcelHelper.h"

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
#pragma package(smart_init)
