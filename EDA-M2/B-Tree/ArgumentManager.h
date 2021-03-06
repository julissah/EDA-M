#ifndef _argumentmanager_H_INCLUDED
#define _argumentmanager_H_INCLUDED

#include <map>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class ArgumentManager {
private:
    map<string, string> m_argumentMap;
public:
    ArgumentManager() { }
    ArgumentManager(int argc, char *argv[], char delimiter=';');
    ArgumentManager(string rawArguments, char delimiter=';');
    void parse(int argc, char *argv[], char delimiter=';');
    void parse(string rawArguments, char delimiter=';');
    string get(string argumentName);
    string toString();
    friend ostream& operator << (ostream &out, ArgumentManager &am);
};

void ArgumentManager::parse(string rawArguments, char delimiter) {
    stringstream currentArgumentName;
    stringstream currentArgumentValue;
    bool argumentNameFinished = false;
    
    for (unsigned int i=0; i<=rawArguments.length(); i++) {
        if (i == rawArguments.length() || rawArguments[i] == delimiter) {
            if (currentArgumentName.str() != "") {
                m_argumentMap[currentArgumentName.str()] = currentArgumentValue.str();
            }
            // reset
            currentArgumentName.str("");
            currentArgumentValue.str("");
            argumentNameFinished = false;
        }
        else if (rawArguments[i] == '=') {
            argumentNameFinished = true;
        }
        else {
            if (argumentNameFinished) {
                currentArgumentValue << rawArguments[i];
            }
            else {
                if (rawArguments[i] == ' ')
                    continue;
                currentArgumentName << rawArguments[i];
            }
        }
    }
}

void ArgumentManager::parse(int argc, char *argv[], char delimiter) {
    if (argc > 1) {
        for (int i=1; i<argc; i++) {
            parse(argv[i], delimiter);
        }
    }
}

ArgumentManager::ArgumentManager(int argc, char *argv[], char delimiter) {
    parse(argc, argv, delimiter);
}

ArgumentManager::ArgumentManager(string rawArguments, char delimiter) {
    parse(rawArguments, delimiter);
}

string ArgumentManager::get(string argumentName) {
    map<string, string>::iterator iter = m_argumentMap.find(argumentName);
    if (iter == m_argumentMap.end()) {
        return "";
    }
    else {
        return iter->second;
    }
}

string ArgumentManager::toString() {
    stringstream ss;
    for (map<string, string>::iterator iter = m_argumentMap.begin(); iter != m_argumentMap.end(); iter++) {
        ss << "Nombre Argumento " << iter->first << endl;
        ss << "Valor Argumento: " << iter->second << endl;
    }
    return ss.str();
}

ostream& operator << (ostream &out, ArgumentManager &am) {
    out << am.toString();
    return out;
}

#endif