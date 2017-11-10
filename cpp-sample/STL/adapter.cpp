#include "stdafx.h"

using namespace std;

void stacks()
{
	// 默认使用deque的栈
	stack<int> stack1;
	// 使用vector作为底层的栈
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
	// 默认队列基于deque
	queue<int> queue1;

	// 还可以使用list或vector
	queue<int, list<int>> queue2;

	queue<int> c;
	c.push(1);
	c.push(2);
	c.push(3);

	c.pop();

	// 优先级队列，优先级大的会放到队列头，队列优先级使用比较操作符比较
	// 所以这里实际上会按照元素大小进行排序
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
