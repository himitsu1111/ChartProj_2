#include <vcl.h>
#include <vector>
#include "ExcelHelper.cpp"
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
		static String Ranges;  //��� ��� ��
		String DiagnObj; //������ �����������
		std::vector<int> Mass; //������ ��� ����� 800 ��������
		std::vector<PointForChart> ListOfPoints; //������ �������� ���� (�����; �����; ����) 7 ����!
		TStringList * DateList; //������ ��� (�� ������ ������, ����� �������� �� ����������)
		TStringList * PathList; //�������� ������ ����� � ������
		XlsHelper* M;

		void Calculating(); //������ � ������� ������ ������,
							//� �������� ������ �������� � ������������ (�������� - ����)

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
    String ParserInterface::Ranges = "_���_";
	ParserInterface::ParserInterface() : Mass(0) {}
	ParserInterface::ParserInterface(TStringList* Path) : Mass(0) { PathList = Path; }

	void ParserInterface::Calculating()
	{
		M = new XlsHelper;
		TStringList * list = new TStringList();

		for (int i = 0; i < PathList->Count; i++)
		{
			if ((PathList->Strings[i].Pos(Channel)) && (PathList->Strings[i].Pos(Ranges)) )
				list->Add(PathList->Strings[i]); //��������������� ����������� ����� ��
												 //������ ������ � ���'��
								//�������� ������ ������, ������� ���������� ����������
			
			M->MakeMas(list->Text);
			
		}
		DiagnObj = M->getColumnLeft();
	  // 	DateList = list;
	}
}
