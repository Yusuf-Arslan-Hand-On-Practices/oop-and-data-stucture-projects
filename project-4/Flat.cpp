// Implementation of an Flat.h

#include "Flat.h"

namespace flt
{
    Flat::Flat(int id, int initial_bandwidth, int is_empty)
    {
        this->id = id;
        this->initial_bandwidth = initial_bandwidth;
        this->is_empty = is_empty;
    }

    Flat::~Flat() = default;

    int Flat::getId()
    {
        return this->id;
    }

    int Flat::getInitialBandwidth()
    {
        return this->initial_bandwidth;
    }

    int Flat::getIsEmpty()
    {
        return this->is_empty;
    }

    void Flat::setInitialBandwidth(int initial_bandwidth)
    {
        this->initial_bandwidth = initial_bandwidth;
    }

    void Flat::setIsEmpty(int is_empty)
    {
        this->is_empty = is_empty;
        this->initial_bandwidth = 0;
    }
    
    std::string Flat::toString() const
    {
        return "Flat" + std::to_string(this->id) + "(" + std::to_string(this->initial_bandwidth) + ")";
    }

    bool Flat::operator==(const Flat& other) const
    {
        return this->id == other.id;
    }

    bool Flat::operator!=(const Flat& other) const
    {
        return this->id != other.id;
    }
} // namespace flt