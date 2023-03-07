#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Order.cpp"
#include "Queue.cpp"

using namespace std;

// Fonction for simulating cashiers
// It has array of cashiers, numCashiers, arrivalQueue and baristaQueue as parameters
void simulateCashiers(Cashier* cashiers, int numCashiers, Queue& arrivalQueue, Queue& baristaQueue)
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
                baristaQueue.enqueueOrderFinishTime(*cashiers[i].current);
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
            baristaQueue.enqueueOrderFinishTime(*cashiers[min].current);
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
            baristaQueue.enqueueOrderFinishTime(*cashiers[i].current);
        }
    }
}

// Fonction for simulating baristas
// It has array of baristas, numBaristas, baristaQueue and finishedQueue as parameters
void simulateBaristas(Barista* baristas, int numBaristas, Queue& baristaQueue, Queue& finishedQueue)
{
    Queue priceQueue;           // For orders that waiting barista

    while (!baristaQueue.isEmpty())
    {
        Order* order = baristaQueue.dequeue();
        // Traverse the baristas, if any are available, set the barista's order to the current order
        int baristaAvailable = -1;
        for (int i = 0; i < numBaristas; i++)
        {
            if (baristas[i].current == NULL)
            {
                baristaAvailable = i;
                break;
            }
        }
        // If barista is available set the barista's order to the current order
        // and set the barista's freeAt to the current order's finish time
        if (baristaAvailable != -1 && priceQueue.isEmpty())
        {
            order->setBrewStartTime(order->getOrderFinishedTime());
            order->setBarista(baristaAvailable);
            baristas[baristaAvailable].current = order;
            baristas[baristaAvailable].freeAt = order->getBrewFinishedTime();
            finishedQueue.enqueueArrivalTime(*order);
        }
        else 
        {
            // find min freeAt  
            int min = 0;
            for (int i = 0; i < numBaristas; i++)
            {
                // Find first barista with smallest freeAt
                if (baristas[i].freeAt < baristas[min].freeAt)
                {
                    min = i;
                }
            }

            // Check the state change when a new order comes in
            if (baristas[min].freeAt <= order->getOrderFinishedTime())
            {
                if (!priceQueue.isEmpty())
                {
                    while (!priceQueue.isEmpty())
                    {
                        Order* priceOrder = priceQueue.dequeue();
                        priceOrder->setBrewStartTime(baristas[min].freeAt);
                        priceOrder->setBarista(min);
                        baristas[min].current = priceOrder;
                        baristas[min].freeAt = priceOrder->getBrewFinishedTime();
                        finishedQueue.enqueueArrivalTime(*priceOrder);
                        
                        // find min freeAt
                        min = 0;
                        for (int i = 0; i < numBaristas; i++)
                        {
                            // Find first barista with smallest freeAt
                            if (baristas[i].freeAt < baristas[min].freeAt)
                            {
                                min = i;
                            }
                        }
                        if (!baristaQueue.isEmpty() && baristas[min].freeAt > order->getOrderFinishedTime())
                        {
                            break;
                        }
                    }
                    if (!priceQueue.isEmpty())
                    {
                        priceQueue.enqueuePrice(*order);
                    }
                    else if (baristas[min].freeAt <= order->getOrderFinishedTime())
                    {
                        order->setBrewStartTime(order->getOrderFinishedTime());
                        order->setBarista(min);
                        baristas[min].current = order;
                        baristas[min].freeAt = order->getBrewFinishedTime();
                        finishedQueue.enqueueArrivalTime(*order);
                    }
                    else 
                    {
                        priceQueue.enqueuePrice(*order);
                    }
                }
                else
                {
                    order->setBrewStartTime(baristas[min].freeAt);
                    order->setBarista(min);
                    baristas[min].current = order;
                    baristas[min].freeAt = order->getBrewFinishedTime();
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
        // find min freeAt
        int min = 0;
        for (int i = 0; i < numBaristas; i++)
        {
            // Find first barista with smallest freeAt
            if (baristas[i].freeAt < baristas[min].freeAt)
            {
                min = i;
            }
        }
        Order* priceOrder = priceQueue.dequeue();
        priceOrder->setBrewStartTime(baristas[min].freeAt);
        priceOrder->setBarista(min);
        baristas[min].current = priceOrder;
        baristas[min].freeAt = priceOrder->getBrewFinishedTime();
        finishedQueue.enqueueArrivalTime(*priceOrder);
    }
}

// Main simuation1 function
void simulation1(ifstream &inputFile, ofstream &outputFile)
{
    cashierQueueCounter = 0;
    maxCashierQueue = 0;
    baristaQueueCounter = 0;
    maxBaristaQueue = 0;

    // Create queues
    Queue arrivalQueue;         // For orders that have arrived
    Queue baristaQueue;         // For orders that have been taken by a cashier and are waiting to be taken by a barista
    Queue finishedQueue;        // For orders that have been finished

    // Read fist line, then second line
    string line;
    getline(inputFile, line);

    // Create cashiers and baristas
    int numCashiers = stoi(line);
    int numBaristas = numCashiers / 3;

    Cashier cashiers[numCashiers];
    Barista baristas[numBaristas];
    
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
    simulateCashiers(cashiers, numCashiers, arrivalQueue, baristaQueue);

    // Simulate baristas
    simulateBaristas(baristas, numBaristas, baristaQueue, finishedQueue);

    
    printRunningTime(outputFile, finishedQueue);
    outputFile << maxCashierQueue << endl;
    outputFile << -1 << endl;
    printUtilizationCashiers(outputFile, finishedQueue, numCashiers, getRunningTime(finishedQueue));
    printUtilizationBaristas(outputFile, finishedQueue, numBaristas, getRunningTime(finishedQueue));
    printTurnaroundTimes(outputFile, finishedQueue);

    inputFile.close();
}
