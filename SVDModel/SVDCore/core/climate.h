#ifndef CLIMATE_H
#define CLIMATE_H

#include <vector>
#include <unordered_map>
#include <unordered_set>


class Climate
{
public:
    Climate();
    void setup();

    // access
    const std::vector<float> &series(const int year, const int climateId) const { return mData.at(year).at(climateId); }
    bool hasSeries(const int year, const int climateId) const { auto y=mData.find(year); if(y==mData.end()) return false;
                                                                auto s= y->second.find(climateId); if (s==(*y).second.end()) return false;
                                                              return true;}
private:
    size_t mNColumns; ///< the number of data elements per year+id
    /// the main container for climate data
    /// the structure is: "year" -> "climateId" + data
    std::unordered_map< int, std::unordered_map<int, std::vector<float> > > mData;
    std::unordered_set<int> mAllYears;
    std::unordered_set<int> mAllIds;
    /// indices of years to use
    std::vector<int> mSequence;
};

#endif // CLIMATE_H