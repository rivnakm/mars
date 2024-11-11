/*!
 * @file tokenizer.hpp
 */
#pragma once

#include <istream>

/*!
 * @namespace mars
 */
namespace mars
{
/*!
 * @class Tokenizer
 */
class Tokenizer
{
  public:
    /*!
     * @fn Tokenizer(std::istream stream)
     * @brief Constructor
     * @param stream Source code file stream
     */
    Tokenizer(std::istream &s);

  private:
    std::istream &_stream;

    /*!
     * @fn void expect(char c)
     * @brief Expect that the next character in the stream is the same as the provided
     * @param c Character to check against
     * @exception mars::UnexpectedCharacterException If the next input character does not match the provided
     */
    void expect(char c);
};
}; // namespace mars
