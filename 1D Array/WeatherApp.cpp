#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Weather Record ADT
struct WeatherRecord {
    string date;      // Format: dd/mm/yyyy
    string city;
    double temperature;
    WeatherRecord(string d, string c, double t) : date(d), city(c), temperature(t) {}
};

// Weather Data Storage Class using 2D Array
class WeatherDataStorage {
private:
    vector<int> years;
    vector<string> cities;
    unordered_map<int, int> yearIndex;
    unordered_map<string, int> cityIndex;
    vector<vector<double>> data;   // 2D array for temperature data
    const double SENTINEL = -999.0; // Sentinel value to represent missing data

public:
    WeatherDataStorage(const vector<int>& yrs, const vector<string>& cts) : years(yrs), cities(cts) {
        // Initialize year and city indices for quick lookup
        for (int i = 0; i < years.size(); ++i) {
            yearIndex[years[i]] = i;
        }
        for (int j = 0; j < cities.size(); ++j) {
            cityIndex[cities[j]] = j;
        }
        // Initialize 2D data array with sentinel values indicating no data
        data = vector<vector<double>>(years.size(), vector<double>(cities.size(), SENTINEL));
    }

    // Insert temperature record
    void insert(const WeatherRecord& record) {
        int year = stoi(record.date.substr(6,4)); // Extract year from "dd/mm/yyyy"
        if (yearIndex.find(year) != yearIndex.end() && cityIndex.find(record.city) != cityIndex.end()) {
            int i = yearIndex[year];
            int j = cityIndex[record.city];
            data[i][j] = record.temperature;
        }
        else {
            cout << "Error: Year or city not found for record insertion.\n";
        }
    }

    // Delete record by setting to sentinel
    void deleteRecord(const string& date, const string& city) {
        int year = stoi(date.substr(6,4));
        if (yearIndex.find(year) != yearIndex.end() && cityIndex.find(city) != cityIndex.end()) {
            int i = yearIndex[year];
            int j = cityIndex[city];
            data[i][j] = SENTINEL;
        }
        else {
            cout << "Error: Year or city not found for record deletion.\n";
        }
    }

    // Retrieve temperature data for a city in a specific year
    double retrieve(const string& city, int year) {
        if (yearIndex.find(year) != yearIndex.end() && cityIndex.find(city) != cityIndex.end()) {
            int i = yearIndex[year];
            int j = cityIndex[city];
            return data[i][j];
        }
        else {
            cout << "Error: Year or city not found for retrieval.\n";
            return SENTINEL;
        }
    }

    // Row-major access and print of all temperature data
    void rowMajorAccess() {
        cout << "Row-major access (Year-wise data):\n";
        for (int i = 0; i < data.size(); ++i) {
            cout << "Year " << years[i] << ":\n";
            for (int j = 0; j < data[i].size(); ++j) {
                if (data[i][j] == SENTINEL)
                    cout << "  " << cities[j] << ": No data\n";
                else
                    cout << "  " << cities[j] << ": " << data[i][j] << "°C\n";
            }
        }
    }

    // Column-major access and print of all temperature data
    void columnMajorAccess() {
        cout << "Column-major access (City-wise data):\n";
        for (int j = 0; j < cities.size(); ++j) {
            cout << "City " << cities[j] << ":\n";
            for (int i = 0; i < years.size(); ++i) {
                if (data[i][j] == SENTINEL)
                    cout << "  Year " << years[i] << ": No data\n";
                else
                    cout << "  Year " << years[i] << ": " << data[i][j] << "°C\n";
            }
        }
    }

    // Complexity analysis summary (just printing here)
    void analyzeComplexity() {
        cout << "\nTime Complexity:\n";
        cout << "Insert: O(1) - Direct array index access\n";
        cout << "Delete: O(1) - Direct array index access\n";
        cout << "Retrieve: O(1) - Direct array index access\n";
        cout << "Row-major/Column-major traversal: O(m*n), m=years, n=cities\n";
        cout << "\nSpace Complexity:\n";
        cout << "O(m*n) for storing temperature data\n\n";
    }
};

int main() {
    vector<int> years = {2023, 2024, 2025};
    vector<string> cities = {"New York", "London", "Tokyo"};

    WeatherDataStorage wds(years, cities);

    // Insert records
    wds.insert(WeatherRecord("01/01/2023", "New York", 5.2));
    wds.insert(WeatherRecord("01/01/2023", "London", 7.6));
    wds.insert(WeatherRecord("01/01/2023", "Tokyo", 10.0));
    wds.insert(WeatherRecord("01/01/2024", "New York", 4.8));
    wds.insert(WeatherRecord("01/01/2025", "Tokyo", 9.5));

    // Access data row-wise and column-wise
    wds.rowMajorAccess();
    wds.columnMajorAccess();

    // Retrieve example
    cout << "\nTemperature in London in 2023: " << wds.retrieve("London", 2023) << "°C\n";

    // Delete example
    wds.deleteRecord("01/01/2023", "London");
    cout << "After deletion:\n";
    wds.rowMajorAccess();

    // Complexity analysis
    wds.analyzeComplexity();

    return 0;
}

