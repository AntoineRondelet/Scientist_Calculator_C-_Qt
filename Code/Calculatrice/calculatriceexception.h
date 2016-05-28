#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

#include <exception>
#include <string>
#include <sstream>

#define CALCULATRICE_EXCEPTION(m) throw CalculatriceException(__FILE__, __LINE__, m);

///Cette classe formate une exception en indiquant le fichier, la ligne de lancement et le message d'exception
class CalculatriceException : public std::exception
{
    std::string file, msg;
    int lineno;
public:
    CalculatriceException(const char* filename, int line, const std::string& message) noexcept : file(filename), msg(message), lineno(line) {}
    ~CalculatriceException() noexcept {}

    const char* what() const noexcept
    {
        std::stringstream ss;
        ss << "[Exception fichier " << file << " ligne n°" << lineno << "] : " << msg << "\n";
        return ss.str().c_str();
    }
};

#endif // CALCULATRICEEXCEPTION_H
