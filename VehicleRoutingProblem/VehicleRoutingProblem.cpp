#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class City {
public:
    int x, y;
    City(int x, int y) : x(x), y(y) {}
};

double calculateDistance(const City& city1, const City& city2) {
    int dx = city1.x - city2.x;
    int dy = city1.y - city2.y;
    return sqrt(dx * dx + dy * dy);
}

vector<City> findShortestRoute(vector<City>& cities) {
    vector<City> route;
    vector<bool> visited(cities.size(), false);
    int currCity = 0;
    route.push_back(cities[currCity]);
    visited[currCity] = true;

    for (int i = 1; i < cities.size(); ++i) {
        double minDistance = numeric_limits<double>::max();
        int nextCity;
        for (int j = 0; j < cities.size(); ++j) {
            if (!visited[j]) {
                double distance = calculateDistance(cities[currCity], cities[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextCity = j;
                }
            }
        }
        route.push_back(cities[nextCity]);
        visited[nextCity] = true;
        currCity = nextCity;
    }
    return route;
}

void printMap(const vector<City>& cities, const vector<City>& route = {}) {
    const int mapWidth = 10;
    const int mapHeight = 10;
    char map[mapHeight][mapWidth];

    // Initialize map with empty spaces
    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWidth; ++j) {
            map[i][j] = ' ';
        }
    }

    // Mark cities on map
    for (const auto& city : cities) {
        map[city.y][city.x] = 'C';
    }

    // Mark route on map if provided
    if (!route.empty()) {
        for (int i = 0; i < route.size(); ++i) {
            map[route[i].y][route[i].x] = i + '0';
        }
    }

    // Print map
    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWidth; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main() {
    vector<City> cities = { City(1, 3), City(2, 5), City(3, 7), City(5, 2),City(1, 1) ,City(1, 2), City(7, 2) };
    cout << "Initial cities map:" << endl;
    printMap(cities);

    vector<City> route = findShortestRoute(cities);
    cout << "\nMap after finding shortest route:" << endl;
    printMap(cities, route);

    return 0;
}
