#include <vcl.h>
#include "Support.h"


namespace too
{
	String mainPath;
	moo::ParserInterface* objForMany; //  new moo::ParserInterface();
	TStringList* listFromFileODGlobal; //������ ��� ����� � ������ �� ��� ������������� ���������
	TStringList* listODGlobalNames; //������ ���� �� ������
	bool markOfManyCharts = false;
	String odToFind; //������, � ������� ����� ����� ��� ������ �� ���������
						//����� - ��� �� ����.
	TStringList* listFindODpath = new TStringList();  //������ ����� � �� ������, ��������� ��� ���������
	TStringList* listFindODname;  //��������������� ������ ���� �� ������
	bool markSearchOd = false; //
	TStringList* listForAnalize; //������ ��� �������� ������� �������� ������� ������ � ��������������
    TStringList* listForManyAnalize; //������ ��� �������� �������, �� ���������� �� ������
}
