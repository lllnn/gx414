# gx414
vector<string> Convert(string& s)
{

	vector<string> v;//转换后输出的向量
	stack<char> sstack;//中转栈
	string nums = "0123456789";
	string oper_ = "+-*/()";
	string st = ""; //中转字符串
	for (int i = 0; i < s.size(); i++)
	{
		if (nums.find(s[i]) != string::npos)
		{
			st = st + s[i];
			if (oper_.find(s[i + 1]) != string::npos || s[i + 1] == NULL)
			{
				v.push_back(st);
				st = "";
			}
		}
		else if (s[i] == '(')
		{
			sstack.push(s[i]);
		}
		else if (s[i] == ')')
		{
			char temp = sstack.top();
			sstack.pop();
			if (temp != '(')
			{
				st = "";
				st = st + temp;
				v.push_back(st);
				temp = sstack.top();
				sstack.pop();
			}
		}
		else
		{
			while (sstack.empty() == false && smap[sstack.top()] >= smap[s[i]])
			{
				st = "";
				st = st + sstack.top();
				v.push_back(st);
				sstack.pop();
			}
			sstack.push(s[i]);
		}
	}
	while (sstack.empty() == false)
	{
		st = "";
		st = st + sstack.top();
		sstack.pop();
		v.push_back(st);
	}
	return v;
}
string Calculate(vector<string>& v)
{
	
	string st;
	double x, y, z;
	stack<string> sstack;
	string oper_ = "+-*/";
	for (int i = 0; i < v.size(); i++)
	{
		if (oper_.find(v[i]) != string::npos)
		{
			if (!sstack.empty())
			{
				x = std::stoi(sstack.top());
				sstack.pop();
			}
			else return "error";
			if (!sstack.empty())
			{
				y = std::stoi(sstack.top());
				sstack.pop();
			}
			else return "error";
			
			if (v[i] == "+")
			{
				z = x + y;
				st = to_string(z);
				sstack.push(st);
			}
			else if (v[i] == "-")
			{
				z = y - x;
				st = to_string(z);
				sstack.push(st);
			}
			else if (v[i] == "*")
			{
				z = x * y;
				st = to_string(z);
				sstack.push(st);
			}
			else if (v[i] == "/")
			{
				z = y/x;
				st = to_string(z);
				sstack.push(st);
			}
		}
		else
		{
			sstack.push(v[i]);//将string类型的数字压入栈中
		}
	}
	st = sstack.top();
	return st;
	
}
