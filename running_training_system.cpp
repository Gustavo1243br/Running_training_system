/*
Running Training Management System
----------------------------------
Author: Gustavo Borges
Language: C++
Purpose: Academic project (First semester)

Description:
Console-based system that allows runners to register training sessions
and sort them by date, pace, duration or distance.

This project uses only concepts studied during the first semester
of the Science and Technology undergraduate program.
*/


#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#define MAX 50

struct Date {
    int day;
    int month;
    int year;
};

struct Run {
    float duration_in_minutes;
    float distance_in_km;
    Date training_date;
    float pace;
};

// Calculates average pace
float calculate_pace(float distance, float duration) {
    float pace = 0.0;
    pace = duration / distance;
    return pace;
}

// Checks if the year is leap year
bool is_leap_year(Date &d) {
    if ((d.year % 4 == 0 && d.year % 100 != 0) ||
        (d.year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

// Reads date fields
void read_date(Date &d) {
    cout << "Day: ";
    cin >> d.day;
    cout << "Month: ";
    cin >> d.month;
    cout << "Year: ";
    cin >> d.year;
}

// Validates date using calendar rules
void validate_date(Date &d) {
    bool leap;
    leap = is_leap_year(d);

    while (((d.day < 1) || (d.day > 31)) ||
           ((d.month < 1) || (d.month > 12)) ||
           (((d.month == 2) || (d.month == 4) ||
             (d.month == 6) || (d.month == 9) ||
             (d.month == 11)) && (d.day == 31)) ||
           ((leap == false) && (d.month == 2) && (d.day > 28)) ||
           ((leap == true) && (d.month == 2) && (d.day > 29))) {

        if ((d.day < 1) || (d.day > 31)) {
            cout << "Invalid day. Enter the date again." << endl;
            read_date(d);
        }

        if ((d.month < 1) || (d.month > 12)) {
            cout << "Invalid month. Enter the date again." << endl;
            read_date(d);
        }

        if (((d.month == 2) ||
             (d.month == 4) ||
             (d.month == 6) ||
             (d.month == 9) ||
             (d.month == 11)) && (d.day == 31)) {
            cout << "This month does not have day 31. Enter the date again." << endl;
            read_date(d);
        }

        leap = is_leap_year(d);

        if ((leap == false) && (d.month == 2) && (d.day > 28)) {
            cout << "February does not have this day in the given year. Enter the date again." << endl;
            read_date(d);
        }
    }
}

// Registers runs and accumulates them in the array
void read_runs(int amount, Run runs[], int &total_runs) {
    cout << endl;
    cout << "Great! Let's add the runs." << endl;

    for (int i = total_runs; i < total_runs + amount; i++) {
        cout << "Enter the date of run " << i + 1 << ":" << endl;
        read_date(runs[i].training_date);
        validate_date(runs[i].training_date);

        cout << "Enter duration in MINUTES: ";
        cin >> runs[i].duration_in_minutes;

        while (runs[i].duration_in_minutes <= 0) {
            cout << "Invalid duration. Enter again: ";
            cin >> runs[i].duration_in_minutes;
        }

        cout << "Enter distance in km: ";
        cin >> runs[i].distance_in_km;
        cout << endl;

        while (runs[i].distance_in_km <= 0) {
            cout << "Invalid distance. Enter again: ";
            cin >> runs[i].distance_in_km;
        }

        runs[i].pace = calculate_pace(
            runs[i].distance_in_km,
            runs[i].duration_in_minutes
        );
    }

    total_runs += amount;
}

// Reads sorting filter
void read_filter(int &sorting_criteria, int &order) {
    order = 0;

    cout << endl;
    cout << "1 - Sort by date." << endl;
    cout << "2 - Sort by pace." << endl;
    cout << "3 - Sort by duration." << endl;
    cout << "4 - Sort by distance." << endl;
    cin >> sorting_criteria;

    while (sorting_criteria < 1 || sorting_criteria > 4) {
        cout << "Invalid option. Choose again." << endl;
        cin >> sorting_criteria;
    }

    while (order != 1 && order != 2) {
        cout << endl;
        cout << "1 - Ascending." << endl;
        cout << "2 - Descending." << endl;
        cin >> order;
    }
}

// Main menu
bool main_menu(int &option) {
    cout << endl;
    cout << "1 - Add run." << endl;
    cout << "2 - Exit." << endl << endl;
    cin >> option;

    while (option != 1 && option != 2) {
        cout << "Invalid option. Choose again." << endl;
        cin >> option;
    }

    return option == 1;
}

// Sort by date
void sort_by_date(Run runs[], int total, int order) {
    Run temp;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            bool condition;

            if (order == 1) {
                condition =
                    (runs[i].training_date.year > runs[j].training_date.year) ||
                    (runs[i].training_date.year == runs[j].training_date.year &&
                     runs[i].training_date.month > runs[j].training_date.month) ||
                    (runs[i].training_date.year == runs[j].training_date.year &&
                     runs[i].training_date.month == runs[j].training_date.month &&
                     runs[i].training_date.day > runs[j].training_date.day);
            } else {
                condition =
                    (runs[i].training_date.year < runs[j].training_date.year) ||
                    (runs[i].training_date.year == runs[j].training_date.year &&
                     runs[i].training_date.month < runs[j].training_date.month) ||
                    (runs[i].training_date.year == runs[j].training_date.year &&
                     runs[i].training_date.month == runs[j].training_date.month &&
                     runs[i].training_date.day < runs[j].training_date.day);
            }

            if (condition) {
                temp = runs[i];
                runs[i] = runs[j];
                runs[j] = temp;
            }
        }
    }
}

// Sort by pace
void sort_by_pace(Run runs[], int total, int order) {
    Run temp;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if ((order == 1 && runs[i].pace > runs[j].pace) ||
                (order == 2 && runs[i].pace < runs[j].pace)) {
                temp = runs[i];
                runs[i] = runs[j];
                runs[j] = temp;
            }
        }
    }
}

