// LETS GET THIS PARTY STARTED

//------------------------------------------------------------------------------
// Lab 29: Coffee Shop Simulation
//------------------------------------------------------------------------------
// ****TESTING GIT
// Order:
    // id: string
    // customer : string
    // drink : string
    // size : string
    // makeTime : int

// Phase lists = arary of 3 lsits
    // [0] queue
    // [1] inProgress
    // [2] completed

//baristas: map<string, Stagelist>> // key = baristas name

// seting up the store:
// baristas = {"Alice": {}, "Bob": {}, "Charlie": {}}
// incomingorders = loadFromFile("orders.txt ");

// PARAMETERS:
    // T = 25           // total times ran
    //MAX_ASSIGN = 3 
    // ASSIGN_MODE = "shortest-queue

// MAIN LOOP:
    // 1) ARRIVALS
    // set up a MAX_ASSIGN for orders per cycle
    // choose a barista with least orders in progress
    // push order into baristas queue

    // 2) START ORDERS
        // for each barista:
            // if inprogress is empty and queue not empty
                // move order from queue to inprogress
    
    // 3) PROCESS ORDERS / COMPLETE ORDERS
        // for each barista:
            // set the inprogress front make time to 1 less (-= 1)
            // if make time == 0
                // move order from inprogress to completed

    // 4) DISPLAY
        // for each barista:
            // display their 3 phase lists
            // show times to if order is in progress
            // show has been complete when completed


#include <iostream>   // lets us use input/output like std::cout and std::cin
#include <fstream>    // allows reading and writing to files (used for orders.txt)
#include <string>     // gives us the string class for storing words and names
#include <vector>     // gives vector, used for storing incoming orders
#include <array>      // gives array, used for our fixed 3-list structure
#include <list>       // gives list, used for queue/in-progress/completed orders
#include <map>        // gives map, used to map each barista to their 3 lists
#include <algorithm>  // gives helper functions like min_element (used for shortest queue)
using namespace std;

struct Order {
    string id;
    string customer;
    string drink;
    string size;
    int makeTime;
};

using Stagelist = array<list<Order>, 3>; // 0 = queue, 1 = inprogress, 2 = completed
using BaristaMap = map<string, Stagelist>; //key is barista name and we are puttign stage list as the value

// declearations

vector<Order> loadFromFile(const string& path) { // testing that the linker is linking and working
    vector<Order> v;
    ifstream fin(path);
    string customer, drink, size;
    int make = 0;
    int idx = 1;

    while (fin >> customer >> drink >> size >> make) {
        v.push_back(Order{
            "#" + to_string(idx++), customer, drink, size, make
        });
    }
    return v;
}

// void findShortestQueueBarista(const BaristaMap& baristas, string& baristaName); // & to modify the actual not a copy
// void processOrders(BaristaMap& baristas);
// void printStatus(const BaristaMap& baristas, int currentTime);
// void printSummary(const BaristaMap& baristas);

int main() {

    int T = 25;      // total times ran
    int MAX_ASSIGN = 3;

    BaristaMap baristas{
        {"Alice", Stagelist{}},
        {"Bob", Stagelist{}},
        {"Griddy", Stagelist{}}
    };

    cout << "Welcome to the Coffee Shop Simulation!" << endl;

    vector<Order> incoming = loadFromFile("orders.txt");

    cout << "Welcome to the Coffee Shop Simulation!\n";

    cout << "\nLoaded " << incoming.size() << " orders:\n";
    for (const auto& order : incoming) {
        cout << order.customer << "\n";

    }
}
// void findShortestQueueBarista(const BaristaMap& baristas, string& baristaName) { // & to modify the actual not a copy
//     // TODO find the barista with the shortest queue and set baristaName
// }

// void processOrders(BaristaMap& baristas) {
//     // TODO: move orders between queue → inProgress → completed
// }

// void printStatus(const BaristaMap& baristas, int currentTime) {
//     // TODO: print current state of each barista
// }

// void printSummary(const BaristaMap& baristas) {
//     // TODO: print how many drinks each barista finished
// }
