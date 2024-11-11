/*!
 * @file exceptions.hpp
 */
#pragma once

/*!
 * @namespace mars
 */
#include <exception>
#include <format>
namespace mars
{
/*!
 * @class UnexpectedCharacterException
 */
class UnexpectedCharacterException : public std::exception
{
  public:
    explicit UnexpectedCharacterException(char c) : _c(c), _message(std::format("Unexpected character: {}", c))
    {
    }

    const char *what() const noexcept override
    {
        return _message.c_str();
    }

  private:
    char _c;
    std::string _message;
};
}; // namespace mars
