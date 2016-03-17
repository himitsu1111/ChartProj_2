//---------------------------------------------------------------------------


#pragma hdrstop

#include "Support.h"

//---------------------------------------------------------------------------
using namespace moo;

void ParserInterface::Calculating()
{
	TStringList * list = new TStringList(); //������ ���������� ����� � ������ ������
	PointForChart PFC;
	ListOfPoints.clear();
	for (int i = 0; i < PathList->Count; i++)
	{
		if ((PathList->Strings[i].Pos(Channel)) && (PathList->Strings[i].Pos(Ranges)) )
			list->Add(PathList->Strings[i]); //��������������� ����������� ����� ��
											 //������ ������ � ���'��
	}						//�������� ������ ������, ������� ���������� ����������

   //	std::vector<float> counting = M->MakeMas(list->Text);
			//���������� �������� ��������, �� ������� ����� ������� �������
	 std::vector<float> buf = CalcDiagnParam(list); //��� ������� ���������� ��� ������� � ���� ������� float

	 for (int i = 0; i < list->Count; i++)
	 {
		PFC.B = buf[i];
		PFC.Date = GettingDate(list->Strings[i]);
		ListOfPoints.push_back(PFC);
	 }

//		for (int j = 0; j < counting.size(); j++)
//		{
//			PFC.B = counting[j];
//			PFC.Date = "12.12.12";
//			ListOfPoints.push_back(PFC);
//		}

   //	DiagnObj = FloatToStr(M->getC());
  // 	DateList = list;
	delete list;
}
std::vector<float> ParserInterface::CalcDiagnParam(TStringList* L)
{
	std::vector<float> result;
	M = new XlsHelper;
	float ReturningVal;
	for (int i = 0; i < L->Count; i++)
	{
		if (DiagnObj.Pos("��������"))
		{   //3 �������, � ������ �� 7 ��������.
			std::vector<float> X1 = M->MakeMas(L->Strings[i],MassFreq[0]);
			std::vector<float> X2 = M->MakeMas(L->Strings[i],MassFreq[1]);
			std::vector<float> X3 = M->MakeMas(L->Strings[i],MassFreq[2]);
			float X11, X22, X33;
			X11 = Sqrt(X1[0]*X1[0]+X1[1]*X1[1]+X1[2]*X1[2]
						+X1[3]*X1[3]+X1[4]*X1[4]
						+X1[5]*X1[5]+X1[6]*X1[6]);
			X22 = Sqrt(X2[0]*X2[0]+X2[1]*X2[1]+X2[2]*X2[2]
						+X2[3]*X2[3]+X2[4]*X2[4]
						+X2[5]*X2[5]+X2[6]*X2[6]);
			X33 = Sqrt(X3[0]*X3[0]+X3[1]*X3[1]+X3[2]*X3[2]
						+X3[3]*X3[3]+X3[4]*X3[4]
						+X3[5]*X3[5]+X3[6]*X3[6]);
			ReturningVal = X11 + X22 + X33;
			result.push_back(ReturningVal);
		}

		if (DiagnObj.Pos("�������")
			|| DiagnObj.Pos("�������")
			|| DiagnObj.Pos("����")
			|| DiagnObj.Pos("��������") )
		{
			String S = L->Strings[i];
			float F = MassFreq[0];

			std::vector<float> X1 = M->MakeMas(L->Strings[i],MassFreq[0]);
			ReturningVal = Sqrt(X1[0]*X1[0]+X1[1]*X1[1]+X1[2]*X1[2]
								+X1[3]*X1[3]+X1[4]*X1[4]
								+X1[5]*X1[5]+X1[6]*X1[6]);
			result.push_back(ReturningVal);
		}

		if (DiagnObj.Pos("������������"))
		{
			ReturningVal = M->MakeSqrtSum(L->Strings[i]);
			result.push_back(ReturningVal);
		}
	}
//		delete M;
	return result;
}

String ParserInterface::GettingDate(String s)
{
	return s.SubString(s.Length()-12,8);	
}

void DrawOnChart(double A, double B)
{
	
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
