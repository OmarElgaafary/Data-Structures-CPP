#include <iostream>
#include <string>
#include <stack>
bool is_valid_closing(char s1, char s2)
{
	if (s1 == '(' && s2 == ')')
		return true;
	else if (s1 == '{' && s2 == '}')
		return true;
	else if (s1 == '[' && s2 == ']')
		return true;
	else
		return false;
}

bool check_para(std::string& s, int length)
{
	std::stack<char> my_stack;
	for (int i = 0; i < length; ++i)
	{
		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
		{
			my_stack.push(s[i]);
		} 
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
		{
			if (my_stack.empty() || !is_valid_closing(my_stack.top(), s[i]))
				return false;
			else
			{
				my_stack.pop();
			}
		}
	}

	if (my_stack.empty())
		return true;
	else 
		return false;
}

int main()
{
	std::string str = "([{])";
	std::cout << check_para(str, 4);
}
