#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

/*
WHY THIS PROGRAM?
-----------------
A tiny "bunk calculator" that:
1) Figures out today's weekday from the system clock (chrono + ctime).
2) Looks up the 5 classes scheduled today from a fixed timetable.
3) Marks you present or absent for each period (one-shot P/A for the day).
4) Loads prior totals from a CSV on startup; saves updated totals on exit.
5) Shows a summary report of attendance and how many more bunks you can afford.

WHAT WE PERSIST (bare minimum):
- For each subject: progress (classes held), attended (classes attended).
- bunkable is recomputed every time from your 20% rule, so the CSV can’t drift.
*/

int today = 0; // kept from your original; no longer used for weekday math

// -------------------- HOLIDAYS --------------------
// Simple list of no-class dates, format "YYYY-M-D" (no zero padding).
const string HOLIDAYS[] = {
    "2025-1-26",  // Republic Day
    "2025-8-15",  // Independence Day
    "2025-10-2"   // Gandhi Jayanti
};
const size_t HOLIDAY_COUNT = sizeof(HOLIDAYS) / sizeof(HOLIDAYS[0]);

// -------------------- CSV STORAGE --------------------
// We keep a super simple CSV next to the exe:
//   subject,progress,attended,bunkable
// On load: we read progress+attended, then recompute bunkable from your rule.
const string CSV_FILE = "attendance.csv";

// -------------------- SUBJECT MODEL --------------------
// sub is a class that stores mutliple courses/subjects as objects
//the attributes of the class include the total number of classes and class name initialied on construction
//other attributes are minimum percentage, progress (total class occured), attended (total attended actually), attendance which is infloat
//bunkable and bunked are in relation to the number of total classes we can bunk now, and how many we ahve bunked already
class sub {
public:
    string subname;
    int total_classes;   // planned total for the semester (used for 20% rule)
    float min = 80.00f;  // minimum attendance percent (kept as-is)
    int progress;        // classes held so far
    int attended;        // classes attended so far
    float attendance;    // computed percent = 100 * attended / progress
    int bunkable;        // remaining allowed bunks = 20% of planned - bunked
    int bunked;          // bunked so far = progress - attended

    sub(string subname, int total)
    {
        this->subname = subname;
        total_classes = total;
        progress = 0;
        attended = 0;
        attendance = 0.0f;
        bunked = 0;
        bunkable = int(0.2f * total_classes); // initial allowance (will be recomputed)

        cout << "For the subject " << subname
             << " the total no. of classes is " << total_classes << "\n\n";
    }

    // Keep all derived values in sync.
    void recompute()
    {
        if (progress > 0) attendance = (float(attended) / progress) * 100.0f;
        else attendance = 0.0f;

        bunked = progress - attended;

        // Your math: allowed bunks = 20% of PLANNED total, minus what you've bunked.
        int base_allowance = int(0.2f * total_classes);
        bunkable = base_allowance - bunked;
    }

    // Mark one present/absent and print a small per-subject status line.
    void mark_present()
    {
        attended++;
        progress++;
        recompute();
        report();
    }
    void mark_absent()
    {
        progress++;
        recompute();
        report();// report gives out an output detailing the attendnace and other details for each class
    }

    void report() const
    {
        if (bunkable < 0) {
            cout << "Well for subject: " << subname << "\n"
                 << "Bro you are cooked: Your attendance is: " << attendance
                 << "\nYou now have bunked: " << bunked << " classes"
                 << "\nYou have bunked: " << -bunkable << " extra classes \n\n";
        } else {
            cout << "Well for subject: " << subname << "\n"
                 << "Bro you are NOT cooked: Your attendance is: " << attendance
                 << "\nYou now have bunked: " << bunked << " classes"
                 << "\nYou can now bunk: " << bunkable << " classes\n\n";
        }
    }
};

