#include <iostream>
#include <string>
class Stack{
private:
    int top = -1;
    int max = 10;
    char stack[10];
public:

    void push(char x)
    {
        if (top == max - 1)
            return;

        stack[++top] = x;
    }

    void pop()
    {
        top--;
    }

    int tops()
    {
        return stack[top];
    }

    bool is_empty()
    {
        if (top == -1)
            return true;
        else 
            return false;
    }
    
    void print_stack()
	{
	  for(int i = 0; i <= top; ++i) std::cout << stack[i] << " ";
	}

  };
  
  void reverse_word(std::string& stack, int length)
  {
  	Stack reverse_stack;
  	//add letters to stack then overwrite the given string from the stack
  	for (int i = 0; i < length*2 ; ++i)
	{
		if (i < length)
			reverse_stack.push(stack[i]);
		else 
		{
			stack[i - length] = reverse_stack.tops();
			reverse_stack.pop();
		}
		
	}

  }

int main()
{
    Stack my_stack;
   	std::string word = "Hello";
   reverse_word(word, word.length());
   std::cout << word;
}


	
