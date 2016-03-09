#include <vcl.h>
#include <vector>
namespace moo
{
	struct PointForChart
	{
		float A; //��������, �� �������� ���������� �����
		float B; //��������, ������� ���������� �������������� ����������
		String Date; //���� ������, ��������� � �������� �����, ���� ������ �����

	};

	class ParserInterface
	{
		private:
		static String Channel; //�����
		String Ranges;  //��� ��� ��
		String DiagnObj; //������ �����������
		std::vector<int> Mass; //������ ��� ����� 800 ��������
		std::vector<PointForChart> ListOfPoints; //������ �������� ���� (�����; �����; ����) 7 ����!
		TStringList * DateList; //������ ��� (�� ������ ������, ����� �������� �� ����������)
		TStringList * PathList; //�������� ������ ����� � ������

		void Calculating(); //������ � ������� ������ ������,
							//� �������� ������ �������� � ������������ (�������� - ����)

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
