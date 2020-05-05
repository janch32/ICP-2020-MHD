#include "../classes/vehicle.hpp"
#include "../classes/position.hpp"

#include "move_functions_library.hpp"

void Step() {

}

/**
 * @brief Vypočítá délku, kterou vozidlo ujede za jednotku casu mezi zastavkami
 *
 * @param length
 * @param curr_time
 * @param final_time
 * @return int
 */
int ComputeSteps(float length, int curr_time, int final_time) {
    int time = final_time - curr_time;
    return length / time;
}

/**
 * @brief Posune vozidlo na danou pozici
 *
 * @param vehicle
 * @param position
 */
void MoveVehicle(Vehicle vehicle, Position position) {
    vehicle.SetPosition(position);
}
