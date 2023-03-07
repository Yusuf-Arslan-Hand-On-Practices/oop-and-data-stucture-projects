#include <iostream>
#include <fstream>
#include <iomanip>

#include "Order.cpp"
#include "Queue.cpp"

using namespace std;

using namespace std;
using namespace que;
using namespace ordr;

double getRunningTime(Queue finishedQueue)
{
    // Find max brewFinishedTime
    double max = 0;
    while (!finishedQueue.isEmpty())
    {
        Order* order = finishedQueue.dequeue();
        if (order->getBrewFinishedTime() > max)
        {
            max = order->getBrewFinishedTime();
        }
    }
    return max;
}

void printRunningTime(ostream &outputFile, Queue finishedQueue)
{
    // Find max brewFinishedTime
    double max = getRunningTime(finishedQueue);
    outputFile << max << endl;
}


void printUtilizationCashiers(ostream &outputFile, Queue finishedQueue, int numCashiers, double totalRunningTime)
{
    double utilization[numCashiers];
    // Fill with 0s
    for (int i = 0; i < numCashiers; i++)
    {
        utilization[i] = 0;
    }

    // Traverse the queue and find the utilization for each cashier
    while (!finishedQueue.isEmpty())
    {
        Order* order = finishedQueue.dequeue();
        int cashier = order->getCashier();
        utilization[cashier] += order->getOrderTime();
    }
    
    // Print utilization - in format of 2 decimal places
    for (int i = 0; i < numCashiers; i++)
    {
        outputFile << utilization[i] / totalRunningTime << endl;
    }
}

void printUtilizationBaristas(ostream &outputFile, Queue finishedQueue, int numBaristas, double totalRunningTime)
{
    double utilization[numBaristas];
    // Fill with 0s
    for (int i = 0; i < numBaristas; i++)
    {
        utilization[i] = 0;
    }

    // Traverse the queue and find the utilization for each barista
    while (!finishedQueue.isEmpty())
    {
        Order* order = finishedQueue.dequeue();
        int barista = order->getBarista();
        utilization[barista] += order->getBrewTime();
    }
    
    // Print utilization
    for (int i = 0; i < numBaristas; i++)
    {
        outputFile << utilization[i] / totalRunningTime << endl;
    }
}

void printTurnaroundTimes(ostream &outputFile, Queue finishedQueue)
{
    while (!finishedQueue.isEmpty())
    {
        Order* order = finishedQueue.dequeue();
        outputFile << order->getBrewFinishedTime() - order->getArrivalTime() << endl;
    }
}

