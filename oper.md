void CMFCApplication1Dlg::OnBnClickedButtonMod()
{
	UpdateData(TRUE);
	if (str != "0")
		str = str + _T("(");
	else
		str = "(";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButtonSub()
{
	UpdateData(TRUE);
	str = str + _T("/");
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButtonPlus()
{
	UpdateData(TRUE);
	str = str + _T("*");
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButtonMin()
{
	UpdateData(TRUE);
	str = str + _T("-");
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButtonAdd()
{
	UpdateData(TRUE);
	str = str + _T("+");
	UpdateData(FALSE);
}

void CMFCApplication1Dlg::OnBnClickedButton10()
{
	UpdateData(TRUE);
	his.DoModal();
	int line = countline("test.txt"),i;
	his.change(line);
	CString st;
	for (i = line;i > 0;i--)
	{
		st = CString(Readline("test.txt", line).c_str());
		his.showstr(st);
	}
	UpdateData(FALSE);
}
