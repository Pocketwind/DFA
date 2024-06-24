#include<iostream>
#include<string>
using namespace std;

int get_state_index(char input)
{
	switch (input)
	{
	case 'A':
		return 0;
		break;
	case 'B':
		return 1;
		break;
	case 'C':
		return 2;
		break;
	case 'D':
		return 3;
		break;
	case 'E':
		return 4;
		break;
	}
	return -1;
}
int get_word_index(char input)
{
	switch (input)
	{
	case 'a':
		return 0;
		break;
	case 'b':
		return 1;
		break;
	}
	return -1;
}

void DFA_Recognize(string input, char start, char* end, int end_size, char table[][2])
{
	if (input.length() == 0)
	{
		cout << "Empty String" << endl;
		return;
	}

	char current_state = start;
	char current;
	for (int i = 0; i < input.length(); ++i)
	{
		current = input[i];
		int state_index = get_state_index(current_state);
		int word_index = get_word_index(current);
		if (state_index == -1 || word_index == -1)
		{
			cout << "Reject" << endl;
			return;
		}
		//word, state 목록 만족하는지 체크
		char next = table[state_index][word_index];
		//만족하면 next state 테이블에서 가져옴

		current_state = next;
	}

	//final 체크
	for (int i = 0; i < end_size; ++i)
	{
		if (current_state == end[i])
		{
			cout << "Accept" << endl;
			return;
		}
	}
	cout << "Reject" << endl;
}

int main()
{
	string input;
	cout << "Input : ";
	cin >> input;

	char start = 'A';
	char end[] = { 'B','D' };
	int end_size = 2;
	char table[5][2] = { 
		{'B','A'},
		{'D','C'},
		{'E',NULL},
		{'D','E'},
		{'D','A'}
	};

	DFA_Recognize(input, start, end, end_size, table);

	return 0;
}