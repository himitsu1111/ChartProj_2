#include <vcl.h>
#include <vector>
#include "ExcelHelper.cpp"
namespace moo
{
	struct PointForChart
	{
		float A; //значение, по которому происходит поиск
		float B; //значение, которое выбирается соответственно найденному
		String Date; //дата замера, указанная в названии файла, либо внутри файла

	};

	class ParserInterface
	{
		private:
		static String Channel; //канал
		static String Ranges;  //свс сву со
		String DiagnObj; //объект диагностики
		std::vector<int> Mass; //массив тех самых 800 значений
		std::vector<PointForChart> ListOfPoints; //массив структур вида (число; число; дата) 7 штук!
		TStringList * DateList; //список дат (на всякий случай, потом возможно не пригодится)
		TStringList * PathList; //входящий список путей к файлам
		XlsHelper* M;

		void Calculating(); //расчет и парсинг файлов экселя,
							//и создание списка структур с координатами (значение - дата)

		public:
		ParserInterface();
		ParserInterface(TStringList*);

		~ParserInterface() {};

		void setChannel(String a) { Channel = a + "_"; };
		static String getChannel() {return Channel;};

		void setRanges(String a) { Ranges = "_" + a + "_"; };
		String getRanges() {return Ranges;};

		void setDiagnObj(String a) { DiagnObj = a; };
		String getDiagnObj() {return DiagnObj;};

		void setPathList(TStringList* a) { PathList = a; };
		TStringList* getPathList() {return PathList;};

		TStringList* getDateList() { Calculating(); return DateList; }; 



	};
	String ParserInterface::Channel = "2_";
    String ParserInterface::Ranges = "_СВС_";
	ParserInterface::ParserInterface() : Mass(0) {}
	ParserInterface::ParserInterface(TStringList* Path) : Mass(0) { PathList = Path; }

	void ParserInterface::Calculating()
	{
		M = new XlsHelper;
		TStringList * list = new TStringList();

		for (int i = 0; i < PathList->Count; i++)
		{
			if ((PathList->Strings[i].Pos(Channel)) && (PathList->Strings[i].Pos(Ranges)) )
				list->Add(PathList->Strings[i]); //отсортировываем необходимые файлы по
												 //номеру канала и СВС'ам
								//получаем список файлов, которые необходимо обработать
			
			M->MakeMas(list->Text);
			
		}
		DiagnObj = M->getColumnLeft();
	  // 	DateList = list;
	}
}
