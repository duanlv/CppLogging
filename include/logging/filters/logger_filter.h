/*!
    \file logger_filter.h
    \brief Logging logger filter definition
    \author Ivan Shynkarenka
    \date 27.07.2016
    \copyright MIT License
*/

#ifndef CPPLOGGING_FILTERS_LOGGER_FILTER_H
#define CPPLOGGING_FILTERS_LOGGER_FILTER_H

#include "logging/filter.h"

#include <regex>

namespace CppLogging {

//! Logging logger filter
/*!
    Logging logger filters out logging records which logger filed is not matched
    to the given regular expression pattern.

    Thread-safe.
*/
class LoggerFilter : public Filter
{
public:
    //! Initialize logger filter with a given regular expression pattern
    /*!
         \param pattern - Regular expression pattern
    */
    LoggerFilter(const std::regex& pattern) : _pattern(pattern) {}
    LoggerFilter(const LoggerFilter&) = delete;
    LoggerFilter(LoggerFilter&&) = default;
    ~LoggerFilter() = default;

    LoggerFilter& operator=(const LoggerFilter&) = delete;
    LoggerFilter& operator=(LoggerFilter&&) = default;

    // Implementation of Filter
    bool FilterRecord(Record& record) override;

private:
    std::regex _pattern;
};

} // namespace CppLogging

#endif // CPPLOGGING_FILTERS_LOGGER_FILTER_H
