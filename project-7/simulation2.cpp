#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Order.cpp"
#include "Queue.cpp"

using namespace std;

// Function for simulating cashiers
// It has array of cashiers, numCashiers, arrivalQueue and array of baristaQueue and numBarista as parameters
void simulateCashiers(Cashier* cashiers, int numCashiers, Queue& arrivalQueue, Queue* baristaQueue, int numBaristas)
{
    while (!arrivalQueue.isEmpty())
    {
        Order* order = arrivalQueue.dequeue();
        // Traverse the cashiers, if any are finished his/her order, 
        // set the cashier order to NULL and add the order to the baristaQueue
        for (int i = 0; i < numCashiers; i++)
        {
            if (cashiers[i].current != NULL && cashiers[i].freeAt <= order->getArrivalTime())
            {
                baristaQueue[i / 3].enqueueOrderFinishTime(*cashiers[i].current);
                cashiers[i].current = NULL;

                // Count the cashier queue
                if (cashierQueueCounter > maxCashierQueue)
                {
                    maxCashierQueue = cashierQueueCounter;
                    cashierQueueCounter = 0;
                }
            }
        }

        // If there is a cashier available, set the cashier's order to the current order
        // and set the cashier's freeAt to the current order's finish time
        bool cashierAvailable = false;
        for (int i = 0; i < numCashiers; i++)
        {
            if (cashiers[i].current == NULL)
            {
                order->setOrderTakenTime(order->getArrivalTime());
                order->setCashier(i);
                cashiers[i].current = order;
                cashiers[i].freeAt = order->getOrderFinishedTime();
                cashierAvailable = true;
                break;
            }
        }
        // If there is no cashier available, find the cashier with the smallest freeAt
        // and set the cashier's order to the current order
        if (!cashierAvailable)
        {
            int min = 0;
            for (int i = 0; i < numCashiers; i++)
            {
                // Find first cashier with smallest freeAt
                if (cashiers[i].freeAt < cashiers[min].freeAt)
                {
                    min = i;
                }
            }
            baristaQueue[min/3].enqueueOrderFinishTime(*cashiers[min].current);
            order->setOrderTakenTime(cashiers[min].freeAt);
            order->setCashier(min);
            cashiers[min].current = order;
            cashiers[min].freeAt = order->getOrderFinishedTime();
            cashierQueueCounter++;
        }
    }

    // Add remaining orders to baristaQueue
    for (int i = 0; i < numCashiers; i++)
    {
        if (cashiers[i].current != NULL)
        {
            baristaQueue[i/3].enqueueOrderFinishTime(*cashiers[i].current);
        }
    }
}

// Fonction for simulating baristas
// It has array of baristas, numBaristas, baristaQueue and finishedQueue as parameters
void simulateBaristas(int currentBarista, Queue& baristaQueue, Queue& finishedQueue)
{
    Queue priceQueue;           // For orders that waiting barista
    Barista barista;            // For baristas
    barista.freeAt = 0;         // Set barista freeAt to 0
    barista.current = NULL;     // Set barista current to NULL

    while (!baristaQueue.isEmpty())
    {
        Order* order = baristaQueue.dequeue();
        order->setBarista(currentBarista);
        // If barista is available set the barista's order to the current order
        // and set the barista's freeAt to the current order's finish time
        if (barista.freeAt == 0 && priceQueue.isEmpty())
        {
            order->setBrewStartTime(order->getOrderFinishedTime());
            barista.current = order;
            barista.freeAt = order->getBrewFinishedTime();
            finishedQueue.enqueueArrivalTime(*order);
        }
        else 
        {
            // Check the state change when a new order comes in
            if (barista.freeAt <= order->getOrderFinishedTime())
            {
                if (!priceQueue.isEmpty())
                {
                    while (!priceQueue.isEmpty())
                    {
                        Order* priceOrder = priceQueue.dequeue();
                        priceOrder->setBrewStartTime(barista.freeAt);
                        barista.current = priceOrder;
                        barista.freeAt = priceOrder->getBrewFinishedTime();
                        finishedQueue.enqueueArrivalTime(*priceOrder);
                        
                        if (!baristaQueue.isEmpty() && barista.freeAt > order->getOrderFinishedTime())
                        {
                            break;
                        }
                    }
                    if (!priceQueue.isEmpty())
                    {
                        priceQueue.enqueuePrice(*order);
                    }
                    else if (barista.freeAt <= order->getOrderFinishedTime())
                    {
                        order->setBrewStartTime(order->getOrderFinishedTime());
                        barista.current = order;
                        barista.freeAt = order->getBrewFinishedTime();
                        finishedQueue.enqueueArrivalTime(*order);
                    }
                    else
                    {
                        priceQueue.enqueuePrice(*order);
                    }
                }
                else
                {
                    order->setBrewStartTime(barista.freeAt);
                    barista.current = order;
                    barista.freeAt = order->getBrewFinishedTime();
                    finishedQueue.enqueueArrivalTime(*order);
                }
            }
            else
            {
                priceQueue.enqueuePrice(*order);
                
            }
        }
    }

    // Add remaining orders to finishedQueue
    while (!priceQueue.isEmpty())
    {
        Order* priceOrder = priceQueue.dequeue();
        priceOrder->setBrewStartTime(barista.freeAt);
        barista.current = priceOrder;
        barista.freeAt = priceOrder->getBrewFinishedTime();
        finishedQueue.enqueueArrivalTime(*priceOrder);
    }
}

