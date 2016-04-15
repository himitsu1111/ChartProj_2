//---------------------------------------------------------------------------

#ifndef SupportH
#define SupportH

//---------------------------------------------------------------------------
#include <vector>
#include "ExcelHelper.h"



//---------------------------------------------------------------------------
using namespace doo;
namespace moo
{
	struct PointForChart
	{
		float B; //значение, которое выбирается соответственно найденному
		AnsiString Date; //дата замера, указанная в названии файла, либо внутри файла
//		PointForChart() { B = NULL; Date = NULL; };
//		~PointForChart();
	};

   //	void DrawOnChart(double A, double B) ;

	class ParserInterface
	{
		private:
		static String Channel; //канал
		static String Ranges;  //свс сву со
		String DiagnObj; //объект диагностики
		String NameDO;
		std::vector<float> MassFreq; //массив диагностических признаков, частот (либо 1 либо 3, если DaignObj - подшипник)
		std::vector<PointForChart> ListOfPoints; //массив структур вида (число; число; дата) 7 штук!
		TStringList * LevelList; //список допустимых уровней (на всякий случай, потом возможно не пригодится)
		TStringList * PathList; //входящий список путей к файлам
		XlsHelper* M;
		String levelWarn;  //допустимые уровни, предупреждение и авария
		String levelCrash;

		int SV;

		void Calculating(); //расчет и парсинг файлов экселя,
							//и создание списка структур с координатами (значение - дата)
		std::vector<float> CalcDiagnParam(TStringList*); //пересчет массива из 7 значений по одной из 6 формул,
								//в зав-ти от объекта диагностики
		String GettingDate(String); //выбор даты из строки с путем к файлу

		public:
		ParserInterface();
		ParserInterface(TStringList*);

		~ParserInterface()
		{
//			MassFreq.clear();
//			std::vector<float>(MassFreq).swap(MassFreq);

            ListOfPoints.clear();
			std::vector<PointForChart>(ListOfPoints).swap(ListOfPoints);

			delete M;
		};

		void setChannel(String a) { Channel = a + "_"; };
		static String getChannel() {return Channel;};

		void setRanges(String a) { Ranges = "_" + a + "_"; };
		String getRanges() {return Ranges;};

		void setDiagnObj(String a) { DiagnObj = a; };
		String getDiagnObj() { Calculating(); return DiagnObj;};

		void setPathList(TStringList* a) { PathList = a; };
		TStringList* getPathList() {return PathList;};

	   //	TStringList* getDateList() { Calculating(); return DateList; };

		void setLevelWarn(String s) { levelWarn = s; };
        String getLevelWarn() {return levelWarn; };
        void setLevelCrash(String s) { levelCrash = s; };
        String getLevelCrash() {return levelCrash; };

		bool setMassFreq(float a) { if (MassFreq.size() < 3) { MassFreq.push_back(a); return true; } else return false; } ;
		std::vector<float> getMassFreq() { return MassFreq; };
		int MassFreqCount() { return MassFreq.size(); } //возвращает размер массива частот
		void MassFreqClearing() { MassFreq.clear(); std::vector<float>(MassFreq).swap(MassFreq); } //чистит массив частот

		std::vector<PointForChart> getCoordinates() { Calculating(); /*MassFreq.clear();*/ return ListOfPoints; };

		void setNameDO(String s) { NameDO = s; }; //имя файла с сохраненными расчетами и координатами графика
		void saveToFile(); //сохранение файла с результатами расчета и
						   //координатами точек для чарта.
		String getPathToSave(); // { return PathList->Strings[0].Pos("123"); }
			//возвращает путь к файлам Xls. ориентируется по пути к первому файлу,
			//потому что файлы все должны быть по одному пути

        TStringList* getListOfPoints();//возвращает строки с содержимым вектора ListOfFiles
	};
	String ParserInterface::Channel = "2_";
	String ParserInterface::Ranges = "_СВС_";
	ParserInterface::ParserInterface() : M(NULL) {}
	ParserInterface::ParserInterface(TStringList* Path) { PathList = Path; }
}

//---------------------------------------------------------------------------
#endif
