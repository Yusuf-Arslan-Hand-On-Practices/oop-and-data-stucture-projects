#include <iostream>

using namespace std;

#ifndef ORDER_H
#define ORDER_H

namespace ordr
{
    class Order
    {
        private:
            double arrivalTime;         // The time when costumer enters the coffee shop
            double orderTime;           // The time required to give coffee order
            double brewTime;            // The time required to make coffee
            double price;               // The price of the coffee
            double orderTakenTime;      // The time when the order is taken
            double brewStartTime;       // The time when the coffee is started to brew
            int cashier;                // The cashier number that took the order
            int barista;                // The barista number that made the coffee
        public:
            Order();
            Order(double arrivalTime, double orderTime, double brewTimem, double price);
            double getArrivalTime();
            double getOrderTime();
            double getBrewTime();
            double getPrice();
            double getOrderTakenTime();
            double getOrderFinishedTime() const;
            double getBrewStartTime();
            double getBrewFinishedTime() const;
            double getCashier();
            double getBarista();
            double getTurnaroundTime() const;

            void setArrivalTime(double arrivalTime);
            void setOrderTime(double orderTime);
            void setBrewTime(double brewTime);
            void setPrice(double price);
            void setOrderTakenTime(double orderTakenTime);
            void setBrewStartTime(double brewStartTime);
            void setCashier(int cashier);
            void setBarista(int barista);
            
            void print() const;
            // overload > operator
            bool operator>(Order &order);
    };

    Order::Order()
    {
        arrivalTime = 0;
        orderTime = 0;
        brewTime = 0;
        price = 0;
        orderTakenTime = 0;
        brewStartTime = 0;
        cashier = 0;
        barista = 0;
    }

    Order::Order(double arrivalTime, double orderTime, double brewTime, double price)
    {
        this->arrivalTime = arrivalTime;
        this->orderTime = orderTime;
        this->brewTime = brewTime;
        this->price = price;
        this->orderTakenTime = 0;
        this->brewStartTime = 0;
        this->cashier = 0;
        this->barista = 0;
    }

    double Order::getArrivalTime()
    {
        return arrivalTime;
    }

    double Order::getOrderTime()
    {
        return orderTime;
    }

    double Order::getBrewTime()
    {
        return brewTime;
    }

    double Order::getPrice()
    {
        return price;
    }

    double Order::getOrderTakenTime()
    {
        return orderTakenTime;
    }

    double Order::getOrderFinishedTime() const
    {
        return orderTakenTime + orderTime;
    }

    double Order::getBrewStartTime()
    {
        return brewStartTime;
    }
    
    double Order::getBrewFinishedTime() const
    {
        return brewStartTime + brewTime;
    }

    double Order::getCashier()
    {
        return cashier;
    }

    double Order::getBarista()
    {
        return barista;
    }

    double Order::getTurnaroundTime() const
    {
        return getBrewFinishedTime() - arrivalTime;
    }


    void Order::setArrivalTime(double arrivalTime)
    {
        this->arrivalTime = arrivalTime;
    }

    void Order::setOrderTime(double orderTime)
    {
        this->orderTime = orderTime;
    }

    void Order::setBrewTime(double brewTime)
    {
        this->brewTime = brewTime;
    }

    void Order::setPrice(double price)
    {
        this->price = price;
    }

    void Order::setOrderTakenTime(double orderTakenTime)
    {
        this->orderTakenTime = orderTakenTime;
    }

    void Order::setBrewStartTime(double brewStartTime)
    {
        this->brewStartTime = brewStartTime;
    }

    void Order::setCashier(int cashier)
    {
        this->cashier = cashier;
    }

    void Order::setBarista(int barista)
    {
        this->barista = barista;
    }


    void Order::print() const
    {
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Order Time: " << orderTime << endl;
        cout << "Brew Time: " << brewTime << endl;
        cout << "Price: " << price << endl;
        cout << "Order Taken Time: " << orderTakenTime << endl;
        cout << "Order Finished Time: " << getOrderFinishedTime() << endl;
        cout << "Brew Start Time: " << brewStartTime << endl;
        cout << "Brew Finished Time: " << getBrewFinishedTime() << endl;
        cout << "Cashier: " << cashier << endl;
        cout << "Barista: " << barista << endl;
        cout << "Turn Around Time: " << getTurnaroundTime() << endl;
    }

    bool Order::operator>(Order &order)
    {
        // Overload > operator, compares the price of two orders 
        // for the barista to decide which order to make first
        return this->price > order.price;
    }
    
} // namespace ORD

#endif
