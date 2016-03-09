#include <vcl.h>
#include <vector>
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
		String Ranges;  //свс сву со
		String DiagnObj; //объект диагностики
		std::vector<int> Mass; //массив тех самых 800 значений
		std::vector<PointForChart> ListOfPoints; //массив структур вида (число; число; дата) 7 штук!
		TStringList * DateList; //список дат (на всякий случай, потом возможно не пригодится)
		TStringList * PathList; //входящий список путей к файлам

		void Calculating(); //расчет и парсинг файлов экселя,
							//и создание списка структур с координатами (значение - дата)

		public:
		ParserInterface();
		ParserInterface(TStringList*);

		~ParserInterface() {};

		void setChannel(String a) { Channel = a; };
		static String getChannel() {return Channel;};

		void setRanges(String a) { Ranges = a; };
		String getRanges() {return Ranges;};

		void setDiagnObj(String a) { DiagnObj = a; };
		String getDiagnObj() {return DiagnObj;};

		void setPathList(TStringList* a) { PathList = a; };
		TStringList* getPathList() {return PathList;};

		TStringList* getDateList() { return DateList; }; 



	};
	String ParserInterface::Channel = "test";
	ParserInterface::ParserInterface() : Ranges(0), Mass(0) {}
	ParserInterface::ParserInterface(TStringList* Path) : Ranges(0), Mass(0) { PathList = Path; }

	void ParserInterface::Calculating()
	{
		TStringList * list;
		for (int i = 0; i < PathList->Count; i++)
		{
			if ((PathList->Strings[i].Pos(Channel)) && (PathList->Strings[i].Pos(Ranges)) )
				list->Add(PathList->Strings[i]);

				

		}
	}
}
