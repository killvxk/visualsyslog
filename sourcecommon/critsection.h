
#include <windows.h>

/*
  ������ ��� ������ � ����������� ������� Windows
  �����: ������� �.

  ������ �������������:

  // �������� ����������� ������
  TCritSection cs;

  void f(void)
  {
    TCritSectionEnter cse(&cs); // ��������� ����������� ������ cs

    // .. ��� ������ ���������� ...

    // ���������� ������������� ��������� ������������ TCritSectionEnter
    // ��� ������ ������� cse �� ���� "���������"
  }
*/

//---------------------------------------------------------------------------
// ����� ������� ��� ������� win api "����������� ������"
class TCritSection
{
  CRITICAL_SECTION busy;

public:
  TCritSection();       // ������� ������ win api "����������� ������"
  ~TCritSection();      // ���������� ���

  void Enter(void);     // ���������
  BOOL TryEnter(void);  // ������� �����������, ���� �������� - ���������
                        // � ���������� true, ���� ������ - �� ���������
                        // � ���������� false
  void Leave(void);     // ������� ����������
};
//---------------------------------------------------------------------------
// ����� "����� ����������" ����������� ������ TCritSection
class TCritSectionEnter
{
  TCritSection * pcs;

public:
  TCritSectionEnter(TCritSection * _pcs);
  ~TCritSectionEnter();
};
//---------------------------------------------------------------------------

