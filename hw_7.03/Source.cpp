#include<iostream>
#include<fstream>

#include<stack>
#include<queue>
#include<string>

int main() {
	std::ifstream names("test.txt");
	std::stack<std::string> names_stack;
	std::queue<std::string> names_queue;
	std::string name;

	while (std::getline(names, name))
	{
		names_stack.push(name);
		names_queue.push(name);
	}

	int len = names_queue.size();
	if (len != 2) {
		std::queue<std::string> new_queue;

		for (size_t i = 0; i < len / 2 + 1; i++)
		{
			new_queue.push(names_stack.top());
			names_stack.pop();
		}
		for (size_t i = 0; i < len / 2 + 1; i++)
		{
			names_stack.push(new_queue.front());
			new_queue.pop();
		}
	}

	for (size_t i = 0; i < len; i++)
	{
		std::cout << names_stack.top() << "\t" << names_queue.front() << "\n";
		names_queue.pop();
		names_stack.pop();
	}

	names.close();

	return 0;
}
