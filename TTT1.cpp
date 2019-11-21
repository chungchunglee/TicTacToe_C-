#include "ttt.h"

TTT::TTT()
{
	a = 0; b = 0;
}

void TTT::print(int a, int b) 			// �׷��� ����ϴ� �Լ�
{
	for (int i = 1; i < 10; i++)
	{
		if ((i % 3) == 1) cout << endl << endl;
		if ((a >> (9 - i) & 1) == 1)
		{
			cout << "  O"; continue;
		}
		if ((b >> (9 - i) & 1) == 1)
		{
			cout << "  X"; continue;
		}
		cout << "  " << i;
	}
}

void TTT::In2(int* a, int* b)//a0000000000000�� �޴� �Լ�  
{
	int input;
	while (1)
	{
		cout << endl << endl << "  1���� 9�����߿��� ���� �Է��ϼ��� : ";
		cin >> input;
		if ((input > 9) || (input < 1))	cout << "  1~9������ ���ڸ� �Է��Ͻʽÿ�";
		else if (((1 << (9 - input)) | (*a)) == (*a)) cout << "  �̹� �Էµ� �ڸ��Դϴ� �ٽ� �Է��Ͽ� �ֽʽÿ�";
		else if (((1 << (9 - input)) | (*b)) == (*b)) cout << "  �̹� �Էµ� �ڸ��Դϴ� �ٽ� �Է��Ͽ� �ֽʽÿ�";
		else break;
	}
	*a |= (1 << (9 - input));
}

void TTT::In3(int* b, int input)//b���޴��Լ�  
{
	*b |= (1 << (9 - input));
}



void TTT::In(int* a, int* b)//���� �ް�  ��ȯ�ؼ�  a,b�� �����ϴ� �Լ�  
{
	int input;
	static int cnt = 1;
	//cout<<endl<<"���� a:"<<a<<"���� b:"<<b; Ȯ�ο� 
	while (1)
	{
		cout << endl << endl << "  1���� 9�����߿��� ���� �Է��ϼ��� : ";
		cin >> input;
		if ((input > 9) || (input < 1))	cout << "  1~9������ ���ڸ� �Է��Ͻʽÿ�";
		else if (((1 << (9 - input)) | (*a)) == (*a)) cout << "  �̹� �Էµ� �ڸ��Դϴ� �ٽ� �Է��Ͽ� �ֽʽÿ�";
		else if (((1 << (9 - input)) | (*b)) == (*b)) cout << "  �̹� �Էµ� �ڸ��Դϴ� �ٽ� �Է��Ͽ� �ֽʽÿ�";
		else break;
	}
	if (cnt & 1 == 1)
	{
		*a |= (1 << (9 - input));
		//cout<<"a��"<<bitset<8>(a); Ȯ�� 
	}
	else
	{
		*b |= (1 << (9 - input));
		// cout<<"b��"<<bitset<8>(b); Ȯ�� 
	}
	cnt++;

}



