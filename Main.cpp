// Multi-threading By: Matthew Sender

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

//global varaibles
const int numThreads = 10;
mutex MLock;
int localTID = 0;

// step 1 create a function that we want executed 
void countDown(int tid)
{
	// missle count down
	int i = 3;
	MLock.lock();
	localTID = tid;
	cout << "Missle ID = " << localTID << " " << endl;
	// while loop for count down
	while( i > 0, i--)
	{
		cout << "Missle Launch in ... " << i << "seconds" << endl;
	}

	MLock.unlock();
}

int main()
{
	//step 2 create threads
	thread exampleThreads[numThreads];
	for (int i = 0; i < numThreads; i++)
	{
		// step 3 associate the thread to the function and any input it needs
		exampleThreads[i] = thread(countDown, i);
	}
	cout << "Theads created and associated with a function" << endl;

	for (int i = 0; i < numThreads; i++)
	{
		if (exampleThreads[i].joinable())
		{
			//step 4 join it
			exampleThreads[i].join();
		}
		else
		{
			cout << "error joining thread " << i << endl;
		}
	}
	cout << "All Missles Launched" << endl;
}