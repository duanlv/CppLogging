/*!
    \file message_filter.cpp
    \brief Logging message filter implementation
    \author Ivan Shynkarenka
    \date 27.07.2016
    \copyright MIT License
*/

#include "logging/filters/message_filter.h"

namespace CppLogging {

bool MessageFilter::FilterRecord(Record& record)
{
    return std::regex_match(record.message.first, record.message.first + record.message.second, _pattern);
}

} // namespace CppLogging