int TTT::vic(int* a, int* b) //�¸� �й� �Ǻ� 
{
	int w[8] = { w1,w2,w3,w4,w5,w6,w7,w8 };
	int i;


	for (i = 0; i < 8; i++)
	{
		if ((w[i] | (*a)) == (*a))
		{
			print(*a, *b);
			cout << endl << endl << "  ****  Player O�� �¸��Դϴ�  *****" << endl;
			return -1;
		}
		if (((*b) | w[i]) == (*b))
		{
			print(*a, *b);
			cout << endl << endl << "  ****  Player X�� �¸��Դϴ�  *****" << endl;
			return -1;
		}

	}
	if ((*a | *b) == 0b111111111)
	{
		print(*a, *b);
		cout << endl << endl << "  ****  ���º��Դϴ�  ****" << endl;
		return -1;
	}
	return 0;
}
//�˰���
int TTT::argo1(int* a, int* b)//���̵� �� 
{
	int w[8] = { w1,w2,w3,w4,w5,w6,w7,w8 };
	int x[8][3] = { {0b000100100,0b100000100,0b100100000},{0b000010010,0b010000010,0b010010000},{0b000001001,0b001000001,0b001001000}
	,{0b011000000,0b101000000,0b110000000},{0b000011000,0b000101000,0b000110000},{0b000000011,0b000000101,0b000000110},{0b000010001,0b100000001,0b100010000},{0b000010100,0b001000100,0b001010000} };
	int i, j;
	int output;
	srand((unsigned int)time(NULL));
	output = 0;
	//���� ä��� 
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 3; j++)
		{
			//	cout<<(w[i]-x[i][j])<<endl;
			if ((*b & w[i]) == x[i][j])
			{

				if (((w[i] - x[i][j]) & (*a)) != 0) { continue; }
				else { output = (w[i] - x[i][j]);		return output; }
			}
		}
	}
	for (i = 0; i < 8; i++) // ��벨 ���� 
	{
		for (j = 0; j < 3; j++)
		{
			if ((*a & w[i]) == x[i][j])
			{

				if (((w[i] - x[i][j]) & (*b)) != 0) continue;

				else { output = (w[i] - x[i][j]);		return output; }
			}
		}
	}
	while (1)
	{
		output = rand() % 9 + 1;
		if (((1 << (9 - output)) & (*a)) == 0)
		{
			if (((1 << (9 - output)) & (*b)) == 0)
			{
				output = (1 << (9 - output));
				return output;
			}
		}
	}
	//�Ѵ� �ƴ� ��� ���� ���� ä��� 

}
int TTT::argo2(int* a, int* b)//���̵� �� 
{
	int w[8] = { w1,w2,w3,w4,w5,w6,w7,w8 };
	int x[8][3] = { {0b000100100,0b100000100,0b100100000},{0b000010010,0b010000010,0b010010000},{0b000001001,0b001000001,0b001001000}
	,{0b011000000,0b101000000,0b110000000},{0b000011000,0b000101000,0b000110000},{0b000000011,0b000000101,0b000000110},{0b000010001,0b100000001,0b100010000},{0b000010100,0b001000100,0b001010000} };
	int i, j;
	int output;
	srand((unsigned int)time(NULL));
	output = 0;
	//���� ä��� 
	for (i = 0; i < 8; i++) // ��벨 ���� 
	{
		for (j = 0; j < 3; j++)
		{
			if ((*a & w[i]) == x[i][j])
			{

				if (((w[i] - x[i][j]) & (*b)) != 0) continue;

				else { output = (w[i] - x[i][j]);		return output; }
			}
		}
	}

	for (i = 0; i < 5; i++) //10���� ������ ��ȸ�� 
	{
		output = rand() % 9 + 1;
		if (((1 << (9 - output)) & (*a)) == 0)
		{
			if (((1 << (9 - output)) & (*b)) == 0)
			{
				output = (1 << (9 - output));
				//	cout<<"!!"<<output;
				return output;
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 3; j++)
		{
			//	cout<<(w[i]-x[i][j])<<endl;
			if ((*b & w[i]) == x[i][j])
			{

				if (((w[i] - x[i][j]) & (*a)) != 0) { continue; }
				else { output = (w[i] - x[i][j]);		return output; }
			}
		}
	}



	while (1)
	{
		output = rand() % 9 + 1;
		if (((1 << (9 - output)) & (*a)) == 0)
		{
			if (((1 << (9 - output)) & (*b)) == 0)
			{
				output = (1 << (9 - output));
				//	cout<<"!!"<<output;
				return output;
			}
		}
	}
	//�Ѵ� �ƴ� ��� ���� ���� ä��� 

}

int TTT::argo0(int* a) //���۾˰���1 
{
	switch (*a)
	{
	case 0b100000000:
	case 0b001000000:
	case 0b000000100:
	case 0b000000001:
		return 5;
	case 0b010000000:
		return 8;
	case 0b000100000:
		return 6;
	case 0b000001000:
		return 4;
	case 0b000000010:
		return 2;
	case 0b000010000:
		return 3;
	}
}





//���̵�����?

//�޴� ��� /1 p vs p /2 p v e �ʱ� / 3 pve ��� 
void TTT::menu(void)
{
	int a = 0;
	while (1)
	{
		a = 0;
		cout << endl << endl << "�޴��� �����Ͻʽÿ�" << endl << "1. Player VS Player" << endl << "2. Player VS Computer(���̵� ��)" << endl << "3. Player VS Computer(���̵� ��)" << endl << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "Player VS Player �� �����ϼ̽��ϴ�." << endl;
			m1();
			break;

		case 2:
			cout << "Player VS Computer(���̵� ��) �� �����ϼ̽��ϴ�." << endl;
			m2();
			break;

		case 3:
			cout << "Player VS Computer(���̵� ��) �� �����ϼ̽��ϴ�." << endl;
			m3();
			break;

		}
	}

}

void TTT::m1(void)
{
	int x = 0;
	int static a = 0b0;
	int static b = 0b0;
	a = 0b0;
	b = 0b0;
	while (1)
	{
		print(a, b);
		In(&a, &b);
		x = vic(&a, &b);
		if (x == -1) break;
	}
}

void TTT::m2(void)
{
	int x = 0;
	int static a = 0b0;
	int static b = 0b0;
	int inputb;
	a = 0b0;
	b = 0b0;

	while (1)
	{
		print(a, b);
		In2(&a, &b);
		x = vic(&a, &b);	if (x == -1) break;
		inputb = argo2(&a, &b);
		b = b | inputb;
		x = vic(&a, &b);	if (x == -1) break;
	}
}

void TTT::m3(void)
{
	int x = 0;
	int static a = 0b0;
	int static b = 0b0;
	int inputb;
	a = 0b0;
	b = 0b0;

	print(a, b);
	In2(&a, &b);
	inputb = argo0(&a);
	b = b | (1 << (9 - inputb));
	In3(&b, inputb);
	print(a, b);

	while (1)
	{
		In2(&a, &b);
		x = vic(&a, &b);
		if (x == -1) break;
		inputb = argo1(&a, &b);
		b = b | inputb;
		x = vic(&a, &b);
		if (x == -1) break;
		print(a, b);
	}
}



