# gx414
void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
int countline(char* filename)
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
string Readline(char* filename, int line)
{
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(filename, ios::in);
	lines = countline(filename);
	while (getline(file, temp) && i < line - 1)
		i++;
	file.close();
	return temp;
}

void CMFCApplication1Dlg::OnBnClickedEnter()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	ofstream out("test.txt", ios_base::app);
	vector<string> v;
	string s;
	s = CT2A(str.GetString());
	out << s << "=";
	v = Convert(s);
	s=Calculate(v);
	out << s << endl;
	str2 = CString(s.c_str());
	str = L"";
	out.close();
	UpdateData(FALSE);
}
