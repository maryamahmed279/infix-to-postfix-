#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


//the ADT to the queue(circular)
typedef struct
{
	int* arr;
	int front;
	int rear;
	int count;
}queue;

//construct the queue(circular)
queue* construct(int size)
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->arr = (int*)malloc(size * sizeof(int));
	q->rear = 0;
	q->count = 0;
	q->front = 0;

	return q;
}

//functions for the queue
// 
//insert insinde the  queue
void enqueue(queue* q, int size, int value)
{
	//as the counter is the indecator to the number of elemnts in the array 
	// //mmake it circular to make sure that it"s empty or fulll to be more specific
	//printf("doneeee");
	if (q->count < size)
	{
		q->arr[q->rear] = value;
		q->rear++;
		q->rear%= size;
		q->count++;
	}
}
//remove from the queue
int dequeue(queue* q,int size)
{
	int out_value;
	if (q->count != 0)
	{
		out_value = q->arr[q->front];
		q->front++;
		q->count--;
		q->front =q->front%size;
		return out_value;
	}
	else
	{
		printf("empty");
	}
}
//print the queue

void printqueue(queue q, int size)
{
	int i;
	if (q.rear > q.front)
	{
		for (i = q.front; i < q.rear; i++)
		{
			printf("hiiii");
			printf("%d", q.arr[i]);
		}
	}
	else if ((q.rear) < (q.front))
	{

		for (i = q.front; i < size; i++)
		{
			printf("%d", q.arr[i]);
		}
		for (i = 0; i < q.rear; i++)
		{
			printf("%d", q.arr[i]);
		}
	}
}
	//to check if the queue is empty or not
	bool isempty(queue q)
	{

		if (q.count == 0)
		{
			return true;	//empty queue
		}
		else
		{
			return false;  //not empty queue(there is elemnt stil inside)
		}
	}
	//to check if the queue is full or not 
	bool isfull(queue q ,int size)
	{
		if (q.count = size)
		{
			return true; //full queue
		}
		else
		{
			return false;  //the queue not full(there is a sapce in it)
		}
	}