// Main simuation2 function
void simulation2(ifstream &inputFile, ofstream &outputFile)
{
    cashierQueueCounter = 0;
    maxCashierQueue = 0;
    baristaQueueCounter = 0;
    maxBaristaQueue = 0;

    // Create queues
    Queue arrivalQueue;         // For orders that have arrived
    Queue finishedQueue;

    // Read fist line, then second line
    string line;
    getline(inputFile, line);

    // Create cashiers and baristas
    int numCashiers = stoi(line);
    int numBaristas = numCashiers / 3;
    Cashier cashiers[numCashiers];
    Barista baristas[numBaristas];
    Queue baristaQueue[numBaristas];                // For orders that have been taken by a cashier and are waiting to be taken by a barista
    Queue baristaFinishedQueue[numBaristas];        // For orders that have been finished

    
    // Set cashiers to free
    for (int i = 0; i < numCashiers; i++)
    {
        cashiers[i].current = NULL;
        cashiers[i].freeAt = 0;
    }
    for (int i = 0; i < numBaristas; i++)
    {
        baristas[i].current = NULL;
        baristas[i].freeAt = 0;
    }

    getline(inputFile, line);
    
    int numOrders = stoi(line);

    // Read entire file
    while (getline(inputFile, line))
    {
        // Create order
        Order* order = new Order();

        // Parse line
        stringstream ss(line);
        string token;
        int i = 0;
        while (getline(ss, token, ' '))
        {
            switch (i)
            {
                case 0:
                    order->setArrivalTime(stod(token));
                    break;
                case 1:
                    order->setOrderTime(stod(token));
                    break;
                case 2:
                    order->setBrewTime(stod(token));
                    break;
                case 3:
                    order->setPrice(stod(token));
                    break;
            }
            i++;
        }
        arrivalQueue.enqueueArrivalTime(*order);
    }

    // Simulate cashiers
    simulateCashiers(cashiers, numCashiers, arrivalQueue, baristaQueue, numBaristas);

    // Simulate baristas
    for (int i = 0; i < numBaristas; i++)
    {
        simulateBaristas(i, baristaQueue[i], baristaFinishedQueue[i]);
    }
    
    // Add all finished orders to finishedQueue according to arrival time
    for (int i = 0; i < numBaristas; i++)
    {
        while (!baristaFinishedQueue[i].isEmpty())
        {
            finishedQueue.enqueueArrivalTime(*baristaFinishedQueue[i].dequeue());
        }
    }
    printRunningTime(outputFile, finishedQueue);
    outputFile << maxCashierQueue << endl;
    for (int i = 0; i < numBaristas; i++)
    {
        outputFile << "-1" << endl;
    }
    printUtilizationCashiers(outputFile, finishedQueue, numCashiers, getRunningTime(finishedQueue));
    printUtilizationBaristas(outputFile, finishedQueue, numBaristas, getRunningTime(finishedQueue));
    printTurnaroundTimes(outputFile, finishedQueue);

}
