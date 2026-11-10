#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //Set up the variables and it values 
    double cadence = 2.00, track_length = 400, target_time = 220, total_distance = 1600, average_distance_ps = 1.80, cadence_increase = 0.01, fatigue_loss = 0.02, current_step_distance, steps_per_lap, time_per_lap, time_all_laps, time_per_lap1 = 0, time_per_lap2 = 0, time_per_lap3 = 0, time_per_lap4 = 0; 
    int num_of_laps = 4, lap;
    bool program_running;
    string program;

    program_running = true;

//-----------------------------------------------------------------------

    //Asking if I want to start the program and storing it in the "program" variable as a string
    cout << "Do you want to start the program?(Y/N): ";
    cin >> program;
//-----------------------------------------------------------------------
    //If the person types "Y" for the lats question, it would run the program until "program" become false.
    if(program == "Y"){
        while(program_running == true){
            time_all_laps = 0;
            current_step_distance = average_distance_ps;   

            cout << "\nTesting Cadence: " << cadence << " steps/sec\n\n";
//-------------------------------------------------------------------------
            //This is where the time for each lap is shown
            for(lap = 1; lap <= num_of_laps; lap++){
                steps_per_lap = track_length / current_step_distance;
                time_per_lap = steps_per_lap / cadence;

                time_all_laps = time_all_laps + time_per_lap;

                if(lap == 1){
                    time_per_lap1 = time_per_lap;
                }
                else if(lap == 2){
                    time_per_lap2 = time_per_lap;
                }
                else if(lap == 3){
                    time_per_lap3 = time_per_lap;
                }
                else{
                    time_per_lap4 = time_per_lap;
                }

                cout << "Lap " << lap << " (" << current_step_distance << " m/step) time: " << time_per_lap << " seconds\n";

                current_step_distance = current_step_distance - fatigue_loss;
            }
//---------------------------------------------------------------------------
            //This will show teh results IF you did NOT get the WR
            cout << "\nYour time: " << time_all_laps << " seconds";
            cout << "\nTarget time: " << target_time << " seconds\n";

            if(time_all_laps > target_time){
                cout << "\nResult: Target not reached.";
                cout << "\n=======================\n";
                cadence = cadence + cadence_increase;
            }
//--------------------------------------------------------------------------
            //This is when you actually gete teh world record, it will print this and teh program will stop running
            else{
                program_running = false;
                cout << "\n\n=======================\n";
                cout << "CONGRATS! YOU GOT THE WORLD RECORD!\n";
                cout << "=======================\n\n";

                cout << "Race Distance: " << total_distance << " meters";
                cout << "\nTarget Time: " << target_time << " seconds";
                cout << "\nMinimum Required Cadence: " << cadence << " steps/sec";
                cout << "\nYour Time: " << time_all_laps << " seconds";
                cout << "\nLap 1 time: " << time_per_lap1 << " seconds";
                cout << "\nLap 2 time: " << time_per_lap2 << " seconds";
                cout << "\nLap 3 time: " << time_per_lap3 << " seconds";
                cout << "\nLap 4 time: " << time_per_lap4 << " seconds\n";
            }
        }
    }
}