//////start the programm in main//////////////
	int main()
	{
		while (1)
		{
			///will take the value number 1st as float to handl the float
			int num=0;
			printf("eneter the number of elemnts:\n");
			scanf("%d", &num);
			//the queues intilization that will be used (in the radix sort)
	        //1st to enter the elemnt (intial) (qi)
			//the queue will uesed to get max and sort (qm)
			if (num==0|| num<0)
			{
				printf("canont enterd ");
				return 9;
			}
			
			queue* q0 = construct(num);
			queue* q1 = construct(num);
			queue* q2 = construct(num);
			queue* q3 = construct(num);
			queue* q4 = construct(num);
			queue* q5 = construct(num);
			queue* q6 = construct(num);
			queue* q7 = construct(num);
			queue* q8 = construct(num);
			queue* q9 = construct(num);

			//make a check that it's not include letters 
			//will loop to check every number enterd

			int i;
			float x;//to make the check if it's float or integar
			int y;//to make the casting on the number
			int change;
			float* array2 = (float*)malloc(num * sizeof(float));
			float enterd;//the value that will be enterd as float to make the check
			//make the array that will take the elemnts after the check
			int* array = (int*)malloc(num * sizeof(int));
			for (i = 0; i < num; i++)
			{
				printf("enter your value");
				scanf("%f", &enterd);
				y = (int)enterd;
				x = enterd / y;
				if (x == 1)
				{
					//make the elemnts and add them to the array 
					//the check of thefloat done
					//printf("the value is not float\n");
					change = (int)enterd;
					//printf("%d\n", change);
					if (change < 0)
					{

						printf("do you what it -ve?\n");
						printf("1.yes\n");
						printf("2.no\n");
						int check;
						scanf_s("%d", &check);
						//means yes
						if (check == 1)
						{
							printf("you can't add -ve number sorry");
							return 0;
						}
						else if (check == 2)
						{
						    change  = -1 * change;
						}
					
					}
					//add number to the array after finish the check of the-ve
					array[i] = change;
					array2[i] = enterd;
					
				}

				//will eneter here if the number enterd is float 
				else
				{
					printf("erorr\n");
					printf("you can't you float number,sorry the progrram willl end	");
					return 0;

				}
			}//end of for loop of entring the values(and make all the checks)
			//make a queue add inside the elemnts of the array
			queue* qi = construct(num);
			
			for (int ii = 0; ii < num; ii++)
			{
				int x;
				x = array[ii];
				printf("%d", x);
				printf(" ");
				enqueue(qi,num ,x);
			}
			printf("\n");
			/*
			//the queue contain the numbers
			printf("your elemnts in the queue are:");
			printqueue(*qi,num);
			printf("\n");
			*/
		 //to get the max number
		 //the new queue that the values will be inside it
			queue* qm = construct(num);
			int max = dequeue(qi,num);
			enqueue(qm,num, max);
			while (!isempty(*qi))
			{
				int x;
				x = dequeue(qi,num);
				enqueue(qm,num, x);
				if (max < x)
				{
					max = x;
				}
			}
			printf("the max num is =%d \n", max);
			//to get the number of the loops will done to make the radix sort
			int count = 0;
			while (max != 0)
			{
				count++;
				max = max / 10;

			}
			printf("the numbe of loops needed =%d\n", count);
			

			//to get the digit in each loop
			int r = 1;
			int out;
			int d;
 
			//the loop will move intill the the counter(the number f max digit)end
			while (count)
			{
				//to check by every to them one by one
				while (!isempty(*qm))
				{
					//d to detrimne the digit value
					//out the number that will be out from the queue
					out = dequeue(qm,num);
					d = out / r % 10;
					//sort the values in the queue according to their digigts
					if (d == 0)
					{
						enqueue(q0, num,out);
					}
					else if (d == 1)
					{
						enqueue(q1,num, out);
					}
					else if (d == 2)
					{
						enqueue(q2,num, out);
					}
					else if (d == 3)
					{
						enqueue(q3,num, out);
					}
					else if (d == 4)
					{
						enqueue(q4,num, out);
					}
					else if (d == 5)
					{
						enqueue(q5,num,out);
					}
					else if (d == 6)
					{
						enqueue(q6,num, out);
					}
					else if (d == 7)
					{
						enqueue(q7,num, out);
					}
					else if (d == 8)
					{
						enqueue(q8, num,out);
					}
					else if (d == 9)
					{
						enqueue(q9, num,out);
					}

				}
				////after move each number to queue
				   ////remove them from queue and enter them to the main queue
				while (!isempty(*q0))
				{
					int x = dequeue(q0,num);
					enqueue(qm,num, x);

				}
				while (!isempty(*q1))
				{
					int  x = dequeue(q1,num);
					enqueue(qm,num, x);

				}
				while (!isempty(*q2))
				{
					int x = dequeue(q2,num);
					enqueue(qm,num, x);
				}
				while (!isempty(*q3))
				{
					int x = dequeue(q3,num);
					enqueue(qm,num, x);
				}
				while (!isempty(*q4))
				{
					int x = dequeue(q4,num);
					enqueue(qm,num, x);
				}
				while (!isempty(*q5))
				{
					int x = dequeue(q5,num);
					enqueue(qm,num, x);

				}
				while (!isempty(*q6))
				{
					int x = dequeue(q6,num);
					enqueue(qm,num, x);
				}
				while (!isempty(*q7))
				{
					int x = dequeue(q7,num);
					enqueue(qm, num,x);

				}
				while (!isempty(*q8))
				{
					int x = dequeue(q8,num);
					enqueue(qm, num,x);

				}
				while (!isempty(*q9))
				{
					int x = dequeue(q9,num);
					enqueue(qm,num, x);
				}
				count--;
				//to get the another digit
				r = r * 10;
			}
			//print the sorted array
			printf("the sorted queue is done |^-^|");
			while (!isempty(*qm))
			{
				printf("\n");
				int out_sorted;
				out_sorted = dequeue(qm,num);
				printf("%d", out_sorted);
			}
			printf("\n");
		}//the end of the whilr loop that repeat the application (infint )
	}