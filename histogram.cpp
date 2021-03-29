// histogram: used to count and display the frequencies
//            of values in input.
//            First two values represent the min and max
//            value respectively.
//            All other integers in input counted and
//            displayed as a histogram.
//Input:
//1 2
//1 1 1 2 3
//
//Output:
//Error: value 3 is out of range
//2 |#
//1 |###
//  +----+----+
//  0    5    10
//
// Tyler Faulkner, 3/29/2021
//
#include <iostream>
#include <math.h> 
#include <iomanip>
using namespace std;

const int RANGE = 10; // default range of the x-axis
const int Y_AXIS_WIDTH = 3; //width of the printed y-axis values used for formatting
const int SPACES = 5; //amount of spaces between numbers


int max_val;
int min_val;

int highest_frequency = 0;
int array_length = 0;

void read_range()
{
    cin >> min_val;
    cin >> max_val;
    array_length = (max_val - min_val);
}

void get_counts(int counts[])
{
    int num;
    cin >> num;
    while ( cin ){
        if (num >= min_val && num <= max_val){
            int i = num - min_val;
            counts[i] += 1;
            if(counts[i] > highest_frequency){
                highest_frequency = counts[i];
            }
        } 
        else {
            cout << "Error: value " << num << " is out of range\n";
        }
        cin >> num;
    }
}

void print_xaxis(int multiplier)
{
    for (int i = 0; i <= Y_AXIS_WIDTH; i++){
        cout << " ";
    }
    cout << "0    5    10";
    for(int i=15; i<=RANGE*multiplier; i+=5){
        cout << "   ";
        cout << i;
    }
    cout << "\n";
}

void print_range()
{
    int multiplier = (int) ceil(highest_frequency/(float)RANGE);
    if (multiplier == 0){
        multiplier = 1;
    }
    for (int i = 0; i <= Y_AXIS_WIDTH; i++) {
        cout << " ";
    }
    cout << "+";
    for(int i = 5; i<=RANGE*multiplier;  i+=5) {
        cout << "----+";
    }
    cout << "\n";
    print_xaxis(multiplier);
}

void print_results(int counts[])
{
    for (int i = array_length; i >= 0; i--) {
        int count = counts[i];
        int val = i + min_val;
        for (int i = 0; i < Y_AXIS_WIDTH - (int) to_string(val).length(); i++){
            cout << " ";
        }
        cout << val << " |";
        for (int i=0; i<count; i++){
            cout << "#";
        }
        cout << "\n";
    }
    print_range();
}


int main(int argc, char **argv)
{
    read_range();
    int counts[array_length + 1] = {};
    get_counts(counts);
    print_results(counts);
}
