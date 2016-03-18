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
	int myRange; //�������� �������� ��� ������� �� Xls. 800 || 1600
	int rangeOfMidValue; //��������� +/- �������� �������� ������� �� ������� B
	float searchingValueL; //������ ���������� �����
	float searchingValueR; //�������������� ������� ����� � ������� B
  //	float searchingValue; //���������� �����, ������� ���������� �����, ���� �� 800.
    std::vector<float> ColumnLeft; //������ �������� ��������� �� Xls
    Variant XlsRange;
 //   std::vector<float> ColumnRight;


	public:
	XlsHelper();
	~XlsHelper();
	std::vector<float> MakeMas(AnsiString, float); //���������� ������ �� 7 ��������
										//��������� �� 800. ������ ��� ���������� � Xls
	float MakeSqrtSum(String); //��������� ��� 800 �������� � ���������� ������������������

	int LogSearching(float StartingPoint);//���������� ������ ���������� ��������

	void setMyRange(int a) { myRange = a; } ;
	int getMyRange() { return myRange; };

	float getSearchingValueL() { return searchingValueL; };
};


//---------------------------------------------------------------------------
#endif
