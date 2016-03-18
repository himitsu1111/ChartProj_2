//---------------------------------------------------------------------------

#ifndef SupportH
#define SupportH

//---------------------------------------------------------------------------
#include <vector>
#include "ExcelHelper.h"

//---------------------------------------------------------------------------
namespace moo
{
	struct PointForChart
	{
		float B; //��������, ������� ���������� �������������� ����������
		AnsiString Date; //���� ������, ��������� � �������� �����, ���� ������ �����
//		PointForChart() { B = NULL; Date = NULL; };
//		~PointForChart();
	};

   //	void DrawOnChart(double A, double B) ;

	class ParserInterface
	{
		private:
		static String Channel; //�����
		static String Ranges;  //��� ��� ��
		String DiagnObj; //������ �����������
		std::vector<float> MassFreq; //������ ��������������� ���������, ������ (���� 1 ���� 3, ���� DaignObj - ���������)
		std::vector<PointForChart> ListOfPoints; //������ �������� ���� (�����; �����; ����) 7 ����!
		TStringList * DateList; //������ ��� (�� ������ ������, ����� �������� �� ����������)
		TStringList * PathList; //�������� ������ ����� � ������
		XlsHelper* M;

		int SV;

		void Calculating(); //������ � ������� ������ ������,
							//� �������� ������ �������� � ������������ (�������� - ����)
		std::vector<float> CalcDiagnParam(TStringList*); //�������� ������� �� 7 �������� �� ����� �� 6 ������,
								//� ���-�� �� ������� �����������
		String GettingDate(String); //����� ���� �� ������ � ����� � �����

		public:
		ParserInterface();
		ParserInterface(TStringList*);

		~ParserInterface()
		{
			MassFreq.clear();
			ListOfPoints.clear();
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

		TStringList* getDateList() { Calculating(); return DateList; };

		bool setMassFreq(float a) { if (MassFreq.size() < 3) { MassFreq.push_back(a); return true; } else return false; } ;
		std::vector<float> getMassFreq() { return MassFreq; };
		int MassFreqCount() { return MassFreq.size(); } //���������� ������ ������� ������
		void MassFreqClearing() { MassFreq.clear(); std::vector<float>(MassFreq).swap(MassFreq); } //������ ������ ������

		std::vector<PointForChart> getCoordinates() { Calculating(); MassFreq.clear(); return ListOfPoints; };


	};
	String ParserInterface::Channel = "2_";
    String ParserInterface::Ranges = "_���_";
	ParserInterface::ParserInterface() : MassFreq(0), M(NULL) {}
	ParserInterface::ParserInterface(TStringList* Path) : MassFreq(0) { PathList = Path; }
}

//---------------------------------------------------------------------------
#endif
