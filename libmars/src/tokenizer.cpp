#include "mars/tokenizer.hpp"
#include "mars/exceptions.hpp"

namespace mars
{
Tokenizer::Tokenizer(std::istream &s) : _stream(s)
{
}

void Tokenizer::expect(char c)
{
    if (_stream.peek() != c)
    {
        throw new UnexpectedCharacterException(_stream.peek());
    }
}
}; // namespace mars