// Sort by duration
void sort_by_duration(Run runs[], int total, int order) {
    Run temp;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if ((order == 1 && runs[i].duration_in_minutes > runs[j].duration_in_minutes) ||
                (order == 2 && runs[i].duration_in_minutes < runs[j].duration_in_minutes)) {
                temp = runs[i];
                runs[i] = runs[j];
                runs[j] = temp;
            }
        }
    }
}

// Sort by distance
void sort_by_distance(Run runs[], int total, int order) {
    Run temp;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if ((order == 1 && runs[i].distance_in_km > runs[j].distance_in_km) ||
                (order == 2 && runs[i].distance_in_km < runs[j].distance_in_km)) {
                temp = runs[i];
                runs[i] = runs[j];
                runs[j] = temp;
            }
        }
    }
}

// Displays sorted runs
void print_runs(Run runs[], int total, int order, int criteria, char user_name[]) {
    cout << endl << endl;
    cout << user_name << ", your runs sorted by ";

    if (criteria == 1) cout << "date ";
    else if (criteria == 2) cout << "pace ";
    else if (criteria == 3) cout << "duration ";
    else cout << "distance ";

    if (order == 1) cout << "in ascending order ";
    else cout << "in descending order ";

    cout << "are:" << endl << endl;

    for (int i = 0; i < total; i++) {
        cout << "Run on " << runs[i].training_date.day << "/"
             << runs[i].training_date.month << "/"
             << runs[i].training_date.year << endl;

        cout << "Distance: " << fixed << setprecision(2)
             << runs[i].distance_in_km << " km" << endl;

        cout << "Duration: " << runs[i].duration_in_minutes << " min" << endl;
        cout << "Pace: " << runs[i].pace << endl << endl;
    }
}

int main() {
    int amount, menu_option, order, choice, criteria;
    int finish_program = 1;
    int total_runs = 0;
    char user_name[MAX];

    Run runs[MAX];

    cout << "Welcome to the Running Training Management System." << endl;
    cout << "Here you can sort your runs by date, duration, distance or pace." << endl;
    cout << "Let's begin!" << endl;

    finish_program = main_menu(menu_option);

    if (!finish_program) {
        cout << "Goodbye!" << endl;
        return 0;
    }

    cout << "How many runs do you want to register? (Max 50)" << endl;
    cin >> amount;

    while (amount < 1 || amount > 50) {
        cout << "Invalid amount. Enter again." << endl;
        cin >> amount;
    }

    cout << "Enter your name: ";
    cin.ignore();
    cin.getline(user_name, MAX);

    read_runs(amount, runs, total_runs);

    read_filter(criteria, order);

    if (criteria == 1) sort_by_date(runs, total_runs, order);
    else if (criteria == 2) sort_by_pace(runs, total_runs, order);
    else if (criteria == 3) sort_by_duration(runs, total_runs, order);
    else sort_by_distance(runs, total_runs, order);

    print_runs(runs, total_runs, order, criteria, user_name);

    do {
        cout << endl;
        cout << "What do you want to do now?" << endl;
        cout << "1 - Add more runs" << endl;
        cout << "2 - Apply a different filter" << endl;
        cout << "3 - Exit program" << endl;
        cin >> choice;

        while (choice < 1 || choice > 3) {
            cout << "Invalid option. Choose again." << endl;
            cin >> choice;
        }

        if (choice == 1) {
            cout << "How many runs do you want to add?" << endl;
            cin >> amount;

            while (total_runs + amount > MAX) {
                cout << "Limit exceeded. You can add up to "
                     << (MAX - total_runs) << " more runs." << endl;
                cin >> amount;
            }

            read_runs(amount, runs, total_runs);
        } 
        else if (choice == 2) {
            read_filter(criteria, order);

            if (criteria == 1) sort_by_date(runs, total_runs, order);
            else if (criteria == 2) sort_by_pace(runs, total_runs, order);
            else if (criteria == 3) sort_by_duration(runs, total_runs, order);
            else sort_by_distance(runs, total_runs, order);

            print_runs(runs, total_runs, order, criteria, user_name);
        } 
        else {
            cout << "Goodbye!" << endl;
            finish_program = 0;
        }

    } while (finish_program != 0);

    return 0;
}
