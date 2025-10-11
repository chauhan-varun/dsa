#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct WeatherRecord {
  string date;
  int temperature;
  string city;
  WeatherRecord(string d, int t, string c) : date(d), temperature(t), city(c) {}
};

class WeatherDataStorage {
private:
  vector<int> years;
  vector<string> cities;
  unordered_map<int, int> yearsIdx;
  unordered_map<string, int> citiesIdx;
  vector<vector<int>> data;
  const double SENTINEL = -999.0;

public:
  WeatherDataStorage(const vector<int> &years, const vector<string> &cities)
      : years(years), cities(cities) {
    for (int i = 0; i < years.size(); i++) {
      yearsIdx[years[i]] = i;
    }
    for (int i = 0; i < cities.size(); i++) {
      citiesIdx[cities[i]] = i;
    }

    data =
        vector<vector<int>>(years.size(), vector<int>(cities.size(), SENTINEL));
  }

  void insert(WeatherRecord &record) {

    int year = stoi(record.date.substr(6, 4));
    if (yearsIdx.find(year) != yearsIdx.end() &&
        citiesIdx.find(record.city) != citiesIdx.end()) {
      int i = yearsIdx[year];
      int j = citiesIdx[record.city];
      data[i][j] = record.temperature;
    } else {
      cout << "cant find the record \n";
    }
  }

  void deletion(WeatherRecord &record) {

    int year = stoi(record.date.substr(6, 4));
    if (yearsIdx.find(year) != yearsIdx.end() &&
        citiesIdx.find(record.city) != citiesIdx.end()) {
      int i = yearsIdx[year];
      int j = citiesIdx[record.city];
      data[i][j] = SENTINEL;
    } else {
      cout << "cant find the record \n";
    }
  }
  int retrieval(WeatherRecord &record) {

    int year = stoi(record.date.substr(6, 4));
    if (yearsIdx.find(year) != yearsIdx.end() &&
        citiesIdx.find(record.city) != citiesIdx.end()) {
      int i = yearsIdx[year];
      int j = citiesIdx[record.city];
      return data[i][j];
    } else {
      return SENTINEL;
    }
  }

  void rowMajorAccess() {
    for (int i = 0; i < years.size(); i++) {
      for (int j = 0; j < cities.size(); j++) {
        cout << "City: " << cities[j] << "Temperature: " << data[i][j];
      }
    }
  }

  void columnMajorAccess() {
    for (int i = 0; i < years.size(); i++) {
      for (int j = 0; j < cities.size(); j++) {
        cout << "Year: " << years[i] << "Temperature: " << data[i][j];
      }
    }
  }
};
