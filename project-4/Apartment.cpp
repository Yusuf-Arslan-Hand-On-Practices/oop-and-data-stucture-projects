// Implementation of an Apartment class

#include "Apartment.h"

namespace aprt
{
    Apartment::Apartment(string name, int max_bandwidth)
    {
        this->name = name;
        this->max_bandwidth = max_bandwidth;
    }

    Apartment::~Apartment() = default;

    string Apartment::getName()
    {
        return this->name;
    }

    int Apartment::getMaxBandwidth()
    {
        return this->max_bandwidth;
    }

    void Apartment::setName(string name)
    {
        this->name = name;
    }

    void Apartment::setMaxBandwidth(int max_bandwidth)
    {
        this->max_bandwidth = max_bandwidth;
    }

    void Apartment::addFlat(flt::Flat& flat, int pos)
    {
        if (flat.getIsEmpty() == 1)
        {
            flat.setInitialBandwidth(0);
            this->flats.insertAtPosition(pos, &flat);
            return;
        }

        int total_bandwidth = this->getTotalBandwidth();
        if (total_bandwidth + flat.getInitialBandwidth() < this->max_bandwidth)
        {
            this->flats.insertAtPosition(pos, &flat);
        }
        else
        {
            flat.setInitialBandwidth(this->max_bandwidth - total_bandwidth);
            this->flats.insertAtPosition(pos, &flat);
        }
    }
    
    // HELPER - get total bandwidth of all flats 
    int Apartment::getTotalBandwidth()
    {
        int total_bandwidth = 0;
        for (int i = 0; i < this->flats.getSize(); i++)
        {
            total_bandwidth += this->flats.getData(i)->getInitialBandwidth();
        }
        return total_bandwidth;
    }

    void Apartment::makeFlatEmpty(int pos)
    {
        flt::Flat* flat = this->flats.getData(pos);
        flat->setIsEmpty(1);
        flat->setInitialBandwidth(0);
    }

    string Apartment::toString()
    {
        string result = this->name + "(" + std::to_string(this->max_bandwidth) + ")\t";
        for (int i = 0; i < this->flats.getSize(); i++)
        {
            flt::Flat* flat = this->flats.getData(i);
            result += flat->toString() + "\t";
        }
        return result;
    }

    bool Apartment::operator==(const Apartment& other) const
    {
        return this->name == other.name;
    }

    bool Apartment::operator!=(const Apartment& other) const
    {
        return this->name != other.name;
    }

} // namespace aprt
