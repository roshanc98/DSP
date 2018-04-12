//This program inputs N-letter word which are used to generate anagrams (regardless whether they are an actual word in some language).

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class stack
{
	public:
	int top=-1;
	char stack[50];
	void push(char letter)
	{
		stack[++top]=letter;
	}
	char pop()
	{
		return stack[top--];
	}
	char top_value()
	{
		return stack[top];
	}
};

class queue
{
	public:
	int front=-1;
	int rear=-1;
	char queue[100];
	void enqueue(char letter)
	{
		if (front==-1)
		{
			queue[++front]=letter;
			rear++;
		}
		else
		{
			queue[++rear]=letter;
		}
	}
	char dequeue()
	{
		return queue[front++];
	}
	char front_value()
	{
		return queue[front];
	}
	char rear_value()
	{
		return queue[rear];
	}
};

string sort(string word)
{
	char temp;
	int len=word.size();
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(word[i]>word[j])
			{
				temp=word[i];
				word[i]=word[j];	
				word[j]=temp;
			}
		}
	}
	return word;
}

int fact(int len)
{
	int value=1;
	while(len>1)
	{
		value=value*(len--);
		return value;
	}
}
int main()
{
	cout<<"Enter the word for which anagrams have to be printed\n";
	string word;
	cin>>word;
	int len=word.size();
	stack s;
	queue q;
	char pivot;
	word=sort(word);//sort the letters to first possible combination
	cout<<"The anagrams for "<<word<<" are\n";
	cout<<word<<endl;
	for(int i=1;i<fact(len);i++)//main loop for len! possible permutations
	{                          	    
		for (int i=0;i<len;i++)	
		{         
			s.push(word[i]);//putting the letters in stack
			q.enqueue(s.pop());//initial popping and enqueuing till pivot
			while(s.top_value()>q.rear_value())
			{
				q.enqueue(s.pop());
				pivot=s.pop(); //setting pivot value
				while(q.front_value()<pivot)
				{
					q.enqueue(q.dequeue());//enqueuing and dequeuing till char bigger than pivot is found
					s.push(q.dequeue());//pushing found value onto stack
					q.enqueue(pivot);//enqueuing the pivot
					while(q.front_value()>pivot)
					{
						q.enqueue(q.dequeue());//enqueuing and dequeuing and then pushing everything on the stack
						while(q.front!=q.rear+1)//emptying the queue onto the stack
						{
							s.push(q.dequeue());
							while(s.top!=-1) 
							{                 
								for(int i=0;i<len;i++)
								{
									word[i]=s.pop();//popping from stack to form word, but in reverse
									reverse(word.begin(),word.end());//reversing word to form correct word
									cout<<word<<endl;
									q.front=q.rear=-1;//making sure queue is empty
									s.top=-1;
								}
							}
						}
					}
				}
			}
		}
	}
}

