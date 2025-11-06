// LETS GET THIS PARTY STARTED

//------------------------------------------------------------------------------
// Lab 29: Coffee Shop Simulation
//------------------------------------------------------------------------------

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

    // DISPLAY
        // for each barista:
            // display their 3 phase lists


