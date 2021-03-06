#pragma once
#include <vector>
#include <cstdint>
#include <sstream>
#include <boost/archive/binary_iarchive.hpp>
namespace smoipc {

constexpr struct ObjectDeserialize {
    template<class Type, class Func>
    void operator()(
        const std::string& buffer, Func func
     ) const {
        std::istringstream is;
        is.str(buffer);
        boost::archive::binary_iarchive bi(is);
        Type object;
        bi >> object;
        func(object);
    }
    template<class Type>
    void operator()(
        Type& object,
        const std::string& buffer 
     ) const {
        std::istringstream is;
        is.str(buffer);
        boost::archive::binary_iarchive bi(is);
        bi >> object;
    }
    template<class Type>
    void operator()(
        Type& object,
        boost::archive::binary_iarchive& bi
     ) const {
        bi >> object;
    }
} object_deserialize;

}