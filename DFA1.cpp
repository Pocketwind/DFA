#include<iostream>
#include<string>
#include<vector>
using namespace std;



int get_word_index(char input)
{
	switch (input)
	{
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	}
	return -1;
}
int get_state_index(char input)
{
	switch (input)
	{
	case 'p':
		return 0;
		break;
	case 'q':
		return 1;
		break;
	case 'r':
		return 2;
		break;
	}
	return -1;
}

void DFA_Recognize(string input, char start, char end, char table[][2])
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

	if (current_state == end)
		cout << "Accept" << endl;
	else
		cout << "Reject" << endl;
}

int main()
{
	string input;
	cout << "Input : ";
	cin >> input;

	char start = 'p', end = 'r';
	char table[3][2] = { {'q','p'},{'r','p'},{'r','r'} };

	DFA_Recognize(input, start, end, table);

	return 0;
}