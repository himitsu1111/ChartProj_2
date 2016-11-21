#include <vcl.h>
#include "Support.h"


namespace too
{
	String mainPath;
	moo::ParserInterface* objForMany; //  new moo::ParserInterface();
	TStringList* listFromFileODGlobal; //список для путей к файлам ОД при множественном пересчете
	TStringList* listODGlobalNames; //список имен ОД файлов
	bool markOfManyCharts = false;
	String odToFind; //строка, в которой будет слово для поиска по каталогам
						//слово - это од файл.
	TStringList* listFindODpath = new TStringList();  //список путей к од файлам, найденным для сравнения
	TStringList* listFindODname;  //соответственный список имен ОД файлов
	bool markSearchOd = false; //
	TStringList* listForAnalize; //список для подсчета средних значений уровней аварии и предупреждения
    TStringList* listForManyAnalize; //список для подсчета средних, из нескольких ОД файлов
}
