#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "History.h"
#include <string>
#include <fstream>
using namespace std;
// History 对话框

IMPLEMENT_DYNAMIC(History, CDialogEx)

History::History(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_history, pParent)
{

}

History::~History()
{
}

void History::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, str3);
}

BEGIN_MESSAGE_MAP(History, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON1, &History::OnBnClickedButton1)
END_MESSAGE_MAP()

int Countline(char* filename)
{
	ifstream in;
	int n = 0;
	string tmp;
	in.open(filename, ios::in);
	if (in.fail()) return 0;
	else
	{
		while (getline(in, tmp, '\n'))
		{
			n++;
		}
		in.close();
		return n;
	}
}
string readline(char* filename, int line)
{
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(filename, ios::in);
	lines = Countline(filename);
	while (getline(file, temp) && i < line - 1)
		i++;
	file.close();
	return temp;
}

// History 消息处理程序







void History::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}