// SUBJECTS PLUS LOOKUP
sub dsa ("Data Structures & Algorithms", 13);
sub dbms("Database Management Systems", 14);
sub oops("Object Oriented Programming", 12);
sub dld ("Digital Logic Design", 15);
sub dms ("Discrete Mathematics", 10);

// One authoritative array (so we can loop/save/load in one place)
sub subjects[5] = { dsa, dbms, oops, dld, dms };

// Fast: subject name -> index in subjects[] MAPPING KINDA LIKE DICTIONARIES IN PYTHON
unordered_map<string, int> name_to_idx;

// THE TIME TABLE
// 6 rows x 5 columns:
// row 0 is headers (Mon..Fri); rows 1..5 are the 5 periods of the day.
// columns 0..4 map to Monday..Friday.
string timetable[6][5] = {
    {"Monday",   "Tuesday",   "Wednesday",   "Thursday",   "Friday"},
    {"Data Structures & Algorithms", "Database Management Systems", "Object Oriented Programming", "Digital Logic Design", "Discrete Mathematics"},
    {"Database Management Systems",  "Object Oriented Programming", "Digital Logic Design",        "Discrete Mathematics", "Data Structures & Algorithms"},
    {"Object Oriented Programming",  "Digital Logic Design",        "Discrete Mathematics",        "Data Structures & Algorithms", "Database Management Systems"},
    {"Digital Logic Design",         "Discrete Mathematics",        "Data Structures & Algorithms","Database Management Systems", "Object Oriented Programming"},
    {"Discrete Mathematics",         "Data Structures & Algorithms","Database Management Systems", "Object Oriented Programming", "Digital Logic Design"}
};

// -------------------- WEEKDAY (chrono + ctime) --------------------
// Convert system time -> calendar fields (tm), then map tm_wday to your scheme:
// Monday=1..Friday=5, Saturday=6, Sunday=7. Also returns day name.
int weekday_marker_today(int& day_of_month, string& day_name)
{
    auto now = chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t(now);
    tm local = *std::localtime(&tt); // local time (uses OS timezone)

    day_of_month = local.tm_mday;

    // tm_wday: 0=Sun..6=Sat. We remap to your 1..7 scheme.
    switch (local.tm_wday) {
        case 0: day_name = "Sunday";    return 7;
        case 1: day_name = "Monday";    return 1;
        case 2: day_name = "Tuesday";   return 2;
        case 3: day_name = "Wednesday"; return 3;
        case 4: day_name = "Thursday";  return 4;
        case 5: day_name = "Friday";    return 5;
        case 6: day_name = "Saturday";  return 6;
    }
    return 7;
}

//LOADING AND SAVING THE CSV FILE
// CSV format is like this:-  subject,progress,attended,bunkable
// We trust only progress+attended from file; bunkable is recomputed.
void load_csv()
{
    ifstream in(CSV_FILE); //input file stream
    //in is an object that stores the data
    if (!in) {
        //when in is empty...i.e. null
        cerr << "(Note) No CSV found. Starting fresh counters.\n";
        return;
    }
    string line;
    while (getline(in, line)) { // getline returns null whent here is no line to read in the csv file
        if (line.empty()) continue;
        stringstream ss(line);// as a fake input output stream. this line helps in parsing. ;replaces cin in the getline 

        string name, sprog, satt, sbunk;
        if (!getline(ss, name, ',')) continue;//reads till the first comman from ss and stores it in hte name variable
        if (!getline(ss, sprog, ',')) continue;
        if (!getline(ss, satt, ',')) continue;
        if (!getline(ss, sbunk, ',')) continue;

        auto it = name_to_idx.find(name);
        if (it == name_to_idx.end()) continue; // ignore unknown rows

        int idx = it->second;//grabs the index: 1,2,3...
        try {
            subjects[idx].progress = stoi(sprog);
            subjects[idx].attended = stoi(satt);
        } catch (...) {
            continue; // skip bad rows
        }
        subjects[idx].recompute(); // keep derived fields consistent... makes sure bunkable and bunkk match the math
    }
}

