#include <vcl.h>
#include <vector>
#include "ExcelHelper.cpp"
namespace moo
{
	struct PointForChart
	{
		float B; //��������, ������� ���������� �������������� ����������
		AnsiString Date; //���� ������, ��������� � �������� �����, ���� ������ �����
//		PointForChart() { B = NULL; Date = NULL; };
//		~PointForChart();
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

		int SV;

		void Calculating(); //������ � ������� ������ ������,
							//� �������� ������ �������� � ������������ (�������� - ����)
		void CalcDiagnParam(); //�������� ������� �� 7 �������� �� ����� �� 6 ������,
								//� ���-�� �� ������� �����������

		public:
		ParserInterface();
		ParserInterface(TStringList*);

		~ParserInterface() {};

		void setChannel(String a) { Channel = a + "_"; };
		static String getChannel() {return Channel;};

		void setRanges(String a) { Ranges = "_" + a + "_"; };
		String getRanges() {return Ranges;};

		void setDiagnObj(String a) { DiagnObj = a; };
		String getDiagnObj() { Calculating(); return DiagnObj;};

		void setPathList(TStringList* a) { PathList = a; };
		TStringList* getPathList() {return PathList;};

		TStringList* getDateList() { Calculating(); return DateList; };

		int getSV() { Calculating(); return SV; } ;

	};
	String ParserInterface::Channel = "2_";
    String ParserInterface::Ranges = "_���_";
	ParserInterface::ParserInterface() : Mass(0) {}
	ParserInterface::ParserInterface(TStringList* Path) : Mass(0) { PathList = Path; }

	void ParserInterface::Calculating()
	{
		M = new XlsHelper;
		TStringList * list = new TStringList();
        PointForChart PFC;
		for (int i = 0; i < PathList->Count; i++)
		{
			if ((PathList->Strings[i].Pos(Channel)) && (PathList->Strings[i].Pos(Ranges)) )
				list->Add(PathList->Strings[i]); //��������������� ����������� ����� ��
												 //������ ������ � ���'��
								//�������� ������ ������, ������� ���������� ����������
			std::vector<float> counting = M->MakeMas(list->Text);
                //���������� �������� ��������, �� ������� ����� ������� �������


			for (int j = 0; j < counting.size(); j++)
			{
				PFC.B = counting[i];
				PFC.Date = "12.12.12";
				ListOfPoints.push_back(PFC);
			}
		}
	   //	DiagnObj = FloatToStr(M->getC());
	  // 	DateList = list;
      	delete M;
	}
}
