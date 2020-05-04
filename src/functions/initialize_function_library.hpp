
void InitializeStreets(Streets *streets, StreetParser parser);

void InitializeStops(Stops *stops/*, StopParser parser*/);

void InitializeLines(Stops stops, Lines *lines /*, LinesParser parser */);

Vehicle StartVehicle(Vehicles vehicles, Line line, int number, Position position);
