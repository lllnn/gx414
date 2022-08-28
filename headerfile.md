#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "History.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#ifndef HEAD_H_
#define HEAD_H_
#include<iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include<fstream>
using namespace std;
void Despace(string& s);
//中缀表达式转后缀
vector<string> Convert(string& s);
//对后缀表达式进行计算
string Calculate(vector<string>& s);
#endif
