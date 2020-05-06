#include "initialize_library.hpp"


void InitializeStreets(Streets *streets, StreetList parsed_streets) {
    StreetList::iterator i;

    for (i = parsed_streets.begin(); i != parsed_streets.end(); ++i) {
        streets->AddStreet(i.value());
    }
}

void InitializeLines(Lines *lines,  QHash<QString, Line> parsed_lines) {
    QHash<QString, Line>::iterator i;

    for (i = parsed_lines.begin(); i != parsed_lines.end(); ++i)
        lines->AddLine(i.value());
}

