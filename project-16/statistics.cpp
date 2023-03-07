#include <iostream>
#include <fstream>
#include <iomanip>

#include "Order.h"
#include "Queue.h"

using namespace std;
using namespace que;
using namespace ordr;

/**
 * It takes a double, multiplies it by 100, adds .5, casts it to an int, then divides it by 100
 */
double formattedDouble(double number)
{
    double formattedNumber = (int)(number * 100 + .5);
    return (double)formattedNumber / 100;
}

/**
 * Find the maximum brewFinishedTime of all the orders in the finishedQueue
 */
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

/**
 * This function prints the maximum running time of the coffee machine to the output file
 */
void printRunningTime(ostream &outputFile, Queue finishedQueue)
{
    // Find max brewFinishedTime
    double max = getRunningTime(finishedQueue);
    outputFile << formattedDouble(max) << endl;
}


/**
 * This function takes in a queue of finished orders, the number of cashiers, and the total running
 * time of the simulation. It then calculates the utilization of each cashier and prints it to the
 * output file
 */
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
        outputFile << formattedDouble(utilization[i] / totalRunningTime) << endl;
    }
}

/**
 * It takes a queue of finished orders and the number of baristas, and prints the utilization of each
 * barista
 */
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
        outputFile << formattedDouble(utilization[i] / totalRunningTime) << endl;
    }
}

/**
 * It prints the turnaround times of all the orders in the finished queue to the output file
 */
void printTurnaroundTimes(ostream &outputFile, Queue finishedQueue)
{
    while (!finishedQueue.isEmpty())
    {
        Order* order = finishedQueue.dequeue();
        outputFile << formattedDouble(order->getBrewFinishedTime() - order->getArrivalTime()) << endl;
    }
}

