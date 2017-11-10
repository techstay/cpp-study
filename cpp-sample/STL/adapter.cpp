#include "stdafx.h"

using namespace std;

void stacks()
{
	// Ĭ��ʹ��deque��ջ
	stack<int> stack1;
	// ʹ��vector��Ϊ�ײ��ջ
	stack<int, vector<int>> stack2;

	stack<int> c;
	c.push(1);
	c.push(2);
	c.push(3);
	int i = c.top();
	cout << i << endl;
	c.pop();
	cout << c.top() << endl;
}

void queues()
{
	// Ĭ�϶��л���deque
	queue<int> queue1;

	// ������ʹ��list��vector
	queue<int, list<int>> queue2;

	queue<int> c;
	c.push(1);
	c.push(2);
	c.push(3);

	c.pop();

	// ���ȼ����У����ȼ���Ļ�ŵ�����ͷ���������ȼ�ʹ�ñȽϲ������Ƚ�
	// ��������ʵ���ϻᰴ��Ԫ�ش�С��������
	priority_queue<int> q;
	q.push(5);
	q.push(6);
	q.push(9);
	while(!q.empty())
	{
		cout << q.top() << ", ";
		q.pop();
	}
	cout << endl;
}