void save_csv()
{
    ofstream out(CSV_FILE, ios::trunc);//writes content from scratch. erases file first
    if (!out) {
        cerr << "ERROR: Cannot write CSV: " << CSV_FILE << "\n";
        return;
    }
    for (int i = 0; i < 5; ++i) {
        out << subjects[i].subname << ","
            << subjects[i].progress << ","
            << subjects[i].attended << ","
            << subjects[i].bunkable << "\n";
    }
}

// today
// Keeps your original flow: construct 'date' = today; then mark today's classes.
class date
{
public:
    int dd;         // day of month number (e.g., 24)
    string day;     // "Monday"..."Sunday"
    int day_marker; // 1..5=Mon..Fri, 6=Sat, 7=Sun
    string iso;     // "YYYY-M-D" (no padding), used for holiday match

    date()
    {
        day_marker = weekday_marker_today(dd, day);

        // builds string iso
        time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
        tm local = *std::localtime(&tt);
        int y = local.tm_year + 1900;
        int m = local.tm_mon + 1;  // 0..11 -> 1..12
        int d = local.tm_mday;     // 1..31
        iso = to_string(y) + "-" + to_string(m) + "-" + to_string(d);
    }

    // Mark all 5 periods for *today* as either present or absent.
    // Skips holidays and weekends.
    void present(bool is_present)
    {
        // Holiday guard
        for (size_t i = 0; i < HOLIDAY_COUNT; ++i) {
            if (HOLIDAYS[i] == iso) {
                cout << "Holiday: " << day << " " << iso << " — no classes.\n";
                return;
            }
        }

        // Weekend guard
        if (day_marker == 6 || day_marker == 7) {
            cout << "It's " << day << " (no classes scheduled).\n";
            return;
        }

        // For Mon..Fri, column index is 0..4
        int col = day_marker - 1;

        // For each of the 5 periods: find the subject and mark P/A
        for (int i = 1; i <= 5; i++) {
            const string& subname = timetable[i][col];
            auto it = name_to_idx.find(subname);
            if (it == name_to_idx.end()) {
                cerr << "Unknown subject in timetable: " << subname << "\n";
                continue;
            }
            int idx = it->second;
            if (is_present) subjects[idx].mark_present();
            else            subjects[idx].mark_absent();
        }

        // Persist the updated counters so next run starts from here.
        save_csv();
    }
};

// -------------------- REPORT (new) --------------------
// Prints a compact summary for all subjects (after load or marking).
void show_report()
{
    cout << "\n===== REPORT =====\n";
    for (int i = 0; i < 5; ++i) {
        cout << subjects[i].subname << "\n"
             << "  Held: " << subjects[i].progress
             << "  Attended: " << subjects[i].attended
             << "  %: " << subjects[i].attendance
             << "  Bunkable now: " << subjects[i].bunkable
             << (subjects[i].bunkable < 0 ? "  (COOKED)" : "")
             << "\n\n";
    }
}

// INITIAL SETUP - MAPPING THE INDEXES TO SUBJECTS
void init_index()
{
    // Build name -> index map once, so timetable lookup is O(1)
    for (int i = 0; i < 5; ++i) {
        name_to_idx[subjects[i].subname] = i;
    }
}

// THE MAIN 
int main()
{
    init_index(); // enable fast subject lookup
    load_csv();   // pull prior totals (if CSV exists)

    date d;       // today’s date + weekday + ISO string
    cout << "Hey Good morning!\nToday is: " << d.day
         << " and date is: " << d.dd << "\n";

    // Optional: quick look at where you stand before marking
    show_report();

    char presence;
    cout << "Are you present today (P/A): ";
    cin >> presence;

    bool isP = (presence == 'P' || presence == 'p');
    d.present(isP);

    // Show final state after today’s update
    show_report();

    return 0;
}
