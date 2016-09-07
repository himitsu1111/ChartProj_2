//---------------------------------------------------------------------------


#pragma hdrstop

#include "ExcelHelper.h"



//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
using namespace doo;

XlsHelper::XlsHelper(int a)
{
	myRange = a;
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
   //	ColumnLeft.clear();
   //	std::vector<float>(ColumnLeft).swap(ColumnLeft);
//	delete XlsBook;
 //	delete XlsSheet;
}

std::vector<float> XlsHelper::MakeMas(AnsiString PathToFile, float searchingValue)
{
	std::vector<float> Column;

	if (PathToFile != PathToLastFile)
	{
		XlsApp = new TExcelApplication(NULL);

		XlsApp->Visible[0] = false;
		if (PathToFile.Pos('\0'))
        	PathToFile = PathToFile.SubString(0, PathToFile.Length()-2);    


		XlsApp->Workbooks->Open(WideString(PathToFile));
		XlsRange = XlsApp->Range[Variant("A" + IntToStr(14) +
								  ":B" + IntToStr(myRange+14) /*+ IntToStr(13)*/)]->get_Value();
								  //получение массива Variant из диапазона файла Xls
		//A.GetElement(index,column); начинают отсчет с 1!

	}
    searchingValueL = LogSearching(searchingValue);
//	                                590
	int c = rangeOfMidValue;
	for (int i = 0; i < rangeOfMidValue*2+1; i++)
		Column.push_back(XlsRange.GetElement(searchingValueL-(--c),2));
													// ^ разница в индексах с ренжой из экселя. не забудь!!!
	int si = Column.size();	                        

    PathToLastFile = PathToFile;
	return Column;
}

float XlsHelper::MakeSqrtSum(String PathToFile)
{
	XlsApp = new TExcelApplication(NULL);
	if (PathToFile.Pos('\0'))
		PathToFile = PathToFile.SubString(0, PathToFile.Length()-2);
	XlsApp->Workbooks->Open(WideString(PathToFile));
    Variant A = XlsApp->Range[Variant("A" + IntToStr(14) +
							  ":B" + IntToStr(myRange+14) /*+ IntToStr(13)*/)]->get_Value();
	float X = 0;
	for (int i = 0; i < myRange; i++)
		X = X + (A.GetElement(i+1,2)*A.GetElement(i+1,2));
	X = Sqrt(X);
	A.Clear();
	return X;
}

int XlsHelper::LogSearching(float StartingPoint)
{   //возвращает индекс найденного элемента.
//	div_t x;
//	x = div(StartingPoint/2);
//	x.quot;
   //	std::vector<float> ColumnLeft;
    int arSize = XlsRange.ArrayHighBound(1);
	int iteration = 0, left = 0, right = XlsRange.ArrayHighBound(1)-1, mid;

	  //	bool Boo = binary_search(ColumnLeft.begin(),ColumnLeft.end(),StartingPoint);
	while(left <= right)
	{
		iteration++;
		mid = (int)((left + right)/2);

		if (StartingPoint == XlsRange.GetElement(mid+1,1))
		{
			return mid;
		}
		else
		{
			if (StartingPoint > XlsRange.GetElement(mid+1,1))
			{
            	left = mid + 1;
			}
			else
			{
            	right = mid - 1;
			}
		}
	}
	return mid;
}



//---------------------------------------------------------------------------
#pragma package(smart_init)
